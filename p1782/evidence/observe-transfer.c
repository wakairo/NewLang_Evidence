#include <stdio.h>
#include "newlang/copy_body.h"
#include "src/c17_local_field_internal.h"
#include "src/control.h"
#include "src/division_usize_internal.h"
#include "src/h_origin_internal.h"
#include "src/pure_u8_internal.h"
#include "tests/support/node_checked.h"

typedef struct {
    const NLCheckedNodeView *loan;
    NLCheckedNodeId call;
    NLCopyBodyParameters parameters;
    NLCheckedField change;
    const NLCheckedField *sibling;
    NLValueId constructor;
} Exchange;

static bool observe_call(const NLCheckedFragment *body, NLCheckedNodeId id,
                         Exchange *v)
{
    NLCopyBodyView view;
    NLCopyBodyEventView event;
    CHECK(nl_checked_copy_body_parameters(body, id, &v->parameters) &&
          nl_checked_copy_body_view(body, id, &view) &&
          nl_checked_copy_body_event(body, id, 0, &event));
    const NLCheckStatus replay =
        nl_checked_copy_body_parameters_validate(body, id, &v->parameters);
    printf("replay=%d event_count=%zu change_result=%zu returned=%zu\n",
           (int)replay, view.event_count, event.result, view.result.value);
    CHECK(replay == NL_CHECK_OK && view.event_count == 1 &&
          event.kind == NL_COPY_BODY_CHANGE);
    const NLCheckedNodeView *writer_root = nl_checked_node_view(view.body, view.root);
    CHECK(writer_root);
    const NLCheckedNodeView *tail = nl_checked_node_view(view.body, writer_root->tail);
    CHECK(tail && tail->results[0].value == view.result.value);
    if (writer_root->tail == event.node) {
        CHECK(view.result.value == event.result);
    } else {
        const NLCheckedNodeView *binding = nl_checked_node_view(view.body, writer_root->first_item);
        CHECK(binding && binding->kind == NL_CHECKED_BINDING &&
              binding->initializer == event.node && tail->kind == NL_CHECKED_IDENTIFIER &&
              tail->symbol == binding->symbol && tail->value_use == NL_VALUE_COPIED);
    }
    const NLCheckedNodeView *loan =
        nl_checked_node_view(body, v->parameters.loan);
    CHECK(loan && loan->kind == NL_CHECKED_LOAN_HEADER &&
          loan->loan.body_nonescape_proved && loan->loan.normal_result_forwarded &&
          loan->results[0].value == view.result.value);
    v->loan = loan;
    v->call = id;
    v->change = event.field;
    const NLCheckedField *field = &v->change;
    for (NLCheckedNodeId i = 1; i <= body->count; ++i) {
        const NLCheckedNodeView *node = nl_checked_node_view(body, i);
        if (node->kind == NL_CHECKED_BINDING && node->symbol == field->base) {
            const NLCheckedNodeView *ctor =
                nl_checked_node_view(body, node->initializer);
            CHECK(ctor && ctor->kind == NL_CHECKED_AGGREGATE && !v->constructor);
            v->constructor = ctor->results[0].value;
        }
        if (node->kind == NL_CHECKED_FIELD_READ &&
            node->field.parent == field->parent && node->field.index != field->index) {
            CHECK(!v->sibling);
            v->sibling = &node->field;
        }
    }
    CHECK(v->constructor && v->sibling &&
          nl_c17_descriptor_frame(v->parameters.entry, field->base,
                                  v->constructor, field, v->sibling));
    NLSemanticScopeView scope;
    NLSemanticPlaceView root, child, sibling;
    NLSemanticValueView old;
    CHECK(nl_semantic_scope_view(body->context, loan->loan.scope, &scope) &&
          !scope.active &&
          nl_semantic_place_view(body->context, field->parent, &root) &&
          nl_semantic_place_view(body->context, field->child, &child) &&
          nl_semantic_place_view(body->context, v->sibling->child, &sibling) &&
          !root.live && !child.live && !sibling.live &&
          root.incarnation == field->parent_incarnation &&
          child.incarnation == field->child_incarnation &&
          sibling.incarnation == v->sibling->child_incarnation);
    CHECK(nl_semantic_value_view(body->context, view.result.value, &old) &&
          old.scalar_known);
    printf("site=%zu function=%zu scope=%zu root=%zu/%zu field=%zu/%zu sibling=%zu "
           "old=%zu pre_fact=%zu post_fact=%zu replay=%d change=1 closed=1 ended=1\n",
           id, view.function, loan->loan.scope, field->parent, field->parent_incarnation,
           field->child, field->child_incarnation, v->sibling->child, old.scalar_value,
           field->child_fact, field->child_post_fact, (int)replay);
    return true;
}

static bool frames(const NLCheckedFragment *body, const Exchange *active,
                   const Exchange *standby)
{
    const NLCheckedNodeId product = body->body_calls[0], selector = body->body_calls[1];
    const NLCheckedFragment *product_body = nl_checked_call_body(body, product);
    CHECK(product_body);
    const NLCheckedNodeView *product_root = nl_checked_node_view(product_body, product_body->root);
    NLPureU8Call mode;
    CHECK(product_root && nl_pure_u8_call(body, selector, &mode));
    NLCheckedNodeId count = 0;
    for (size_t i = 0; i < body->count; ++i) {
        const NLCheckedNodeId id = i + 1;
        if (nl_checked_node_view(body, id)->kind == NL_CHECKED_IF) {
            CHECK(!count);
            count = id;
        }
    }
    CHECK(count);
    const NLCheckedFragment *owners[] = {body, product_body, mode.body};
    const NLCheckedNodeId choices[] = {count, product_root->tail, mode.selection};
    for (size_t i = 0; i < 3; ++i) {
        for (size_t arm = 0; arm < 2; ++arm) {
            const NLSemanticContext *c =
                nl_checked_context(nl_checked_if_arm(owners[i], choices[i], arm));
            CHECK(nl_c17_descriptor_frame(c, active->change.base, active->constructor,
                                          &active->change, active->sibling) &&
                  nl_c17_descriptor_frame(c, standby->change.base, standby->constructor,
                                          &standby->change, standby->sibling));
        }
    }
    return true;
}

static bool transfer(const NLCheckedFragment *body, const NLCheckedNodeView *root,
                     const Exchange *left, const Exchange *right)
{
    const NLCheckedNodeView *binding = NULL;
    for (NLCheckedNodeId id = root->first_item; id;) {
        const NLCheckedNodeView *item = nl_checked_node_view(body, id);
        CHECK(item);
        if (item->initializer == left->parameters.loan) {
            binding = nl_checked_node_view(body, item->next_item);
            break;
        }
        id = item->next_item;
    }
    CHECK(binding && binding->kind == NL_CHECKED_BINDING);
    const NLCheckedNodeView *read = nl_checked_node_view(body, binding->initializer);
    const NLCheckedNodeView *actual = nl_checked_node_view(body, right->parameters.arguments[1]);
    const NLCheckedField *changed = &left->change;
    CHECK(read && read->kind == NL_CHECKED_FIELD_READ && read->value_use == NL_VALUE_COPIED &&
          read->field.present && read->field.base == changed->base &&
          read->field.parent == changed->parent &&
          read->field.parent_incarnation == changed->parent_incarnation &&
          read->field.parent_fact == changed->parent_post_fact &&
          read->field.index == changed->index && read->field.child == changed->child &&
          read->field.child_incarnation == changed->child_incarnation &&
          read->field.child_fact == changed->child_post_fact &&
          read->field.old_value == changed->new_value &&
          left->loan->span.end_byte < read->span.start_byte &&
          read->span.end_byte < right->loan->span.start_byte);
    NLSemanticBindingView entry_binding;
    NLSemanticValueView read_value, actual_value;
    const NLSemanticContext *entry = right->parameters.entry;
    CHECK(nl_semantic_binding_view(entry, binding->symbol, &entry_binding) &&
          entry_binding.availability == NL_AVAILABLE &&
          entry_binding.value == read->results[0].value &&
          actual && actual->kind == NL_CHECKED_IDENTIFIER && actual->value_use == NL_VALUE_COPIED &&
          actual->symbol == binding->symbol && actual->type == read->type &&
          nl_semantic_value_view(body->context, read->results[0].value, &read_value) &&
          nl_semantic_value_view(body->context, actual->results[0].value, &actual_value) &&
          read_value.type == actual_value.type && !read_value.scalar_known &&
          !actual_value.scalar_known && read_value.dependencies == NL_DEPENDENCY_FREE &&
          actual_value.dependencies == NL_DEPENDENCY_FREE);

    NLCopyBodyView validated;
    NLCopyBodyEventView event;
    CHECK(nl_checked_copy_body_view(body, right->call, &validated) &&
          nl_checked_copy_body_event(body, right->call, 0, &event));
    const NLCheckedNodeView *store = nl_checked_node_view(validated.body, event.node);
    CHECK(store && store->kind == NL_CHECKED_REPLACE);
    const NLCheckedNodeView *target = nl_checked_node_view(validated.body, store->first_argument);
    CHECK(target);
    const NLCheckedNodeView *mode = nl_checked_node_view(validated.body, target->next_argument);
    CHECK(mode && mode->kind == NL_CHECKED_IDENTIFIER && mode->value_use == NL_VALUE_COPIED &&
          mode->symbol == right->parameters.parameters[1] &&
          event.incoming == mode->results[0].value);
    printf("active_new=%zu read_field_fact=%zu tracked_read_copy=%zu through_symbol=%zu "
           "actual=%zu formal=%zu validated_change_incoming=%zu scalar_known=0\n",
           changed->new_value, read->field.child_fact, read->results[0].value,
           binding->symbol, actual->results[0].value, mode->symbol, event.incoming);
    return true;
}

static bool observe(const TestNode *test)
{
    const NLCheckedNodeId site = nl_checked_root(test->entry);
    const NLCheckedNodeView *call = nl_checked_node_view(test->entry, site);
    const NLCheckedFragment *body = nl_checked_call_body(test->entry, site);
    const NLCheckedNodeView *root = body ? nl_checked_node_view(body, body->root) : NULL;
    CHECK(call && root && body->body_count == 4 && root->item_count == 16 &&
          root->terminates && nl_control_exits_count(body->exits) == 1 &&
          nl_control_exits_only_return(body->exits, body->function_target));
    NLDivisionUsizePlan plan;
    printf("items=%zu calls=%zu quantity_plan=%d entry_world=%d\n",
           root->item_count, body->body_count,
           nl_quantity_usize_body_at(body, body->context, call->function, true, &plan),
           nl_h_custody_result_world_present(test->entry, site));
    Exchange left = {0}, right = {0};
    CHECK(observe_call(body, body->body_calls[2], &left) &&
          observe_call(body, body->body_calls[3], &right));
    const NLCheckedField *a = &left.change, *b = &right.change;
    const NLSemanticContext *second_entry = right.parameters.entry;
    NLSemanticScopeView first_scope;
    NLSemanticPlaceView active, active_field;
    CHECK(a->parent != b->parent && a->child != b->child &&
          left.sibling->child != right.sibling->child &&
          left.loan->span.end_byte < right.loan->span.start_byte &&
          nl_semantic_scope_view(second_entry, left.loan->loan.scope, &first_scope) &&
          !first_scope.active &&
          nl_semantic_place_view(second_entry, a->parent, &active) && active.live &&
          active.incarnation == a->parent_incarnation && active.current_fact == a->parent_post_fact &&
          nl_semantic_place_view(second_entry, a->child, &active_field) && active_field.live &&
          active_field.incarnation == a->child_incarnation &&
          active_field.current_value == a->new_value && active_field.current_fact == a->child_post_fact &&
          nl_c17_descriptor_frame(left.parameters.entry, b->base, right.constructor,
                                 b, right.sibling) &&
          frames(body, &left, &right) && transfer(body, root, &left, &right));
    puts("distinct_originals=1 first_closed_at_second_entry=1 live_first_post_at_second_entry=1 "
         "second_unmodified_in_first_entry=1 both_original_frames_in_all_six_arms=1");
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 2;
    TestNode node = {0};
    const bool ok = node_checked_load(argv[1], &node) && observe(&node);
    node_checked_destroy(&node);
    return ok ? 0 : 1;
}
