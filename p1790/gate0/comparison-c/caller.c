#include "queue_writer.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

_Static_assert(offsetof(QueueModes, reserve_mode) <
                   offsetof(QueueModes, normal_mode), "field declaration order");

typedef enum { Current, Literal, Old } Handoff;

typedef struct {
    const char *name;
    bool first_normal;
    bool second_normal;
    size_t rank;
    Handoff handoff;
} Scenario;

static const Scenario scenarios[] = {
    {"mixed-current-low", true, false, 3u, Current},
    {"mixed-current-high", false, true, 11u, Current},
    {"mixed-literal-low", true, false, 3u, Literal},
    {"mixed-literal-high", false, true, 11u, Literal},
    {"same-current", true, true, 3u, Current},
    {"same-literal", false, false, 11u, Literal},
    {"same-old", true, true, 3u, Old},
    {"mixed-old", true, false, 3u, Old},
};

static uint8_t *target(QueueModes *queue, bool normal)
{
    return normal ? &queue->normal_mode : &queue->reserve_mode;
}

static int report(const Scenario *scenario)
{
    QueueModes active = {.normal_mode = 41u, .reserve_mode = 117u};
    QueueModes standby = {.normal_mode = 149u, .reserve_mode = 101u};
    const QueueModes *const first = &active, *const second = &standby;
    const uint8_t *const first_field = target(&active, scenario->first_normal);
    const uint8_t *const second_field = target(&standby, scenario->second_normal);
    const uint8_t *const first_peer = target(&active, !scenario->first_normal);
    const uint8_t *const second_peer = target(&standby, !scenario->second_normal);
    const uint8_t first_peer_before = *first_peer;
    const uint8_t second_peer_before = *second_peer;
    const uint8_t second_before = *second_field;
    const size_t blocks = scenario->rank < 8u ? 63u : 64u;
    const size_t bytes = bounded_bytes(blocks);
    const uint8_t selected = select_mode(bytes);
    uint8_t old_active;
    {
        uint8_t *slot = target(&active, scenario->first_normal);
        old_active = install(slot, selected);
    }
    assert(*second_field == second_before && *second_peer == second_peer_before);
    const uint8_t incoming = scenario->handoff == Literal ? 19u :
                             scenario->handoff == Old ? old_active : *first_field;
    uint8_t old_standby;
    {
        uint8_t *slot = target(&standby, scenario->second_normal);
        old_standby = install(slot, incoming);
    }
    assert(first != second && first == &active && second == &standby);
    assert(first_field == target(&active, scenario->first_normal));
    assert(second_field == target(&standby, scenario->second_normal));
    assert(first_field != second_field && first_field != first_peer &&
           second_field != second_peer);
    assert(*first_field == selected && *second_field == incoming &&
           *first_peer == first_peer_before && *second_peer == second_peer_before);
    printf("%zu,%u,%u,%u,%u,%u,%u,%u,%u\n", bytes, (unsigned)selected,
           (unsigned)incoming, (unsigned)old_active, (unsigned)*first_field,
           (unsigned)*first_peer, (unsigned)old_standby,
           (unsigned)*second_field, (unsigned)*second_peer);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 2;
    for (size_t i = 0; i < sizeof(scenarios) / sizeof(scenarios[0]); ++i)
        if (strcmp(argv[1], scenarios[i].name) == 0)
            return report(&scenarios[i]);
    return 2;
}
