from pathlib import Path
import hashlib,json,subprocess,shutil,re,stat
R=Path('/workspace/p1528-gate0');A=Path('/workspace/p1528-evidence-stage')
assert not A.exists();A.mkdir()
ref='archive/c1198-terminal-read-gate0-20261118';url='https://github.com/wakairo/NewLang_Evidence.git'
assert not subprocess.check_output(['git','ls-remote','--heads',url,'refs/heads/'+ref]),'Unexpected Evidence writer STOP'
def git(*args):return subprocess.check_output(['git',*args],cwd=A).decode().strip()
git('init','--initial-branch='+ref)
for k,v in [('user.name','Codex Track P'),('user.email','codex-p@users.noreply.github.com'),('core.hooksPath','/dev/null'),('core.autocrlf','false'),('commit.gpgsign','false')]:git('config','--local',k,v)
(A/'.gitattributes').write_text('* -filter -text\n')
def copy(p,rel):
 assert p.is_file() and not p.is_symlink();q=A/rel;q.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,q)
for p in sorted(R.iterdir()):
 if p.is_file() and p.suffix in {'.json','.txt','.py','.c'} and p.name not in {'ledger.json','archive-local.json'}:copy(p,'packet/'+p.name)
for directory in ['source','logs']:
 for p in sorted((R/directory).iterdir()):
  if p.is_file():copy(p,'packet/'+directory+'/'+p.name)
rows=json.loads((R/'ledger.json').read_text());completed=[x for x in rows if x['status']=='FINISHED']
(A/'packet/ledger-through-measurement.json').write_text(json.dumps(completed,indent=2)+'\n')
copy(Path('/workspace/p1520-custody/verify_members.py'),'verify_members.py')
(A/'README.md').write_text('''# P1528 C1198 unchanged-compiler LOCAL GATE0

Fixed mainc97/candidate7de, Draft17.38. P1525 remains COMPLETE/STOP.
packet/ contains complete own FIRST, source/oracle/public-only probe, raw
CHECK/owned/C17 refusals/three source negatives, provenance and scoped reuse
analysis. Exact complete packet FIRST was POST/GET before source execution.
Both positives CHECK0/MACHINE1/5-step same-original-D read scope closed before
EndRoot/public Copy proofs; C17 CLI4 unsupported; native NOT_RUN. Three
negative CHECK semantic refusals. One public-probe build; no frontend build,
SDK/host-fault/full CTest/Production edit/Compiler remote or CI. No independent
F/R original input. Existing original snapshots/raw/SDK remain untouched.

The callee only obtains root read access and discards it in scope; caller
payload read is unchanged. This is not a practical consumer completion or
measured UB audit-locality improvement. Existing shared5-step machinery is a
reuse candidate, not proof that a guard-only patch suffices. No implementation
is authorized. Product GO624 PAUSED/H1 HOLD, benefit UNMEASURED.

Ledger snapshot covers completed measurement/administrative invocations;
later Git-only archive/restore costs are reported in the Issue FINAL. Raw
first refusals are retained. One read-only nonexistent source lookup path was
corrected; no source/probe/oracle correction. ELF/object/SDK/env/auth data
excluded per mission; source plus build argv and artifact hashes retained.
verify_members.py checks every actual path/size/SHA/Git mode/blob from a fresh
HTTPS clone using the external manifest SHA. No runtime rerun for custody.
''')
members=[];patterns=[rb'gh[pousr]_[A-Za-z0-9_]{30,}',rb'github_pat_[A-Za-z0-9_]{30,}',rb'-----BEGIN [A-Z ]*PRIVATE KEY-----',rb'X-Amz-Signature=[0-9a-fA-F]{32,}']
for p in sorted(A.rglob('*')):
 rel=p.relative_to(A)
 if rel.parts[0]=='.git' or p.is_dir():continue
 assert not p.is_symlink() and stat.S_ISREG(p.lstat().st_mode)
 b=p.read_bytes()
 for pat in patterns:assert not re.search(pat,b),f'Concrete secret pattern STOP: {rel}'
 members.append(dict(path=str(rel),bytes=len(b),sha256=hashlib.sha256(b).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644'))
manifest=dict(issue=1528,subject='7deabd1b1f44bc40862b6a28c89fde502832d8cb',members=members)
(A/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
total=sum(x['bytes'] for x in members)+(A/'manifest.json').stat().st_size
assert len(members)+1<=256 and total<=8388608
git('add','.');git('commit','-m','Preserve C1198 unchanged-compiler optional-read Gate0 FIRST and refusals')
receipt=dict(ref=ref,commit=git('rev-parse','HEAD'),tree=git('rev-parse','HEAD^{tree}'),files=len(members)+1,bytes=total,manifest_sha256=hashlib.sha256((A/'manifest.json').read_bytes()).hexdigest(),secret_patterns='no matches',ELF_objects_SDK_independent_inputs='excluded',pushes=0)
(R/'archive-local.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))
