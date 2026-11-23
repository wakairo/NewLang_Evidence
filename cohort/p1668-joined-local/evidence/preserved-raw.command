cd -- /workspace/p1544-6afecbd5/p1668-joined-local
bash -e -c for\ p\ in\ \"\$@\"\;\ do\ \(cd\ \"\$p\"\ \&\&\ awk\ -F\ \"\\t\"\ \'\{print\ \$1\ \"\ \ \"\ \$3\}\'\ evidence/raw-manifest.stdout\ \|\ sha256sum\ -c\ --quiet\)\;\ done saved /workspace/p1544-6afecbd5/p1662-local-remainder /workspace/p1544-6afecbd5/p1662-local-remainder-public-prep 
