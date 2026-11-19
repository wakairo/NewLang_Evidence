"""Read only original decoded job logs and fixed test-registration identities."""
from pathlib import Path
import json,re,hashlib
E=Path('/workspace/p1539-c1243-integration')
MERGE='110692e27da7a498e19c97c17f84b8b7e76dce25'
HEAD='9bb09dd172fd3fd9ed0f2958dc2203092181d397'
MAIN='9c9b17f7f0584c88a92ab284f57e4a93b8ab350b'
EXPECTED={'p1539_'+n for n in ['zero_owned.unit','nonzero_owned.unit','negative_foreign-allocation.unit','negative_foreign-domain.unit','negative_live-read-at-end.unit','negative_post-end-read.unit','artifact_authentication.unit','rollback_4.unit','rollback_5.unit','native.integration']}
def analyze(path,lane):
    b=Path(path).read_bytes();s=b.decode('utf-8');lines=s.splitlines()
    checkout=[v for v in lines if MERGE in v and ('fetch' in v or v.rstrip().endswith(MERGE))]
    assert checkout and any('HEAD is now at '+MERGE[:7] in v and HEAD in v and MAIN in v for v in lines),('CHECKOUT STOP',path)
    summaries=re.findall(r'(\d+)% tests passed, (\d+) tests failed out of (\d+)',s)
    assert summaries,('NO EXECUTION SUMMARY',path)
    passed,total_failed,total=summaries[-1];assert passed=='100' and total_failed=='0'
    actual=[]
    for v in lines:
        if re.search(r'\d+/\d+ Test\s+#\d+:',v) and re.search(r'\bPassed\b',v):
            m=re.search(r'Test\s+#\d+:\s+(\S+)',v)
            if m:actual.append(m.group(1))
    assert len(actual)==len(set(actual))==int(total),('ACTUAL TEST COUNT',path,len(actual),total)
    new={n for n in actual if n.startswith('p1539_')}
    if lane=='EARLY':
        assert int(total)==84 and not new
    else:
        assert new==EXPECTED,('NEW TEST COVERAGE',path,sorted(new))
        assert int(total)==(1201 if lane=='FULL' else 1200)
        assert 'p1539_native.integration' in actual
    cli=[]
    if lane=='PARTIAL':
        cli=[v for v in lines if 'NO LLVM / PARTIAL: Production source/checker exit 0, zero stdout/stderr' in v and 'echo ' not in v]
        assert cli and './build-frontend/newlangc --check' in s and 'test ! -s' in s,('PARTIAL CLI NOT VERIFIED',path)
        assert 'llvm.c_api' not in actual
    if lane=='FULL':assert 'llvm.c_api' in actual
    return dict(file=Path(path).name,bytes=len(b),sha256=hashlib.sha256(b).hexdigest(),checkout=MERGE,tree='b7a0ab30f9150143df2434e8e478232daf9ca951',lane=lane,total=int(total),actual_passed=len(actual),new10_passed=sorted(new),native_integration_executed='p1539_native.integration' in actual,partial_actual_CLI=cli,source_of_bytes='Exact UTF-8 re-encoding of original connector-decoded complete job text, BOM/newlines retained; no ZIP or rerun.')
if __name__=='__main__':
    import sys
    print(json.dumps(analyze(sys.argv[1],sys.argv[2]),indent=2))
