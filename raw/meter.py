import fcntl,json,os,subprocess,time
from pathlib import Path
E=Path('/workspace/p1535-evidence');(E/'logs').mkdir(exist_ok=True)
def run(label,argv,local=1,native=0,frontend=0,probe=0,host=0,sites=(),env=None,expect=0):
    with (E/'ledger.lock').open('a+') as f:
        fcntl.flock(f,fcntl.LOCK_EX);p=E/'ledger.jsonl'
        rows=[json.loads(x) for x in p.read_text().splitlines()] if p.exists() else []
        for k,v,lim in [('local',local,128),('native',native,24),('frontend',frontend,2),('probe',probe,2),('host',host,12)]:
            assert sum(r[k] for r in rows)+v<=lim,('BUDGET STOP',k)
        allsites=set(sites)
        for r in rows:allsites.update(r['sites'])
        assert len(allsites)<=4,('BUDGET STOP','sites')
        n=len(rows)+1
        with p.open('a') as s:s.write(json.dumps(dict(id=n,label=label,argv=list(map(str,argv)),local=local,native=native,frontend=frontend,probe=probe,host=host,sites=list(sites),env_overrides=env or {},time=time.time()))+'\n')
    r=subprocess.run(list(map(str,argv)),capture_output=True,env=dict(os.environ,**(env or {})))
    for ext,b in [('stdout',r.stdout),('stderr',r.stderr)]:(E/'logs'/f'{n:04d}.{ext}').write_bytes(b)
    with (E/'results.jsonl').open('a') as f:f.write(json.dumps(dict(id=n,exit=r.returncode,time=time.time()))+'\n')
    print(label,n,r.returncode,r.stdout[-800:].decode(errors='replace'),r.stderr[-1000:].decode(errors='replace'),flush=True)
    if expect is not None:assert r.returncode==expect,(label,r.returncode,expect)
    return r
