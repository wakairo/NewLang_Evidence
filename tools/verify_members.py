#!/usr/bin/env python3
"""Verify actual archive bytes and Git modes, including the full file set."""
from pathlib import Path
import argparse
import hashlib
import json
import stat
import subprocess


def verify(root, expected_manifest_sha):
    root = Path(root).resolve()
    path = root / "manifest.json"
    data = path.read_bytes()
    assert hashlib.sha256(data).hexdigest() == expected_manifest_sha
    manifest = json.loads(data)
    rows = manifest["members"]
    expected = {r["path"] for r in rows} | {"manifest.json"}
    assert len(expected) == len(rows) + 1
    actual = set()
    for p in root.rglob("*"):
        relative = p.relative_to(root)
        if relative.parts[0] == ".git":
            continue
        assert not p.is_symlink(), str(relative)
        if p.is_dir():
            continue
        assert stat.S_ISREG(p.lstat().st_mode), str(relative)
        actual.add(relative.as_posix())
    assert actual == expected, {"missing": sorted(expected-actual), "extra": sorted(actual-expected)}
    tracked = {}
    raw = subprocess.check_output(["git", "ls-files", "--stage", "-z"], cwd=root)
    for entry in raw.split(b"\0"):
        if not entry:
            continue
        header, name = entry.split(b"\t", 1)
        mode, blob, stage = header.decode().split()
        assert stage == "0"
        tracked[name.decode()] = (mode, blob)
    assert set(tracked) == expected
    assert tracked["manifest.json"][0] == "100644"
    assert not path.stat().st_mode & 0o111
    assert subprocess.check_output(["git", "cat-file", "blob", tracked["manifest.json"][1]], cwd=root) == data
    for row in rows:
        relative = Path(row["path"])
        assert not relative.is_absolute() and ".." not in relative.parts
        p = root / relative
        b = p.read_bytes()
        mode = "100755" if p.stat().st_mode & 0o111 else "100644"
        assert len(b) == row["bytes"]
        assert hashlib.sha256(b).hexdigest() == row["sha256"], row["path"]
        assert mode == row["mode"] == tracked[row["path"]][0]
        blob_data = subprocess.check_output(["git", "cat-file", "blob", tracked[row["path"]][1]], cwd=root)
        assert blob_data == b, row["path"]
    return {"member_count_including_manifest": len(expected),
            "payload_count": len(rows),
            "total_bytes_including_manifest": sum(r["bytes"] for r in rows) + len(data),
            "manifest_sha256": expected_manifest_sha,
            "path_set_size_sha256_Git_mode_and_blob_bytes": "ALL_MATCH"}


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("archive")
    parser.add_argument("manifest_sha256")
    args = parser.parse_args()
    print(json.dumps(verify(args.archive, args.manifest_sha256), indent=2))
