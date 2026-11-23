#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1654-bool-discard-priority
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
clang=/workspace/p1544-6afecbd5/repo/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-23
cd "$root"
raw=$root/evidence/native-placement
mkdir -p "$raw"
printf '23\n41\n' > "$raw/predicted.stdout"
cmp evidence/fixed-cff/let.c evidence/final-local/let.c
for case in fixed-cff/let final-local/let final-local/discard; do
    c=$root/evidence/$case.c
    name=${case//\//-}
    observed=$raw/$name-observed.c
    bash "$capture" "$raw/$name-instrument" python3 -B -c \
        'import runpy, sys; from pathlib import Path; source=Path(sys.argv[1]); sys.stdout.buffer.write(runpy.run_path("repo/tests/p1654/run.py")["observe"](source.read_bytes(), source.stem == "discard"))' "$c"
    cp "$raw/$name-instrument.stdout" "$observed"
    for compiler in /usr/bin/gcc "$clang"; do
        for opt in O0 O2; do
            for kind in pristine observed; do
                input=$c
                if [[ $kind == observed ]]; then input=$observed; fi
                label=$raw/$name-${compiler##*/}-$opt-$kind
                bash "$capture" "$label-compile" "$compiler" -std=c17 \
                    -pedantic-errors -Wall -Wextra -Werror "-$opt" "$input" -o "$label"
                bash "$capture" "$label-run" "$label"
                test ! -s "$label-run.stderr"
                if [[ $kind == observed ]]; then
                    cmp "$raw/predicted.stdout" "$label-run.stdout"
                else
                    test ! -s "$label-run.stdout"
                fi
            done
        done
    done
    printf '%s strict GCC/Clang O0/O2: 23 then 41 exactly once; pristine exit 0.\n' "$case"
done
