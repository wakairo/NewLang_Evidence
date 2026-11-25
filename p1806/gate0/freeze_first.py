from hashlib import sha256
from pathlib import Path
from subprocess import check_output

here = Path(__file__).resolve().parent
repo = here.parent / "repo"
main = "1c99d8dfc536160dfd1b26016cd4414dc1af9b75"
comparison = "0610baef571243ee5dc326b2a7a908c0b66c2263"

def source(name, commit=main):
    return check_output(["git", "-C", repo, "show",
                         f"{commit}:tests/p1738/source/{name}.nl"])

def normal(data, tail=b""):
    original = b"    return unit;\n"
    assert data.count(original) == 1
    return data.replace(original, tail)

low, high = source("snapshot-low"), source("snapshot-high")
mixed = source("snapshot-mixed")
reverse = source("snapshot-mixed-reverse", comparison)
unit = b"    unit\n"
assert normal(low) == source("complete-snapshot")

low_values = "4032,35,35,41,35,117,149,35,101"
high_values = "4096,93,93,117,93,41,101,93,149"
cases = (
    ("complete-snapshot", normal(low), "11", "snapshot", 0, 4, 4, 0, low_values),
    ("complete-snapshot-low-unit", normal(low, unit), "11", "snapshot", 0, 4, 4, 0, low_values),
    ("complete-snapshot-high", normal(high), "00", "snapshot", 0, 4, 4, 0, high_values),
    ("complete-snapshot-high-unit", normal(high, unit), "00", "snapshot", 0, 4, 4, 0, high_values),
    ("snapshot-low", low, "11", "snapshot", 0, 0, 0, 0, low_values),
    ("snapshot-high", high, "00", "snapshot", 0, 0, 0, 0, high_values),
    ("snapshot-mixed", mixed, "10", "snapshot", 0, 4, 0, 4,
     "4032,35,35,41,35,117,101,35,149"),
    ("snapshot-mixed-reverse", reverse, "01", "snapshot", 0, 4, 0, 4,
     "4096,93,93,117,93,41,149,93,101"),
    ("complete-snapshot-mixed", normal(mixed), "10", "snapshot", 0, 4, 4, 4, ""),
    ("complete-snapshot-mixed-reverse", normal(reverse, unit), "01", "snapshot", 0, 4, 4, 4, ""),
    ("complete-snapshot-stale", normal(source("snapshot-stale")), "11", "snapshot", 0, 4, 4, 4, ""),
    ("complete-snapshot-sibling", normal(source("snapshot-sibling-actual")), "11", "snapshot", 0, 4, 4, 4, ""),
    ("complete-snapshot-other", normal(source("snapshot-wrong-original"), unit), "11", "snapshot", 0, 4, 4, 4, ""),
    ("mixed-old", source("mixed-old"), "10", "displaced", 0, 4, 4, 4, ""),
    ("scope-escape", source("scope-exit"), "", "escape", 3, 3, 3, 3, ""),
)

with (here / "oracle.tsv").open("x", newline="\n") as output:
    output.write("case\tbytes\tsha256\tpositions\tactual\tcheck\tmain\tcompare\tcandidate\tvalues\n")
    for name, data, *expected in cases:
        with (here / "source" / f"{name}.nl").open("xb") as dst:
            dst.write(data)
        output.write("\t".join(map(str, (name, len(data), sha256(data).hexdigest(), *expected))) + "\n")
