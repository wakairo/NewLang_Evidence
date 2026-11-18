from pathlib import Path
import sys
sys.path.insert(0,'/workspace/p1529-evidence');from meter import run
sys.path.insert(0,'/workspace/NewLang_P1529/tests/p1529');from native import compile_and_run,CASES
E=Path('/workspace/p1529-evidence');T=Path('/workspace/NewLang_P1529/tests/p1529');clang='/workspace/NewLang_P1525_tooling/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-23'
for tag,cc,san,cases,opts in [('gcc','/usr/bin/gcc','none',CASES[:2],[0,2]),('clang',clang,'none',CASES[:2],[0,2]),('gcc-oldcopy','/usr/bin/gcc','none',CASES[2:],[2]),('clang-oldcopy',clang,'none',CASES[2:],[2]),('asan',clang,'address',[CASES[3]],[2]),('ubsan',clang,'undefined',[CASES[0]],[2])]:
 out=E/('native-'+tag);out.mkdir(exist_ok=True)
 def selected(label,argv,units=1,guest=False,setting=None):
  return run(tag+' '+label,argv,local=units,native=int(guest),env=dict({'ASAN_OPTIONS':'detect_leaks=1:halt_on_error=1','UBSAN_OPTIONS':'halt_on_error=1:print_stacktrace=1'},**(setting or {})))
 for case in cases:
  for opt in opts:compile_and_run(cc,T,E/(case[0]+'.c'),out,case,opt,san,selected)
