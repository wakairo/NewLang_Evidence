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
static uint8_t nl_fn_10(size_t nl_local_8);

static void nl_fn_11(void)
{
    const size_t nl_local_1 = ((size_t)UINTMAX_C(1));
    (void)nl_local_1;
    const size_t nl_local_2 = nl_local_1;
    (void)nl_local_2;
    const size_t nl_local_3 = nl_local_2;
    (void)nl_local_3;
    nl_type_10 nl_local_4 = { .f0 = 166, .f1 = 28, };
    (void)nl_local_4;
    NL_LOOP_BIND(&nl_local_4.f0, &nl_local_4.f1);
    size_t nl_local_5;
    size_t nl_loop_carry_19 = nl_local_3;
    for (;;) {
        const size_t nl_loop_phase_19 = nl_loop_carry_19;
        NL_CURRENT_PHASE(nl_loop_phase_19, &nl_local_4.f0, &nl_local_4.f1);
        if (nl_loop_phase_19 < (size_t)UINTMAX_C(8)) {
            const size_t nl_local_6 = nl_loop_phase_19;
            (void)nl_local_6;
            NL_CURRENT_LOCAL(6, nl_local_6);
            const size_t nl_local_7 = nl_local_6;
            (void)nl_local_7;
            NL_CURRENT_LOCAL(7, nl_local_7);
            const uint8_t nl_local_13 = nl_fn_10(nl_local_7);
            (void)nl_local_13;
            NL_CURRENT_LOCAL(13, nl_local_13);
            uint8_t nl_loan_result_1;
            {
                uint8_t *const nl_local_14 = &nl_local_4.f0;
                (void)nl_local_14;
                const uint8_t nl_replace_old_14 = *nl_local_14;
                *nl_local_14 = nl_local_13;
                nl_loan_result_1 = nl_replace_old_14;
            }
            (void)nl_loan_result_1;
            const uint8_t nl_local_15 = nl_loan_result_1;
            (void)nl_local_15;
            NL_CURRENT_LOCAL(15, nl_local_15);
            const uint8_t nl_local_16 = nl_local_15;
            (void)nl_local_16;
            NL_CURRENT_LOCAL(16, nl_local_16);
            (void)nl_local_16;
            const uint8_t nl_local_17 = nl_local_4.f0;
            (void)nl_local_17;
            NL_CURRENT_LOCAL(17, nl_local_17);
            const uint8_t nl_local_18 = nl_local_4.f1;
            (void)nl_local_18;
            NL_CURRENT_LOCAL(18, nl_local_18);
            (void)nl_local_17;
            (void)nl_local_18;
            nl_loop_carry_19 = nl_loop_phase_19 + (size_t)UINTMAX_C(2);
            continue;
        }
        nl_local_5 = nl_loop_phase_19;
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
    const size_t nl_local_8 = nl_local_5;
    (void)nl_local_8;
    (void)0;
}

static uint8_t nl_fn_10(size_t nl_local_8)
{
    helper_input(nl_local_8);
    (void)nl_local_8;
    const size_t nl_local_9 = nl_local_8;
    (void)nl_local_9;
    const size_t nl_local_10 = nl_local_9;
    (void)nl_local_10;
    const uint8_t nl_local_11 = ((nl_local_10 == ((size_t)UINTMAX_C(5))) ? 92 : 201);
    (void)nl_local_11;
    const uint8_t nl_local_12 = nl_local_11;
    (void)nl_local_12;
    return helper_return(nl_local_12);
}

int main(void)
{
    nl_fn_11();
    return 0;
}
