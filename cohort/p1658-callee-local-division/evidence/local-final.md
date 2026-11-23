## P1658 LOCAL FINAL · STOP C

既存 sole Codex Track P。固定 private 基点 `350d20c7fb781f15d53e599854224aedceba1bc5`／tree `8710553227f620ee5fe65423abac0f28f8c9737b` を未採用依存として使用。現実 main `19e14c6b90e38c8d3875966a47a0e443649ab800`／Draft17.38 と区別。ACTUAL START／FIRST は個別GETで全文一致。 [ACTUAL START・FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087196412) · [C ACK](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087211640)

### 未変更基点の実測

- 自作 local-let／local-discard と literal／mixed 対照は全て SOURCE／登録／CHECK 成功。二つの真正 BODY、対応する named Bool Copy actual／fresh formal、二つの canonical normal ARM、call/body 同じ結果 slot を確認。local 二例とも真正な固定除算 view/valid がそれぞれ4件成立。95÷6=15、95÷8=11、usize actual を分子の出所とする観測は0。
- 最初の差は whole quantity proof。local 二例は `machine_proved=0`、stdout／named C17=4、named 出力の bytes／inode／mode／時刻を保全。根の unary Bool の literal 専用形が局所分子形を除外し、既存の演算 origin 判定も helper 内の除算で formal 由来を要求していた。literal／mixed は `machine_proved=1`／C17=0。両対照は strict GCC・Clang O0/O2 で pristine stdout 空／観測15→11。local 二例は未変更基点で native 未到達。凍結 source／oracle hashes と raw は ACTUAL と同一。

### 限定修復

- 純粋な登録済み `(bool) -> usize`、通常 main 直下からの named Bool Copy、一つのリテラル初期化 `usize` let に続く直接 IF tail、同じ局所 binding の名前付き Copy を、二つの normal arm の固定非ゼロ除算の分子に使う形。caller は let と式文の両方で検証した。
- Unary Bool の形を照合した private planner 内だけで numerator の checked symbol を保持し、既存 item 検証で元 source binding／literal、既存 atom 検証で ARM の exact name／symbol／typed Copy、既存 operation validator で元 BODY・ARM・world、固定非ゼロ除数・operand/result を照合。その後も既存の invocation／formal／result seal と C17 renderer を使用。既存の formal 由来規則に対する例外はこの arm division に限る。新しい意味論、public API／issuer／world／schema の追加は0。
- helper 内で IF 結果を別 let に受ける旧 #1654 の元例は今回の範囲外。exact 元例で CHECK=0／named C17=4／no-clobber を再確認した。literal selector と混合 Copy 対照の owned・生成Cは固定基点にバイト一致。混合 Copy では caller が数値を追加実引数として持つ。literal arm は結果だけで足りる場合に簡潔だが、helper 内で分子と除数の関係を保持しない。本修復は caller に numerator を運ぶ必要を除く。製品価値・監査局所性・将来の保守負担は今回未測定。

### 候補と測定

- private `p1658-callee-local-division-private`、HEAD `ccdd8d16ca65f5593f7c8b955ec85d360828ea3a`、tree `2320df8104003475996e173ccf34ed8e9be5423b`、単親 `350d20c7fb781f15d53e599854224aedceba1bc5`。clean。4 paths は `src/usize_addition.c`、`tests/p1654/{CMakeLists.txt,run.py}`、追加 `tests/p1658/local-let.nl`。full-index diff 9,864 B／SHA-256 `e4fc6e3bd0c02a5027947999e35084ad848eb5459152dc449c6b331456497a24`。固定 formatter と `git diff --check` 成功。
- 修復後の同じ local 二例は `machine_proved=1`／C17=0、named と stdout は各例で同一。局所 validator・actual/formal・結果観測は未変更基点の観測と一致。生成Cは一つの同じ helper local を分子に実際の /6 と /8 を保持。strict GCC/Clang O0/O2、各構成16 native runs（pristine／別観測、caller 2形、計48）。通常 stdout は空、別観測は source 順に15→11を各1回。
- remainder、alias、arm 内で初期化した local は CHECK=0／C17=4 と no-clobber。Bool 分子／ゼロ除数は CHECK=3 とそれぞれ `USIZE-DIVISION-TYPE`／`USIZE-DIVISION-ZERO`、named C17=3 と no-clobber。継承した literal、discard、mixed、先行除算／余り回帰を含む selected normal／ASan/LSan／UBSan は各 **129/129**。局所分子の helper seal 10,368 B、entry world 39,239 B、C17 staging 22,016 B は各構成1 hitずつ。状態・出力保全、通常再試行を確認。全 CTest／SDK は測定外。
- 元 #1654 FIRST／RED／raw と固定候補の関連4 manifestを再照合。独立 F/R 原資料未参照。新 raw は `/workspace/p1544-6afecbd5/p1658-callee-local-division/evidence/`、manifest 2,817件／411,345 B／SHA-256 `4dd60066c6e2bd3523d4b72f18735f6d494087da90ebb1f0f9851b0661125f1f`。途中の観測用C生成の引用符エラーは元ログを保持し、観測器のみ訂正して両対照を再実行成功。

直前GETで #1657 は DRAFT、公開 HEAD／ref は `350d20c7fb78…`、実 main は `19e14c6b90e3…`。先行 #1657 の Required は5成功／ASan 1進行中、EARLY 2成功。先行C reviewに重大所見なし。先行採否と公開段階の実main再照合は C の対象。今回の候補は private 固定、公開操作 0。 **STOP C**。 [先行 C 審査](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7087167898) · [先行 DRAFT](https://github.com/wakairo/NewLang_Compiler/pull/1657)
