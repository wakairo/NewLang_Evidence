from pathlib import Path
import hashlib,json
from meter import run,E
W=Path('/workspace/NewLang_P1539');B=Path('/workspace/p1535-evidence/build-asan');D=E/'build-asan';D.mkdir()
C=Path('/workspace/NewLang_P1525_tooling/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-23')
assert hashlib.sha256(C.read_bytes()).hexdigest()=='913453afb492abab17025139852413ba7fd7a52b4fb75fcce58ff3fe399d0a9e'
flags=['-O2','-g','-DNDEBUG','-std=c17','-Wall','-Wextra','-Wpedantic','-Werror','-fsanitize=address','-fno-omit-frame-pointer','-fno-sanitize-recover=all','-I'+str(W/'include')]
old=[B/'CMakeFiles/newlang_checked_c_node.dir/src/checked_c_five.c.o',B/'CMakeFiles/newlang_checked_c_node.dir/src/readonly_u8_consumer_internal.c.o']
libs=[B/('libnewlang_'+x+'.a') for x in ['semantic','diagnostic','checked','parser','diagnostic','syntax','lexer','source']]
objects={name:B/f'CMakeFiles/{name}.dir'/(f'src/main.c.o' if name=='newlangc' else f'tests/{"p1529/consumer" if name=="p1529_consumer" else "p1517/safety"}.c.o') for name in ['newlangc','p1529_consumer','p1517_safety']}
inputs=[*old,*libs,*objects.values()]
(E/'incremental-asan-provenance.json').write_text(json.dumps({'method':'recompile changed TU/header only; cache source before formatter token-identical for unchanged units, git b1..7b changes no other production TU/headers; no cached outputs overwritten','compiler':str(C),'flags':flags,'inputs':[dict(path=str(p),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in inputs]},indent=2)+'\n')
run('candidate Clang ASan frontend build2 changed TU',[C,*flags,'-c',W/'src/checked_c_node.c','-o',D/'checked_c_node.c.o'],frontend=1)
run('candidate ASan archive',['/usr/bin/ar','rcs',D/'libnewlang_checked_c_node.a',D/'checked_c_node.c.o',*old])
for name,obj in objects.items():
    wrap=[] if name=='newlangc' else ['-Wl,--wrap=malloc','-Wl,--wrap=realloc','-Wl,--wrap=nl_sem_clone']
    run('candidate ASan link '+name,[C,*flags,*wrap,obj,D/'libnewlang_checked_c_node.a',*libs,'-o',D/name])
for variant in ['zero','nonzero']:
    run('ASan frontend CHECK '+variant,[D/'newlangc','--check',E/f'source/P-{variant}.nl'])
    run('ASan frontend emit '+variant,[D/'newlangc','--emit-c17-to',E/f'{variant}-asan-frontend.c',E/f'source/P-{variant}.nl'])
    assert (E/f'{variant}-asan-frontend.c').read_bytes()==(E/f'{variant}.c').read_bytes()
    run('ASan API bytes '+variant,[D/'p1529_consumer','agree',E/f'source/P-{variant}.nl',E/f'{variant}.c'])
for p in sorted((E/'source').glob('N-*.nl')):
    run('final ASan frontend negative '+p.name,[D/'newlangc','--check',p],expect=3)
for variant in ['zero','nonzero']:
    for site,name in [(4,'receiver_text'),(5,'trailing_copy_replay')]:
        run('new composed path ASan OOM '+variant+' '+name,[D/'p1517_safety','oom',E/f'source/P-{variant}.nl',str(site)],selected=2,host=2,sites=[name])
