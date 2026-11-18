#!/usr/bin/env python3
"""Git-only reconstruction. Never builds or runs compiler/guest/test code."""
from pathlib import Path
import argparse
import hashlib
import json
import os
import subprocess
import sys
import time
sys.dont_write_bytecode = True
from verify_members import verify

BASE = "c97ce81c48a0c003b072c77c655bdeb10860ebf1"
IMPLEMENTATION = "dca50af1d7d59fc4c609810aa6c2968e9ec1e6eb"
FINAL = "7deabd1b1f44bc40862b6a28c89fde502832d8cb"
REMOTE = "https://github.com/wakairo/NewLang_Compiler.git"


def replay(archive, target, output, manifest_sha):
    archive, target, output = map(lambda p: Path(p).resolve(), (archive, target, output))
    members = verify(archive, manifest_sha)
    metadata = json.loads((archive / "publication-c1184/candidate/metadata.json").read_text())
    assert metadata["base"] == BASE
    assert metadata["commits"][0]["sha"] == IMPLEMENTATION
    assert metadata["commits"][1]["sha"] == FINAL
    assert not target.exists(), "replay destination must be newly created"
    target.mkdir(parents=True)
    env = {k: v for k, v in os.environ.items() if k not in {
        "GIT_DIR", "GIT_WORK_TREE", "GIT_COMMON_DIR", "GIT_OBJECT_DIRECTORY",
        "GIT_ALTERNATE_OBJECT_DIRECTORIES", "GIT_INDEX_FILE"}}
    env["PYTHONDONTWRITEBYTECODE"] = "1"
    commands = []
    start = time.monotonic()

    def git(*args):
        p = subprocess.run(["git", *args], cwd=target, env=env, capture_output=True)
        commands.append({"argv": ["git", *args], "exit": p.returncode,
                         "stdout": p.stdout.decode(errors="replace"),
                         "stderr": p.stderr.decode(errors="replace")})
        output.with_suffix(".commands.json").write_text(json.dumps(commands, indent=2)+"\n")
        assert p.returncode == 0, commands[-1]
        return p.stdout.decode().strip()

    git("init", "--initial-branch=replay-unborn")
    for key, value in [("user.name", "Codex P Custody Replay"),
                       ("user.email", "codex-p@users.noreply.github.com"),
                       ("core.hooksPath", "/dev/null"),
                       ("core.autocrlf", "false"),
                       ("core.attributesFile", "/dev/null"),
                       ("commit.gpgsign", "false"),
                       ("am.threeWay", "false")]:
        git("config", "--local", key, value)
    git("fetch", "--depth=1", "--no-tags", REMOTE, BASE)
    assert git("rev-parse", "FETCH_HEAD") == BASE
    git("checkout", "--detach", BASE)
    assert git("rev-parse", "HEAD^{tree}") == metadata["base_tree"]
    assert not (target / ".git/objects/info/alternates").exists()
    results = []
    for commit in metadata["commits"]:
        original = (archive / commit["raw_commit"]).read_bytes()
        identity = hashlib.sha1(b"commit " + str(len(original)).encode() + b"\0" + original).hexdigest()
        assert identity == commit["sha"]
        git("am", "--keep-cr", "--whitespace=nowarn", str(archive / commit["patch"]))
        restored = git("rev-parse", "HEAD")
        tree = git("rev-parse", "HEAD^{tree}")
        assert tree == commit["tree"]
        restored_raw = subprocess.check_output(["git", "cat-file", "commit", restored], cwd=target, env=env)
        original_author = next(l for l in original.split(b"\n") if l.startswith(b"author "))
        restored_author = next(l for l in restored_raw.split(b"\n") if l.startswith(b"author "))
        assert original_author == restored_author
        assert original.split(b"\n\n", 1)[1] == restored_raw.split(b"\n\n", 1)[1]
        results.append({"original_commit": commit["sha"], "patch_replay_commit": restored,
                        "expected_tree": commit["tree"], "actual_tree": tree,
                        "tree_match": True, "original_author_and_message_match": True})
    assert not git("status", "--porcelain=v1")
    for row in json.loads((archive / "publication-c1184/candidate/files.json").read_text()):
        actual = (target / row["path"]).read_bytes()
        assert len(actual) == row["bytes"]
        assert hashlib.sha256(actual).hexdigest() == row["sha256"]
        assert actual == (archive / "publication-c1184/candidate/source" / row["path"]).read_bytes()
    bundle = archive / "publication-c1184/candidate/p1525-publication.bundle"
    git("bundle", "verify", str(bundle))
    git("fetch", str(bundle), "refs/heads/p1525-terminal-receiver-c1184:refs/remotes/custody/p1525-publication-original")
    assert git("rev-parse", "refs/remotes/custody/p1525-publication-original") == FINAL
    for commit in metadata["commits"]:
        raw = subprocess.check_output(["git", "cat-file", "commit", commit["sha"]], cwd=target, env=env)
        assert raw == (archive / commit["raw_commit"]).read_bytes()
        assert git("rev-parse", commit["sha"] + "^{tree}") == commit["tree"]
        assert git("rev-parse", commit["sha"] + "^") == commit["parent"]
    result = {"members": members, "fresh_parent_remote": REMOTE,
              "fixed_parent": BASE, "fixed_parent_tree": metadata["base_tree"],
              "patch_replay": results,
              "bundle_restores_original_two_commit_bytes_and_ids": True,
              "source_HEAD_tree": git("rev-parse", "HEAD^{tree}"),
              "no_alternates": True, "no_local_P_objects_or_cache": True,
              "compiler_native_test_CI_runs": 0,
              "seconds": time.monotonic()-start}
    output.write_text(json.dumps(result, indent=2)+"\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("archive")
    parser.add_argument("fresh_target")
    parser.add_argument("receipt_json")
    parser.add_argument("manifest_sha256")
    a = parser.parse_args()
    replay(a.archive, a.fresh_target, a.receipt_json, a.manifest_sha256)
