from pathlib import Path
import fcntl,json,os,subprocess,time
E=Path('/workspace/p1539-c1243-integration')
def run(label,argv,selected=1,frontend=0,probe=0,native=0,host=0,sites=(),expect=0,env=None):
 with (E/'ledger.lock').open('a+') as f:
  fcntl.flock(f,fcntl.LOCK_EX);p=E/'ledger.jsonl';rows=[json.loads(s) for s in p.read_text().splitlines()] if p.exists() else []
  for key,value,limit in [('selected',selected,100),('frontend',frontend,2),('probe',probe,2),('native',native,12),('host',host,8)]:assert sum(r[key] for r in rows)+value<=limit,('STOP C BUDGET',key)
  allsites=set(sites)
  for r in rows:allsites.update(r['sites'])
  assert len(allsites)<=2
  n=len(rows)+1
  with p.open('a') as out:out.write(json.dumps(dict(id=n,label=label,argv=list(map(str,argv)),selected=selected,frontend=frontend,probe=probe,native=native,host=host,sites=list(sites),env=env or {},time=time.time()))+'\n')
 t=time.monotonic();r=subprocess.run(list(map(str,argv)),capture_output=True,env=dict(os.environ,**(env or {})))
 for ext,b in [('stdout',r.stdout),('stderr',r.stderr)]:(E/'logs'/f'{n:03d}.{ext}').write_bytes(b)
 with (E/'results.jsonl').open('a') as out:out.write(json.dumps(dict(id=n,exit=r.returncode,expected=expect,seconds=time.monotonic()-t))+'\n')
 print(label,n,r.returncode,r.stdout[-1800:].decode(errors='replace'),r.stderr[-1200:].decode(errors='replace'),flush=True)
 if expect is not None:assert r.returncode==expect,('preserve FIRST; test plumbing only repair allowed',label)
 return r
