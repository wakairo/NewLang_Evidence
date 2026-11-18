/* North Star V0/V1/AVS Checked-C reference output. */
#include <stdint.h>

#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
#include <stddef.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

typedef struct { uint8_t f0; uint8_t f1; } nl_type_10;

#ifdef NEWLANG_CURRENT_LOOP_OBSERVER
#include NEWLANG_CURRENT_LOOP_OBSERVER
#endif
#ifndef NL_CURRENT_PHASE
#define NL_CURRENT_PHASE(...) ((void)0)
#endif
#ifndef NL_CURRENT_LOCAL
#define NL_CURRENT_LOCAL(...) ((void)0)
#endif
#ifndef NL_CURRENT_RESULT
#define NL_CURRENT_RESULT(...) ((void)0)
#endif

#ifndef NL_CURRENT_CALL_RESULT
#define NL_CURRENT_CALL_RESULT(...) ((void)0)
#endif
#ifndef NL_CURRENT_CALLER_COPY
#define NL_CURRENT_CALLER_COPY(...) ((void)0)
#endif

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

static void nl_fn_11(void);
static uint8_t nl_fn_10(uint8_t nl_local_3);
static uint8_t nl_fn_12(void);

static void nl_fn_11(void)
{
    const uint8_t nl_call_2 = nl_fn_12();
    NL_CURRENT_CALL_RESULT(12, 2, nl_call_2);
    (void)nl_call_2;
    const uint8_t nl_local_15 = nl_call_2;
    NL_CURRENT_CALLER_COPY(15, nl_local_15);
    (void)nl_local_15;
    const uint8_t nl_local_16 = nl_local_15;
    NL_CURRENT_CALLER_COPY(16, nl_local_16);
    (void)nl_local_16;
    (void)nl_local_16;
    (void)0;
}

static uint8_t nl_fn_10(uint8_t nl_local_3)
{
    (void)nl_local_3;
    nl_type_10 nl_local_4 = { .f0 = 17, .f1 = 193, };
    (void)nl_local_4;
    NL_LOOP_BIND(&nl_local_4.f0, &nl_local_4.f1);
    uint8_t nl_local_5;
    size_t nl_loop_carry_10 = (size_t)UINTMAX_C(0);
    for (;;) {
        const size_t nl_loop_phase_10 = nl_loop_carry_10;
        NL_CURRENT_PHASE(nl_loop_phase_10, &nl_local_4.f0, &nl_local_4.f1);
        if (nl_loop_phase_10 < (size_t)UINTMAX_C(2)) {
            NL_LOOP_BEFORE(&nl_local_4.f0, &nl_local_4.f1, 0);
            uint8_t nl_loan_result_1;
            {
                uint8_t *const nl_local_6 = &nl_local_4.f0;
                (void)nl_local_6;
                const uint8_t nl_replace_old_4 = *nl_local_6;
                *nl_local_6 = nl_local_3;
                nl_loan_result_1 = nl_replace_old_4;
            }
            (void)nl_loan_result_1;
            const uint8_t nl_local_7 = nl_loan_result_1;
            (void)nl_local_7;
            NL_LOOP_AFTER(&nl_local_4.f0, &nl_local_4.f1, 0, nl_local_7);
            NL_CURRENT_LOCAL(7, nl_local_7);
            nl_loop_carry_10 = nl_loop_phase_10 + (size_t)UINTMAX_C(1);
            continue;
        }
        NL_LOOP_BEFORE(&nl_local_4.f0, &nl_local_4.f1, 0);
        uint8_t nl_loan_result_1;
        {
            uint8_t *const nl_local_6 = &nl_local_4.f0;
            (void)nl_local_6;
            const uint8_t nl_replace_old_4 = *nl_local_6;
            *nl_local_6 = 211;
            nl_loan_result_1 = nl_replace_old_4;
        }
        (void)nl_loan_result_1;
        const uint8_t nl_local_7 = nl_loan_result_1;
        (void)nl_local_7;
        NL_LOOP_AFTER(&nl_local_4.f0, &nl_local_4.f1, 0, nl_local_7);
        nl_local_5 = nl_local_7;
        NL_CURRENT_RESULT(nl_local_5);
        break;
    }
    (void)nl_local_5;
    const uint8_t nl_local_6 = nl_local_4.f0;
    (void)nl_local_6;
    NL_LOOP_READ(&nl_local_4.f0, nl_local_6);
    const uint8_t nl_local_7 = nl_local_4.f1;
    (void)nl_local_7;
    NL_LOOP_READ(&nl_local_4.f1, nl_local_7);
    (void)nl_local_6;
    (void)nl_local_7;
    const uint8_t nl_local_8 = nl_local_5;
    (void)nl_local_8;
    return nl_local_8;
}

static uint8_t nl_fn_12(void)
{
    nl_type_10 nl_local_1 = { .f0 = 41, .f1 = 167, };
    (void)nl_local_1;
    NL_LOOP_BIND(&nl_local_1.f0, &nl_local_1.f1);
    const uint8_t nl_local_2 = nl_local_1.f1;
    (void)nl_local_2;
    NL_LOOP_READ(&nl_local_1.f1, nl_local_2);
    const uint8_t nl_call_12 = nl_fn_10(nl_local_2);
    NL_CURRENT_CALL_RESULT(10, 12, nl_call_12);
    (void)nl_call_12;
    const uint8_t nl_local_9 = nl_call_12;
    NL_CURRENT_CALLER_COPY(9, nl_local_9);
    (void)nl_local_9;
    uint8_t nl_loan_result_1;
    {
        uint8_t *const nl_local_10 = &nl_local_1.f0;
        (void)nl_local_10;
        const uint8_t nl_replace_old_18 = *nl_local_10;
        *nl_local_10 = nl_local_9;
        nl_loan_result_1 = nl_replace_old_18;
    }
    (void)nl_loan_result_1;
    const uint8_t nl_local_11 = nl_loan_result_1;
    (void)nl_local_11;
    NL_CURRENT_LOCAL(11, nl_local_11);
    const uint8_t nl_local_12 = nl_local_1.f0;
    (void)nl_local_12;
    NL_LOOP_READ(&nl_local_1.f0, nl_local_12);
    const uint8_t nl_local_13 = nl_local_1.f1;
    (void)nl_local_13;
    NL_LOOP_READ(&nl_local_1.f1, nl_local_13);
    (void)nl_local_11;
    (void)nl_local_12;
    (void)nl_local_13;
    const uint8_t nl_local_14 = nl_local_9;
    NL_CURRENT_CALLER_COPY(14, nl_local_14);
    (void)nl_local_14;
    return nl_local_14;
}

int main(void)
{
    nl_fn_11();
    return 0;
}
