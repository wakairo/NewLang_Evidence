# Exact body of the executed selected host campaign, retained after execution.
# Do not rerun during custody. Uses existing apparatus, no new fault engine.
from pathlib import Path
import sys
sys.path.insert(0,'/workspace/p1529-evidence')
from meter import run
E=Path('/workspace/p1529-evidence');T=Path('/workspace/NewLang_P1529/tests/p1529')
env={'ASAN_OPTIONS':'detect_leaks=1:halt_on_error=1','UBSAN_OPTIONS':'halt_on_error=1:print_stacktrace=1'}
for point in range(6):
    run('GCC host fault/retry site '+str(point),[E/'build-gcc/p1517_safety','oom',T/'A-prefix-zero.nl',point],host=2)
for point in [3,4,5]:
    run('ASan host fault/retry site '+str(point),[E/'build-asan/p1517_safety','oom',T/'D-combined-nonzero.nl',point],host=2,env=env)
out=E/'named';out.mkdir(exist_ok=True);target=out/'result.c'
sentinel=b'P1529 no-clobber original target\n'
for point in [1,2]:
    target.write_bytes(sentinel)
    run('GCC named fault '+str(point),[E/'build-gcc/p1517_cli_fault','--emit-c17-to',target,T/'A-prefix-zero.nl'],host=1,env={'P1517_HOST_TEXT_FAIL':str(point)},expect=1)
    assert target.read_bytes()==sentinel and not list(out.glob('result.c.tmp.*'))
    run('GCC named retry '+str(point),[E/'build-gcc/p1517_cli_fault','--emit-c17-to',target,T/'A-prefix-zero.nl'],host=1)
    assert target.read_bytes()==(E/'A-prefix-zero.c').read_bytes() and not list(out.glob('result.c.tmp.*'))
target.write_bytes(sentinel)
run('named semantic negative',[E/'build-gcc/newlangc','--emit-c17-to',target,T/'N-foreign-domain.nl'],expect=3)
assert target.read_bytes()==sentinel and not list(out.glob('result.c.tmp.*'))
run('named semantic retry',[E/'build-gcc/newlangc','--emit-c17-to',target,T/'A-prefix-zero.nl'])
assert target.read_bytes()==(E/'A-prefix-zero.c').read_bytes()
print('6 unique host sites /22 cases, named no-clobber/rollback PASS')
