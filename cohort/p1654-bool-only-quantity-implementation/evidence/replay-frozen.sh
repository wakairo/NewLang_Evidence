#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1654-bool-only-quantity-implementation
gate=/workspace/p1544-6afecbd5/p1654-bool-only-quantity-gate0/evidence
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
build=$root/verified-normal-build
raw=$root/evidence/frozen-replay
mkdir -p "$raw"
bash "$capture" "$raw/observer-compile" gcc -std=c17 -pedantic-errors \
    -Wall -Wextra -Werror -I "$root/repo/include" "$gate/observe-owned.c" \
    -L "$build" -Wl,--start-group -lnewlang_semantic -lnewlang_checked \
    -lnewlang_parser -lnewlang_syntax -lnewlang_lexer -lnewlang_diagnostic \
    -lnewlang_source -Wl,--end-group -o "$raw/observe-owned"

for label in bool-only-literals bool-only mixed-copy direct-tail; do
    source=$gate/source/$label.nl
    if [[ $label == direct-tail ]]; then
        source=$root/evidence/new-first/direct-tail.nl
    fi
    bash "$capture" "$raw/$label-check" "$build/newlangc" --check "$source"
    bash "$capture" "$raw/$label-owned" "$raw/observe-owned" "$source"
    expect=0
    file=$raw/$label.c
    if [[ $label == bool-only ]]; then
        expect=4
        printf '/* Existing named output. */\nint original;\n' > "$file"
        bash "$capture" "$raw/$label-before" bash -c 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' state "$file"
    fi
    status=0
    bash "$capture" "$raw/$label-emit" "$build/newlangc" "$source" || status=$?
    [[ $status == "$expect" ]]
    status=0
    bash "$capture" "$raw/$label-named" "$build/newlangc" --emit-c17-to "$file" "$source" || status=$?
    [[ $status == "$expect" ]]
    if [[ $expect == 0 ]]; then
        cmp "$raw/$label-emit.stdout" "$file"
    else
        bash "$capture" "$raw/$label-after" bash -c 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' state "$file"
        cmp "$raw/$label-before.stdout" "$raw/$label-after.stdout"
        grep -q 'machine_proved=0' "$raw/$label-owned.stdout"
        [[ $(grep -c 'DIVISION view=1 valid=1' "$raw/$label-owned.stdout") == 4 ]]
        continue
    fi
    grep -q 'machine_proved=1' "$raw/$label-owned.stdout"
    [[ $(grep -c 'formal_is_actual=1.*body_is_call_result=1' "$raw/$label-owned.stdout") == 2 ]]
done
cmp "$raw/mixed-copy.c" "$root/evidence/base/mixed-copy-emit.stdout"
cmp "$raw/mixed-copy-owned.stdout" "$root/evidence/base/mixed-copy-owned.stdout"
