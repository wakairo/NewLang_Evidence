#include "exchange.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    uint8_t route_tag;
    uint8_t mode;
} ReceiveSetting;

typedef enum { DISPLACED, LITERAL, CURRENT, SAME, SINGLE } Flow;

static size_t byte_budget(size_t blocks)
{
    return blocks < 1024 ? blocks * 64 : 0;
}

static uint8_t negotiate(size_t bytes)
{
    return bytes < 4096 ? UINT8_C(35) : UINT8_C(93);
}

static void run(size_t rank, uint8_t active_initial, uint8_t standby_initial,
                Flow flow)
{
    ReceiveSetting active = {.route_tag = UINT8_C(117), .mode = active_initial};
    ReceiveSetting standby = {.route_tag = UINT8_C(149), .mode = standby_initial};
    uint8_t *const active_slot = &active.mode;
    uint8_t *const standby_slot = &standby.mode;
    const uint8_t *const active_sibling = &active.route_tag;
    const uint8_t *const standby_sibling = &standby.route_tag;
    const size_t bytes = byte_budget(rank < 8 ? 63 : 64);
    const uint8_t selected = negotiate(bytes);
    const uint8_t first = install_mode(active_slot, selected);
    assert(first == active_initial && *active_slot == selected);
    assert(active_slot == &active.mode && *active_sibling == UINT8_C(117));
    if (flow == SINGLE) {
        printf("%zu,%u,%u,%u,%u\n", bytes, (unsigned)selected, (unsigned)first,
               (unsigned)active.mode, (unsigned)active.route_tag);
        return;
    }

    if (flow == SAME) {
        const uint8_t intermediate = active.mode;
        const uint8_t second = install_mode(active_slot, UINT8_C(19));
        assert(intermediate == selected && second == selected);
        assert(active_slot == &active.mode && *active_sibling == UINT8_C(117));
        printf("%zu,%u,%u,%u,%u,%u,%u\n", bytes, (unsigned)selected, (unsigned)first,
               (unsigned)intermediate, (unsigned)second, (unsigned)active.mode,
               (unsigned)active.route_tag);
        return;
    }

    const uint8_t handoff = flow == DISPLACED ? first :
                            flow == CURRENT ? active.mode : UINT8_C(19);
    assert(active_slot != standby_slot && active_slot != active_sibling &&
           active_slot != standby_sibling && standby_slot != active_sibling &&
           standby_slot != standby_sibling);
    assert(*standby_slot == standby_initial && *standby_sibling == UINT8_C(149));
    const uint8_t second = install_mode(standby_slot, handoff);
    assert(standby_slot == &standby.mode && second == standby_initial);
    assert(*active_slot == selected && *standby_slot == handoff);
    assert(*active_sibling == UINT8_C(117) && *standby_sibling == UINT8_C(149));
    printf("%zu,%u,%u,%u,%u,%u,%u,%u,%u\n", bytes, (unsigned)selected,
           (unsigned)handoff, (unsigned)first, (unsigned)active.mode,
           (unsigned)active.route_tag, (unsigned)second, (unsigned)standby.mode,
           (unsigned)standby.route_tag);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 2;

    const char *name = argv[1];
    if (!strcmp(name, "fallback-high"))
        run(14, UINT8_C(57), UINT8_C(102), DISPLACED);
    else if (!strcmp(name, "fallback-low") || !strcmp(name, "fallback-tail"))
        run(3, UINT8_C(41), UINT8_C(101), DISPLACED);
    else if (!strcmp(name, "literal-standby"))
        run(3, UINT8_C(41), UINT8_C(101), LITERAL);
    else if (!strcmp(name, "current-standby"))
        run(3, UINT8_C(41), UINT8_C(101), CURRENT);
    else if (!strcmp(name, "same-original"))
        run(3, UINT8_C(41), UINT8_C(101), SAME);
    else if (!strcmp(name, "single-original"))
        run(3, UINT8_C(41), UINT8_C(101), SINGLE);
    else
        return 2;
    return 0;
}
