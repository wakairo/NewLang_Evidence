from pathlib import Path
import hashlib
import json
import os

root = Path(__file__).resolve().parent
base = (root / 'source/P-zero.nl').read_text()

def write(name, text):
    (root / 'source' / name).write_text(text, encoding='utf-8', newline='\n')

def once(text, old, new):
    assert text.count(old) == 1, old
    return text.replace(old, new, 1)

write('P-nonzero.nl', once(base, 'payload: u8(0) }, stable1)',
                         'payload: u8(42) }, stable1)'))
write('N-foreign-allocation.nl', once(base, 'retire(p1, a1, d1);',
                                    'retire(p1, a0, d1);'))
write('N-foreign-domain.nl', once(base, 'retire(p1, a1, d1);',
                                'retire(p1, a1, d0);'))
write('N-owner-reused.nl', once(base, 'retire(p1, a1, d1);',
                              'retire(p1, a1, d1);\n'
                              '                    retire(p1, a1, d1);'))
write('N-stale-read.nl', once(base, 'retire(p1, a1, d1);',
                            'retire(p1, a1, d1);\n'
                            '                    let stale = loan_read(d1) { |late|\n'
                            '                        let dead = ref_from_ptr(read, p1, late);\n'
                            '                        read(dead@payload)\n'
                            '                    };'))
write('N-incomplete-callee.nl', once(base, '    deallocate(a, full);\n', ''))
failure = '''                    let empty0 = loan_exclusive_read(d0) { |end0|
                        destroy(p0, end0)
                    };
                    let full0 = erase_slot<Resource>(empty0);
                    finalize_domain(d0);
                    deallocate(a0, full0);
'''
assert base.count(failure) == 2
write('N-H1-leak.nl', base.replace(failure, '', 1))

cases = {
    'P-zero.nl': {'kind': 'positive', 'sample': 0},
    'P-nonzero.nl': {'kind': 'positive', 'sample': 42},
    'N-foreign-allocation.nl': {'kind': 'negative', 'reason': 'wrong original BackingRegion at receiver entry', 'predicted_code': 'P193-CALL-BACKING'},
    'N-foreign-domain.nl': {'kind': 'negative', 'reason': 'wrong original governing Domain at receiver entry', 'predicted_code': 'P193-CALL-DOMAIN'},
    'N-owner-reused.nl': {'kind': 'negative', 'reason': 'second use of consumed a1/d1', 'predicted_code': 'P3-USE-AFTER-CONSUME'},
    'N-stale-read.nl': {'kind': 'negative', 'reason': 'd1 consumed and p1 ended before attempted stability/read', 'predicted_code': 'P3-USE-AFTER-CONSUME'},
    'N-incomplete-callee.nl': {'kind': 'negative', 'reason': 'independent definition leaves Allocation/full Storage responsibility', 'predicted_code': 'P193-DEFINITION-OBLIGATION'},
    'N-H1-leak.nl': {'kind': 'negative', 'reason': 'second allocation None leaves first H/root/domain/Allocation alive', 'predicted_code': 'normal-exit affine/closure diagnostic, exact code not asserted'},
}
for name, case in cases.items():
    data = (root / 'source' / name).read_bytes()
    case.update(bytes=len(data), sha256=hashlib.sha256(data).hexdigest(), parse=0)
    if case['kind'] == 'positive':
        case.update(check_cli_exit=0, definition=0, actual=0,
                    proof_class='NL_CHECKED_MACHINE_PROVED',
                    public_copy_validators=0,
                    owner='real p1/a1/d1 -> same original callee EndRoot/full Storage/finalize/free; caller p0 release',
                    backend_hypothesis={'cli_exit': 4, 'code': 'V1-BACKEND-UNSUPPORTED',
                                        'C_output': 'absent',
                                        'first_guard_static_hypothesis': 'copy_prepare_at requires live_tail; owner_evidence also requires unrelated link topology; observed first guard may differ'})
    else:
        case.update(check_cli_exit=3, earliest_layer='definition-time semantic CHECK (actual proof must also fail if reached)',
                    accepted_safety_result='semantic rejection; precision refusal separately labeled, parser refusal is not safety coverage',
                    C_output='NOT_RUN; no emission for negative')

oracle = {
    'track': 'P', 'issue': 1515, 'mission': 'C1150 SOURCE-FIRST Gate0',
    'main': '4c388693b95f371783e666f5c77e0aec5d17d215',
    'tree': '867784ea863675788bc5ce4745904091ee319d3e',
    'spec': 'Draft17.38', 'cases': cases,
    'worlds': {
        'H0': {'allocations': 0, 'receiver_calls': 0, 'releases': 0, 'T_writes': 1, 'current': 0, 'second_T_write': False},
        'H1': {'allocations': 1, 'receiver_calls': 0, 'releases': 1, 'release_order': ['original0 caller'], 'T_writes': 1, 'current': 0, 'second_T_write': False},
        'H2': {'allocations': 2, 'receiver_calls': 1, 'releases': 2, 'release_order': ['original1 callee', 'original0 caller'], 'T_writes': 2, 'current': 'sample including zero', 'second_T_write': True}
    },
    'T': {'same_original': True, 'field': 0, 'old_Copy_first': 91, 'old_Copy_second_H2': 0, 'sibling_all_worlds': 23},
    'authentication': ['independent receiver definition requirements255 steps EndRoot/erase/finalize/free; no concrete root from signature',
                       'actual main() from public parse/register/check APIs; no seed/semantic fixtures',
                       'original two live regions/domains distinct at owner entry; actual inputs/formals/donors preserve identities and affine consume',
                       'callee only original1 destroy/erase/finalize/free; caller original0 destroy/free; no producer/LiveTail/link writes',
                       'payload read from original1 under D1; closed scopes; public Copy body/parameters/event validators for both named calls and same-original current/sibling',
                       'MACHINE class alone is insufficient; failed structural authentication halts before baseline C emission'],
    'limits': {'aggregate_local_attempts': 24, 'native_guest': 0, 'host_OOM': 0, 'CI_pairs': 0, 'branches_PR': 0,
               'baseline_emit_c17_to_max': 1, 'isolated_safety_negatives': 6},
    'budget_plan': 'one selected-target build check with every nested CC counted; one probe CC/link; two positive CLI; six negative CLI; two public API probe runs; at most one baseline CLI emit; repairs count additionally; no blanket full build',
    'apparatus': 'reuse environment-prepared frontend only after provenance/target dependency verification; isolated new output directory. No guest/native. Probe is compiler-host API observation, not generated program execution.',
    'prediction_discipline': 'all results predictions until run. Preserve FIRST sources/oracle and earliest diagnostics. Semantic/code change or apparatus repair needs separate new bytes/SHA and predictions before execution. No post-hoc PASS rewrite.',
    'value': 'technical capability/first refusal only; well-factored C versus NewLang author+ordinary-safe caller audit/re-audit dependency closure UNMEASURED. Rust sound facade is a valid alternative. Product GO624 PAUSED/H1#268 HOLD.'
}
(root / 'oracle.json').write_text(json.dumps(oracle, ensure_ascii=False, indent=2) + '\n')
s = os.statvfs(root)
resource = {'free_bytes': s.f_bavail*s.f_frsize, 'free_inodes': s.f_favail,
            'additional_peak_forecast_bytes': 33554432, 'additional_peak_forecast_inodes': 256,
            'basis': 'no full rebuild; prepared main frontend target verification, one small public probe object/executable, eight tiny sources and raw receipts; stop before any unexpected recompile fanout or capacity/budget excess',
            'margin_bytes': s.f_bavail*s.f_frsize-33554432,
            'margin_inodes': s.f_favail-256}
(root / 'resource-before.json').write_text(json.dumps(resource, indent=2) + '\n')
print(json.dumps({'cases': cases, 'resource': resource}, indent=2))
