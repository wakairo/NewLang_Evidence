import sys
from pathlib import Path
from meter import run,E
W=Path('/workspace/NewLang_P1535');T=W/'tests/p1535'
sys.path.insert(0,str(T))
from native import compile_guest,execute_worlds
sdk=Path('/workspace/NewLang_P1525_tooling/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64')
def cc_run(label,argv,**kwargs):
    return run(label,argv,local=2,**kwargs) # two source TUs, charged separately
def execute_group(group):
    if group=='first':
        matrix=[('zero',0,'gcc','none',{}),('nonzero',42,'gcc','none',{}),('zero',0,str(sdk/'bin/clang-23'),'address',{}),('nonzero',42,str(sdk/'bin/clang-23'),'address',{}),('composed',37,str(sdk/'bin/clang-23'),'undefined',dict(initial=83,sibling=27,first=83,prefix=2)),('fourzero',0,'gcc','none',dict(has_read=0))]
    else:
        matrix=[('composed',37,str(sdk/'bin/clang-23'),'none',dict(initial=83,sibling=27,first=83,prefix=2))]
    for v,s,cc,san,extra in matrix:
        name=f'{v}-{Path(cc).name}-{san}';o=E/'native';o.mkdir(exist_ok=True);exe=o/name
        compile_guest(cc_run,cc,E/'generated'/f'{v}.c',T,exe,s,san,**extra)
        execute_worlds(run,exe)
if __name__=='__main__':execute_group(sys.argv[1])
