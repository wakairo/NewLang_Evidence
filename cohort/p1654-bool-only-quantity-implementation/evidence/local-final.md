## P1654 LOCAL FINAL · STOP LOCAL / C

C の PRIVATE IMPLEMENTATION GO に基づき、固定 `0873819cabd3781582384891fc785d01b700056b`（tree `85b750f35d257a9f18cde3a38f97e11696b9919f`、Draft17.38）上の別 private worktree で完了。Compass → Value §1.1/1.3 → Process → CURRENT_SPEC を照合済み。ACTUAL RESUME は個別GETで全文一致。公開判断は C に返す。 [C GO](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079288239) · [ACTUAL RESUME](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079322980)

### 固定候補

- Branch `p1654-bool-only-quantity-private`、HEAD `972a61bc31522cf60d31bb5847e29a3f002e9d9d`、tree `f84987e8d4c063decc27b9547c570d88d22a2b87`、単親 `0873819cabd3781582384891fc785d01b700056b`。clean worktree。固定 clang-format 23.1.3 と `git diff --check` 成功。
- 8 paths。変更 `CMakeLists.txt`、`src/usize_addition.c`、`src/division_usize_internal.h`、`src/c17_division_usize.c`。追加 `tests/p1654/{CMakeLists.txt,probe.c,run.py,selection.nl}`。full-index 差分 33,852 bytes、SHA-256 `8d8ead86df726ad0b1c352e03e997264cab850f9ef0bfcf799c2ccd5d00192be`。

### 到達範囲

- 通常の `main() -> unit` の直下で、名前付き Bool Copy を純粋な登録済み `(bool) -> usize` helper に渡す。helper はその formal を Copy して 2 normal arms の `usize` リテラルから選ぶ。IF が直接 tail の形と、単一の let に受けて tail で Copy する形を測定した。
- 既存の予約済み／確定済み caller BODY から exact actual の slot と fresh formal の binding を照合。元 IF・各 canonical ARM の別 world、既存の quantity plan・result seal・公開 owned view と C17 emitter を再利用した。新しい issuer／world／schema／公開 API や Draft の差分は 0。両入力で SOURCE・登録・CHECK 成功、`machine_proved=1`。2つの call は別々の BODY と result slot を持ち、各 Copy slot が対応する formal に結び付く。両方の IF join は保守的に Unknown、native は実条件で選ぶ。
- 混合 `(usize, bool) -> usize` 対照は基点と owned 観測・C17 がバイト一致。元の単独 bool＋局所分子除算は CHECK=0、公開局所 division view/valid は4件成立、全体は `machine_proved=0`、C17=4。元の分子出所条件を保った。混合形による算術の回避策には追加 usize 引数と caller 変更が要る。後続の採用判断は別途 C に依存する。

### 実測

- 2つの正例で stdout C17 と named C17 がバイト一致。元の C17 と、既存 call の直後に観測用 print を追加した C17 を、strict GCC／Clang O0・O2 でそれぞれコンパイル・実行。各構成16 native runs、normal／ASan／UBSan frontend の3構成で計48。元の出力は空で exit 0、観測出力は2つの call site の source 順で true→11、false→19。基点の混合対照は別途8 native runs で 11→19。
- inline 比較 actual、局所分子の算術 arm、別 helper から呼ぶ形は CHECK=0／C17=4。3例と元の除算例で named 出力の bytes・inode・時刻を保全。3構成とも bool helper result seal（10,368 bytes）、entry result world（38,593 bytes）、C17 staging（19,968 bytes）で意図した割当失敗を各1 hit。CHECK は元 context・anchor にロールバックし、C17 は出力 slot を保全。通常再試行は CHECK／C17 とも成功。
- selected CTest は同一候補で normal **127/127**、ASan/LSan **127/127**、UBSan **127/127**。今回と先行 quantity・Return・custody 回帰を含む。全リポジトリ CTest・SDK・audit locality は測定範囲外。

### 凍結証拠

- 元 FIRST／GATE0 FINAL はそのまま。元 raw 170件を再照合済み。manifest 17,762 bytes、SHA-256 `2b9a72f7a7fc1dbc46bf957016ffed66e86fd97384c49b1ed3bf265987fa13b7`。未変更 base を先に再測定し、単独 bool の元算術例と補助定数例の CHECK=0／C17=4、混合の C17=0 を再現。 [FIRST](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079183947) · [GATE0 FINAL](https://github.com/wakairo/NewLang_Compiler/issues/1654#issuecomment-7079252802)
- 新しい source／予測は初回テストより前にローカル凍結。let-copy 353 bytes `dcbdcd3de823277bb58e725db5f229da43537f7ee3a0733237ce7163bfbcca87`（元定数対照と同一）、direct-tail 328 bytes `bd6b47aaee229362ad14f36fb33a61fd4940a3e7ac5a36db31efd2270d84a4c4`、予測 1,286 bytes `0499562136274ecceb0a3b5ecfb8a5feea8991f6ba041b08c1c8eb235e7d25ac`。負例の bytes/SHA は `evidence/new-first/source-identity.stdout`。
- private raw は `/workspace/p1544-6afecbd5/p1654-bool-only-quantity-implementation/evidence/`。raw manifest 1,255件／175,108 bytes、SHA-256 `11f7b16dcc3e33815935aeaae83a46a171b50612b4665df4dc2d7de54400b8ca`。元基点の再測定、途中の手順ログ、最終候補の cohort 別 command/stdout/stderr/status と native を保存。

直前の GET で実 main は固定 SHA と一致。先行 #1653 は DRAFT の `c602dd2668c0ceb429059e1c647ffc4bfd03e360`、Required 5成功＋ASan 1進行中、EARLY 2成功。先行の重大所見または自身の新しい停止指示は対象 Issue の確認範囲で未観測。独立 F/R 原資料未読。今回の候補は private に固定。 **STOP LOCAL / C**。 [先行 #1653](https://github.com/wakairo/NewLang_Compiler/pull/1653) · [FULL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45022224482) · [PARTIAL](https://github.com/wakairo/NewLang_Compiler/actions/runs/45022224460) · [EARLY](https://github.com/wakairo/NewLang_Compiler/actions/runs/45022224440)
