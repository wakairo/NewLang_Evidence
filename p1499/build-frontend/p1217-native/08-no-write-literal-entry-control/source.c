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

#ifdef NEWLANG_SCALAR_LOOP_OBSERVER
#include NEWLANG_SCALAR_LOOP_OBSERVER
#endif
#ifndef NL_SCALAR_PHASE
#define NL_SCALAR_PHASE(...) ((void)0)
#endif
#ifndef NL_SCALAR_RESULT
#define NL_SCALAR_RESULT(...) ((void)0)
#endif

static void nl_fn_10(void);

static void nl_fn_10(void)
{
    const nl_type_10 nl_local_1 = { .f0 = 38, .f1 = 227, };
    (void)nl_local_1;
    NL_LOOP_BIND(&nl_local_1.f0, &nl_local_1.f1);
    const size_t nl_local_2 = ((size_t)UINTMAX_C(0));
    (void)nl_local_2;
    const size_t nl_local_3 = nl_local_2;
    (void)nl_local_3;
    size_t nl_local_4;
    size_t nl_loop_carry_16 = (size_t)UINTMAX_C(0);
    for (;;) {
        const size_t nl_loop_phase_16 = nl_loop_carry_16;
        NL_SCALAR_PHASE(nl_loop_phase_16);
        if (nl_loop_phase_16 < (size_t)UINTMAX_C(3)) {
            nl_loop_carry_16 = nl_loop_phase_16 + (size_t)UINTMAX_C(1);
            continue;
        }
        nl_local_4 = nl_loop_phase_16;
        NL_SCALAR_RESULT(nl_local_4);
        break;
    }
    (void)nl_local_4;
    const uint8_t nl_local_5 = nl_local_1.f0;
    (void)nl_local_5;
    NL_LOOP_READ(&nl_local_1.f0, nl_local_5);
    const uint8_t nl_local_6 = nl_local_1.f1;
    (void)nl_local_6;
    NL_LOOP_READ(&nl_local_1.f1, nl_local_6);
    const size_t nl_local_7 = nl_local_4;
    (void)nl_local_7;
    (void)0;
}

int main(void)
{
    nl_fn_10();
    return 0;
}
