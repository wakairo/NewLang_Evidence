/* NewLang source-owned quantity composition C17. */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static size_t nl_qty_fn_10(_Bool nl_local_4)
{
    size_t nl_local_5 = ((size_t)UINTMAX_C(95));
    (void)nl_local_5;
    size_t nl_if_6;
    _Bool nl_condition_6 = nl_local_4;
    if (nl_condition_6) {
        nl_if_6 = nl_local_5 % ((size_t)UINTMAX_C(6));
    } else {
        nl_if_6 = nl_local_5 % ((size_t)UINTMAX_C(8));
    }
    return nl_if_6;
}

static void nl_qty_fn_11(void)
{
    size_t nl_local_1 = ((size_t)UINTMAX_C(103));
    (void)nl_local_1;
    _Bool nl_local_2 = ((size_t)UINTMAX_C(80)) < nl_local_1;
    (void)nl_local_2;
    _Bool nl_local_3 = ((size_t)UINTMAX_C(120)) < nl_local_1;
    (void)nl_local_3;
    size_t nl_local_6 = nl_qty_fn_10(nl_local_2);
    printf("%zu\n", nl_local_6);
    (void)nl_local_6;
    size_t nl_local_9 = nl_qty_fn_10(nl_local_3);
    printf("%zu\n", nl_local_9);
    (void)nl_local_9;
    return;
}

int main(void)
{
    nl_qty_fn_11();
    return 0;
}
