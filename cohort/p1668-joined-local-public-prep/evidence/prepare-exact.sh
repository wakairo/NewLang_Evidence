#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1668-joined-local-public-prep
private=/workspace/p1544-6afecbd5/p1668-joined-local
capture=/workspace/p1544-6afecbd5/p1645-if-arm-direct-actual/evidence/capture-command.sh
formatter=/workspace/p1544-6afecbd5/repo/.deps/toolchains/debian-13-x86_64-7c9921be7919a10d/newlang-llvm-23.1.3-linux-x64/bin/clang-format-23
old_main=55b3d960c585745d9b5b481efee6b41b4403f2be
predecessor=b917e0d5a897ea606002a2813fde42f45b49c859
private_head=6ff3eca9d4a9c205a33cd2bf285b514f1a455475
expected_base_tree=7b73d38b2bbb4274da60dc4726cf8f744150446e
expected_tree=3ba251a35e9c6c24453252df1f72687ec78dd8ff
public_ref=refs/heads/p1668-joined-local-public
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

bash "$capture" "$root/evidence/worktree" git worktree add -b p1668-joined-local-public "$root/repo" "$base"
cd "$root/repo"
bash "$capture" "$root/evidence/apply-fixed" git cherry-pick -x "$private_head"
[[ $(git show -s --format=%P HEAD) == "$base" ]]
[[ $(git show -s --format=%T HEAD) == "$expected_tree" ]]
[[ $(git status --porcelain=v1) == "" ]]
bash "$capture" "$root/evidence/identity" git log -1 --format='%H%n%T%n%P'
bash "$capture" "$root/evidence/public-diff" git diff --full-index --binary "$base" HEAD
cmp "$private/evidence/diff.stdout" "$root/evidence/public-diff.stdout"
[[ $(git diff --name-only "$base" HEAD | wc -l) == 6 ]]
[[ $(wc -c < "$root/evidence/public-diff.stdout") == 22141 ]]
diff_sha=$(sha256sum "$root/evidence/public-diff.stdout" | cut -d ' ' -f 1)
[[ $diff_sha == 3700dc62190e2213b1194edad52604656b491971f2eb9e01a28d9b75a9a52a08 ]]
bash "$capture" "$root/evidence/diff-check" git diff "$base" HEAD --check
bash "$capture" "$root/evidence/formatter" "$formatter" --dry-run --Werror src/usize_addition.c
cat "$root/evidence/identity.stdout"
sha256sum "$root/evidence/public-diff.stdout"
