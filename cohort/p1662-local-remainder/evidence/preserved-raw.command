cd -- /workspace/p1544-6afecbd5/p1662-local-remainder
bash -e -c for\ p\ in\ \"\$@\"\;\ do\ \(cd\ \"\$p\"\ \&\&\ awk\ -F\ \"\\t\"\ \'\{print\ \$1\ \"\ \ \"\ \$3\}\'\ evidence/raw-manifest.stdout\ \|\ sha256sum\ -c\ --quiet\)\;\ done preserve /workspace/p1544-6afecbd5/p1658-callee-local-division /workspace/p1544-6afecbd5/p1658-callee-local-division-public-prep 
