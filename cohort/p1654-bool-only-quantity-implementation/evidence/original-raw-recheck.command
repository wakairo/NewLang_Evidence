cd -- /workspace/p1544-6afecbd5/p1654-bool-only-quantity-implementation
bash -c cd\ \"\$1\"\ \&\&\ awk\ -F\ \"\\t\"\ \'\{print\ \$1\ \"\ \ \"\ \$3\}\'\ evidence/raw-manifest.stdout\ \|\ sha256sum\ -c gate /workspace/p1544-6afecbd5/p1654-bool-only-quantity-gate0 
