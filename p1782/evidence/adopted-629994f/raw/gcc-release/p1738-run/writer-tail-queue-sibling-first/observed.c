#include <assert.h>
#include <stdio.h>
/* NewLang source-owned quantity composition C17. */
#include <stddef.h>
#include <stdint.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static size_t nl_qty_fn_10(size_t nl_local_4)
{
    size_t nl_if_5;
    _Bool nl_condition_5 = nl_local_4 < ((size_t)UINTMAX_C(256));
    if (nl_condition_5) {
        const size_t nl_product_left = nl_local_4;
        const size_t nl_product_right = ((size_t)UINTMAX_C(128));
        nl_if_5 = nl_product_left * nl_product_right;
    } else {
        nl_if_5 = ((size_t)UINTMAX_C(0));
    }
    return nl_if_5;
}

static uint8_t nl_qty_fn_12(size_t nl_local_6)
{
    return nl_local_6 < ((size_t)UINTMAX_C(16384)) ? ((uint8_t)UINT8_C(6)) : ((uint8_t)UINT8_C(31));
}

static uint8_t nl_qty_fn_13(uint8_t *nl_local_9, uint8_t nl_local_10)
{
    const uint8_t nl_previous = *nl_local_9;
    *nl_local_9 = nl_local_10;
    return nl_previous;
}

_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1, "NewLang C17 requires exact 8-bit uint8_t");

static void nl_qty_fn_11(void)
{
    struct { uint8_t f0; uint8_t f1; } nl_local_1 = { .f1 = ((uint8_t)UINT8_C(11)), .f0 = ((uint8_t)UINT8_C(91)), };
    const uint8_t *original_target = &nl_local_1.f1;
    const uint8_t *original_sibling = &nl_local_1.f0;
    const uint8_t initial = *original_target;
    const uint8_t flags = *original_sibling;
    size_t nl_local_2 = ((size_t)UINTMAX_C(5));
    (void)nl_local_2;
    size_t nl_if_15;
    _Bool nl_condition_15 = nl_local_2 < ((size_t)UINTMAX_C(7));
    if (nl_condition_15) {
        nl_if_15 = ((size_t)UINTMAX_C(255));
    } else {
        nl_if_15 = ((size_t)UINTMAX_C(256));
    }
    size_t nl_local_3 = nl_if_15;
    (void)nl_local_3;
    size_t nl_local_5 = nl_qty_fn_10(nl_local_3);
    (void)nl_local_5;
    uint8_t nl_local_7 = nl_qty_fn_12(nl_local_5);
    (void)nl_local_7;
    uint8_t nl_local_11;
    {
        uint8_t *const nl_local_8 = &nl_local_1.f1;
        assert(nl_local_8 == original_target && nl_local_8 != original_sibling);
        nl_local_11 = nl_qty_fn_13(nl_local_8, nl_local_7);
    }
    const uint8_t nl_local_12 = nl_local_1.f0;
    (void)nl_local_12;
    const uint8_t nl_local_13 = nl_local_1.f1;
    (void)nl_local_13;
    const uint8_t nl_local_14 = nl_local_11;
    assert(nl_local_11 == initial && nl_local_14 == initial);
    assert(nl_local_7 == *original_target);
    assert(nl_local_13 == nl_local_7);
    assert(nl_local_12 == flags && *original_sibling == flags);
    printf("%zu,%u,%u,%u,%u\n", nl_local_5, (unsigned)nl_local_7, (unsigned)nl_local_11, (unsigned)nl_local_13, (unsigned)nl_local_12);
    (void)nl_local_14;
    return;
}

int main(void)
{
    nl_qty_fn_11();
    return 0;
}
