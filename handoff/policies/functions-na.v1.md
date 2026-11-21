# `functions=N/A` 口径提案 v1（CLR / nonPE 两类件）

> 依据：主干 `main@f7959f39fd631692f14ecbbdfbf2496f543362b3`（2026-11-21）。
> 上游判据：static-acceptance「一件怎么验」2/3、「结果放哪里」；reverse-execution-reference §3.1；acceptance-sop §3（P4-2 覆盖完整 / P4-3 缺口已处理）、§8（三档证据）；reverse-execution-workflow §3；project-instructions「不可省略的约束」「逆向工具」。
> 本文件是一份**可直接采纳或否决的表述**，不是汇报。数以台账可复跑结果为准，未为对齐任何既有数字改数。

## 0. 一句话表述（可直接采纳/否决）

> **建议采纳：本批 1,315 件中 CLR 470 件与 nonPE 86 件的 `functions=N/A` 属结构性/口径性事实而非证据缺口——CLR 件不存在可数的 native 函数体，其覆盖记录由同一份 md 内的 MethodDef/IL 体计数承担（470 件里 460 件给了非零 `methods=`，9 件为 `methods=0` 的纯声明程序集，1 件因 ILSpy `rc=70` 未记录），nonPE 件不存在 PE/IL 函数体并已按 `status=unsupported_non_pe` 显式登记缺口、不主张验收通过；其余 759 件 native 必须给出 `functions=` 数值，本批仅 `msvbvm60.dll`、`MSVBVM50.DLL` 两件因 IDA 900s 超时缺数值、按 `status=failed_analyze` 记缺口而非 N/A；采纳后须同时生效一条硬约束——任何 `functions=N/A` 必须同行给出**理由**且附**同格式替代计数**（CLR）或 `status=unsupported_non_pe`（nonPE），二者缺一即判缺证据，不认 N/A。**

若否决，请指明要求的口径（例如「CLR 按 MethodDef 数写入 `functions=`」「nonPE 一律不留 functions 字段」），我方按新口径重刷 556 份 md。

## 1. 适用范围

| 类 | 边界（适用 N/A） | 适用条件（缺一即不成立） |
| --- | --- | --- |
| CLR（`kind=CLR`，PE 内有 CLR 头、MethodDef 由 ECMA-335 元数据解析） | 仅 `functions=` / `decomp_ok=` / `decomp_fail=` 三个 **native 函数级字段** | ① 理由写明「托管程序集，无 native 函数概念」；② 同一份 md 内有替代计数：MethodDef 总数 + 有 IL 体方法数（`methods=`）+ IL 清单/反编译行数；③ 件本身仍按 P4 五条验收（不是「写了 N/A 就算过」） |
| nonPE（`kind=nonPE`，无 DOS/PE 头：`.gitattributes` / `.csv` / `.obj` / `.lib` 等） | `functions=` 仅表示「本项目工具链（IDA/Ghidra/ILSpy）无此计数口径」 | ① 同 md 有已试工具 + **原始报错**（本批实测 `PEFormatError: 'DOS Header magic not found.'`）；② `status=unsupported_non_pe` 显式登记；③ 全文**不得**出现 `analyzed` / 逆向完成 / `01-completed` 主张（本批 86 件全部落 `02-incomplete/`） |
| **N/A 不成立的情形**（写 N/A 即等于缺证据） | ① 原生 PE 件（本批 2 件实例，见 §2.3）；② CLR 件但 md 无替代计数（本批 1 件：`methods=未在本件报告中记录`）；③ nonPE 件却主张已完成/`analyzed`；④ 混合程序集（含原生部分）——其原生函数必须由 Ghidra 计数，不得 N/A；⑤ 工具超时/崩溃导致未产出（属 `failed_analyze`，不是格式不适用）；⑥ 只是没跑工具。 | — |

对应上游：acceptance-sop §3 P4-2 要求「类型/方法实现、原生代码区域与函数、必要资源都有预期-输出覆盖记录」——CLR 件的「方法实现」覆盖记录即 MethodDef/IL 计数，**上游要的是覆盖记录，不是某个特定字段名**；P4-3 要求缺口「已解释」，nonPE 走 `status=unsupported_non_pe` + 原始报错即满足「已解释」，但**不构成「已通过」**（static-acceptance「结果放哪里」第 3 行：拿不到/缺工具依赖 → 留原目录、记录缺什么）。

## 2. 计数与推导

### 2.1 推导命令（只读输入，输出落 `out/policies/`）

~~~bash
cd "D:/deepseekharness workspace/_work/wf-20261120-aspen-batch"
python -X utf8 out/policies/derive-counts.py        # 产物：ledger-counts.csv / ledger-counts-detail.csv
python -X utf8 out/policies/derive-counts.py > out/policies/derive-counts.out.txt 2>&1
~~~

输入（全部只读）：`out/B2/manifest-b2.csv`、`out/tickets/remote_index.csv`、`out/tickets/tree_main.json`、md 镜像 `out/cache/repo_final/`、`out/R1/ledger-clr.csv`、`out/R1N/ledger-native.csv`。

**镜像可信性（先证后用）**：本地镜像 1,346 份 md 逐份算 git blob sha1，与 `tree_main.json`（main@f7959f39）同名 blob sha 比对：

~~~text
git blob sha check vs tree_main@f7959f39: ok 1346 bad 0 missing 0 of 1346
~~~

即：下表的字段统计就是对 `main` 全量 md 的统计，不是抽样推算。

### 2.2 台账真值（`out/policies/ledger-counts.csv` 原样）

~~~text
kind,manifest_items,index_items,index_status,md_reports,md_functions_na,md_functions_numeric,md_functions_other,md_functions_missing,md_extra_paths_vs_index
CLR,470,470,processed=470,470,470,0,0,0,0
nonPE,86,86,unsupported_non_pe=86,86,86,0,0,0,0
native,759,759,analyzed=759,759,2,757,0,0,0
TOTAL,1315,1315,analyzed=759;processed=470;unsupported_non_pe=86,1346,567,777,0,2,0
UNMAPPED_MD,0,0,,31,9,20,0,0,31
~~~

关键推导（脚本原始输出行）：

~~~text
manifest kinds {'nonPE': 86, 'native': 759, 'CLR': 470} rows 1315
index status {'processed': 470, 'unsupported_non_pe': 86, 'analyzed': 759} rows 1315
tree md 1346
field by kind x class {('native','numeric'):757, ('CLR','na'):470, ('nonPE','na'):86,
                      ('UNMAPPED','numeric'):20, ('UNMAPPED','na'):9, ('UNMAPPED','no_field'):2,
                      ('native','na'):2}
~~~

口径换算（三个数互相对得上，无一件漏账）：

- `1,315 件 = 759 native + 470 CLR + 86 nonPE`（manifest 与 remote_index 逐件同 kind，0 冲突）。
- `1,346 份 md = 1,315 件报告 + 29 份同件多路径副本 + 2 篇索引文件`（`analysis/20261120-batch-driver/INDEX.md`、`README.md`，无 `functions=` 字段）。29 份副本按 md 正文内的原件 SHA-256 回连：20 native（有数值）+ 8 CLR + 1 nonPE（N/A）。
- `functions 字段：数值 777 / N/A 567 / 无字段 2`，`567 + 777 + 2 = 1,346`。
- **按件去重（1,315 件，一件一档）**：N/A 556 件（CLR 470 + nonPE 86 ＝ 两类件 100% 覆盖）、有真实数值 757 件（native）、**矛盾 2 件**（native 却写 N/A，见 §2.3）。
- CLR 内部替代计数分布（按件去重后仍 470 件，逐件一档）：非零 `methods=` **460 件** + **9 件 `methods=0`**（纯声明/纯 interop 程序集、有 0 个 IL 体方法）+ `methods=未在本件报告中记录` 1 件（`Infragistics4.Win.UltraWinListView.v15.1.dll`，`status=failed_analyze`，ILSpy `rc=70`）。
- 数值件自洽性：777/777 份满足 `functions = decomp_ok + decomp_fail`（0 违例）。
- `status=failed_analyze` 共 4 件：`msvbvm60.dll` / `MSVBVM50.DLL`（native，`reason=ida_timeout 900s`）、`Infragistics4...UltraWinListView` / `Microsoft.VisualStudio.Imaging.Interop.14.0.DesignTime`（CLR）。

### 2.3 自审发现的 2 处「N/A 不成立」（本提案的反例，一并交上游）

~~~text
msvbvm60.dll.md   : - functions=N/A（native：未产出 native 函数统计，见 md 内 reason）
                  : - status=failed_analyze
                  : - reason=ida_timeout 900s
MSVBVM50.DLL.md   : - functions=N/A（native：未产出 native 函数统计，见 md 内 reason）
                  : - status=failed_analyze
                  : - reason=ida_timeout 900s
~~~

这两件是**原生 PE**，N/A 系工具超时所致，按 §1 应判**缺证据/缺口**（已记 `failed_analyze`，但 `remote_index.csv` 里仍写 `status=analyzed`，状态口径需同步）。它们既证明该口径可被反例证伪，也说明「先判 kind 再判 N/A」的抽查顺序是必要的。

## 3. 为什么 N/A ≠ 缺证据

### 3.1 CLR（470 件，100% N/A）

**结构性理由**：`functions/decomp_ok/decomp_fail` 是 T1N 原生链（IDA 9.5 / Ghidra）的统计量，度量对象是**机器码函数**。托管程序集的可执行体是 CIL，计数单位是 ECMA-335 元数据里的 **MethodDef**，不是 native 函数；用 IDA 数不出「函数」，因为文件里根本没有可选的原生函数体（project-instructions「逆向工具」：纯 .NET 走 ILSpy + IL 核验，原生部分才走 Ghidra；本批 CLR 件中 `ImplMap=0` 者无原生实现）。故 `functions=` 对 CLR 不成立，而**覆盖证据在另一列**：同一份 md 给出 MethodDef 总数、有 IL 体方法数、IL 字节数、IL 清单行数、反编译行数，正好满足 P4-2「托管程序集核对类型及方法实现」（reference §3.1）。

**抽样原文行**（`Interop.SLMErrorDialogLib.dll.md`，14,888 B，SHA-256 `13e1b4ba…8534f`〔已实测〕）：

~~~text
 5 | - tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
 6 | - functions=N/A（CLR 托管程序集，无 native 函数概念；methods=0）
 7 | - decomp_ok=N/A（CLR：无函数级反编译统计）
 8 | - decomp_fail=N/A（CLR：无函数级反编译统计）
~~~

同件下文（即「N/A 的替代计数」，也是上游抽查要看的行）：

~~~text
方法统计 | 9 = 0（有 IL 体）+ 4（抽象）+ 5（运行时实现/委托）+ 0（P/Invoke）   〔实测〕
IL 清单  | il/002_Interop.SLMErrorDialogLib.dll.il.txt，18 行，MethodDef 9 条（全量，逐条指令）
反编译   | decompiled/002_Interop.SLMErrorDialogLib.dll.cs.txt，62 行（ILSpy 全量 stdout）
MethodDef 总数 | 9    | 有 IL 体方法 | 0 | IL 字节合计 | 0
~~~

**注意一处极易误读的口径**：字段行里的 `methods=0` 指「**有 IL 体**的方法数 = 0」，**不是 MethodDef 总数 = 0**（本件 MethodDef=9，4 抽象 + 5 运行时实现，无 IL 体）。9 件 `methods=0` 的 CLR 件正是「连一个 IL 函数体都不存在」的极端情形——它们连「可数的 IL 函数体」都没有，N/A 在这里是**双重结构性**的（既非 native 函数，也无 IL 体）。若上游要求数值，我方建议该列写 `functions=9 (MethodDef)` / `functions=0 (ILBody)` 这类显式带单位的形态，而不是单纯数字（避免与 native 的 IDA 函数数混为一谈）。

### 3.2 nonPE（86 件，100% N/A + 100% 显式登记缺口）

**结构性理由**：86 件无 PE 映像（无 DOS 头 / 无节表 / 无 CLR 头），因此**不存在 IL 函数体**（IL 只存在于 PE 的 CLR 元数据中），也不存在 IDA/Ghidra 可识别的函数容器；PE/CLR 解析器在第一步就失败并给出可复现原始报错。**但要说清边界**：COFF 目标文件（`.obj` / `.lib`）本身可能有函数符号，只是本批未引入 COFF 解析链——所以 nonPE 的 N/A 只能声明「**本项目工具链无此计数口径**」，**不能**声明「该件已确认没有函数」。正因为如此，该 86 件一律同时写 `status=unsupported_non_pe` 并留在 `02-incomplete/`，按 P4-3「缺口已解释」处理，**不主张通过**（static-acceptance「结果放哪里」第 3 行）。

**抽样原文行**（`BFDYLD.obj.md`，5,629 B，SHA-256 `194e88b4…03ec0`〔已实测〕）：

~~~text
 5 | - tool=pefile 2024.8.26
 6 | - functions=N/A（native：未产出 native 函数统计，见 md 内 reason）
 7 | - decomp_ok=N/A（native：无函数级反编译统计）
 8 | - decomp_fail=N/A（native：无函数级反编译统计）
21 | | 状态 | status=unsupported_non_pe | 〔实测〕 |
28 | 已试工具（逐条为实际执行，含原始报错）：
32 | | dnfile.dnPE | 原始报错 PEFormatError: 'DOS Header magic not found.' |
33 | | pefile.PE   | 原始报错 PEFormatError: 'DOS Header magic not found.' |
65 | dumps: 无（非 PE（COFF 静态库/对象归档），本轮不产出 dump）
~~~

**native 对照件**（证明「有函数就一定有数」，`CxsInteropComV22.dll.md`〔已实测〕）：

~~~text
16 | - tool=IDA 9.5
18 | - functions=650
19 | - decomp_ok=650
20 | - decomp_fail=0
~~~

## 4. 上游可采纳的三个判定点（抽查一件即可确认 N/A 是否成立）

1. **先判格式，再判 N/A。** 取原件跑 `pefile.PE`（或 `dnfile.dnPE`）：有 DOS/PE 头且 COM descriptor 存在 ⇒ CLR 件，N/A 只允许出现在 `functions/decomp_*` 三列，且**必须**在同 md 找到 `MethodDef 总数` 与 `methods=` 数字（抽查 `Interop.SLMErrorDialogLib.dll.md`：MethodDef 9 / methods=0 / IL 18 行 / C# 62 行）。找不到 ⇒ 判缺证据。
2. **native 件出现 N/A 直接判缺证据。** 不接受任何理由（超时、崩溃、忙）——超时应落 `status=failed_analyze`，且 `remote_index.csv` 的状态必须同步。本批反例 2 件：`msvbvm60.dll`、`MSVBVM50.DLL`。同时查等式：`functions = decomp_ok + decomp_fail`（本批 777/777 成立，任取一份 numeric md 即可复跑）。
3. **nonPE 件看「没有主张」而不是看 `functions`。** 该件 md 必须①有 `status=unsupported_non_pe`；②有已试工具 + **原始报错原文**；③输出目录是 `02-incomplete/`、全文无 `analyzed` / 逆向完成字样。三条全中 ⇒ N/A 合法（口径外 + 缺口已解释）；缺一条 ⇒ 判缺证据或改判。抽查 `BFDYLD.obj.md` 一次即可确认。

## 5. 口径差异（任务书 438 CLR + 78 nonPE vs 台账真值）

**真值（可复跑，不改数）**：CLR **470**、nonPE **86**（全量 1,315 件口径）。

| 口径 | CLR | nonPE | native | 合计 | 与任务书 |
| --- | ---: | ---: | ---: | ---: | --- |
| A 全量（manifest/remote_index 行数） | 470 | 86 | 759 | 1,315 | — |
| B 需处理件（排除 `manifest.already_done=true`：CLR 31 / native 19 / nonPE 8） | **439** | **78** | 740 | **1,257** | nonPE 78 精确相符；CLR 439 vs 438 差 1 |

~~~text
already_done x kind Counter({('native','false'):740, ('CLR','false'):439, ('nonPE','false'):78,
                            ('CLR','true'):31, ('native','true'):19, ('nonPE','true'):8})
~~~

- **78 的来源已坐实**：`86 − 8（already_done=true）= 78`，与任务书 78 nonPE 一字不差；也与 `issue_reply.md` 的「78 件 unsupported_non_pe」同源。
- **438 不能从台账复跑出来**：`470 − 31 = 439`，差 1。为凑 438 需要「32 = 31 已完 + 1 件其它」，但本批 CLR 的 `failed_analyze` 是 **2 件**（437），`manifest` 内大小写重复组 **0 组**（去重后仍 470），`analysis_key` 唯一 1,315 条、无重复键。故 438 无法由任何台账列的组合复现 →〔无法判定〕。
- **最可能的来源（未证实）**：任务书用的是 1,257 行「本批需处理」视图（与 `issue_reply.md` 的 `idxw_rows=1257` 一致），在该视图里 CLR 少算 1 件（439→438）；或写作时引用的是更早一版台账。要给准数需任务书作者提供当时所用文件与脚本，我方不猜、不凑。
- **1,346 与 1,344 的差**：`1,346 = 1,315 + 29 同件多路径副本 + 2 篇索引 md（INDEX.md/README.md）`；`issue_reply.md` 的 1,344 = 1,315 + 29（未计 2 篇非报告 md）。两数都自洽，差别是「是否把 2 篇索引文件算作 md 报告」。
- **不可混用**：`438/78` 是两个不同分母上的数（438 疑似 1,257 视图、78 同时等于全量与视图差），本文件所有结论一律以 A 口径（1,315 件）为真值；引用时必须带分母。

## 6. 证据三档标注

| # | 结论 | 档 | 依据（命令 + 原始输出行 / 产物） |
| --- | --- | --- | --- |
| 1 | 件数 1,315 = native 759 / CLR 470 / nonPE 86，manifest 与 index 逐件同 kind | 已实测 | `python -X utf8 out/policies/derive-counts.py` → `manifest kinds {'nonPE': 86, 'native': 759, 'CLR': 470} rows 1315`；`out/policies/ledger-counts.csv` |
| 2 | 主树上 1,346 份 md（含 29 副本 + 2 索引），且本地镜像与 main@f7959f39 逐字节一致 | 已实测 | `git blob sha check vs tree_main@f7959f39: ok 1346 bad 0 missing 0 of 1346` |
| 3 | CLR 470/470、nonPE 86/86 写 `functions=N/A`；native 757 件有数值、2 件误用 N/A | 已实测 | `field by kind x class {('CLR','na'):470, ('nonPE','na'):86, ('native','numeric'):757, ('native','na'):2}`；`out/policies/ledger-counts-detail.csv` |
| 4 | CLR 替代计数（按件去重 470 件）：非零 `methods=` 460 件 + `methods=0` 9 件 + 未记录 1 件 = 470 | 已实测 | 明细表 `functions_value` 列统计；样例 `out/policies/samples/clr.md` 第 6 行原文 |
| 5 | 777/777 数值件满足 `functions = decomp_ok + decomp_fail` | 已实测 | 逐份解析 md 三字段，输出 `equation holds 777 violations 0` |
| 6 | 抽样 3 份 md（CLR/nonPE/native）经 gh.py 只读 GET 取回，与本地镜像逐字节相同 | 已实测 | `clr github_bytes 7744 local 7744 identical True`（nonpe 3174、native 4205 同）；样例落 `out/policies/samples/`；本次 API 共 3 次 |
| 7 | `status=failed_analyze` 4 件；其中 2 件 native 却写 N/A（`ida_timeout 900s`） | 已实测 | `md with status=failed_analyze 4` + 两件 md 第 5/11/12 行原文 |
| 8 | 需处理视图 1,257 = CLR 439 + native 740 + nonPE 78（= 排除 already_done=true） | 已实测 | 同脚本 `already_done x kind` 计数行 |
| 9 | 任务书 438 的台账来源 | 无法判定 | 缺任务书所引用的那一版台账/脚本；可复跑的最近值为 439（见 §5） |
| 10 | `remote_index.csv` 的 status 与 4 份 md 内 `status=failed_analyze` 不一致（index 写 analyzed/processed） | 已实测 | index 聚合 `analyzed=759;processed=470;unsupported_non_pe=86` vs 4 份 md 内 status 行 |

〔未验证〕档本文件为空——凡未能实测的（§5 的 438 来源）一律入〔无法判定〕，不写「大概/应该」。

## 7. 附件

| 文件 | 用途 |
| --- | --- |
| `out/policies/ledger-counts.csv` | §2 逐 kind 计数汇总（可直接复核） |
| `out/policies/ledger-counts-detail.csv` | 1,346 行逐份明细（md 路径 / kind / status / sha256 / functions 分类与原值 / 文件字节与 sha256） |
| `out/policies/derive-counts.py` | 推导脚本（只读输入） |
| `out/policies/derive-counts.out.txt` | 脚本原始输出全文 |
| `out/policies/samples/clr.md`、`nonpe.md`、`native.md` | 抽样 3 份 md 原文（GitHub 只读取回，未加工） |
