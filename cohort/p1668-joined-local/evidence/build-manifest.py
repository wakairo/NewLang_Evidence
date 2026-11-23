import hashlib
from pathlib import Path


def emit(path):
    payload = path.read_bytes()
    print(f"{hashlib.sha256(payload).hexdigest()}\t{len(payload)}\t{path}")


files = [
    Path("base-build/newlangc"),
    Path("smoke-build/newlangc"),
    *Path("evidence").rglob("*"),
]
for cfg in ("normal", "asan", "ubsan"):
    root = Path(f"verified-{cfg}-build")
    files.extend((root / "newlangc", root / "p1654_probe"))
    files.extend((root / "p1654-native").rglob("*"))
for path in sorted(files):
    if path.is_file() and not path.name.startswith(("raw-manifest.", "local-final.")):
        emit(path)
