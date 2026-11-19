import hashlib,json
from pathlib import Path
from meter import run,E
W=Path('/workspace/NewLang_P1535');B=Path('/workspace/p1531-evidence/build-gcc');T=W/'tests/p1535'
libs=[B/f'libnewlang_{x}.a' for x in ['semantic','parser','lexer','checked','syntax','source','diagnostic']]
run('build public owned probe1', ['gcc','-std=c17','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(W/'include'),T/'public_owned.c',*libs,'-o',E/'public_owned'],probe=1)
for v,s,i,k in [('zero',0,91,23),('nonzero',42,91,23),('composed',37,83,27)]:
    p=T/f'P-{v}.nl';raw=E/'baseline'/f'{v}.c'
    run('baseline CHECK '+v,[B/'newlangc','--check',p])
    run('baseline genuine owned '+v,[E/'public_owned',p,str(s),str(i),str(k)])
    run('baseline C17 FIRST refusal '+v,[B/'newlangc','--emit-c17-to',raw,p],expect=4)
    assert not raw.exists()
    run('baseline API refusal '+v,[B/'p1529_consumer','refuse',p])
for name,p in [('fourzero',W/'tests/p1517/P-zero.nl'),('fournonzero',W/'tests/p1517/P-nonzero.nl'),('livetail',W/'tests/p1481/Z-success-zero.nl')]:
    run('baseline unchanged C17 '+name,[B/'newlangc','--emit-c17-to',E/'baseline'/f'{name}.c',p])
