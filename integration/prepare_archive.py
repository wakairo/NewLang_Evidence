from pathlib import Path
import hashlib,json,os,subprocess
E=Path('/workspace/p1539-c1243-integration');W=Path('/workspace/NewLang_P1539_integration');S=Path('/workspace/p1539-c1243-custody-stage')
summary=json.loads((E/'summary.json').read_text());assert summary['public_candidate_HEADs']==1 and summary['natural_jobs']==8
assert not S.exists();S.mkdir();copies=[]
def copy(p,name):
 assert p.is_file() and not p.is_symlink()
 b=p.read_bytes();assert not b.startswith((b'\x7fELF',b'!<arch>'))
 q=S/name;q.parent.mkdir(parents=True,exist_ok=True);q.write_bytes(b);q.chmod(0o755 if p.stat().st_mode&0o111 else 0o644)
 copies.append(dict(original=str(p),archive=name,bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
for p in sorted(E.iterdir()):
 if p.is_file() and p.suffix in {'.json','.jsonl','.txt','.py','.commit'}:copy(p,'integration/'+p.name)
for name in ['ci','logs']:
 for p in sorted((E/name).rglob('*')):
  if p.is_file():copy(p,'integration/'+str(p.relative_to(E)))
for p in sorted((E/'build-gcc/p1539-native').iterdir()):
 if p.is_file() and p.suffix in {'.json','.stdout','.stderr','.c'}:copy(p,'integration/native/'+p.name)
copy(E/'build-gcc/Testing/Temporary/LastTest.log','integration/local-selected-LastTest.log')
copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
(S/'provenance.json').write_text(json.dumps(copies,indent=2)+'\n')
(S/'README.md').write_text('''P1539/C1243 sole P normal test integration and first public natural CI custody.

Compiler PR1542 was published DRAFT HOLD and C adopted it after all8 success.
C receipt7004480375 records actualmaina9715f4bc788c13e213231c639057c2d718a9200,
same tree/ordered parents[main9c,HEAD9bb]. P READY/merge0. New-main CI is C-owned
and remains separate, not inferred PASS here. PublicHEAD9bb09dd172fd3fd9ed0f2958dc2203092181d397,
treeb7a0ab30f9150143df2434e8e478232daf9ca951, sole parentmain9c9b17f7f0584c88a92ab284f57e4a93b8ab350b.
Production2blobs1d17ce025905b18b0b92dbae81ffb8f3d27f947f/10fe0ac4d98a55f261a34c9ad1508a7f5d2e4b8b
are byte-identical to old locala026; no production reformat/semantic change.
13 paths add normal10 tests and minimal CMake. All6 old source hashes unchanged.
The public fixed Compiler commit, manifest correspondence and raw commit identify
all source inputs; this cohort does not duplicate old0355 packet.

integration/ holds new local selected build/inventory/result/raw and publication
API/commit/correspondence. ci/ preserves all8 ORIGINAL complete connector-decoded
job logs, exact UTF8 re-encoding with BOM/newlines. No rerun or ZIP claim.
Native local raw/commands cover actual CLI CHECK/API byte equality, strictC17 O2
real zero/nonzero H0/H1/H2. Probe uses genuine source-issued owned evidence;
physical observer/wrapper and negative/fault engines are reused unchanged.
CI log analysis authenticates actual checkout110692e27da7a498e19c97c17f84b8b7e76dce25,
ordered parents[9c9b17f...,9bb09dd...] and exact same tree; FULL1201x5,
PARTIAL1200x1 including real CLI exit0/empty streams, EARLY84x2. Each Required6
executes new10 incl native. EARLY's new-test coverage0 is explicit. Successful
native CTest execution is verified in original CI logs; per-guest CI workdirs are
not claimed restored. Local per-command native raw is included separately.

One publicHEAD, one normalpush, one DRAFT PR, three natural runs/eight jobs,
manualretry/dispatch/cancel/force/secondHEAD0. Additional local99selected,
1freshfrontend/1probe/6guests/2hostsites4cases. No localfullCTest/LLVM/newSDK.
Old100selected/18guest/incremental builds/FIRST/probeRED/C17RED remain in
archive/p1539-c1240-local-20261119 commit0355cdce066f2a457013bac0b3b62d5d25f6480e.
No F/R independent originals, credentials, SDK, ELF/build objects or Git auth
configuration are included. Actual original/new worktrees/raw/builds and needed
SDK stay local. The read-only CI collector was paused/resumed for custody prep;
no Actions run/job was cancelled or retried.

Use a fresh empty HTTPS clone of archive/p1539-c1243-integration-20261119 and
verify_members.py with the externally recorded manifest SHA. Every actual path,
count/size/SHA/mode/Git blob must match before deleting only redundant newly
owned temporary clones. This proves byte restoration, not semantic correctness,
independent safety review or Product value. READY/merge belongs to Coordination.

VALUE-ALIGNMENT-RISK: finite ordinary identity-helper composition and normal
delivery do not establish a useful protected API, all safe-reachable states or
reduced library-author+ordinary-safe-caller UB audit/re-audit dependency closure.
Original issuer/R/A/D/current/legalwriter/failure/teardown/reentrancy/FFI closure
still matters. ProductGO PAUSED/H1 HOLD/comparative UNMEASURED; direct snapshot
unitclose/T, factored C and sound Rust remain alternatives. No next inert
profile/source/API/issuer expansion is granted by this completed delivery unit.
''')
members=[dict(path=p.relative_to(S).as_posix(),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644') for p in sorted(S.rglob('*')) if p.is_file()]
(S/'manifest.json').write_text(json.dumps(dict(owner='sole Track P',cohort='P1539 C1243 normal integration + eight original CI',head=summary['head'],tree=summary['tree'],pr=1542,members=members),indent=2)+'\n')
r=dict(ref='archive/p1539-c1243-integration-20261119',files=len(members)+1,bytes=sum(x['bytes'] for x in members)+(S/'manifest.json').stat().st_size,largest_bytes=max(x['bytes'] for x in members),manifest_sha256=hashlib.sha256((S/'manifest.json').read_bytes()).hexdigest())
assert r['files']<=512 and r['bytes']<=16*1024*1024
v=os.statvfs('/workspace');r['disk_before']=dict(available_bytes=v.f_bavail*v.f_frsize,free_inodes=v.f_favail)
(E/'archive-preflight.json').write_text(json.dumps(r,indent=2)+'\n')
subprocess.run(['git','init','-b',r['ref'],str(S)],check=True,capture_output=True)
for key,fmt in [('user.name','%an'),('user.email','%ae')]:
 name=subprocess.check_output(['git','-C',str(W),'log','-1','--format='+fmt],text=True).strip();subprocess.run(['git','-C',str(S),'config',key,name],check=True)
subprocess.run(['git','-C',str(S),'add','-f','--','.'],check=True)
subprocess.run(['git','-C',str(S),'commit','-m','Preserve P1539 C1243 normal integration and eight original natural CI results'],check=True,capture_output=True)
r.update(commit=subprocess.check_output(['git','-C',str(S),'rev-parse','HEAD'],text=True).strip(),tree=subprocess.check_output(['git','-C',str(S),'rev-parse','HEAD^{tree}'],text=True).strip())
(E/'archive-local.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
