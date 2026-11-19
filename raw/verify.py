"""Existing fixed cases only. Each child command separately metered."""
from pathlib import Path
import hashlib,json,sys
from meter import run,E
W=Path('/workspace/NewLang_P1535');T=W/'tests/p1535';B=E/'build-gcc'
expected=json.loads((E/'FIRST-linkage.json').read_text())['expected_frozen_C']
def same_output(name):
    p=E/'generated'/f'{name}.c';r=expected[p.name];b=p.read_bytes()
    assert len(b)==r['bytes'] and hashlib.sha256(b).hexdigest()==r['sha256'],('STOP C frozen bytes drift',name)
def positives():
    for v,s,i,k in [('zero',0,91,23),('nonzero',42,91,23),('composed',37,83,27)]:
        p=T/f'P-{v}.nl';raw=E/'generated'/f'{v}.c'
        run('GCC CHECK '+v,[B/'newlangc','--check',p])
        run('GCC genuine public owned '+v,[B/'p1535_public_owned',p,str(s),str(i),str(k)])
        run('GCC C17 '+v,[B/'newlangc','--emit-c17-to',raw,p]);same_output(v)
        run('GCC C17 API CLI frozen agreement '+v,[B/'p1529_consumer','agree',p,raw])
def controls():
    for n,p in [('fourzero',W/'tests/p1517/P-zero.nl'),('livetail',W/'tests/p1481/Z-success-zero.nl')]:
        raw=E/'generated'/f'{n}.c'
        run('GCC existing control CHECK '+n,[B/'newlangc','--check',p])
        run('GCC existing control C17 '+n,[B/'newlangc','--emit-c17-to',raw,p]);same_output(n)
        run('GCC existing control API CLI '+n,[B/'p1529_consumer','agree',p,raw])
def negatives(names):
    for n in names:
        run('GCC original negative CHECK '+n,[B/'newlangc','--check',T/f'N-{n}.nl'],expect=3)
def remaining():
    negatives(['foreign-pointer','live-read-at-end','post-end-read'])
    p=W/'tests/p1531/N-live-prefix.nl';raw=E/'generated/held.c'
    sentinel=b'P1535 C1230 fixed held output must stay unchanged\n';raw.write_bytes(sentinel)
    run('GCC existing held CHECK',[B/'newlangc','--check',p])
    run('GCC existing held C17 no clobber',[B/'newlangc','--emit-c17-to',raw,p],expect=4)
    assert raw.read_bytes()==sentinel and not list(raw.parent.glob(raw.name+'.tmp.*'))
    run('GCC existing held API refusal state preserved',[B/'p1529_consumer','refuse',p])
    p=W/'tests/p1517/P-nonzero.nl';raw=E/'generated/fournonzero.c'
    run('GCC existing4step42 C17',[B/'newlangc','--emit-c17-to',raw,p]);same_output('fournonzero')
    run('GCC existing4step42 API CLI agreement',[B/'p1529_consumer','agree',p,raw])
if __name__=='__main__':
    if sys.argv[1]=='first':
        positives();controls();negatives(['foreign-domain','foreign-allocation'])
    elif sys.argv[1]=='remaining':remaining()
    else:raise ValueError(sys.argv[1])
