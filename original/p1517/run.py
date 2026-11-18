from pathlib import Path
import datetime
import hashlib
import json
import os
import resource
import subprocess
import sys
import time

root = Path(__file__).resolve().parent
label, *argv = sys.argv[1:]
guest = argv[0] == '--guest'
if guest: argv = argv[1:]
assert argv and '/' not in label
ledger = root / 'attempts.json'
entries = json.loads(ledger.read_text()) if ledger.exists() else []
charge = max(1, sum(x.endswith('.c') for x in argv)) if Path(argv[0]).name in ['gcc','clang','clang-23'] else 1
if label == 'ctest-owned-zero': charge = 2
assert sum(e['charge'] for e in entries) + charge <= 80
assert not any(e['label'] == label for e in entries)
assert sum(e.get('guest', False) for e in entries) + guest <= 36
for m in json.loads((root / 'oracle-FIRST.json').read_text())['files']:
    path = Path('/workspace/NewLang_P1517/tests/p1517') / m['path']
    if m['path'] == 'passive.h': path = path.parent / 'history/passive-v1.h.data'
    b = path.read_bytes()
    assert len(b) == m['bytes'] and hashlib.sha256(b).hexdigest() == m['sha256'], m['path']
logs = root / 'logs'
logs.mkdir(exist_ok=True)
prefix = logs / f'{len(entries)+1:02d}-{label}'
before = os.statvfs(root)
entry = {'attempt': len(entries)+1, 'label': label, 'argv': argv,
         'utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
         'status': 'STARTED', 'charge': charge, 'nested_compiler_commands': (1 if label == 'ctest-owned-zero' else 0), 'guest': guest, 'fail_at': os.environ.get('P1517_FAIL_AT'),
         'free_bytes_before': before.f_bavail*before.f_frsize,
         'free_inodes_before': before.f_favail}
entries.append(entry)
ledger.write_text(json.dumps(entries, indent=2)+'\n')
start = time.monotonic()
with prefix.with_suffix('.stdout').open('wb') as out, prefix.with_suffix('.stderr').open('wb') as err:
    result = subprocess.run(argv, cwd=os.environ.get('P1517_ATTEMPT_CWD', '/workspace/NewLang_P1517'), stdout=out, stderr=err, timeout=180)
after = os.statvfs(root)
entry.update(status='FINISHED', exit=result.returncode,
             seconds=round(time.monotonic()-start, 6),
             maxrss_kib_children=resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss,
             free_bytes_after=after.f_bavail*after.f_frsize,
             free_inodes_after=after.f_favail)
for kind in ['stdout','stderr']:
    p = prefix.with_suffix('.'+kind)
    b = p.read_bytes()
    entry[kind] = {'path': str(p.relative_to(root)), 'bytes': len(b), 'sha256': hashlib.sha256(b).hexdigest()}
latest = json.loads(ledger.read_text())
for i, row in enumerate(latest):
    if row['label'] == label: latest[i] = entry
ledger.write_text(json.dumps(latest, indent=2)+'\n')
print(json.dumps(entry, indent=2))
print(prefix.with_suffix('.stdout').read_text(errors='replace')[:12000])
print(prefix.with_suffix('.stderr').read_text(errors='replace')[:12000])
