from pathlib import Path
from meter import run,E
W=Path('/workspace/NewLang_P1535');T=W/'tests/p1535';B=E/'build-asan';O=E/'named';O.mkdir(exist_ok=True)
for n in ['foreign-domain','foreign-allocation','foreign-pointer','live-read-at-end','post-end-read']:
    p=T/f'N-{n}.nl'
    run('negative CHECK '+n,[B/'newlangc','--check',p],expect=3)
    run('negative rollback '+n,[B/'p1517_safety','negative',p])
run('five-step genuine artifact authentication and retry',[B/'p1517_safety','attack',T/'P-zero.nl'])
run('composed prefix fact and original origin authentication',[B/'p1529_consumer','attack',T/'P-composed.nl'])
p=W/'tests/p1531/N-live-prefix.nl'
run('held LiveTail prefix CHECK',[B/'newlangc','--check',p])
run('held LiveTail prefix authentic MACHINE',['/workspace/NewLang_Compiler/build-frontend/p1481_probe','owned',p,'0','0'])
target=O/'held.c';sentinel=b'P1535 held named target remains unchanged\n';target.write_bytes(sentinel)
run('held LiveTail prefix C17 no clobber',[B/'newlangc','--emit-c17-to',target,p],expect=4)
assert target.read_bytes()==sentinel and not list(O.glob('held.c.tmp.*'))
run('held LiveTail prefix API refusal rollback',[B/'p1529_consumer','refuse',p])
for point in [3,4,5]:
    run(f'material host OOM {point} fault plus retry',[B/'p1517_safety','oom',T/'P-zero.nl',str(point)],host=2,sites=[str(point)])
for point in [1,2]:
    target=O/f'fault{point}.c';target.write_bytes(sentinel)
    site=str(point+2)
    run(f'named host text fault {point}',[B/'p1517_cli_fault','--emit-c17-to',target,T/'P-zero.nl'],host=1,sites=[site],expect=1,env={'P1517_HOST_TEXT_FAIL':str(point)})
    assert target.read_bytes()==sentinel and not list(O.glob(target.name+'.tmp.*'))
    run(f'named host pristine retry {point}',[B/'newlangc','--emit-c17-to',target,T/'P-zero.nl'],host=1,sites=[site])
    assert target.read_bytes()==(E/'generated/zero.c').read_bytes() and not list(O.glob(target.name+'.tmp.*'))
