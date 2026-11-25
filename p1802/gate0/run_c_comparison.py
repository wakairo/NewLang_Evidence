from hashlib import sha256
from pathlib import Path
from shutil import which
import sys

from run_gate import oracle, trace

here = Path(__file__).resolve().parent
source = here / "comparison-c"
raw = Path(sys.argv[1]).resolve()
raw.mkdir(parents=True)
gcc, clang = which("gcc"), which("clang-23")
assert gcc and clang
profiles = [
    ("gcc-O0", gcc, ["-O0"]),
    ("gcc-O2", gcc, ["-O2"]),
    ("clang-O0", clang, ["-O0"]),
    ("clang-O2", clang, ["-O2"]),
    ("clang-sanitized", clang, ["-O1", "-g0", "-fsanitize=address,undefined",
                                "-fno-sanitize-recover=all"]),
]
cases = [(row["case"], row["values"]) for row in oracle() if row["values"]]
for label, compiler, flags in profiles:
    work = raw / label
    work.mkdir()
    writer = work / "queue_writer.o"
    exe = work / "caller"
    strict = ["-std=c17", "-pedantic-errors", "-Wall", "-Wextra", "-Werror"]
    version = trace(work, "tool", [compiler, "--version"])
    assert version.returncode == 0
    build = [compiler, *strict, *flags]
    for step, args in (("writer", ["-c", source / "queue_writer.c", "-o", writer]),
                       ("caller", [source / "caller.c", writer, "-o", exe])):
        result = trace(work, step, [*build, *args])
        assert result.returncode == 0 and not result.stderr, (label, step, result)
    digest = sha256(writer.read_bytes()).hexdigest()
    for case, expected in cases:
        result = trace(work, case, [exe, case])
        assert result.returncode == 0 and not result.stderr, (label, case, result)
        assert result.stdout == (expected + "\n").encode(), (label, case, expected, result)
        print(label, case, expected, f"writer_object={digest}", sep="\t", flush=True)
