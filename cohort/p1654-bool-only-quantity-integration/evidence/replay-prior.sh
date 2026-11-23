#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1654-bool-only-quantity-integration
old=/workspace/p1544-6afecbd5/p1654-bool-only-quantity-implementation
preceding=/workspace/p1544-6afecbd5/p1650-arm-tail-remainder
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
clang=/workspace/p1544-6afecbd5/repo/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-23
build=$root/verified-normal-build
raw=$root/evidence/preceding-replay
mkdir -p "$raw"

for family in tail-direct tail-named; do
    source=$preceding/evidence/source/$family.nl
    named=$raw/$family.c
    bash "$capture" "$raw/$family-check" "$build/newlangc" --check "$source"
    bash "$capture" "$raw/$family-emit" "$build/newlangc" "$source"
    bash "$capture" "$raw/$family-named" "$build/newlangc" --emit-c17-to "$named" "$source"
    cmp "$named" "$raw/$family-emit.stdout"
    cmp "$named" "$preceding/evidence/normal/$family.c"
    bash "$capture" "$raw/$family-instrument" python3 -B \
        "$preceding/evidence/observe-native.py" "$named"
    for compiler in /usr/bin/gcc "$clang"; do
        for opt in O0 O2; do
            for kind in pristine observed; do
                input=$named
                if [[ $kind == observed ]]; then input=$raw/$family-instrument.stdout; fi
                label=$raw/$family-${compiler##*/}-$opt-$kind
                bash "$capture" "$label-compile" "$compiler" -std=c17 \
                    -pedantic-errors -Wall -Wextra -Werror "-$opt" -x c "$input" -o "$label"
                bash "$capture" "$label-run" "$label"
                if [[ $kind == observed ]]; then
                    cmp "$preceding/evidence/native-expected.stdout" "$label-run.stdout"
                else
                    test ! -s "$label-run.stdout"
                fi
            done
        done
    done
    printf '%s retains adopted C17 bytes and strict GCC/Clang O0/O2 results.\n' "$family"
done

bash "$capture" "$raw/fault-compile" /usr/bin/gcc -std=c17 \
    -pedantic-errors -Wall -Wextra -Werror -I "$root/repo/include" -I "$root/repo/src" \
    "$preceding/evidence/observe-fault.c" -L "$build" \
    -Wl,--wrap=malloc -Wl,--wrap=nl_h_custody_seal_result -Wl,--start-group \
    -lnewlang_checked_c_node -lnewlang_semantic -lnewlang_checked -lnewlang_parser \
    -lnewlang_syntax -lnewlang_lexer -lnewlang_diagnostic -lnewlang_source \
    -Wl,--end-group -o "$raw/fault-probe"
legacy=$(find "$preceding/evidence/base/legacy-scope-raw" -type f -name remainder.nl)
test -f "$legacy"
bash "$capture" "$raw/identity" "$raw/fault-probe" identity \
    "$preceding/evidence/source/known-both-remainder.nl"
bash "$capture" "$raw/rollback" "$raw/fault-probe" rollback "$legacy"

for label in bool-only-literals bool-only mixed-copy direct-tail; do
    for metric in check.status owned.stdout emit.status emit.stdout named.status; do
        cmp "$root/evidence/frozen-replay/$label-$metric" \
            "$old/evidence/frozen-replay/$label-$metric"
    done
    printf '%s matches the CHECK, owned and C17 replay from the old Bool candidate.\n' "$label"
done
