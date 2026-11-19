import fcntl,json,os,subprocess,time
from pathlib import Path
E=Path('/workspace/p1531-evidence');(E/'logs').mkdir(exist_ok=True)
def run(label,argv,local=1,native=0,build=0,host=0,env=None,expect=0):
    with (E/'ledger.lock').open('a+') as f:
        fcntl.flock(f,fcntl.LOCK_EX)
        p=E/'ledger.jsonl';rows=[json.loads(x) for x in p.read_text().splitlines()] if p.exists() else []
        for k,v,lim in [('local',local,96),('native',native,18),('build',build,2),('host',host,12)]:
            assert sum(r.get(k,0) for r in rows)+v<=lim,('BUDGET STOP',k)
        n=len(rows)+1
        with p.open('a') as s:s.write(json.dumps(dict(id=n,label=label,argv=list(map(str,argv)),local=local,native=native,build=build,host=host,env_overrides=env or {},time=time.time()))+'\n')
    r=subprocess.run(list(map(str,argv)),capture_output=True,env=dict(os.environ,**(env or {})))
    for suffix,b in [('stdout',r.stdout),('stderr',r.stderr)]:(E/'logs'/f'{n:04d}.{suffix}').write_bytes(b)
    with (E/'results.jsonl').open('a') as f:f.write(json.dumps(dict(id=n,exit=r.returncode,time=time.time()))+'\n')
    print(label,n,r.returncode,r.stdout[-750:].decode(errors='replace'),r.stderr[-1000:].decode(errors='replace'),flush=True)
    if expect is not None:assert r.returncode==expect,(label,r.returncode,expect)
    return r
