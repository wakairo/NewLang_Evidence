from csv import DictReader
from hashlib import sha256
import json
from pathlib import Path
from shlex import join
from subprocess import run
import sys

here = Path(__file__).resolve().parent

def trace(folder, label, args):
    (folder / f'{label}.command').write_text(join(map(str, args)) + '\n')
    result = run(args, capture_output=True, check=False)
    (folder / f'{label}.stdout').write_bytes(result.stdout)
    (folder / f'{label}.stderr').write_bytes(result.stderr)
    (folder / f'{label}.status').write_text(f'{result.returncode}\n')
    return result

def state(path):
    info = path.stat()
    return tuple(getattr(info, n) for n in (
        'st_dev', 'st_ino', 'st_mode', 'st_size', 'st_mtime_ns', 'st_ctime_ns'
    ))

if __name__ == '__main__':
    cli, raw = [Path(s).resolve() for s in sys.argv[1:3]]
    stage = sys.argv[3]
    raw.mkdir(parents=True)
    print(f'compiler\t{cli}\t{sha256(cli.read_bytes()).hexdigest()}', flush=True)
    with (here / 'oracle.tsv').open() as table:
        for row in DictReader(table, delimiter='\t'):
            name = row['case']
            source = here / 'cases' / (name + '.nl')
            data = source.read_bytes()
            assert len(data) == int(row['bytes']) and sha256(data).hexdigest() == row['sha256']
            case = raw / name
            case.mkdir()
            check = trace(case, 'check', [cli, '--check', source])
            if row['role'] == 'escape' and check.returncode == 0:
                raise RuntimeError('scope escape was unexpectedly accepted at CHECK')
            emit = trace(case, 'c17', [cli, source])
            first, second = case / 'existing.c', case / 'absent.c'
            sentinel = b'/* P1786 pre-existing C17 destination */\n'
            first.write_bytes(sentinel)
            before = state(first)
            existing = trace(case, 'named-existing', [cli, '--emit-c17-to', first, source])
            absent = trace(case, 'named-absent', [cli, '--emit-c17-to', second, source])
            after = state(first)
            residue = list(case.glob('*.tmp.*'))
            details = dict(initial=before, final=after, absent=not second.exists(),
                           staging=[p.name for p in residue],
                           existing_sha256=sha256(first.read_bytes()).hexdigest())
            (case / 'named-state.json').write_text(json.dumps(details, sort_keys=True) + '\n')
            assert emit.returncode == existing.returncode == absent.returncode, (stage, name)
            assert not residue and not check.stdout and not existing.stdout and not absent.stdout, (stage, name)
            if check.returncode == 0:
                assert not check.stderr, (stage, name)
            if emit.returncode == 0:
                assert check.returncode == 0 and emit.stdout, (stage, name)
                assert not emit.stderr and not existing.stderr and not absent.stderr, (stage, name)
                assert emit.stdout == first.read_bytes() == second.read_bytes(), (stage, name)
            else:
                assert not emit.stdout and not second.exists(), (stage, name)
                assert first.read_bytes() == sentinel and before == after, (stage, name)
                if emit.returncode == 4:
                    for result in (emit, existing, absent):
                        assert b'V1-BACKEND-UNSUPPORTED' in result.stderr, (stage, name)
                elif row['role'] == 'escape':
                    for result in (check, emit, existing, absent):
                        assert b'P8-EXIT-DEPENDENCY' in result.stderr, (stage, name)
                for result in (check, emit, existing, absent):
                    assert b'Sanitizer' not in result.stderr and b'runtime error:' not in result.stderr
            expected = int(row['main' if stage == 'main' else 'compare'])
            if stage == 'candidate':
                expected = 0 if row['role'] == 'fallback' else int(row['main'])
            match = (check.returncode == int(row['check']) and emit.returncode == expected)
            print(name, check.returncode, emit.returncode, existing.returncode,
                  absent.returncode, 'match' if match else 'prediction-difference',
                  sep='\t', flush=True)
