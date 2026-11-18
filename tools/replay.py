"""Git-only replay; never executes a compiler, native program or CI."""
from pathlib import Path
import hashlib,json,subprocess,sys
A=Path(sys.argv[1]).resolve();D=Path(sys.argv[2]).resolve();receipt=Path(sys.argv[3]).resolve()
assert not D.exists();D.mkdir()
m=json.loads((A/'candidate/metadata.json').read_text());commands=[]
def git(*args):
 r=subprocess.run(['git',*args],cwd=D,capture_output=True)
 commands.append(dict(argv=['git',*args],exit=r.returncode,stdout=r.stdout.decode(errors='replace'),stderr=r.stderr.decode(errors='replace')))
 receipt.with_suffix('.commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 assert r.returncode==0,commands[-1]
 return r.stdout
git('init','-q')
git('fetch','--depth=1','https://github.com/wakairo/NewLang_Compiler.git',m['base'])
git('checkout','--detach',m['base'])
assert git('rev-parse','HEAD^{tree}').decode().strip()==m['base_tree']
git('apply','--index',str(A/'candidate/local-candidate.patch'))
tree=git('write-tree').decode().strip();assert tree==m['tree']
for name in m['changed_paths']:
 p=D/name;q=A/'candidate/source'/name
 assert p.read_bytes()==q.read_bytes()
 assert bool(p.stat().st_mode&0o111)==bool(q.stat().st_mode&0o111)
raw=(A/'candidate/original.commit').read_bytes()
assert hashlib.sha1(b'commit '+str(len(raw)).encode()+b'\0'+raw).hexdigest()==m['head']
assert git('hash-object','-w','-t','commit',str(A/'candidate/original.commit')).decode().strip()==m['head']
git('reset','--hard',m['head'])
assert not git('status','--porcelain=v1')
receipt.write_text(json.dumps(dict(parent=m['base'],parent_tree=m['base_tree'],head=m['head'],replayed_tree=tree,all_changed_files=len(m['changed_paths']),bytes_modes='ALL_MATCH',original_commit_reconstructed=True,compiler_native_CI_runs=0),indent=2)+'\n')
print(receipt.read_text())
