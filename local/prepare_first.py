from pathlib import Path
import json,hashlib,shutil
W=Path('/workspace/NewLang_P1539');E=Path('/workspace/p1539-c1240-local');S=E/'source';P=E/'probe'
S.mkdir();P.mkdir()
for name,original,close,write in [('zero','P-zero.nl','retire','write_reading'),('nonzero','P-composed.nl','close_cell','set_count')]:
    s=(W/'tests/p1535'/original).read_text()
    s=s.replace(s.splitlines()[0],'// P1539 own FIRST: caller H Copy -> plain u8 helper -> unit close -> original T.')
    mark=f'fn {close}('
    assert s.count(mark)==1
    s=s.replace(mark,'fn relay_byte(copied: u8) -> u8 {\n    copied\n}\n\n'+mark)
    actual=f'{close}(p1, a1, d1);';assert s.count(actual)==1
    s=s.replace(actual,'let relayed = relay_byte(sample);\n                    '+actual)
    old=f'{write}(w, sample)';assert s.count(old)==1
    s=s.replace(old,f'{write}(w, relayed)')
    (S/f'P-{name}.nl').write_text(s)
s=(S/'P-zero.nl').read_text()
for name,old,new in [('foreign-domain','retire(p1, a1, d1);','retire(p1, a1, d0);'),('foreign-allocation','retire(p1, a1, d1);','retire(p1, a0, d1);')]:
    assert s.count(old)==1;(S/f'N-{name}.nl').write_text(s.replace(old,new))
call='                    retire(p1, a1, d1);\n';assert s.count(call)==1
n=s.replace(call,'');read='                        read(r1@payload)';assert n.count(read)==1
(S/'N-live-read-at-end.nl').write_text(n.replace(read,'                        retire(p1, a1, d1);\n'+read))
read='                    let sample = loan_read(d1)';assert n.count(read)==1
(S/'N-post-end-read.nl').write_text(n.replace(read,call+read))
p=(W/'tests/p1535/public_owned.c').read_text()
p=p.replace('size_t calls, copies, payloads, destroys, frees, trials;', 'size_t calls, copies, payloads, destroys, frees, trials, helpers;')
p=p.replace('const NLCheckedFragment *copy_owners[2];','const NLCheckedFragment *copy_owners[2];\n    size_t helpers;\n    const NLCheckedFragment *helper_owner;\n    NLSymbolId helper_binding;\n    NLValueId helper_result;\n    NLSourceSpan helper_span;')
p=p.replace('v.value_dependency_count == 0;', 'v.value_dependency_count == 0 && v.reference_count == 0;')
helper=r'''static int helper(const NLCheckedFragment *f, NLCheckedNodeId id, Trace *t)
{
    const NLSemanticContext *c = nl_checked_context(f);
    const NLCheckedNodeView *call = nl_checked_node_view(f, id);
    const NLCheckedNodeView *arg = call ? nl_checked_node_view(f, call->first_argument) : NULL;
    const NLCheckedFragment *body = nl_checked_call_body(f, id);
    const NLCheckedNodeView *root = body ? nl_checked_node_view(body, nl_checked_root(body)) : NULL;
    const NLCheckedNodeView *tail = root ? nl_checked_node_view(body, root->tail) : NULL;
    NLTypeId u8 = nl_semantic_core_type(c, NL_TYPE_U8);
    NLSemanticBindingView input, formal, output;
    NEED(!t->helpers && t->reads == 1 && call && call->body_backed &&
         call->type == u8 && call->result_count == 1 && call->argument_count == 1 &&
         !call->owner_call.entry_proved && !call->producer.entry_proved &&
         arg && arg->kind == NL_CHECKED_IDENTIFIER && arg->type == u8 &&
         arg->parameter_type == u8 && !arg->next_argument &&
         arg->value_use == NL_VALUE_COPIED && arg->result_count == 1 &&
         scalar(c, arg->results[0].value, t->sample) &&
         scalar(c, call->results[0].value, t->sample) && body &&
         nl_checked_context(body) == c && root && root->kind == NL_CHECKED_BLOCK &&
         !root->terminates && !root->item_count && root->type == u8 &&
         root->result_count == 1 && tail && tail->kind == NL_CHECKED_IDENTIFIER &&
         tail->type == u8 && tail->value_use == NL_VALUE_COPIED &&
         tail->result_count == 1 && tail->symbol != arg->symbol &&
         nl_semantic_binding_view(c, tail->symbol, &formal) && formal.type == u8 &&
         formal.value == arg->results[0].value &&
         root->results[0].value == call->results[0].value &&
         tail->results[0].value == call->results[0].value &&
         nl_semantic_binding_view(c, arg->symbol, &input));
    size_t inputs = 0, outputs = 0;
    for (size_t i = 1; i <= nl_checked_node_count(f); ++i) {
        const NLCheckedNodeView *n = nl_checked_node_view(f, i);
        if (n->kind != NL_CHECKED_BINDING) continue;
        const NLCheckedNodeView *init = nl_checked_node_view(f, n->initializer);
        if (n->symbol == arg->symbol) {
            const NLCheckedNodeView *block = init ? nl_checked_node_view(f, init->initializer) : NULL;
            const NLCheckedNodeView *read = block ? nl_checked_node_view(f, block->tail) : NULL;
            NLSemanticScopeView scope;
            NEED(init && init->kind == NL_CHECKED_LOAN_HEADER && init->type == u8 &&
                 init->loan.body_nonescape_proved && init->loan.normal_result_forwarded &&
                 !init->loan.is_exclusive && init->loan.access == NL_ACCESS_READ &&
                 nl_semantic_scope_view(c, init->loan.scope, &scope) && !scope.active &&
                 read && read->kind == NL_CHECKED_LINK_READ && read->field.index == 1 &&
                 init->span.end_byte < call->span.start_byte &&
                 input.value == init->results[0].value &&
                 init->results[0].value == read->results[0].value);
            ++inputs;
        }
        if (n->initializer == id) {
            NEED(nl_semantic_binding_view(c, n->symbol, &output) && output.type == u8 &&
                 output.value == call->results[0].value);
            t->helper_binding = n->symbol;
            ++outputs;
        }
    }
    NEED(inputs == 1 && outputs == 1);
    t->helper_owner = f; t->helper_result = call->results[0].value;
    t->helper_span = call->span; ++t->helpers;
    printf("SCALAR_HELPER actual=%zu formal=%zu input=%zu result=%zu binding=%zu plain_u8_after_closed_caller_loan=1\n",
           id, tail->symbol, arg->results[0].value, t->helper_result, t->helper_binding);
    return 1;
}

'''
p=p.replace('static int copy(',helper+'static int copy(',1)
mark='    if (!t->copies) {\n        t->original_root = p.field.parent;'
assert p.count(mark)==1
use=r'''    if (t->copies) {
        const NLCheckedNodeView *call = nl_checked_node_view(f, id);
        const NLCheckedNodeView *first = call ? nl_checked_node_view(f, call->first_argument) : NULL;
        const NLCheckedNodeView *second = first ? nl_checked_node_view(f, first->next_argument) : NULL;
        NLSemanticBindingView result;
        NEED(t->helpers == 1 && t->helper_owner == f && second &&
             second->kind == NL_CHECKED_IDENTIFIER && second->value_use == NL_VALUE_COPIED &&
             second->symbol == t->helper_binding &&
             nl_semantic_binding_view(p.entry, second->symbol, &result) &&
             result.value == t->helper_result &&
             p.field.new_value == second->results[0].value);
        printf("HELPER_RESULT_CONSUMED same_original_T=%zu child=%zu actual_result=%zu\n",
               p.field.parent, p.field.child, t->helper_result);
    }
'''
p=p.replace(mark,use+mark)
p=p.replace('        if (n->owner_call.entry_proved) {\n            NEED(owner(f, id));', '        if (n->kind == NL_CHECKED_REGISTERED_CALL && n->argument_count == 1 &&\n            n->type == nl_semantic_core_type(c, NL_TYPE_U8)) {\n            NEED(helper(f, id, t)); ++out->helpers;\n        }\n        if (n->owner_call.entry_proved) {\n            NEED(t->helpers == 1 && t->helper_owner == f &&\n                 t->helper_span.end_byte < n->span.start_byte);\n            NEED(owner(f, id));')
p=p.replace('!branch.copies && !branch.payloads &&','!branch.copies && !branch.payloads && !branch.helpers &&')
p=p.replace('branch.copies == 1 && branch.payloads == 1 &&','branch.copies == 1 && branch.payloads == 1 && branch.helpers == 1 &&')
p=p.replace('                out->calls += branch.calls;', '                out->helpers += branch.helpers;\n                out->calls += branch.calls;')
p=p.replace('count.calls == 1 && count.copies == 2 && count.destroys == 3 &&', 'count.calls == 1 && count.copies == 2 && count.helpers == 1 &&\n         t.helpers == 1 && count.destroys == 3 &&')
(P/'public_owned.c').write_text(p)
manifest=[dict(path=str(p.relative_to(E)),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in [*sorted(S.iterdir()),P/'public_owned.c']]
(E/'FIRST-files.json').write_text(json.dumps(manifest,indent=2)+'\n')
print(json.dumps(manifest,indent=2))
