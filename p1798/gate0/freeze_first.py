from csv import writer
from hashlib import sha256
from pathlib import Path
import re

prior = Path("/workspace/p1544-6afecbd5/p1794-early-field-copy/evidence")
here = Path(__file__).resolve().parent

def old(name):
    return (prior / "source" / (name + ".nl")).read_text()

def replace_once(text, source, replacement):
    assert text.count(source) == 1
    return text.replace(source, replacement)

def complete(text, tail=""):
    return replace_once(text, "    return unit;\n}\n", tail + "}\n")

current = old("repeat-low")
high = old("repeat-high")
displaced = replace_once(high, "    let incoming = active@reserve_mode;\n",
                         "    let incoming = old_active;\n")
literal = replace_once(high, "    let incoming = active@reserve_mode;\n",
                       "    let incoming = u8(19);\n")
literal = re.sub(r"standby@(reserve_mode|normal_mode)",
                 lambda m: "standby@" + ("normal_mode" if m[1] == "reserve_mode" else "reserve_mode"),
                 literal)
mixed_old = replace_once(old("repeat-mixed"), "    let incoming = active@normal_mode;\n",
                         "    let incoming = old_active;\n")
incoming = "    let incoming = active@normal_mode;\n"
stale = replace_once(
    current.replace(incoming, ""),
    "    let old_active = loan_write(active@normal_mode)",
    incoming + "    let old_active = loan_write(active@normal_mode)",
)
low = "4032,35,35,41,35,117,149,35,101"
literal_high = "4096,93,19,117,93,41,149,19,101"
old_high = "4096,93,117,117,93,41,101,117,149"
snap = old("snapshot-low")
cases = [
    ("complete-current", complete(current), "11", "current", 0, 4, 4, 0, low),
    ("return-current", current, "11", "current", 0, 0, 0, 0, low),
    ("complete-literal-mixed", complete(literal), "01", "literal", 0, 4, 4, 0, literal_high),
    ("return-literal-mixed", literal, "01", "literal", 0, 0, 0, 0, literal_high),
    ("complete-displaced-unit", complete(displaced, "    unit\n"), "00", "displaced", 0, 4, 4, 0, old_high),
    ("return-displaced", displaced, "00", "displaced", 0, 0, 0, 0, old_high),
    ("complete-mixed-displaced", complete(mixed_old), "10", "displaced", 0, 4, 4, 4, ""),
    ("complete-stale-current", complete(stale), "11", "current", 0, 4, 4, 4, ""),
    ("return-snapshot", snap, "11", "snapshot", 0, 4, 0, 4, low),
    ("complete-snapshot", complete(snap), "11", "snapshot", 0, 4, 4, 4, ""),
    ("scope-escape", old("scope-escape"), "", "escape", 3, 3, 3, 3, ""),
]
rows = []
for name, text, *values in cases:
    data = text.encode("ascii")
    path = here / "source" / f"{name}.nl"
    with path.open("xb") as out:
        out.write(data)
    rows.append((name, len(data), sha256(data).hexdigest(), *values))
with (here / "oracle.tsv").open("x", newline="") as out:
    table = writer(out, delimiter="\t", lineterminator="\n")
    table.writerow(("case", "bytes", "sha256", "positions", "actual",
                    "check", "main", "compare", "candidate", "values"))
    table.writerows(rows)

for part in ("queue_writer.h", "queue_writer.c"):
    (here / "comparison-c" / part).write_bytes((prior / "comparison-c" / part).read_bytes())
caller = (prior / "comparison-c/caller.c").read_text().replace(
    "{ Snapshot, Repeat, Displaced } Handoff", "{ Snapshot, Repeat, Displaced, Literal } Handoff"
)
start = caller.index("static const Scenario cases[] = {")
end = caller.index("\n};", start) + len("\n};")
caller = caller[:start] + """static const Scenario cases[] = {
    {"complete-current", 1u, 1u, 3u, Repeat},
    {"return-current", 1u, 1u, 3u, Repeat},
    {"complete-literal-mixed", 0u, 1u, 11u, Literal},
    {"return-literal-mixed", 0u, 1u, 11u, Literal},
    {"complete-displaced-unit", 0u, 0u, 11u, Displaced},
    {"return-displaced", 0u, 0u, 11u, Displaced},
    {"return-snapshot", 1u, 1u, 3u, Snapshot},
};""" + caller[end:]
caller = replace_once(caller,
    "        incoming = scenario->handoff == Repeat ? *first_target : old_active;",
    """        incoming = scenario->handoff == Literal ? 19u :
                   scenario->handoff == Repeat ? *first_target : old_active;"""
)
(here / "comparison-c/caller.c").write_text(caller)
