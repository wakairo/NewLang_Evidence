#include "queue_writer.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

_Static_assert(offsetof(PollDescriptor, reserve_mode) <
                   offsetof(PollDescriptor, normal_mode), "field order");

typedef struct {
    const char *name;
    unsigned first;
    unsigned second;
    size_t rank;
} Scenario;

static const Scenario cases[] = {
    {"complete-snapshot", 1u, 1u, 3u},
    {"complete-snapshot-low-unit", 1u, 1u, 3u},
    {"complete-snapshot-high", 0u, 0u, 11u},
    {"complete-snapshot-high-unit", 0u, 0u, 11u},
    {"snapshot-low", 1u, 1u, 3u},
    {"snapshot-high", 0u, 0u, 11u},
    {"snapshot-mixed", 1u, 0u, 3u},
    {"snapshot-mixed-reverse", 0u, 1u, 11u},
};

static uint8_t *field(PollDescriptor *original, unsigned index)
{
    assert(index < 2u);
    return index == 0u ? &original->reserve_mode : &original->normal_mode;
}

static void report(const Scenario *scenario)
{
    PollDescriptor active = {.normal_mode = 41u, .reserve_mode = 117u};
    PollDescriptor standby = {.normal_mode = 149u, .reserve_mode = 101u};
    const PollDescriptor *const first_original = &active;
    const PollDescriptor *const second_original = &standby;
    uint8_t *const first_target = field(&active, scenario->first);
    uint8_t *const second_target = field(&standby, scenario->second);
    const uint8_t *const first_peer = field(&active, 1u - scenario->first);
    const uint8_t *const second_peer = field(&standby, 1u - scenario->second);
    const uint8_t first_before = *first_target, second_before = *second_target;
    const uint8_t first_peer_before = *first_peer, second_peer_before = *second_peer;
    const size_t planned = bounded_bytes(scenario->rank < 8u ? 63u : 64u);
    const uint8_t selected = select_mode(planned);

    uint8_t old_active;
    {
        uint8_t *slot = field(&active, scenario->first);
        assert(slot == first_target && slot != first_peer);
        old_active = install(slot, selected);
    }
    const uint8_t incoming = *first_target;
    const uint8_t active_mode = incoming, active_sibling = *first_peer;
    uint8_t old_standby;
    {
        uint8_t *slot = field(&standby, scenario->second);
        assert(slot == second_target && slot != second_peer && slot != first_target);
        assert(*slot == second_before && *second_peer == second_peer_before);
        old_standby = install(slot, incoming);
    }
    assert(first_original == &active && second_original == &standby);
    assert(first_original != second_original);
    assert(old_active == first_before && old_standby == second_before);
    assert(active_mode == selected && *first_target == active_mode);
    assert(active_sibling == first_peer_before && *first_peer == active_sibling);
    assert(*second_target == incoming && *second_peer == second_peer_before);
    printf("%zu,%u,%u,%u,%u,%u,%u,%u,%u\n", planned, (unsigned)selected,
           (unsigned)incoming, (unsigned)old_active, (unsigned)active_mode,
           (unsigned)active_sibling, (unsigned)old_standby,
           (unsigned)*second_target, (unsigned)*second_peer);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 2;
    for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
        if (strcmp(argv[1], cases[i].name) == 0) {
            report(&cases[i]);
            return 0;
        }
    }
    return 2;
}
