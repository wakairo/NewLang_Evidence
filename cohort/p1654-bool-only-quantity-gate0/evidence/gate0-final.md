## P1654 · GATE0 FINAL · COVERAGE DIFFERENCE · STOP C

固定main `0873819cabd3781582384891fc785d01b700056b` で、単独 `bool` と `(usize, bool)` はともに通常CHECKと真正な公開owned BODYに到達しました。最初の実差は全体の `machine_proved` です。単独boolは局所の除算validatorが通ってもC17がfail-closed、混合形は同じ値でstrict nativeまで通りました。 [ACTUAL START](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079173214) · [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079183947)

GitHub actual mainと作業前後cleanのprivate detached HEADを照合しました。tree `85b750f35d257a9f18cde3a38f97e11696b9919f`、ordered parents `[f3aaab3d1cb85f752195ace1c277add1dce675ce, 49fdb154ac93436df8573d7d50c335fecb7dc710]`。CURRENT_SPEC → Draft17.38。固定mainのprivate診断として完結しました。 [固定main](https://github.com/wakairo/NewLang_Compiler/commit/0873819cabd3781582384891fc785d01b700056b)

| frozen FIRST | UTF-8 bytes | SHA-256 |
|---|---:|---|
| `source/bool-only.nl` | 394 | `27a1d1b3db92ef068416648bd672e5ac9e8eb59db280a1ea146217e6cb909f6e` |
| `source/mixed-copy.nl` | 395 | `8edc741f40719adac07f569ee671f559d0f8b11a65ff7d12ea13ba8f526d96e0` |
| `oracle.md` | 1699 | `7c9c424d8b1406d7987877467e5c1272d76131e19e9d4180ab0a1b879f4528e2` |

### 最初の実測

| layer | `(bool) -> usize` | `(usize, bool) -> usize` |
|---|---|---|
| 通常SOURCE／CHECK | load、parse、register、CHECKすべて0 | 同じ |
| public-owned | registered callとBODY、同じcall context、typed bool Copyの新しいslotが実formal bindingに対応 | 同じ。先行usize Copy 77もformalに対応し、両armの分子で使用 |
| IF／arm division | condition 1→0、各IFは2 normal arms。各armの独自contextで77÷7=11、77÷4=19、いずれも真正 `view=1 valid=1` | 同じ |
| result／proof class | call resultはBODY resultと同じslot、joinとcallはUnknown、`machine_proved=0` | joinとcallはUnknown、`machine_proved=1` |
| 通常C17／named | 両方exit 4 `V1-BACKEND-UNSUPPORTED`、stdout 0。namedの既存内容・inode等を保持、staging残留なし | 両方exit 0。通常stdoutとnamed生成Cはbyte一致 |
| strict native | NOT_RUN（C17拒否） | GCC 14.2／Clang 23.1.3のO0/O2。pristine 4実行はexit 0、stdout/stderr空。別観測版4実行はactual 77/true→then→11、77/false→else→19 |

公開観測器は通常のsource load、parse、register、`main()` CHECKとborrowed getterを使用しました。混合形のC17はusize→boolの順に各actualを一度ずつmaterializeしてから呼びます。観測版は生成Cの別コピーに引数・選択arm・元mainのbinding出力のみを追加し、挿入の除去で元bytesと一致しました。

最初の境界を局所化するため、元FIRSTと初回結果を保持したまま、第2対照として単独boolのcallee内 `let stock` を取り除き、両除算を `usize(11)`／`usize(19)` に置換しました。signature、caller、選択条件、予測値は同じです。補足sourceは実行前にローカルで凍結した353 bytes、SHA-256 `dcbdcd3de823277bb58e725db5f229da43537f7ee3a0733237ce7163bfbcca87`。補足oracleは645 bytes、SHA-256 `e0b625eb7a17d925c1815a5b3173a837301261b3d31a53c73d64fbdb151cfc9f`。この対照でもSOURCE/CHECKと正規bool Copy／両armは成立、`machine_proved=0`、通常／named exit 4、named no-clobber、native NOT_RUN。拒否はarm内除算を外しても残りました。

### 最初の制約と再利用の見込み

現在の `nl_quantity_usize_function` は一引数の場合に `bool` formalを受けず、`quantity_helper_at` はこのpredicateを既存helper planの入口で使います。CHECKの `quantity_result` は既存result sealの条件で、公開proof classはrootのresult sealも検証します。実測した全体proof差と整合します。rendererへ渡る前の境界です。 [signature predicate](https://github.com/wakairo/NewLang_Compiler/blob/0873819cabd3781582384891fc785d01b700056b/src/usize_addition.c#L710-L736) · [helper plan](https://github.com/wakairo/NewLang_Compiler/blob/0873819cabd3781582384891fc785d01b700056b/src/usize_addition.c#L2219-L2235) · [CHECK seal](https://github.com/wakairo/NewLang_Compiler/blob/0873819cabd3781582384891fc785d01b700056b/src/semantic_check.c#L4640-L4664) · [公開proof class](https://github.com/wakairo/NewLang_Compiler/blob/0873819cabd3781582384891fc785d01b700056b/src/h_origin_internal.c#L1063-L1071)

predicateだけを変更すれば足りるとは判断していません。現planは混合形の2 formalsでoriginをseedし、named bool条件はそのoriginを要求します。元単独形の局所定数stockには、固定演算のformal由来numeratorを要求する別の制約もあります。今あるCALL/BODY、実Copy、IF/arm、局所演算、C17の `_Bool` 支持は再利用候補です。単独boolのtyped formalとresult/condition originの検証は別裁定で、今回の結果から新issuer/worldが必須とは判定しません。 [formalのorigin](https://github.com/wakairo/NewLang_Compiler/blob/0873819cabd3781582384891fc785d01b700056b/src/usize_addition.c#L2157-L2182) · [条件と固定演算](https://github.com/wakairo/NewLang_Compiler/blob/0873819cabd3781582384891fc785d01b700056b/src/usize_addition.c#L1716-L1776) · [既存renderer](https://github.com/wakairo/NewLang_Compiler/blob/0873819cabd3781582384891fc785d01b700056b/src/c17_division_usize.c#L221-L240)

### 代替と先行優先

混合Copyは現mainで利用できる実用代替です。今回の `usize` は実際に分子となり、値をcallee内の定数からcallerの知識へ移す負担と、追加引数・signatureの差が残ります。技術結果と別に、新しい目標逸脱は観測していません。Product GO #624 PAUSED、H1 #268 HOLD、UB-prevention audit locality未測定。

先行 #1653 は固定 `c602dd2668c0ceb429059e1c647ffc4bfd03e360` のDRAFT。C実質審査を個別GETしmaterial findingなし。自然初回Requiredは観測時点で3成功・3進行中、EARLY 2成功。先行側で対応を優先すべき重大所見はこの時点で確認されていません。 [#1653](https://github.com/wakairo/NewLang_Compiler/pull/1653) · [C実質審査](https://github.com/wakairo/NewLang_Compiler/issues/1650#issuecomment-7079180498) · [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45022224482) · [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45022224460) · [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45022224440)

### Raw

`/workspace/p1544-6afecbd5/p1654-bool-only-quantity-gate0/evidence` にcommand／stdout／stderr／status、最初の結果とno-clobber、生成物を保存。raw manifestは170ファイル、17,762 bytes、SHA-256 `2b9a72f7a7fc1dbc46bf957016ffed66e86fd97384c49b1ed3bf265987fa13b7`。

| artifact | bytes | SHA-256 |
|---|---:|---|
| 固定newlangc | 2534688 | `2530e469fd51dee7003f4e642f61ee347ee1b7cf9fe27164275f7c98f89fd929` |
| bool-only owned stdout | 1381 | `6f7eb322271584a93c07d2ee7237ce3c05ae541f3e66c40a420b75efc646e95b` |
| bool-only C17 stderr | 196 | `7db8ef905ca7d4a76da3ec125fed4acaeb35b901ef493a40fdf71cdef73d879b` |
| bool-only named 前後fingerprint（同一bytes） | 242 | `2736bc9718da0e4d8bb42d8c847f2a0dc715d0e4124afc4015c4286cab3f1d6b` |
| mixed owned stdout | 1454 | `eca9dea8dca0295abef678dc49899aa9eac1b8c4dbff085e58f2506aa36fb9f6` |
| mixed C17 | 1275 | `bbc0d3c373bf7c532ba648e4078008b944fc5d4d6f7b8a15aea15d4df2a6b63c` |
| mixed native 観測stdout | 62 | `7e12f064551fb14425deda20457dfef9db343c2dbbd6b1f839bb488acd8640be` |
| literal-control owned stdout | 953 | `05d57bb6d6d71cadadc0fe1c9abdffb9ddaf85dbe39714454487ea77e3544752` |
| literal-control C17 stderr | 205 | `8770b08575623b24c73d83eb7e217f16b36d27c52a41508b1fb09f9d16929b90` |

**STOP C**。既存のsole Pとして、必要な実装判断をCに返します。
