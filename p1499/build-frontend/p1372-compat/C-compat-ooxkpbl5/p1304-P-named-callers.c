/* North Star V0/V1/AVS Checked-C reference output. */
#include <stdint.h>

#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
typedef struct { uint8_t f0; uint8_t f1; } nl_type_10;

static void nl_fn_10(void);
static uint8_t nl_fn_13(uint8_t *nl_local_3, uint8_t nl_local_4);
static uint8_t nl_fn_11(void);
static uint8_t nl_fn_12(uint8_t nl_local_12);

static void nl_fn_10(void)
{
    const uint8_t nl_call_2 = nl_fn_11();
    (void)nl_call_2;
    const uint8_t nl_local_10 = nl_call_2;
    (void)nl_local_10;
    const uint8_t nl_local_11 = nl_local_10;
    (void)nl_local_11;
    const uint8_t nl_call_8 = nl_fn_12(nl_local_11);
    (void)nl_call_8;
    const uint8_t nl_local_22 = nl_call_8;
    (void)nl_local_22;
    const uint8_t nl_local_23 = nl_local_22;
    (void)nl_local_23;
    (void)0;
}

static uint8_t nl_fn_13(uint8_t *nl_local_3, uint8_t nl_local_4)
{
    (void)nl_local_4;
    (void)nl_local_3;
    const uint8_t nl_replace_old_2 = *nl_local_3;
    *nl_local_3 = nl_local_4;
    const uint8_t nl_local_5 = nl_replace_old_2;
    (void)nl_local_5;
    const uint8_t nl_local_6 = nl_local_5;
    (void)nl_local_6;
    return nl_local_6;
}

static uint8_t nl_fn_11(void)
{
    nl_type_10 nl_local_1 = { .f0 = 83, .f1 = 211, };
    (void)nl_local_1;
    uint8_t nl_loan_result_1;
    {
        uint8_t *const nl_local_2 = &nl_local_1.f0;
        (void)nl_local_2;
        const uint8_t nl_call_11 = nl_fn_13(nl_local_2, 167);
        (void)nl_call_11;
        nl_loan_result_1 = nl_call_11;
    }
    (void)nl_loan_result_1;
    const uint8_t nl_local_7 = nl_loan_result_1;
    (void)nl_local_7;
    const uint8_t nl_local_8 = nl_local_1.f0;
    (void)nl_local_8;
    const uint8_t nl_local_9 = nl_local_1.f1;
    (void)nl_local_9;
    return nl_local_7;
}

static uint8_t nl_fn_12(uint8_t nl_local_12)
{
    (void)nl_local_12;
    nl_type_10 nl_local_13 = { .f1 = 109, .f0 = 37, };
    (void)nl_local_13;
    uint8_t nl_loan_result_2;
    {
        uint8_t *const nl_local_14 = &nl_local_13.f1;
        (void)nl_local_14;
        const uint8_t nl_call_11 = nl_fn_13(nl_local_14, nl_local_12);
        (void)nl_call_11;
        nl_loan_result_2 = nl_call_11;
    }
    (void)nl_loan_result_2;
    const uint8_t nl_local_19 = nl_loan_result_2;
    (void)nl_local_19;
    const uint8_t nl_local_20 = nl_local_13.f1;
    (void)nl_local_20;
    const uint8_t nl_local_21 = nl_local_13.f0;
    (void)nl_local_21;
    return nl_local_19;
}

int main(void)
{
    nl_fn_10();
    return 0;
}
