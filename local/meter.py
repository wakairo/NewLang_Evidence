from pathlib import Path
import fcntl,json,os,subprocess,time
E=Path('/workspace/p1539-c1240-local')
def run(label,argv,selected=1,native=0,frontend=0,probe=0,host=0,sites=(),env=None,expect=0):
    with (E/'ledger.lock').open('a+') as f:
        fcntl.flock(f,fcntl.LOCK_EX);p=E/'ledger.jsonl'
        rows=[json.loads(s) for s in p.read_text().splitlines()] if p.exists() else []
        for k,v,limit in [('selected',selected,140),('native',native,24),('frontend',frontend,3),('probe',probe,3),('host',host,10)]:assert sum(r[k] for r in rows)+v<=limit,('STOP C BUDGET',k)
        allsites=set(sites)
        for r in rows:allsites.update(r['sites'])
        assert len(allsites)<=3
        n=len(rows)+1
        with p.open('a') as s:s.write(json.dumps(dict(id=n,label=label,argv=list(map(str,argv)),selected=selected,native=native,frontend=frontend,probe=probe,host=host,sites=list(sites),env=env or {},time=time.time()))+'\n')
    t=time.monotonic();r=subprocess.run(list(map(str,argv)),capture_output=True,env=dict(os.environ,**(env or {})))
    for ext,b in [('stdout',r.stdout),('stderr',r.stderr)]:(E/'logs'/f'{n:03d}.{ext}').write_bytes(b)
    with (E/'results.jsonl').open('a') as s:s.write(json.dumps(dict(id=n,exit=r.returncode,expected=expect,seconds=time.monotonic()-t))+'\n')
    print(label,n,r.returncode,r.stdout[-1000:].decode(errors='replace'),r.stderr[-1300:].decode(errors='replace'),flush=True)
    if expect is not None:assert r.returncode==expect,('STOP/repair candidate within scope',label,r.returncode,expect)
    return r
