from csv import DictReader
from functools import partial
from pathlib import Path
from shutil import which
import runpy
import sys

here = Path(__file__).resolve().parents[1]
pinned_runner = Path(sys.argv[1]).resolve()
protocol = runpy.run_path(str(pinned_runner))
native = protocol['support']['native']
hosts = [('gcc', which('gcc')), ('clang', which('clang-23'))]
with (here / 'oracle.tsv').open() as table:
    oracle = {row['case']: row for row in DictReader(table, delimiter='\t')}
cases = {
    'literal-standby': ('main', protocol['observe_independent']),
    'same-original': ('main', protocol['observe_sequence']),
    'single-original': ('main', protocol['observe']),
    'current-standby': ('compare', partial(protocol['observe_independent'], observed_mode=True))
}
out = here / 'alternatives/native'
out.mkdir()
for case, (stage, observer) in cases.items():
    raw = out / case
    raw.mkdir()
    generated = here / 'raw' / ('exact-' + stage) / case / 'existing.c'
    contents = generated.read_bytes()
    if stage == 'main':
        counterpart = here / 'raw/exact-compare' / case / 'existing.c'
        assert contents == counterpart.read_bytes()
    else:
        assert (here / 'raw/exact-main' / case / 'c17.status').read_text().strip() == '4'
    observed = raw / 'observed.c'
    observed.write_bytes(observer(contents, b'1'))
    values = oracle[case]['values'].split(',')
    if case == 'literal-standby':
        del values[2]
    want = (','.join(values) + '\n').encode()
    for host_name, compiler in hosts:
        assert compiler
        native(raw, compiler, [(host_name + '-original', generated, b''),
                               (host_name + '-observed', observed, want)])
    print(case, stage, 'PASS', ','.join(values), sep='\t', flush=True)
