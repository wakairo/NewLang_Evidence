"""Read only original decoded job logs and fixed test-registration identities."""
from pathlib import Path
import json,re,hashlib
E=Path('/workspace/p1535-c1236-publication')
MERGE='3e17928d2340831a65286f8aac18f5c734c38b33'
HEAD='7b0b8e0a5348220061abe86921e9d006be5e398a'
MAIN='1a32f87f1007db8e8c11dc375a6b7416a35adbc7'
EXPECTED={'p1535_'+n for n in ['zero_owned.unit','nonzero_owned.unit','composed_owned.unit','negative_foreign-allocation.unit','negative_foreign-domain.unit','negative_foreign-pointer.unit','negative_live-read-at-end.unit','negative_post-end-read.unit','owner_authentication.unit','native.integration']}
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
    new={n for n in actual if n.startswith('p1535_')}
    if lane=='EARLY':
        assert int(total)==84 and not new
    else:
        assert new==EXPECTED,('NEW TEST COVERAGE',path,sorted(new))
        assert int(total)==(1191 if lane=='FULL' else 1190)
        assert 'p1535_native.integration' in actual
    cli=[]
    if lane=='PARTIAL':
        cli=[v for v in lines if 'NO LLVM / PARTIAL: Production source/checker exit 0, zero stdout/stderr' in v and 'echo ' not in v]
        assert cli and './build-frontend/newlangc --check' in s and 'test ! -s' in s,('PARTIAL CLI NOT VERIFIED',path)
        assert 'llvm.c_api' not in actual
    if lane=='FULL':assert 'llvm.c_api' in actual
    return dict(file=Path(path).name,bytes=len(b),sha256=hashlib.sha256(b).hexdigest(),checkout=MERGE,tree='a7e0561c7b57e03330b1d1d91c90300dd093f938',lane=lane,total=int(total),actual_passed=len(actual),new10_passed=sorted(new),native_integration_executed='p1535_native.integration' in actual,partial_actual_CLI=cli,source_of_bytes='Exact UTF-8 re-encoding of original connector-decoded complete job text, BOM/newlines retained; no ZIP or rerun.')
if __name__=='__main__':
    import sys
    print(json.dumps(analyze(sys.argv[1],sys.argv[2]),indent=2))
