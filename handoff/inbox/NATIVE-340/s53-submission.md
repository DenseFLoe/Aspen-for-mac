# NATIVE-340 s53 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ ac9d6b69cdcfe99f9b2147e0c8c12f01787bae93
- 本轮 head：见 #13

## 1. EH 各节逐节对照（25 节，全部 in_range）

逐节表见 `code/s53-eh-sections.csv`（方法 / 节序号 / RVA / size / entry / 子句数 / more / 所在 PE 节 / 节末 / in_range）。
真件 25 个 EH 方法各 1 节，全部满足：

- 每节 RVA 落在其 PE 节的映射范围内，且 `RVA + size <= 节末`（`in_range=true`）；
- `size == 4 + entry*clauses`（fat entry=24、small entry=12）；
- 每节 `more=false`（单节链）。

## 2. 正反输入（成对，不部分成功）

| 输入 | 输出 |
| --- | --- |
| 9 节链（前 8 节 `0xC1`、末节 `0x41`） | 读取 9 节；逐节 RVA=`base+28*i`、size=28、clauses=1、more=(i<8) |
| 10 节链 | 读取 10 节；同上，末节 more=False |
| 末节声明 32 字节（比映射多 4 字节） | **ValueError**，消息含 `overruns ... 4 bytes outside the mapped range` |
| 链走后继落在映射之外 | **ValueError**，不返回残缺列表 |
| 未支持 kind | `UnsupportedSection`，报 RVA/kind/size |

上游 `s45-eh-chain.py` 复跑：`expected=9 returned=9`、`expected=10 returned=10`、`last_more=False`。

## 3. 两项混合布局用例（统一口径）

用同一个构造器 `chain_case([kind1, kind2])` 生成两种混合链，断言完全一致：

| 用例 | 断言 |
| --- | --- |
| `fat|0x80 + small` | 2 节；entry 24/12；clauses 1/1；more True/False |
| `small|0x80 + fat` | 2 节；entry 12/24；clauses 1/1；more True/False |

## 4. 分支事实（解码生成，不写死）

主表 0x20CC 的 callee/note 现由 `gate_facts` 的字段拼装：条件码/opcode/目标/落空地址、两分支 AL 立即数、节 Characteristics 与 signed、消费端极性、正分支范围，全部来自字节解码（`branch_note()`）。上一版 note 里「取 0x28FD」这类固定措辞已删除。

注入（保留）：`jge`→`jl` 使 `jcc_cc=jl / jcc_taken=True / al_for_slot=1 / slot_skipped=False`；立即数 `1`→`2` 使 `al_immediates[0x28FD]=2`。

## 5. 幂等

同一候选连跑两次：`calls.csv`（560 行）、5 个原生附表（各 16 行）、`code/s53-audit.md`、`code/s53-eh-sections.csv` 的 SHA-256 完全相同（`IDENTICAL True / ROWS_SAME True`）。

## 6. 指纹（最后生成，从新 head 逐项验证）

```
python -B tool/gen_fingerprints_340.py --set receipt --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s29-fingerprints.json
python -B tool/gen_fingerprints_340.py --set round --base-head ac9d6b69cdcfe99f9b2147e0c8c12f01787bae93 --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s53-fingerprints.json --rules-out handoff/inbox/NATIVE-340/code/s53-fingerprints.md
```

路径集：declared 与按同规则算出的实际集合逐路径相等（receipt 53 / round 81，README 在集内）。从新 head 全量下载后重跑两条命令：`path_missing [] / path_extra [] / hash_diff []`。

## 7. 判定（真实退出码，head 副本）

```
check-native-coverage.py  exit 2   1105 coverage / 354 native / 559 calls / 0 gaps
pwsh check-s29-446.ps1    exit 0   fingerprint 53 / fingerprint_mismatches []
```
