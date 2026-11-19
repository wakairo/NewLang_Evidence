"""One bounded C1230 raw cohort; no compiler/native invocation."""
from pathlib import Path
import hashlib,json,subprocess,sys
E=Path('/workspace/p1535-c1230-gcc');O=Path('/workspace/p1535-evidence');W=Path('/workspace/NewLang_P1535');S=Path('/workspace/p1535-c1230-custody-stage')
assert not S.exists();S.mkdir()
g=lambda *a:subprocess.check_output(['git',*a],cwd=W)
summary=json.loads((E/'summary.json').read_text())
assert summary['additional']['selected']==32 and summary['unexpected_failures']==0
assert not g('status','--porcelain') and g('rev-parse','HEAD').decode().strip()==summary['head']
rows=[]
for m in json.loads((O/'final-source-manifest.json').read_text()):
    p=W/m['path'];b=p.read_bytes();assert len(b)==m['bytes'] and hashlib.sha256(b).hexdigest()==m['sha256']
    rows.append(dict(**m,blob=g('rev-parse','HEAD:'+m['path']).decode().strip()))
(E/'source-identities.json').write_text(json.dumps(dict(head=summary['head'],tree=summary['tree'],parent=summary['parent'],clean=True,unchanged_final_members=rows),indent=2)+'\n')
provenance=[]
def copy(p,name):
    assert p.is_file() and not p.is_symlink()
    b=p.read_bytes();assert not b.startswith((b'\x7fELF',b'!<arch>')),str(p)
    q=S/name;q.parent.mkdir(exist_ok=True,parents=True);q.write_bytes(b);q.chmod(0o755 if p.stat().st_mode&0o111 else 0o644)
    provenance.append(dict(original=str(p),archive=name,bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
for p in sorted(E.iterdir()):
    if p.is_file() and p.suffix in {'.json','.jsonl','.py','.txt'}:copy(p,'raw/'+p.name)
for directory in ['logs','generated']:
    for p in sorted((E/directory).iterdir()):copy(p,'raw/'+directory+'/'+p.name)
copy(E/'build-gcc/CMakeCache.txt','build/CMakeCache.txt')
for n in ['newlangc','newlang_checked_c_node','p1529_consumer','p1535_public_owned']:
    for f in ['flags.make','link.txt']:copy(E/'build-gcc/CMakeFiles'/f'{n}.dir'/f,'build/'+n+'/'+f)
for n in ['oracle-FIRST.json','FINAL-POST-GET.json','final-source-manifest.json']:
    copy(O/n,'frozen-C1223/'+n)
copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
(S/'custody').mkdir();(S/'custody/original-path-provenance.json').write_text(json.dumps(provenance,indent=2)+'\n')
(S/'README.md').write_text('''# P1535 / C1230 fixed-candidate GCC closure

Same sole Track P, Compiler Issue1535 C1230 comment7000082606.
Fixed HEAD58245a24e047280304443258b2cfc8a540c9202a,
treea7e0561c7b57e03330b1d1d91c90300dd093f938,
parentb1a6f1725abe25981ad29088175de581f956f919;
Production src/checked_c_node.c blobe18c444ffc667be9022819c9b6151cf10b82d34b.
Code, tests, own oracle and local commit are unchanged. Public Compiler mainb2f
and PR1532 publication refb1a6 remain fixed. This is no Compiler publication.

GCC_VERIFIED: exact final formatted source and unchanged public probe built
under existing GCC14.2.0 Debian14.2.0-19, normal Release -O3 -DNDEBUG with
explicit -D_FORTIFY_SOURCE=2 and project -std=c17 -Wall -Wextra -Wpedantic
-Werror. Verbose build stdout, actual compile/link flags and executable hashes
are preserved. No executable, SDK, object/archive, full build directory,
credential, environment dump or independent R/F material is included.

The 32 additional selected invocations include GCC version/configure, one
frontend build and one public-probe build; three existing positive sources'
CHECK/genuine public-owned MACHINE5step/C17/API CLI frozen-byte agreement;
four-step0/42 and zero-prefix LiveTail controls; five original source negative
CHECKs; held LiveTailprefix CHECK then C17/API refusal and named no-clobber.
Every child compiler/probe command is metered and every stdout/stderr retained.
Nonzero exits are only the expected five CHECK3 and held backend CLI4.
No new guest-native, host fault, SDK acquisition, fullCTest or Compiler CI.
Original C1223 counters remain117selected/2frontend/2probe/21guest/3sites10host;
cumulative actuals149selected/3frontend/3probe, native/host unchanged.

Previous immutable Evidence ref archive/p1535-c1223-scoped-root-read-20261119
commit94fb7376d4cb7803d7b97672e91f3edc2d23e5c2,
tree992732170f08ddb9fc26748e27979160486c7e3d,
manifestSHA0a96b1b77fce63b9ad414c7100e39f457622982b34f78ff5ce4cddadb2324eb9
holds full original source/patch/commit metadata/FIRST/RED/raw and the original
P1528 evidence. Its original failed GCC candidate and final GCC NOT_RUN are
not relabelled; C1230 is a separate verification on exact final source bytes.

New custody is exactly archive/p1535-c1230-gcc-closeout-20261119, one ordinary
Git push. Verify all actual paths/sizes/SHA/modes/Git blob bytes from a fresh
empty HTTPS clone using tools/verify_members.py and the externally published
manifest SHA. This verifies bytes, not a compiler/native rerun. Only new
redundant standalone stage/restore clones may be deleted after receipt POST/GET;
active source, new build/raw, pinned SDK and all prior originals remain.

VALUE-ALIGNMENT-RISK: a GCC build-family limitation is closed. Obtaining and
discarding the optional same-D root reference does not demonstrate useful
callee payload/API or reduced author-plus-ordinary-safe-caller UB audit and
re-audit dependency closure. Comparison remains UNMEASURED; ProductGO624 PAUSED/
H1 HOLD. Existing four-step continuation and fair sound Rust alternatives remain.
''')
members=[dict(path=p.relative_to(S).as_posix(),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644') for p in sorted(S.rglob('*')) if p.is_file()]
(S/'manifest.json').write_text(json.dumps(dict(owner='sole Track P',cohort='P1535 C1230 GCC closure',head=summary['head'],tree=summary['tree'],members=members),indent=2)+'\n')
receipt=dict(ref='archive/p1535-c1230-gcc-closeout-20261119',files=len(members)+1,bytes=sum(p['bytes'] for p in members)+(S/'manifest.json').stat().st_size,largest_bytes=max(p['bytes'] for p in members),manifest_sha256=hashlib.sha256((S/'manifest.json').read_bytes()).hexdigest())
assert receipt['files']<=128 and receipt['bytes']<=8*1024*1024
(E/'archive-preflight.json').write_text(json.dumps(receipt,indent=2)+'\n')
subprocess.run(['git','init','-b',receipt['ref'],S],check=True,stdout=subprocess.DEVNULL)
for k,fmt in [('user.name','%an'),('user.email','%ae')]:subprocess.run(['git','config',k,g('log','-1','--format='+fmt).decode().strip()],cwd=S,check=True)
subprocess.run(['git','add','-f','--','.'],cwd=S,check=True)
subprocess.run(['git','commit','-m','Preserve C1230 exact formatted GCC closure without source changes'],cwd=S,check=True,stdout=subprocess.DEVNULL)
sys.path.insert(0,'/workspace/p1520-custody');from verify_members import verify
verified=verify(S,receipt['manifest_sha256']);receipt.update(commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=S).decode().strip(),tree=subprocess.check_output(['git','rev-parse','HEAD^{tree}'],cwd=S).decode().strip(),local_verify=verified)
(E/'archive-local.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))
