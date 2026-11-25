## FIRST · P1794 · ordinary caller snapshot before the standby exchange

I froze these inputs after the [ACTUAL receipt](https://github.com/wakairo/NewLang_Compiler/issues/1794#issuecomment-7160781160) and before any Gate0 execution or production edit. Worktree startup remains unconfirmed because the selected sole workspace's exec transport is unavailable. The checked pins and the C-attested exact EARLY2 receipt are in ACTUAL. The old #1790 source, comparison and public handoff are independent preserved records.

### One caller edit

The caller changes the active queue's byte mode, then records its updated byte and sibling immediately after closing that loan. Its existing recorded field Copy also supplies the named actual to the standby exchange. The exchange operates on a separate live original of the same two-u8 nominal and the same selected field position. This caller uses one genuine current-field read for the record and the next call. The currently available `repeat` source fetches the active target before the standby write and repeats the observation after it. Both retain the same two original storage objects, two scopes, per-object Change/old Copy, unchanged siblings, guard and selection and ordinary teardown.

The two positives cover positions 1→1 and 0→0, low/high guard results and the named or direct-tail writer. Existing displaced-copy and #1793 mixed-position controls pin comparison limits. Snapshot across different positions and alternate incoming values stay outside this increment. The stale, wrong-original and sibling-actual source variants are legal CHECK cases predicted outside this selected backend path. Scope escape is the source rejection control.

### Frozen predictions and comparison

Both unchanged compilers should CHECK the snapshot positives at status 0 and first refuse C17 at status 4 `V1-BACKEND-UNSUPPORTED`. The before-second observation and reused current Copy produce one fewer binding than the existing pair's fixed shape. This is a pre-run expectation. The two repeat controls and adopted equal-index displaced control are expected to emit on both. The mixed repeat control is expected to emit on #1793 alone. The escape should stop at CHECK 3 with `P8-EXIT-DEPENDENCY`. The candidate column is the proposed bounded result, contingent on actual evidence.

The ordinary CLI Gate0 captures CHECK, C17 stdout and named-existing/absent output, preserving sentinel bytes, identity, mode, timestamps and lack of staging on every refusal. Record each actual predecessor compiler's pin and binary digest. Native tuples are planned bytes, selected byte, actual byte, active old/new/sibling, standby old/new/sibling. Verify both real field addresses, old Copies, call order, first lifetime/scope and second actual from the exact first Change's field Copy. Measure the worktree with checked replay, entry world and out-of-memory rollback only if the selected proof supports the increment.

The factored C comparison uses the same complete stack records and named fields, two calls with a typed byte writer from a separate translation unit, sequential lexical use, returned old bytes and unchanged siblings. Same API, physical storage, no allocation and ordinary teardown. Compare recorded vs late duplicated loads before/after the selected caller maintenance. C author audits live writable pointer, one Change and nonretention. The caller's re-audit covers target identity, lifetime and effects across calls. The scoped checked alternative is intended to cover storage identity and sequencing through the existing compiler evidence. Correct choice of queues and mode policy stays with the caller. Relative effort is unmeasured.

Files below are ASCII with LF and one final newline. Manifest digest `cb5c34f33857b39b677f551ef3f875ad74f57f71f1800aba54cdbcac99f990b1`. Gate0 status at freeze is **NOT_RUN**.

### source/snapshot-low.nl · 1178 B · SHA-256 `49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e`

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

### source/snapshot-high.nl · 1162 B · SHA-256 `6b0519cc4510126a759d25d140aead738cf0e072e663713cbea9cf0e2a5d3369`

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

### source/repeat-low.nl · 1213 B · SHA-256 `cd81bce5ca556f57ba8cb1dbd7a462f57b93a4c25ddb3ec89bb99b1e2b4f2fec`

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

### source/repeat-high.nl · 1198 B · SHA-256 `86bb23957bec460f3aca8163c6ee8595abf56e6a174ad8824d90b85e7848cad1`

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
    let incoming = active@reserve_mode;
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

### source/repeat-mixed.nl · 1214 B · SHA-256 `68cdda0e4f1c1c36762bc890fb61483418510abfbc9b0dc923b14c4455614eb2`

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

### source/displaced-control.nl · 1205 B · SHA-256 `1cefa5c2bd8a0f8dd845dc172a429c3b3ac6d6ab13d45b66f06bd92d2c91299c`

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

### source/snapshot-stale.nl · 1178 B · SHA-256 `3a48d92ddb708cc679f18983941af7f48a9718dc03cf1795bd564a90789d9caf`

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
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### source/snapshot-sibling-actual.nl · 1177 B · SHA-256 `2211972ed888d8c94185c8c0ebda3f72406cce08d04bfde518731416c706eb07`

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
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, active_peer) };
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### source/snapshot-wrong-original.nl · 1179 B · SHA-256 `f54400f45d9ead9af5751483de4b30413b1134435aab6d57d6f8316375c754cf`

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
    let old_standby = loan_write(standby@normal_mode) { |slot| install(slot, active_after) };
    let standby_after = standby@normal_mode;
    let standby_peer = standby@reserve_mode;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### source/snapshot-mixed.nl · 1179 B · SHA-256 `f5a166a1d60282f0a6e04fa7e7fb65d6bf62b2a78520f30cd8498c78fef5472d`

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

### source/scope-escape.nl · 283 B · SHA-256 `7fc80f8187803aefadf3836fc7c51df397d19c1f5a12bfb2b96c6ada3f18d2d5`

```text
struct PollDescriptor { reserve_mode: u8, normal_mode: u8 }

fn main() -> unit {
    let active = PollDescriptor{normal_mode: u8(41), reserve_mode: u8(117)};
    let outside = loan_write(active@normal_mode) { |slot| slot };
    let old = replace(outside, u8(35));
    return unit;
}
```

### oracle.tsv · 1415 B · SHA-256 `182af6e2557ccd7b0376d4a1522da05b5f7cb442940a5571c33b51bfab1366ac`

```text
case	bytes	sha256	positions	actual	check	main	compare	candidate	values
snapshot-low	1178	49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e	11	snapshot	0	4	4	0	4032,35,35,41,35,117,149,35,101
snapshot-high	1162	6b0519cc4510126a759d25d140aead738cf0e072e663713cbea9cf0e2a5d3369	00	snapshot	0	4	4	0	4096,93,93,117,93,41,101,93,149
repeat-low	1213	cd81bce5ca556f57ba8cb1dbd7a462f57b93a4c25ddb3ec89bb99b1e2b4f2fec	11	repeat	0	0	0	0	4032,35,35,41,35,117,149,35,101
repeat-high	1198	86bb23957bec460f3aca8163c6ee8595abf56e6a174ad8824d90b85e7848cad1	00	repeat	0	0	0	0	4096,93,93,117,93,41,101,93,149
repeat-mixed	1214	68cdda0e4f1c1c36762bc890fb61483418510abfbc9b0dc923b14c4455614eb2	10	repeat	0	4	0	4	4032,35,35,41,35,117,101,35,149
displaced-control	1205	1cefa5c2bd8a0f8dd845dc172a429c3b3ac6d6ab13d45b66f06bd92d2c91299c	11	displaced	0	0	0	0	4032,35,41,41,35,117,149,41,101
snapshot-stale	1178	3a48d92ddb708cc679f18983941af7f48a9718dc03cf1795bd564a90789d9caf	11	stale	0	4	4	4	
snapshot-sibling-actual	1177	2211972ed888d8c94185c8c0ebda3f72406cce08d04bfde518731416c706eb07	11	sibling	0	4	4	4	
snapshot-wrong-original	1179	f54400f45d9ead9af5751483de4b30413b1134435aab6d57d6f8316375c754cf	11	crossed	0	4	4	4	
snapshot-mixed	1179	f5a166a1d60282f0a6e04fa7e7fb65d6bf62b2a78520f30cd8498c78fef5472d	10	snapshot	0	4	4	4	
scope-escape	283	7fc80f8187803aefadf3836fc7c51df397d19c1f5a12bfb2b96c6ada3f18d2d5		escape	3	3	3	3	
```

### comparison-c/queue_writer.h · 313 B · SHA-256 `d8a770bc3d199ffdc5323d02619b9416f1ae6696500b8c15b1037ff6db89bd2a`

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

### comparison-c/queue_writer.c · 306 B · SHA-256 `a5ba5139dde34a3b291ef7dfc3573431236be8008724e12f083f027f35a8ec37`

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

### comparison-c/caller.c · 3693 B · SHA-256 `7cead3b623c9c2393aef420ca986d09b8c8c716948fde46d7850063141602b6e`

```c
#include "queue_writer.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

_Static_assert(offsetof(PollDescriptor, reserve_mode) <
                   offsetof(PollDescriptor, normal_mode), "field order");

typedef enum { Snapshot, Repeat, Displaced } Handoff;
typedef struct {
    const char *name;
    unsigned first;
    unsigned second;
    size_t rank;
    Handoff handoff;
} Scenario;

static const Scenario cases[] = {
    {"snapshot-low", 1u, 1u, 3u, Snapshot},
    {"snapshot-high", 0u, 0u, 11u, Snapshot},
    {"repeat-low", 1u, 1u, 3u, Repeat},
    {"repeat-high", 0u, 0u, 11u, Repeat},
    {"repeat-mixed", 1u, 0u, 3u, Repeat},
    {"displaced-control", 1u, 1u, 3u, Displaced},
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
        incoming = scenario->handoff == Repeat ? *first_target : old_active;
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

### FIRST-inputs.sha256 · 1361 B · SHA-256 `cb5c34f33857b39b677f551ef3f875ad74f57f71f1800aba54cdbcac99f990b1`

```text
7cead3b623c9c2393aef420ca986d09b8c8c716948fde46d7850063141602b6e  comparison-c/caller.c
a5ba5139dde34a3b291ef7dfc3573431236be8008724e12f083f027f35a8ec37  comparison-c/queue_writer.c
d8a770bc3d199ffdc5323d02619b9416f1ae6696500b8c15b1037ff6db89bd2a  comparison-c/queue_writer.h
182af6e2557ccd7b0376d4a1522da05b5f7cb442940a5571c33b51bfab1366ac  oracle.tsv
1cefa5c2bd8a0f8dd845dc172a429c3b3ac6d6ab13d45b66f06bd92d2c91299c  source/displaced-control.nl
86bb23957bec460f3aca8163c6ee8595abf56e6a174ad8824d90b85e7848cad1  source/repeat-high.nl
cd81bce5ca556f57ba8cb1dbd7a462f57b93a4c25ddb3ec89bb99b1e2b4f2fec  source/repeat-low.nl
68cdda0e4f1c1c36762bc890fb61483418510abfbc9b0dc923b14c4455614eb2  source/repeat-mixed.nl
7fc80f8187803aefadf3836fc7c51df397d19c1f5a12bfb2b96c6ada3f18d2d5  source/scope-escape.nl
6b0519cc4510126a759d25d140aead738cf0e072e663713cbea9cf0e2a5d3369  source/snapshot-high.nl
49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e  source/snapshot-low.nl
f5a166a1d60282f0a6e04fa7e7fb65d6bf62b2a78520f30cd8498c78fef5472d  source/snapshot-mixed.nl
2211972ed888d8c94185c8c0ebda3f72406cce08d04bfde518731416c706eb07  source/snapshot-sibling-actual.nl
3a48d92ddb708cc679f18983941af7f48a9718dc03cf1795bd564a90789d9caf  source/snapshot-stale.nl
f54400f45d9ead9af5751483de4b30413b1134435aab6d57d6f8316375c754cf  source/snapshot-wrong-original.nl
```

### Recovery dependency at FIRST

I individually GET-verified [C's environment recovery note](https://github.com/wakairo/NewLang_Compiler/issues/1794#issuecomment-7160819222). The original worktree attempt returned `exec-server transport disconnected; failed to resume exec-server session: recovery timed out after 45s`. Retries, including after that note, returned `No usable execution environment is available`. The task reports the original environment unavailable even though the control-plane snapshot lists it running. The frozen sources above remain recoverable from this exact comment and manifest. The missing dependency is a working command connection to the original sole P workspace; worktree creation and all compiler runs remain unverified/NOT_RUN. On recovery recheck the actual worktree, main, compare pin and STOP, then record resumed ACTUAL before measurement as C directs.
