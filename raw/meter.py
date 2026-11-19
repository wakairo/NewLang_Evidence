"""C1230 additional fixed-input GCC phase; old C1223 ledger stays immutable."""
from pathlib import Path
import fcntl,json,os,subprocess,time
E=Path('/workspace/p1535-c1230-gcc')
def run(label,argv,frontend=0,probe=0,expect=0):
    with (E/'ledger.lock').open('a+') as lock:
        fcntl.flock(lock,fcntl.LOCK_EX)
        p=E/'ledger.jsonl'
        rows=[json.loads(x) for x in p.read_text().splitlines()] if p.exists() else []
        assert len(rows)<32, 'selected budget STOP C'
        assert sum(r['frontend'] for r in rows)+frontend<=1
        assert sum(r['probe'] for r in rows)+probe<=1
        n=len(rows)+1
        with p.open('a') as f:f.write(json.dumps(dict(id=n,label=label,argv=list(map(str,argv)),selected=1,frontend=frontend,probe=probe,native=0,hostfault=0,SDK=0,time=time.time()))+'\n')
    t=time.monotonic();r=subprocess.run(list(map(str,argv)),capture_output=True)
    for ext,b in [('stdout',r.stdout),('stderr',r.stderr)]:(E/'logs'/f'{n:02d}.{ext}').write_bytes(b)
    with (E/'results.jsonl').open('a') as f:f.write(json.dumps(dict(id=n,exit=r.returncode,elapsed_seconds=time.monotonic()-t,expected=expect))+'\n')
    print(label,n,r.returncode,r.stdout[-1000:].decode(errors='replace'),r.stderr[-1600:].decode(errors='replace'),flush=True)
    assert r.returncode==expect,('STOP C fixed input failure',label,r.returncode,expect)
    return r
