#!/usr/bin/env bash
set -euo pipefail
cd /workspace/p1544-6afecbd5/p1668-joined-local
raw=evidence/native-controls-final
cap=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
clang=/workspace/p1544-6afecbd5/repo/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-23
mkdir -p "$raw"
for name in literal-divide literal-remainder caller-joined; do
    case "$name" in literal-divide) printf "13\n19\n" ;; literal-remainder) printf "6\n2\n" ;; caller-joined) printf "13\n10\n" ;; esac > "$raw/$name-expected.stdout"
    pristine=evidence/base/$name.c
    observed=$raw/$name-observed.c
    bash "$cap" "$raw/$name-instrument" python3 -B evidence/observe-control.py "$pristine"
    cp "$raw/$name-instrument.stdout" "$observed"
    for compiler in /usr/bin/gcc "$clang"; do
        for opt in O0 O2; do
            for input in "$pristine" "$observed"; do
                filename=${input##*/}
                label=$raw/${filename%.c}-${compiler##*/}-$opt
                bash "$cap" "$label-compile" "$compiler" -std=c17 -pedantic-errors -Wall -Wextra -Werror "-$opt" "$input" -o "$label"
                bash "$cap" "$label-run" "$label"
                test ! -s "$label-run.stderr"
                if [[ $input == "$observed" ]]; then
                    cmp "$raw/$name-expected.stdout" "$label-run.stdout"
                else
                    test ! -s "$label-run.stdout"
                fi
            done
        done
    done
    printf '%s strict GCC/Clang O0/O2: ordinary stdout empty, observed predicted order.\n' "$name"
done
