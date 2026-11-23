## Scope

Allow an ordinary pure `(bool) -> usize` selector to use one immutable, literal-initialized local `usize` as the numerator in both normal arms of its direct IF tail. Each arm uses a named Copy of that same local and a fixed nonzero `usize` literal divisor. A named Bool Copy is passed directly from the ordinary `main` block. The caller can bind the result or discard it as a direct statement.

The private planner verifies the local source binding, each arm's typed Copy and existing division proof, the original BODY and ARM worlds, exact actual/formal binding, and the existing result seal. The existing C17 renderer emits the division. The change adds no public API, schema, or issuer.

The supported shape uses a direct IF tail. A separate binding for the IF result within the helper, a numerator alias or an arm-local numerator, and remainder are outside this increment. A mixed `(usize, bool) -> usize` helper can still receive the numerator as a caller argument. Literal-result arms remain available when the division itself is unnecessary.

## Evidence

- Fixed pre-adoption dependency `350d20c7fb78`: both local cases passed CHECK and the public ARM division validator, then exited C17 with status 4 while preserving existing named output. The literal and mixed controls reached C17 and native.
- Private measured tree `2320df8104003475996e173ccf34ed8e9be5423b`: both local placements reached C17 with identical stdout and named output. Strict GCC and Clang O0/O2 observed 15 then 11 once each. Pristine executables exited 0 with empty stdout. The literal and mixed controls retained the same owned observations and C17 bytes.
- Selected tests on that tree: normal 129/129, ASan/LSan 129/129, UBSan 129/129. Three OOM sites reached with rollback, output preservation, and ordinary retry. Type, zero-divisor, alias, arm-local and remainder rejections preserved existing named output.

[Issue #1658](https://github.com/wakairo/NewLang_Compiler/issues/1658) · [Frozen inputs and predictions](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087196412) · [Private LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087281069)
