## P1662 ACTUAL START · independent FIRST

既存 sole Codex Track P。own Issue、先行P1658のPUBLIC HANDOFF、先行 #1661 の最新 C 審査を個別GET。先行に重大 STOP は未観測。固定 main の Compass → Value §1.1/1.3 → Process §4.1.2/4.3 → CURRENT_SPEC／Draft17.38 §5.4 を確認。先行の独立 F/R 原資料・入力は未参照。 [先行 HANDOFF](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087707261) · [先行 C 審査](https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087772407)

Git／GitHub 照合で別 private checkout の基点は未採用 `1e6ec2206a4ea891f50b903cf728a65789f41310`、tree `2320df8104003475996e173ccf34ed8e9be5423b`。実 main とその単親 `b11e8b9a960fc8c5f253c9906ebf5f02c471c022` を区別。先行公開候補・元 FIRST/RED/raw は保全する。 [固定 DRAFT #1661](https://github.com/wakairo/NewLang_Compiler/pull/1661)

### 凍結した主例

```text
fn choose_remainder(flag: bool) -> usize {
    let stock = usize(83);
    if (flag) {
        stock % usize(7)
    } else {
        stock % usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let early = usize(61) < limit;
    let late = usize(123) < limit;
    let first = choose_remainder(early);
    let second = choose_remainder(late);
    unit
}
```

- local-let 369 B /`6ecbc5d22f32ee03df0c9a500343d4cb2874677765e4a0919d9d861b058ef187`、caller 式文 local-discard 344 B /`65a9c835b085e4b0b177f16cc50c6943b4eb2aebf986d08bb10016d1c9b017e4`。
- 対照の / 369 B /`0a212457166ce2cb41e5ff629a84af7769da6a4a98d361e266ff615c5fe08148`、literal 326 B /`7da4bc8552512ad0ed69a18759baa9235176eb0302e46df6e80cba6b392e19ad`、mixed 397 B /`b78675a0d5ca0acd82f26ae2dd30317fef794aeba6ed8e7a572b5f84902fa478`。oracle 1,307 B /`98f650bf9a7eeb464a9a62244255a7ace5d1a4088546f8232f700ead03e0dd6c`。SHA-256 と各全文は `/workspace/p1544-6afecbd5/p1662-local-remainder/evidence/` に実行前保存。
- true→83%7=6、false→83%5=3、division 対照は11→16。両 local % は parse／CHECK／真正 ARM remainder view・validator まで成功し、whole quantity plan が初めて拒否、C17=4 と named 出力保全を予測。division／literal／mixed は strict native まで予測。通常 native stdout は空、別観測では既存の結果を二つの呼出し順に各1回。
- 安全に再利用できるなら、一つのリテラル初期化 `usize` let、直接 IF tail、同一 local を two normal arms が named Copy する形に限り、両 arm が % の場合を追加。既存 / も両 arm 同じ演算の範囲を維持する。mixed signature は caller に追加 numerator が要り、literal arm は式を保持しない。alias、arm-local、別 IF-result binding と arm 間の /・% 混在は今回の対象外。新意味論・公開契約・重大先行所見は STOP C。
