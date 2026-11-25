from hashlib import sha256
from pathlib import Path
from subprocess import check_output

here = Path(__file__).resolve().parent
repo = here.parent / "repo"
main = "94eb75c3efa91a3feb2a14319d840bc00677bed9"

def adopted(name):
    return check_output(["git", "-C", repo, "show",
                         f"{main}:tests/p1738/source/{name}.nl"]).decode()

def change(source, before, after):
    assert source.count(before) == 1, before
    return source.replace(before, after)

def line(source, binding):
    matches = [s for s in source.splitlines(keepends=True)
               if s.startswith(f"    let {binding} = ")]
    assert len(matches) == 1
    return matches[0]

def with_reread(source):
    target = line(source, "active_after")
    peer = line(source, "active_peer")
    second = line(source, "old_standby")
    incoming = change(target, "let active_after", "let incoming")
    return change(source, target + peer + second,
                  incoming + change(second, ", active_after)", ", incoming)") + target + peer)

lower = adopted("snapshot-mixed")
upper = change(lower, "let rank = usize(3);", "let rank = usize(11);")
for original in ("active", "standby"):
    upper = (upper.replace(f"{original}@normal_mode", f"{original}@temporary")
             .replace(f"{original}@reserve_mode", f"{original}@normal_mode")
             .replace(f"{original}@temporary", f"{original}@reserve_mode"))
active_read = line(lower, "active_after")
active_peer = line(lower, "active_peer")
first_call = line(lower, "old_active")
sibling = change(lower, active_read + active_peer,
                 change(active_read, "@normal_mode", "@reserve_mode") +
                 change(active_peer, "@reserve_mode", "@normal_mode"))
wrong_original = change(lower, active_read, change(active_read, "active@", "standby@"))
before_write = change(lower, first_call + active_read, active_read + first_call)
normal_exit = change(lower, "    return unit;\n", "")

lower_values = "4032,35,35,41,35,117,101,35,149"
upper_values = "4096,93,93,117,93,41,149,93,101"
cases = (
    ("snapshot-mixed", lower, "10", "snapshot", 0, 4, 4, 0, lower_values),
    ("snapshot-mixed-reverse", upper, "01", "snapshot", 0, 4, 4, 0, upper_values),
    ("reread-mixed", with_reread(lower), "10", "current", 0, 0, 0, 0, lower_values),
    ("reread-mixed-reverse", with_reread(upper), "01", "current", 0, 0, 0, 0, upper_values),
    ("snapshot-low", adopted("snapshot-low"), "11", "snapshot", 0, 0, 0, 0,
     "4032,35,35,41,35,117,149,35,101"),
    ("snapshot-high", adopted("snapshot-high"), "00", "snapshot", 0, 0, 0, 0,
     "4096,93,93,117,93,41,101,93,149"),
    ("snapshot-mixed-sibling", sibling, "10", "snapshot", 0, 4, 4, 4, ""),
    ("snapshot-mixed-other", wrong_original, "10", "snapshot", 0, 4, 4, 4, ""),
    ("snapshot-mixed-before-change", before_write, "10", "snapshot", 0, 4, 4, 4, ""),
    ("snapshot-mixed-normal-exit", normal_exit, "10", "snapshot", 0, 4, 4, 4, ""),
    ("mixed-old", adopted("mixed-old"), "10", "displaced", 0, 4, 4, 4, ""),
    ("scope-escape", adopted("scope-exit"), "", "escape", 3, 3, 3, 3, ""),
)

with (here / "oracle.tsv").open("x", newline="\n") as output:
    output.write("case\tbytes\tsha256\tpositions\tactual\tcheck\tmain\tcompare\tcandidate\tvalues\n")
    for name, source, *expected in cases:
        data = source.encode()
        with (here / "source" / f"{name}.nl").open("xb") as dst:
            dst.write(data)
        output.write("\t".join(map(str, (name, len(data), sha256(data).hexdigest(), *expected))) + "\n")
