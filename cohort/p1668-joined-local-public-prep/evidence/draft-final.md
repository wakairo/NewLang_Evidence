## Scope

Support fixed nonzero `usize` division or remainder in an ordinary unary Bool selector after a genuine helper-local IF join. An initial IF on the named Bool formal has two normal literal `usize` tails and binds the joined value once. The subsequent direct IF tail reads the same Bool formal and uses a named Copy of that exact joined local as the numerator in both normal arms. Both arms use the same operator. A direct call from ordinary `main` passes a named Bool Copy. The caller may bind or directly discard the result.

The private planner checks the original binding symbol, value slot, and place against the retained arm worlds, with the existing source, BODY, ARM, actual/formal, arithmetic and result seal validation. Existing C17 emission is reused. Mixed operators, aliases, other or arm-local numerators, and wider IF shapes remain outside this increment. The literal-local profile and the mixed signature with a caller-joined numerator remain available alternatives.

## Frozen evidence

- Fixed `b917e0d5a897`: the four joined-local forms passed CHECK and the genuine ARM arithmetic validators. The complete quantity plan rejected C17 with status 4. Existing output bytes and metadata were preserved and absent targets stayed absent.
- Measured private tree `3ba251a35e9c6c24453252df1f72687ec78dd8ff`: both caller placements emitted matching stdout and named C17. Strict GCC and Clang at O0/O2 observed division `13`, then `10`, and remainder `6`, then `4`, once each. Pristine runs exited 0 with empty stdout. The literal-local and caller-joined controls kept their owned observations and generated C bytes.
- Selected normal, ASan/LSan and UBSan each passed 132/132 on that tree. Six allocation failure sites per operator preserved state or output and allowed normal retry. Near-profile refusals preserved existing and absent output targets.
- The fixed private candidate is `6ff3eca9d4a9c205a33cd2bf285b514f1a455475`. Its six-path full-index binary diff is 22,141 bytes, SHA-256 `3700dc62190e2213b1194edad52604656b491971f2eb9e01a28d9b75a9a52a08`.

[Issue #1668](https://github.com/wakairo/NewLang_Compiler/issues/1668) · [ACTUAL START / FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088522329) · [Private LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088645033)

Public candidate `f1f394d2e84621f70264965b92b3851c359249a6` has sole parent and base `5299ef4da6d45909abef6a0bebaa514d2e4c5ad0` (Draft17.38). Its tree and full-index binary patch match the measured private candidate byte for byte. Selected normal, ASan/LSan and UBSan passed 132/132 each on the exact public candidate, including rollback, existing and absent output preservation, and strict native results for both caller placements. [PUBLIC ACTUAL](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088882351)
