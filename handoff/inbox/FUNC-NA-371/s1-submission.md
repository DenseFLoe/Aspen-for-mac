# FUNC-NA-371 提交（阶段 1）

- task_id: FUNC-NA-371（#371 N/A 口径退回修订）
- worker: starter-t13/worker-371
- 基线：BASE=d1faeb69c2c06d8fe658c3400f5da5eb474a6fcc（review-20261122.md §#371）；旧提案 head=135a6f51cd66e14e35245d4621e179fd0ee5f90e，blob ac69c5cd8d2d85c3446d3ca4a6edc83a915e69d4
- 时间：2026-11-22（Asia/Shanghai）；口径文档 197→213 行（本轮在 §9.2 增补两段证据脚本后）
- 本目录只放状态与提交说明；口径文档与复算脚本在 handoff/policies/。

## 1 交付文件

| 文件 | 说明 |
| --- | --- |
| handoff/policies/functions-na.v1.md | 修订版口径（197 行，条款 1–5 + 流程 + 差异 + 输入指纹 + 证据与限制） |
| handoff/policies/recount-nan.py | 复算入口（312 行，纯标准库；模式 A=tree+index+mdroot，模式 B=带指纹 detail） |
| handoff/policies/ledger-counts.csv | PR 原样 blob 2fb03922…（sha256 99abb0bf…db631），输入 |
| handoff/policies/ledger-counts.fixed.csv | 修正 UNMAPPED_MD.md_functions_missing=2 后的台账 |
| handoff/policies/recount-nan.out.txt | 复算原始 stdout（exit 0） |
| handoff/policies/recount-nan.modeB.out.txt | 模式 B（detail）复算 stdout（exit 0） |
| handoff/policies/parse-native340-methoddefs.py | NATIVE-340 MethodDef/ImplFlags 独立解析脚本 |
| handoff/policies/parse-native340.out.txt | 该脚本原始 stdout（exit 0） |
| handoff/policies/parse-bfdyld-coff.py | BFDYLD.obj COFF 独立解析脚本 |
| handoff/policies/parse-bfdyld-coff.out.txt | 该脚本原始 stdout（exit 0） |
| handoff/inbox/FUNC-NA-371/s1-started.md | 任务开始状态 |
| handoff/inbox/FUNC-NA-371/s1-submission.md | 本文件 |

## 2 口径条款 1–4 对应位置（行号以 handoff/policies/functions-na.v1.md 为准）

| 裁定 | 条款 | 起始行 | 关键子条 |
| --- | --- | --- | --- |
| 1（纯托管才可 N/A；分列 MethodDef/IL/无体声明；超时失败=缺口） | 条款 1 | 19 | R1.1–R1.7 条件表 21；1.2 报告分列表 33；1.3 缺口定义 43；1.4 4 件 failed_analyze 45 |
| 2（删 COM descriptor⇒CLR、ImplMap=0⇒无原生；混合件查 ImplFlags/RVA/原生区域；NATIVE-340 实证） | 条款 2 | 47 | 2.1 删除判据 49；2.2 S1–S5 53；2.3 NATIVE-340 实证 60；2.4 后果 62 |
| 3（nonPE 区分工具失败/未恢复 vs 应分析成员；BFDYLD.obj 实证） | 条款 3 | 64 | 3.1 a/b/c 三元组 66；3.2 可含代码格式禁 N/A 71；3.3 BFDYLD 实证 73；3.4 状态用法 75 |
| 4（UNMAPPED_MD=31/2 无字段；两组口径；复算入口；2 件 native N/A 复核） | 条款 4 | 77 | 4.1 两组口径表 79；4.2 missing=2 88；4.3 ledger 核对 90；4.4 2 件 native 92；4.5 复算入口 97 |
| 5（保留逐件状态与阶段 2 单文件；三轴分列） | 条款 5 | 101 | 5.1 保留 103；5.2 三轴 105；5.3 N/A 与缺口 107；5.4 同 md 落点 109 |

判据原文位置核对命令（本次实测）：

~~~
$ grep -n '^## 条款' handoff/policies/functions-na.v1.md
19:## 条款 1（对应裁定 1）只有原件已证明纯托管实现，才可在原生函数专用字段写 N/A
47:## 条款 2（对应裁定 2）删除两条单一判据；混合件必须查元数据实现标志、RVA 与原生区域
64:## 条款 3（对应裁定 3）nonPE 记录须区分「PE 工具失败 / 未恢复」与「实际容器应分析的成员」
77:## 条款 4（对应裁定 4）修正 UNMAPPED_MD 计数；两组口径分列；给出复算入口
101:## 条款 5（对应裁定 5）保留既有逐件状态与阶段 2 单文件形态；三轴分列
~~~

## 3 计数复算：命令、exit code、原始 stdout

工作目录 _work/wf-20261120-aspen-batch。命令（python -B）：

~~~
python -B handoff/policies/recount-nan.py --ledger handoff/policies/ledger-counts.csv --tree out/tickets/tree_main.json --index out/tickets/remote_index.csv --mdroot out/cache/repo_final --write-ledger handoff/policies/ledger-counts.fixed.csv
~~~

exit code：0（RESULT PASS；EXPECT 15 项 mismatches=0）。原始 stdout（与 handoff/policies/recount-nan.out.txt 逐字节相同）：

~~~
INPUT ledger_sha256=99abb0bf485ce8ff444f31b5043c01e8ca0f822362cb186dc8cd53db16adb631
INPUT tree_root=f7959f39fd631692f14ecbbdfbf2496f543362b3 md_blobs=1346 index_sha256=5d313a891e6ce512a7c4954d394916b8950dfc765d867c3252825179de468dee index_rows=1315
FINGERPRINT git_blob_verify ok=1346 bad=0 missing=0 of 1346
CALIBER_A md_total=1346 na=567 numeric=777 other=0 no_field=2 missing_file=0
CALIBER_B item_total=1315 na=558 (CLR=470 nonPE=86 native=2) numeric=757
NATIVE_NA_ITEM sha256=4aef0066e8e4bad65018ec85d46b902303155ec2d8f049f3803e571005a90ff0 md=analysis/20261120-batch-driver/Aspen-Plus/[SystemFolder]/MSVBVM50.DLL.md
NATIVE_NA_ITEM sha256=898288bd3b21d0e7d5f406df2e0b69a5bbfa4f241baf29a2cdf8a3cf4d4619f2 md=analysis/20261120-batch-driver/Aspen-Plus/Windows/SysWOW64/msvbvm60.dll.md
UNMAPPED_MD total=31 na=9 numeric=20 other=0 no_field=2 missing_file=0
UNMAPPED_NO_FIELD md=analysis/20261120-batch-driver/INDEX.md
UNMAPPED_NO_FIELD md=analysis/20261120-batch-driver/README.md
LEDGER_DEFECT UNMAPPED_MD.md_functions_missing ledger='0' recomputed=2
LEDGER_CROSSCHECK mismatches=1 (listed above; UNMAPPED_MD.md_functions_missing=0 is the old hardcoded defect)
EXPECT check fields=15 mismatches=0
WROTE_LEDGER handoff/policies/ledger-counts.fixed.csv
RESULT PASS
~~~

模式 B（带指纹明细，不需镜像）同值复核：

~~~
python -B handoff/policies/recount-nan.py --ledger handoff/policies/ledger-counts.csv --detail out/policies/ledger-counts-detail.csv
~~~

exit 0；CALIBER_A/B、UNMAPPED_MD、LEDGER_DEFECT 行与模式 A 完全一致（detail sha256 d25e2c77…98232）。

## 4 原件证据复算（条款 2.3 / 3.3 的实测来源）

1) NATIVE-340：contents API 取 issue-materials/340/WrapSaveMergeNNFiles.dll@64670801de54e990f975aaeda06e89340c0e4e08，落本地临时文件后运行独立解析脚本（exit 0）：

~~~
python -B handoff/policies/parse-native340-methoddefs.py --dll WrapSaveMergeNNFiles.dll
size=107048 sha256=869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec
clr_dir_rva=0x6370 metadata_rva=0x6570 metadata_size=65396
TypeDef=563 MethodDef=188
ImplFlags by (CodeType, RVA==0): {(0, False): 167, (0, True): 2, (1, False): 19}
il=167 native=19 rva0=2 total=188
~~~

即 188 = 167 IL + 19 原生实现 + 2 无 RVA 声明；19 个原生实现 ImplFlags CodeType=1，与任务卡 188/19 一致。

2) BFDYLD.obj：取 Git blob eda5f8fe191dcdecc59d2bc0961cf882ad8b1318 落本地后运行 COFF 解析脚本（exit 0）：

~~~
python -B handoff/policies/parse-bfdyld-coff.py --obj BFDYLD.obj
size=5629 sha256=194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0
machine=0x8664 nsec=7 nsyms=51 optsz=0 characteristics=0x0000
sec1 .text    vsize=0 rawsize=1792 rawptr=300 nreloc=59 flags=0x60500020
sec2 .rdata   vsize=0 rawsize=128 rawptr=2092 nreloc=0 flags=0x40400040
sec3 .bss     vsize=0 rawsize=416 rawptr=0 nreloc=0 flags=0xc0600080
sec4 .data    vsize=0 rawsize=320 rawptr=2220 nreloc=0 flags=0xc0600040
sec5 .xdata   vsize=0 rawsize=184 rawptr=2540 nreloc=27 flags=0x40300040
sec6 .pdata   vsize=0 rawsize=120 rawptr=2724 nreloc=30 flags=0x40300040
sec7 .drectve vsize=0 rawsize=187 rawptr=2844 nreloc=0 flags=0x00100a00
symbol b'BFDYLD' section=1 value=0 type=0x20 storageclass=2
~~~

## 5 与旧提案的差异清单

1. D1 N/A 门槛：旧「理由 + 替代计数」即可 → 新要求 MethodDef 全表 ImplFlags/RVA、四数分列（总数/IL/原生/无 RVA）、token→IL/源码关联、零 IL 体逐项核。
2. D2 删除两条单一判据：旧 §4「COM descriptor 存在 ⇒ CLR」、旧 §3.1「ImplMap=0 ⇒ 无原生实现」。
3. D3 混合件：旧仅一句「混合件不得 N/A」→ 新增 S1–S5 五步与 NATIVE-340 实证（188=167+19+2，19 原生）。
4. D4 nonPE：旧只声明「工具链无此计数口径」→ 新增 a/b/c 三元组（工具与原始报错 / 未恢复成员 / 应分析成员清单），并以 BFDYLD.obj 为反例。
5. D5 计数构成：旧「1,346 = 1,315 + 29 副本 + 2 索引」与自身 stdout（items with >1 md path 0）矛盾 → 改为 1,315 件报告 + 29 份未映射报告 + 2 份索引文档 = 1,346。
6. D6 UNMAPPED_MD：旧脚本硬编码 md_functions_missing=0（旧文件第 105 行）→ 新值 2，附 recount-nan.py 与 EXPECT 15 项；ledger-counts.fixed.csv 已修正该行。
7. D7 三轴：旧未分「字段用途 / 工具缺口 / 整件状态」→ 新增 §0 与条款 5，禁止互替。
8. D8 主张降级：旧 §0「N/A 属结构性事实而非证据缺口」→ 改为「字段可 N/A，须附原件级证明与替代覆盖；缺口与整件状态另行记录」。
9. D9 新增逐件复核对象：MSVBVM50.DLL（4aef0066…）、msvbvm60.dll（898288bd…）2 件 native 写 N/A，且同名 msvbvm60.dll 另一版（20cbf883…）有 9,429 个函数，须按指纹区分。

## 6 限制

- 未重跑 1,315 件的 ILSpy 全量分析；md 数字按镜像原值统计（1346/1346 份 Git blob 与 tree 一致）。
- 条款 1.2 分列表、条款 2.2 的 S1–S5 需下一轮逐件补证：4 件 failed_analyze、2 件 native N/A、9 件 methods=0、全部混合件。
- 未核各 md 的 methods= 逐件值（仅抽样 1 份 CLR 样例：Interop.SLMErrorDialogLib.dll，MethodDef 9 / methods=0 / IL 18 行 / C# 62 行）；旧提案 §5 的 438 来源仍为〔无法判定〕。
- 本目录为只读镜像工作副本，未 push/commit；不修改 _work 以外目录，未动 逆向成果/，无常驻进程。
- 计数只用于台账核对，不替代 static-acceptance.v2 的整件判定。