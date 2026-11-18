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
assert argv and '/' not in label
ledger = root / 'attempts.json'
entries = json.loads(ledger.read_text()) if ledger.exists() else []
assert len(entries) < 24
assert not any(e['label'] == label for e in entries)
for m in json.loads((root / 'FIRST-manifest.json').read_text()):
    b = (root / m['path']).read_bytes()
    assert len(b) == m['bytes'] and hashlib.sha256(b).hexdigest() == m['sha256'], m['path']
logs = root / 'logs'
logs.mkdir(exist_ok=True)
prefix = logs / f'{len(entries)+1:02d}-{label}'
before = os.statvfs(root)
entry = {'attempt': len(entries)+1, 'label': label, 'argv': argv,
         'utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
         'status': 'STARTED', 'charge': 1, 'nested_compiler_commands': 0,
         'free_bytes_before': before.f_bavail*before.f_frsize,
         'free_inodes_before': before.f_favail}
entries.append(entry)
ledger.write_text(json.dumps(entries, indent=2)+'\n')
start = time.monotonic()
with prefix.with_suffix('.stdout').open('wb') as out, prefix.with_suffix('.stderr').open('wb') as err:
    result = subprocess.run(argv, cwd='/workspace/NewLang_Compiler', stdout=out, stderr=err, timeout=180)
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
ledger.write_text(json.dumps(entries, indent=2)+'\n')
print(json.dumps(entry, indent=2))
print(prefix.with_suffix('.stdout').read_text(errors='replace')[:12000])
print(prefix.with_suffix('.stderr').read_text(errors='replace')[:12000])
