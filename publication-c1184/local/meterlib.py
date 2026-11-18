import fcntl
import json
import os
from pathlib import Path
import time

ROOT = Path('/workspace/p1525-evidence')

def record(label, argv, local=1, native=0, host_cases=0, **extra):
    with (ROOT / 'ledger.lock').open('a+') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        path = ROOT / 'ledger.jsonl'
        rows = [json.loads(x) for x in path.read_text().splitlines()] if path.exists() else []
        totals = {k: sum(r.get(k, 0) for r in rows) for k in ('local', 'native', 'host_cases')}
        for key, value, limit in [('local', local, 320), ('native', native, 64), ('host_cases', host_cases, 48)]:
            if totals[key] + value > limit:
                raise RuntimeError(f'P1525 BUDGET STOP {key}: {totals[key]}+{value}>{limit}')
        row = dict(id=len(rows)+1, time=time.time(), label=label,
                   argv=[str(x) for x in argv], local=local, native=native,
                   host_cases=host_cases, **extra)
        with path.open('a') as stream:
            stream.write(json.dumps(row) + '\n')
        return row['id']

def finish(number, code, stdout=None, stderr=None):
    if stdout is not None:
        (ROOT / 'logs' / f'{number:04d}.stdout').write_bytes(stdout if isinstance(stdout, bytes) else stdout.encode())
    if stderr is not None:
        (ROOT / 'logs' / f'{number:04d}.stderr').write_bytes(stderr if isinstance(stderr, bytes) else stderr.encode())
    with (ROOT / 'results.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(id=number, exit=code, time=time.time()))+'\n')
