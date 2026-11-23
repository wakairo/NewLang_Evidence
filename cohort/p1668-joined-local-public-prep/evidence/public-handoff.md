## P1668 PUBLIC HANDOFF · STOP C

既存 sole Track P。条件付き認可、条件成立 RELEASE、先行 #1665 の採用記録を個別GET。先行は exact HEAD で adopted、指定の実 main と親・tree が一致。PUBLIC ACTUAL は ref 公開前に POST／個別GETし全文一致。指定 ref への通常 push 1回と main 向け **DRAFT #1669** 1件を作成した。 [条件付き認可](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088707007) · [RELEASE](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088866199) · [採用記録](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7088858365) · [PUBLIC ACTUAL](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088882351) · [DRAFT #1669](https://github.com/wakairo/NewLang_Compiler/pull/1669)

### Exact identity と差分

- `refs/heads/p1668-joined-local-public` と `refs/pull/1669/head` は `f1f394d2e84621f70264965b92b3851c359249a6`。tree `3ba251a35e9c6c24453252df1f72687ec78dd8ff`、sole parent／base／実 main `5299ef4da6d45909abef6a0bebaa514d2e4c5ad0`（Draft17.38）。
- 実 main tree `7b73d38b2bbb4274da60dc4726cf8f744150446e`、ordered parents `[55b3d960c585745d9b5b481efee6b41b4403f2be, b917e0d5a897ea606002a2813fde42f45b49c859]`。新 synthetic `a25e745d2719132f83b0ef0eb69cb895aad594a0` は候補と同 tree、ordered parents `[5299ef4da6d45909abef6a0bebaa514d2e4c5ad0, f1f394d2e84621f70264965b92b3851c359249a6]`。GitとGitHubのref／commitを照合。
- 固定 private `6ff3eca9d4a9c205a33cd2bf285b514f1a455475` の変更を、実 main 直上の単一コミットへ移した。6 paths は `src/usize_addition.c`、`tests/p1654/{CMakeLists.txt,probe.c,run.py}`、追加 `tests/p1668/{divide,remainder}.nl`。full-index binary diff 22,141 B、SHA-256 `3700dc62190e2213b1194edad52604656b491971f2eb9e01a28d9b75a9a52a08` は private とバイト一致。GitHubの6 paths／after-blob、固定 formatter、diff-check、clean statusも照合。 [公開差分](https://github.com/wakairo/NewLang_Compiler/pull/1669/files)

### Exact 公開候補の再検証

- selected normal／ASan/LSan／UBSan 各 **132/132**。ordinary main の named Bool Copy、先行 IF の genuine joined local、後続 direct IF 両通常 arm の matching 固定 /・%、caller let／直接式文。既存 source・binding symbol/value slot/place／ARM／BODY/world・actual/formal・演算と result seal の検証を使用。strict GCC/Clang O0/O2 の 4例×8実行×3構成で、通常 stdout 空、別観測は / が13→10、% が6→4。named と stdout は各例で一致。
- 各演算・各構成で、先行 IF 第2 world clone、joined numerator slot、後続 IF 第2 world clone、helper seal、entry world、C17 staging に1 hitずつ。rollback、出力保全と同一プロセスの通常再試行を確認。mixed operators、alias、別 numerator、arm-local、余分な root item、終了する先行 arm、call initializer の拒否で既存・未作成両方の named 出力先を保全。元 Gate0 の型・ゼロ除数等の測定は LOCAL FINAL に保持。
- 元 FIRST／RED／raw と固定 private identity を保全。private の全6,387 manifest entries を再照合。公開候補のログは `/workspace/p1544-6afecbd5/p1668-joined-local-public-prep/evidence/`。manifest 4,182件／654,772 B／SHA-256 `ff4f97f58b16e777596c730a4b2cf4f625e9536dbab5ae496e0734036701145f`。独立 F/R 原資料未参照。先行 R のスコープ外 control-oracle NONPASS は元の C 採用記録に保持。 [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088522329) · [LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1668#issuecomment-7088645033)

### 初回自然CI

2026-11-23 10:08:11 JST に起動した `pull_request` attempt 1。実 PR／HEAD／base と8 job IDs を照合。引き渡し時点で8件進行中、checkout step 8件成功。原ログによる実 checkout SHA 照合と最終結果は残件。

- Required FULL `45092801005`。GCC `137425921452`、GCC Release `137425921564`、Clang `137425921306`、ASan `137425921510`、UBSan `137425921614`。 [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45092801005)
- Required PARTIAL `45092801018`、Production CHECK/C17 native `137425921165`。 [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45092801018)
- 非Required EARLY `45092801002`、ASan `137425921356`、UBSan `137425921100`。 [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45092801002)

先行 #1665 adopted-main FULL `45092403164`／PARTIAL `45092403174` は別 identity の6件が進行中。重大所見／NONPASS は直前確認で未観測。公開 ref と DRAFT を固定して **STOP C**。 [adopted-main FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45092403164) · [adopted-main PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45092403174)
