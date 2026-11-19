from pathlib import Path
import hashlib,json
from meter import run,E
W=Path('/workspace/NewLang_P1539');B=Path('/workspace/p1535-c1230-gcc/build-gcc');D=E/'build-gcc';D.mkdir()
flags=['-D_FORTIFY_SOURCE=2','-O3','-DNDEBUG','-std=c17','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(W/'include')]
old=[B/'CMakeFiles/newlang_checked_c_node.dir/src/checked_c_five.c.o',B/'CMakeFiles/newlang_checked_c_node.dir/src/readonly_u8_consumer_internal.c.o']
libs=[B/('libnewlang_'+x+'.a') for x in ['semantic','diagnostic','checked','parser','diagnostic','syntax','lexer','source']]
main=B/'CMakeFiles/newlangc.dir/src/main.c.o';consumer=B/'CMakeFiles/p1529_consumer.dir/tests/p1529/consumer.c.o'
items=[*old,*libs,main,consumer]
(E/'incremental-build-provenance.json').write_text(json.dumps({'base_tree':'a7e0561c7b57e03330b1d1d91c90300dd093f938','method':'only changed translation unit checked_c_node.c including private header; all other source/headers identical to exact cached base; GCC flags unchanged; new backend archive and two links, no old outputs overwritten','compiler':'/usr/bin/gcc','flags':flags,'unchanged_inputs':[dict(path=str(p),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in items]},indent=2)+'\n')
run('candidate GCC frontend build1 changed TU',['/usr/bin/gcc',*flags,'-c',W/'src/checked_c_node.c','-o',D/'checked_c_node.c.o'],frontend=1)
run('candidate archive unchanged backend objects',['/usr/bin/ar','rcs',D/'libnewlang_checked_c_node.a',D/'checked_c_node.c.o',*old])
run('candidate frontend link',['/usr/bin/gcc',*flags,main,D/'libnewlang_checked_c_node.a',*libs,'-o',D/'newlangc'])
run('candidate API checker link',['/usr/bin/gcc',*flags,'-Wl,--wrap=malloc','-Wl,--wrap=realloc','-Wl,--wrap=nl_sem_clone',consumer,D/'libnewlang_checked_c_node.a',*libs,'-o',D/'p1529_consumer'])
run('candidate CLI C17 zero',[D/'newlangc','--emit-c17-to',E/'zero.c',E/'source/P-zero.nl'],expect=None)
