from pathlib import Path
import hashlib,json,os,shutil,subprocess
E=Path('/workspace/p1539-c1240-local');W=Path('/workspace/NewLang_P1539');S=Path('/workspace/p1539-c1240-custody-stage')
assert not S.exists();S.mkdir();provenance=[]
def cp(p,name):
 assert p.is_file() and not p.is_symlink(),p
 b=p.read_bytes();assert not b.startswith((b'\x7fELF',b'!<arch>')),p
 q=S/name;q.parent.mkdir(parents=True,exist_ok=True);q.write_bytes(b);q.chmod(0o755 if p.stat().st_mode&0o111 else 0o644)
 provenance.append(dict(original=str(p),archive=name,bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
for p in sorted(E.iterdir()):
 if p.is_file() and p.suffix in {'.json','.jsonl','.py','.txt','.patch','.commit','.c'}:cp(p,'local/'+p.name)
for name in ['source','FIRST-source','FIRST-probe','probe','logs','controls']:
 for p in sorted((E/name).rglob('*')):
  if p.is_file():cp(p,'local/'+str(p.relative_to(E)))
for name in ['tests/p1535/passive.h','tests/p1535/native.py','tests/p1517/guest_wrap.c','tests/p1517/safety.c','tests/p1529/consumer.c','tests/p1463/probe.c']:
 cp(W/name,'apparatus/'+name)
for name in ['src/checked_c_node.c','src/checked_c_scalar_control_internal.h']:cp(W/name,'candidate/'+name)
cp(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
cp(Path('/workspace/p1535-evidence/SDK-reuse-provenance.json'),'provenance/prior-SDK-reuse.json')
(S/'provenance/copies.json').write_text(json.dumps(provenance,indent=2)+'\n')
(S/'README.md').write_text('''P1539/C1240-C1241 sole P finite local custody; no Compiler publication.

Fixed public parent7b0b8e0a5348220061abe86921e9d006be5e398a/treea7e0561c7b57e03330b1d1d91c90300dd093f938.
Local implementation a026544d52ce631e339dbd5ec40c6fc3ebcca734/tree75697e0bdaec271954d25b4ffa3c2ab3c7390533, two private files+22/-4.
Main9c9b17f7f0584c88a92ab284f57e4a93b8ab350b was recorded separately, not substituted.

local/source/ and oracle-FIRST are own frozen 2 positives/4 purposeful negatives;
FIRST-source and FIRST-probe keep raw pre-execution bytes; logs3/5 are apparatus
RED, logs9/13 original CLI C17 exit4, logs10/14 genuine API refusal/no-clobber.
Diagnostic probe source is separately retained. Its correction uses public Copy
parameter/event contracts; field.new_value on a loan observation is zero, not
Change incoming. No old failure is rewritten or claimed to be the final result.

One existing readonly-u8 consumer is narrowly connected to the planned directH2
source-owner lane before unit receiver, after one caller payload read and closed
loan. Actual scalar return binding feeds namedCopy of SAME original T. No source
law/issuer/public API/ABI/owner/new shadow state mechanism is added. Current
source proof uses genuine owned body after defining AST destruction, not seed.

summary/ledger/results/logs give all new costs and reached layers. 100 selected,
2 incremental frontends, 3 public-probe builds, 18 strictC17 O2 guests, 2 hostsites
8 cases. Original FIRST/RED and prior P1535 history remain preserved. Selected
frontends recompile only changed TU; unchanged cached object/library hashes and
exact build flags are explicit. SDK reused under prior verified pin/guards,
actual compiler SHA/version; SDK acquisition0. O0, full clean all-TU build,
fullCTest/LLVM and Compiler remote/PR/CI/READY/merge NOT_RUN/0. No R/F originals.

No ELF/objects/SDK/credentials/Git authentication settings are included. They are
reproducible current build products retained at original P paths, not claimed to
be restored by this archive. Actual raw C17, sources, public probe, existing
apparatus, recipes, immutable logs and complete patch/raw commit/tree are here.
Run tools/verify_members.py on a fresh empty HTTPS clone with externally recorded
manifest SHA; verify all actual paths/count/bytes/SHA/modes and Git blob bytes.

For implementation restoration, separately fetch fixed public Compiler7b0 by
HTTPS into a new empty repo. git am local/implementation.patch must produce tree
75697e0bdaec271954d25b4ffa3c2ab3c7390533, with the complete tree compared to
local/final-tree.txt. local/implementation.commit raw Git commit bytes must
hash as a026544d52ce631e339dbd5ec40c6fc3ebcca734; it references the same tree and
public7b0 parent. This is Git byte restoration, not rerunning tests or a semantic
safety proof. No original P worktree/commit/build/raw/SDK may be removed.

VALUE-ALIGNMENT-RISK: identity helper shows finite ordinary value-flow support;
comparative author-plus-ordinary-safe-caller UB audit/re-audit locality remains
UNMEASURED. No useful facade or all-safe-reachable-state result follows. Original
issuer/R/A/D/current/legal writers/teardown and failure/reentrancy/FFI obligations
remain in closure. ProductGO624 PAUSED/H1 HOLD; direct snapshot->unitclose->T,
no change, factoredC and soundRust remain alternatives. C owns later release.
''')
members=[dict(path=p.relative_to(S).as_posix(),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644') for p in sorted(S.rglob('*')) if p.is_file()]
(S/'manifest.json').write_text(json.dumps(dict(owner='sole Track P',cohort='P1539 C1240-C1241 local',local_HEAD='a026544d52ce631e339dbd5ec40c6fc3ebcca734',local_tree='75697e0bdaec271954d25b4ffa3c2ab3c7390533',members=members),indent=2)+'\n')
r=dict(ref='archive/p1539-c1240-local-20261119',files=len(members)+1,bytes=sum(x['bytes'] for x in members)+(S/'manifest.json').stat().st_size,largest_bytes=max(x['bytes'] for x in members),manifest_sha256=hashlib.sha256((S/'manifest.json').read_bytes()).hexdigest())
assert r['files']<=768 and r['bytes']<=16*1024*1024
st=os.statvfs('/workspace');r['disk_before']=dict(available_bytes=st.f_bavail*st.f_frsize,free_inodes=st.f_favail)
(E/'archive-preflight.json').write_text(json.dumps(r,indent=2)+'\n')
subprocess.run(['git','init','-b',r['ref'],str(S)],check=True,capture_output=True)
for key,fmt in [('user.name','%an'),('user.email','%ae')]:
 v=subprocess.check_output(['git','-C',str(W),'log','-1','--format='+fmt],text=True).strip();subprocess.run(['git','-C',str(S),'config',key,v],check=True)
subprocess.run(['git','-C',str(S),'add','-f','--','.'],check=True)
subprocess.run(['git','-C',str(S),'commit','-m','Preserve P1539 own FIRST, private consumer closure and original RED/raw'],check=True,capture_output=True)
r.update(commit=subprocess.check_output(['git','-C',str(S),'rev-parse','HEAD'],text=True).strip(),tree=subprocess.check_output(['git','-C',str(S),'rev-parse','HEAD^{tree}'],text=True).strip())
(E/'archive-local.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
