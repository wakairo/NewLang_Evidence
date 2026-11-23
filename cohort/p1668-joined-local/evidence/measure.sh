#!/usr/bin/env bash
set -euo pipefail
cd /workspace/p1544-6afecbd5/p1668-joined-local
cap=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
build=$1
raw=evidence/$2
joined=$3
mkdir -p "$raw"
bash "$cap" "$raw/observe-compile" gcc -std=c17 -pedantic-errors -Wall -Wextra -Werror \
    -I repo/include evidence/observe-owned.c -L "$build" -Wl,--start-group \
    -lnewlang_semantic -lnewlang_checked -lnewlang_parser -lnewlang_syntax \
    -lnewlang_lexer -lnewlang_diagnostic -lnewlang_source -Wl,--end-group -o "$raw/observe"
for name in joined-divide joined-divide-discard joined-remainder joined-remainder-discard literal-divide literal-remainder caller-joined; do
    source=$PWD/evidence/source/$name.nl
    dest=$raw/$name.c
    status=0
    expected=0
    if [[ $name == joined-* ]]; then expected=$joined; fi
    if [[ $2 != base ]]; then
        bash "$cap" "$raw/$name-check" "$build/newlangc" --check "$source"
        bash "$cap" "$raw/$name-emit" "$build/newlangc" "$source" || status=$?
        [[ $status == "$expected" ]]
    fi
    [[ $(cat "$raw/$name-check.status") == 0 && $(cat "$raw/$name-emit.status") == "$expected" ]]
    bash "$cap" "$raw/$name-owned" "$raw/observe" "$source"
    [[ $(grep -c 'formal_is_actual=1.*body_is_call_result=1' "$raw/$name-owned.stdout") == 2 ]]
    if [[ $name == joined-* ]]; then
        [[ $(grep -c 'JOINED_NUMERATOR.*unknown=1' "$raw/$name-owned.stdout") == 4 ]]
        [[ $(grep -c 'view=1 valid=1 original_arm=1 numerator_known=0' "$raw/$name-owned.stdout") == 4 ]]
    fi
    if ((expected)); then
        grep -q 'machine_proved=0' "$raw/$name-owned.stdout"
        printf '/* Keep existing file. */\nint sentinel;\n' > "$dest"
        bash "$cap" "$raw/$name-before" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' snapshot "$dest"
    else
        grep -q 'machine_proved=1' "$raw/$name-owned.stdout"
    fi
    status=0
    bash "$cap" "$raw/$name-named" "$build/newlangc" --emit-c17-to "$dest" "$source" || status=$?
    [[ $status == "$expected" ]]
    if ((expected)); then
        bash "$cap" "$raw/$name-after" bash -ec 'stat --printf="%d %i %f %s %y %z\n" "$1"; sha256sum "$1"' snapshot "$dest"
        cmp "$raw/$name-before.stdout" "$raw/$name-after.stdout"
        status=0
        bash "$cap" "$raw/$name-absent" "$build/newlangc" --emit-c17-to "$dest.absent" "$source" || status=$?
        [[ $status == "$expected" && ! -e $dest.absent ]]
    else
        cmp "$dest" "$raw/$name-emit.stdout"
    fi
    printf '%s CHECK=0 C17=%s\n' "$name" "$expected"
done
