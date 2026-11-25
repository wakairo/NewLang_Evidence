from csv import DictReader
from hashlib import sha256
from pathlib import Path
import json
import shlex
import subprocess
import sys

here = Path(__file__).resolve().parent


def trace(folder, label, command):
    (folder / f"{label}.command").write_text(shlex.join(map(str, command)) + "\n")
    done = subprocess.run(command, capture_output=True, check=False)
    (folder / f"{label}.stdout").write_bytes(done.stdout)
    (folder / f"{label}.stderr").write_bytes(done.stderr)
    (folder / f"{label}.status").write_text(f"{done.returncode}\n")
    return done


def fingerprint(path):
    item = path.stat()
    return item.st_dev, item.st_ino, item.st_mode, item.st_size, item.st_mtime_ns, item.st_ctime_ns


def run(cli, out, stage):
    out.mkdir(parents=True)
    print("compiler", cli, sha256(cli.read_bytes()).hexdigest(), sep="\t", flush=True)
    with (here / "oracle.tsv").open() as table:
        for case in DictReader(table, delimiter="\t"):
            name = case["case"]
            folder = out / name
            folder.mkdir()
            source = here / "cases" / f"{name}.nl"
            contents = source.read_bytes()
            assert len(contents) == int(case["bytes"])
            assert sha256(contents).hexdigest() == case["sha256"]
            check = trace(folder, "check", [cli, "--check", source])
            if int(case["check"]) == 3 and check.returncode == 0:
                raise RuntimeError(f"{stage} unexpectedly accepted {name} at CHECK")
            emit = trace(folder, "c17", [cli, source])
            existing, absent = folder / "existing.c", folder / "absent.c"
            sentinel = b"/* P1749 original output */\n"
            existing.write_bytes(sentinel)
            first = fingerprint(existing)
            to_existing = trace(folder, "named-existing", [cli, "--emit-c17-to", existing, source])
            to_absent = trace(folder, "named-absent", [cli, "--emit-c17-to", absent, source])
            final = fingerprint(existing)
            temps = sorted(str(path) for path in folder.glob("*.tmp.*"))
            absence = not absent.exists()
            state = {"initial": first, "final": final, "absent": absence,
                     "staging": temps, "existing_sha256": sha256(existing.read_bytes()).hexdigest()}
            (folder / "named-state.json").write_text(json.dumps(state, sort_keys=True) + "\n")
            assert emit.returncode == to_existing.returncode == to_absent.returncode, (stage, name)
            assert not to_existing.stdout and not to_absent.stdout and not temps, (stage, name)
            if emit.returncode == 0:
                assert check.returncode == 0 and emit.stdout and check.stderr == emit.stderr == b""
                assert to_existing.stderr == to_absent.stderr == b""
                assert existing.read_bytes() == absent.read_bytes() == emit.stdout
            else:
                assert not emit.stdout and absence and first == final and existing.read_bytes() == sentinel
                if emit.returncode == 4:
                    assert b"V1-BACKEND-UNSUPPORTED" in emit.stderr
                if case["diagnostic"]:
                    assert all(case["diagnostic"].encode() in attempt.stderr
                               for attempt in (check, emit, to_existing, to_absent))
            match = check.returncode == int(case["check"]) and emit.returncode == int(case[stage])
            print(name, check.returncode, emit.returncode, to_existing.returncode,
                  to_absent.returncode, "match" if match else "prediction-difference", sep="\t", flush=True)


if __name__ == "__main__":
    run(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve(), sys.argv[3])
