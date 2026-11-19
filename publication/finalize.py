"""Finalize publication/CI identity from original final API and logs only."""
from pathlib import Path
import json,subprocess,hashlib
from analyze_ci import analyze,EXPECTED
E=Path('/workspace/p1535-c1236-publication');P=Path('/workspace/NewLang_P1535_publication');W=Path('/workspace/NewLang_P1535')
HEAD='7b0b8e0a5348220061abe86921e9d006be5e398a';MAIN='1a32f87f1007db8e8c11dc375a6b7416a35adbc7';TREE='a7e0561c7b57e03330b1d1d91c90300dd093f938'
packet=json.loads((E/'CI-API-FINAL.json').read_text())
pr=packet['pr'];assert pr['number']==1538 and pr['draft'] and not pr['merged'] and pr['state']=='open'
assert pr['head_sha']==HEAD and pr['base_sha']==MAIN and pr['commits']==1 and pr['changed_files']==15
assert len(packet['runs'])==3 and {r['id'] for r in packet['runs']}=={44465857731,44465857708,44465857668}
alljobs=[]
for r in packet['runs']:
    assert r['head_sha']==HEAD and r['head_commit']['tree_id']==TREE and r['event']=='pull_request' and r['run_attempt']==1
    assert r['status']=='completed' and r['conclusion']=='success'
    assert any(p['number']==1538 and p['head']['sha']==HEAD and p['base']['sha']==MAIN for p in r['pull_requests'])
    js=packet['jobs'][str(r['id'])];assert len(js)==({44465857731:5,44465857708:1,44465857668:2}[r['id']])
    for j in js:
        assert j['status']=='completed' and j['conclusion']=='success'
        alljobs.append(dict(j,run_id=r['id']))
assert {j['id'] for j in alljobs}=={135363352200,135363352455,135363352474,135363352513,135363352591,135363352061,135363351901,135363352205}
rows=[]
for j in alljobs:
    lane='FULL' if j['run_id']==44465857731 else 'PARTIAL' if j['run_id']==44465857708 else 'EARLY'
    row=analyze(E/'ci'/f"job-{j['id']}.log",lane);row.update(job_id=j['id'],job_name=j['name'],run_id=j['run_id'],conclusion=j['conclusion']);rows.append(row)
g=lambda wd,*a:subprocess.check_output(['git',*a],cwd=wd)
assert g(P,'rev-list','--parents','-n1','HEAD').decode().split()==[HEAD,MAIN]
assert g(P,'rev-parse','HEAD^{tree}').decode().strip()==TREE and not g(P,'status','--porcelain')
assert g(W,'rev-parse','HEAD').decode().strip()=='58245a24e047280304443258b2cfc8a540c9202a' and not g(W,'status','--porcelain')
assert g(P,'ls-tree','-r','-z',HEAD)==g(P,'ls-tree','-r','-z','58245a24e047280304443258b2cfc8a540c9202a')
for m in json.loads((E/'integration-audit.json').read_text())['source_members']:
    b=(P/m['path']).read_bytes();assert len(b)==m['bytes'] and hashlib.sha256(b).hexdigest()==m['sha256'] and b==(W/m['path']).read_bytes()
assert subprocess.check_output(['git','ls-remote','https://github.com/wakairo/NewLang_Compiler.git','refs/heads/main']).decode().split()[0]==MAIN
assert subprocess.check_output(['git','ls-remote','https://github.com/wakairo/NewLang_Compiler.git','refs/heads/p1535-root-read-integration-c1236']).decode().split()[0]==HEAD
(E/'CI-log-verification.json').write_text(json.dumps(rows,indent=2)+'\n')
summary=dict(status='PUBLICATION_CI_COMPLETE / DRAFT HOLD / custody pending',pr=1538,url='https://github.com/wakairo/NewLang_Compiler/pull/1538',head=HEAD,tree=TREE,base=MAIN,branch='p1535-root-read-integration-c1236',original_local='58245a24e047280304443258b2cfc8a540c9202a',whole7452tree_entries_and15actual_bytes='EXACT',synthetic_checkout='3e17928d2340831a65286f8aac18f5c734c38b33',public_HEADs=1,Compiler_pushes=1,DRAFT_PRs=1,natural_runs=3,natural_jobs=8,attempts=1,all8_success=True,Required6_verified=True,Required6_new10_and_native_integration=True,EARLY_new10_coverage=0,additional_HEAD=0,manual_retry_dispatch_cancel=0,additional_local_build_probe_native_hostfault_CTest_SDK=0,prior_counters=dict(selected=149,frontend=3,probe=3,native=21,host_sites=3,host_cases=10),not_run=['additional local compiler/probe build or native/hostfault/CTest/SDK campaign','EARLY new10 tests','READY/merge','extra source/API/owner/body category or universal preservation claim'],scope='one-binding discarded same-D root ref -> ordinary scope closure -> original direct unit terminal teardown; declared named controls only',value_alignment_risk='Selected compiler coverage only. Callee payload/API/all safe-reachable state and author+ordinary safe caller UB audit/re-audit closure comparison UNMEASURED. ProductGO624 PAUSED/H1 HOLD.',CI=[{k:r[k] for k in ['job_id','job_name','run_id','conclusion','lane','total','actual_passed','native_integration_executed','sha256']} for r in rows])
(E/'summary.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary,indent=2))
