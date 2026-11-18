#define main nl_p1499_original_main
#include "/workspace/p1499-evidence/native-gcc/attempt-nijuv5s3/B-repeat-advance.c"
#undef main
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    static const size_t expected[] = {((size_t)UINTMAX_C(2)), ((size_t)UINTMAX_C(16)), ((size_t)UINTMAX_C(16)), ((size_t)UINTMAX_C(16)), ((size_t)UINTMAX_C(18446744073709551615))};
    if (argc != (int)(sizeof(expected)/sizeof(*expected)) + 1) return 1;
    for (int i = 1; i < argc; ++i) {
        size_t input = (size_t)strtoumax(argv[i], NULL, 10);
        size_t first = nl_qty_fn_10(input);
        size_t actual = nl_qty_fn_10(first);
        printf("input=%zu result=%zu\n", input, actual);
        if (actual != expected[i-1]) return 2;
    }
    size_t caller = nl_qty_fn_11();
    printf("caller=%zu\n", caller);
    return caller == ((size_t)UINTMAX_C(13)) ? 0 : 3;
}
