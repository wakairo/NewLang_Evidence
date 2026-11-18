import subprocess,sys,json,time,hashlib
from pathlib import Path
p=Path('/workspace/p1507-evidence'); ledger=p/'attempts.json'; rows=json.loads(ledger.read_text()) if ledger.exists() else []
label=sys.argv[1]; cmd=sys.argv[2:]; assert len(rows)<48
assert not any(r['label']==label for r in rows)
r={'attempt':len(rows)+1,'label':label,'argv':cmd,'state':'started'};rows.append(r);ledger.write_text(json.dumps(rows,indent=2)+'\n');t=time.monotonic()
x=subprocess.run(cmd,capture_output=True); r.update(state='completed',exit=x.returncode,seconds=time.monotonic()-t)
for suffix,b in [('stdout',x.stdout),('stderr',x.stderr)]:
 f=p/(label+'.'+suffix);f.write_bytes(b);r[suffix]={'size':len(b),'sha256':hashlib.sha256(b).hexdigest()}
ledger.write_text(json.dumps(rows,indent=2)+'\n');print(json.dumps(r));print(x.stdout.decode(errors='replace')[-1600:]);print(x.stderr.decode(errors='replace')[-1600:]);sys.exit(x.returncode)
