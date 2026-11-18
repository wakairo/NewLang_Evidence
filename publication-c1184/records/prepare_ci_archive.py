"""Append this P-owned publication/CI packet; never alter old raw evidence."""
from pathlib import Path
import hashlib
import json
import re
import shutil
import stat
import subprocess

E=Path('/workspace/p1525-evidence')
P=Path('/workspace/NewLang_P1525_publication')
D=E/'publication-c1184'
A=Path('/workspace/p1525-ci-archive-stage')
OLD='0db02f5088c494d5811e18edb1f15c1537a5cfef'
BASE='c97ce81c48a0c003b072c77c655bdeb10860ebf1'
FIRST='dca50af1d7d59fc4c609810aa6c2968e9ec1e6eb'
FINAL='7deabd1b1f44bc40862b6a28c89fde502832d8cb'
PREFIX='publication-c1184/'

def git(root,*args):
    return subprocess.check_output(['git',*args],cwd=root)
def put(rel,data):
    p=A/PREFIX/rel;p.parent.mkdir(parents=True,exist_ok=True)
    p.write_bytes(data if isinstance(data,bytes) else data.encode())
def copy(src,rel):
    assert src.is_file() and not src.is_symlink(),src
    p=A/PREFIX/rel;p.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,p)

assert git(A,'rev-parse','HEAD').decode().strip()==OLD
assert not git(A,'status','--porcelain')
assert git(P,'rev-parse','HEAD').decode().strip()==FINAL
assert not git(P,'status','--porcelain')
summary=json.loads((D/'CI-final-summary.json').read_text())
assert summary['final_head']==FINAL and summary['required6']=='success'
assert summary['early2']=='success' and summary['head_count']==2 and summary['job_count']==16
assert summary['local']==276 and summary['host_cases']==48 and summary['host_reinjection']==0
old_manifest=(A/'manifest.json').read_bytes()
assert hashlib.sha256(old_manifest).hexdigest()=='04d9742ec74f452e581cf82fb9f37419d32e89f36f9a2313a0d5c2fadf707207'
put('previous-manifest.json',old_manifest)
for p in sorted(D.iterdir()):
    if p.is_file() and p.suffix in {'.json','.txt','.md','.diff','.log','.c','.py'}:
        copy(p,'records/'+p.name)
for name in ['ledger.jsonl','results.jsonl','meterlib.py','run.py','cc.py','sitecustomize.py']:
    copy(E/name,'local/'+name)
for p in sorted((E/'logs').iterdir()):
    if p.is_file() and p.name.split('.')[0].isdigit() and int(p.name.split('.')[0])>313:
        copy(p,'local/logs/'+p.name)
copy(D/'build-release/Testing/Temporary/LastTest.log','local/Release-nonfault-CTest.log')
copy(D/'build-release/compile_commands.json','local/Release-compile-commands.json')

metadata=dict(base=BASE,base_tree=git(P,'rev-parse',BASE+'^{tree}').decode().strip(),commits=[])
for i,c in enumerate([FIRST,FINAL]):
    patch=PREFIX+f'candidate/patches/{i+1:04d}-{c}.patch';raw=PREFIX+f'candidate/commits/{c}.commit'
    put(patch.removeprefix(PREFIX),git(P,'format-patch','-1','--stdout','--binary','--full-index','--no-stat','--no-signature',c))
    put(raw.removeprefix(PREFIX),git(P,'cat-file','commit',c))
    metadata['commits'].append(dict(sha=c,tree=git(P,'rev-parse',c+'^{tree}').decode().strip(),parent=git(P,'rev-parse',c+'^').decode().strip(),patch=patch,raw_commit=raw))
put('candidate/metadata.json',json.dumps(metadata,indent=2)+'\n')
subprocess.run(['git','bundle','create',str(A/PREFIX/'candidate/p1525-publication.bundle'),'refs/heads/p1525-terminal-receiver-c1184','^'+BASE],cwd=P,check=True)
files=[]
for name in git(P,'diff','--name-only',BASE,FINAL).decode().splitlines():
    data=(P/name).read_bytes();copy(P/name,'candidate/source/'+name)
    files.append(dict(path=name,bytes=len(data),sha256=hashlib.sha256(data).hexdigest()))
assert len(files)==25
put('candidate/files.json',json.dumps(files,indent=2)+'\n')

replay=Path('/workspace/p1520-custody/replay.py').read_text()
for old,new in [('7591848bd7f4bf8967dffd4be8d360e1901a3f06',BASE),('24206697820ff5521aba0239487c5b9b0f168445',FIRST),('c57fed0bad9b0e6c0dea7b1f02f1b5ff3c0cfd5c',FINAL),('candidate/metadata.json',PREFIX+'candidate/metadata.json'),('candidate/p1517-local.bundle',PREFIX+'candidate/p1525-publication.bundle'),('p1517-terminal-receiver-local','p1525-terminal-receiver-c1184'),('p1517-original','p1525-publication-original')]:
    replay=replay.replace(old,new)
replay=replay.replace('    bundle = archive /', '''    for row in json.loads((archive / "publication-c1184/candidate/files.json").read_text()):
        actual = (target / row["path"]).read_bytes()
        assert len(actual) == row["bytes"]
        assert hashlib.sha256(actual).hexdigest() == row["sha256"]
        assert actual == (archive / "publication-c1184/candidate/source" / row["path"]).read_bytes()
    bundle = archive /''')
put('tools/replay-publication.py',replay)
copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
put('README.md', '''# C1184 publication and original CI

Append-only successor to Evidence0db02f5. All old payloads remain byte-identical.
Root manifest indexes both snapshots; previous-manifest.json preserves the old
external SHA04d9742e… The original old FIRST/RED/NOT_RUN/ENV-PARTIAL remain.

candidate/ recovers exact actual-c97 -> first dca50af -> final7deabd1 using
two format-patches/raw commits/small bundle and all25 final changed files.
records/ contains publication notices, run/job metadata, decoded original
GitHub job logs, first GCC Release RED and exact source/SHA fixture repair.
local/ preserves cumulative276/320 ledger and new selected raw, including the
fortified warning reproduction and non-fault Release10 CTests. Native57/64,
host48/48; local host reinjection0. No SDK/ELF/objects/home/env/auth config or
independent F/R originals copied; active originals and SDK remain locally held.

Use tools/replay-publication.py with the archive root/new empty target/receipt
path and externally recorded new manifest SHA. It verifies all actual archive
members/modes/blobs, fetches actual c97 over HTTPS, applies both patches,
compares exact trees and25 file bytes, then restores original commit IDs via
the bundle. No compiler/native/CTest/CI execution occurs in this restoration.

Required6 and separate EARLY2 are final-head evidence; initial Release RED is
not rewritten by successor success. DRAFT/HOLD, independent F/R review and C
substantive adoption remain distinct. Audit-locality benefit is UNMEASURED.
''')
patterns=[rb'gh[pousr]_[A-Za-z0-9_]{30,}',rb'github_pat_[A-Za-z0-9_]{30,}',rb'-----BEGIN [A-Z ]*PRIVATE KEY-----',rb'X-Amz-Signature=[0-9a-fA-F]{32,}',rb'(?i)Authorization: (Bearer|Basic) [A-Za-z0-9+/=]{12,}']
members=[]
for p in sorted(A.rglob('*')):
    rel=p.relative_to(A)
    if rel.parts[0]=='.git' or p.is_dir() or str(rel)=='manifest.json':continue
    assert not p.is_symlink() and stat.S_ISREG(p.lstat().st_mode)
    data=p.read_bytes();assert len(data)<5*1024*1024,(rel,len(data))
    for pattern in patterns:assert not re.search(pattern,data),f'Concrete secret pattern STOP in {rel}'
    members.append(dict(path=str(rel),bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644'))
assert sum(x['bytes'] for x in members)<32*1024*1024
(A/'manifest.json').write_text(json.dumps(dict(issue=1525,parent_archive=OLD,scope='C1177 original plus C1184 publication/first RED/final CI',members=members),indent=2)+'\n')
for k,v in [('user.name','Codex Track P'),('user.email','codex-p@users.noreply.github.com'),('core.hooksPath','/dev/null'),('commit.gpgsign','false')]:git(A,'config','--local',k,v)
git(A,'add','.')
changed=git(A,'diff','--cached','--name-only').decode().splitlines()
assert all(x=='manifest.json' or x.startswith(PREFIX) for x in changed)
git(A,'commit','-m','Preserve C1184 publication, initial Release RED and fixed-head CI')
receipt=dict(branch='archive/p1525-c1177-revalidation-20261118',parent=OLD,commit=git(A,'rev-parse','HEAD').decode().strip(),tree=git(A,'rev-parse','HEAD^{tree}').decode().strip(),manifest_sha256=hashlib.sha256((A/'manifest.json').read_bytes()).hexdigest(),files=len(members)+1,bytes=sum(x['bytes'] for x in members)+(A/'manifest.json').stat().st_size,max_file=max(x['bytes'] for x in members),original_payloads='unchanged',concrete_secret_patterns='no matches',push_number=2)
(D/'archive-final-prepush.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))
