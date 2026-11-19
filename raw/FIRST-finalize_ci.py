from pathlib import Path
import hashlib,json,re
E=Path('/workspace/p1531-evidence');packet=json.loads((E/'ci/final-API-packet.json').read_text());inventory=json.loads((E/'inventory-summary.json').read_text());expected=set(inventory['p1517']+inventory['p1529']);jobs=[]
for group in packet:
    run=group['run'];assert run['status']=='completed' and run['conclusion']=='success' and run['event']=='pull_request' and run['run_attempt']==1 and run['head_sha']=='c683ca533caaca05e1b546dd45f2a051295da81f'
    assert any(x['number']==1532 for x in run['pull_requests'])
    for job in group['jobs']:
        assert job['status']=='completed' and job['conclusion']=='success'
        p=E/'ci'/('job-'+str(job['id'])+'.log');raw=p.read_bytes();text=raw.decode('utf-8')
        assert 'cd466b636d1be482dd7698e228cecc330479235e' in text
        counts=re.findall(r'100% tests passed, 0 tests failed out of (\d+)',text);assert len(counts)==1
        passed=re.findall(r'Test\s+#\d+:\s+(\S+)\s+\.+\s+Passed',text)
        early=run['id']==44444037298;partial=run['id']==44444037319
        if early:
            assert int(counts[0])==84
            assert not any(x.startswith(('p1517_','p1529_')) for x in passed)
        else:
            assert expected.issubset(passed),(job['id'],expected-set(passed))
            assert int(counts[0])==(1179 if partial else 1180)
            assert ('llvm.c_api' in passed)==(not partial)
        jobs.append(dict(run_id=run['id'],job_id=job['id'],name=job['name'],conclusion=job['conclusion'],CTest_passed=int(counts[0]),p1517_passed=sum(x.startswith('p1517_') for x in passed),p1529_passed=sum(x.startswith('p1529_') for x in passed),LLVM_C_API_passed='llvm.c_api' in passed,decoded_log_bytes=len(raw),decoded_log_sha256=hashlib.sha256(raw).hexdigest(),synthetic_checkout='cd466b636d1be482dd7698e228cecc330479235e'))
assert len(jobs)==8 and len({j['job_id'] for j in jobs})==8
summary=dict(head='c683ca533caaca05e1b546dd45f2a051295da81f',tree='d8567d3a12a8c1e35e51f21369c8e495d58a97d9',base='b2f22d39b61c0cf3ea18b7a1529fa8f0bf801be1',all8_success=True,HEADs=1,HEAD_limit=2,job_count=8,job_limit=16,run_count=3,manual_retries=0,all_attempts=1,all_PR_event=True,all_required_28_P_tests_passed=True,EARLY_P1517_P1529_coverage=False,unexpected_CI_RED=0,jobs=jobs)
(E/'CI-final-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
print(json.dumps(summary,indent=2))
