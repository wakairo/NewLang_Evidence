## P1654 · FIRST · PRIVATE GATE0 FREEZE

固定 `0873819cabd3781582384891fc785d01b700056b` の実行前に、sole P自身のsource・oracleを末尾LF込みで凍結しました。 [ACTUAL START](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079173214)

| file | UTF-8 bytes | SHA-256 |
|---|---:|---|
| `source/bool-only.nl` | 394 | `27a1d1b3db92ef068416648bd672e5ac9e8eb59db280a1ea146217e6cb909f6e` |
| `source/mixed-copy.nl` | 395 | `8edc741f40719adac07f569ee671f559d0f8b11a65ff7d12ea13ba8f526d96e0` |
| `oracle.md` | 1699 | `7c9c424d8b1406d7987877467e5c1272d76131e19e9d4180ab0a1b879f4528e2` |

### `source/bool-only.nl`

```text
fn choose(flag: bool) -> usize {
    let stock = usize(77);
    let amount = if (flag) {
        stock / usize(7)
    } else {
        stock / usize(4)
    };
    amount
}

fn main() -> unit {
    let stock = usize(77);
    let select_first = usize(50) < stock;
    let select_second = usize(90) < stock;
    let first = choose(select_first);
    let second = choose(select_second);
    unit
}
```

### `source/mixed-copy.nl`

```text
fn choose(stock: usize, flag: bool) -> usize {
    let amount = if (flag) {
        stock / usize(7)
    } else {
        stock / usize(4)
    };
    amount
}

fn main() -> unit {
    let stock = usize(77);
    let select_first = usize(50) < stock;
    let select_second = usize(90) < stock;
    let first = choose(stock, select_first);
    let second = choose(stock, select_second);
    unit
}
```

### `oracle.md`

```markdown
# P1654 pre-execution oracle

Draft17.38 §§4.2, 5.4, 18.1–18.2, 19.1, 27.3–27.4 allow the ordinary declarations, argument Copy, an IF driven by a bool and fixed nonzero usize division. The two helpers use the same division expressions. The bool-only helper binds 77 locally. The mixed helper receives a genuine Copy of the caller's stock and uses it in the numerator in both arms. Both main calls pass a named bool Copy, produced by the same comparisons against 77.

| main order | bool actual/formal | selected arm | arithmetic result |
|---|---|---|---:|
| first | 50 < 77 = true | then, 77 / 7 | 11 |
| second | 90 < 77 = false | else, 77 / 4 | 19 |

Evaluate the source actuals once in order (stock then flag for the mixed signature), bind fresh formals, evaluate the condition once, execute just its selected arm, then bind the helper result in main. If emitted, pristine native main exits 0. A separate native observation should show the selected paths and results 11 then 19. The published CHECK artifacts can contain both hypothetical arm results and an Unknown IF join.

Expect both to parse and ordinarily CHECK. Expect genuine registered call/body evidence, bool Copy actual identities and ordinary same-world formal binding in both. The prediction is that bool-only does not pass whole-program quantity admission, while the mixed profile does. The fixed numeric arm evidence and local numerator-origin requirements must be examined independently. On C17 refusal expect exit 4, empty stdout and a preserved existing named destination. An arithmetic-free bool-only reduction may be frozen and measured if needed to isolate a first admission boundary. The first outcomes stay frozen.
```
