## P1668 ACTUAL START · FIRST

既存 sole Track P。own #1668、先行 #1665、P1662 PUBLIC HANDOFF と先行 C の latest exact review を個別GET。確認範囲に重大所見なし。実 main `55b3d960c585745d9b5b481efee6b41b4403f2be`、CURRENT_SPEC Draft17.38。固定した未採用依存は #1665 `b917e0d5a897ea606002a2813fde42f45b49c859`、tree `7b73d38b2bbb4274da60dc4726cf8f744150446e`、単親は上記 main。別 private checkout。独立 F/R 原資料未参照。Product GO／H1 は元裁定のまま。 [先行 P HANDOFF](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7088239378) · [先行 C review](https://github.com/wakairo/NewLang_Compiler/issues/1662#issuecomment-7088328442)

実行前の source／oracle は UTF-8・末尾 LF 付き。固定 compiler では両 joined-local 演算と両 caller 形が CHECK／真正 ARM validator まで成立し、最初の拒否は whole quantity plan、C17=4 と予測。division 13→10、remainder 6→4、literal stock 97 の / は13→19、%は6→2、caller-joined は13→10。通常 native stdout は空で、数値と順序は別観測。認可範囲は同じ Bool formal を読む先行 IF の二つの normal literal tails と sole joined binding、後続直接 IF tail の同じ local Copy と matching 固定非ゼロ / または % のみ。新意味論・authority・一般 IF／alias は対象外。

```text
592 evidence/source/caller-joined.nl
 416 evidence/source/joined-divide-discard.nl
 441 evidence/source/joined-divide.nl
 416 evidence/source/joined-remainder-discard.nl
 441 evidence/source/joined-remainder.nl
 384 evidence/source/literal-divide.nl
 384 evidence/source/literal-remainder.nl
1510 evidence/oracle.md
4584 total
345a1dd67dc0f2f5807920f92bb2e3b3cf89581cf9ccbde50f82ae3c09b83a81  evidence/source/caller-joined.nl
628e3ebd591aba5e8e74d63fa74d96813b4ec75c8f358ae3b409e8f8f1a308c5  evidence/source/joined-divide-discard.nl
9c237b3e6909f5c45b8b347194f48e4fa134f6b1595f5bd65f59ed66001b2427  evidence/source/joined-divide.nl
45e8bb077c0ff4db82b634a1734a1d33780ea8b0aff6c9f1c6630965a355ec7f  evidence/source/joined-remainder-discard.nl
9917485c13b540b83ae07975ca5a9a40f1b238e41429f07a44e906f7bb215dc4  evidence/source/joined-remainder.nl
4916e55ac0d37cd72190a7a7e46df2048842a20693661bbaef7467da24df524e  evidence/source/literal-divide.nl
2484b5473e029885dabdc2e2766ed66e12f136aff0231d09e9efb797b6f09aaa  evidence/source/literal-remainder.nl
54c68985eead638e02ffdec9d5a21c912b625e24e1ac26aa6e54d7cd70ce83c5  evidence/oracle.md
```

### joined-divide.nl

```newlang
fn choose_volume(flag: bool) -> usize {
    let stock = if (flag) {
        usize(97)
    } else {
        usize(54)
    };
    if (flag) {
        stock / usize(7)
    } else {
        stock / usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    let first = choose_volume(first_flag);
    let second = choose_volume(second_flag);
    unit
}
```

### joined-remainder.nl

```newlang
fn choose_volume(flag: bool) -> usize {
    let stock = if (flag) {
        usize(97)
    } else {
        usize(54)
    };
    if (flag) {
        stock % usize(7)
    } else {
        stock % usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    let first = choose_volume(first_flag);
    let second = choose_volume(second_flag);
    unit
}
```

### literal-divide.nl

```newlang
fn choose_volume(flag: bool) -> usize {
    let stock = usize(97);
    if (flag) {
        stock / usize(7)
    } else {
        stock / usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    let first = choose_volume(first_flag);
    let second = choose_volume(second_flag);
    unit
}
```

### literal-remainder.nl

```newlang
fn choose_volume(flag: bool) -> usize {
    let stock = usize(97);
    if (flag) {
        stock % usize(7)
    } else {
        stock % usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    let first = choose_volume(first_flag);
    let second = choose_volume(second_flag);
    unit
}
```

### caller-joined.nl

```newlang
fn choose_volume(stock: usize, flag: bool) -> usize {
    if (flag) {
        stock / usize(7)
    } else {
        stock / usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    let first_stock = if (first_flag) {
        usize(97)
    } else {
        usize(54)
    };
    let first = choose_volume(first_stock, first_flag);
    let second_stock = if (second_flag) {
        usize(97)
    } else {
        usize(54)
    };
    let second = choose_volume(second_stock, second_flag);
    unit
}
```

### joined-divide-discard.nl

```newlang
fn choose_volume(flag: bool) -> usize {
    let stock = if (flag) {
        usize(97)
    } else {
        usize(54)
    };
    if (flag) {
        stock / usize(7)
    } else {
        stock / usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    choose_volume(first_flag);
    choose_volume(second_flag);
    unit
}
```

### joined-remainder-discard.nl

```newlang
fn choose_volume(flag: bool) -> usize {
    let stock = if (flag) {
        usize(97)
    } else {
        usize(54)
    };
    if (flag) {
        stock % usize(7)
    } else {
        stock % usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    choose_volume(first_flag);
    choose_volume(second_flag);
    unit
}
```

### Frozen oracle

# P1668 frozen oracle

Named Bool arguments are true (64 < 100) then false (124 < 100). In the joined-local cases the first IF chooses 97 or 54 exactly once and binds its genuine result as stock. The second IF selects the same Bool's arm. Expected division values are floor(97/7)=13 then floor(54/5)=10; expected remainder values are 6 then 4. With a literal stock of 97, the same native branch order gives division 13 then 19, remainder 6 then 2. With a caller-joined mixed signature, division gives 13 then 10.

At fixed b917e0d5a897, predict SOURCE/register/CHECK success on all fixtures and owned IFs with well-typed two normal arms. The joined-local numerator should be statically Unknown, with the same recorded binding symbol/package in both protected later IF arms. Predict valid existing local ARM arithmetic observations, then the full quantity plan refuses the joined-local case, whether the caller binds or discards; stdout/named C17 exit 4. Existing target bytes and metadata stay intact; an absent target stays absent. The literal and caller-joined controls should reach strict native.

Authorized candidate shape: sole helper root item binds a preceding IF on the exact same named Bool formal with two usize literal normal tails, followed by the existing direct IF tail and two matching fixed nonzero division or remainder arms. No new issuer, world or general alias/IF rule. If closed by existing validation, observe the two runtime results once in call order. Pristine native stdout is empty.

ローカル凍結記録は `/workspace/p1544-6afecbd5/p1668-joined-local/evidence/`。初回結果と raw を production 編集前に別保全し、既存の source・world・結果 seal で閉じる場合だけ実装・回帰へ。
