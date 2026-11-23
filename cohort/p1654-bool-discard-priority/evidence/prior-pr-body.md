## Scope

Support one ordinary pure `(bool) -> usize` helper called directly from ordinary `main() -> unit` with a named Bool Copy actual. The helper selects between two normal `usize` literal arms with a Copy of its formal. The IF can be the body tail or feed a single result binding returned by Copy.

The existing caller BODY and result seal tie the exact actual slot to its fresh formal. The existing IF planner validates the original arms and their worlds. C17 reuses the existing renderer with a `_Bool` parameter.

## Observations

- The frozen literal control and direct-tail case reach CHECK, owned validation, and C17. Named and stdout C17 are byte-identical. Strict GCC and Clang at O0 and O2 run the two calls in source order and yield `11`, then `19`.
- The mixed `(usize, bool) -> usize` control has byte-identical owned observations and C17 relative to main. The original local-numerator division case still passes CHECK with valid local observations and stops at C17 with exit 4. An inline Bool actual, a local arithmetic arm, and a call from another helper remain outside this finite profile. Named C17 output is preserved for these refusals.
- Local selected regression: normal 127/127, ASan/LSan 127/127, UBSan 127/127. Observed a real allocation failure at each of the helper result seal, entry result-world seal, and C17 staging. State and output were preserved, and ordinary retry succeeded.

## Evidence

Measured HEAD `972a61bc31522cf60d31bb5847e29a3f002e9d9d`, tree `f84987e8d4c063decc27b9547c570d88d22a2b87`, sole parent and base `0873819cabd3781582384891fc785d01b700056b` (Draft17.38). The 8-path full-index binary diff is 33,852 bytes, SHA-256 `8d8ead86df726ad0b1c352e03e997264cab850f9ef0bfcf799c2ccd5d00192be`. The frozen FIRST, Gate0 and raw records remain available in the receipts. The fixed base also permits independent review of sibling #1653. [Issue #1654](https://github.com/wakairo/NewLang_Compiler/issues/1654) · [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079183947) · [GATE0 FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079252802) · [LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079495869) · [PUBLIC RESUME](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079564605)
