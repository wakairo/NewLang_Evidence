from pathlib import Path
import runpy
from shutil import which
import sys

from run_gate import oracle, trace

here = Path(__file__).resolve().parent
pin, emitted, where = sys.argv[1:4]
emitted = Path(emitted).resolve()
raw = Path(where).resolve()
raw.mkdir(parents=True)
candidate_runner = here.parents[1] / "p1794-early-field-copy/repo/tests/p1738/run.py"
observe = runpy.run_path(str(candidate_runner))["observe_independent"]
gcc, clang = which("gcc"), which("clang-23")
assert gcc and clang
profiles = (
    ("gcc-O0", gcc, ["-O0"]),
    ("gcc-O2", gcc, ["-O2"]),
    ("clang-O0", clang, ["-O0"]),
    ("clang-O2", clang, ["-O2"]),
    ("clang-sanitized", clang, ["-O1", "-g0", "-fsanitize=address,undefined",
                                "-fno-sanitize-recover=all"]),
)
for row in oracle():
    if int(row[pin]) != 0:
        continue
    name = row["case"]
    expected = (row["values"] + "\n").encode()
    assert row["values"]
    case = raw / name
    case.mkdir()
    c = emitted / name / "existing.c"
    code = c.read_bytes()
    positions = row["positions"].encode()
    mode = "current" if row["actual"] == "snapshot" else row["actual"]
    observed_code = observe(code, positions, mode_source=mode,
                            snapshot_first=row["actual"] == "snapshot")
    instrumented = case / "observed.c"
    instrumented.write_bytes(observed_code)
    for label, compiler, flags in profiles:
        comparison = here / "investigation/c" / label / (name + ".stdout")
        assert comparison.read_bytes() == expected
        for mode, inp, want in (("original", c, b""), ("observed", instrumented, expected)):
            key = f"{label}-{mode}"
            dst = case / key
            build = trace(case, key + "-build", [compiler, "-std=c17", "-pedantic-errors",
                                                "-Wall", "-Wextra", "-Werror", *flags,
                                                inp, "-o", dst])
            assert build.returncode == 0 and not build.stderr, (pin, name, key, build)
            result = trace(case, key + "-run", [dst])
            assert result.returncode == 0 and not result.stderr, (pin, name, key, result)
            assert result.stdout == want, (pin, name, key, want, result.stdout)
            print(pin, name, label, mode, row["values"] if mode == "observed" else "PASS",
                  sep="\t", flush=True)
