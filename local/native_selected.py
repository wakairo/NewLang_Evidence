from pathlib import Path
import hashlib,importlib.util,json
from meter import E,run
W=Path('/workspace/NewLang_P1539');T=W/'tests/p1535';D=E/'native';D.mkdir()
C=Path('/workspace/NewLang_P1525_tooling/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-23')
assert hashlib.sha256(C.read_bytes()).hexdigest()=='913453afb492abab17025139852413ba7fd7a52b4fb75fcce58ff3fe399d0a9e'
run('pinned reused Clang identity',[C,'--version'])
spec=importlib.util.spec_from_file_location('own_p1535_native',T/'native.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
def counted(label,argv,**kwargs):
    return run(label,argv,selected=2 if label.endswith('-cc') else 1,**kwargs)
for cc,san,variant in [('/usr/bin/gcc','none','zero'),('/usr/bin/gcc','none','nonzero'),(C,'address','zero'),(C,'address','nonzero'),(C,'none','nonzero'),(C,'undefined','nonzero')]:
    extra={} if variant=='zero' else dict(initial=83,sibling=27,first=83,prefix=2)
    exe=D/(('gcc' if str(cc)=='/usr/bin/gcc' else 'clang')+'-'+san+'-'+variant)
    m.compile_guest(counted,cc,E/(variant+'.c'),T,exe,0 if variant=='zero' else 37,san,**extra)
    m.execute_worlds(counted,exe)
