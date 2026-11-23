#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1658-callee-local-division-public-prep
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
toolchain=/workspace/p1544-6afecbd5/repo/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin
cmake_dir=/workspace/newlang-tools/lib/python3.12/site-packages/cmake/data/bin
cfg=$1
build_jobs=$2
test_jobs=$3
label=${4:-cohort}
evidence=$root/evidence/$cfg
build=$root/verified-$cfg-build
mkdir -p "$evidence"
export PATH="$toolchain:$PATH"
case "$cfg" in
    normal) host=/usr/bin/gcc; sanitizer=none ;;
    asan) host=$toolchain/clang-23; sanitizer=address ;;
    ubsan) host=$toolchain/clang-23; sanitizer=undefined ;;
    *) exit 2 ;;
esac

cohort='^(p(1544|1549|1554|1561|1567|1572|1579|1587|1592|1596|1598|1605|1615|1623|1628|1632|1638|1643|1645|1654|1658|634|605)_).*'
bash "$capture" "$evidence/$label-configure" "$cmake_dir/cmake" -S "$root/repo" -B "$build" \
    -DNEWLANG_FRONTEND_ONLY=ON -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Debug \
    "-DCMAKE_C_COMPILER=$host" "-DNEWLANG_SANITIZER=$sanitizer"
bash "$capture" "$evidence/$label-build" "$cmake_dir/cmake" --build "$build" --parallel "$build_jobs" \
    --target newlangc p1544_probe p1549_probe p1554_probe p1561_probe \
    p1567_probe p1572_probe p1579_probe p1587_probe p1592_probe p1596_probe \
    p1598_probe p1605_probe p1615_probe p1623_probe p1628_probe p1632_probe \
    p1638_probe p1643_probe p1645_probe p1654_probe p634_ended_root_gate p605_public_probe
bash "$capture" "$evidence/$label-test" env ASAN_OPTIONS=detect_leaks=1:halt_on_error=1 \
    UBSAN_OPTIONS=halt_on_error=1:print_stacktrace=1 "$cmake_dir/ctest" --test-dir "$build" \
    --no-tests=error --output-on-failure -V -j "$test_jobs" -R "$cohort"
tail -10 "$evidence/$label-test.stdout"
