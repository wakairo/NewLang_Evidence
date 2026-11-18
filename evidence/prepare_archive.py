"""Prepare one eligible P-only normal-Git cohort; keep every original."""
from pathlib import Path
import hashlib
import json
import os
import re
import shutil
import stat
import subprocess

E=Path('/workspace/p1525-evidence')
P=Path('/workspace/NewLang_P1525')
A=Path('/workspace/p1525-archive-staging')
assert not A.exists()
A.mkdir()

def git(*args):
    return subprocess.check_output(['git',*args],cwd=A).decode().strip()
def pgit(*args):
    return subprocess.check_output(['git',*args],cwd=P)
def write(relative,data):
    p=A/relative;p.parent.mkdir(parents=True,exist_ok=True)
    p.write_bytes(data if isinstance(data,bytes) else data.encode())
def copy(src,relative):
    assert src.is_file() and not src.is_symlink(),src
    p=A/relative;p.parent.mkdir(parents=True,exist_ok=True)
    shutil.copy2(src,p)

git('init','--initial-branch=archive/p1525-c1177-revalidation-20261118')
for k,v in [('user.name','Codex Track P'),('user.email','codex-p@users.noreply.github.com'),('core.autocrlf','false'),('core.hooksPath','/dev/null'),('commit.gpgsign','false')]:
    git('config','--local',k,v)
write('.gitattributes','* -filter -text\n')
base='ac6be8e3473f08c44fe8e9407dc33c0fb53086d6'
commits=['7063ca3a770f3cea1b142f59774d63a263cc5184','394d35d4175716a4fc2947e3d5fbdbc89c167237']
metadata=dict(base=base,base_tree=pgit('rev-parse',base+'^{tree}').decode().strip(),commits=[],original_P1517='unchanged; see e46bda3c634dc55d19f5561fb431f56720c87495 archive',status='LOCAL READY / WAIT PUBLICATION')
for i,c in enumerate(commits):
    patch=f'candidate/patches/{i+1:04d}-{c}.patch';raw=f'candidate/commits/{c}.commit'
    write(patch,pgit('format-patch','-1','--stdout','--binary','--full-index','--no-stat','--no-signature',c))
    write(raw,pgit('cat-file','commit',c))
    metadata['commits'].append(dict(sha=c,tree=pgit('rev-parse',c+'^{tree}').decode().strip(),parent=pgit('rev-parse',c+'^').decode().strip(),patch=patch,raw_commit=raw))
write('candidate/metadata.json',json.dumps(metadata,indent=2)+'\n')
subprocess.run(['git','bundle','create',str(A/'candidate/p1525-local.bundle'),'refs/heads/p1525-terminal-revalidation-local','^'+base],cwd=P,check=True)
for row in json.loads((E/'candidate-files.json').read_text()):
    copy(P/row['path'],'candidate/source/'+row['path'])

for name in ['meterlib.py','run.py','cc.py','sitecustomize.py','cc-gcc','cc-clang','regress.py','prepare_archive.py','ledger.jsonl','results.jsonl','integration-inputs.json','candidate-files.json','sdk-receipt.json','summary.json','issue-receipts.json','original-candidate.diff']:
    copy(E/name,'evidence/'+name)
for directory in ['logs','ctest']:
    for src in sorted((E/directory).rglob('*')):
        if src.is_file():copy(src,'evidence/'+str(src.relative_to(E)))
for build in ['build-gcc','build-clang','build-asan','build-ubsan']:
    copy(E/build/'compile_commands.json','evidence/'+build+'/compile_commands.json')
    for cohort in ['p1517-native','p1517-named']:
        d=E/build/cohort
        if d.exists():
            for src in sorted(d.rglob('*')):
                if src.is_file() and src.suffix in ['.c','.json','.stdout','.stderr']:
                    copy(src,'evidence/'+str(src.relative_to(E)))
for src in sorted((E/'regress').iterdir()):
    if src.is_file() and src.suffix in ['.c','.json','.stdout','.stderr']:
        copy(src,'evidence/'+str(src.relative_to(E)))

copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
replay=Path('/workspace/p1520-custody/replay.py').read_text()
for old,new in [('7591848bd7f4bf8967dffd4be8d360e1901a3f06',base),('24206697820ff5521aba0239487c5b9b0f168445',commits[0]),('c57fed0bad9b0e6c0dea7b1f02f1b5ff3c0cfd5c',commits[1]),('p1517-local.bundle','p1525-local.bundle'),('p1517-terminal-receiver-local','p1525-terminal-revalidation-local'),('p1517-original','p1525-original')]:
    replay=replay.replace(old,new)
replay=replay.replace('    bundle = archive /', '''    for row in json.loads((archive / "evidence/candidate-files.json").read_text()):
        actual = (target / row["path"]).read_bytes()
        assert len(actual) == row["bytes"]
        assert hashlib.sha256(actual).hexdigest() == row["sha256"]
        assert actual == (archive / "candidate/source" / row["path"]).read_bytes()
    bundle = archive /''')
write('tools/replay.py',replay)
write('README.md', '''# P1525 C1177 local revalidation evidence

Sole Track P; Issue1525. LOCAL READY / WAIT PUBLICATION, no Compiler push/PR/CI.
Candidate metadata and two original local commits/format-patches/small bundle
recover exact ac6 parent -> integration -> final formatted/documented candidate.
Original P1517 FIRST/RED/80/80/ENV-PARTIAL are unchanged in archive
archive/p1517-c1157-local-20261118 at e46bda3c634dc55d19f5561fb431f56720c87495.

evidence/summary.json records255/320 local,57/64 native,6 logical host sites,
48/48 host fault/retry cases,SDK1/2. All313 metered command records have a
result and raw stdout/stderr; standard compiler-build driver commands are
recorded but the whole build is the charged experimental unit. Separate
CTest/native/named/regression logs and actual emitted C are retained too.
GCC18/18,Clang18/18,ASan18/18,UBSan selected11/11; old selectedCTest3/3.
UBSan host fault tests were not repeated beyond the host-case budget.

This cohort omits reproducible build objects/ELFs and the126MB SDK; those
remain locally retained. SDK trust identity/guard receipt and fixed tooling
commit are recorded. No secrets, credentials, home/env/auth config, or
independent F/R original inputs are included. Eligible P evidence only.

Verify all actual files/modes/blobs using tools/verify_members.py and the
external manifest SHA from Issue1525. tools/replay.py fetches the fixed parent
over HTTPS into a newly created target, applies both patches and compares
trees/files, then verifies exact original raw commit identities via the bundle.
It never runs the compiler/native/CTest/CI. Fresh restore and receipt, not a
successful push alone, establish custody. Keep original P worktrees/evidence.

Technical PASS is finite; no independent review, full LLVM/ordinary CI, adopted
main, Product GO or measured UB-prevention audit-locality benefit is claimed.
''')

patterns=[rb'gh[pousr]_[A-Za-z0-9_]{30,}',rb'github_pat_[A-Za-z0-9_]{30,}',rb'-----BEGIN [A-Z ]*PRIVATE KEY-----',rb'X-Amz-Signature=[0-9a-fA-F]{32,}',rb'(?i)Authorization: (Bearer|Basic) [A-Za-z0-9+/=]{12,}']
members=[]
for p in sorted(A.rglob('*')):
    rel=p.relative_to(A)
    if rel.parts[0]=='.git' or p.is_dir():continue
    assert not p.is_symlink() and stat.S_ISREG(p.lstat().st_mode)
    data=p.read_bytes()
    assert len(data)<1000000,(rel,len(data))
    for pattern in patterns:
        assert not re.search(pattern,data),f'Concrete secret pattern STOP in {rel}'
    members.append(dict(path=str(rel),bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644'))
manifest=dict(issue=1525,scope='P1525 candidate and successor evidence; no original deletion',members=members)
write('manifest.json',json.dumps(manifest,indent=2)+'\n')
sha=hashlib.sha256((A/'manifest.json').read_bytes()).hexdigest()
git('add','.')
git('commit','-m','Preserve P1525 C1177 local terminal receiver verification')
receipt=dict(branch='archive/p1525-c1177-revalidation-20261118',commit=git('rev-parse','HEAD'),tree=git('rev-parse','HEAD^{tree}'),manifest_sha256=sha,files=len(members)+1,bytes=sum(x['bytes'] for x in members)+(A/'manifest.json').stat().st_size,max_file=max(x['bytes'] for x in members),concrete_secret_scan='no matched token/key/signed-session patterns; no env/home/auth files included',originals='retained',SDK='not copied; retained',pushes=0)
(E/'archive-local.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps(receipt,indent=2))
