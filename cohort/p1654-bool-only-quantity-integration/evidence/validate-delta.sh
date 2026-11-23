#!/usr/bin/env bash
set -euo pipefail

base=0873819cabd3781582384891fc785d01b700056b
old=972a61bc31522cf60d31bb5847e29a3f002e9d9d
main=19e14c6b90e38c8d3875966a47a0e443649ab800
candidate=cff254ac141194318b2b5b5f11ceb3a2a1b91e06
shared=src/usize_addition.c

[[ $(git rev-parse HEAD) == "$candidate" ]]
[[ $(git show -s --format=%P "$candidate") == "$old $main" ]]
[[ $(git status --porcelain=v1) == "" ]]
cmp <(git diff --name-status "$base" "$old") <(git diff --name-status "$main" "$candidate")
cmp <(git diff --name-status "$base" "$main") <(git diff --name-status "$old" "$candidate")
cmp <(git diff "$base" "$old" -- . ":(exclude)$shared") \
    <(git diff "$main" "$candidate" -- . ":(exclude)$shared")
cmp <(git diff "$base" "$main" -- . ":(exclude)$shared") \
    <(git diff "$old" "$candidate" -- . ":(exclude)$shared")

payload() {
    git diff --no-ext-diff -U0 "$1" "$2" -- "$shared" |
        awk '/^@@/{inside=1; next} inside && /^[+-]/{print}'
}
cmp <(payload "$base" "$old") <(payload "$main" "$candidate")
cmp <(payload "$base" "$main") <(payload "$old" "$candidate")

merged_sha=$(git show "$candidate:$shared" | sha256sum)
[[ ${merged_sha%% *} == 3685d4aefa1961fcd49c4e14c1c94d8800a5e0a321a5db3361ef317f2b44b8c0 ]]
printf 'Both directional delta payloads match, including the shared file.\n'
printf '%s\n' "$merged_sha"
