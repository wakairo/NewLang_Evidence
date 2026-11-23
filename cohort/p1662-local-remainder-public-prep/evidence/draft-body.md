## Scope

Support fixed nonzero `usize` remainder in the two normal arms of a unary Bool selector's direct IF tail. Both arms read the same immutable, literal-initialized callee-local `usize` by named Copy. Ordinary `main()` passes a named Bool Copy directly and can bind the result or discard it as a statement.

The private planner reuses the existing source, local binding, BODY/ARM, typed operands, nonzero divisor, actual/formal and result seal validation. Existing C17 emission is reused. The two arms use the same operator. The prior division profile remains covered. Mixed arm operators, aliases, arm-local initialization and a separate binding for the helper's IF result remain outside this increment. Passing the numerator through the mixed Copy signature and using literal result arms remain available alternatives.

## Evidence

- Fixed `1e6ec2206a4e`: both local remainder forms passed CHECK and the public ARM remainder validator, then rejected C17 with exit 4 and preserved named output. Division, literal and mixed controls reached native.
- Exact public `b917e0d5a897ea606002a2813fde42f45b49c859`: both caller placements emit the same bytes through stdout and named C17 for their respective forms. Strict GCC and Clang at O0/O2 observe `6`, then `3` once each. Pristine executables exit 0 with empty stdout. The unchanged prior remainder fixture reaches `5`, then `7`.
- Selected normal, ASan/LSan and UBSan each pass 130/130. Three OOM sites reached, with rollback, output preservation and successful retry. Near-profile refusals preserve named output.

Tree `7b73d38b2bbb4274da60dc4726cf8f744150446e`. Sole parent and base `55b3d960c585745d9b5b481efee6b41b4403f2be` (Draft17.38). The four-path full-index binary diff is byte-identical to the measured private change, 9,271 bytes, SHA-256 `6a87e299a07e2c4d5b76e485a5c094a6365b36313f938a0f5b63c1bdbfe84b3b`. [Issue #1662](https://github.com/wakairo/NewLang_Compiler/issues/1662) · [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7087797422) · [LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7087852397) · [PUBLIC ACTUAL](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7088195628)
