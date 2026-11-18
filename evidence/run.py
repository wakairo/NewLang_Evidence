import argparse
import os
from pathlib import Path
import subprocess
import sys
from meterlib import record, finish

p=argparse.ArgumentParser()
p.add_argument('--label', required=True)
p.add_argument('--local', type=int, default=1)
p.add_argument('--native', type=int, default=0)
p.add_argument('--host-cases', type=int, default=0)
p.add_argument('--phase', default='selected')
p.add_argument('argv', nargs=argparse.REMAINDER)
a=p.parse_args()
argv=a.argv[1:] if a.argv[0]=='--' else a.argv
n=record(a.label,argv,a.local,a.native,a.host_cases,phase=a.phase)
env=dict(os.environ,P1525_PHASE=a.phase)
env['PYTHONPATH']='/workspace/p1525-evidence'+(os.pathsep+env['PYTHONPATH'] if env.get('PYTHONPATH') else '')
r=subprocess.run(argv,env=env,capture_output=True)
finish(n,r.returncode,r.stdout,r.stderr)
print(f'P1525 id={n} exit={r.returncode} label={a.label}',flush=True)
sys.stdout.buffer.write(r.stdout[-5000:])
sys.stderr.buffer.write(r.stderr[-5000:])
sys.exit(r.returncode)
