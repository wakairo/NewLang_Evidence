import fcntl,json,os,subprocess,time
from pathlib import Path
E=Path('/workspace/p1531-evidence/amendment');(E/'logs').mkdir(exist_ok=True)
def run(label,argv,local=1,native=0,build=0,host=0,env=None,expect=0):
    assert host==0,'C1213 new host fault forbidden'
    with (E/'ledger.lock').open('a+') as f:
        fcntl.flock(f,fcntl.LOCK_EX);p=E/'ledger.jsonl'
        rows=[json.loads(x) for x in p.read_text().splitlines()] if p.exists() else []
        for k,v,lim in [('local',local,40),('native',native,6),('build',build,1)]:assert sum(r[k] for r in rows)+v<=lim,('BUDGET STOP',k)
        n=len(rows)+1
        with p.open('a') as s:s.write(json.dumps(dict(id=n,label=label,argv=list(map(str,argv)),local=local,native=native,build=build,host=0,env_overrides=env or {},time=time.time()))+'\n')
    r=subprocess.run(list(map(str,argv)),capture_output=True,env=dict(os.environ,**(env or {})))
    for ext,b in [('stdout',r.stdout),('stderr',r.stderr)]:(E/'logs'/f'{n:04d}.{ext}').write_bytes(b)
    with (E/'results.jsonl').open('a') as f:f.write(json.dumps(dict(id=n,exit=r.returncode,time=time.time()))+'\n')
    print(label,n,r.returncode,r.stdout[-1100:].decode(errors='replace'),r.stderr[-1200:].decode(errors='replace'),flush=True)
    if expect is not None:assert r.returncode==expect,(label,r.returncode,expect)
    return r
