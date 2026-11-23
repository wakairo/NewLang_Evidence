#!/usr/bin/env bash
set -euo pipefail

root=/workspace/p1544-6afecbd5/p1654-bool-only-quantity-implementation
base=0873819cabd3781582384891fc785d01b700056b
preceding=c602dd2668c0ceb429059e1c647ffc4bfd03e360
head=972a61bc31522cf60d31bb5847e29a3f002e9d9d
previous_ref=refs/heads/p1650-arm-tail-remainder-public
public_ref=refs/heads/p1654-bool-only-quantity-public
shared=src/usize_addition.c

cd "$root/repo"
[[ $(git status --porcelain=v1) == "" ]]
[[ $(git rev-parse HEAD) == "$head" ]]
[[ $(git show -s --format=%P "$head") == "$base" ]]
[[ $(git show -s --format=%P "$preceding") == "$base" ]]
[[ $(git merge-base "$preceding" "$head") == "$base" ]]
git log -1 --format='candidate %H tree %T parents %P' "$head"
git log -1 --format='preceding %H tree %T parents %P' "$preceding"
git log -1 --format='base %H tree %T parents %P' "$base"
git diff --check "$base" "$head"
git diff --check "$base" "$preceding"
diff=$(git diff --full-index --binary "$base" "$head" | sha256sum)
[[ ${diff%% *} == 8d8ead86df726ad0b1c352e03e997264cab850f9ef0bfcf799c2ccd5d00192be ]]
[[ $(git diff --full-index --binary "$base" "$head" | wc -c) == 33852 ]]
[[ $(git diff --name-only "$base" "$head" | wc -l) == 8 ]]
git diff --name-status "$base" "$head"
expected=$(printf '%s\trefs/heads/main\n%s\t%s' "$base" "$preceding" "$previous_ref")
[[ $(git ls-remote origin refs/heads/main "$previous_ref" "$public_ref") == "$expected" ]]
printf '%s\n' "$expected"
test "$(comm -12 <(git diff --name-only "$base" "$head" | sort) <(git diff --name-only "$base" "$preceding" | sort))" = "$shared"
scratch=$(mktemp -d "$root/public-evidence/overlap.XXXXXXXX")
git show "$base:$shared" > "$scratch/base.c"
git show "$head:$shared" > "$scratch/bool.c"
git show "$preceding:$shared" > "$scratch/remainder.c"
git merge-file -p "$scratch/remainder.c" "$scratch/base.c" "$scratch/bool.c" > "$scratch/combined-forward.c"
git merge-file -p "$scratch/bool.c" "$scratch/base.c" "$scratch/remainder.c" > "$scratch/combined-backward.c"
cmp "$scratch/combined-forward.c" "$scratch/combined-backward.c"
printf 'Shared file %s merges identically in both directions; no Git ref or candidate changed.\n' "$shared"
sha256sum "$scratch/combined-forward.c"
