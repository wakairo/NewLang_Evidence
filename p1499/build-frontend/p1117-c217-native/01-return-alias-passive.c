/* North Star V0/V1/AVS Checked-C reference output. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
static const size_t p1117_c217_args[] = {400,401,403};
static const unsigned p1117_c217_results[] = {157,232,232};

static size_t p1117_c217_entered, p1117_c217_returned;
static void p1117_c217_finish(void) {
    assert(p1117_c217_entered == sizeof(p1117_c217_args) / sizeof(*p1117_c217_args));
    assert(p1117_c217_returned == p1117_c217_entered);
    puts("P1117-C217 genuine native results PASS");
}
static void p1117_c217_input(size_t value) {
    assert(p1117_c217_entered == p1117_c217_returned);
    assert(p1117_c217_entered < sizeof(p1117_c217_args) / sizeof(*p1117_c217_args));
    assert(value == p1117_c217_args[p1117_c217_entered]);
    if (!p1117_c217_entered) assert(atexit(p1117_c217_finish) == 0);
    ++p1117_c217_entered;
}
static uint8_t p1117_c217_output(uint8_t value) {
    assert(p1117_c217_returned + 1 == p1117_c217_entered);
    assert(value == p1117_c217_results[p1117_c217_returned]);
    ++p1117_c217_returned;
    return value;
}


#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
#include <stddef.h>
_Static_assert(SIZE_MAX == UINTMAX_C(18446744073709551615), "NewLang usize target mismatch");

static void nl_fn_10(void);
static uint8_t nl_fn_11(size_t nl_local_1);

static void nl_fn_10(void)
{
    const uint8_t nl_call_2 = nl_fn_11(((size_t)UINTMAX_C(400)));
    (void)nl_call_2;
    const uint8_t nl_local_6 = nl_call_2;
    (void)nl_local_6;
    const uint8_t nl_call_6 = nl_fn_11(((size_t)UINTMAX_C(401)));
    (void)nl_call_6;
    const uint8_t nl_local_12 = nl_call_6;
    (void)nl_local_12;
    const uint8_t nl_call_10 = nl_fn_11(((size_t)UINTMAX_C(403)));
    (void)nl_call_10;
    const uint8_t nl_local_18 = nl_call_10;
    (void)nl_local_18;
    (void)0;
    return;
}

static uint8_t nl_fn_11(size_t nl_local_1)
{
    p1117_c217_input(nl_local_1);
    (void)nl_local_1;
    const size_t nl_less_left_2 = nl_local_1;
    const size_t nl_less_right_2 = ((size_t)UINTMAX_C(401));
    const _Bool nl_local_2 = (nl_less_left_2 < nl_less_right_2);
    (void)nl_local_2;
    const uint8_t nl_local_3 = (nl_local_2 ? 157 : 232);
    (void)nl_local_3;
    const uint8_t nl_local_4 = nl_local_3;
    (void)nl_local_4;
    const uint8_t nl_local_5 = nl_local_4;
    (void)nl_local_5;
    return p1117_c217_output(nl_local_5);
}

int main(void)
{
    nl_fn_10();
    return 0;
}
