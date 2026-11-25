## FIRST · provisional observed active mode to independent standby before Gate0 — sole Track P #1782

A caller configures an active queue and a separate standby on the same receive configuration path. The active queue installs the mode returned by guarded byte planning and a pure selector. A closed lexical loan yields the active old value. A fresh read from the actual active target field supplies a byte to the same registered exchange on the separate standby target. The caller observes each final mode, each original sibling, and each separate displaced Copy, then exits both originally initialized locals. This measures use of the current value at the original field when the caller coordinates the second descriptor.

The pins are actual main 32b63e7bea3be5fd6fafb9f11f8ea0a7fd2376cc (Draft17.38) and the separate #1781 comparator d121c79a0f3cb94da1d2d15aaf789cc16a6e94f0. Table outcomes are provisional predictions before any target execution. CHECK 0 and C17 4 predicts V1-BACKEND-UNSUPPORTED. Scope-escape predicts CHECK 3 P8-EXIT-DEPENDENCY, also for emission. Every failure should preserve bytes, inode and timestamps of an existing named output, leave an absent target absent and leave zero staging files.

For the independent pair the tuple is planned bytes, selected active mode, second actual (the measured observation or literal), active old/final/tag, standby old/final/tag. The two original fields have distinct addresses, the ordered loans are disjoint, and both siblings are retained. The same-original control's tuple is bytes, first selection, first old, second old, final and tag. The single control gives bytes, selected, old, final and tag. The fixed standby literal comparison keeps both originals and allows independent policy. The live-read comparison should track both active settings 35 and 93 on standby while preserving the standby's own old 81 and tag 147. The typed C caller and exchange have the same API and physical field contract. Each C configuration uses one independently compiled exchange object for all five callers.

The refusal controls read the sibling, read standby, move the observation before the first Change, use a different actual despite the observation, or try to let the reference escape. The ordinary CLI and existing proofs will be measured before a private implementation choice. [ACTUAL START](https://github.com/wakairo/NewLang_Compiler/issues/1782#issuecomment-7154580126)

### oracle.tsv

1363 B · SHA-256 811c903a5a8423cf395aa587e676ae88c5ab8ab4981ccc861c774d3b501a5305

```text
case	bytes	sha256	check	main	pin	diagnostic	contract	values
mirror-low	1207	244edcc1be497233155cc68fc09173db8a2c6980f042efc4f0c1a722f895c95f	0	4	4		mirror	4032,35,35,22,35,119,81,35,147
mirror-high	1208	0ef1fe84f088a8b0cf3851216938148f893a276abafddfa530b153bf37447127	0	4	4		mirror	4096,93,93,22,93,119,81,93,147
mirror-tail	1188	78202cbab6e9b6e7527bb23e7fbba9be1700bd2d3b89af482e30ec9130f33df3	0	4	4		mirror	4032,35,35,22,35,119,81,35,147
literal-independent	1196	0c9af8d5cfbb2e06b568accd5ff727c49a73483678c606012765174a2995659e	0	4	0		literal	4032,35,11,22,35,119,81,11,147
same-original	1034	c3e7fde8e522af4ce7c3c1284446828b19fb7a874da982670ff69c4951551ebc	0	0	0		same	4032,35,22,35,11,119
single-original	879	b6d08aaca372cfef6e1be560f309dbd1691120da64173927ce81858e0c0f264d	0	0	0		single	4032,35,22,35,119
mirror-sibling	1206	1252a57e9ea413ce538eb68e48496a83ed71ef6d6e65ef574b2a4aa1b5b94aea	0	4	4		other-field	
mirror-wrong-original	1208	2092f03c360af40fcda1daea8dc5df7e092097733603655f1d12fac7a177e78c	0	4	4		other-root	
mirror-stale	1207	3e07891ea7d6152bccba1eb4683401cd28047d7c1ccc90e43e23e9cb17af29d3	0	4	4		old-observation	
mirror-wrong-actual	1208	995acf076db5cd283129aa0fd6d1467609edc8d7b4061488486b9b04d4451151	0	4	4		unrelated-actual	
scope-escape	282	601b9955a642ecff11e2d245fd1b6eff4384ef145236c52f8a331952020b9eb6	3	3	3	P8-EXIT-DEPENDENCY	escape	
```

### cases/literal-independent.nl

1196 B · SHA-256 0c9af8d5cfbb2e06b568accd5ff727c49a73483678c606012765174a2995659e

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = u8(11);
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/mirror-high.nl

1208 B · SHA-256 0ef1fe84f088a8b0cf3851216938148f893a276abafddfa530b153bf37447127

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(11);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = active@coalescing;
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/mirror-low.nl

1207 B · SHA-256 244edcc1be497233155cc68fc09173db8a2c6980f042efc4f0c1a722f895c95f

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = active@coalescing;
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/mirror-sibling.nl

1206 B · SHA-256 1252a57e9ea413ce538eb68e48496a83ed71ef6d6e65ef574b2a4aa1b5b94aea

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = active@class_tag;
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/mirror-stale.nl

1207 B · SHA-256 3e07891ea7d6152bccba1eb4683401cd28047d7c1ccc90e43e23e9cb17af29d3

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let applied = active@coalescing;
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/mirror-tail.nl

1188 B · SHA-256 78202cbab6e9b6e7527bb23e7fbba9be1700bd2d3b89af482e30ec9130f33df3

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    replace(slot, mode)
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = active@coalescing;
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/mirror-wrong-actual.nl

1208 B · SHA-256 995acf076db5cd283129aa0fd6d1467609edc8d7b4061488486b9b04d4451151

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = active@coalescing;
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, selected) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/mirror-wrong-original.nl

1208 B · SHA-256 2092f03c360af40fcda1daea8dc5df7e092097733603655f1d12fac7a177e78c

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let standby = ReceiveDescriptor{coalescing: u8(81), class_tag: u8(147)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = standby@coalescing;
    let old_standby = loan_write(standby@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let standby_mode = standby@coalescing;
    let standby_tag = standby@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/same-original.nl

1034 B · SHA-256 c3e7fde8e522af4ce7c3c1284446828b19fb7a874da982670ff69c4951551ebc

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let applied = u8(11);
    let old_standby = loan_write(active@coalescing) { |field| exchange(field, applied) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let first_previous = old_active;
    let second_previous = old_standby;
    return unit;
}
```

### cases/scope-escape.nl

282 B · SHA-256 601b9955a642ecff11e2d245fd1b6eff4384ef145236c52f8a331952020b9eb6

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let escaped = loan_write(active@coalescing) { |field| field };
    let old = replace(escaped, u8(35));
    return unit;
}
```

### cases/single-original.nl

879 B · SHA-256 b6d08aaca372cfef6e1be560f309dbd1691120da64173927ce81858e0c0f264d

```text
struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn bounded_bytes(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiated_mode(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn exchange(slot: ref<write,u8>, mode: u8) -> u8 {
    let old = replace(slot, mode);
    old
}

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let planned = bounded_bytes(blocks);
    let selected = negotiated_mode(planned);
    let old_active = loan_write(active@coalescing) { |field| exchange(field, selected) };
    let active_mode = active@coalescing;
    let active_tag = active@class_tag;
    let first_previous = old_active;
    return unit;
}
```

### comparison-c/oracle.tsv

217 B · SHA-256 186880a91e683fc08d9692a45e45256daef3c8695ee240a25a08009576658ff6

```text
case	values
mirror-low	4032,35,35,22,35,119,81,35,147
mirror-high	4096,93,93,22,93,119,81,93,147
literal-independent	4032,35,11,22,35,119,81,11,147
same-original	4032,35,22,35,11,119
single-original	4032,35,22,35,119
```

### comparison-c/caller.c

3455 B · SHA-256 3f00ee3c3c2ed2007b94c84108b4a120b07ca9b5981da20b634fbcbcd3a80d7f

```text
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
```

### comparison-c/exchange.c

138 B · SHA-256 7aba2ed6f7e45964800ff8d8dd06b0c345f8517f701534968e970cd150b6f675

```text
#include "exchange.h"

uint8_t exchange(uint8_t *slot, uint8_t mode)
{
    const uint8_t old = *slot;
    *slot = mode;
    return old;
}
```

### comparison-c/exchange.h

217 B · SHA-256 f79ebf76004fa57a745c77d391ab2a801085ca2550aeb26856a4fd6aa4d8a7de

```text
#ifndef COMPARE_EXCHANGE_H
#define COMPARE_EXCHANGE_H

#include <stdint.h>

typedef struct {
    uint8_t class_tag;
    uint8_t coalescing;
} ReceiveDescriptor;

uint8_t exchange(uint8_t *slot, uint8_t mode);

#endif
```
