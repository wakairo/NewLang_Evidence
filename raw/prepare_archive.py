"""P1535 one ordinary Git custody cohort, no compiler/native execution."""
from pathlib import Path
import json,hashlib,subprocess,stat
E=Path('/workspace/p1535-evidence');W=Path('/workspace/NewLang_P1535');S=Path('/workspace/p1535-custody-stage')
assert not S.exists();S.mkdir()
summary=json.loads((E/'summary.json').read_text());assert summary['counts']['local']==117
provenance=[]
def copy(p,name):
    assert p.is_file() and not p.is_symlink()
    b=p.read_bytes();assert not b.startswith((b'\x7fELF',b'!<arch>')),str(p)
    q=S/name;q.parent.mkdir(exist_ok=True,parents=True);q.write_bytes(b);q.chmod(0o755 if p.stat().st_mode&0o111 else 0o644)
    provenance.append(dict(original=str(p),archive=name,bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
for p in sorted(E.iterdir()):
    if p.is_file() and p.suffix in {'.json','.jsonl','.txt','.py','.patch','.diff','.commit'}:copy(p,'raw/'+p.name)
for name in ['logs','first-source','apparatus-FIRST','candidate-FIRST','candidate-r2','baseline','generated','named']:
    for p in sorted((E/name).iterdir()):
        if p.is_file():copy(p,'raw/'+name+'/'+p.name)
for name in summary['changed_paths']:copy(W/name,'source/'+name)
old=Path('/workspace/p1528-gate0')
for name in ['FIRST-comment.txt','FIRST-files.json','oracle-FIRST.json','public_owned.c','ledger.json','summary.json','build-provenance.json','FINAL.txt','FINAL-POST-GET.json','archive-local.json','restore-receipt.json']:
    copy(old/name,'inherited-P1528/'+name)
for name in ['source','logs']:
    for p in sorted((old/name).iterdir()):copy(p,'inherited-P1528/'+name+'/'+p.name)
copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
(S/'custody').mkdir()
(S/'custody/original-path-provenance.json').write_text(json.dumps(provenance,indent=2)+'\n')
(S/'README.md').write_text('''# P1535 / C1223 local selected direct receiver root read

Owner: same sole Track P. Compiler Issue1535, canonical Draft17.38 §18.1a.
Fixed local parent b1a6f1725abe25981ad29088175de581f956f919,
tree1fb87662e11c8e1ccd4d54a45be0e3d38a8e67b9; unadopted PR1532 remains fixed.
Local candidate58245a24e047280304443258b2cfc8a540c9202a,
treea7e0561c7b57e03330b1d1d91c90300dd093f938. Adopted mainb2f22d39b61c0cf3ea18b7a1529fa8f0bf801be1 unchanged.

LOCAL_READY within the declared source family, no Compiler publication/CI.
One existing same-D scoped root ref binding, discarded with unit before the
existing four terminal teardown steps; no callee payload/use/u8 return,
new source law, proof issuer, API/ABI, ownership or producer relabelling.
The private consumer reuses the ordinary root-ref/world validation and scope
closure only inside the genuine authenticated direct owner call/body.

raw/ includes source/oracle FIRST, all selected stdout/stderr and ledgers,
baseline/final generated C, original candidate and apparatus/formatter REDs,
actual local commit bytes and format-patch, source manifests, tool provenance,
all Issue POST/GET material before custody and bounded result summary.
source/ gives every changed source file. inherited-P1528/ copies the original
FIRST/source/oracle/probe/C17 RED and raw at7de without rerunning or changing it;
its previous independently restored Evidence ref remains intact.
No SDK/ELF/build objects, credentials, signed URLs or independent R/F original
source/oracle/runner/report/raw is included. Active worktrees, original raw,
baseline binaries and the one pinned SDK remain in the P environment.

117/128 selected,21/24 O2 guests,2/2 frontend builds,2/2 public probe builds,
3/4 material host fault sites10/12 cases,SDK0,Compiler remote/PR/CI0.
Final repaired frontend is pinned Clang23.1.3 ASan. First GCC consumer build
remained RED, explicitly retained. GCC and pinnedClang strict generated-C
guests plus ASan/UBSan and uninstrumented syntax checks passed. O0/fullCTest/
LLVM backend/final repaired GCC frontend build/new CI are NOT_RUN. After tests,
only formatter whitespace changed; exact C token identity is recorded.

Custody restoration: fresh empty HTTPS clone of this one exact Evidence ref,
verify tools/verify_members.py with the externally recorded manifest SHA.
Also fetch the fixed public Compiler parent into another fresh empty HTTPS
repository, git apply --index raw/local-candidate.patch, and compare write-tree
to the candidate tree. Hash raw/local.commit and raw/parent.commit as Git
commit objects to check their exact original identities. No compiler/native
rerun is needed or claimed by this byte/tree restoration.

Technical coverage is separate from VALUE-ALIGNMENT-RISK: an obtained/discarded
root ref does not show useful callee payload/API/all safe-reachable states or
reduced author-plus-ordinary-safe-caller UB audit/re-audit dependency closure.
Existing four-step already handles caller payload->teardown->same T; keeping
four-step-only/postponing optional coverage and fair sound Rust facades remain
alternatives. ProductGO624 PAUSED/H1 HOLD, comparative value UNMEASURED.
''')
members=[]
for p in sorted(S.rglob('*')):
    if p.is_file():members.append(dict(path=p.relative_to(S).as_posix(),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644'))
manifest=dict(cohort='P1535 C1223 local implementation',owner='sole Track P',parent=summary['parent'],head=summary['head'],tree=summary['tree'],members=members)
(S/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
files=members+[dict(path='manifest.json',bytes=(S/'manifest.json').stat().st_size)]
assert len(files)<=512 and sum(p['bytes'] for p in files)<=16*1024*1024
receipt=dict(ref='archive/p1535-c1223-scoped-root-read-20261119',files=len(files),bytes=sum(p['bytes'] for p in files),largest_bytes=max(p['bytes'] for p in files),manifest_sha256=hashlib.sha256((S/'manifest.json').read_bytes()).hexdigest(),source_head=summary['head'],source_tree=summary['tree'],stage=str(S),pushes_allowed=1)
(E/'archive-preflight.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps(receipt,indent=2))
