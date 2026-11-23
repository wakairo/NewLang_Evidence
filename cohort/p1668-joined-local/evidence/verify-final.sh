#!/usr/bin/env bash
set -euo pipefail
cd /workspace/p1544-6afecbd5/p1668-joined-local
cap=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
build=$PWD/verified-normal-build
bash "$cap" evidence/final-measure bash evidence/measure.sh "$build" final 0
for name in literal-divide literal-remainder caller-joined; do
    cmp "evidence/base/$name.c" "evidence/final/$name.c"
    cmp "evidence/base/$name-owned.stdout" "evidence/final/$name-owned.stdout"
done
for name in joined-divide joined-divide-discard joined-remainder joined-remainder-discard; do
    cmp <(sed '/^OWNED /d' "evidence/base/$name-owned.stdout") \
        <(sed '/^OWNED /d' "evidence/final/$name-owned.stdout")
done
raw=evidence/final-negative
mkdir -p "$raw"
for f in evidence/negative-source/*.nl; do
    name=${f##*/}
    name=${name%.nl}
    case "$name" in
        missing-prior-arm) code=P13-IF-ELSE ;;
        wrong-bool-actual) code=P3-TYPE-MISMATCH ;;
        wrong-joined-arm) code=P13-IF-RESULT ;;
        zero-divisor) code=USIZE-DIVISION-ZERO ;;
        zero-remainder-divisor) code=USIZE-REMAINDER-ZERO ;;
    esac
    out=$raw/$name
    status=0
    bash "$cap" "$out-check" "$build/newlangc" --check "$f" || status=$?
    [[ $status == 3 ]]
    grep -q "\[$code\]" "$out-check.stderr"
    printf '/* Keep this output. */\nint original;\n' > "$out.c"
    bash "$cap" "$out-before" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' snapshot "$out.c"
    status=0
    bash "$cap" "$out-named" "$build/newlangc" --emit-c17-to "$out.c" "$f" || status=$?
    [[ $status == 3 ]]
    grep -q "\[$code\]" "$out-named.stderr"
    bash "$cap" "$out-after" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' snapshot "$out.c"
    cmp "$out-before.stdout" "$out-after.stdout"
    status=0
    bash "$cap" "$out-absent" "$build/newlangc" --emit-c17-to "$out.absent.c" "$f" || status=$?
    [[ $status == 3 && ! -e $out.absent.c ]]
    printf '%s CHECK=3 %s existing/absent output preserved\n' "$name" "$code"
done
