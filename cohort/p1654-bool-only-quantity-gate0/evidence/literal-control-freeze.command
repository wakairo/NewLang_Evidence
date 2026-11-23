cd -- /workspace/p1544-6afecbd5/p1654-bool-only-quantity-gate0/evidence
bash -c $'wc -c source/bool-only-literals.nl literal-control-oracle.md\nsha256sum source/bool-only-literals.nl literal-control-oracle.md\ndiff -u source/bool-only.nl source/bool-only-literals.nl || test "$?" -eq 1' 
