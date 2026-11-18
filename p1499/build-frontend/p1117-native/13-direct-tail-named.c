/* North Star V0/V1/AVS Checked-C reference output. */
#include <stdint.h>

#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
#include <stddef.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static void nl_fn_10(void);
static uint8_t nl_fn_11(size_t nl_local_1);

static void nl_fn_10(void)
{
    const uint8_t nl_call_2 = nl_fn_11(((size_t)UINTMAX_C(1)));
    (void)nl_call_2;
    const uint8_t nl_local_2 = nl_call_2;
    (void)nl_local_2;
    const uint8_t nl_call_6 = nl_fn_11(((size_t)UINTMAX_C(1025)));
    (void)nl_call_6;
    const uint8_t nl_local_4 = nl_call_6;
    (void)nl_local_4;
    const uint8_t nl_call_10 = nl_fn_11(((size_t)UINTMAX_C(1026)));
    (void)nl_call_10;
    const uint8_t nl_local_6 = nl_call_10;
    (void)nl_local_6;
    (void)0;
    return;
}

static uint8_t nl_fn_11(size_t nl_local_1)
{
    (void)nl_local_1;
    return ((nl_local_1 == ((size_t)UINTMAX_C(1025))) ? 136 : 217);
}

int main(void)
{
    nl_fn_10();
    return 0;
}
