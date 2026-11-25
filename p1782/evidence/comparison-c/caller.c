#include "exchange.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static size_t bounded_bytes(size_t blocks)
{
    return blocks < 1024 ? blocks * 64 : 0;
}

static uint8_t negotiated_mode(size_t bytes)
{
    return bytes < 4096 ? 35 : 93;
}

static void pair(size_t blocks, bool mirror)
{
    ReceiveDescriptor active = { .class_tag = 119, .coalescing = 22 };
    ReceiveDescriptor standby = { .class_tag = 147, .coalescing = 81 };
    uint8_t *const active_original = &active.coalescing;
    uint8_t *const standby_original = &standby.coalescing;
    assert(&active != &standby && active_original != standby_original);
    const size_t bytes = bounded_bytes(blocks);
    const uint8_t selected = negotiated_mode(bytes);
    uint8_t old_active, old_standby;
    {
        uint8_t *const scoped = &active.coalescing;
        assert(scoped == active_original && scoped != &active.class_tag);
        old_active = exchange(scoped, selected);
    }
    const uint8_t observed = mirror ? active.coalescing : 11;
    assert(standby.coalescing == 81 && standby.class_tag == 147);
    {
        uint8_t *const scoped = &standby.coalescing;
        assert(scoped == standby_original && scoped != &standby.class_tag);
        old_standby = exchange(scoped, observed);
    }
    assert(old_active == 22 && old_standby == 81);
    assert(active.coalescing == selected && standby.coalescing == observed);
    assert(active.class_tag == 119 && standby.class_tag == 147);
    printf("%zu,%u,%u,%u,%u,%u,%u,%u,%u\n", bytes, (unsigned)selected, (unsigned)observed,
           (unsigned)old_active, (unsigned)*active_original, (unsigned)active.class_tag,
           (unsigned)old_standby, (unsigned)*standby_original, (unsigned)standby.class_tag);
}

static void single_or_same(bool repeat)
{
    ReceiveDescriptor active = { .class_tag = 119, .coalescing = 22 };
    uint8_t *const original = &active.coalescing;
    const size_t bytes = bounded_bytes(63);
    const uint8_t selected = negotiated_mode(bytes);
    uint8_t first;
    {
        uint8_t *const scoped = &active.coalescing;
        assert(scoped == original && scoped != &active.class_tag);
        first = exchange(scoped, selected);
    }
    assert(first == 22 && *original == selected && active.class_tag == 119);
    if (repeat) {
        uint8_t second;
        {
            uint8_t *const scoped = &active.coalescing;
            assert(scoped == original && scoped != &active.class_tag);
            second = exchange(scoped, 11);
        }
        assert(second == selected && *original == 11 && active.class_tag == 119);
        printf("%zu,%u,%u,%u,%u,%u\n", bytes, (unsigned)selected,
               (unsigned)first, (unsigned)second, (unsigned)*original, (unsigned)active.class_tag);
    } else {
        printf("%zu,%u,%u,%u,%u\n", bytes, (unsigned)selected, (unsigned)first,
               (unsigned)*original, (unsigned)active.class_tag);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 2;
    if (!strcmp(argv[1], "mirror-low"))
        pair(63, true);
    else if (!strcmp(argv[1], "mirror-high"))
        pair(64, true);
    else if (!strcmp(argv[1], "literal-independent"))
        pair(63, false);
    else if (!strcmp(argv[1], "same-original"))
        single_or_same(true);
    else if (!strcmp(argv[1], "single-original"))
        single_or_same(false);
    else
        return 2;
    return 0;
}
