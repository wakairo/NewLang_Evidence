cd -- /workspace/p1544-6afecbd5/p1662-local-remainder
bash -e -c awk\ -F\ \"\\t\"\ \'\{print\ \$1\ \"\ \ \"\ \$3\}\'\ evidence/raw-manifest.stdout\ \|\ sha256sum\ -c\ --quiet 
