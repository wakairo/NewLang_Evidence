# P1654 priority freeze — call result placement

- Both inputs contain the same pure Bool helper, two named Bool Copies, exactly two calls in source order, and a unit tail. The only difference is where each call result goes.
- In either input the helper condition is true for the first call and false for the second. Observing the existing return immediately before it returns should print 23 then 41 exactly once per call. The pristine executables should exit 0 with empty stdout when emitted.
- Fixed integrated candidate: both parse/register/CHECK and retain their genuine call bodies. Predict machine_proved=1 and C17/named success for let, machine_proved=0 and C17/named exit 4 for discard. The refused named output retains its bytes, inode, permissions and time.
- If the statement checker admits the existing consumed result without weakening custody, the discarded variant should emit C17 with the same two calls in source order, wrap each in void, and preserve the exact let behavior. Inline actual and out-of-profile callees remain refused.
