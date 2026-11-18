# NewLang Evidence

Public, Git-native development evidence. This repository's `main` is a small
index; original evidence is kept in append-only archive refs with fixed commits,
per-member manifests, and restoration receipts.

## Current evidence archives

- **P1499 / C1127 — canonical original evidence:** [archive/p1499-c1127-20261118](https://github.com/wakairo/NewLang_Evidence/tree/archive/p1499-c1127-20261118), fixed verified commit `546b3f18d9d01ce087bc83179770008011455ebe` / tree `9d4eaac1bdaf5911b83845eee3834ced6fff6ffe`. The `p1499/` cohort contains **23,814 individual files / 832,993,112 bytes**. Its [full fresh-clone restoration receipt](https://github.com/wakairo/NewLang_Compiler/issues/1513#issuecomment-6969549328) verifies paths, sizes, SHA-256, Git executable modes, and 16 source snapshots; see `provenance/` for original-member and tar-mode metadata.
- **P1507 / C1137 — current original development evidence:** [archive/p1507-20261118](https://github.com/wakairo/NewLang_Evidence/tree/archive/p1507-20261118), fixed verified commit `d5d5004c38d6779f2f5965b5929192fb83f2f60b`. The original real P FIRST/RED, native and six CI job logs were [restored and verified](https://github.com/wakairo/NewLang_Compiler/issues/1507#issuecomment-6967835791).

## Superseded P1499 LFS transport archive

After verified migration, the original P1499 compressed Git LFS archive is **no
longer a current authoritative copy**. At the owner's request to avoid two
competing sources of truth, the redundant current-tip LFS pointer was deleted
from Compiler's data-only `archive/track-p-evidence-20261117` branch in
[commit `88ffe7dca1ede7d80ea43cfb3af537b5addaaf26`](https://github.com/wakairo/NewLang_Compiler/commit/88ffe7dca1ede7d80ea43cfb3af537b5addaaf26).
The branch was retained because it also contains **other distinct historical
evidence**. Its P1499 `STORAGE-RECEIPT.json` is unchanged; a
`CANONICAL-EVIDENCE.md` redirect now points to the Evidence archive.

The historical 292,528,339-byte LFS object's SHA-256 is recorded in
[Issue #1499](https://github.com/wakairo/NewLang_Compiler/issues/1499#issuecomment-6950223019).
Deleting the pointer from the active branch does **not** rewrite its historical
commit or purge its GitHub LFS object/quota. Extracted files preserve original
member bytes and provenance, not the exact old compressed tar.gz byte sequence.

## Retired synthetic pilot

The synthetic C1134 pilot branch `archive/pilot-c1134-20261118` **was deleted**
after its historical results were recorded in
[Issue #1505](https://github.com/wakairo/NewLang_Compiler/issues/1505#issuecomment-6965521070).
Its former tip was `65cf7cbf98479e7e0524fca609d3b85bb882ecac`
(parent `0b864636c66c60b00f32a1ce7af1a9f273148084`). No ref/tag preserves
that synthetic tree, and its blobs may cease to be independently fetchable
after GitHub garbage collection. This is not a real P or compiler safety PASS.

The [adopted archive and disk policy](https://github.com/wakairo/NewLang_Compiler/blob/main/docs/NewLang_Evidence_Archive_and_Codex_Cloud_Disk_Policy.md)
governs future evidence capture, verification, and cleanup.
