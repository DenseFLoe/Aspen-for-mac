# NATIVE-340 s49 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ c1a0c0850352360315ab5842cbd00e3ce6f7b7f9
- 本轮 head：见 #13
- 保留：`jge`→`jl` 与立即数 `1`→`2` 两项注入（本轮继续跑，字段差异见下）

## 1. 幂等（连跑两次）

同一候选连续运行 `python -B tool/audit_340_s49.py` 两次，受影响文件的 SHA-256 与行数：

| 文件 | 行数 | SHA-256（两次相同） |
| --- | ---: | --- |
| calls.csv | 560（表头 + 559 记录） | `dbbf4bd41167ba5b…` |
| code/s{25,33,37,41,45}-unresolved-native.csv | 16（表头 + 15 行） | `8877fc5464a5…`（5 个文件同内容同哈希） |
| code/s49-audit.md | 生成页 | `366a820f5430…` |

`IDENTICAL True / ROWS_SAME True`。根因修复：0x20CC 的说明不再 `row["note"] += …` 追加，而是**切掉旧口径后缀后重写一次**（`note.split("。口径：")[0] + "。" + CALIBER`），所以重复运行不会越长越长。

## 2. 受影响面（不整表重写）

只改 1 行主表（`native,0x20CC`）+ 5 个真正嵌入该 note 的原生未决附表（s25/s33/s37/s41/s45-native）；其余表、覆盖表、原生函数表均未触碰。

## 3. EH 链（成对：整读 / 明确报错）

上游 `s45-eh-chain.py` 复跑：**9 节 returned=9、10 节 returned=10，末节 more=False**（旧实现 `guard > 8` 硬上限导致 10 节只读 9 节）。

本地成对用例（`tool/audit_340_s49.py`）：

| 用例 | 结果 |
| --- | --- |
| chain 1 / 2 / 9 / 10：整链读完，last.more=False | PASS |
| 末节声明后继但后继 RVA 落在所有节之外 | PASS（抛错，不返回部分结果） |
| 子句 try/handler 越界 | PASS（拒绝） |
| 未支持 kind | PASS（报 RVA/kind/size 并停止） |

## 4. 注入（逐字段，本轮复跑）

| 字段 | 基线 | jge→jl（0x28F7: 7D→7C） | imm 1→2（0x28FE: 01→02） |
| --- | --- | --- | --- |
| jcc_cc | jge | **jl** | jge |
| jcc_taken | False | **True** | False |
| al_immediates | {"0x28FD":1,"0x28F9":0} | 同基线 | **{"0x28FD":2,"0x28F9":0}** |
| al_for_slot | 0 | **1** | 0 |
| slot_skipped | True | **False** | True |

## 5. 指纹（所有修改完成后再生成）

```
python -B tool/gen_fingerprints_340.py --set receipt --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s29-fingerprints.json
python -B tool/gen_fingerprints_340.py --set round --base-head c1a0c0850352360315ab5842cbd00e3ce6f7b7f9 --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s49-fingerprints.json --rules-out handoff/inbox/NATIVE-340/code/s49-fingerprints.md
```

输出与路径集校验：

```
receipt: 51 files ; round: 75 files ; rules -> code/s49-fingerprints.md
receipt declared 51 actual 51 equal True
round   declared 75 actual 75 equal True
code/README.md in receipt True
```

排除规则（`code/s49-fingerprints.md` 里的「规则」一节）：文件名含 `fingerprints` 的文件（指纹 JSON 与其规则索引）不纳入；receipt 另排除 `*-started.md`/`*-submission.md`。**declared 集与按同规则算出的实际文件集逐路径相等，不只是数量相等。**

## 6. 判定（真实退出码，逐项对照）

```
$ python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340
checked 1105 coverage rows, 354 tool-native entries, 559 call records, 0 declared gaps
exit code: 2

$ pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original <原件> -Unit handoff/inbox/NATIVE-340
exit code: 0   (fingerprint 51 / mismatches 0)
```

PowerShell JSON 的 `fingerprint_mismatches` 为 `[]`（逐项为空），`fingerprint_count` 51 与路径集校验一致。
