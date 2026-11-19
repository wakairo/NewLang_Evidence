from pathlib import Path
import hashlib,importlib.util,json,subprocess,sys
E=Path('/workspace/p1539-c1243-integration');W=Path('/workspace/NewLang_P1539_integration');sys.dont_write_bytecode=True
sys.path.insert(0,str(E));from analyze_ci import analyze
HEAD='9bb09dd172fd3fd9ed0f2958dc2203092181d397';TREE='b7a0ab30f9150143df2434e8e478232daf9ca951';MAIN='9c9b17f7f0584c88a92ab284f57e4a93b8ab350b'
IDS={135430575943:'FULL',135430576195:'FULL',135430576205:'FULL',135430576232:'FULL',135430576380:'FULL',135430575972:'PARTIAL',135430576141:'EARLY',135430576741:'EARLY'}
def flatten(x):
 if isinstance(x,list):
  for y in x:yield from flatten(y)
 else:yield x
metadata=json.loads((E/'CI-API-FINAL.json').read_text());jobs=[j for p in metadata['packets'] for j in flatten(p['data']['jobs'])]
assert {x['id'] for x in jobs}==set(IDS) and len(jobs)==8
assert all(x['status']=='completed' and x['conclusion']=='success' for x in jobs)
verification=[analyze(E/'ci'/f'job-{i}.log',lane) for i,lane in IDS.items()]
assert len(verification)==8 and all(v['checkout']=='110692e27da7a498e19c97c17f84b8b7e76dce25' for v in verification)
for j in jobs:
 if j['name']=='Clang':assert any(s['name']=='Check C formatting and provide exact pinned-formatter correction' and s['conclusion']=='success' for s in j['steps'])
api=json.loads((E/'FINAL-API.json').read_text());pr=api['pr'];runs=api['runs']['workflow_runs']
assert pr['head']['sha']==HEAD and pr['base']['sha']==MAIN
adopted=json.loads((E/'adopted-main.json').read_text());ADOPTED='a9715f4bc788c13e213231c639057c2d718a9200'
assert api['main']['object']['sha']==ADOPTED and pr['merged'] and pr['state']=='closed' and not pr['draft'] and pr['merge_commit_sha']==ADOPTED and pr['merged_by']['login']=='wakairo'
assert adopted['sha']==ADOPTED and adopted['tree']['sha']==TREE and [p['sha'] for p in adopted['parents']]==[MAIN,HEAD]
assert json.loads((E/'PUBLICATION-API-FIRST.json').read_text())['prCreate']['draft']
assert len(runs)==api['runs']['total_count']==3
assert {r['id'] for r in runs}=={44486322406,44486322393,44486322427}
assert all(r['head_sha']==HEAD and r['run_attempt']==1 and r['event']=='pull_request' and r['conclusion']=='success' and r['status']=='completed' for r in runs)
assert subprocess.check_output(['git','-C',str(W),'rev-parse','HEAD'],text=True).strip()==HEAD
assert not subprocess.check_output(['git','-C',str(W),'status','--porcelain'],text=True).strip()
correspondence=json.loads((E/'integration-correspondence.json').read_text());assert all(r['byte_identity'] for r in correspondence['production'])
ledger=[json.loads(x) for x in (E/'ledger.jsonl').read_text().splitlines()];results=[json.loads(x) for x in (E/'results.jsonl').read_text().splitlines()]
assert len(ledger)==len(results)==6 and all(x['exit']==0 for x in results)
counts={k:sum(x[k] for x in ledger) for k in ['selected','frontend','probe','native','host']};assert counts==dict(selected=99,frontend=1,probe=1,native=6,host=4)
(E/'CI-log-verification.json').write_text(json.dumps(verification,indent=2)+'\n')
summary=dict(outcome='C1243 INTEGRATED / ALL8 ORIGINAL SUCCESS / C-ADOPTED EXACT TREE / PRODUCER STOP C',head=HEAD,tree=TREE,parent=MAIN,branch='p1539-scalar-integration-c1243',pr=1542,adopted_by_C_main=ADOPTED,adopted_main_tree=TREE,adoption_outside_P=True,publication_was_DRAFT=True,READY_merge_by_P=0,production_blobs_unchanged=['1d17ce025905b18b0b92dbae81ffb8f3d27f947f','10fe0ac4d98a55f261a34c9ad1508a7f5d2e4b8b'],changed_paths=13,diff='+1251/-4; production+22/-4 unchanged, root CMake include and10 test files',source_FIRST_unchanged=6,registered_new_tests=10,full_actual=[1201]*5,partial_actual=1200,early_actual=[84]*2,EARLY_new_test_execution=0,same_checkout='110692e27da7a498e19c97c17f84b8b7e76dce25',checkout_tree=TREE,required6_actual_new10_and_native=True,partial_real_CLI_exit0_empty_streams=True,Clang_format=True,public_candidate_HEADs=1,natural_runs=3,natural_jobs=8,second_HEAD=0,retry=0,dispatch=0,cancel=0,force=0,additional_local=counts,host_sites=2,fresh_GCC_compiled_CUs=35,fresh_GCC_child_build_tools=55,old_C1240_costs='100selected/18guest/2incrementalfrontends/3probe/2sites8 unchanged',selected_time_seconds=sum(x['seconds'] for x in results),NOT_RUN=['local fullCTest','local LLVM','new SDK acquisition','new local Clang integration run (normal fixed-HEAD Clang/ASan/UBSan CI is original successful evidence)','second public HEAD or natural set','P READY/merge (C adoption separately recorded)'],originals_kept='a026/FIRST/RED/0355, active original/integration worktrees, all original/new raw/builds and needed SDK',new_custody='one bounded integration/CI cohort; do not duplicate old0355 packet',value_alignment_risk='Finite ordinary by-value helper and normal delivery are capability evidence; trivial identity helper does not prove protected safe facade/full safe-reachable-state or reduced author+ordinary-safe-caller UB audit closure. ProductGO PAUSED/H1 HOLD/UNMEASURED; no new inert-profile expansion.')
(E/'summary.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary,indent=2))
