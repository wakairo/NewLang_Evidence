# P1654 private increment predictions

- let-copy is byte-identical to the earlier literal-arm control. The direct-tail variant changes only the placement of the same tail expression.
- Both positive inputs parse, register and CHECK successfully. Each entry owns two separate helper BODY invocations in source order. Each actual is a named Bool Copy. Its exact slot belongs to the fresh formal. Each invocation has a distinct owned result slot and two original normal arms. The conservative checked IF join may be Unknown.
- Stdout and named C17 match. The two direct call sites run exactly once in source order, with true then false, yielding 11 then 19. Pristine executables have empty stdout and exit 0. The output observation only adds two print statements after the existing call assignments.
- inline-actual, local-numerator, and called-from-helper pass CHECK and fail C17 with status 4 and unchanged named output. The original frozen local-numerator arithmetic example remains outside the finite profile.
- OOM predicts one real failed allocation at each helper seal, entry world seal, and C17 staging site in separate attempts. CHECK failures preserve the original context and anchor. C17 failure preserves the output slots. Ordinary retry succeeds through the same owned plan.
