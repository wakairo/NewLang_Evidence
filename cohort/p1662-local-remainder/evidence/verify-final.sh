#!/usr/bin/env bash
set -euo pipefail
cd /workspace/p1544-6afecbd5/p1662-local-remainder
cap=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
old=/workspace/p1544-6afecbd5/p1658-callee-local-division-public-prep
build=$PWD/verified-normal-build
bash "$cap" evidence/final-measure bash evidence/measure.sh "$build" "$PWD/repo" final 0
for name in division literals mixed; do
    cmp "evidence/base/$name.c" "evidence/final/$name.c"
    cmp "evidence/base/$name-owned.stdout" "evidence/final/$name-owned.stdout"
done
for name in local-let local-discard; do
    cmp <(sed '/^OWNED /d' "evidence/base/$name-owned.stdout") \
        <(sed '/^OWNED /d' "evidence/final/$name-owned.stdout")
done
legacy=$(find "$old/verified-normal-build/p1654-native" -path '*/local-remainder/source.nl')
test -f "$legacy"
for sample in "$build"/p1654-native/*/local-remainder/source.nl; do
    cmp "$legacy" "$sample"
done
printf 'Old P1658 remainder fixture bytes preserved during refusal-to-success transition.\n'

raw=evidence/final-nearby
mkdir -p "$raw"
for name in wrong-type zero-divisor helper-let; do
    source=$PWD/evidence/source/$name.nl
    check=3
    expected=3
    diagnostic=USIZE-REMAINDER-TYPE
    if [[ $name == zero-divisor ]]; then diagnostic=USIZE-REMAINDER-ZERO; fi
    if [[ $name == helper-let ]]; then
        check=0
        expected=4
        diagnostic=V1-BACKEND-UNSUPPORTED
    fi
    status=0
    bash "$cap" "$raw/$name-check" "$build/newlangc" --check "$source" || status=$?
    [[ $status == "$check" ]]
    status=0
    dest=$raw/$name.c
    printf '/* Existing C17 output. */\nint original;\n' > "$dest"
    bash "$cap" "$raw/$name-before" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' state "$dest"
    bash "$cap" "$raw/$name-named" "$build/newlangc" --emit-c17-to "$dest" "$source" || status=$?
    [[ $status == "$expected" ]]
    grep -q "$diagnostic" "$raw/$name-named.stderr"
    test ! -s "$raw/$name-named.stdout"
    bash "$cap" "$raw/$name-after" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' state "$dest"
    cmp "$raw/$name-before.stdout" "$raw/$name-after.stdout"
    printf '%s CHECK=%s named=%s %s no-clobber=PASS\n' "$name" "$check" "$expected" "$diagnostic"
done
