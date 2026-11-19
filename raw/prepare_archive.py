"""One C1209 raw-only Git cohort; execute once after final CI collection."""
from pathlib import Path
import hashlib,json,subprocess
E=Path('/workspace/p1531-evidence');R=Path('/workspace/NewLang_P1531');S=Path('/workspace/p1531-custody-stage')
assert not S.exists();assert not (E/'archive-preflight.json').exists()
ci=json.loads((E/'CI-final-summary.json').read_text())
assert ci['head']=='b1a6f1725abe25981ad29088175de581f956f919'
assert ci['all8_success'] and ci['job_count']==16 and ci['HEADs']==2
assert not subprocess.check_output(['git','status','--porcelain=v1'],cwd=R)
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=R).decode().strip()==ci['head']
S.mkdir();provenance=[]
def copy(p,dest):
    assert p.is_file() and not p.is_symlink()
    raw=p.read_bytes();q=S/dest;q.parent.mkdir(parents=True,exist_ok=True);q.write_bytes(raw)
    q.chmod(0o755 if p.stat().st_mode&0o111 else 0o644)
    assert not raw.startswith((b'\x7fELF',b'!<arch>')),p
    provenance.append(dict(original=str(p),archive=dest,bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest()))
for p in sorted(E.iterdir()):
    if p.is_file() and p.suffix in {'.txt','.json','.jsonl','.py','.c','.stdout','.stderr'}:
        copy(p,'raw/'+p.name)
for p in sorted((E/'logs').iterdir()):
    assert p.suffix in {'.stdout','.stderr'};copy(p,'raw/logs/'+p.name)
for p in sorted((E/'ci').iterdir()):
    assert p.suffix in {'.log','.json'};copy(p,'ci/'+p.name)
for p in sorted((E/'amendment').rglob('*')):
    if p.is_file() and p.suffix in {'.txt','.json','.jsonl','.py','.c','.stdout','.stderr'}:
        copy(p,'amendment/'+str(p.relative_to(E/'amendment')))
copy(Path('/workspace/p1520-custody/verify_members.py'),'tools/verify_members.py')
(S/'source').mkdir()
(S/'source/integration.commit').write_bytes(subprocess.check_output(['git','cat-file','commit',ci['head']],cwd=R))
(S/'source/FIRST-integration.commit').write_bytes(subprocess.check_output(['git','cat-file','commit','c683ca533caaca05e1b546dd45f2a051295da81f'],cwd=R))
(S/'custody').mkdir();(S/'custody/original-path-provenance.json').write_text(json.dumps(provenance,indent=2)+'\n')
(S/'README.md').write_text('''# P1531 C1209 integration validation raw

One raw-only archive for Compiler Issue1531 / DRAFT HOLD PR1532. Exact public
final headb1a6f1725abe25981ad29088175de581f956f919, tree1fb87662e11c8e1ccd4d54a45be0e3d38a8e67b9,
baseb2f22d39b61c0cf3ea18b7a1529fa8f0bf801be1. Source already public on this
P branch and both preserved original parent histories; source/integration.commit
retains raw original metadata for both FIRST and final child. FIRST's raw tree
audit records independent exact all7435 path/mode/blob equality to original738
with three adopted T substitutions; amendment/second-head-audit.json records
the precise7-path C1213 guard/regression delta. No source law, toolchain, API,
issuer or workflow modification; Production amendment only existing direct guard.

New full staged inventory and decoded original CI logs exceed normal Issue
comment limits; the exact production tree is preserved. C1209 permits this
one dedicated non-LFS Evidence ref and one normal push. No earlier archive
is rewritten. All prior FIRST/RED/P1525/P1528/P1529 STOP/results stay retained.
No SDK, executable/object, build tree, credentials, temporary signed log URL,
or independent F/R original is included. ci/ logs are exact UTF-8 re-encoding
of the connector's decoded original job text (BOM/newlines preserved), not
re-execution or a downloaded ZIP. All API/job/CI/source identities indexed.

raw/ contains complete new FIRST/runner and stdout/stderr, ledger/expected
negative exits, six generated sources with same historical bytes, SDK reuse
and integration provenance, actual inventory, local and natural CI summaries.
No new local RED; expected source/host refusals retain original bytes.
FIRST local89/96,guest18/18,host4sites12cases,build2/2,SDK0 preserved; C1213
adds38/40,guest6/6,build1/1,newhost0/SDK0. Total127/129,24guests/24,3builds/3.
Natural twoHEADs/16jobs,manual retry0. FIRST all8 green remains history; C1213
scope-acceptance baseline and final held-source refusal retained separately.
Technical finite capability is not independent safety adoption
or comparative UB-audit locality proof; ProductGO PAUSED/H1 HOLD.

From an independent empty HTTPS clone at the exact archive commit, verify
the manifest SHA recorded in Issue1531, then:
  python tools/verify_members.py . MANIFEST_SHA
The verifier checks all actual paths, sizes, SHA256, filesystem/Git modes and
Git blob bytes. Only redundant owner-created temporary clones can be removed
after full restore and POST/GET receipt. Active original P worktrees, raw,
commits and pinned SDK remain retained. No compiler/native/CI custody rerun.
''')
rows=[]
for p in sorted(S.rglob('*')):
    if p.is_file():
        b=p.read_bytes();rows.append(dict(path=str(p.relative_to(S)),bytes=len(b),sha256=hashlib.sha256(b).hexdigest(),mode='100755' if p.stat().st_mode&0o111 else '100644'))
(S/'manifest.json').write_text(json.dumps(dict(schema='p1531-c1209-raw-v1',members=rows),indent=2)+'\n')
total=sum(x['bytes'] for x in rows)+(S/'manifest.json').stat().st_size
assert len(rows)+1<=1024 and total<=16*1024*1024
preflight=dict(files=len(rows)+1,bytes=total,manifest_sha256=hashlib.sha256((S/'manifest.json').read_bytes()).hexdigest(),max_member=max(x['bytes'] for x in rows))
(E/'archive-preflight.json').write_text(json.dumps(preflight,indent=2)+'\n')
print(json.dumps(preflight,indent=2))
