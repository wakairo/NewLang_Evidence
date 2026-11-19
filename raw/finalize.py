from pathlib import Path
import subprocess,json,hashlib
E=Path('/workspace/p1535-evidence');W=Path('/workspace/NewLang_P1535')
def git(*a):return subprocess.check_output(['git',*a],cwd=W)
assert git('rev-parse','HEAD').decode().strip()=='58245a24e047280304443258b2cfc8a540c9202a'
assert git('rev-parse','HEAD^').decode().strip()=='b1a6f1725abe25981ad29088175de581f956f919'
assert not git('status','--porcelain')
ledger=[json.loads(s) for s in (E/'ledger.jsonl').read_text().splitlines()]
results=[json.loads(s) for s in (E/'results.jsonl').read_text().splitlines()]
assert [r['id'] for r in ledger]==[r['id'] for r in results]==list(range(1,107))
counts={k:sum(x[k] for x in ledger) for k in ['local','native','frontend','probe','host']}
assert counts==dict(local=117,native=21,frontend=2,probe=2,host=10)
assert {s for r in ledger for s in r['sites']}=={'3','4','5'}
assert all(r['exit']==0 for r,l in zip(results,ledger) if l['native'])
nonzero=[dict(id=r['id'],label=l['label'],exit=r['exit']) for r,l in zip(results,ledger) if r['exit']]
assert {r['id'] for r in nonzero}=={4,8,12,23,50,52,54,56,58,64,69,71,101}
manifest=json.loads((E/'FIRST-manifest.json').read_text())
for m in manifest:
    p=W/m['path']
    if p.suffix=='.nl':assert len(p.read_bytes())==m['bytes'] and hashlib.sha256(p.read_bytes()).hexdigest()==m['sha256']
for v in ['zero','nonzero']:
    assert (W/f'tests/p1535/P-{v}.nl').read_bytes()==Path(f'/workspace/p1528-gate0/source/P-{v}.nl').read_bytes()
changed=git('diff','--name-only','HEAD^','HEAD').decode().splitlines()
assert len(changed)==15 and set(changed[:])=={'src/checked_c_node.c','CMakeLists.txt',*['tests/p1535/'+p.name for p in (W/'tests/p1535').iterdir() if p.is_file()]}
assert git('diff','HEAD^','HEAD','--','include','src/semantic*','src/checked.c','src/typed*','scripts','tests/integration/bootstrap_retry_test.py','.github','docs','README.md')==b''
(E/'local-candidate.patch').write_bytes(git('format-patch','-1','--stdout','--full-index','--binary','HEAD'))
(E/'implementation.diff').write_bytes(git('diff','HEAD^','HEAD','--','src/checked_c_node.c'))
(E/'diff-stat.txt').write_bytes(git('diff','--stat','HEAD^','HEAD'))
(E/'local.commit').write_bytes(git('cat-file','commit','HEAD'))
(E/'parent.commit').write_bytes(git('cat-file','commit','HEAD^'))
(E/'final-source-manifest.json').write_text(json.dumps([dict(path=p,bytes=(W/p).stat().st_size,sha256=hashlib.sha256((W/p).read_bytes()).hexdigest(),mode='100644') for p in changed],indent=2)+'\n')
generated=[dict(path=p.name,bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in sorted((E/'generated').iterdir())]
summary=dict(status='LOCAL_READY / bounded declared capability / STOP C after custody',parent=git('rev-parse','HEAD^').decode().strip(),head=git('rev-parse','HEAD').decode().strip(),tree=git('rev-parse','HEAD^{tree}').decode().strip(),local_branch='p1535-scoped-root-read-local',main='b2f22d39b61c0cf3ea18b7a1529fa8f0bf801be1',canonical='Draft17.38',changed_paths=changed,diff='15files +1549/-6; private consumer57-line diff, focused own tests and CMake only',counts=counts,host_sites=3,Compiler_remote=0,SDK=0,not_run=['O0 guests','remaining3 guest reserve','full CTest sweep','LLVM backend','final repaired GCC frontend build (cap2 consumed; final Clang ASan frontend used)','new CI','callee payload/u8-return/general owner capability'],original_RED=[dict(layer='P1528 old7de source-owned/C17',immutable=True),dict(layer='new b1 baseline',ids=[4,8,12]),dict(layer='first private candidate',id=23),dict(layer='observer static generation',file='apparatus-static-FIRST-RED.txt'),dict(layer='formatter',id=101)],nonzero=nonzero,native='21 O2 guests; GCCzero/42 6, ClangASanzero/42 6, ClangUBSancomposed3, GCCfourstepzero3, Clangnormalcomposed3. Actual H0/H1/H2, physical original second->first release and same-T continuation. No sanitizer diagnostics.',negatives='5 source negatives CHECK3 plus rollback; 35 artifact+foreign origin negatives with pristine retry, composedprefix4; legal heldLiveTailprefix CHECK/MACHINE but backend refusal, no-clobber/rollback.',host='main/callee C text staging, trailingCopy replay clone: each fault/retry=6 cases; named main/callee fault/retry4 cases; total3sites10cases with state/out length98765/no-clobber/no temp residue.',format='final formatter PASS; post-test changes whitespace only, exact C token identity recorded, no third frontend/probe build',generated=generated,value_alignment_risk='Optional obtained/discarded root ref coverage; fourstep already permits caller payload->teardown->sameT. No useful callee payload/API/all safe-reachable-state or comparative author+caller audit/re-audit closure demonstration. ProductGO624 PAUSED/H1 HOLD, comparative value UNMEASURED; fair sound Rust facade and postpone optional alternative retained.',priority='No C correction relayed in1535 latest GET; public main b2f and PR1532 ref b1 unchanged; no independent R/F material read.',custody='One new normalGit Evidence ref archive/p1535-c1223-scoped-root-read-20261119; all manifest members and fixed-parent patch replay from fresh HTTPS required before temp deletion.')
(E/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
print(json.dumps(summary,indent=2))
