#!/usr/bin/env bash
set -euo pipefail
log=$1
shift
{
  printf 'cd -- %q\n' "$PWD"
  printf '%q ' "$@"
  printf '\n'
} > "$log.command"
code=0
"$@" > "$log.stdout" 2> "$log.stderr" || code=$?
printf '%s\n' "$code" > "$log.status"
exit "$code"
