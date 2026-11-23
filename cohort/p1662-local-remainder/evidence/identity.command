cd -- /workspace/p1544-6afecbd5/p1662-local-remainder/repo
bash -c git\ log\ -1\ --format=\"%H%n%T%n%P\"\ \&\&\ git\ diff\ --name-status\ HEAD\^\ HEAD\ \&\&\ git\ status\ --porcelain=v1 
