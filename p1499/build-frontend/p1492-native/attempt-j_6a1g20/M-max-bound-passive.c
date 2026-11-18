#define main nl_p1492_original_main
#include "/workspace/NewLang_Compiler/build-frontend/p1492-native/attempt-j_6a1g20/M-max-bound.c"
#undef main
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    static const size_t expected[] = {((size_t)UINTMAX_C(1)), ((size_t)UINTMAX_C(18446744073709551615)), ((size_t)UINTMAX_C(18446744073709551615))};
    if (argc != (int)(sizeof(expected)/sizeof(*expected)) + 1) return 1;
    for (int i = 1; i < argc; ++i) {
        size_t input = (size_t)strtoumax(argv[i], NULL, 10);
        size_t actual = nl_qty_fn_11(input);
        printf("input=%zu result=%zu\n", input, actual);
        if (actual != expected[i-1]) return 2;
    }
    size_t caller = nl_qty_fn_10();
    printf("caller=%zu\n", caller);
    return caller == ((size_t)UINTMAX_C(18446744073709551615)) ? 0 : 3;
}
