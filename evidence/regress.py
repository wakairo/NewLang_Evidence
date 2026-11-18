"""Run bounded slices of existing P-owned fixtures/oracles, unchanged."""
import json
import os
from pathlib import Path
import subprocess
from meterlib import record, finish

root=Path('/workspace/p1525-evidence')
repo=Path('/workspace/NewLang_P1525')
out=root/'regress'
out.mkdir(exist_ok=True)
gcc=root/'build-gcc/newlangc'
clang=root/'build-clang/newlangc'
strict=['-std=c17','-Wall','-Wextra','-Wpedantic','-Werror','-O2']
rows=[]

def run(label,argv,expected=0,guest=False,env=None):
    argv=[str(x) for x in argv]
    number=record(label,argv,native=1) if guest else None
    r=subprocess.run(argv,env=env,capture_output=True)
    if number:
        finish(number,r.returncode,r.stdout,r.stderr)
    (out/(label+'.stdout')).write_bytes(r.stdout)
    (out/(label+'.stderr')).write_bytes(r.stderr)
    rows.append(dict(label=label,argv=argv,expected=expected,exit=r.returncode,guest=guest))
    (out/'ledger.json').write_text(json.dumps(rows,indent=2)+'\n')
    assert r.returncode==expected,(rows[-1],r.stdout,r.stderr)
    if guest:
        assert b'PASS' in r.stdout,(rows[-1],r.stdout)

for source in sorted((repo/'tests/p1517').glob('N-*.nl')):
    run('CLI-'+source.stem,[clang,'--check',source],3)

tests=repo/'tests/p1507'
for index,name in enumerate(['A-direct-zero','B-direct-index-one']):
    raw=out/(name+'.c');exe=out/name
    run('emit-'+name,[gcc,'--emit-c17-to',raw,tests/(name+'.nl')])
    run('cc-'+name,[root/'cc-gcc',*strict,f'-DNEWLANG_NODE_OBSERVER="{tests}/passive.h"',
        f'-DNEWLANG_HEAP_OBSERVER="{tests}/passive.h"',f'-DP1507_INDEX={index}',raw,
        tests/'guest_wrap.c','-Wl,--wrap=malloc','-Wl,--wrap=free','-o',exe])
    for fail in [1,2,0]:
        run(name+f'-fail{fail}',[exe],guest=True,env=dict(os.environ,P1507_FAIL_AT=str(fail)))

tests=repo/'tests/p1481'
raw=out/'Z-success-zero.c'
run('emit-linked-zero',[clang,'--emit-c17-to',raw,tests/'Z-success-zero.nl'])
for fail in [1,2,0]:
    exe=out/f'linked-zero-asan-fail{fail}'
    run(f'cc-linked-fail{fail}',[root/'cc-clang',*strict,'-fsanitize=address',
        '-fno-omit-frame-pointer','-fno-sanitize-recover=all',
        f'-DNEWLANG_NODE_OBSERVER="{tests}/passive.h"',
        f'-DNEWLANG_HEAP_OBSERVER="{tests}/passive.h"',f'-DP1463_FAIL_AT={fail}',
        '-DP1481_SAMPLE=0','-DP1463_FIELD_INDEX=0',raw,tests/'../p1463/guest_wrap.c',
        '-Wl,--wrap=malloc','-Wl,--wrap=free','-o',exe])
    run(f'linked-fail{fail}',[exe],guest=True,
        env=dict(os.environ,ASAN_OPTIONS='detect_leaks=1:halt_on_error=1'))
print('P1525 original negative CLI7 + inline native6 + linked ASan native3 PASS')
