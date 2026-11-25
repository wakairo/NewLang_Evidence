## FIRST · P1798 · normal unit completion after two scoped writers

This is the pre-run freeze after the individually verified ACTUAL. Both unmodified compilers are kept at their exact manifest pins. The predicted candidate column describes only the scoped change if the measurements justify it.

An ordinary caller uses one checked registered writer on two separate live descriptor originals, reads both target and peer fields, keeps both returned old bytes and completes the unit entry. The maintenance edit replaces the final explicit `return unit;` with ordinary block completion. The two no-tail cases use current-field or literal input, including the already-supported mixed-position literal. The explicit unit-tail case feeds the first call's real displaced Copy across equal indices. Each pair keeps source order, field indices, original storage and cleanup unchanged.

Draft17.38 §19.1 and the existing complete ordinary unit validator permit an absent tail or an exact unit tail. Predict CHECK0 and first C17 refusal at status 4 on both pins for all three normal-completion positives. The distinct-writer validator is expected to require the explicit Return in a caller whose existing handoff evidence is otherwise complete. The verbatim Return counterparts should emit on both pins. The snapshot Return control remains compare-only and its no-tail counterpart is a scope control. A stale current input or mixed-index displaced input still refuses at C17. Scope escape still stops at CHECK3 with P8-EXIT-DEPENDENCY.

Gate0 captures CHECK, C17 and both named output forms. A refusal preserves an existing sentinel's bytes, inode, mode and timestamps, and an absent destination remains absent without staging. The read-only probe should check the ordinary unit block and exact nil/Unit tail, no Return exit, both call replays and lexical scopes, original roots, child facts and final cleanup. If the candidate validates, compare its three emitted C17 pairs byte for byte through the exact same writer and native values. Native tuples are planned bytes, selected, incoming, active old/new/peer, standby old/new/peer.

The factored C baseline separately compiles the typed writer and the caller. It exercises the same physical automatic records, field addresses, one Change per original, old values, unchanged peer bytes, no allocation and ordinary teardown. Both source endings have the same caller obligations. The C author audits live writable pointer storage, one load/store, return and nonretention. The caller accounts for storage, disjoint targets, ordering and lifetime on the exit path. The selected compiler path should authenticate those properties through existing evidence at normal block completion. The chosen field/value policy stays with the caller. Effort is unmeasured.

ACTUAL https://github.com/wakairo/NewLang_Compiler/issues/1798#issuecomment-7161656240

Frozen input manifest SHA-256 bb831a519ae6ec335c0fe7400aeb1db67b5a4942f9a1fd640c54e5750a89564c. Files below have their original LF bytes.

### FIRST-inputs.sha256 · 1483 B · SHA-256 bb831a519ae6ec335c0fe7400aeb1db67b5a4942f9a1fd640c54e5750a89564c

```text
425faf9bd54f310fee4d861304fa379682387f9cdecbb2255baf86717713e87e  oracle.tsv
65225bb4108097439403e67524e2df4a3e371e877e5ea088c498e9462b02e1eb  source/complete-current.nl
1a60c5a1428997710b176a6703a2b59c06bce3f1cc76858cd4b3ee37eb2193f9  source/complete-displaced-unit.nl
750d6f94e66d65c3e8f583e25ab414241bf523d2f2582993027748896c186c97  source/complete-literal-mixed.nl
d434782072cf710cce3fa74808dc9785bdcf8c750960ae8d8fd974007d02b294  source/complete-mixed-displaced.nl
65135b3f3a79f542e95910e597ba5081b9e3c7f12b0f813bd96454eae0345cc9  source/complete-snapshot.nl
f29fec8ee0cd436fa9c2832a2edc72cc4809a0ce73b59f7fac0861da173029b4  source/complete-stale-current.nl
cd81bce5ca556f57ba8cb1dbd7a462f57b93a4c25ddb3ec89bb99b1e2b4f2fec  source/return-current.nl
90e92d7d52b0ec6eff6693dc5890ad33974cb9487c79201c917b07294a526864  source/return-displaced.nl
7fb7ead47acba283b41f3ec87bba728410c79a3fd0ba6fa2781e4ad5e72b13c6  source/return-literal-mixed.nl
49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e  source/return-snapshot.nl
7fc80f8187803aefadf3836fc7c51df397d19c1f5a12bfb2b96c6ada3f18d2d5  source/scope-escape.nl
f8a17c071ea846e18fa4ad4a9cb5c1067e9929260b5dc940c6a8eb5878e7c227  comparison-c/caller.c
a5ba5139dde34a3b291ef7dfc3573431236be8008724e12f083f027f35a8ec37  comparison-c/queue_writer.c
d8a770bc3d199ffdc5323d02619b9416f1ae6696500b8c15b1037ff6db89bd2a  comparison-c/queue_writer.h
70a00338b47ec751d699f88bce4504d4220e9b92421e5ff5db89ad575690d5bf  freeze_first.py
```

### oracle.tsv · 1498 B · SHA-256 425faf9bd54f310fee4d861304fa379682387f9cdecbb2255baf86717713e87e

```text
case	bytes	sha256	positions	actual	check	main	compare	candidate	values
complete-current	1196	65225bb4108097439403e67524e2df4a3e371e877e5ea088c498e9462b02e1eb	11	current	0	4	4	0	4032,35,35,41,35,117,149,35,101
return-current	1213	cd81bce5ca556f57ba8cb1dbd7a462f57b93a4c25ddb3ec89bb99b1e2b4f2fec	11	current	0	0	0	0	4032,35,35,41,35,117,149,35,101
complete-literal-mixed	1167	750d6f94e66d65c3e8f583e25ab414241bf523d2f2582993027748896c186c97	01	literal	0	4	4	0	4096,93,19,117,93,41,149,19,101
return-literal-mixed	1184	7fb7ead47acba283b41f3ec87bba728410c79a3fd0ba6fa2781e4ad5e72b13c6	01	literal	0	0	0	0	4096,93,19,117,93,41,149,19,101
complete-displaced-unit	1181	1a60c5a1428997710b176a6703a2b59c06bce3f1cc76858cd4b3ee37eb2193f9	00	displaced	0	4	4	0	4096,93,117,117,93,41,101,117,149
return-displaced	1189	90e92d7d52b0ec6eff6693dc5890ad33974cb9487c79201c917b07294a526864	00	displaced	0	0	0	0	4096,93,117,117,93,41,101,117,149
complete-mixed-displaced	1189	d434782072cf710cce3fa74808dc9785bdcf8c750960ae8d8fd974007d02b294	10	displaced	0	4	4	4	
complete-stale-current	1196	f29fec8ee0cd436fa9c2832a2edc72cc4809a0ce73b59f7fac0861da173029b4	11	current	0	4	4	4	
return-snapshot	1178	49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e	11	snapshot	0	4	0	4	4032,35,35,41,35,117,149,35,101
complete-snapshot	1161	65135b3f3a79f542e95910e597ba5081b9e3c7f12b0f813bd96454eae0345cc9	11	snapshot	0	4	4	4	
scope-escape	283	7fc80f8187803aefadf3836fc7c51df397d19c1f5a12bfb2b96c6ada3f18d2d5		escape	3	3	3	3	
```

### source/complete-current.nl · 1196 B · SHA-256 65225bb4108097439403e67524e2df4a3e371e877e5ea088c498e9462b02e1eb

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
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, incoming) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
}
```

### source/return-current.nl · 1213 B · SHA-256 cd81bce5ca556f57ba8cb1dbd7a462f57b93a4c25ddb3ec89bb99b1e2b4f2fec

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
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, incoming) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### source/complete-literal-mixed.nl · 1167 B · SHA-256 750d6f94e66d65c3e8f583e25ab414241bf523d2f2582993027748896c186c97

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
    let incoming = u8(19);
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, incoming) };
    let active_after = active@reserve_mode;
    let active_peer = active@normal_mode;
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
}
```

### source/return-literal-mixed.nl · 1184 B · SHA-256 7fb7ead47acba283b41f3ec87bba728410c79a3fd0ba6fa2781e4ad5e72b13c6

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
    let incoming = u8(19);
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

### source/complete-displaced-unit.nl · 1181 B · SHA-256 1a60c5a1428997710b176a6703a2b59c06bce3f1cc76858cd4b3ee37eb2193f9

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
    let incoming = old_active;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, incoming) };
    let active_after = active@reserve_mode;
    let active_peer = active@normal_mode;
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    unit
}
```

### source/return-displaced.nl · 1189 B · SHA-256 90e92d7d52b0ec6eff6693dc5890ad33974cb9487c79201c917b07294a526864

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
    let incoming = old_active;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, incoming) };
    let active_after = active@reserve_mode;
    let active_peer = active@normal_mode;
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### source/complete-mixed-displaced.nl · 1189 B · SHA-256 d434782072cf710cce3fa74808dc9785bdcf8c750960ae8d8fd974007d02b294

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
    let incoming = old_active;
    let old_standby = loan_write(standby@reserve_mode) { |slot| install(slot, incoming) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let standby_after = standby@reserve_mode;
    let standby_peer = standby@normal_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
}
```

### source/complete-stale-current.nl · 1196 B · SHA-256 f29fec8ee0cd436fa9c2832a2edc72cc4809a0ce73b59f7fac0861da173029b4

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
    let incoming = active@normal_mode;
    let old_active = loan_write(active@normal_mode) { |slot| install(slot, selected) };
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, incoming) };
    let active_after = active@normal_mode;
    let active_peer = active@reserve_mode;
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
}
```

### source/return-snapshot.nl · 1178 B · SHA-256 49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e

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

### source/complete-snapshot.nl · 1161 B · SHA-256 65135b3f3a79f542e95910e597ba5081b9e3c7f12b0f813bd96454eae0345cc9

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
}
```

### source/scope-escape.nl · 283 B · SHA-256 7fc80f8187803aefadf3836fc7c51df397d19c1f5a12bfb2b96c6ada3f18d2d5

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let outside = loan_write(active@normal_mode) { |slot| slot };
    let old = replace(outside, u8(35));
    return unit;
}
```

### comparison-c/caller.c · 3844 B · SHA-256 f8a17c071ea846e18fa4ad4a9cb5c1067e9929260b5dc940c6a8eb5878e7c227

```c
#include "queue_writer.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

_Static_assert(offsetof(PollDescriptor, reserve_mode) <
                   offsetof(PollDescriptor, normal_mode), "field order");

typedef enum { Snapshot, Repeat, Displaced, Literal } Handoff;
typedef struct {
    const char *name;
    unsigned first;
    unsigned second;
    size_t rank;
    Handoff handoff;
} Scenario;

static const Scenario cases[] = {
    {"complete-current", 1u, 1u, 3u, Repeat},
    {"return-current", 1u, 1u, 3u, Repeat},
    {"complete-literal-mixed", 0u, 1u, 11u, Literal},
    {"return-literal-mixed", 0u, 1u, 11u, Literal},
    {"complete-displaced-unit", 0u, 0u, 11u, Displaced},
    {"return-displaced", 0u, 0u, 11u, Displaced},
    {"return-snapshot", 1u, 1u, 3u, Snapshot},
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
    const size_t planned = bounded_bytes(scenario->rank < 8u ? 63u : 64u);
    const uint8_t selected = select_mode(planned);
    const PollDescriptor *const first_original = &active;
    const PollDescriptor *const second_original = &standby;
    const uint8_t *const first_target = field(&active, scenario->first);
    const uint8_t *const second_target = field(&standby, scenario->second);
    const uint8_t *const first_peer = field(&active, 1u - scenario->first);
    const uint8_t *const second_peer = field(&standby, 1u - scenario->second);
    const uint8_t first_before = *first_target, second_before = *second_target;
    const uint8_t first_peer_before = *first_peer, second_peer_before = *second_peer;
    uint8_t old_active;
    {
        uint8_t *slot = field(&active, scenario->first);
        assert(slot == first_target && slot != first_peer);
        old_active = install(slot, selected);
    }
    uint8_t active_mode = 0u, active_sibling = 0u;
    uint8_t incoming;
    if (scenario->handoff == Snapshot) {
        active_mode = *first_target;
        active_sibling = *first_peer;
        incoming = active_mode;
    } else {
        incoming = scenario->handoff == Literal ? 19u :
                   scenario->handoff == Repeat ? *first_target : old_active;
    }
    uint8_t old_standby;
    {
        uint8_t *slot = field(&standby, scenario->second);
        assert(slot == second_target && slot != second_peer && slot != first_target);
        assert(*slot == second_before && *second_peer == second_peer_before);
        old_standby = install(slot, incoming);
    }
    if (scenario->handoff != Snapshot) {
        active_mode = *first_target;
        active_sibling = *first_peer;
    }
    assert(first_original == &active && second_original == &standby &&
           first_original != second_original);
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

### comparison-c/queue_writer.c · 306 B · SHA-256 a5ba5139dde34a3b291ef7dfc3573431236be8008724e12f083f027f35a8ec37

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

### comparison-c/queue_writer.h · 313 B · SHA-256 d8a770bc3d199ffdc5323d02619b9416f1ae6696500b8c15b1037ff6db89bd2a

```c
#ifndef P1794_QUEUE_WRITER_H
#define P1794_QUEUE_WRITER_H

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

### freeze_first.py · 4160 B · SHA-256 70a00338b47ec751d699f88bce4504d4220e9b92421e5ff5db89ad575690d5bf

```text
from csv import writer
from hashlib import sha256
from pathlib import Path
import re

prior = Path("/workspace/p1544-6afecbd5/p1794-early-field-copy/evidence")
here = Path(__file__).resolve().parent

def old(name):
    return (prior / "source" / (name + ".nl")).read_text()

def replace_once(text, source, replacement):
    assert text.count(source) == 1
    return text.replace(source, replacement)

def complete(text, tail=""):
    return replace_once(text, "    return unit;\n}\n", tail + "}\n")

current = old("repeat-low")
high = old("repeat-high")
displaced = replace_once(high, "    let incoming = active@reserve_mode;\n",
                         "    let incoming = old_active;\n")
literal = replace_once(high, "    let incoming = active@reserve_mode;\n",
                       "    let incoming = u8(19);\n")
literal = re.sub(r"standby@(reserve_mode|normal_mode)",
                 lambda m: "standby@" + ("normal_mode" if m[1] == "reserve_mode" else "reserve_mode"),
                 literal)
mixed_old = replace_once(old("repeat-mixed"), "    let incoming = active@normal_mode;\n",
                         "    let incoming = old_active;\n")
incoming = "    let incoming = active@normal_mode;\n"
stale = replace_once(
    current.replace(incoming, ""),
    "    let old_active = loan_write(active@normal_mode)",
    incoming + "    let old_active = loan_write(active@normal_mode)",
)
low = "4032,35,35,41,35,117,149,35,101"
literal_high = "4096,93,19,117,93,41,149,19,101"
old_high = "4096,93,117,117,93,41,101,117,149"
snap = old("snapshot-low")
cases = [
    ("complete-current", complete(current), "11", "current", 0, 4, 4, 0, low),
    ("return-current", current, "11", "current", 0, 0, 0, 0, low),
    ("complete-literal-mixed", complete(literal), "01", "literal", 0, 4, 4, 0, literal_high),
    ("return-literal-mixed", literal, "01", "literal", 0, 0, 0, 0, literal_high),
    ("complete-displaced-unit", complete(displaced, "    unit\n"), "00", "displaced", 0, 4, 4, 0, old_high),
    ("return-displaced", displaced, "00", "displaced", 0, 0, 0, 0, old_high),
    ("complete-mixed-displaced", complete(mixed_old), "10", "displaced", 0, 4, 4, 4, ""),
    ("complete-stale-current", complete(stale), "11", "current", 0, 4, 4, 4, ""),
    ("return-snapshot", snap, "11", "snapshot", 0, 4, 0, 4, low),
    ("complete-snapshot", complete(snap), "11", "snapshot", 0, 4, 4, 4, ""),
    ("scope-escape", old("scope-escape"), "", "escape", 3, 3, 3, 3, ""),
]
rows = []
for name, text, *values in cases:
    data = text.encode("ascii")
    path = here / "source" / f"{name}.nl"
    with path.open("xb") as out:
        out.write(data)
    rows.append((name, len(data), sha256(data).hexdigest(), *values))
with (here / "oracle.tsv").open("x", newline="") as out:
    table = writer(out, delimiter="\t", lineterminator="\n")
    table.writerow(("case", "bytes", "sha256", "positions", "actual",
                    "check", "main", "compare", "candidate", "values"))
    table.writerows(rows)

for part in ("queue_writer.h", "queue_writer.c"):
    (here / "comparison-c" / part).write_bytes((prior / "comparison-c" / part).read_bytes())
caller = (prior / "comparison-c/caller.c").read_text().replace(
    "{ Snapshot, Repeat, Displaced } Handoff", "{ Snapshot, Repeat, Displaced, Literal } Handoff"
)
start = caller.index("static const Scenario cases[] = {")
end = caller.index("\n};", start) + len("\n};")
caller = caller[:start] + """static const Scenario cases[] = {
    {"complete-current", 1u, 1u, 3u, Repeat},
    {"return-current", 1u, 1u, 3u, Repeat},
    {"complete-literal-mixed", 0u, 1u, 11u, Literal},
    {"return-literal-mixed", 0u, 1u, 11u, Literal},
    {"complete-displaced-unit", 0u, 0u, 11u, Displaced},
    {"return-displaced", 0u, 0u, 11u, Displaced},
    {"return-snapshot", 1u, 1u, 3u, Snapshot},
};""" + caller[end:]
caller = replace_once(caller,
    "        incoming = scenario->handoff == Repeat ? *first_target : old_active;",
    """        incoming = scenario->handoff == Literal ? 19u :
                   scenario->handoff == Repeat ? *first_target : old_active;"""
)
(here / "comparison-c/caller.c").write_text(caller)
```

