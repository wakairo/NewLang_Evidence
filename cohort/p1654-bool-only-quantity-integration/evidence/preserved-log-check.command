cd -- /workspace/p1544-6afecbd5/p1654-bool-only-quantity-integration
bash -e -c for\ origin\ in\ \"\$@\"\;\ do\ \(cd\ \"\$origin\"\ \&\&\ awk\ -F\ \"\\t\"\ \'\{print\ \$1\ \"\ \ \"\ \$3\}\'\ evidence/raw-manifest.stdout\ \|\ sha256sum\ -c\ --quiet\)\;\ done origins /workspace/p1544-6afecbd5/p1654-bool-only-quantity-implementation /workspace/p1544-6afecbd5/p1654-bool-only-quantity-gate0 
