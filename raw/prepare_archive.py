from pathlib import Path
import hashlib,json,shutil,stat,subprocess
E=Path('/workspace/p1529-evidence');R=Path('/workspace/NewLang_P1529');S=Path('/workspace/p1529-custody-stage')
assert not S.exists(); S.mkdir()
def git(*a):return subprocess.check_output(['git',*a],cwd=R)
def write(p,b):
 q=S/p;q.parent.mkdir(parents=True,exist_ok=True);q.write_bytes(b);q.chmod(0o644)
provenance=[]
def copy(p,dest):
 assert p.is_file() and not p.is_symlink()
 b=p.read_bytes();write(dest,b)
 if p.stat().st_mode&0o111:(S/dest).chmod(0o755)
 provenance.append(dict(original=str(p),archive=dest,bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
head=git('rev-parse','HEAD').decode().strip();base='7deabd1b1f44bc40862b6a28c89fde502832d8cb'
assert head=='738024ff18973459c1ec83efcf8dbd92619fb0bd' and not git('status','--porcelain=v1')
assert git('rev-parse','HEAD^').decode().strip()==base
changed=git('diff','--name-only',base,head).decode().splitlines()
for path in changed:copy(R/path,'candidate/source/'+path)
write('candidate/original.commit',git('cat-file','commit',head))
copy(E/'local-candidate.patch','candidate/local-candidate.patch')
meta=dict(issue=1529,release='C1202',status='LOCAL READY / WAIT PUBLICATION',head=head,tree=git('rev-parse','HEAD^{tree}').decode().strip(),base=base,base_tree='20083ff35349efd254e015f90dcac38a8d16852a',adopted_main='c97ce81c48a0c003b072c77c655bdeb10860ebf1',main_tree='7591cf7c908c9f7258d0d9512fc79d084d73fbaa',spec='Draft17.38',changed_paths=changed,local=181,local_limit=192,native=45,native_limit=48,frontend_probe_builds=4,build_limit=4,host_sites=6,host_site_limit=8,host_cases=22,host_case_limit=24,SDK_acquisition=0,Compiler_remote_branch_PR_push_CI=0,independent_FR_original_read=False,prior_P1517_P1525_P1528_FIRST_RED_results_counters_unchanged=True)
write('candidate/metadata.json',(json.dumps(meta,indent=2)+'\n').encode())
for p in sorted(E.iterdir()):
 if p.is_file() and p.suffix in {'.txt','.json','.jsonl','.py','.c','.h','.diff'}:
  copy(p,'raw/'+p.name)
for p in sorted((E/'logs').iterdir()):
 assert p.suffix in {'.stdout','.stderr'};copy(p,'raw/logs/'+p.name)
for p in sorted((E/'old-native').glob('*.c')):copy(p,'raw/old-native/'+p.name)
copy(E/'build-asan/Testing/Temporary/LastTest.log','raw/ctest/LastTest.log')
copy(Path('/workspace/p1525-evidence/sdk-receipt.json'),'provenance/reused-p1525-sdk-receipt.json')
copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
copy(E/'replay_archive.py','tools/replay.py')
write('custody/original-path-provenance.json',(json.dumps(provenance,indent=2)+'\n').encode())
write('README.md',b'''# P1529 C1202 local-only prefix-read repair

Compiler/main c97 is adopted; candidate parent7de and local738 are unadopted.
No Compiler push/PR/CI. This Evidence ref is custody, not publication/adoption.
Original P1517/P1525/P1528 FIRST/RED and worktrees stay retained. New raw/
contains complete own FIRST/oracle/apparatus revisions and stdout/stderr,
ledger, original baseline refusals, unexpected already-supported old-Copy
initializer success, observer compilation RED and formatter RED, then repairs.
candidate/ contains final source, exact format-patch and raw original commit.
No SDK, executable, object, build tree, secret or independent F/R raw included.
See candidate/metadata.json and raw/PREP-FINAL.txt for scope/results/debt.

Verify the manifest SHA from Issue1529, from a fresh empty HTTPS clone:
  python tools/verify_members.py . MANIFEST_SHA
Then replay Git only (no compiler/native/CI execution):
  python tools/replay.py . /new/empty/replay /outside/receipt.json
This fetches the fixed public Compiler parent7de over HTTPS, applies the patch,
verifies tree/all16 source files/modes and reconstructs the original commit.
Archive manifest covers all paths except itself, including sizes/SHA/Git mode.
Only self-owned temporary clones may be removed after POST/GET restore receipt.
Active original worktrees, commits, raw and SDK are retained.
Finite capability PASS is not UB-audit-locality proof or Product GO.
''')
rows=[]
for p in sorted(S.rglob('*')):
 if p.is_file():
  b=p.read_bytes();rows.append(dict(path=str(p.relative_to(S)),bytes=len(b),sha256=hashlib.sha256(b).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644'))
manifest=dict(schema='p1529-evidence-v1',members=rows)
write('manifest.json',(json.dumps(manifest,indent=2)+'\n').encode())
total=sum(x['bytes'] for x in rows)+(S/'manifest.json').stat().st_size
assert len(rows)+1<=1024 and total<=16*1024*1024
print(json.dumps(dict(files=len(rows)+1,bytes=total,manifest_sha256=hashlib.sha256((S/'manifest.json').read_bytes()).hexdigest()),indent=2))
