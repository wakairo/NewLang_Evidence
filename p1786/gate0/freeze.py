from csv import writer
from hashlib import sha256
from pathlib import Path

here = Path(__file__).resolve().parent
cases = here / 'cases'

prefix = """struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
WRITER
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(OLD), route_tag: u8(117)};
STANDBY    let rank = usize(RANK);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
"""

first = "    let first_old = loan_write(active@mode) { |field| install(field, selected) };\n"
second = "    let second_old = loan_write(OTHER@mode) { |field| install(field, INCOMING) };\n"
finish = "    return unit;\n}\n"

def case(flow, *, high=False, tail=False):
    paired = flow not in ('same-original', 'single-original')
    text = prefix.replace('WRITER', '    replace(slot, mode)' if tail else
                          '    let displaced = replace(slot, mode);\n    displaced')
    text = text.replace('OLD', '57' if high else '41').replace('RANK', '14' if high else '3')
    standby = ("    let standby = ReceiveSetting{mode: u8(" +
               ('102' if high else '101') + "), route_tag: u8(149)};\n")
    text = text.replace('STANDBY', standby if paired else '')
    if flow == 'pre-change-read':
        text += '    let fallback = active@mode;\n'
    text += first
    if flow == 'single-original':
        return text + '''    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let displaced_active = first_old;
''' + finish
    if flow == 'same-original':
        text += '    let intermediate = active@mode;\n'
    expr = {
        'fallback': 'first_old',
        'same-original': 'u8(19)',
        'literal': 'u8(19)',
        'current': 'active@mode',
        'wrong-origin': 'selected',
        'wrong-actual': 'first_old',
    }
    if flow != 'pre-change-read':
        text += f'    let fallback = {expr[flow]};\n'
    text += second.replace('OTHER', 'standby' if paired else 'active').replace(
        'INCOMING', 'selected' if flow == 'wrong-actual' else 'fallback')
    text += '''    let active_mode = active@mode;
    let active_tag = active@route_tag;
'''
    if paired:
        text += '''    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
'''
    return text + '''    let displaced_active = first_old;
    let displaced_second = second_old;
''' + finish

escape = """struct ReceiveSetting { route_tag: u8, mode: u8 }

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let escaped = loan_write(active@mode) { |field| field };
    return unit;
}
"""

inputs = [
    ('fallback-low', case('fallback'), 0, 4, 4, 'fallback', '4032,35,41,41,35,117,101,41,149'),
    ('fallback-high', case('fallback', high=True), 0, 4, 4, 'fallback', '4096,93,57,57,93,117,102,57,149'),
    ('fallback-tail', case('fallback', tail=True), 0, 4, 4, 'fallback', '4032,35,41,41,35,117,101,41,149'),
    ('literal-standby', case('literal'), 0, 0, 0, 'literal', '4032,35,19,41,35,117,101,19,149'),
    ('current-standby', case('current'), 0, 4, 0, 'current', '4032,35,35,41,35,117,101,35,149'),
    ('same-original', case('same-original'), 0, 0, 0, 'same', '4032,35,41,35,35,19,117'),
    ('single-original', case('single-original'), 0, 0, 0, 'single', '4032,35,41,35,117'),
    ('other-copy', case('wrong-origin'), 0, 4, 4, 'non-result-copy', ''),
    ('fallback-wrong-actual', case('wrong-actual'), 0, 4, 4, 'unrelated-actual', ''),
    ('pre-change-read', case('pre-change-read'), 0, 4, 4, 'read-outside-result', ''),
    ('scope-escape', escape, 3, 3, 3, 'escape', ''),
]
with (here / 'oracle.tsv').open('x', newline='') as table:
    out = writer(table, delimiter='\t', lineterminator='\n')
    out.writerow(('case', 'bytes', 'sha256', 'check', 'main', 'compare', 'diagnostic', 'role', 'values'))
    for name, text, check, main, compare, role, values in inputs:
        data = text.encode()
        with (cases / f'{name}.nl').open('xb') as source:
            source.write(data)
        diagnostic = 'P8-EXIT-DEPENDENCY' if check == 3 else ('V1-BACKEND-UNSUPPORTED' if 4 in (main, compare) else '')
        out.writerow((name, len(data), sha256(data).hexdigest(), check, main, compare, diagnostic, role, values))
