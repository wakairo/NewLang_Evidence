## P1654 PUBLIC HANDOFF — named Bool call statement · STOP C

同じ sole Codex Track P。C PRIORITY RELEASE と最新 C ACK、Compass → Value／Process → CURRENT_SPEC Draft17.38 を確認。独自の matched pair を先に凍結し、固定候補の拒否を再現してから、既存の検証だけで限定修復。ACTUAL RESUME は個別GETで全文一致。指定の既存 ref を1回の通常 non-force push で更新し、同じ DRAFT #1657 の説明に caller の対応範囲を明記した。説明は個別GETで照合済み。 [C RELEASE](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079849570) · [C ACK](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079944332) · [ACTUAL RESUME](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7087019265) · [DRAFT #1657](https://github.com/wakairo/NewLang_Compiler/pull/1657)

### 固定候補 cff254a の最初の差

- 同じ純粋な `(bool) -> usize` helper、二つの literal arm、同じ named Bool Copy actual と同じ二つの呼出順。変更は caller の `let result = call(flag);` を `call(flag);` にする点だけ。両方 SOURCE／登録／CHECK 成功。2つの真正 BODY、元 actual に対応する fresh formal と同じ call/body 結果 slot、二つの normal arm が観測できた。
- `let` は `machine_proved=1`／C17=0、式文は `machine_proved=0`／C17=4。後者は既存 named 出力の bytes・inode・mode・時刻を保全。最初の差は whole quantity plan の式文条件で、元実装は source が名前の Copy であることを要求していた。式文の CHECK や helper BODY の発行は成立済み。
- 凍結 source: let 335 B / SHA-256 `ed1c546eea910b5ac480f817ed3a972269293d742d5d8095fafb87f82f02ba15`、discard 310 B / `a2c85be47b04677335ee3d0b37c6f195672f23164e4778c2a6d28980abc127d0`、oracle 1,053 B / `6e2e72c7cd59aae7146e8b195d88459ef99105ef08fe7162b98d19cb82344fb7`。未変更 cff の統合済み compiler hash `be65bdd567e679591a2dd765d55b2b2c79fe6a2aa4fec341f76146f53c8d34bf` を再確認。

### 修復範囲と実測

- 通常 main 直下の純粋な登録済み unary Bool selector だけ。名前付き Bool の typed Copy、source 上の直接の call、unit で結果を持たない statement、既存 Copy/Discardable の ended carrier と空 owner place を照合。その後、既存の call chain、順序、actual/formal、BODY/world、既存の result seal を再検証。既存 C17 が `(void)(call(...));` を一度ずつ出す。新しい意味論・破棄規則・公開 API・issuer/world の追加は0。既存 let は同じ代替で、追加 binding が必要。
- 修復後の exact pair は両方 `machine_proved=1`／C17=0、named と stdout は各ケースで同一。旧 let と修復 let の owned 観測／生成Cがバイト一致。旧 let／新 let／新 discard を strict GCC・Clang O0/O2 で、pristine と観測版の計24 native runs。観測は二つの呼出を再評価せず、順に23、41を各1回。inline actual と IF-arm 内の直 discard は CHECK=0／C17=4、既存 named 出力を保全。元の未資格形・先行余り回帰も維持。
- 同一候補 selected normal／ASan/LSan／UBSan 各 **128/128**。新式文の result seal 5,184 B、entry world 34,472 B、C17 staging 17,408 B は各構成で1 hitずつ。CHECK state／anchor と C17 output を保全し通常再試行成功。全ローカル CTest／SDK はこの測定範囲外。
- 元 FIRST／Gate0 170件、元 private raw 1,255件、旧統合 raw 1,013件を SHA 再照合。旧独立拒否・旧 HEAD・旧 synthetic・各旧 run は旧 identity に保持。独立 F/R 原資料は未参照。今回の local raw は `/workspace/p1544-6afecbd5/p1654-bool-discard-priority/evidence/`、manifest 1,819件／260,519 B／SHA-256 `e554caecb9843d59423b1541a3acf05db3b001e2859bb1da8707567446e71433`。 [旧統合 HANDOFF](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079720479)

### 公開 identity と自然 CI

- 指定 ref と PR HEAD `350d20c7fb781f15d53e599854224aedceba1bc5`、tree `8710553227f620ee5fe65423abac0f28f8c9737b`、単親 `cff254ac141194318b2b5b5f11ceb3a2a1b91e06`。PR base と実 main は `19e14c6b90e38c8d3875966a47a0e443649ab800`。synthetic `4301d6f96d0a0466309bd429deb487599272828d` は候補と同tree、ordered parents `[19e14c6b90e38c8d3875966a47a0e443649ab800, 350d20c7fb781f15d53e599854224aedceba1bc5]`。
- 修復5 paths は `src/usize_addition.c` と `tests/p1654/{CMakeLists.txt,discard.nl,probe.c,run.py}`。旧→新 full-index diff 13,628 B、SHA-256 `f6a213a1aa0761e8f9c9bfc0f8bfbfffa0db7a72a4510c47520995c6d7bdfbde`。main→新の9 paths／40,336 B／SHA-256 `e0bb5e2b1e47f782421331180221b0f653dae7427e126a7d138582a77d108a18`、GitとGitHubの全9 after-blobsが一致。固定 formatter／diff-check 成功。 [公開差分](https://github.com/wakairo/NewLang_Compiler/pull/1657/files)
- 新 head の `pull_request` attempt 1 は 2026-11-23 07:48:24 JST に自然起動。PR、HEAD、base、synthetic と以下のジョブを個別照合した。引渡し時点で8件進行中。checkout step は成功、ジョブログの実 checkout SHA と最終結果は未確認。先行 main の Required 6件と cff の自然8件は別 identity で SUCCESS。
  - FULL `45079750322`。GCC `137385003021`、GCC Release `137385002649`、Clang `137385003004`、UBSan `137385002903`、ASan `137385002987`。 [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45079750322)
  - PARTIAL `45079750370`。Production CHECK/C17 native `137385002817`。 [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45079750370)
  - EARLY `45079750325`。ASan `137385003884`、UBSan `137385004175`。 [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45079750325)

公開候補を DRAFT で固定して **STOP C**。
