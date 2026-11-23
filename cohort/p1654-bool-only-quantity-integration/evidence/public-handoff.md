## P1654 PUBLIC HANDOFF — integrated new main · STOP PUBLIC / C

C の新 main 統合 RELEASE に従い、旧公開 HEAD に固定新 main を通常 merge。認可範囲・local 検証・公開直前の ref 照合を通過し、既存の `p1654-bool-only-quantity-public` を1回の non-force fast-forward で更新した。同じ #1657 が main 向け DRAFT であることを個別GETで確認。 [C RELEASE](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079626218) · [ACTUAL INTEGRATION RESUME](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079660493) · [DRAFT #1657](https://github.com/wakairo/NewLang_Compiler/pull/1657)

### Exact identity と差分

- 公開 ref と `refs/pull/1657/head` の HEAD は `cff254ac141194318b2b5b5f11ceb3a2a1b91e06`、tree は `2113961602c5e21c6d13f9ed067db7c80e4925b6`、ordered parents は `[972a61bc31522cf60d31bb5847e29a3f002e9d9d, 19e14c6b90e38c8d3875966a47a0e443649ab800]`。
- PR base と引渡し直前の実 main は `19e14c6b90e38c8d3875966a47a0e443649ab800`、tree `e23eac8e23bdbac15aefccfd02db0225479852db`、Draft17.38。新 synthetic `4274792f8511081e6404c167f165b661a97f3097` は候補と同じ tree、ordered parents `[19e14c6b90e38c8d3875966a47a0e443649ab800, cff254ac141194318b2b5b5f11ceb3a2a1b91e06]`。
- 新 base との差分は旧候補と同じ8 paths、full-index binary 33,852 B / SHA-256 `d11f15daadefaed25c5610eb90dcbe280e57494ab28d7654afd49ed122b8f733`。GitHub PR files の全8 after-blobs を Git で照合。対象は `CMakeLists.txt`、`src/{c17_division_usize.c,division_usize_internal.h,usize_addition.c}`、`tests/p1654/{CMakeLists.txt,probe.c,run.py,selection.nl}`。共有 `src/usize_addition.c` の追加・削除行も旧単独 Bool 差分と一致し、旧候補側から見た2-path差分は採用済み #1653 の追加・削除行と一致。競合なしの merge だけで整合し、固定 formatter と diff-check を通過。 [公開差分](https://github.com/wakairo/NewLang_Compiler/pull/1657/files)

### 新候補のローカル検証

- 同一 HEAD の選択回帰は normal **127/127**、ASan/LSan **127/127**、UBSan **127/127**。各構成で単独 Bool の直接 tail／let-copy が strict GCC/Clang O0/O2 で順に 11、19。inline actual・局所分子算術・別 helper caller は CHECK=0／C17=4、既存 named 出力を保全。旧凍結 Bool・混合対照の CHECK／owned／C17 の比較一致を確認した。
- 単独 Bool の helper result seal、entry world、C17 staging の3 OOMサイトは各構成で1 hitずつ。rollback、出力保全、CHECK／C17再試行成功を再確認。採用済み余りの直接・名前付き対照も旧 C17 とバイト一致し、strict native は両形計16 runs で予測を再現。normal で余りの既存 provenance 検証と3 OOMサイトの到達・再試行も再確認。SDK・全体ローカルCIは測定範囲外。
- 旧 FIRST／Gate0／RED、旧候補、旧ローカル raw は別 identity で保持し、元170件＋旧127件回帰を含むraw 1,255件をハッシュ再照合。新しい local raw は `/workspace/p1544-6afecbd5/p1654-bool-only-quantity-integration/evidence/`。統合・試験 manifest 1,013件 / 142,607 B / SHA-256 `0ff003eb786a2ba620e87067e3371879e2973f2ebc16c970e2ec5af7abbff542`。 [元 FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079183947) · [元 GATE0](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079252802) · [旧 LOCAL FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079495869)

### 新旧の自然CI

新セットは22:17:12 JST に自然起動した `pull_request` attempt 1。run の HEAD／PR #1657／base と8 job IDsを個別照合。引渡し時点で8ジョブすべて進行中。checkout step の成功と GitHub synthetic identity は確認済み。進行中の新 PARTIAL 原ログは未配信のため、ジョブログからの checkout SHA 照合は未成立。

- Required FULL `45026668765`。GCC `137221091840`、GCC Release `137221091903`、Clang `137221091602`、ASan `137221091897`、UBSan `137221091771`。 [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45026668765)
- Required PARTIAL `45026668802`。Production CHECK + C17/native `137221091843`。 [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45026668802)
- 非Required EARLY `45026668793`。ASan `137221092044`、UBSan `137221091846`。 [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45026668793)

旧 `45025796646 / 45025796688 / 45025796714` は HEAD `972a61bc3152…` と旧 synthetic `358eaab36a17…` の記録。旧GCC原ログにも旧 synthetic の fetch が残る。更新後に旧 run API の埋込み PR オブジェクトは現 PR HEAD/base を返すため、固定済み旧 checkout と区別した。新 main 自身の FULL/PARTIAL `45025944644 / 45025944653` は別 run で、C の監査対象。引渡し前の確認範囲で追加の STOP または重大所見なし。独立 F/R 原資料未読。 **STOP PUBLIC / C**。 [旧 PUBLIC HANDOFF](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079616688) · [旧GCC原ログ](https://github.com/wakairo/NewLang_Compiler/actions/runs/45025796646/job/137218418328)
