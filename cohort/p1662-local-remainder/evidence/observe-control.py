import re
import sys
from pathlib import Path

c = Path(sys.argv[1]).read_bytes()
c, count = re.subn(
    rb"^(    return (nl_if_\d+);)$",
    rb'    printf("%zu\\n", \2);\n\1',
    c, flags=re.MULTILINE,
)
assert count == 1
sys.stdout.buffer.write(
    c.replace(b"#include <stdint.h>\n", b"#include <stdint.h>\n#include <stdio.h>\n")
)
