## P1662 PUBLIC HANDOFF · STOP C

既存 sole Track P。C PUBLIC DRAFT GO を個別GETし、採用済み #1661 の exact HEAD と実 main を照合。PUBLIC ACTUAL は POST／個別GETで全文一致。指定 ref へ通常 push 1回、main 向け **DRAFT #1665** を1件作成した。 [C PUBLIC DRAFT GO](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7088130610) · [PUBLIC ACTUAL](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7088195628) · [DRAFT #1665](https://github.com/wakairo/NewLang_Compiler/pull/1665)

### Exact identity

- 公開 ref `refs/heads/p1662-local-remainder-public` と `refs/pull/1665/head` は `b917e0d5a897ea606002a2813fde42f45b49c859`。tree `7b73d38b2bbb4274da60dc4726cf8f744150446e`、sole parent／base／実 main `55b3d960c585745d9b5b481efee6b41b4403f2be`、Draft17.38。
- 実 main tree `2320df8104003475996e173ccf34ed8e9be5423b`、ordered parents `[b11e8b9a960fc8c5f253c9906ebf5f02c471c022, 1e6ec2206a4ea891f50b903cf728a65789f41310]`。#1661 は指定 HEAD で merged=true。新 synthetic `86d67953af84e590d3e123656e1f1395dba570ee` は候補と同じ tree、ordered parents `[55b3d960c585745d9b5b481efee6b41b4403f2be, b917e0d5a897ea606002a2813fde42f45b49c859]`。Git と GitHub を照合。 [先行採用記録](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7088182783)
- 固定 private `4b24d2f354de4fa0d0c479825df688e41a30c634` から実 main 直上へ移した4 paths。変更 `src/usize_addition.c`、`tests/p1654/{CMakeLists.txt,run.py}`、追加 `tests/p1662/local-let.nl`。full-index binary diff **9,271 B**／SHA-256 `6a87e299a07e2c4d5b76e485a5c094a6365b36313f938a0f5b63c1bdbfe84b3b`。private の差分・tree とバイト照合し、GitHubの4 path／after-blobも一致。diff-check／固定 formatter／clean status を確認。 [公開差分](https://github.com/wakairo/NewLang_Compiler/pull/1665/files)

### Exact 公開候補の再検証

- 選択 normal／ASan/LSan／UBSan は各 **130/130**。通常 main 直下の named Bool Copy、単一リテラル初期化 `usize` local、直接 IF tail の二通常 arm が同じ local を固定非ゼロ % の分子に使う形。既存 source／Copy・BODY／ARM・actual/formal・result seal で検証し、caller の let／直接式文とも通常・named C17が一致。strict GCC/Clang O0/O2 で観測6→3を各1回、通常 native stdout は空。先行 /・literal・mixed と既存余り回帰を含む。混在演算、alias、arm-local、helper 内の別 IF-result binding は対象外。
- helper seal 10,368 B、entry world 39,189 B、C17 staging 22,016 B で各構成1 hit。rollback、出力保全、通常 CHECK／C17 再試行を確認。元 FIRST／RED／raw、固定 private を保全し、private raw 3,980件を再照合。公開候補の選択 raw は `/workspace/p1544-6afecbd5/p1662-local-remainder-public-prep/evidence/`。manifest 2,621件／407,119 B／SHA-256 `460b881f17da457c19354a1e1801327e122d05da85448efd671d06be163422fd`。独立 F/R 原資料未参照。 [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7087797422) · [LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7087852397)

### 自然CI

2026-11-23 09:17:02 JST 起動の `pull_request` attempt 1。実 PR／HEAD／base と全ジョブIDを照合。引渡し時点で8件進行中、checkout step は全件成功。実 checkout SHA の原ログ照合と最終結果は残件。

- Required FULL `45087851540`。GCC `137410423897`、GCC Release `137410423813`、Clang `137410423634`、ASan `137410423932`、UBSan `137410423877`。 [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45087851540)
- Required PARTIAL `45087851476`、Production CHECK/C17 native `137410422888`。 [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45087851476)
- 非Required EARLY `45087851504`、ASan `137410423378`、UBSan `137410423019`。 [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45087851504)

先行 #1661 採用前 Required 6/6 は別 identity。採用後 main は FULL `45087193085`／PARTIAL `45087193015` の6件が進行中で重大 NONPASS 未観測。公開 ref と DRAFT を固定し **STOP C**。 [実 main FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45087193085) · [実 main PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45087193015)
