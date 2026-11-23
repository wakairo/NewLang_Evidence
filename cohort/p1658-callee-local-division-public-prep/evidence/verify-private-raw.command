cd -- /workspace/p1544-6afecbd5/p1658-callee-local-division-public-prep
bash -e -c cd\ \"\$1\"\ \&\&\ awk\ -F\ \"\\t\"\ \'\{print\ \$1\ \"\ \ \"\ \$3\}\'\ evidence/raw-manifest.stdout\ \|\ sha256sum\ -c\ --quiet preserve /workspace/p1544-6afecbd5/p1658-callee-local-division 
