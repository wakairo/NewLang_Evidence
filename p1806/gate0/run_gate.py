from csv import DictReader
from hashlib import sha256
import json
from pathlib import Path
from shlex import join
from subprocess import run
import sys

here = Path(__file__).resolve().parent

def trace(folder, label, args, **kwargs):
    (folder / f"{label}.command").write_text(join(map(str, args)) + "\n")
    result = run(args, capture_output=True, check=False, **kwargs)
    (folder / f"{label}.stdout").write_bytes(result.stdout)
    (folder / f"{label}.stderr").write_bytes(result.stderr)
    (folder / f"{label}.status").write_text(f"{result.returncode}\n")
    return result

def state(path):
    info = path.stat()
    return tuple(getattr(info, key) for key in (
        "st_dev", "st_ino", "st_mode", "st_size", "st_mtime_ns", "st_ctime_ns"
    ))

def digest(data):
    return sha256(data).hexdigest()

def oracle():
    with (here / "oracle.tsv").open() as table:
        yield from DictReader(table, delimiter="\t")

def replay(cli, raw, pin):
    raw.mkdir(parents=True)
    print(f"compiler\t{cli}\t{digest(cli.read_bytes())}", flush=True)
    print("case\tCHECK\tC17\texisting\tabsent\tprediction", flush=True)
    for row in oracle():
        name = row["case"]
        source = here / "source" / f"{name}.nl"
        data = source.read_bytes()
        assert len(data) == int(row["bytes"]) and digest(data) == row["sha256"]
        case = raw / name
        case.mkdir()
        check = trace(case, "check", [cli, "--check", source])
        assert name != "scope-escape" or check.returncode != 0, "scope escape reached CHECK"
        emit = trace(case, "c17", [cli, source])
        first, second = case / "existing.c", case / "absent.c"
        sentinel = b"/* P1798 pre-existing output */\n"
        (case / "existing.before").write_bytes(sentinel)
        first.write_bytes(sentinel)
        first.chmod(0o640)
        before = state(first)
        existing = trace(case, "named-existing", [cli, "--emit-c17-to", first, source])
        absent = trace(case, "named-absent", [cli, "--emit-c17-to", second, source])
        after = state(first)
        residue = sorted(p.name for p in case.glob("*.tmp.*"))
        same = first.read_bytes() == sentinel and before == after
        details = dict(initial=before, final=after, absent=not second.exists(),
                       same=same, staging=residue, existing_sha256=digest(first.read_bytes()))
        (case / "named-state.json").write_text(json.dumps(details, sort_keys=True) + "\n")
        assert emit.returncode == existing.returncode == absent.returncode, (pin, name)
        assert not residue and not check.stdout and not existing.stdout and not absent.stdout, (pin, name)
        if check.returncode == 0:
            assert not check.stderr, (pin, name)
        if emit.returncode == 0:
            assert check.returncode == 0 and emit.stdout, (pin, name)
            assert not emit.stderr and not existing.stderr and not absent.stderr, (pin, name)
            assert emit.stdout == first.read_bytes() == second.read_bytes(), (pin, name)
        else:
            assert not emit.stdout and same and not second.exists(), (pin, name)
            if emit.returncode == 4:
                for result in (emit, existing, absent):
                    assert b"V1-BACKEND-UNSUPPORTED" in result.stderr, (pin, name)
            elif name == "scope-escape":
                for result in (check, emit, existing, absent):
                    assert b"P8-EXIT-DEPENDENCY" in result.stderr, (pin, name)
        for result in (check, emit, existing, absent):
            assert b"Sanitizer" not in result.stderr and b"runtime error:" not in result.stderr, (pin, name)
        match = check.returncode == int(row["check"]) and emit.returncode == int(row[pin])
        print(name, check.returncode, emit.returncode, existing.returncode, absent.returncode,
              "match" if match else "prediction-difference", sep="\t", flush=True)

if __name__ == "__main__":
    compiler, output = [Path(arg).resolve() for arg in sys.argv[1:3]]
    replay(compiler, output, sys.argv[3])
