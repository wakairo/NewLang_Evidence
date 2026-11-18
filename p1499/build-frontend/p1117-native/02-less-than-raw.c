/* North Star V0/V1/AVS Checked-C reference output. */
#include <stdint.h>

#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
#include <stddef.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static void nl_fn_11(void);
static uint8_t nl_fn_10(size_t nl_local_1);

static void nl_fn_11(void)
{
    const uint8_t nl_call_2 = nl_fn_10(((size_t)UINTMAX_C(23)));
    (void)nl_call_2;
    const uint8_t nl_local_3 = nl_call_2;
    (void)nl_local_3;
    const uint8_t nl_call_6 = nl_fn_10(((size_t)UINTMAX_C(24)));
    (void)nl_call_6;
    const uint8_t nl_local_6 = nl_call_6;
    (void)nl_local_6;
    const uint8_t nl_call_10 = nl_fn_10(((size_t)UINTMAX_C(26)));
    (void)nl_call_10;
    const uint8_t nl_local_9 = nl_call_10;
    (void)nl_local_9;
    (void)0;
    return;
}

static uint8_t nl_fn_10(size_t nl_local_1)
{
    (void)nl_local_1;
    const size_t nl_less_left_2 = nl_local_1;
    const size_t nl_less_right_2 = ((size_t)UINTMAX_C(24));
    const uint8_t nl_local_2 = ((nl_less_left_2 < nl_less_right_2) ? 113 : 247);
    (void)nl_local_2;
    return nl_local_2;
}

int main(void)
{
    nl_fn_11();
    return 0;
}
