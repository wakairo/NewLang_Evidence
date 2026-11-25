from csv import DictReader
from pathlib import Path
import runpy
import sys

here = Path.cwd()
prior = Path("../../p1778-independent-descriptor-exchange/adopted-repo")
support = runpy.run_path(str(prior / "tests/p1738/run.py"))
native = runpy.run_path("../repo/tests/p1682/run.py")["native"]
labels = (
    ("main", "single-original", support["observe"]),
    ("main", "same-original", support["observe_sequence"]),
    ("pin", "literal-independent", support["observe_independent"]),
)
with Path("oracle.tsv").open() as table:
    oracle = {row["case"]: row["values"] for row in DictReader(table, delimiter="\t")}
out = Path("raw/native-alternatives")
out.mkdir()
for pin, name, observe in labels:
    raw = out / name
    raw.mkdir()
    original = here / "raw" / f"exact-{pin}" / name / "existing.c"
    observed = raw / "observed.c"
    observed.write_bytes(observe(original.read_bytes(), b"1"))
    values = oracle[name].split(",")
    if name == "literal-independent":
        del values[2]  # The unchanged prior observer reports the final standby byte.
    expect = (",".join(values) + "\n").encode()
    for cc, label in (("/usr/bin/gcc", "gcc"), (sys.argv[1], "clang")):
        native(raw, cc, [(label + "-original", original, b""),
                         (label + "-observed", observed, expect)])
    print(pin, name, expect.decode().strip(), "8 strict runs", flush=True)
