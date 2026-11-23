## P1658 PUBLIC HANDOFF · STOP C

同じ sole Codex Track P。条件成立の C 確認と条件付き PUBLIC DRAFT GO を個別GET。採用済み #1657 の HEAD、実 main の ordered parents／tree、重大 STOP の有無を再照合した。ACTUAL PUBLIC START は POST／個別GETで全文一致。指定 ref に通常 push 1回、main 向け **DRAFT #1661** を1件作成。 [条件成立](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087596479) · [公開認可](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087316444) · [PUBLIC ACTUAL](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087662522) · [DRAFT #1661](https://github.com/wakairo/NewLang_Compiler/pull/1661)

### Exact identity と差分

- `refs/heads/p1658-callee-local-division-public` と `refs/pull/1661/head` は `1e6ec2206a4ea891f50b903cf728a65789f41310`。tree `2320df8104003475996e173ccf34ed8e9be5423b`、唯一の親／PR base／実 main `b11e8b9a960fc8c5f253c9906ebf5f02c471c022`（Draft17.38）。
- Base tree `8710553227f620ee5fe65423abac0f28f8c9737b`、ordered parents `[19e14c6b90e38c8d3875966a47a0e443649ab800, 350d20c7fb781f15d53e599854224aedceba1bc5]`。#1657 は指定 HEAD で merged=true。PR の synthetic `00242b1ce72738f4b4686ceb0495f6b792fc30b1` は公開候補と同 tree、ordered parents `[b11e8b9a960fc8c5f253c9906ebf5f02c471c022, 1e6ec2206a4ea891f50b903cf728a65789f41310]`。ref と commit は Git／GitHub で照合。
- 固定 private `ccdd8d16ca65f5593f7c8b955ec85d360828ea3a` の差分を、実 main の別 checkout に cherry-pick。tree と full-index binary diff を旧測定結果とバイト照合した。4 pathsは変更 `src/usize_addition.c`、`tests/p1654/CMakeLists.txt`、`tests/p1654/run.py`、追加 `tests/p1658/local-let.nl`。9,864 B／SHA-256 `e4fc6e3bd0c02a5027947999e35084ad848eb5459152dc449c6b331456497a24`。GitHub PR の4 path／after-blob も一致。固定 formatter、diff-check、clean status すべて成功。 [公開差分](https://github.com/wakairo/NewLang_Compiler/pull/1661/files)

### 実測範囲

- 通常 main 直下から named Bool Copy を渡す純粋な unary Bool helper。その一つのリテラル初期化 `usize` local を、直接 IF tail の二 normal arms で同じ名前付き Copy として固定非ゼロ除算に使用。既存 source・ARM／BODY・Copy・actual/formal・result seal を検証し、既存 C17 renderer を使用。helper 内で IF 結果を別 let に受ける形、alias、arm-local、余りは今回の範囲外。混合 Copy による caller からの追加 numerator と literal arm は既存の代替。
- 公開 exact HEAD で selected normal／ASan/LSan／UBSan 各 **129/129**。caller の let と式文で named/stdout C17 一致、strict GCC/Clang O0/O2 で 15→11、pristine stdout 空。3構成の helper seal／entry world／C17 staging は各1 hit、rollback／出力保全／通常再試行成功。未変更の初回拒否、元 FIRST／RED／raw、private identity は保全。private raw 全2,817件を再照合。新公開候補の試験 raw は `/workspace/p1544-6afecbd5/p1658-callee-local-division-public-prep/evidence/`、manifest 1,754件／266,747 B／SHA-256 `2146c9dac70d4d2b1c3427a74b114bb6cc8cb704457d89f5d64e5b1b7ba3cb75`。独立 F/R 原資料未参照。 [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087196412) · [元 LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087281069)

### 初回の自然 CI

すべて 2026-11-23 08:35:42 JST に起動した `pull_request` attempt 1。実 PR／HEAD／base と各 job を個別GET。引き渡し時点で8ジョブが進行中、checkout step は8件成功。原ログによる実 checkout SHA 照合と最終結果は残件。

- Required FULL `45084091370`。GCC `137398593191`、GCC Release `137398593203`、Clang `137398592969`、ASan `137398593199`、UBSan `137398593245`。 [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45084091370)
- Required PARTIAL `45084091283`、Production CHECK/C17 native `137398592414`。 [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45084091283)
- 非Required EARLY `45084091288`、ASan `137398592563`、UBSan `137398592309`。 [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45084091288)

先行 main の採用後 FULL／PARTIAL `45083315120 / 45083315102` は別 identity で C が並走監査。実 main と公開対象を再照合し、候補を DRAFT で固定して **STOP C**。
