## FIRST · P1806 · ordinary unit completion after an early current-field Copy

Frozen before either compiler run. Actual main is 1c99d8dfc536160dfd1b26016cd4414dc1af9b75. Compare-only #1805 is 0610baef571243ee5dc326b2a7a908c0b66c2263. The chosen caller omits an explicit Return after the two existing writers and early observations at the same declared position on distinct originals of the same nominal. Four variants cover no tail and a literal unit tail at both positions. Only the ending varies from the corresponding explicit unit Return. The two constructions, actual field addresses, arithmetic policy, observations, copies and registered writer are identical in each pair. [ACTUAL](https://github.com/wakairo/NewLang_Compiler/issues/1806#issuecomment-7163999580)

Predict CHECK success and C17 refusal for all four ordinary completion variants on both original pins. The two matching-position explicit Return controls should emit on both. Both mixed explicit controls should emit on #1805. Mixed ordinary completion, a stale or unrelated Copy, and displaced-position mismatch should still refuse. The oracle records the candidate prediction independently. Emission is checked with a present file and an absent destination.

The expected native observations are planned byte count, selected byte, second actual, first displaced/current/sibling, and second displaced/current/sibling. The C reference separates its guarded arithmetic and one-load one-store writer from the caller. The caller creates both stack originals and checks the field addresses, their lifetime, values and sequence. The experiment asks whether that same checked caller can change its ending while retaining existing original, source and cleanup proofs.

FIRST-inputs.sha256 has 20 entries and SHA-256 `ceb1f064b39a7c8a1d34c0e19b8293d8baa8b0c7750d89d6c7e396b0e5a0ef5b`. Source is UTF-8 including the final LF.

```text
bd1524d59fc9ddaeb5b4a63811e20cd731216e9b1814e5144c38542957904162  oracle.tsv
2f49d8952e0d43c7daf982c7d8cd305275a1c4762b5a5fff6287d40c6bea154d  source/complete-snapshot-high-unit.nl
6f201a303683405ffd91a2d7f275d7b6bfed3cdd111492aad5ef275f7e282c2c  source/complete-snapshot-high.nl
ab710c9596e63344a0c3867a905a1e4cd67468b8a1549ed97b5808b329a3902b  source/complete-snapshot-low-unit.nl
705a29dbf881b56d9f7241cef68359181899309d8871f9dc35d4787719de1e7b  source/complete-snapshot-mixed-reverse.nl
f8496cd87fd59766d0710c52e3f08592c3e044da5e7070154e97b98c6771f67d  source/complete-snapshot-mixed.nl
64f94403318d730c716375a95e96119173bc2ad7f36482e2cf0361b93a1e0947  source/complete-snapshot-other.nl
0a774b15a68513be41b0c71e131ed056a9e60b4db40f591ee413d7d978d37768  source/complete-snapshot-sibling.nl
5b098818ffe75d844d580150351da2c9d48088cade852193d1fe2d5a982ea559  source/complete-snapshot-stale.nl
65135b3f3a79f542e95910e597ba5081b9e3c7f12b0f813bd96454eae0345cc9  source/complete-snapshot.nl
1aad03bdf0e08db344bd989fdab67af0a9d30ab82ec8ff190f51c5f4a1c05f93  source/mixed-old.nl
fdee3344122a64ad906abd04725b92cbed29f3d52575104872838777c4d09990  source/scope-escape.nl
6b0519cc4510126a759d25d140aead738cf0e072e663713cbea9cf0e2a5d3369  source/snapshot-high.nl
49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e  source/snapshot-low.nl
ef03900ffa408d84cf254d2f0b6f112c2ad2ffa76f8f81682da63dd93187f5e1  source/snapshot-mixed-reverse.nl
f5a166a1d60282f0a6e04fa7e7fb65d6bf62b2a78520f30cd8498c78fef5472d  source/snapshot-mixed.nl
21211b0c298d15f33b121b7423597e33affa1a5416847993e329583b264cbc97  comparison-c/caller.c
a5ba5139dde34a3b291ef7dfc3573431236be8008724e12f083f027f35a8ec37  comparison-c/queue_writer.c
d01842da9e2a41d60f3df8472a3683665390733e169702486ade7307edddecaa  comparison-c/queue_writer.h
1cf1639f06378a94f0552ffb896e9c0768b39cdd0560c0b92f08cf3f7ca1bb89  freeze_first.py
```

```text
case	bytes	sha256	positions	actual	check	main	compare	candidate	values
complete-snapshot	1161	65135b3f3a79f542e95910e597ba5081b9e3c7f12b0f813bd96454eae0345cc9	11	snapshot	0	4	4	0	4032,35,35,41,35,117,149,35,101
complete-snapshot-low-unit	1170	ab710c9596e63344a0c3867a905a1e4cd67468b8a1549ed97b5808b329a3902b	11	snapshot	0	4	4	0	4032,35,35,41,35,117,149,35,101
complete-snapshot-high	1145	6f201a303683405ffd91a2d7f275d7b6bfed3cdd111492aad5ef275f7e282c2c	00	snapshot	0	4	4	0	4096,93,93,117,93,41,101,93,149
complete-snapshot-high-unit	1154	2f49d8952e0d43c7daf982c7d8cd305275a1c4762b5a5fff6287d40c6bea154d	00	snapshot	0	4	4	0	4096,93,93,117,93,41,101,93,149
snapshot-low	1178	49f8374f3ac4f95390db3f4f72c43ad504627e6c4cd36958f95cea73ea90db2e	11	snapshot	0	0	0	0	4032,35,35,41,35,117,149,35,101
snapshot-high	1162	6b0519cc4510126a759d25d140aead738cf0e072e663713cbea9cf0e2a5d3369	00	snapshot	0	0	0	0	4096,93,93,117,93,41,101,93,149
snapshot-mixed	1179	f5a166a1d60282f0a6e04fa7e7fb65d6bf62b2a78520f30cd8498c78fef5472d	10	snapshot	0	4	0	4	4032,35,35,41,35,117,101,35,149
snapshot-mixed-reverse	1180	ef03900ffa408d84cf254d2f0b6f112c2ad2ffa76f8f81682da63dd93187f5e1	01	snapshot	0	4	0	4	4096,93,93,117,93,41,149,93,101
complete-snapshot-mixed	1162	f8496cd87fd59766d0710c52e3f08592c3e044da5e7070154e97b98c6771f67d	10	snapshot	0	4	4	4	
complete-snapshot-mixed-reverse	1172	705a29dbf881b56d9f7241cef68359181899309d8871f9dc35d4787719de1e7b	01	snapshot	0	4	4	4	
complete-snapshot-stale	1161	5b098818ffe75d844d580150351da2c9d48088cade852193d1fe2d5a982ea559	11	snapshot	0	4	4	4	
complete-snapshot-sibling	1160	0a774b15a68513be41b0c71e131ed056a9e60b4db40f591ee413d7d978d37768	11	snapshot	0	4	4	4	
complete-snapshot-other	1171	64f94403318d730c716375a95e96119173bc2ad7f36482e2cf0361b93a1e0947	11	snapshot	0	4	4	4	
mixed-old	1194	1aad03bdf0e08db344bd989fdab67af0a9d30ab82ec8ff190f51c5f4a1c05f93	10	displaced	0	4	4	4	
scope-escape	340	fdee3344122a64ad906abd04725b92cbed29f3d52575104872838777c4d09990		escape	3	3	3	3	
```

#### source/complete-snapshot.nl

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

#### source/complete-snapshot-low-unit.nl

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
    unit
}
```

#### source/complete-snapshot-high.nl

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
}
```

#### source/complete-snapshot-high-unit.nl

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
    unit
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

#### source/complete-snapshot-mixed.nl

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

#### source/complete-snapshot-mixed-reverse.nl

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
    unit
}
```

#### source/complete-snapshot-stale.nl

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
}
```

#### source/complete-snapshot-sibling.nl

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
}
```

#### source/complete-snapshot-other.nl

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
    unit
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
#ifndef P1806_QUEUE_WRITER_H
#define P1806_QUEUE_WRITER_H

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

This freezes the initial predictions and the bytes for ordinary CLI Gate0.