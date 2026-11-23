cd -- /workspace/p1544-6afecbd5/p1654-bool-only-quantity-gate0
bash -c $'\nset -euo pipefail\n{ printf "%s\\0" build/newlangc; find evidence -type f ! -path "evidence/raw-manifest.*" -print0; } |\nLC_ALL=C sort -z | while IFS= read -r -d "" f; do\n size=$(stat -c %s "$f")\n sum=$(sha256sum "$f")\n printf "%s\\t%s\\t%s\\n" "${sum%% *}" "$size" "$f"\ndone' 
