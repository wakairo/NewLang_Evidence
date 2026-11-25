## FIRST · recover the actual displaced mode · sole Track P #1786

Provisional source, comparison and oracle before target execution. The caller installs a selected new receive mode on the active descriptor. A closed lexical loan returns the displaced byte. A normal Copy of that returned byte becomes the standby writer's actual on an independent fallback descriptor. This preserves the previously working setting even when the new selected mode and the two old settings differ. The exact low and high examples expect old active 41 or 57, active final 35 or 93, and standby old 101 or 102. Both original tags persist. The tail example changes only the writer's equivalent direct Change return form.

Actual main is `629994f527ded64d755923dcf9a3df2de08eacf5` (Draft17.38). Draft #1785 comparison is `c537de350517bcb0b78700deafe22cf5b624f98d`. CHECK 0 followed by C17 4 predicts V1-BACKEND-UNSUPPORTED. The escape control predicts CHECK 3 P8-EXIT-DEPENDENCY. On refusal the existing named output's bytes, inode, mode and timestamps must persist, the absent output stays absent and zero staging files remain. On success all three C17 outputs must agree. The initial scope is one explicitly named ordinary Copy of the genuine first result, the same registered writer and field index, two separately scoped loans, the existing guard and pure selector and ordinary unit cleanup. The non-result Copy, wrong actual and pre-Change read are outside the proposed bounded family.

Values for independent originals are bytes, selected, second actual, active old/final/tag, standby old/final/tag. Sequential same-original is bytes, selected, first old, intermediate, second old, final, tag. The single case is bytes, selected, old, final, tag. C and NewLang share the typed one-field exchange contract, same physical originals, typed byte Copy and finite cleanup. C's separate exchange object is reused per configuration. On local run refusal the source, first outcomes and raw stdout, stderr, statuses and hashes stay pinned.

```tsv
case	bytes	sha256	check	main	compare	diagnostic	role	values
fallback-low	1139	694d3f791460b5fde17103851fc8eb69afe16612f98e5ff452dc9334bc87017a	0	4	4	V1-BACKEND-UNSUPPORTED	fallback	4032,35,41,41,35,117,101,41,149
fallback-high	1140	ef44ba4280aedc9740fef9829553995aa8f6614509c48af2f43a18c1521c0462	0	4	4	V1-BACKEND-UNSUPPORTED	fallback	4096,93,57,57,93,117,102,57,149
fallback-tail	1108	9f2d9ead0f014233666038e682a73a322151ac098dbd3839181c7f63856f61a0	0	4	4	V1-BACKEND-UNSUPPORTED	fallback	4032,35,41,41,35,117,101,41,149
literal-standby	1136	2ced3a83508a549a243fd86c75e8981cdd2c9bf77fc6c513312d698aea5ee4da	0	0	0		literal	4032,35,19,41,35,117,101,19,149
current-standby	1141	31ef9fc404fa451aa631878378b7c48c7b95b2c850f3fa3a451506394ffab1d8	0	4	0	V1-BACKEND-UNSUPPORTED	current	4032,35,35,41,35,117,101,35,149
same-original	1024	f9aa5c7b4ed531b55867cda6f4fc5777b36d00d9c670c35104c6ecf70ce2a485	0	0	0		same	4032,35,41,35,35,19,117
single-original	839	dc6de459c8dbcddf098b3f0441ee14b9eb83757d552fe6fad24388b93488765b	0	0	0		single	4032,35,41,35,117
other-copy	1138	4990bc35308290a8dc3e053bcbb34d887090577b886e2f76da90a7b32dac3f77	0	4	4	V1-BACKEND-UNSUPPORTED	non-result-copy	
fallback-wrong-actual	1139	5172b970d23e3cc61a92cbb2aaa129a73ce61e05118185ba254dc684b47b1a4c	0	4	4	V1-BACKEND-UNSUPPORTED	unrelated-actual	
pre-change-read	1141	7248a9cbe8726ed9efe76263eba5624ff3be3f14e461fe83ff83af8f1822b558	0	4	4	V1-BACKEND-UNSUPPORTED	read-outside-result	
scope-escape	218	6b0f517142c5bc497475e5f12ee9f68fffe674ac9974647bd85fbece176961ea	3	3	3	P8-EXIT-DEPENDENCY	escape	
```

### fallback-low.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(101), route_tag: u8(149)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let fallback = first_old;
    let second_old = loan_write(standby@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### fallback-high.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(57), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(102), route_tag: u8(149)};
    let rank = usize(14);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let fallback = first_old;
    let second_old = loan_write(standby@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### fallback-tail.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    replace(slot, mode)
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(101), route_tag: u8(149)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let fallback = first_old;
    let second_old = loan_write(standby@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### literal-standby.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(101), route_tag: u8(149)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let fallback = u8(19);
    let second_old = loan_write(standby@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### current-standby.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(101), route_tag: u8(149)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let fallback = active@mode;
    let second_old = loan_write(standby@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### same-original.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let intermediate = active@mode;
    let fallback = u8(19);
    let second_old = loan_write(active@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### single-original.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let displaced_active = first_old;
    return unit;
}
```

### other-copy.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(101), route_tag: u8(149)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let fallback = selected;
    let second_old = loan_write(standby@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### fallback-wrong-actual.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(101), route_tag: u8(149)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let fallback = first_old;
    let second_old = loan_write(standby@mode) { |field| install(field, selected) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### pre-change-read.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn byte_budget(blocks: usize) -> usize {
    if (blocks < usize(1024)) { blocks * usize(64) } else { usize(0) }
}

fn negotiate(bytes: usize) -> u8 {
    if (bytes < usize(4096)) { u8(35) } else { u8(93) }
}

fn install(slot: ref<write,u8>, mode: u8) -> u8 {
    let displaced = replace(slot, mode);
    displaced
}

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let standby = ReceiveSetting{mode: u8(101), route_tag: u8(149)};
    let rank = usize(3);
    let blocks = if (rank < usize(8)) { usize(63) } else { usize(64) };
    let bytes = byte_budget(blocks);
    let selected = negotiate(bytes);
    let fallback = active@mode;
    let first_old = loan_write(active@mode) { |field| install(field, selected) };
    let second_old = loan_write(standby@mode) { |field| install(field, fallback) };
    let active_mode = active@mode;
    let active_tag = active@route_tag;
    let standby_mode = standby@mode;
    let standby_tag = standby@route_tag;
    let displaced_active = first_old;
    let displaced_second = second_old;
    return unit;
}
```

### scope-escape.nl

```text
struct ReceiveSetting { route_tag: u8, mode: u8 }

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let escaped = loan_write(active@mode) { |field| field };
    return unit;
}
```

## Well-factored C inputs

### exchange.h

210 bytes, SHA-256 `12820c60c374d20bb84b5b32ee7743af96aa7f84d2337208aeefb0d465c12897`.

```c
#ifndef P1786_EXCHANGE_H
#define P1786_EXCHANGE_H

#include <stdint.h>

/* The caller supplies a live writable field for the duration of this call. */
uint8_t install_mode(uint8_t *slot, uint8_t mode);

#endif
```

### exchange.c

154 bytes, SHA-256 `08091af64b983037a641100c72372deaa731bef82164cdeca03ad39a7d46d5c7`.

```c
#include "exchange.h"

uint8_t install_mode(uint8_t *slot, uint8_t mode)
{
    const uint8_t displaced = *slot;
    *slot = mode;
    return displaced;
}
```

### caller.c

3,674 bytes, SHA-256 `4b7db6ca49b98c2b70f9689d192324bba7e88302f33ce83c8c06baacc14e9ab8`.

```c
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
```
