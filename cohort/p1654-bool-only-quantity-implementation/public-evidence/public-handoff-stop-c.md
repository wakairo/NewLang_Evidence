## P1654 PUBLIC HANDOFF · STOP C — 公開後に main 移動

C の exact PUBLIC DRAFT GO に従い、指定 ref に固定コミットを1回の通常 push で公開。固定 base を Git／GitHub で再確認して **DRAFT #1657** を 2026-11-22 22:07:10 JST に作成した。ACTUAL PUBLIC RESUME は POST／個別GETで全文一致。作成後の再照合で、先行 #1653 が 22:08:56 JST に採用され実 main が進んだため、**STOP C**。公開候補と DRAFT をそのまま保全し、統合順と新 base の評価を C に戻す。 [指示](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079523309) · [ACTUAL PUBLIC RESUME](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079564605) · [DRAFT #1657](https://github.com/wakairo/NewLang_Compiler/pull/1657)

### 公開時の exact identity

- `refs/heads/p1654-bool-only-quantity-public` と `refs/pull/1657/head` = `972a61bc31522cf60d31bb5847e29a3f002e9d9d`。tree `f84987e8d4c063decc27b9547c570d88d22a2b87`。唯一の親と公開時 base は `0873819cabd3781582384891fc785d01b700056b`、base tree `85b750f35d257a9f18cde3a38f97e11696b9919f`、Draft17.38。
- 初回の `refs/pull/1657/merge` = `358eaab36a175e32a6581e1e948ab954b4bf4c28`。Git と GitHub の個別GETで tree が候補と同一であること、親が順に `[0873819cabd3781582384891fc785d01b700056b, 972a61bc31522cf60d31bb5847e29a3f002e9d9d]` であることを確認。
- full-index binary diff 33,852 bytes、SHA-256 `8d8ead86df726ad0b1c352e03e997264cab850f9ef0bfcf799c2ccd5d00192be`。GitHub PR files の8 pathsと全 after-blob が測定済みローカル差分に一致。変更 `CMakeLists.txt`、`src/c17_division_usize.c`、`src/division_usize_internal.h`、`src/usize_addition.c`。追加 `tests/p1654/{CMakeLists.txt,probe.c,run.py,selection.nl}`。
- 実測範囲は通常 main 直下の named Bool Copy → `(bool) -> usize` の純粋 helper → 二つの normal literal arms。直接IF tailとlet-copyで strict native の順序と値 11→19 を確認。元局所分子算術例と近傍負例の CHECK=0／C17=4、混合対照のバイト一致、3 OOMの保全と再試行、selected normal／ASan／UBSan 各127/127 は測定済み候補の結果。元 FIRST／GATE0／RED／raw と private 候補を保全。 [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079183947) · [GATE0 FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079252802) · [LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079495869)

### 初回の自然CI

各 run を個別GET。全て 22:07:14 JST に自然起動した `pull_request` / attempt 1。run の PR #1657、exact HEAD `972a61bc3152…`、旧 base `0873819cabd3…` を確認。8ジョブとも引渡し時点で進行中。各 checkout ステップの成功を確認したが、GCC の原ログは進行中に未配信だったため、ジョブログ自体の checkout SHA 照合は未成立。以下は旧 base の run であり、新 main に対する結果には数えない。

- Required FULL `45025796646`。GCC `137218418328`、GCC Release `137218418496`、Clang `137218418539`、UBSan `137218418579`、ASan `137218418581`。 [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45025796646)
- Required PARTIAL `45025796688`。Production CHECK + C17/native `137218418380`。 [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45025796688)
- 非Required EARLY `45025796714`。UBSan `137218418460`、ASan `137218418679`。 [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45025796714)

### STOP C の根拠

引渡し前の `git ls-remote` と GitHub 個別GETで、実 main `19e14c6b90e38c8d3875966a47a0e443649ab800`、tree `e23eac8e23bdbac15aefccfd02db0225479852db`、parents `[0873819cabd3781582384891fc785d01b700056b, c602dd2668c0ceb429059e1c647ffc4bfd03e360]`、#1653 `merged=true` を確認。直後の #1657 API スナップショットは旧 base／synthetic を返していたため、実 main の移動と区別した。公開時の独立評価は旧 base に限定し、候補への更新・追加検証はこの引渡しで停止。独立 F/R 原資料は未参照。 [採用 #1653](https://github.com/wakairo/NewLang_Compiler/pull/1653) · [実 main](https://github.com/wakairo/NewLang_Compiler/commit/19e14c6b90e38c8d3875966a47a0e443649ab800)
