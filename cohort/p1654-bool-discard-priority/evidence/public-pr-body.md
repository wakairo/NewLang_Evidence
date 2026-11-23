## Scope

A pure registered `(bool) -> usize` helper receives a named Bool Copy directly from the top-level block of ordinary `main() -> unit`. The finite helper body copies that formal to choose between two normal `usize` literal arms. The helper's IF can be its body tail or feed a single result binding returned by Copy.

The caller can bind the result with `let result = select(flag);` or discard it with the direct statement `select(flag);`. The new statement path validates the existing ended Copy/Discardable result and then reuses the same registered call, actual/formal and result seal checks. C17 emits the statement with a void cast around the single call. Inline Bool actuals, IF-arm statements, calls from another helper and local-numerator arithmetic in the selector remain outside this profile.

## Observations

- On the fixed integrated candidate `cff254ac14119`, the matched let and discard inputs both passed CHECK and retained the genuine helper bodies. Let emitted C17. Discard failed the complete quantity plan and returned C17 exit 4 while preserving existing named output.
- On `350d20c7fb78`, both inputs emit identical named/stdout C17 for their respective shapes. The old let C17 is byte-identical. Strict GCC and Clang at O0/O2 observe 23 then 41 exactly once per call. Adjacent inline and IF-arm statement variants still pass CHECK and reject C17 without clobbering named output.
- Selected normal, ASan/LSan and UBSan each pass 128/128. The new discard regression reaches OOM at helper result sealing, entry result-world sealing and C17 staging, preserving state and output and passing ordinary retry. The earlier let, mixed and adopted remainder regressions remain in the selected tests.

## Evidence

HEAD `350d20c7fb781f15d53e599854224aedceba1bc5`, tree `8710553227f620ee5fe65423abac0f28f8c9737b`, sole parent `cff254ac141194318b2b5b5f11ceb3a2a1b91e06`, base `19e14c6b90e38c8d3875966a47a0e443649ab800` (Draft17.38). Base-to-HEAD 9-path full-index binary diff: 40,336 bytes, SHA-256 `e0bb5e2b1e47f782421331180221b0f653dae7427e126a7d138582a77d108a18`. The original FIRST/Gate0 and the old head's tests and natural CI retain their own identities. [Issue #1654](https://github.com/wakairo/NewLang_Compiler/issues/1654) · [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079183947) · [Original GATE0](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079252802) · [Integrated cff254a handoff](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079720479) · [Priority ACTUAL RESUME](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7087019265)
