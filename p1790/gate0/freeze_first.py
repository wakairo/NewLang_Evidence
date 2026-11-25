from csv import writer
from hashlib import sha256
from pathlib import Path

here = Path(__file__).resolve().parent
source_dir = here / "source"
header = """struct QueueModes { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}
"""
prefix = """
fn main() -> unit {
    let active = QueueModes{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = QueueModes{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize({rank});
    let blocks = if (rank < usize(8)) {{ usize(63) }} else {{ usize(64) }};
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
""".replace("fn main() -> unit {", "fn main() -> unit {{")
prefix = prefix.replace(
    "QueueModes{normal_mode: u8(41), reserve_mode: u8(117)}",
    "QueueModes{{normal_mode: u8(41), reserve_mode: u8(117)}}",
).replace(
    "QueueModes{normal_mode: u8(149), reserve_mode: u8(101)}",
    "QueueModes{{normal_mode: u8(149), reserve_mode: u8(101)}}",
)
field = ("reserve_mode", "normal_mode")
active_initial = (117, 41)
standby_initial = (101, 149)
scenarios = (
    # name, active position, standby position, rank, second actual, shape,
    # oracle: CHECK, C17/main, C17/compare, C17/planned, emit-native values
    ("mixed-current-low", 1, 0, 3, "current", "named", 0, 4, 4, 0, True),
    ("mixed-current-high", 0, 1, 11, "current", "tail", 0, 4, 4, 0, True),
    ("mixed-literal-low", 1, 0, 3, "literal", "named", 0, 4, 4, 0, True),
    ("mixed-literal-high", 0, 1, 11, "literal", "tail", 0, 4, 4, 0, True),
    ("same-current", 1, 1, 3, "current", "named", 0, 0, 0, 0, True),
    ("same-literal", 0, 0, 11, "literal", "named", 0, 0, 0, 0, True),
    ("same-old", 1, 1, 3, "old", "named", 0, 4, 0, 4, True),
    ("mixed-old", 1, 0, 3, "old", "named", 0, 4, 4, 4, True),
    ("mixed-sibling", 1, 0, 3, "sibling", "named", 0, 4, 4, 4, False),
    ("mixed-stale", 1, 0, 3, "current", "stale", 0, 4, 4, 4, False),
    ("mixed-crossed-read", 1, 0, 3, "current", "crossed", 0, 4, 4, 4, False),
)

def freeze_file(path, data):
    with path.open("xb") as out:
        out.write(data.encode("utf-8"))

def digest(data):
    return sha256(data).hexdigest()

rows = []
for case, first, second, rank, source, shape, check, main, compare, candidate, native in scenarios:
    first_field, second_field = field[first], field[second]
    first_peer, second_peer = field[1 - first], field[1 - second]
    exchange = header if shape != "tail" else header.replace(
        "    let old = replace(slot, mode);\n    old", "    replace(slot, mode)"
    )
    text = exchange + prefix.format(rank=rank)
    actual = {
        "current": f"active@{first_field}",
        "literal": "u8(19)",
        "old": "old_active",
        "sibling": f"active@{first_peer}",
    }[source]
    first_call = f"    let old_active = loan_write(active@{first_field}) {{ |slot| install(slot, selected) }};\n"
    transfer = f"    let incoming = {actual};\n"
    second_peer_base = "active" if shape == "crossed" else "standby"
    text += transfer + first_call if shape == "stale" else first_call + transfer
    text += (
        f"    let old_standby = loan_write(standby@{second_field}) {{ |slot| install(slot, incoming) }};\n"
        f"    let active_after = active@{first_field};\n"
        f"    let active_peer = active@{first_peer};\n"
        f"    let standby_after = standby@{second_field};\n"
        f"    let standby_peer = {second_peer_base}@{second_peer};\n"
        "    let first_previous = old_active;\n"
        "    let second_previous = old_standby;\n"
        "    return unit;\n"
        "}\n"
    )
    planned = 4032 if rank < 8 else 4096
    selected = 35 if rank < 8 else 93
    incoming = {"current": selected, "literal": 19, "old": active_initial[first],
                "sibling": active_initial[1 - first]}[source]
    expected = (planned, selected, incoming, active_initial[first], selected,
                active_initial[1 - first], standby_initial[second], incoming,
                standby_initial[1 - second])
    path = source_dir / f"{case}.nl"
    freeze_file(path, text)
    data = path.read_bytes()
    values = ",".join(map(str, expected)) if native else ""
    rows.append((case, len(data), digest(data), f"{first}{second}", source,
                 check, main, compare, candidate, values))

# Same root with different positions stays under the existing reloan rule.
same_root = header + prefix.format(rank=3).replace(
    "    let standby = QueueModes{normal_mode: u8(149), reserve_mode: u8(101)};\n", ""
) + """    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let incoming = u8(19);
    let old_second = loan_write(active@reserve_mode) { |slot| install(slot, incoming) };
    let after = active@normal_mode;
    let peer = active@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_second;
    return unit;
}
"""
escape = """struct QueueModes { reserve_mode: u8, normal_mode: u8 }

fn main() -> unit {
    let active = QueueModes{normal_mode: u8(41), reserve_mode: u8(117)};
    let outside = loan_write(active@normal_mode) { |slot| slot };
    let old = replace(outside, u8(35));
    return unit;
}
"""
for case, text, check, emit in (
    ("same-root-different-position", same_root, 0, 4),
    ("scope-escape", escape, 3, 3),
):
    path = source_dir / f"{case}.nl"
    freeze_file(path, text)
    data = path.read_bytes()
    rows.append((case, len(data), digest(data), "", case, check, emit, emit, emit, ""))

with (here / "oracle.tsv").open("x", newline="") as out:
    table = writer(out, delimiter="\t", lineterminator="\n")
    table.writerow(("case", "bytes", "sha256", "positions", "actual",
                    "check", "main", "compare", "candidate", "values"))
    table.writerows(rows)
