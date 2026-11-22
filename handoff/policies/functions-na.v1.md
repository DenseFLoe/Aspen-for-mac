# functions=N/A 口径 v1（FUNC-NA-371 退回修订版）

> 依据：BASE 提交 d1faeb69c2c06d8fe658c3400f5da5eb474a6fcc 的 handoff/outbox/legacy-prs/review-20261122.md「#371 · 函数统计口径退回修订」；被修订的旧提案为 PR #371 固定 head 135a6f51cd66e14e35245d4621e179fd0ee5f90e 的 handoff/policies/functions-na.v1.md（blob ac69c5cd8d2d85c3446d3ca4a6edc83a915e69d4）。判据来源：handoff/standards/static-acceptance.v2.md、handoff/standards/native-coverage-evidence.v1.md、handoff/assignments/NATIVE-340.md。
>
> 本文是可执行的修订口径，不是汇报；与旧提案的逐条差异见 §7。旧提案「CLR/nonPE 的 N/A 属结构性事实而非证据缺口」的整体主张不再成立，改为「字段可以写 N/A，但必须有原件级证明与替代覆盖；缺口与整件状态另行记录」。

## 0 适用范围与三条独立记录轴

- 对象：批量台账 1,315 件（CLR 470 / nonPE 86 / native 759）与主树 1,346 份 md 报告；单件形态为阶段 2 的一份 md。
- 原生函数专用字段只有三个：functions、decomp_ok、decomp_fail。N/A 只允许写在这三个字段上，不允许写成整件结论。
- 三条互不替代的轴，任何一轴都不得代替另一轴：

| 轴 | 落点 | 作用 |
| --- | --- | --- |
| A 字段用途 | functions / decomp_ok / decomp_fail / methods | 说明该字段对本件是否有意义（N/A 或数值） |
| B 工具缺口 | status / reason / 已试工具与原始报错 / 未恢复成员 | 说明跑没跑、失败在哪、缺什么 |
| C 整件状态 | 静态验收结论 + 目录归属（待静态验收 / 通过 / 未通过 / 留原目录） | 说明该件能否算通过 |

## 条款 1（对应裁定 1）只有原件已证明纯托管实现，才可在原生函数专用字段写 N/A

1.1 允许写 N/A 的七个条件，须全部满足，缺一即判缺证据：

| 编号 | 条件 | 证据落点 |
| --- | --- | --- |
| R1.1 | 原件身份确认：SHA-256、字节数、原路径 | md 摘要表首行 |
| R1.2 | PE 头可读且 CLR 数据目录（data directory 14）非零、元数据根魔数 BSJB 有效 | 工具原始输出 |
| R1.3 | MethodDef 全表逐行核对 ImplFlags 的 CodeType（低 2 位：0=IL、1=Native、2=OPTIL、3=Runtime）与 RVA | metadata 行号（表偏移 + 行号） |
| R1.4 | 四数分列且相加等于 MethodDef 总数：MethodDef 总数 / 实际 IL 体数 / 原生实现数 / 无 RVA 声明数 | 见 1.2 模板 |
| R1.5 | 每个 MethodDef 的 token（0x06xxxxxx）在 coverage.csv 有 kind=method 行，指向 IL 清单或声明及恢复源码行号；原生实现行按 RVA 关联 native-functions.csv | native-coverage-evidence v1 §对应关系 2 |
| R1.6 | 同 md 内给出替代计数，且 methods= 明确标注为「有 IL 体的方法数」，不得当作 MethodDef 总数 | md §方法统计 |
| R1.7 | 「零个 IL 体」的结论仍须逐项核对 ImplFlags 与 RVA，不能由 methods=0 直接推出 | 逐行清单 |

1.2 报告必备分列表（缺一行即不完整）：

| 项 | 值 | 依据（行号 / 命令） |
| --- | --- | --- |
| MethodDef 总数 | 与元数据行数一致 | 表偏移、行数 |
| 实际 IL 体数 | RVA≠0 且 CodeType=0/2 的行数 | 逐行清单 |
| 原生实现数 | RVA≠0 且 CodeType=1 的行数 | 逐行清单 + native-functions.csv |
| 原件支持的无体声明及依据 | RVA=0 的行：abstract / P-Invoke（ImplMap）/ runtime / delegate / InternalCall | 每行的依据 |
| 成员 / IL / 恢复结果关联 | token 或 RVA → IL 行 / 恢复源码行 | coverage.csv 行号 |

1.3 工具超时、工具失败、未分析、字段缺失，一律是证据缺口，不是 N/A：分别记 status=failed_analyze + reason（如 ida_timeout 900s、ILSpy rc=70）、已试工具与原始报错、未恢复成员；remote_index.csv 的 status 必须同步。

1.4 本批 4 件 status=failed_analyze 按本条款复核：msvbvm60.dll、MSVBVM50.DLL（native，N/A 不成立）；Infragistics4.Win.UltraWinListView.v15.1.dll（CLR，ILSpy rc=70）、Microsoft.VisualStudio.Imaging.Interop.14.0.DesignTime（CLR）。

## 条款 2（对应裁定 2）删除两条单一判据；混合件必须查元数据实现标志、RVA 与原生区域

2.1 删除的判据（违反即判口径错误）：
- 删除「存在 COM descriptor（CLR 数据目录非零）即判 CLR 分流」——旧提案 §4 判定点 1。CLI 元数据与原生代码可同件共存。
- 删除「ImplMap=0 即无原生实现」——旧提案 §3.1。ImplMap 只描述 P/Invoke 导入表，不描述原生实现。

2.2 混合件五步判定（对每个含 CLI 元数据的原件执行）：
- S1 双读：DOS/PE 头、7 个数据目录（重点 14=CLR）、CLR 头、元数据根 BSJB。
- S2 全 MethodDef 行取三组位：RVA、ImplFlags（CodeType、Unmanaged 0x4、ForwardRef 0x10、PreserveSig 0x80）、Flags（Abstract 0x400、PInvoke 0x2000、Runtime 0x3000）。
- S3 RVA 映射到节：落在可执行节且 CodeType=1 ⇒ 原生实现，必须计入原生函数数并进 native 清单；CodeType=0/2 且 RVA 指向 IL 头 ⇒ IL 体。
- S4 原生区域：x64 异常目录（.pdata）BeginAddress、PE 入口、可执行导出与 S3 的原生 RVA 取并集（native-coverage-evidence v1 §对应关系 1）。
- S5 ImplMap、COM descriptor 仅作线索，不得单独证明「纯托管」或「无原生实现」。

2.3 实证（NATIVE-340）：WrapSaveMergeNNFiles.dll，107,048 字节，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。本件有 CLI 元数据（BSJB，runtime 2.5）、563 个 TypeDef、188 个 MethodDef，分列为 167 个 IL 体 + 19 个原生实现 + 2 个无 RVA 声明（188=167+19+2）。19 个原生实现的 ImplFlags=0x0085（CodeType=1 Native）；2 个无 RVA 的 ImplFlags=0x0080（CodeType=0，PreserveSig，属声明）。复算命令与原始输出见 §9.2。结论：有 CLI 元数据不等于纯托管，19 个原生实现必须计数、不得写 N/A。

2.4 后果：凡 S3 命中（至少 1 个原生实现）的件，functions= 必须是原生实现数，或写成「原生实现 N + 托管 IL 体 M」的分列形态；三字段 N/A 全禁；覆盖须同时交 native 行（按 RVA）与 method 行（按 token）。

## 条款 3（对应裁定 3）nonPE 记录须区分「PE 工具失败 / 未恢复」与「实际容器应分析的成员」

3.1 每份 nonPE 报告须写三元组，缺一项即不完整：
- a) 已试工具与原始报错（如 PEFormatError: 'DOS Header magic not found.'），写明工具与版本；
- b) 未恢复 / 失败的具体成员：哪些容器、节、符号或成员未分析；
- c) 该容器按格式实际应分析的成员清单（COFF：节表、符号表、重定位；归档：成员清单；其他：按格式列出）。

3.2 对能包含代码的格式（COFF .obj/.lib、静态库、归档、脚本容器等），不得因 PE 解析失败写 N/A：PE 解析器只覆盖 PE 映像，解析失败只说明工具范围，不能证明没有函数。

3.3 实证（BFDYLD.obj）：原件 SHA-256 194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0，5,629 字节；来源提交 ad53650f6071f83b133ede7bf847bc5096cd3b56 的 等待铁头猫/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Biofuel and Biochemicals/Biomass characterization/Biofeed converter.apwz!/BFDYLD.obj，Git blob eda5f8fe191dcdecc59d2bc0961cf882ad8b1318。直接解析 COFF：Machine=0x8664（AMD64）、NumberOfSections=7、NumberOfSymbols=51（含辅助记录）；.text rawsize=1,792 字节、重定位 59 条；外部函数符号 BFDYLD 在 SectionNumber=1、Value=0，Type=0x20（函数），StorageClass=2（External）。该件是含可执行代码的 AMD64 COFF，PE 解析失败不构成 N/A，须补 COFF 覆盖（.text 反汇编 + 符号→源码关联）。

3.4 nonPE 件仍按 status=unsupported_non_pe 登记缺口、不主张通过（static-acceptance.v2「结果放哪里」第 3 行：工具或依赖缺失 → 留原目录并记录）。该 status 只能填「工具缺口」轴，不能替代 3.1 三元组，也不能据此写「N/A 合法」。

## 条款 4（对应裁定 4）修正 UNMAPPED_MD 计数；两组口径分列；给出复算入口

4.1 两组口径，引用时必须带分母，禁止混用：

| 口径 | 分母 | N/A | 数值 | 无字段 |
| --- | --- | --- | --- | --- |
| 按件（remote_index 行，sha256 去重） | 1,315 | 558 = CLR 470 + nonPE 86 + native 2 | 757 | 0 |
| 按 md 文件（主树 analysis/20261120-batch-driver/**.md） | 1,346 | 567 = 470 + 86 + 2 native + 9 未映射 | 777 | 2（INDEX.md、README.md） |

其中「558 份按件写 N/A」里有 556 份属 CLR/nonPE（提案讨论的两类），另 2 份是 native 误用（见 4.4）；「567 个 N/A」多出 9 份来自未映射 md。1,346 = 1,315 件报告 + 29 份未映射报告 + 2 份索引文档；主树内同一 md 路径不在 index 中重复（旧脚本原始输出 items with >1 md path 0），所以 29 与 2 不能合并成「29 副本 + 2 索引」以外的口径。

4.2 UNMAPPED_MD 正确值：31 份 = 20 数值 + 9 N/A + 2 无字段，md_functions_missing=2，不是 0。旧 derive-counts.py 在其输出行硬编码 'md_functions_missing': 0（旧文件第 105 行），与逐份明细（no_field=2）矛盾，属脚本缺陷。修订后该行必须是 missing=2，且 missing 的定义是 no_field + missing_file。

4.3 与随附 ledger-counts.csv（blob 2fb03922dde447f68565743397189d6ec730226c）核对：CLR 470 件/470 N/A、nonPE 86/86、native 759 件含 2 N/A + 757 数值、TOTAL 1,346 份 md / N/A 567 / 数值 777 / missing 2，均与复算一致；唯一不符是 UNMAPPED_MD.md_functions_missing=0，须改为 2（修订产物见 ledger-counts.fixed.csv）。

4.4 必须逐件复核的 2 件 native 也写了 N/A：
- MSVBVM50.DLL，sha256 4aef0066e8e4bad65018ec85d46b902303155ec2d8f049f3803e571005a90ff0（[SystemFolder]），status=failed_analyze；
- msvbvm60.dll，sha256 898288bd3b21d0e7d5f406df2e0b69a5bbfa4f241baf29a2cdf8a3cf4d4619f2（Windows/SysWOW64），status=failed_analyze、reason=ida_timeout 900s。
同名 msvbvm60.dll 另有一版（[SystemFolder] 原件 20cbf8835f6fd3878acacbb7868f7b95a7aae6c2c9d5d0a926337ed31378fa7a）记 9,429 个函数：同名异版本必须按 SHA-256 区分，不得互相引用数值。这 2 件的 N/A 不成立，须补数或维持缺口登记，并同步 remote_index.csv 的 status。

4.5 复算入口（随本文交付）：handoff/policies/recount-nan.py，纯标准库，输入 ledger-counts.csv + 目录清单（tree_main.json，GitHub 递归树，1,346 个 md blob）+ remote_index.csv（1,315 行），输出 4.1 两组计数与 UNMAPPED_MD=31，并逐项对照 ledger。命令与期望输出见 §9.2；exit 0 表示与 EXPECT 15 项完全一致，exit 1 表示输入缺失或复算不符，计数不得发布。

4.6 计数只用于台账核对，不得替代覆盖证据：整件判定仍按 static-acceptance.v2「一件怎么验」2/3 与「结果放哪里」。

## 条款 5（对应裁定 5）保留既有逐件状态与阶段 2 单文件形态；三轴分列

5.1 保留：每件仍为阶段 2 的一份 md；既有 status 取值（processed / analyzed / failed_analyze / unsupported_non_pe）与目录归属不因本修订重刷；本修订只增加字段要求与证据要求，不拆文件、不改批次结构。

5.2 三轴在同一 md 内分列记录（同 §0 表），互不替代：字段用途回答「这个字段对本件有没有意义」，工具缺口回答「跑没跑、失败在哪、缺什么成员」，整件状态回答「能否算通过」。任何一格空缺不得用另一格内容填充。

5.3 N/A 与缺口的关系：N/A 仅在条款 1 成立时合法，且必须同时有本件的替代覆盖计数；缺口件即使写了 N/A，也必须记失败/未分析，不得据 N/A 判通过。

5.4 新增证据写进同 md 的固定小节（§方法统计、§字段与缺口、§覆盖关联），不新开逐件文件。

## 6 单件判定流程（8 步 checklist）

1. 身份：SHA-256、字节数、原路径（同名异版本按指纹区分）。
2. 容器识别：PE / CLR / COFF / 归档 / 其他；含 CLI 元数据者继续 3、4。
3. MethodDef 全表：RVA + ImplFlags + Flags 逐行。
4. 原生实现：S3 命中 → 按 native 标准计数，给 native 行（RVA + first_bytes）。
5. IL 体：CodeType=0/2 且 RVA 指向 IL 头 → 计数并给 token 行。
6. 无 RVA 声明：逐行写依据（abstract / P-Invoke / runtime / InternalCall）。
7. 字段写入：functions/decomp_ok/decomp_fail；N/A 仅在条款 1 成立时使用。
8. 三轴落账：字段用途、工具缺口、整件状态分别填写，互不替代。

## 7 与旧提案 functions-na.v1.md 的差异清单

| 编号 | 旧提案 | 修订版 |
| --- | --- | --- |
| D1 | §1 只要「理由 + 替代计数」即可写 N/A | 条款 1 要求 MethodDef 全表 ImplFlags/RVA 证据、四数分列、token 关联；零 IL 体也要逐项核 |
| D2 | §4 判定点 1「COM descriptor 存在 ⇒ CLR 分流」；§3.1「ImplMap=0 者无原生实现」 | 两条均删除；改为条款 2 的 S1–S5，ImplMap/COM descriptor 仅作线索 |
| D3 | 混合件只在「N/A 不成立情形 ④」一句带过 | 新增条款 2 五步与 NATIVE-340 实证（188=167+19+2），要求原生实现必须计数 |
| D4 | §3.2 nonPE 只声明「本项目工具链无此计数口径」 | 条款 3 要求 a/b/c 三元组；以 BFDYLD.obj（AMD64、7 节、51 符号记录、.text 1,792 字节）证明 PE 解析失败不等于无函数 |
| D5 | §2.2「1,346 = 1,315 + 29 副本 + 2 索引」，与原始 stdout（items with >1 md path 0）不一致 | 条款 4.1 明确 1,346 = 1,315 件报告 + 29 份未映射报告 + 2 份索引文档，29+2=31=UNMAPPED_MD |
| D6 | 随附脚本 UNMAPPED_MD.md_functions_missing 硬编码 0 | 条款 4.2 定为 2，并交付 recount-nan.py 与期望值（EXPECT 15 项） |
| D7 | 未区分字段用途 / 工具缺口 / 整件状态 | 条款 0 与 5 新增三轴表，禁止互替 |
| D8 | §0「CLR/nonPE 的 N/A 属结构性事实而非证据缺口」 | 改为「字段可 N/A，但须附原件级证明与替代覆盖；缺口与整件状态另行记录」，不再整体主张非缺口 |
| D9 | 未要求逐件复核 native 也写 N/A 的 2 件 | 条款 4.4 点名 2 件并给出 SHA-256、状态与同名异版本风险 |

## 8 输入清单与指纹

| 文件 | 指纹 | 用途 |
| --- | --- | --- |
| ledger-counts.csv（PR blob 2fb03922dde447f68565743397189d6ec730226c） | sha256 99abb0bf485ce8ff444f31b5043c01e8ca0f822362cb186dc8cd53db16adb631 | 分 kind 计数，作交叉核对 |
| tree_main.json（GitHub 递归树，未截断，20,809 项） | tree root f7959f39fd631692f14ecbbdfbf2496f543362b3 | 目录清单；md 清单 = analysis/20261120-batch-driver/**.md，1,346 份 |
| remote_index.csv | sha256 5d313a891e6ce512a7c4954d394916b8950dfc765d867c3252825179de468dee，1,315 行 | 按件口径映射（kind / sha256 / report_md） |
| md 镜像 out/cache/repo_final | 逐份 Git blob sha1 校验 ok 1346 / bad 0 / missing 0 | 字段原值（大小写不敏感匹配） |

## 9 证据与限制

9.1 证据三档：

| # | 结论 | 档 | 依据 |
| --- | --- | --- | --- |
| 1 | NATIVE-340 件 188 MethodDef = 167 IL + 19 Native + 2 无 RVA | 已实测 | 本次独立解析 PE/CLR 元数据，命令与输出见 9.2 |
| 2 | BFDYLD.obj 为 AMD64 COFF，7 节、51 符号记录、.text 1,792 字节，BFDYLD 为 External(Type=0x20) | 已实测 | 取 Git blob eda5f8fe…，sha256 194e88b4…，自写 COFF 解析，见 9.2 |
| 3 | md 1,346 / N/A 567 / 数值 777 / 无字段 2 | 已实测 | recount-nan.py CALIBER_A，Git blob 校验 1,346/1,346 |
| 4 | 按件 1,315 / N/A 558（470+86+2）/ 数值 757 | 已实测 | recount-nan.py CALIBER_B |
| 5 | UNMAPPED_MD 31 = 20+9+2，missing 应为 2；ledger 旧值 0 | 已实测 | recount-nan.py UNMAPPED_MD 行 + LEDGER_DEFECT 行 |
| 6 | 2 件 native 写 N/A（MSVBVM50.DLL、msvbvm60.dll） | 已实测 | NATIVE_NA_ITEM 两行（sha256 + 路径） |
| 7 | 各 md 的 methods= 逐件值与 9 件 methods=0 的逐项 ImplFlags | 未验证 | 本修订只抽查 1 份 CLR 样例，需按条款 1 逐件复跑 |
| 8 | 旧提案 §5 中 438 的来源 | 无法判定 | 缺当时所用台账/脚本，本轮不猜 |

9.2 复算命令与原始输出（在 _work/wf-20261120-aspen-batch 下执行，全程 python -B）：

复算计数：

~~~
python -B handoff/policies/recount-nan.py --ledger handoff/policies/ledger-counts.csv --tree out/tickets/tree_main.json --index out/tickets/remote_index.csv --mdroot out/cache/repo_final --write-ledger handoff/policies/ledger-counts.fixed.csv
~~~

实际 stdout（exit 0）：

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

NATIVE-340 复算（脚本 handoff/policies/parse-native340-methoddefs.py，原件经 contents API 取 issue-materials/340@64670801）：

~~~
python -B handoff/policies/parse-native340-methoddefs.py --dll WrapSaveMergeNNFiles.dll
size=107048 sha256=869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec
clr_dir_rva=0x6370 metadata_rva=0x6570 metadata_size=65396
TypeDef=563 MethodDef=188
ImplFlags by (CodeType, RVA==0): {(0, False): 167, (0, True): 2, (1, False): 19}
il=167 native=19 rva0=2 total=188
~~~

BFDYLD.obj 复算（脚本 handoff/policies/parse-bfdyld-coff.py，原件为 Git blob eda5f8fe191dcdecc59d2bc0961cf882ad8b1318）：

~~~
python -B handoff/policies/parse-bfdyld-coff.py --obj BFDYLD.obj
size=5629 sha256=194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0
machine=0x8664 nsec=7 nsyms=51 optsz=0 characteristics=0x0000
sec1 .text    vsize=0 rawsize=1792 rawptr=300 nreloc=59 flags=0x60500020
...
symbol b'BFDYLD' section=1 value=0 type=0x20 storageclass=2
~~~

9.3 限制：
- 本轮未重跑 1,315 件的 ILSpy 全量分析，md 内数字按镜像原值统计（镜像逐份 Git blob 与 tree 一致，ok 1346）。
- 条款 1.2 的分列表与条款 2.2 的 S1–S5 需在下一轮逐件补证（重点 4 件 failed_analyze、2 件 native N/A、9 件 methods=0、全部混合件）。
- 本修订不改变阶段 2 单文件形态与既有逐件状态；需要重刷的只有 2 件 native N/A 的字段与 4 件 failed_analyze 的 status 同步。
