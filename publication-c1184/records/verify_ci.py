from pathlib import Path
import hashlib
import json
import re

p=Path('/workspace/p1525-evidence/publication-c1184')
runs=json.loads((p/'CI-run-metadata.json').read_text())
bundles=json.loads((p/'CI-original-jobs-final.json').read_text())
assert len(runs)==len(bundles)==6
first='dca50af1d7d59fc4c609810aa6c2968e9ec1e6eb'
final='7deabd1b1f44bc40862b6a28c89fde502832d8cb'
base='c97ce81c48a0c003b072c77c655bdeb10860ebf1'
initial=json.loads((p/'remote-head-and-run-metadata.json').read_text())
for old in initial[:3]:
    r=old['data']
    assert r['head_sha']==first and r['event']=='pull_request' and r['run_attempt']==1
    assert any(x['number']==1526 and x['head']['sha']==first and x['base']['sha']==base for x in r['pull_requests'])

job_rows=[]
for i,(run,bundle) in enumerate(zip(runs,bundles)):
    expected=first if i<3 else final
    assert run['status']=='completed' and run['event']=='pull_request'
    assert run['head_sha']==expected and run['run_attempt']==1
    assert run['conclusion']==('failure' if i==0 else 'success')
    # PR associations describe the current PR. run.head_sha and the original
    # checkout/immutable Git tree identify the historical execution subject.
    assert any(x['number']==1526 and x['head']['sha']==final and x['base']['sha']==base for x in run['pull_requests'])
    assert bundle['run_id']==run['id'] and len(bundle['jobs'])==[5,1,2,5,1,2][i]
    for job in bundle['jobs']:
        bad=job['id']==134747699566
        assert job['status']=='completed' and job['conclusion']==('failure' if bad else 'success')
        paths=list(p.glob(f'CI-*-{job["id"]}.log'));assert len(paths)==1
        raw=paths[0].read_bytes();text=raw.decode()
        merge='92a17ce07c2d3a7135646fd1d0d3e949685b890a' if i<3 else '3d0301cd4f0830b183f92eb0921bf08b6171392f'
        assert merge in text
        wanted=84 if i in (2,5) else 1169 if i in (1,4) else 1170
        receiver=len(re.findall(r'Test\s+#\d+: p1517_.*Passed',text))
        if bad:
            assert 'error: ignoring return value' in text
        else:
            assert f'100% tests passed, 0 tests failed out of {wanted}' in text
            assert not re.search(r'ERROR: (AddressSanitizer|LeakSanitizer)|runtime error:',text)
            assert receiver==(0 if wanted==84 else 18)
            if i in (0,3):assert re.search(r'llvm.c_api.*Passed',text)
        job_rows.append(dict(run_id=run['id'],job_id=job['id'],name=job['name'],phase='first' if i<3 else 'final',head=expected,conclusion=job['conclusion'],tests=0 if bad else wanted,receiver18_passes=receiver,log=paths[0].name,bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest(),checkout=merge))
assert len(job_rows)==len({j['job_id'] for j in job_rows})==16
summary=dict(final_head=final,final_tree='20083ff35349efd254e015f90dcac38a8d16852a',base=base,PR=1526,draft=True,required6='success',early2='success',head_count=2,run_count=6,job_count=16,manual_retry_dispatch_cancel=0,local=276,native=57,host_sites=6,host_cases=48,host_reinjection=0,SDK_acquisitions=1,Evidence_pushes_before_this_packet=1,first_Release_RED='preserved; build-layer unused write result',historical_PR_association='mutable; initial snapshot, run.head_sha and original checkout preserved',jobs=job_rows,F_R_originals_read=False,adoption='C/F/R separate; not self READY/merge',value_alignment_risk='UNMEASURED audit-locality benefit; Product GO PAUSED/H1 HOLD')
(p/'CI-final-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
print('All16 original logs and same-HEAD Required6/EARLY2 verified; first RED preserved')
