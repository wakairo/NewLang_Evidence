/* NewLang source-owned quantity composition C17. */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static size_t nl_qty_fn_10(_Bool nl_local_4)
{
    size_t nl_if_3;
    _Bool nl_condition_3 = nl_local_4;
    if (nl_condition_3) {
        nl_if_3 = ((size_t)UINTMAX_C(97));
    } else {
        nl_if_3 = ((size_t)UINTMAX_C(54));
    }
    size_t nl_local_5 = nl_if_3;
    (void)nl_local_5;
    size_t nl_if_7;
    _Bool nl_condition_7 = nl_local_4;
    if (nl_condition_7) {
        nl_if_7 = nl_local_5 / ((size_t)UINTMAX_C(7));
    } else {
        nl_if_7 = nl_local_5 / ((size_t)UINTMAX_C(5));
    }
    printf("%zu\n", nl_if_7);
    return nl_if_7;
}

static void nl_qty_fn_11(void)
{
    size_t nl_local_1 = ((size_t)UINTMAX_C(100));
    (void)nl_local_1;
    _Bool nl_local_2 = ((size_t)UINTMAX_C(64)) < nl_local_1;
    (void)nl_local_2;
    _Bool nl_local_3 = ((size_t)UINTMAX_C(124)) < nl_local_1;
    (void)nl_local_3;
    (void)(nl_qty_fn_10(nl_local_2));
    (void)(nl_qty_fn_10(nl_local_3));
    return;
}

int main(void)
{
    nl_qty_fn_11();
    return 0;
}
