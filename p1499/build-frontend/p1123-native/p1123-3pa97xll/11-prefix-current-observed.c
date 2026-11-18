/* North Star V0/V1/AVS Checked-C reference output. */
#include <stdint.h>

#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
#include <stddef.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

typedef struct { uint8_t f0; uint8_t f1; } nl_type_10;

#ifdef NEWLANG_LOOP_OBSERVER
#include NEWLANG_LOOP_OBSERVER
#endif
#ifndef NL_LOOP_BIND
#define NL_LOOP_BIND(...) ((void)0)
#endif
#ifndef NL_LOOP_READ
#define NL_LOOP_READ(...) ((void)0)
#endif
#ifndef NL_LOOP_BEFORE
#define NL_LOOP_BEFORE(...) ((void)0)
#endif
#ifndef NL_LOOP_AFTER
#define NL_LOOP_AFTER(...) ((void)0)
#endif

#ifndef NL_LOOP_PHASE
#define NL_LOOP_PHASE(...) ((void)0)
#endif
#ifndef NL_LOOP_CONTINUE
#define NL_LOOP_CONTINUE(...) ((void)0)
#endif

static void nl_fn_11(void);
static uint8_t nl_fn_10(uint8_t *nl_local_6, uint8_t nl_local_7);

static void nl_fn_11(void)
{
    nl_type_10 nl_local_1 = { .f0 = 58, .f1 = 193, };
    (void)nl_local_1;
    NL_LOOP_BIND(&nl_local_1.f0, &nl_local_1.f1);
    const nl_type_10 nl_local_2 = { .f0 = 91, .f1 = 217, };
    (void)nl_local_2;
    NL_LOOP_BIND(&nl_local_2.f0, &nl_local_2.f1);
    uint8_t nl_loan_result_1;
    {
        uint8_t *const nl_local_3 = &nl_local_1.f1;
        (void)nl_local_3;
        const uint8_t nl_replace_old_18 = *nl_local_3;
        *nl_local_3 = 163;
        p1123_outer_store(nl_local_3);
        nl_loan_result_1 = nl_replace_old_18;
    }
    (void)nl_loan_result_1;
    const uint8_t nl_local_4 = nl_loan_result_1;
    (void)nl_local_4;
    uint8_t nl_local_10;
    size_t nl_loop_carry_24 = (size_t)UINTMAX_C(6);
    for (;;) {
        const size_t nl_loop_phase_24 = nl_loop_carry_24;
        NL_LOOP_PHASE(nl_loop_phase_24, &nl_local_1.f0, &nl_local_1.f1);
        if (nl_loop_phase_24 < (size_t)UINTMAX_C(7)) {
            nl_loop_carry_24 = (size_t)UINTMAX_C(7);
            NL_LOOP_CONTINUE(nl_loop_phase_24, nl_loop_carry_24, &nl_local_1.f0, &nl_local_1.f1);
            continue;
        }
        NL_LOOP_BEFORE(&nl_local_1.f0, &nl_local_1.f1, 1);
        nl_local_10 = nl_fn_10(&nl_local_1.f1, 224);
        NL_LOOP_AFTER(&nl_local_1.f0, &nl_local_1.f1, 1, nl_local_10);
        break;
    }
    (void)nl_local_10;
    uint8_t nl_loan_result_3;
    {
        uint8_t *const nl_local_11 = &nl_local_1.f0;
        (void)nl_local_11;
        const uint8_t nl_replace_old_29 = *nl_local_11;
        *nl_local_11 = nl_local_10;
        p1123_outer_store(nl_local_11);
        nl_loan_result_3 = nl_replace_old_29;
    }
    (void)nl_loan_result_3;
    const uint8_t nl_local_12 = nl_loan_result_3;
    (void)nl_local_12;
    const uint8_t nl_local_13 = nl_local_1.f0;
    (void)nl_local_13;
    NL_LOOP_READ(&nl_local_1.f0, nl_local_13);
    const uint8_t nl_local_14 = nl_local_1.f1;
    (void)nl_local_14;
    NL_LOOP_READ(&nl_local_1.f1, nl_local_14);
    const uint8_t nl_local_15 = nl_local_2.f0;
    (void)nl_local_15;
    NL_LOOP_READ(&nl_local_2.f0, nl_local_15);
    const uint8_t nl_local_16 = nl_local_2.f1;
    (void)nl_local_16;
    NL_LOOP_READ(&nl_local_2.f1, nl_local_16);
    (void)0;
    return;
}

static uint8_t nl_fn_10(uint8_t *nl_local_6, uint8_t nl_local_7)
{
    p1123_helper(nl_local_6, nl_local_7);
    (void)nl_local_7;
    (void)nl_local_6;
    const uint8_t nl_replace_old_2 = *nl_local_6;
    *nl_local_6 = nl_local_7;
    p1123_changed(nl_local_6);
    const uint8_t nl_local_8 = nl_replace_old_2;
    (void)nl_local_8;
    return nl_local_8;
}

int main(void)
{
    nl_fn_11();
    return 0;
}
