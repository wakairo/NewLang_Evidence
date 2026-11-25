## FIRST · P1802 · reuse a current-field Copy across different field positions

Frozen before either compiler run. Actual main is 94eb75c3efa91a3feb2a14319d840bc00677bed9. Compare-only #1801 is 74ff94c7d24f702823f0885f8525c7472b2c9cf6. The writer, ordinary local originals, typed projection, loans, teardown and arithmetic policy are the same in each matched source pair. The matching-field snapshot is already selected. The chosen refactor retains the first current-field Copy and its sibling observation between loans, uses that Copy as the second writer input, and removes one redundant read. Test both declared index orders. [ACTUAL](https://github.com/wakairo/NewLang_Compiler/issues/1802#issuecomment-7162540513)

Expected first refusal for the two mixed-position snapshots is C17 status 4 after CHECK 0 on both original pins. Their matched reread forms and same-position snapshot controls should emit. Predictions for a bounded candidate are recorded separately. C17 value observations report planned bytes, selected byte, second actual, first old/current/sibling, second old/current/sibling. Refusals are checked against an existing output and an absent destination.

FIRST-inputs.sha256 has 17 entries and SHA-256 `ff3d1cb37674b1582da8c8855f5cc1627edd85a836712718fda981b669593325`. Each source is retained as UTF-8 with its final LF. The manifest and oracle below bind the original bytes.

```text
47bc2730eb227af1c19f12826f125e61f6407f25ea91a39332d8c2ac2e540706  oracle.tsv
1aad03bdf0e08db344bd989fdab67af0a9d30ab82ec8ff190f51c5f4a1c05f93  source/mixed-old.nl
40ae3cd6f739d03e22bc7a85718e87ce63bd7587f318ec9f327125ba9b1640c7  source/reread-mixed-reverse.nl
68cdda0e4f1c1c36762bc890fb61483418510abfbc9b0dc923b14c4455614eb2  source/reread-mixed.nl
fdee3344122a64ad906abd04725b92cbed29f3d52575104872838777c4d09990  source/scope-escape.nl
6b0519cc4510126a759d25d140aead738cf0e072e663713cbea9cf0e2a5d3369  source/snapshot-high.nl
49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e  source/snapshot-low.nl
b93c1086d871c9929e57702791eb29c7503ab3ccc808ecd228b084eb8ef6f51e  source/snapshot-mixed-before-change.nl
f8496cd87fd59766d0710c52e3f08592c3e044da5e7070154e97b98c6771f67d  source/snapshot-mixed-normal-exit.nl
1132511b1ce6683a97a17377d90ea4f7d2f424372fc25681d39f4a0865205396  source/snapshot-mixed-other.nl
ef03900ffa408d84cf254d2f0b6f112c2ad2ffa76f8f81682da63dd93187f5e1  source/snapshot-mixed-reverse.nl
4b00da7b9e0d29097403851eb736397b2c87a9149e1bfc10cd911a3823a77a56  source/snapshot-mixed-sibling.nl
f5a166a1d60282f0a6e04fa7e7fb65d6bf62b2a78520f30cd8498c78fef5472d  source/snapshot-mixed.nl
aaf9d021e1dc08c25e06631de48d235f937354db02053b87e212bf3e1683cd1a  comparison-c/caller.c
a5ba5139dde34a3b291ef7dfc3573431236be8008724e12f083f027f35a8ec37  comparison-c/queue_writer.c
db453e35cb22613545f059580958533aff7133456a571aac932fb828bf0f6c2a  comparison-c/queue_writer.h
aedf598309dc9c1bbabd4b16c49ffeb447aaf8655a476df3929f63e6826edff3  freeze_first.py
```

```text
case	bytes	sha256	positions	actual	check	main	compare	candidate	values
snapshot-mixed	1179	f5a166a1d60282f0a6e04fa7e7fb65d6bf62b2a78520f30cd8498c78fef5472d	10	snapshot	0	4	4	0	4032,35,35,41,35,117,101,35,149
snapshot-mixed-reverse	1180	ef03900ffa408d84cf254d2f0b6f112c2ad2ffa76f8f81682da63dd93187f5e1	01	snapshot	0	4	4	0	4096,93,93,117,93,41,149,93,101
reread-mixed	1214	68cdda0e4f1c1c36762bc890fb61483418510abfbc9b0dc923b14c4455614eb2	10	current	0	0	0	0	4032,35,35,41,35,117,101,35,149
reread-mixed-reverse	1216	40ae3cd6f739d03e22bc7a85718e87ce63bd7587f318ec9f327125ba9b1640c7	01	current	0	0	0	0	4096,93,93,117,93,41,149,93,101
snapshot-low	1178	49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e	11	snapshot	0	0	0	0	4032,35,35,41,35,117,149,35,101
snapshot-high	1162	6b0519cc4510126a759d25d140aead738cf0e072e663713cbea9cf0e2a5d3369	00	snapshot	0	0	0	0	4096,93,93,117,93,41,101,93,149
snapshot-mixed-sibling	1179	4b00da7b9e0d29097403851eb736397b2c87a9149e1bfc10cd911a3823a77a56	10	snapshot	0	4	4	4	
snapshot-mixed-other	1180	1132511b1ce6683a97a17377d90ea4f7d2f424372fc25681d39f4a0865205396	10	snapshot	0	4	4	4	
snapshot-mixed-before-change	1179	b93c1086d871c9929e57702791eb29c7503ab3ccc808ecd228b084eb8ef6f51e	10	snapshot	0	4	4	4	
snapshot-mixed-normal-exit	1162	f8496cd87fd59766d0710c52e3f08592c3e044da5e7070154e97b98c6771f67d	10	snapshot	0	4	4	4	
mixed-old	1194	1aad03bdf0e08db344bd989fdab67af0a9d30ab82ec8ff190f51c5f4a1c05f93	10	displaced	0	4	4	4	
scope-escape	340	fdee3344122a64ad906abd04725b92cbed29f3d52575104872838777c4d09990		escape	3	3	3	3	
```

#### source/snapshot-mixed.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/snapshot-mixed-reverse.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(11);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@reserve_mode) { |slot| install(slot, selected) };
    let active_after = active@reserve_mode;
    let active_peer = active@normal_mode;
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/reread-mixed.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let incoming = active@normal_mode;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, incoming) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/reread-mixed-reverse.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(11);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@reserve_mode) { |slot| install(slot, selected) };
    let incoming = active@reserve_mode;
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, incoming) };
    let active_after = active@reserve_mode;
    let active_peer = active@normal_mode;
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/snapshot-low.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/snapshot-high.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    replace(slot, mode)
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(11);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@reserve_mode) { |slot| install(slot, selected) };
    let active_after = active@reserve_mode;
    let active_peer = active@normal_mode;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/snapshot-mixed-sibling.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let active_after = active@reserve_mode;
    let active_peer = active@normal_mode;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/snapshot-mixed-other.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let active_after = standby@normal_mode;
    let active_peer = active@reserve_mode;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/snapshot-mixed-before-change.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let active_after = active@normal_mode;
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let active_peer = active@reserve_mode;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/snapshot-mixed-normal-exit.nl

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = PollDescriptor{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
}
```

#### source/mixed-old.nl

```text
struct QueueModes { reserve_mode: u8, normal_mode: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn select_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = QueueModes{normal_mode: u8(41), reserve_mode: u8(117)};
    let standby = QueueModes{normal_mode: u8(149), reserve_mode: u8(101)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = select_mode(planned);
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let incoming = old_active;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, incoming) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

#### source/scope-escape.nl

```text
struct QueueState { mode: u8, flags: u8 }

fn main() -> unit {
    let original = QueueState{mode: u8(17), flags: u8(211)};
    let outside = loan_write(original@mode) { |writer| writer };
    let old = replace(outside, u8(53));
    let updated = original@mode;
    let sibling = original@flags;
    let old_again = old;
    return unit;
}
```

#### comparison-c/caller.c

```c
#include "queue_writer.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

_Static_assert(offsetof(PollDescriptor, reserve_mode) <
                   offsetof(PollDescriptor, normal_mode), "field order");

typedef struct {
    const char *name;
    unsigned first;
    unsigned second;
    size_t rank;
    bool snapshot;
} Scenario;

static const Scenario cases[] = {
    {"snapshot-mixed", 1u, 0u, 3u, true},
    {"snapshot-mixed-reverse", 0u, 1u, 11u, true},
    {"reread-mixed", 1u, 0u, 3u, false},
    {"reread-mixed-reverse", 0u, 1u, 11u, false},
    {"snapshot-low", 1u, 1u, 3u, true},
    {"snapshot-high", 0u, 0u, 11u, true},
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
    uint8_t active_mode = 0u, active_sibling = 0u;
    if (scenario->snapshot) {
        active_mode = incoming;
        active_sibling = *first_peer;
    }
    uint8_t old_standby;
    {
        uint8_t *slot = field(&standby, scenario->second);
        assert(slot == second_target && slot != second_peer && slot != first_target);
        assert(*slot == second_before && *second_peer == second_peer_before);
        old_standby = install(slot, incoming);
    }
    if (!scenario->snapshot) {
        active_mode = *first_target;
        active_sibling = *first_peer;
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
```

#### comparison-c/queue_writer.c

```c
#include "queue_writer.h"

size_t bounded_bytes(size_t blocks)
{
    return blocks < 1024u ? blocks * 64u : 0u;
}

uint8_t select_mode(size_t bytes)
{
    return bytes < 4096u ? 35u : 93u;
}

uint8_t install(uint8_t *slot, uint8_t mode)
{
    const uint8_t old = *slot;
    *slot = mode;
    return old;
}
```

#### comparison-c/queue_writer.h

```c
#ifndef P1802_QUEUE_WRITER_H
#define P1802_QUEUE_WRITER_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t reserve_mode;
    uint8_t normal_mode;
} PollDescriptor;

size_t bounded_bytes(size_t blocks);
uint8_t select_mode(size_t bytes);
uint8_t install(uint8_t *slot, uint8_t mode);

#endif
```

The C control uses separate translation units and the same two stack originals, two typed field writes, old and sibling checks, and sequence. Its caller remains responsible for live writable target pointers and ordering. The selected NewLang experiment asks whether existing checked Copy and loan proofs can enforce those dependencies with one source read.