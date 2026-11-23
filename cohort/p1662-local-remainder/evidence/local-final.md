## P1662 LOCAL FINAL · STOP C

既存 sole Codex Track P。独自 FIRST と予測を固定してから、未採用 `1e6ec2206a4ea891f50b903cf728a65789f41310`／tree `2320df8104003475996e173ccf34ed8e9be5423b` を別 private checkout に使用。実 main `b11e8b9a960fc8c5f253c9906ebf5f02c471c022`、Draft17.38 とは区別。ACTUAL START／FIRST は POST・個別GETで全文一致。独立 F/R 原資料未参照。 [ACTUAL START・FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7087797422) · [先行 HANDOFF](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087707261)

### 未変更基点の到達層

- 自作の local-let／local-discard、division／literal／mixed remainder 対照はいずれも SOURCE／登録／CHECK=0。named Bool Copy→fresh formal、真正 BODY、二つの normal ARM と別 world、同じ BODY／call result slot を確認。
- local 二形ではそれぞれ4件の真正な公開 remainder view／validator が成功。83%7=6、83%5=3。分子は元の local symbol で usize actual 由来は0。最初の拒否は whole quantity plan で、従来の unary Bool local shape が division tail だけを選び、local-origin の例外も division に限定していた。各形 `machine_proved=0`、通常／named C17=4、named 出力の bytes／inode／mode／時刻を保全。両 local % の未変更 native は未到達。
- division／literal／mixed の対照は `machine_proved=1`／C17=0 と named/stdout 一致。strict GCC・Clang O0/O2、pristine／別観測の計24 native runs。通常 stdout は空、既存 return を観測すると division 11→16、literal／mixed 6→3。凍結 source と oracle の bytes/SHA は FIRST の記録を保持。

### 限定修復と実測

- 一つのリテラル初期化 `usize` let に続く直接 IF tail。二 normal arms は同じ local symbol を正規の名前付き Copy として使い、両方とも固定非ゼロ %、もしくは既存どおり両方とも /。通常 main 直下の named Bool Copy、caller の let／直接式文を維持。既存 `fixed_divisor` が /・% のみに限り、既存の source binding／atom と operation validator が元 ARM／BODY／world、nonzero literal、operand/result を検査。そのまま invocation の actual/formal、既存 result seal、C17 renderer を使う。新規意味論・公開API／issuer／world／schema は0。
- 新候補の二 local % は `machine_proved=1`、通常／named C17=0 と同一 bytes。固定基点と比較して owned／validator 観測の差は全体 proof 状態だけ。生成Cでは同じ元 local が二 arm の %7・%5 の分子。strict GCC/Clang O0/O2、pristine／観測、caller 2形は各構成16 runs、計48。通常 stdout は空、観測は6→3を各1回。division／literal／mixed 対照の owned と生成C は基点と byte 一致。
- 先行 P1658 の旧拒否 `local-remainder` fixture は bytes を再照合し、同じ source だけを今回の5→7成功回帰へ移した。旧拒否 raw は保持。mixed arm operators、alias、arm-local、helper 内の別 IF-result let は CHECK=0／C17=4、型違い／ゼロ除数は CHECK=3 `USIZE-REMAINDER-TYPE`／`USIZE-REMAINDER-ZERO`。いずれも既存 named 出力を保全。mixed signature なら caller に numerator を追加する。literal arms は結果のみを記述する。製品価値や監査局所性は未測定。
- 選択 CTest は normal／ASan/LSan／UBSan 各 **130/130**。先行の literal selector、division、既存余り、let／式文を含む。新経路の helper seal 10,368 B、entry result-world 39,189 B、C17 staging 22,016 B は各構成1 hit。元状態・出力保全と通常 CHECK／C17 retry 成功。全ローカル CTest／SDK は測定外。

### 固定候補と証拠

- private `p1662-local-remainder-private`、HEAD `4b24d2f354de4fa0d0c479825df688e41a30c634`、tree `7b73d38b2bbb4274da60dc4726cf8f744150446e`、単親 `1e6ec2206a4ea891f50b903cf728a65789f41310`。clean status、固定 formatter、diff-check 成功。変更 `src/usize_addition.c`、`tests/p1654/{CMakeLists.txt,run.py}`、追加 `tests/p1662/local-let.nl` の4 paths。full-index diff 9,271 B／SHA-256 `6a87e299a07e2c4d5b76e485a5c094a6365b36313f938a0f5b63c1bdbfe84b3b`。
- 現 raw は `/workspace/p1544-6afecbd5/p1662-local-remainder/evidence/`、manifest 3,980件／601,179 B／SHA-256 `823c8f6f3a64c177e12963b99e203730a6ca184b2c6880144e13ef82a0361a96`。先行 private／public 検証 manifest の全項目を再照合。元 FIRST／RED／raw と先行公開 ref を保全。
- 直前 GET で #1661 は DRAFT、公開 HEAD `1e6ec2206a4e…`、実 main `b11e8b9a960f…`。先行 Required は4成功、ASan／UBSan進行中、非Required EARLY 2成功。先行重大所見未観測。今回の候補は private、公開操作0。 **STOP C**。 [先行 C 審査](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087772407) · [先行 DRAFT](https://github.com/wakairo/NewLang_Compiler/pull/1661)
