# P1658 frozen oracle

Same named Bool actual source and ordering in four cases. The first Bool is true (80 < 103); the second is false (120 < 103). Local quotients are floor(95/6)=15 and floor(95/8)=11. The original native program has no stdout. The observed program may report 15 then 11 exactly once each without changing the call arguments or control flow.

Fixed 350d20c: local-let and local-discard should parse/register/CHECK and retain genuine bodies and locally valid division events in both normal arms per invocation. Predict the first gap at whole quantity proof; C17/stdout and named should exit 4 and preserve existing file bytes and metadata. Literal and mixed Copy controls should have machine proof, matching named/stdout C17 and native 15 then 11. The mixed control takes the numerator as one more actual.

If a private implementation retains the existing division, origin and result validators, the local-let case should also reach C17/native 15 then 11; test the direct ordinary-main statement placement as the existing consumer as well. The only admitted numerator shape planned is a callee-local immutable literal-initialized usize used by name in direct normal division tails. Aliases, arm-local initializer, nonliteral or zero divisor, remainder and non-Bool shape are outside the new path.
