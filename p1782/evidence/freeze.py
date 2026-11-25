from hashlib import sha256
from pathlib import Path
import csv


here = Path(__file__).resolve().parent
header = """struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

"""
active = "    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};\n"
standby = "    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};\n"
quantity = """    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
"""
first = "    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };\n"
observe = "    let applied = active@coalescing;\n"
second = "    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };\n"
active_reads = """    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
"""
standby_reads = """    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
"""
old_active = "    let first_previous = old_active;\n"
old_standby = "    let second_previous = old_standby;\n"


def entry(items):
    return header + "fn main() -> unit {\n" + items + "    return unit;\n}\n"


both = entry(active + standby + quantity + first + observe + second +
             active_reads + standby_reads + old_active + old_standby)
literal = both.replace(observe, "    let applied = u8(11);\n")
same = entry(active + quantity + first + "    let applied = u8(11);\n" +
             second.replace("standby@coalescing", "active@coalescing") +
             active_reads + old_active + old_standby)
single = entry(active + quantity + first + active_reads + old_active)
escape = """struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let escaped = loan_write(active@coalescing) { |field| field };
    let old = replace(escaped, u8(35));
    return unit;
}
"""
rows = [
    ("mirror-low", both, 0, 4, 4, "", "mirror", "4032,35,35,22,35,119,81,35,147"),
    ("mirror-high", both.replace("let rank = usize(3)", "let rank = usize(11)"),
     0, 4, 4, "", "mirror", "4096,93,93,22,93,119,81,93,147"),
    ("mirror-tail", both.replace("    let old = replace(slot, mode);\n    old", "    replace(slot, mode)"),
     0, 4, 4, "", "mirror", "4032,35,35,22,35,119,81,35,147"),
    ("literal-independent", literal, 0, 4, 0, "", "literal", "4032,35,11,22,35,119,81,11,147"),
    ("same-original", same, 0, 0, 0, "", "same", "4032,35,22,35,11,119"),
    ("single-original", single, 0, 0, 0, "", "single", "4032,35,22,35,119"),
    ("mirror-sibling", both.replace(observe, "    let applied = active@class_tag;\n"),
     0, 4, 4, "", "other-field", ""),
    ("mirror-wrong-original", both.replace(observe, "    let applied = standby@coalescing;\n"),
     0, 4, 4, "", "other-root", ""),
    ("mirror-stale", both.replace(first + observe, observe + first),
     0, 4, 4, "", "old-observation", ""),
    ("mirror-wrong-actual", both.replace("exchange(field, applied)", "exchange(field, selected)"),
     0, 4, 4, "", "unrelated-actual", ""),
    ("scope-escape", escape, 3, 3, 3, "P8-EXIT-DEPENDENCY", "escape", ""),
]
with (here / "oracle.tsv").open("x", encoding="utf-8", newline="") as out:
    writer = csv.writer(out, delimiter="\t", lineterminator="\n")
    writer.writerow(("case", "bytes", "sha256", "check", "main", "pin", "diagnostic", "contract", "values"))
    for name, contents, check, main, pin, diagnostic, contract, values in rows:
        data = contents.encode()
        with (here / "cases" / (name + ".nl")).open("xb") as source:
            source.write(data)
        writer.writerow((name, len(data), sha256(data).hexdigest(), check, main, pin, diagnostic, contract, values))
