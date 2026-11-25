from csv import DictReader
from hashlib import sha256
from pathlib import Path
from shutil import which
import sys

from run_gate import trace

here = Path(__file__).resolve().parent
src = here / 'comparison-c'
out = Path(sys.argv[1]).resolve()
out.mkdir(parents=True)
gcc, clang = which('gcc'), which('clang-23')
assert gcc and clang
profiles = [
    ('gcc-O0', gcc, ['-O0']),
    ('gcc-O2', gcc, ['-O2']),
    ('clang-O0', clang, ['-O0']),
    ('clang-O2', clang, ['-O2']),
    ('clang-sanitized', clang, ['-O1', '-g0', '-fsanitize=address,undefined',
                                '-fno-sanitize-recover=all']),
]
with (here / 'oracle.tsv').open() as table:
    cases = [(row['case'], row['values']) for row in DictReader(table, delimiter='\t') if row['values']]
for label, compiler, flags in profiles:
    work = out / label
    work.mkdir()
    writer = work / 'exchange.o'
    exe = work / 'caller'
    strict = ['-std=c17', '-pedantic-errors', '-Wall', '-Wextra', '-Werror']
    def call(step, args):
        result = trace(work, step, [compiler, *strict, *flags, *args])
        if result.returncode or result.stderr:
            raise RuntimeError(f'{label} {step}: status {result.returncode}\n{result.stderr.decode()}')
    call('writer', ['-c', src / 'exchange.c', '-o', writer])
    call('caller', [src / 'caller.c', writer, '-o', exe])
    digest = sha256(writer.read_bytes()).hexdigest()
    for case, expected in cases:
        result = trace(work, case, [exe, case])
        assert result.returncode == 0 and not result.stderr, (label, case, result)
        assert result.stdout == (expected + '\n').encode(), (label, case, expected, result)
        print(label, case, expected, f'exchange={digest}', sep='\t', flush=True)
