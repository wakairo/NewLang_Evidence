import os
from pathlib import Path
import subprocess
import sys
from meterlib import record, finish

real=sys.argv[1]
argv=[real,*sys.argv[2:]]
phase=os.environ.get('P1525_PHASE','selected')
units=sum(x.endswith('.c') for x in argv[1:])
charge=0 if phase=='whole-build' else max(1,units)
n=record('CC '+Path(real).name,argv,charge,phase=phase,translation_units=units,actual_tool=str(Path(real).resolve()))
r=subprocess.run(argv,capture_output=True)
finish(n,r.returncode,r.stdout,r.stderr)
sys.stdout.buffer.write(r.stdout)
sys.stderr.buffer.write(r.stderr)
sys.exit(r.returncode)
