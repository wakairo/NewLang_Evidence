/* NewLang source-owned quantity composition C17. */
#include <stddef.h>
#include <stdint.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static size_t nl_qty_fn_11(_Bool nl_local_4)
{
    size_t nl_if_3;
    _Bool nl_condition_3 = nl_local_4;
    if (nl_condition_3) {
        nl_if_3 = ((size_t)UINTMAX_C(23));
    } else {
        nl_if_3 = ((size_t)UINTMAX_C(41));
    }
    return nl_if_3;
}

static void nl_qty_fn_10(void)
{
    size_t nl_local_1 = ((size_t)UINTMAX_C(61));
    (void)nl_local_1;
    _Bool nl_local_2 = ((size_t)UINTMAX_C(30)) < nl_local_1;
    (void)nl_local_2;
    _Bool nl_local_3 = ((size_t)UINTMAX_C(70)) < nl_local_1;
    (void)nl_local_3;
    (void)(nl_qty_fn_11(nl_local_2));
    (void)(nl_qty_fn_11(nl_local_3));
    return;
}

int main(void)
{
    nl_qty_fn_10();
    return 0;
}
