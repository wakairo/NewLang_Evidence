import hashlib,json
from pathlib import Path
from meter import run,E
W=Path('/workspace/NewLang_P1535');B=E/'build-asan';T=W/'tests/p1535';(E/'generated').mkdir(exist_ok=True)
libs=[B/f'libnewlang_{x}.a' for x in ['semantic','parser','lexer','checked','syntax','source','diagnostic']]
# Public issuer source unchanged; public probe2 binary preserved, no third probe build.
for v,s,i,k in [('zero',0,91,23),('nonzero',42,91,23),('composed',37,83,27)]:
    p=T/f'P-{v}.nl';raw=E/'generated'/f'{v}.c'
    run('final CHECK '+v,[B/'newlangc','--check',p])
    run('final genuine owned '+v,[E/'public_owned_final',p,str(s),str(i),str(k)])
    run('final C17 '+v,[B/'newlangc','--emit-c17-to',raw,p])
    run('final CLI API agree '+v,[B/'p1529_consumer','agree',p,raw])
for name,p,sample in [('fourzero',W/'tests/p1517/P-zero.nl',0),('fournonzero',W/'tests/p1517/P-nonzero.nl',42)]:
    run('control CHECK '+name,[B/'newlangc','--check',p])
    run('control genuine owned '+name,['/workspace/p1531-evidence/build-gcc/p1517_public_owned',p,str(sample)])
    raw=E/'generated'/f'{name}.c'
    run('control C17 '+name,[B/'newlangc','--emit-c17-to',raw,p])
    run('control CLI API agree '+name,[B/'p1529_consumer','agree',p,raw])
    assert raw.read_bytes()==(E/'baseline'/raw.name).read_bytes()
p=W/'tests/p1481/Z-success-zero.nl';raw=E/'generated/livetail.c'
run('old zero prefix LiveTail CHECK',[B/'newlangc','--check',p])
run('old zero prefix LiveTail owned',['/workspace/NewLang_Compiler/build-frontend/p1481_probe','owned',p,'0','0'])
run('old zero prefix LiveTail C17',[B/'newlangc','--emit-c17-to',raw,p])
run('old zero prefix LiveTail API agree',[B/'p1529_consumer','agree',p,raw])
assert raw.read_bytes()==(E/'baseline'/raw.name).read_bytes()
(E/'control-byte-identity.json').write_text(json.dumps([dict(name=p.name,bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest(),identical_to_b1=True) for p in (E/'generated').iterdir() if p.stem in ['fourzero','fournonzero','livetail']],indent=2)+'\n')
