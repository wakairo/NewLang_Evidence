## P1668 LOCAL FINAL · STOP C

既存 sole Track P。固定した未採用依存 `b917e0d5a897ea606002a2813fde42f45b49c859`／tree `7b73d38b2bbb4274da60dc4726cf8f744150446e` を別 private checkout の基点とした。実 main `55b3d960c585745d9b5b481efee6b41b4403f2be`／Draft17.38 と区別。ACTUAL START／FIRST は POST・個別GETで全文一致。独立 F/R 原資料未参照。 [ACTUAL START・FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088522329)

### 未変更 Gate0

- 凍結した7例は全て SOURCE／登録／CHECK=0。joined-local の /・% と caller let・直接式文の4例は `machine_proved=0`、通常／named C17=4、native 未到達。先行 IF の2 normal literal arms（97／54）と genuine joined result は成立。joined slot は Unknown のまま sole binding が受け取り、後続2 arm の Copy は同じ symbol／value slot／place に対応。各例の4演算 view／validator は真正 ARM で成功し、numerator/result は静的 Unknown。最初の拒否は whole quantity plan の unary Bool shape。既存出力の SHA・bytes／inode／mode／時刻を保全し、absent target は生成されなかった。
- literal-local /・% と caller-joined mixed / の3対照は `machine_proved=1`、C17=0、named/stdout bytes 一致、strict GCC・Clang O0/O2。pristine／別観測の24 native runs、通常 stdout 空。観測は順に13→19、6→2、13→10。この Gate0 と source／oracle は production 編集前に保全。観測器の初回ビルドで division view に存在しない `source` field を参照したため、元stderrを保全して観測器だけ訂正し、固定 compiler で7例を測定した。

### 固定範囲の実装

- 純粋な登録済み `(bool)->usize` helper、通常 `main()` 直下の named Bool Copy。helper の唯一の root item は同じ Bool formal を Copy する先行 IF の joined binding。両 arm は非終了の `usize` literal tail。後続 direct IF tail も同じ formal を読み、二つの通常 arm で同じ joined local の Copy を分子に使い、両方 / または両方 %、固定非ゼロ除数だけ。
- 既存 IF shape 照合を有限な2-site形に再利用。通常 binding 検証から得た元 symbol・value slot・place を従来の private plan 走査で保持し、後続 ARM の同じ binding と照合。既存の IF／source／ARM／BODY／world、actual／formal、演算 validator、result seal、C17 renderer はそのまま使用。scalar の値一致で identity を代用せず、公開 issuer／API／world／schema、意味論、alias／一般 IF validator の追加は0。
- Exact candidate では joined 4例すべて `machine_proved=1`、C17=0、named/stdout byte 一致。元 Gate0 と比較した owned 観測の差は全体 proof 状態のみ。生成Cは先行 IF の結果を一度だけ local に保存し、後続両 arm は同 local と指定演算・除数を使用。各構成で4例×GCC/Clang×O0/O2×pristine/観測＝32 runs、計96。通常 stdout 空。観測で / は13→10、%は6→4を source 順に各1回。literal・caller-joined の owned／生成Cは固定基点と byte 一致。
- mixed /・%、alias、別 numerator、arm-local、先行 arm 終了、registered-call initializer、余分な root item は CHECK=0／C17=4。先行 arm 欠落・wrong Bool actual・joined arm 型不一致・/0・%0 は CHECK=3。各範囲外で既存 named bytes／metadata と absent target を保全。
- 選択 CTest normal、ASan/LSan、UBSan 各 **132/132**。両演算の各構成で先行 IF の第2 world clone 168 B、joined numerator slot 11,264 B、後続 IF の第2 world clone 168 B、helper result seal 12,096 B、entry world 42,099 B、C17 staging 25,600 B に実割当失敗を各1 hit。元 CHECK context／anchor・未公開出力と C17 の出力先を保全し、同一プロセスの通常 CHECK／C17 再試行成功。追加の private shape 走査自体は割当を行わない。全ローカル CTest／SDK は測定外。

### 固定候補と引き渡し

- private branch `p1668-joined-local-private`、HEAD `6ff3eca9d4a9c205a33cd2bf285b514f1a455475`、tree `3ba251a35e9c6c24453252df1f72687ec78dd8ff`、単親 `b917e0d5a897ea606002a2813fde42f45b49c859`。clean、固定 formatter・diff-check 成功。6 paths: `src/usize_addition.c`、`tests/p1654/{CMakeLists.txt,probe.c,run.py}`、追加 `tests/p1668/{divide,remainder}.nl`。full-index binary diff 22,141 B／SHA-256 `3700dc62190e2213b1194edad52604656b491971f2eb9e01a28d9b75a9a52a08`。
- Raw `/workspace/p1544-6afecbd5/p1668-joined-local/evidence/`、manifest 6,387件／972,900 B／SHA-256 `7ba79337c9ced3cca47f2c5914546402056725b4d6b674fa44a93df6fa00609f`。元 FIRST／RED／raw と先行 private/public manifest を再照合。既存の caller-joined 代替は caller に追加 slot と実引数を要求し、literal-local は caller 引数を増やさず先行選択の値を保持しない。Product GO／H1／監査局所性の結果は別。
- 直前GETの #1665 は元 HEAD `b917e0d5a897…` の DRAFT、Required 6/6 と EARLY 2/2 が SUCCESS。C の独立審査は別で、確認範囲内に重大所見なし。**固定された有限 /・% の技術 GO を推奨**し、候補は private に固定、公開操作0。 **STOP C**。 [先行 C review](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7088328442) · [先行 DRAFT](https://github.com/wakairo/NewLang_Compiler/pull/1665)
