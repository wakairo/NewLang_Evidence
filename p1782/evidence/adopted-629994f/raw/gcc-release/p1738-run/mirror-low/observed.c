#include <assert.h>
#include <stdio.h>
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
    struct { uint8_t f0; uint8_t f1; } nl_local_1 = { .f1 = ((uint8_t)UINT8_C(22)), .f0 = ((uint8_t)UINT8_C(119)), };
    struct { uint8_t f0; uint8_t f1; } nl_local_2 = { .f1 = ((uint8_t)UINT8_C(81)), .f0 = ((uint8_t)UINT8_C(147)), };
    const uint8_t *const first_original = &nl_local_1.f1;
    const uint8_t *const second_original = &nl_local_2.f1;
    const uint8_t initial_first = *first_original, initial_second = *second_original;
    const uint8_t saved_first_tag = nl_local_1.f0, saved_second_tag = nl_local_2.f0;
    assert(first_original != second_original);
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
        assert(nl_local_9 == first_original && nl_local_9 != &nl_local_1.f0);
        nl_local_13 = nl_qty_fn_11(nl_local_9, nl_local_8);
    }
    const uint8_t nl_local_14 = nl_local_1.f1;
    (void)nl_local_14;
    uint8_t nl_local_19;
    {
        uint8_t *const nl_local_15 = &nl_local_2.f1;
        assert(nl_local_15 == second_original && nl_local_15 != &nl_local_2.f0);
        assert(*first_original == nl_local_8 && *second_original == initial_second && nl_local_2.f0 == saved_second_tag);
        assert(nl_local_14 == *first_original);
        nl_local_19 = nl_qty_fn_11(nl_local_15, nl_local_14);
    }
    const uint8_t nl_local_20 = nl_local_1.f1;
    (void)nl_local_20;
    const uint8_t nl_local_21 = nl_local_1.f0;
    (void)nl_local_21;
    const uint8_t nl_local_22 = nl_local_2.f1;
    (void)nl_local_22;
    const uint8_t nl_local_23 = nl_local_2.f0;
    (void)nl_local_23;
    const uint8_t nl_local_24 = nl_local_13;
    (void)nl_local_24;
    const uint8_t nl_local_25 = nl_local_19;
    assert(nl_local_24 == initial_first && nl_local_25 == initial_second);
    assert(nl_local_20 == nl_local_8 && *first_original == nl_local_20 && nl_local_22 == nl_local_14 && *second_original == nl_local_22);
    assert(nl_local_21 == saved_first_tag && nl_local_23 == saved_second_tag);
    printf("%zu,%u,%u,%u,%u,%u,%u,%u,%u\n", nl_local_6, (unsigned)nl_local_8, (unsigned)nl_local_14, (unsigned)nl_local_24, (unsigned)nl_local_20, (unsigned)nl_local_21, (unsigned)nl_local_25, (unsigned)nl_local_22, (unsigned)nl_local_23);
    (void)nl_local_25;
    return;
}

int main(void)
{
    nl_qty_fn_12();
    return 0;
}
