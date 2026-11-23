#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1654-bool-discard-priority
gate=/workspace/p1544-6afecbd5/p1654-bool-only-quantity-gate0
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
build=$1
repository=$2
label=$3
discard_status=$4
raw=$root/evidence/$label
mkdir -p "$raw"
bash "$capture" "$raw/observer-compile" gcc -std=c17 -pedantic-errors \
    -Wall -Wextra -Werror -I "$repository/include" "$gate/evidence/observe-owned.c" \
    -L "$build" -Wl,--start-group -lnewlang_semantic -lnewlang_checked \
    -lnewlang_parser -lnewlang_syntax -lnewlang_lexer -lnewlang_diagnostic \
    -lnewlang_source -Wl,--end-group -o "$raw/observe-owned"

for place in let discard; do
    source=$root/evidence/source/$place.nl
    dest=$raw/$place.c
    expect=0
    if [[ $place == discard ]]; then expect=$discard_status; fi
    bash "$capture" "$raw/$place-check" "$build/newlangc" --check "$source"
    bash "$capture" "$raw/$place-owned" "$raw/observe-owned" "$source"
    [[ $(grep -c 'formal_is_actual=1.*body_is_call_result=1' "$raw/$place-owned.stdout") == 2 ]]
    if ((expect != 0)); then
        printf '/* Protect existing output. */\nint existing;\n' > "$dest"
        bash "$capture" "$raw/$place-before" bash -e -c \
            'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' inspect "$dest"
    fi
    status=0
    bash "$capture" "$raw/$place-emit" "$build/newlangc" "$source" || status=$?
    [[ $status == "$expect" ]]
    status=0
    bash "$capture" "$raw/$place-named" "$build/newlangc" --emit-c17-to "$dest" "$source" || status=$?
    [[ $status == "$expect" ]]
    if ((expect == 0)); then
        cmp "$dest" "$raw/$place-emit.stdout"
        grep -q 'machine_proved=1' "$raw/$place-owned.stdout"
    else
        test ! -s "$raw/$place-emit.stdout"
        grep -q 'V1-BACKEND-UNSUPPORTED' "$raw/$place-emit.stderr"
        grep -q 'machine_proved=0' "$raw/$place-owned.stdout"
        bash "$capture" "$raw/$place-after" bash -e -c \
            'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' inspect "$dest"
        cmp "$raw/$place-before.stdout" "$raw/$place-after.stdout"
    fi
    printf '%s CHECK=0 C17=%s\n' "$place" "$expect"
done
