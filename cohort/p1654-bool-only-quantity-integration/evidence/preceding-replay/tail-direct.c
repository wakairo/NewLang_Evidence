/* NewLang source-owned quantity composition C17. */
#include <stddef.h>
#include <stdint.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static size_t nl_qty_fn_11(size_t nl_local_3)
{
    _Static_assert(UINTMAX_C(11) != 0, "nonzero divisor");
    return nl_local_3 % ((size_t)UINTMAX_C(11));
}

static size_t nl_qty_fn_12(size_t nl_local_1)
{
    size_t nl_if_5;
    _Bool nl_condition_5 = nl_local_1 < ((size_t)UINTMAX_C(50));
    if (nl_condition_5) {
        nl_if_5 = ((size_t)UINTMAX_C(38));
    } else {
        nl_if_5 = ((size_t)UINTMAX_C(53));
    }
    size_t nl_local_2 = nl_if_5;
    (void)nl_local_2;
    size_t nl_if_11;
    _Bool nl_condition_11 = nl_local_1 < ((size_t)UINTMAX_C(100));
    if (nl_condition_11) {
        nl_if_11 = nl_qty_fn_11(nl_local_2 % ((size_t)UINTMAX_C(7)));
    } else {
        nl_if_11 = ((size_t)UINTMAX_C(17));
    }
    size_t nl_local_3 = nl_if_11;
    (void)nl_local_3;
    return nl_local_3;
}

static void nl_qty_fn_10(void)
{
    size_t nl_local_4 = nl_qty_fn_12(((size_t)UINTMAX_C(40)));
    (void)nl_local_4;
    size_t nl_local_8 = nl_qty_fn_12(((size_t)UINTMAX_C(90)));
    (void)nl_local_8;
    size_t nl_local_12 = nl_qty_fn_12(((size_t)UINTMAX_C(165)));
    (void)nl_local_12;
    return;
}

int main(void)
{
    nl_qty_fn_10();
    return 0;
}
