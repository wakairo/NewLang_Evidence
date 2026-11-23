#!/usr/bin/env bash
set -euo pipefail
cd /workspace/p1544-6afecbd5/p1662-local-remainder
cap=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
build=$1
repo=$2
raw=evidence/$3
local_exit=$4
mkdir -p "$raw"
bash "$cap" "$raw/observe-compile" gcc -std=c17 -pedantic-errors -Wall -Wextra -Werror \
    -I "$repo/include" "$PWD/evidence/observe-owned.c" -L "$build" \
    -Wl,--start-group -lnewlang_semantic -lnewlang_checked -lnewlang_parser \
    -lnewlang_syntax -lnewlang_lexer -lnewlang_diagnostic -lnewlang_source \
    -Wl,--end-group -o "$raw/observe"
for name in local-let local-discard division literals mixed; do
    source=$PWD/evidence/source/$name.nl
    output=$raw/$name.c
    expected=0
    if [[ $name == local-* ]]; then expected=$local_exit; fi
    bash "$cap" "$raw/$name-check" "$build/newlangc" --check "$source"
    bash "$cap" "$raw/$name-owned" "$raw/observe" "$source"
    [[ $(grep -c 'formal_is_actual=1.*body_is_call_result=1' "$raw/$name-owned.stdout") == 2 ]]
    case "$name" in
        division) pattern=DIVISION ;;
        literals) pattern=LITERAL_ARM ;;
        *) pattern=REMAINDER ;;
    esac
    if [[ $pattern == LITERAL_ARM ]]; then
        [[ $(grep -c "$pattern" "$raw/$name-owned.stdout") == 4 ]]
    else
        [[ $(grep -c "$pattern view=1 valid=1.*numerator=83" "$raw/$name-owned.stdout") == 4 ]]
    fi
    if ((expected)); then
        printf '/* Keep existing output. */\nint existing;\n' > "$output"
        bash "$cap" "$raw/$name-before" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' state "$output"
    fi
    status=0
    bash "$cap" "$raw/$name-emit" "$build/newlangc" "$source" || status=$?
    [[ $status == "$expected" ]]
    status=0
    bash "$cap" "$raw/$name-named" "$build/newlangc" --emit-c17-to "$output" "$source" || status=$?
    [[ $status == "$expected" ]]
    if ((expected)); then
        grep -q 'machine_proved=0' "$raw/$name-owned.stdout"
        grep -q 'V1-BACKEND-UNSUPPORTED' "$raw/$name-emit.stderr"
        test ! -s "$raw/$name-emit.stdout"
        bash "$cap" "$raw/$name-after" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' state "$output"
        cmp "$raw/$name-before.stdout" "$raw/$name-after.stdout"
    else
        grep -q 'machine_proved=1' "$raw/$name-owned.stdout"
        cmp "$output" "$raw/$name-emit.stdout"
    fi
    printf '%s CHECK=0 C17=%s\n' "$name" "$expected"
done
