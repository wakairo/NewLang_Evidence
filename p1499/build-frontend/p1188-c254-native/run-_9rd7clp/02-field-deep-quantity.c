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

#ifdef NEWLANG_SCALAR_LOOP_OBSERVER
#include NEWLANG_SCALAR_LOOP_OBSERVER
#endif
#ifndef NL_SCALAR_PHASE
#define NL_SCALAR_PHASE(...) ((void)0)
#endif
#ifndef NL_SCALAR_RESULT
#define NL_SCALAR_RESULT(...) ((void)0)
#endif

static void nl_fn_11(void);
static uint8_t nl_fn_10(size_t nl_local_13);

static void nl_fn_11(void)
{
    nl_type_10 nl_local_1 = { .f1 = 11, .f0 = 227, };
    (void)nl_local_1;
    NL_LOOP_BIND(&nl_local_1.f0, &nl_local_1.f1);
    const uint8_t nl_local_2 = nl_local_1.f1;
    (void)nl_local_2;
    NL_LOOP_READ(&nl_local_1.f1, nl_local_2);
    const uint8_t nl_local_3 = nl_local_2;
    (void)nl_local_3;
    const uint8_t nl_local_4 = nl_local_3;
    (void)nl_local_4;
    const uint8_t nl_local_5 = 11;
    (void)nl_local_5;
    const size_t nl_local_6 = ((size_t)UINTMAX_C(1));
    (void)nl_local_6;
    const size_t nl_local_7 = nl_local_6;
    (void)nl_local_7;
    const size_t nl_local_8 = nl_local_7;
    (void)nl_local_8;
    size_t nl_local_9;
    size_t nl_loop_carry_31 = nl_local_8;
    for (;;) {
        const size_t nl_loop_phase_31 = nl_loop_carry_31;
        NL_CURRENT_PHASE(nl_loop_phase_31, &nl_local_1.f0, &nl_local_1.f1);
        if (nl_loop_phase_31 < (size_t)UINTMAX_C(6)) {
            const uint8_t nl_local_10 = nl_local_4;
            (void)nl_local_10;
            NL_CURRENT_LOCAL(10, nl_local_10);
            (void)nl_local_4;
            const size_t nl_local_11 = nl_loop_phase_31;
            (void)nl_local_11;
            NL_CURRENT_LOCAL(11, nl_local_11);
            const size_t nl_local_12 = nl_local_11;
            (void)nl_local_12;
            NL_CURRENT_LOCAL(12, nl_local_12);
            (void)nl_loop_phase_31;
            const uint8_t nl_local_16 = nl_fn_10(nl_local_12);
            (void)nl_local_16;
            NL_CURRENT_LOCAL(16, nl_local_16);
            uint8_t nl_loan_result_1;
            {
                uint8_t *const nl_local_17 = &nl_local_1.f1;
                (void)nl_local_17;
                const uint8_t nl_replace_old_21 = *nl_local_17;
                *nl_local_17 = nl_local_16;
                nl_loan_result_1 = nl_replace_old_21;
            }
            (void)nl_loan_result_1;
            const uint8_t nl_local_18 = nl_loan_result_1;
            (void)nl_local_18;
            NL_CURRENT_LOCAL(18, nl_local_18);
            const uint8_t nl_local_19 = nl_local_18;
            (void)nl_local_19;
            NL_CURRENT_LOCAL(19, nl_local_19);
            (void)nl_local_19;
            const uint8_t nl_local_20 = nl_local_1.f1;
            (void)nl_local_20;
            NL_CURRENT_LOCAL(20, nl_local_20);
            const uint8_t nl_local_21 = nl_local_1.f0;
            (void)nl_local_21;
            NL_CURRENT_LOCAL(21, nl_local_21);
            (void)nl_local_20;
            (void)nl_local_21;
            const uint8_t nl_local_22 = nl_local_4;
            (void)nl_local_22;
            NL_CURRENT_LOCAL(22, nl_local_22);
            (void)nl_local_4;
            nl_loop_carry_31 = nl_loop_phase_31 + (size_t)UINTMAX_C(2);
            continue;
        }
        nl_local_9 = nl_loop_phase_31;
        NL_CURRENT_RESULT(nl_local_9);
        break;
    }
    (void)nl_local_9;
    const uint8_t nl_local_10 = nl_local_1.f1;
    (void)nl_local_10;
    NL_LOOP_READ(&nl_local_1.f1, nl_local_10);
    const uint8_t nl_local_11 = nl_local_1.f0;
    (void)nl_local_11;
    NL_LOOP_READ(&nl_local_1.f0, nl_local_11);
    const uint8_t nl_local_12 = nl_local_4;
    (void)nl_local_12;
    const size_t nl_local_13 = nl_local_9;
    (void)nl_local_13;
    (void)0;
}

static uint8_t nl_fn_10(size_t nl_local_13)
{
    (void)nl_local_13;
    const size_t nl_local_14 = nl_local_13;
    (void)nl_local_14;
    const size_t nl_local_15 = nl_local_14;
    (void)nl_local_15;
    return ((nl_local_15 == ((size_t)UINTMAX_C(3))) ? 97 : 11);
}

int main(void)
{
    nl_fn_11();
    return 0;
}
