from pathlib import Path
import hashlib,json,subprocess
E=Path('/workspace/p1539-c1243-integration');W=Path('/workspace/NewLang_P1539_integration');O=Path('/workspace/NewLang_P1539')
def git(*a):return subprocess.check_output(['git','-C',str(W),*a])
head=git('rev-parse','HEAD').decode().strip();assert head=='9bb09dd172fd3fd9ed0f2958dc2203092181d397'
assert not git('status','--porcelain').strip()
paths=git('diff','--name-only','HEAD^','HEAD').decode().splitlines();assert len(paths)==13
rows=[]
for p in paths:
 q=W/p;b=q.read_bytes();rows.append(dict(path=p,blob=git('hash-object',p).decode().strip(),bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
prod=[]
for p in ['src/checked_c_node.c','src/checked_c_scalar_control_internal.h']:
 b=(W/p).read_bytes();assert b==(O/p).read_bytes();prod.append(dict(path=p,original_local='a026544d52ce631e339dbd5ec40c6fc3ebcca734',original_blob=subprocess.check_output(['git','-C',str(O),'rev-parse','HEAD:'+p],text=True).strip(),integration_blob=git('rev-parse','HEAD:'+p).decode().strip(),byte_identity=True,production_formatting=False))
sources=[]
for r in json.loads(Path('/workspace/p1539-c1240-local/FIRST-files.json').read_text()):
 if r['path'].startswith('source/'):
  q=W/'tests/p1539'/Path(r['path']).name;assert q.stat().st_size==r['bytes'] and hashlib.sha256(q.read_bytes()).hexdigest()==r['sha256'];sources.append(dict(original=r['path'],integration=str(q.relative_to(W)),bytes=r['bytes'],sha256=r['sha256'],unchanged=True))
out=dict(head=head,tree=git('rev-parse','HEAD^{tree}').decode().strip(),parent=git('rev-parse','HEAD^').decode().strip(),paths=rows,production=prod,source=sources,scope='only2 fixed production files plus rootinclude and10 test files',old_0355_not_rewritten=True)
(E/'integration-correspondence.json').write_text(json.dumps(out,indent=2)+'\n')
commands=json.loads((E/'fresh-build-commands.json').read_text())['compile_commands'];source=[]
for cmd in commands:
 p=Path(cmd.rsplit(' -c ',1)[1]);assert p.is_file();source.append(dict(path=str(p.relative_to(W)),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest(),blob=git('hash-object',str(p)).decode().strip(),command=cmd))
(E/'fresh-build-inputs.json').write_text(json.dumps(dict(head=head,all35_changed_or_unchanged_CUs_freshly_compiled=source,cached_objects_reused=0,compiler='/usr/bin/gcc',compiler_sha256=hashlib.sha256(Path('/usr/bin/x86_64-linux-gnu-gcc-14').read_bytes()).hexdigest(),flags='Release -O3 -DNDEBUG -D_FORTIFY_SOURCE=2 -std=c17 -Wall -Wextra -Wpedantic -Werror'),indent=2)+'\n')
print({'paths':len(rows),'source_first_equal':len(sources),'fixed_production_equal':len(prod),'fresh_CUs':len(source),'HEAD':head})
