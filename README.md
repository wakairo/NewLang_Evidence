# P1525 C1177 local revalidation evidence

Sole Track P; Issue1525. LOCAL READY / WAIT PUBLICATION, no Compiler push/PR/CI.
Candidate metadata and two original local commits/format-patches/small bundle
recover exact ac6 parent -> integration -> final formatted/documented candidate.
Original P1517 FIRST/RED/80/80/ENV-PARTIAL are unchanged in archive
archive/p1517-c1157-local-20261118 at e46bda3c634dc55d19f5561fb431f56720c87495.

evidence/summary.json records255/320 local,57/64 native,6 logical host sites,
48/48 host fault/retry cases,SDK1/2. All313 metered command records have a
result and raw stdout/stderr; standard compiler-build driver commands are
recorded but the whole build is the charged experimental unit. Separate
CTest/native/named/regression logs and actual emitted C are retained too.
GCC18/18,Clang18/18,ASan18/18,UBSan selected11/11; old selectedCTest3/3.
UBSan host fault tests were not repeated beyond the host-case budget.

This cohort omits reproducible build objects/ELFs and the126MB SDK; those
remain locally retained. SDK trust identity/guard receipt and fixed tooling
commit are recorded. No secrets, credentials, home/env/auth config, or
independent F/R original inputs are included. Eligible P evidence only.

Verify all actual files/modes/blobs using tools/verify_members.py and the
external manifest SHA from Issue1525. tools/replay.py fetches the fixed parent
over HTTPS into a newly created target, applies both patches and compares
trees/files, then verifies exact original raw commit identities via the bundle.
It never runs the compiler/native/CTest/CI. Fresh restore and receipt, not a
successful push alone, establish custody. Keep original P worktrees/evidence.

Technical PASS is finite; no independent review, full LLVM/ordinary CI, adopted
main, Product GO or measured UB-prevention audit-locality benefit is claimed.
