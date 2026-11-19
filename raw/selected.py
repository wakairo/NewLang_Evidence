from pathlib import Path
import hashlib,json,sys
sys.path.insert(0,'/workspace/p1531-evidence')
from meter import run
E=Path('/workspace/p1531-evidence');R=Path('/workspace/NewLang_P1531')
sdk=Path('/workspace/NewLang_P1525_tooling/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64')
env={'ASAN_OPTIONS':'detect_leaks=1:halt_on_error=1','UBSAN_OPTIONS':'halt_on_error=1:print_stacktrace=1'}
raws={}
for p in [*sorted((R/'tests/p1517').glob('P-*.nl')),*sorted((R/'tests/p1529').glob('[ABCD]-*.nl'))]:
    original=p.parent.name=='p1517';sample=(42 if 'nonzero' in p.stem else 0) if original else (37 if 'nonzero' in p.stem else 0)
    name=p.parent.name+'-'+p.stem;B=E/'build-gcc';raw=E/(name+'.c');raws[name]=raw
    run('CHECK '+name,[B/'newlangc','--check',p])
    run('OWNED '+name,[B/('p1517_public_owned' if original else 'p1529_public_owned'),p,sample])
    run('C17 '+name,[B/'newlangc','--emit-c17-to',raw,p])
    run('API agreement '+name,[B/'p1529_consumer','agree',p,raw])
    if original:
        historic=Path('/workspace/p1525-evidence/build-gcc/p1517-native')
        matches=list(historic.glob('*/'+('nonzero.c' if sample else 'zero.c')))
        assert len(matches)==1 and matches[0].read_bytes()==raw.read_bytes()
    else:assert raw.read_bytes()==(Path('/workspace/p1529-evidence')/(p.stem+'.c')).read_bytes()
for name in ['A-prefix-zero','D-combined-nonzero']:
    B=E/'build-asan';p=R/'tests/p1529'/(name+'.nl');raw=E/(name+'.asan.c')
    run('ASan CHECK '+name,[B/'newlangc','--check',p],env=env)
    run('ASan OWNED '+name,[B/'p1529_public_owned',p,37 if 'nonzero' in name else 0],env=env)
    run('ASan C17 '+name,[B/'newlangc','--emit-c17-to',raw,p],env=env)
    assert raw.read_bytes()==raws['p1529-'+name].read_bytes()
    run('ASan API agreement '+name,[B/'p1529_consumer','agree',p,raw],env=env)
for p in sorted((R/'tests/p1529').glob('N-*.nl')):
    run('source negative '+p.stem,[E/'build-gcc/newlangc','--check',p],expect=3)
    run('ASan negative rollback '+p.stem,[E/'build-asan/p1517_safety','negative',p],env=env)
run('ASan four artifact negatives + retries',[E/'build-asan/p1529_consumer','attack',R/'tests/p1529/D-combined-nonzero.nl'],env=env)
sys.path.insert(0,str(R/'tests/p1529'))
from native import compile_and_run,CASES
for tag,cc,san,cases in [('gcc','/usr/bin/gcc','none',[CASES[0],CASES[3]]),('clang',str(sdk/'bin/clang-23'),'none',[CASES[0],CASES[3]]),('asan',str(sdk/'bin/clang-23'),'address',[CASES[3]]),('ubsan',str(sdk/'bin/clang-23'),'undefined',[CASES[0]])]:
    out=E/('native-'+tag);out.mkdir(exist_ok=True)
    def selected(label,argv,units=1,guest=False,setting=None):
        return run(tag+' '+label,argv,local=units,native=int(guest),env=dict(env,**(setting or {})))
    for case in cases:compile_and_run(cc,R/'tests/p1529',raws['p1529-'+case[0]],out,case,2,san,selected)
for point in [2,3,4,5]:
    run('host fault+retry '+str(point),[E/'build-gcc/p1517_safety','oom',R/'tests/p1529/D-combined-nonzero.nl',point],host=2)
out=E/'named';out.mkdir(exist_ok=True);target=out/'result.c';sentinel=b'P1531 named target original\n'
for point in [1,2]:
    target.write_bytes(sentinel)
    run('named fault '+str(point),[E/'build-gcc/p1517_cli_fault','--emit-c17-to',target,R/'tests/p1529/A-prefix-zero.nl'],host=1,env={'P1517_HOST_TEXT_FAIL':str(point)},expect=1)
    assert target.read_bytes()==sentinel and not list(out.glob('result.c.tmp.*'))
    run('named retry '+str(point),[E/'build-gcc/p1517_cli_fault','--emit-c17-to',target,R/'tests/p1529/A-prefix-zero.nl'],host=1)
    assert target.read_bytes()==raws['p1529-A-prefix-zero'].read_bytes() and not list(out.glob('result.c.tmp.*'))
target.write_bytes(sentinel)
run('named semantic negative',[E/'build-gcc/newlangc','--emit-c17-to',target,R/'tests/p1529/N-foreign-domain.nl'],expect=3)
assert target.read_bytes()==sentinel and not list(out.glob('result.c.tmp.*'))
run('named semantic retry',[E/'build-gcc/newlangc','--emit-c17-to',target,R/'tests/p1529/A-prefix-zero.nl'])
assert target.read_bytes()==raws['p1529-A-prefix-zero'].read_bytes()
run('staged exact CTest inventory',['/workspace/newlang-tools/bin/ctest','--test-dir',E/'build-gcc','--show-only=json-v1'])
row=json.loads((E/'ledger.jsonl').read_text().splitlines()[-1]);inventory=json.loads((E/'logs'/f"{row['id']:04d}.stdout").read_text())
names=[x['name'] for x in inventory['tests']]
assert len([x for x in names if x.startswith('p1517_')])==18
assert len([x for x in names if x.startswith('p1529_')])==10
(E/'inventory-summary.json').write_text(json.dumps(dict(total=len(names),p1517=[x for x in names if x.startswith('p1517_')],p1529=[x for x in names if x.startswith('p1529_')],full_CTest_executed=False),indent=2)+'\n')
rows=[json.loads(x) for x in (E/'ledger.jsonl').read_text().splitlines()]
print('FINAL COUNTERS',{k:sum(r[k] for r in rows) for k in ['local','native','build','host']})
