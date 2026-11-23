## P1658 ACTUAL START

既存の sole Codex Track P。#1658 本文、P1654 PUBLIC HANDOFF、#1657 の最新 C 審査を個別GET。#1657 の重大所見は現時点で未観測。固定mainの Compass → Value §1.1/1.3 → Process §4.1.2/4.3 → CURRENT_SPEC／Draft17.38 と Copy・通常関数結果・固定除算を確認。局所値を保持できる場合の caller 変更負担と、混合 Copy／定数 arm の代替を技術実測と区別する。 [元 HANDOFF](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7087121053) · [先行 C 審査](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7087167898)

実 main `19e14c6b90e38c8d3875966a47a0e443649ab800` と、未採用依存 `350d20c7fb781f15d53e599854224aedceba1bc5`／tree `8710553227f620ee5fe65423abac0f28f8c9737b`／単親 `cff254ac141194318b2b5b5f11ceb3a2a1b91e06` を Git／GitHub で確認。後者を別 private checkout の基点にし、先行公開候補・元 FIRST／RED／raw と独立性を保全する。独立 F/R 原資料未参照。 [先行 DRAFT #1657](https://github.com/wakairo/NewLang_Compiler/pull/1657)

### 独自 FIRST — 実測前に凍結

```text
fn choose_quota(flag: bool) -> usize {
    let stock = usize(95);
    if (flag) {
        stock / usize(6)
    } else {
        stock / usize(8)
    }
}

fn main() -> unit {
    let limit = usize(103);
    let above_first = usize(80) < limit;
    let above_second = usize(120) < limit;
    let first = choose_quota(above_first);
    let second = choose_quota(above_second);
    unit
}
```

- local-let 385 B／SHA-256 `c24b6858fc5b9751b760def1ce20b8f7c0edcf815ffcc35eb9cd2a82f69b4cd6`。local-discard は同じ呼出しを2式文にした360 B／`7ccef2e170d44626f2f7cb066ff452cea1e9260899e610a944c5cf2842b71c21`。
- literal control 344 B／`2d4ebb76ca127efd0c748d942503f7d1d5a0d8269c87de5049b83526be8f21c7`。mixed Copy control 413 B／`c48fae4be7ccf985275dd52b7d60ee9f11792e5e92bbef90e22c67c378701c0f`。oracle 1,315 B／`874c396218b15e611ec7c17afe09fde0efd607538000f2b5f231e0c899d1c192`。全文と freeze raw は `/workspace/p1544-6afecbd5/p1658-callee-local-division/evidence/`。
- 予測は true の95÷6→15、false の95÷8→11。固定候補では両 local 例で CHECK と真正 BODY／ARM／局所 division validator は成立し、whole quantity proof で止まり C17=4、named 出力保全と予測。literal／mixed は C17=0 と strict native 到達を予測。通常 native の stdout は空、別観測は15→11を各1回。認可範囲で、関数内の一つの不変リテラル初期化 `usize` local の Copy を二つの通常 arm の固定非ゼロ除算に使う形を調べる。既存出所・world／result seal・Copy・rollback のいずれかに新しい契約を要するなら STOP C。
