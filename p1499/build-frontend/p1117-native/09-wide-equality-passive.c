/* North Star V0/V1/AVS Checked-C reference output. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
static const size_t p1117_args[] = {1,257,258};
static const unsigned p1117_results[] = {211,134,211};
static size_t p1117_entered, p1117_returned;
static void p1117_finish(void) { assert(p1117_entered == sizeof(p1117_args)/sizeof(*p1117_args)); assert(p1117_returned == p1117_entered); puts("P1117 runtime true/false results PASS"); }
static void p1117_input(size_t arg) { assert(p1117_entered == p1117_returned); assert(p1117_entered < sizeof(p1117_args)/sizeof(*p1117_args)); assert(arg == p1117_args[p1117_entered]); if (!p1117_entered) assert(atexit(p1117_finish)==0); ++p1117_entered; }
static uint8_t p1117_output(uint8_t value) { assert(p1117_returned+1 == p1117_entered); assert(value == p1117_results[p1117_returned]); printf("P1117 actual quantity=%zu result=%u\n",p1117_args[p1117_returned],(unsigned)value); ++p1117_returned; return value; }


#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
#include <stddef.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static void nl_fn_11(void);
static uint8_t nl_fn_10(size_t nl_local_1);

static void nl_fn_11(void)
{
    const uint8_t nl_call_2 = nl_fn_10(((size_t)UINTMAX_C(1)));
    (void)nl_call_2;
    const uint8_t nl_local_4 = nl_call_2;
    (void)nl_local_4;
    const uint8_t nl_call_6 = nl_fn_10(((size_t)UINTMAX_C(257)));
    (void)nl_call_6;
    const uint8_t nl_local_8 = nl_call_6;
    (void)nl_local_8;
    const uint8_t nl_call_10 = nl_fn_10(((size_t)UINTMAX_C(258)));
    (void)nl_call_10;
    const uint8_t nl_local_12 = nl_call_10;
    (void)nl_local_12;
    (void)0;
    return;
}

static uint8_t nl_fn_10(size_t nl_local_1)
{
    p1117_input(nl_local_1);
    (void)nl_local_1;
    const size_t nl_local_2 = nl_local_1;
    (void)nl_local_2;
    const uint8_t nl_local_3 = ((nl_local_2 == ((size_t)UINTMAX_C(257))) ? 134 : 211);
    (void)nl_local_3;
    return p1117_output(nl_local_3);
}

int main(void)
{
    nl_fn_11();
    return 0;
}
