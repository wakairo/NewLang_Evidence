"""One bounded new publication/CI metadata cohort; no compiler rerun."""
from pathlib import Path
import json,hashlib,subprocess,sys
E=Path('/workspace/p1535-c1236-publication');P=Path('/workspace/NewLang_P1535_publication');S=Path('/workspace/p1535-c1236-custody-stage')
summary=json.loads((E/'summary.json').read_text());assert summary['all8_success'] and summary['Required6_verified']
assert not S.exists();S.mkdir();provenance=[]
def copy(p,name):
    assert p.is_file() and not p.is_symlink()
    b=p.read_bytes();assert not b.startswith((b'\x7fELF',b'!<arch>')),str(p)
    q=S/name;q.parent.mkdir(exist_ok=True,parents=True);q.write_bytes(b);q.chmod(0o755 if p.stat().st_mode&0o111 else 0o644)
    provenance.append(dict(original=str(p),archive=name,bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
for p in sorted(E.iterdir()):
    if p.is_file() and p.suffix in {'.json','.jsonl','.txt','.py','.commit'}:copy(p,'publication/'+p.name)
for directory in ['ci','admin']:
    for p in sorted((E/directory).iterdir()):
        if p.is_file():copy(p,directory+'/'+p.name)
assert len(list((S/'ci').glob('job-*.log')))==8
copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
(S/'custody').mkdir();(S/'custody/original-path-provenance.json').write_text(json.dumps(provenance,indent=2)+'\n')
(S/'README.md').write_text('''# P1535 C1236 exact-tree publication and original natural CI

Same sole Track P. Issue1535 / C1236; DRAFT HOLD Compiler PR1538.
One public HEAD7b0b8e0a5348220061abe86921e9d006be5e398a,
sole parent adoptedmain1a32f87f1007db8e8c11dc375a6b7416a35adbc7,
treea7e0561c7b57e03330b1d1d91c90300dd093f938.
All7452 tree entries/modes/blobs and15 changed paths/actual bytes equal the
reviewed original58245a24e047280304443258b2cfc8a540c9202a. Source/test/oracle
were unchanged; only new commit provenance integrates onto adopted main.
Branchp1535-root-read-integration-c1236, one normal push, one DRAFT PR.

Natural PR CI exactly3runs/8jobs, attempt1: FULL44465857731 five lanes each
1191 actual tests; PARTIAL44465857708 1190 actual tests and real Production
CLI exit0/zero stdout/stderr; EARLY44465857668 two lanes84tests each, no new10
test execution there. Every Required6 lane executes all10 P1535 cases and
p1535_native.integration. No skipped required case/job, manual retry,
dispatch, cancellation, additional HEAD or local build/test/native/fault/SDK.
Actual checkout3e17928d2340831a65286f8aac18f5c734c38b33, ordered parents
[adoptedmain1a32f87,public7b0b8e0], exact same reviewed tree. Original complete
connector-decoded job text is re-encoded UTF8 with BOM/newlines preserved;
these are not ZIP downloads or reruns. Per-log bytes/SHA and actual execution
coverage are recorded, plus original final API/run/job/PR metadata.

publication/ holds new identity/provenance/checkpoint/API summaries and raw
commit headers only; ci/ holds all8 original final logs; admin/ keeps new Git
command outputs and metadata transport errors. No SDK/binary/build directory,
credentials/signed log URL or independent R/F original is present. There was
one failed metadata argv-size transport attempt (no process), then chunked
preservation; one optional direct job-detail GET was unsupported400, retained
without bypass. Supported run-jobs metadata and final logs provide the facts.
These administrative errors are not reclassified as compiler or CI runs.

Original source/patch/FIRST/RED/raw stay in immutable old Evidence94fb7376d4cb7803d7b97672e91f3edc2d23e5c2
(archive/p1535-c1223-scoped-root-read-20261119) and5acde0a037963b2558b25f66c24d2601001ef39d
(archive/p1535-c1230-gcc-closeout-20261119). They are not recopied or rewritten.
Prior local counters149selected/3frontend/3probe/21native/3sites10host unchanged.
Active original582/publication source, GCC/ASan builds/raw and pinned SDK remain.

One new normal Evidence ref archive/p1535-c1236-publication-20261119 only.
From a fresh empty HTTPS clone, verify exact HEAD/tree and every actual
path/size/SHA/mode/Git blob with tools/verify_members.py using the externally
published manifest SHA. Only new redundant standalone custody stage/restore
copies may be deleted after full verification and receipt POST/GET.

Scope: one-binding discarded same-D root reference -> ordinary scope closure
-> original direct unit teardown, and declared named controls. No universal
four-step-body/vacuous-scope preservation, new issuer/API/owner or callee
payload/use/u8-return claim. Technical selected coverage does not demonstrate
ordinary-safe library/all safe-reachable states or reduced author-plus-safe-
caller UB audit/re-audit dependency closure. Comparative value UNMEASURED,
ProductGO624 PAUSED/H1 HOLD. READY/merge and adoption are C decisions.
''')
members=[dict(path=p.relative_to(S).as_posix(),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644') for p in sorted(S.rglob('*')) if p.is_file()]
(S/'manifest.json').write_text(json.dumps(dict(owner='sole Track P',cohort='P1535 C1236 publication',head=summary['head'],tree=summary['tree'],pr=1538,members=members),indent=2)+'\n')
receipt=dict(ref='archive/p1535-c1236-publication-20261119',files=len(members)+1,bytes=sum(r['bytes'] for r in members)+(S/'manifest.json').stat().st_size,largest_bytes=max(r['bytes'] for r in members),manifest_sha256=hashlib.sha256((S/'manifest.json').read_bytes()).hexdigest())
assert receipt['files']<=128 and receipt['bytes']<=8*1024*1024
(E/'archive-preflight.json').write_text(json.dumps(receipt,indent=2)+'\n')
subprocess.run(['git','init','-b',receipt['ref'],S],check=True,stdout=subprocess.DEVNULL)
for k,fmt in [('user.name','%an'),('user.email','%ae')]:subprocess.run(['git','config',k,subprocess.check_output(['git','log','-1','--format='+fmt],cwd=P).decode().strip()],cwd=S,check=True)
subprocess.run(['git','add','-f','--','.'],cwd=S,check=True)
subprocess.run(['git','commit','-m','Preserve C1236 fixed publication identity and eight original natural CI logs'],cwd=S,check=True,stdout=subprocess.DEVNULL)
sys.path.insert(0,'/workspace/p1520-custody');from verify_members import verify
receipt.update(commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=S).decode().strip(),tree=subprocess.check_output(['git','rev-parse','HEAD^{tree}'],cwd=S).decode().strip(),local_verify=verify(S,receipt['manifest_sha256']))
(E/'archive-local.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))
