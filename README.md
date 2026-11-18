# P1517 C1157 frozen local candidate custody

Custody: Compiler Issue1520/C1167, sole Track P. Evidence-only archival ref
archive/p1517-c1157-local-20261118. This is never a Compiler merge branch.
The original local worktree and both original commits are retained by P.

candidate/patches contains the two exact format-patches from fixed P1508
7591848bd7f4bf8967dffd4be8d360e1901a3f06. candidate/p1517-local.bundle
contains the same two original commits with that public parent as prerequisite.
candidate/commits retains original raw commit bytes; candidate/source contains
the actual final24 changed files. Original FIRST/RED/source/oracles, complete
stdout/stderr ledgers, generated C, and receipts are under original/. No SDK,
ELF, object files, whole build trees, credentials or independent R/F originals
are included. Original path/mode/size/SHA provenance is retained.

Historical results: new GCC O0/O2 two sources x H0/H1/H2 =12 native; total
selected guest19/36 with regressions;35 tamper refusals;7 source negatives;
6 logical host OOM selectors/16 fault-retry cases;18 CTests registered/1 run.
P1517 aggregate80/80 is exhausted. Clang/ASan/UBSan/format NOT_RUN. The lock
top-level LLVM version23.1.3 differs from failed Debian legacy clang-23
artifact23.1.2; its three404 requests remain original failures. User later
suggested the existing23.1.3 SDK Release for Debian; no use was measured.
Initial private C compile RED and initial observer preprocessing RED remain
separate from repaired results. Moving the original malformed observer to
history/passive-v1.h.data preserved its bytes. No result is regraded here.

manifest.json lists every payload member, including mode/size/SHA256, except
itself. Its exact SHA256 and the archive commit/tree are recorded in Issue1520.
Verify that SHA from the Issue, then run (from a fresh HTTPS Evidence clone):

  python tools/verify_members.py . MANIFEST_SHA256
  python tools/replay.py . /new/empty/replay-target /outside/replay-receipt.json MANIFEST_SHA256

replay.py fetches the fixed P parent directly over public GitHub HTTPS into
a newly initialized standalone repo, applies the patches in order and checks
implementation tree f0cc19d3540102784c41c25a780ceb19570e5271 and final tree
a0b1fb1be96befe86f5b87bb82daed39017ba213. It checks author/message preservation
and imports the restored bundle to confirm both exact original commit IDs/raw
bytes/parents. No original P Git objects, alternates or shared caches are used.
Only Git reconstruction occurs: compiler/native/build/test/CI are never run.

Custody preserves available evidence; it does not establish soundness, adopted
compiler status, independent safety or Product GO. Author+ordinary-safe caller
UB audit/re-audit locality versus well-factored C remains UNMEASURED. Product
GO624 PAUSED/H1#268 HOLD. Future publication requires separate C release.
