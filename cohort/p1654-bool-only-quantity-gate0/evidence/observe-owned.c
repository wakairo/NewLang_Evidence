#include "newlang/checked.h"
#include "newlang/parser.h"
#include "newlang/source.h"
#include "newlang/usize_division.h"

#include <stdio.h>

#define NEED(c) do { \
    if (!(c)) { fprintf(stderr, "observe:%d: %s\n", __LINE__, #c); return false; } \
} while (0)

static bool scalar(const NLCheckedFragment *f, const NLCheckedNodeView *node,
                   NLSemanticValueView *out)
{
    return node && node->result_count == 1 &&
           nl_semantic_value_view(nl_checked_context(f), node->results[0].value, out) &&
           out->type == node->results[0].type;
}

static bool copy_value(const NLCheckedFragment *f, const NLCheckedNodeView *node,
                       NLSemanticValueView *out)
{
    NLSemanticBindingView binding;
    const NLSemanticContext *context = nl_checked_context(f);
    return node && node->kind == NL_CHECKED_IDENTIFIER &&
           node->value_use == NL_VALUE_COPIED &&
           scalar(f, node, out) && out->scalar_known &&
           nl_semantic_binding_view(context, node->symbol, &binding) &&
           binding.type == out->type && binding.value != node->results[0].value;
}

static bool inspect_arm(const NLCheckedFragment *body, NLCheckedNodeId id,
                        size_t index, NLValueId stock_actual)
{
    const NLCheckedFragment *arm = nl_checked_if_arm(body, id, index);
    NEED(arm && nl_checked_source(arm) == nl_checked_source(body) &&
         nl_checked_context(arm) != nl_checked_context(body));
    const NLCheckedNodeView *root = nl_checked_node_view(arm, nl_checked_root(arm));
    const NLCheckedNodeView *block = root ? nl_checked_node_view(arm, root->initializer) : NULL;
    const NLCheckedNodeView *tail = block ? nl_checked_node_view(arm, block->tail) : NULL;
    NLSemanticValueView result;
    NEED(scalar(arm, root, &result) && tail);
    printf("ARM index=%zu normal=1 separate_context=1 known=%d value=%zu\n",
           index, result.scalar_known, result.scalar_value);
    if (tail->kind == NL_CHECKED_USIZE_LITERAL) {
        puts("LITERAL_ARM arithmetic=none");
        return true;
    }
    NEED(tail->kind == NL_CHECKED_USIZE_DIVISION);
    const NLCheckedNodeView *left = nl_checked_node_view(arm, tail->first_argument);
    NLSemanticValueView use;
    NLSemanticBindingView original;
    NEED(copy_value(arm, left, &use) &&
         nl_semantic_binding_view(nl_checked_context(body), left->symbol, &original));
    NLUsizeDivisionView v = {0};
    const bool have = nl_checked_usize_division_view(arm, block->tail, &v);
    printf("DIVISION view=%d valid=%d original_arm=%d numerator_known=%d numerator=%zu "
           "divisor=%zu quotient_known=%d quotient=%zu input_from_usize_actual=%d\n",
           have, nl_checked_usize_division_valid(arm, block->tail, NULL),
           have && v.origin == arm, v.numerator_known, v.numbers[0], v.numbers[1],
           v.quotient_known, v.quotient, stock_actual && original.value == stock_actual);
    return true;
}

static bool inspect_call(const NLCheckedFragment *main, NLCheckedNodeId id)
{
    const NLCheckedNodeView *call = nl_checked_node_view(main, id);
    const NLCheckedFragment *body = nl_checked_call_body(main, id);
    NEED(call && call->kind == NL_CHECKED_REGISTERED_CALL && call->body_backed &&
         (call->argument_count == 1 || call->argument_count == 2) &&
         body && nl_checked_context(body) == nl_checked_context(main));
    const NLSemanticContext *context = nl_checked_context(main);
    const NLTypeId boolean = nl_semantic_core_type(context, NL_TYPE_BOOL);
    const NLTypeId usize = nl_semantic_core_type(context, NL_TYPE_USIZE);
    const NLCheckedNodeView *actual = nl_checked_node_view(main, call->first_argument);
    NLValueId stock_slot = 0;
    if (call->argument_count == 2) {
        NLSemanticValueView stock;
        NEED(copy_value(main, actual, &stock) && stock.type == usize &&
             actual->parameter_type == usize);
        stock_slot = actual->results[0].value;
        printf("USIZE_ACTUAL copy=1 slot=%zu value=%zu\n", stock_slot, stock.scalar_value);
        actual = nl_checked_node_view(main, actual->next_argument);
    }
    NLSemanticValueView arg;
    NEED(copy_value(main, actual, &arg) && arg.type == boolean &&
         actual->parameter_type == boolean && !actual->next_argument);
    const NLValueId actual_slot = actual->results[0].value;
    printf("CALL id=%zu arity=%zu body_owned=1 same_world=1 "
           "bool_actual_copy=1 bool_actual_slot=%zu bool_value=%zu\n",
           id, call->argument_count, actual_slot, arg.scalar_value);
    NLCheckedNodeId site = 0;
    for (NLCheckedNodeId i = 1; i <= nl_checked_node_count(body); ++i) {
        const NLCheckedNodeView *n = nl_checked_node_view(body, i);
        if (n && n->kind == NL_CHECKED_IF) {
            NEED(!site && n->normal_arms == 2);
            site = i;
        }
    }
    const NLCheckedNodeView *join = nl_checked_node_view(body, site);
    const NLCheckedNodeView *condition = join ? nl_checked_node_view(body, join->initializer) : NULL;
    NLSemanticValueView cond, join_value, call_value, body_value;
    NLSemanticBindingView formal;
    NEED(copy_value(body, condition, &cond) && cond.type == boolean &&
         nl_semantic_binding_view(context, condition->symbol, &formal) &&
         scalar(body, join, &join_value) && scalar(main, call, &call_value));
    const NLCheckedNodeView *body_root = nl_checked_node_view(body, nl_checked_root(body));
    NEED(scalar(body, body_root, &body_value));
    printf("IF site=%zu normal_arms=2 condition_copy=1 condition=%zu "
           "formal_binding_slot=%zu formal_is_actual=%d join_known=%d "
           "body_is_call_result=%d call_known=%d\n",
           site, cond.scalar_value, formal.value,
           formal.value == actual_slot && arg.scalar_value == cond.scalar_value,
           join_value.scalar_known, body_root->results[0].value == call->results[0].value,
           call_value.scalar_known);
    return inspect_arm(body, site, 0, stock_slot) && inspect_arm(body, site, 1, stock_slot);
}

static bool inspect(const NLCheckedFragment *entry)
{
    const NLCheckedFragment *body = nl_checked_call_body(entry, nl_checked_root(entry));
    printf("OWNED main_present=%d machine_proved=%d\n", body != NULL,
           nl_checked_proof_class(entry) == NL_CHECKED_MACHINE_PROVED);
    NEED(body);
    size_t calls = 0;
    for (NLCheckedNodeId i = 1; i <= nl_checked_node_count(body); ++i) {
        const NLCheckedNodeView *n = nl_checked_node_view(body, i);
        if (n && n->kind == NL_CHECKED_REGISTERED_CALL) {
            NEED(inspect_call(body, i));
            ++calls;
        }
    }
    return calls == 2;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 2;
    NLSource *source = NULL, *entry_source = NULL;
    NLParser *parse_unit = NULL, *parse_entry = NULL;
    NLSyntaxTree *unit = NULL, *expression = NULL;
    NLSemanticContext *context = NULL;
    NLCheckedFragment *entry = NULL;
    NLParseDiagnostic pd = {0};
    NLFunctionUnitDiagnostic ud = {0};
    NLCheckDiagnostic cd = {0};
    int rc = 1;
    const NLSourceStatus loaded = nl_source_load(argv[1], &source);
    printf("LOAD status=%d\n", loaded);
    if (loaded != NL_SOURCE_OK || nl_parser_create(source, &parse_unit) != NL_PARSE_OK)
        goto done;
    const NLParseStatus parsed = nl_parser_parse_function_unit(parse_unit, &unit, &pd);
    printf("SOURCE parse=%d\n", parsed);
    if (parsed != NL_PARSE_OK || nl_semantic_create(&context) != NL_CHECK_OK)
        goto done;
    const NLSyntaxTree *units[] = {unit};
    const NLCheckStatus registered = nl_semantic_register_function_unit(context, units, 1, &ud);
    printf("UNIT register=%d diagnostic=%s\n", registered,
           ud.diagnostic.diagnostic.code ? ud.diagnostic.diagnostic.code : "-");
    if (registered != NL_CHECK_OK ||
        nl_source_create("main()", sizeof("main()") - 1, "<v0-entry>", &entry_source) != NL_SOURCE_OK ||
        nl_parser_create(entry_source, &parse_entry) != NL_PARSE_OK ||
        nl_parser_parse_expression_fragment(parse_entry, &expression, &pd) != NL_PARSE_OK)
        goto done;
    const NLCheckStatus status = nl_semantic_check_expression(context, expression, &entry, &cd);
    printf("CHECK status=%d artifact=%d diagnostic=%s\n", status, entry != NULL,
           cd.diagnostic.code ? cd.diagnostic.code : "-");
    if (status == NL_CHECK_OK && entry && inspect(entry))
        rc = 0;
done:
    nl_checked_destroy(entry);
    nl_syntax_tree_destroy(expression);
    nl_parser_destroy(parse_entry);
    nl_source_destroy(entry_source);
    nl_semantic_destroy(context);
    nl_syntax_tree_destroy(unit);
    nl_parser_destroy(parse_unit);
    nl_source_destroy(source);
    return rc;
}
