#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1658-callee-local-division-public-prep
private=/workspace/p1544-6afecbd5/p1658-callee-local-division
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
formatter=/workspace/p1544-6afecbd5/repo/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-format-23
old_main=19e14c6b90e38c8d3875966a47a0e443649ab800
predecessor=350d20c7fb781f15d53e599854224aedceba1bc5
private_head=ccdd8d16ca65f5593f7c8b955ec85d360828ea3a
expected_base_tree=8710553227f620ee5fe65423abac0f28f8c9737b
expected_tree=2320df8104003475996e173ccf34ed8e9be5423b
public_ref=refs/heads/p1658-callee-local-division-public
base=$1

cd "$private/repo"
[[ $(git rev-parse HEAD) == "$private_head" ]]
[[ $(git status --porcelain=v1) == "" ]]

bash "$capture" "$root/evidence/accepted-refs" git ls-remote origin refs/heads/main "$public_ref"
[[ $(cat "$root/evidence/accepted-refs.stdout") == "$(printf '%s\trefs/heads/main' "$base")" ]]
bash "$capture" "$root/evidence/fetch-main" git fetch --no-tags --no-write-fetch-head origin refs/heads/main
[[ $(git show -s --format=%P "$base") == "$old_main $predecessor" ]]
[[ $(git show -s --format=%T "$base") == "$expected_base_tree" ]]
[[ $(git show -s --format=%T "$private_head^") == "$expected_base_tree" ]]

bash "$capture" "$root/evidence/worktree" git worktree add -b p1658-callee-local-division-public "$root/repo" "$base"
cd "$root/repo"
bash "$capture" "$root/evidence/apply-fixed" git cherry-pick -x "$private_head"
[[ $(git show -s --format=%P HEAD) == "$base" ]]
[[ $(git show -s --format=%T HEAD) == "$expected_tree" ]]
[[ $(git status --porcelain=v1) == "" ]]
bash "$capture" "$root/evidence/identity" git log -1 --format='%H%n%T%n%P'
bash "$capture" "$root/evidence/public-diff" git diff --full-index --binary "$base" HEAD
cmp "$private/evidence/diff.stdout" "$root/evidence/public-diff.stdout"
[[ $(git diff --name-only "$base" HEAD | wc -l) == 4 ]]
bash "$capture" "$root/evidence/diff-check" git diff "$base" HEAD --check
bash "$capture" "$root/evidence/formatter" "$formatter" --dry-run --Werror src/usize_addition.c
cat "$root/evidence/identity.stdout"
sha256sum "$root/evidence/public-diff.stdout"
