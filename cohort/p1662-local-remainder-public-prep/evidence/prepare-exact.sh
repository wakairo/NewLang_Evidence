#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1662-local-remainder-public-prep
private=/workspace/p1544-6afecbd5/p1662-local-remainder
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
formatter=/workspace/p1544-6afecbd5/repo/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-format-23
old_main=b11e8b9a960fc8c5f253c9906ebf5f02c471c022
predecessor=1e6ec2206a4ea891f50b903cf728a65789f41310
private_head=4b24d2f354de4fa0d0c479825df688e41a30c634
expected_base_tree=2320df8104003475996e173ccf34ed8e9be5423b
expected_tree=7b73d38b2bbb4274da60dc4726cf8f744150446e
public_ref=refs/heads/p1662-local-remainder-public
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

bash "$capture" "$root/evidence/worktree" git worktree add -b p1662-local-remainder-public "$root/repo" "$base"
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
