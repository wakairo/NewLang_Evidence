"""Observe argument values, selected arms, and original C17 bindings."""

from pathlib import Path
import re
import sys


def instrument(pristine):
    lines = pristine.splitlines(keepends=True)
    inserts = {}

    def one(pattern):
        matches = [(i, m) for i, line in enumerate(lines) if (m := re.fullmatch(pattern, line))]
        assert len(matches) == 1, pattern
        return matches[0]

    i, _ = one(r"#include <stdint.h>\n")
    inserts[i] = "#include <stdio.h>\n"
    i, formals = one(r"static size_t nl_qty_fn_10\(size_t (nl_local_\d+), _Bool (nl_local_\d+)\)\n")
    assert lines[i+1] == "{\n"
    inserts[i+1] = f'    printf("actual=%zu/%u\\n", {formals[1]}, (unsigned){formals[2]});\n'
    i, _ = one(r"    if \(nl_condition_3\) \{\n")
    inserts[i] = '        puts("arm=then");\n'
    alt, _ = one(r"    \} else \{\n")
    inserts[alt] = '        puts("arm=else");\n'
    assert " / ((size_t)UINTMAX_C(7))" in lines[i+1]
    assert " / ((size_t)UINTMAX_C(4))" in lines[alt+1]

    calls = []
    for i, line in enumerate(lines):
        m = re.fullmatch(r"    size_t (nl_local_\d+) = nl_qty_fn_10\(nl_actual_(\d+)_0, nl_actual_\2_1\);\n", line)
        if m:
            assert re.fullmatch(rf"    size_t nl_actual_{m[2]}_0 = nl_local_\d+;\n", lines[i-2])
            assert re.fullmatch(rf"    _Bool nl_actual_{m[2]}_1 = nl_local_\d+;\n", lines[i-1])
            inserts[i] = f'    printf("result=%zu\\n", {m[1]});\n'
            calls.append(i)
    assert len(calls) == 2

    out, indices = [], set()
    for i, line in enumerate(lines):
        out.append(line)
        if i in inserts:
            indices.add(len(out))
            out.append(inserts[i])
    assert len(indices) == len(inserts)
    assert "".join(line for i, line in enumerate(out) if i not in indices) == pristine
    return "".join(out)


if __name__ == "__main__":
    print(instrument(Path(sys.argv[1]).read_text(encoding="ascii")), end="")
