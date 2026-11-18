/* NewLang source-owned guarded quantity C17. */
#include <stddef.h>
#include <stdint.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static size_t nl_qty_fn_11(size_t nl_local_1)
{
    if (nl_local_1 < ((size_t)UINTMAX_C(16))) {
        size_t nl_local_2 = nl_local_1 + ((size_t)UINTMAX_C(1));
        return nl_local_2;
    } else {
        return nl_local_1;
    }
}

static size_t nl_qty_fn_10(void)
{
    size_t nl_local_2 = nl_qty_fn_11(((size_t)UINTMAX_C(11)));
    size_t nl_local_3 = nl_local_2;
    return nl_local_3;
}

int main(void)
{
    (void)nl_qty_fn_10();
    return 0;
}
