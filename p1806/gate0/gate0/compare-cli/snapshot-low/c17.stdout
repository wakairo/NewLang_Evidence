/* NewLang source-owned quantity composition C17. */
#include <stddef.h>
#include <stdint.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static size_t nl_qty_fn_10(size_t nl_local_5)
{
    size_t nl_if_5;
    _Bool nl_condition_5 = nl_local_5 < ((size_t)UINTMAX_C(1024));
    if (nl_condition_5) {
        const size_t nl_product_left = nl_local_5;
        const size_t nl_product_right = ((size_t)UINTMAX_C(64));
        nl_if_5 = nl_product_left * nl_product_right;
    } else {
        nl_if_5 = ((size_t)UINTMAX_C(0));
    }
    return nl_if_5;
}

static uint8_t nl_qty_fn_13(size_t nl_local_7)
{
    return nl_local_7 < ((size_t)UINTMAX_C(4096)) ? ((uint8_t)UINT8_C(35)) : ((uint8_t)UINT8_C(93));
}

static uint8_t nl_qty_fn_11(uint8_t *nl_local_10, uint8_t nl_local_11)
{
    const uint8_t nl_previous = *nl_local_10;
    *nl_local_10 = nl_local_11;
    return nl_previous;
}

_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1, "NewLang C17 requires exact 8-bit uint8_t");

static void nl_qty_fn_12(void)
{
    struct { uint8_t f0; uint8_t f1; } nl_local_1 = { .f1 = ((uint8_t)UINT8_C(41)), .f0 = ((uint8_t)UINT8_C(117)), };
    struct { uint8_t f0; uint8_t f1; } nl_local_2 = { .f1 = ((uint8_t)UINT8_C(149)), .f0 = ((uint8_t)UINT8_C(101)), };
    size_t nl_local_3 = ((size_t)UINTMAX_C(3));
    (void)nl_local_3;
    size_t nl_if_22;
    _Bool nl_condition_22 = nl_local_3 < ((size_t)UINTMAX_C(8));
    if (nl_condition_22) {
        nl_if_22 = ((size_t)UINTMAX_C(63));
    } else {
        nl_if_22 = ((size_t)UINTMAX_C(64));
    }
    size_t nl_local_4 = nl_if_22;
    (void)nl_local_4;
    size_t nl_local_6 = nl_qty_fn_10(nl_local_4);
    (void)nl_local_6;
    uint8_t nl_local_8 = nl_qty_fn_13(nl_local_6);
    (void)nl_local_8;
    uint8_t nl_local_13;
    {
        uint8_t *const nl_local_9 = &nl_local_1.f1;
        nl_local_13 = nl_qty_fn_11(nl_local_9, nl_local_8);
    }
    const uint8_t nl_local_14 = nl_local_1.f1;
    (void)nl_local_14;
    const uint8_t nl_local_15 = nl_local_1.f0;
    (void)nl_local_15;
    uint8_t nl_local_20;
    {
        uint8_t *const nl_local_16 = &nl_local_2.f1;
        nl_local_20 = nl_qty_fn_11(nl_local_16, nl_local_14);
    }
    const uint8_t nl_local_21 = nl_local_2.f1;
    (void)nl_local_21;
    const uint8_t nl_local_22 = nl_local_2.f0;
    (void)nl_local_22;
    const uint8_t nl_local_23 = nl_local_13;
    (void)nl_local_23;
    const uint8_t nl_local_24 = nl_local_20;
    (void)nl_local_24;
    return;
}

int main(void)
{
    nl_qty_fn_12();
    return 0;
}
