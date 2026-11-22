# Aspen 逆向结果静态验收器

`verify.py` 读取原件和已经交付的源码、证据、资源。逐件输出 JSON，进程退出码 0 表示整件静态通过，1 表示查实了交付缺口，2 表示证据或输入不足。项目模式重新执行每一份已绑定的交付，保留每一个未绑定原件。运行不需要联网；读取固定版本源码清单时需要提前准备相应文件。

## 运行

需要 Python 3.11 或更新版本。PE 的指令、资源和 Office 的 VBA 核对使用 [requirements.txt](requirements.txt) 中的固定依赖。CLR 方法比较使用 PowerShell 7 与 .NET 元数据读取器。需要重新编译的专项在临时目录工作。待验目录里的构建脚本和待验程序均不执行。

以下 PowerShell 命令在仓库根目录运行。示例核验 Aspen V15 安装目录里的 `apdelayload.lib` 和仓库中该件的归档。安装位置有变化时调整 `$original`。

```powershell
$tool = 'tools/reverse_acceptance/verify.py'
$original = Join-Path $env:ProgramFiles 'AspenTech/APrSystem V15.0/Engine/Lib/apdelayload.lib'
$logical = '[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Lib/apdelayload.lib'
$delivery = (Resolve-Path -LiteralPath "逆向成果/静态验收通过/Plus/$logical").Path
$sha = 'd8c809c76f202e0df54bbc6315f0b16ce5840771099533988bdde0a5727b8afb'
python -B $tool item --original $original --sha256 $sha --delivery $delivery --product Plus --original-path $logical
```

新环境可用 `python -m pip install -r tools/reverse_acceptance/requirements.txt` 安装 Python 依赖。`--rebuilt` 接受已有 CLR 回编件。`--assembler` 接受 COFF 及原生导出回编使用的受信 Windows Zig 0.13.0。需要核对导入提供方的导出节时，同时传入 `--provider <原版 DLL> --provider-sha256 <清单指纹>`。未提供时，使用方可见的槽读取、跳板和调用证据仍会列出。

在 Windows 上使用嵌入式 Python 时，先用实际执行验收器的解释器运行 `python -B -c "import iced_x86"` 检查依赖。若模块已安装但无法导入，检查该解释器的 `sys.path` 和嵌入式配置。若该配置允许读取 `PYTHONPATH`，可在当前 PowerShell 会话把它指向现有依赖目录。否则使用能导入这些依赖的项目解释器。

若原生导出回编报告 Zig `AccessDenied`、`Permission denied` 或 `FailedToEmit`，检查当前工作盘的写权限。在专用 PowerShell 会话内，将 `TEMP` 和 `TMP` 指向可写的临时目录，将 `LOCALAPPDATA` 指向可写的 Zig 缓存位置，再运行原命令。原生导出回编子进程会继承这三个变量，`ZIG_*CACHE_DIR` 不在其传递列表中。

## 整件通过的依据

1. **既有整件验收回放。** 验收器保管独立于交付的[受信档案指纹](accepted_archives.json)。两个初始条目均取自项目固定提交，逐件确认了通过说明、可编辑源码与依据。重算原件 SHA-256、全目录文件名和逐文件 SHA-256。全部相符才复用既有结论；交付发生变化时保留逐文件差异，重新判断。原路径或产品不符时也保留待核。回放继承原判定已记载的差异和适用范围。[受信提交](https://github.com/DenseFLoe/Aspen-for-mac/tree/773260c1033e524cebe000699409f5708bebfda0)
2. **从此次交付的 C# 源码独立回编。** 适用于固定 Roslyn 和 .NET Framework 引用即可编出的 DLL。只接收 `fresh-cs/` 目录第一层的 C# 源码，用固定参数、引用和编译工具在新目录生成 DLL，再比较整份 PE 的每个字节。以 `--product` 和 `--original-path` 指定原件的受信身份。确认源码指纹、说明、程序集版本和全目录范围后可给出新交付的整件通过。不同编译器、依赖、签名或构建布局可能导致同等行为的源码无法通过此路线，此时返回待核。本机未安装已核对的编译器或引用版本时也返回待核。编译参数和限额见 [fresh_cs.py](fresh_cs.py)。

新 C# 交付中，根目录放 `<原文件名>.md`，例如 `Example.dll.md`。以下为新格式的具名字段，值应来自受信清单和实际源码。字段逐行书写，值完整匹配。可在其他行补充版本说明、操作与代码说明。

```text
Product: Plus
Original path: GUI/Xeq/Example.dll
Original SHA-256: <原件小写 SHA-256>
Assembly version: 1.0.0.0
Verification profile: roslyn-5.0-netfx48-csharp12-release-anycpu-v1
Scope: whole-pe-static
Evidence: fresh-source-build
Static gaps: none
```

每个 `fresh-cs/Example.cs` 配同目录的 `Example.md` 或 `Example.cs.md`。说明写入源码相对路径和小写指纹。验收器将其与本次实际传给编译器的源码核对。已有其他格式的 Aspen 交付仍可走对应专项。

```text
Source: fresh-cs/Example.cs
Source SHA-256: <这份源码的小写 SHA-256>
```

## 已有交付的专项

| 证据 | 验收范围 |
| --- | --- |
| 原生或混合件的 `coverage.csv` | 对照项目已有 AMD64 原件锚点读取器，核对键、申报缺口、入口字节、逐址或逐 token 的反汇编引用及源码证据区间。检查覆盖表格式、重复键和缺失文件。源码非空仍须单独证明该段实现对应原逻辑。 |
| 原生 `calls.csv` 与反汇编 | 使用原件回读指令，核对清单内间接转移、可识别 IAT 目标、重复、遗漏及登记类别。保留原件可见入口和清单边界的差距、待解跳转。按具体交付格式检查的范围见子报告。 |
| 原生 `internal-transfers.csv` 和 `control-gaps.csv` | 兼容旧表的 `owner,site,target,target_owner,instruction` 与新版 RVA 表头。逐址解码直接边，对照间接边的附件和主表。输出的 `unresolved_site_rvas` 保留未决地址，`data_import_evidence` 区分数据读取、导入桩和观测到的调用。 |
| `s5/business-evidence.json` 与可编辑导出源码 | 对支持的 AMD64 内联汇编 C 交付，从原件导出与异常目录或可确定的直线叶函数确定边界。在临时目录重新编译、处理 COFF 重定位并逐字节对照。`metrics.exports` 按真实导出名列出结论与区间，`findings` 记录差异位置和两侧值。入口缺口在覆盖专项的 `declared_entry_gaps` 中。 |
| PE `resources.csv` 及 `s5/resources.json` | 核对原件资源树中的键、语言、大小、地址、代码页、指纹及可用的实际交付内容。 |
| 工作簿的 `VBA/` 或 `vba-src/` | 按模块身份比较原件和交付的可编辑 VBA。记录缺失、多出或改变的模块。宿主表单、公式、XLM、P-code 和运行行为仍需各自的证据。 |
| `--rebuilt` 的 CLR 程序集 | 比较逐方法签名和实现、IL、有关 token 元数据、局部变量和异常区域。方法体无法证明等价时输出差异。传入同一 DLL 只能验证二进制比较环节。 |
| 交付根目录的一份 `.s` 源码 | 对受支持的 AMD64 COFF 对象，先核对原件布局和受限 AT&T 汇编语法，再使用受信 Zig 在临时目录重组。对照节、字节、符号、辅助记录和重定位。源码文件名和普通注释可变。需要预处理的 `.S` 或超出支持范围的语法保留待核。 |

三个固定候选的逐件对照、工具和复跑命令见[原生验收回归记录](native-regression.md)。

### 复核固定交付

每次 CLI 运行的顶层 `verifier` 给出验收器版本、实际工具源码和受信档案的组合指纹、Python 及已安装的解析依赖版本。逐件报告中的 `delivery_sha256` 和 `delivery_files` 标识此次验的交付，包括失败或待核的交付。在有受信交付指纹时，可为 `item` 传入 `--delivery-sha256`，批量输入中对应字段为 `delivery_sha256`。不吻合时该件返回 `delivery_identity_mismatch` 并待核。交付指纹是“相对 POSIX 文件名 → 文件 SHA-256”的 JSON 对象按键排序、以 UTF-8 和紧凑分隔符编码后的 SHA-256。复验同一批次时，应从独立核实过的候选取得预期值。

原生覆盖会核对工具发现的额外入口与原件锚点，并从完整证据文件核验所引首条指令及源码范围。转移报告的 `missing_sites` 为**清单中存在指令、主表却缺登记**的站点数。`original_reachable_unlisted_sites` 为**从原件可信入口独立核得、交付清单缺指令**的间接转移数。逐址来由见 `original_reachability.unlisted_transfers`。仅由导出提示、遇到解码冲突或超过遍历预算的位置单列待核。

导出报告的 `rebuild_status` 表示实际编译和重定位后字节是否匹配。`original_facts_status` 单列可直接从原件核对的申报，`manifest_status` 汇总已核对的申报。缺少受信 Zig 时，导出回编待核、匹配字节计为零，指令、调用、RIP 相对引用中可核实的矛盾照常报告。

原生交付还会按原件 PE 资源树逐项报告资源证据。对支持的 `version.json` 和 `s5-data/version-resource.json`，验收器从 JSON 构造完整版本资源并比较每个字节，包含 UTF-16 字符串、终止符及对齐字节。[Windows 版本资源布局](https://learn.microsoft.com/en-us/windows/win32/menurc/vs-versioninfo)

### 下游如何提交间接 CALL 的目标依据

`item` 和 `project` 都从原件核对。原有 `calls.csv`、`code/indirect.csv`、`code/indirect-resolved.csv` 可以直接提交。每个调用地址在 `indirect_call_targets.sites` 中有一行，包含主表行号、旧表申报、原件指令字节、操作数、判定和理由。这个专项收录主表中尚未核准的间接 CALL，以及附件明确提到的地址。已核准的普通导入仅在附件点名时进入本专项。所有间接转移的漏登统计仍见原有的 `metrics`。

需要提交新依据时，在交付根目录添加 `target-evidence.json`。下面两条可分别在 FindComponent.dll 上复验。第一条申报一个按序号导入的函数，第二条仅申报分派路径。

```json
{
  "schema": "indirect-call-targets-v1",
  "original_sha256": "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02",
  "claims": [
    {
      "site": "0x1012", "owner": "0x1000", "target": null,
      "external": {"iat_rva": "0x75b8", "import": "mfc140.dll!#310"},
      "witness": {"kind": "iat", "slot_rva": "0x75b8"}
    },
    {
      "site": "0x53f2", "owner": "0x5310", "target": null, "external": null,
      "witness": {"kind": "guard_dispatch", "definition_rva": "0x53eb", "register": "r9", "slot_rva": "0x7670"}
    }
  ]
}
```

每个地址提交一次。`site` 是 CALL 的 RVA，`owner` 是所属函数的起始 RVA。内部函数填十六进制 `target` 并将 `external` 置空。外部导入填 `external` 并将 `target` 置空。最终目标未知时两项均可为空。原件指纹须与本次 `item` 的受信输入相符。新增附件会改变交付指纹，重跑时应使用该副本的指纹。

| AMD64 PE32+ 依据 | 原件核对的事实 | 通过时可引用的结论 |
| --- | --- | --- |
| `iat` | CALL 的 RIP 相对内存操作数、槽 RVA、导入描述符、DLL 名和区分大小写的符号或序号 | `instruction_operand`，原件静态导入身份 |
| `readonly_slot` | 同形 CALL 消费的只读槽有唯一 DIR64 重定位，槽中的指针指向可核的原件函数入口 | `instruction_operand`，原件静态内部目标 RVA |
| `readonly_table` | 另填 `definition_rva` 和 `register`。从已核的原件函数入口，RIP 相对 LEA 定义表基址，直线到达 CALL，寄存器保持，固定偏移槽及内部目标满足上述只读指针要求 | `from_owner_entry`，从所列入口执行的目标 RVA |
| `guard_dispatch` | 另填 `definition_rva` 和 `register`。原件 MOV 从 Load Config 标注的分派槽读取到寄存器，顺序执行至调用时该寄存器保持 | `definition_fallthrough`，`original.dispatch_route` 可核实，最终目标仍待核 |

`decision=confirmed` 时读取 `confirmed_target` 及其 `binding_scope`。`unresolved` 保留现有线索，例如只写了基址寄存器、只取到了分派器，或依据超出支持范围。`contradicted` 表示申报的地址、归属、操作数、依据或目标存在可定位的冲突，或同址登记存在冲突。`witness_result.reported` 与 `witness_result.original` 分别记录申报和原件结果。三种状态按地址互斥计数，后两种的 `confirmed_target` 均为空。运行时完整目标集合和整件静态验收各有独立判据。

兼容旧表混列的间接转移。`indirect_jump_targets` 记录原生间接 JMP，明确填错 CALL 或 JMP 的行会报告 `indirect_target_transfer_kind_mismatch`。`managed_indirect_records` 给出旧表中托管记录的位置和申报内容。声明 CALL 目标的 JSON 仍使用上面的格式。

旧表用明确的 RVA 申报站点时，行号问题见 `legacy_indirect_listing_references`。其中列出原申报地址、行号实际对应的地址和已核字节的当前清单位置。仅因旧引用错位或无法唯一定位的记录，不作为具体目标矛盾计数。修正引用后，最终目标仍按实际依据判断。

### 两跳导入证据

`item` 和 `project` 都可读取 FindComponent S17 使用的 `code/import-callers.csv`。每个调用点只提交一行。`rva` 填直接 CALL 或尾部 JMP 的 RVA，`owner` 填调用点所属函数的起始 RVA，缺归属时留空。`detail` 使用 `0x4aa3 -> IAT 0x75e8 -> mfc140.dll!#2344` 的格式，支持按名和按序号导入。

`import_routes.sites` 逐址显示原件调用指令、原件跳板指令、IAT 槽和导入身份，并列下游提交。静态证明要求调用点和跳板边界可独立核实，跳板是消费该 IAT 槽的一条间接 JMP。 `chain_counts` 汇总四项链路证据，`counts` 还要求原件异常目录能核实调用方归属。边界或归属不足的保留未决。主表登记情况见 `main_registration` 和 `unregistered_sites`。导入身份以原件 PE 描述符为准。

### 内部函数回编与 CLR 跳转槽

交付含 `s13/callee-evidence.json` 或 `s13/reassembly-delta.json` 时，`item` 和 `project` 会增加内部函数回编专项。前者列出函数符号和各自的 `s13/<符号>.c` 源码，后者按 RVA 对应 `code/verified.c` 引用的源码分片。现有两种格式可原样提交。验收器依据原件 PE 异常目录定位函数起止，使用 `--assembler` 指定的受信 Zig 重新编译受支持的内联汇编，并按原件指令核对 COFF 重定位字段、类型、目标、加数及应用重定位后的代码字节。只编译通过语法核对的指令与受信宏。其他源码形式和缺少编译器的结果会保留待核。

`metrics.regions` 每行给出源码出处、原件范围、回编状态和计数。重定位不符时同时显示指令 RVA、重定位字段 RVA、原件目标和重编目标；字节不同则给出首个差异。累计匹配数只计本次独立回编且吻合的范围。

包含 `code/vtable-fixups.csv` 的混合程序集会增加 `clr_vtable_fixups` 专项，需要 PowerShell 7。工具静态读取原件 CLR 描述符、槽宽、槽地址、MethodDef token、名称及方法体 RVA。若提供 `code/indirect-native.csv`，会核对其中可定位的 `vtable-slot` 跳转以及原件指令所读的槽。报告分别给出目录条目、槽、不同方法和已核跳转的计数。程序集加载后的目标、未登记跳转和方法体实现各自需要相应证据。

### 历史附件与原件复检

交付含可识别的分轮原生回编清单时，`cumulative_rebuild` 逐段重编早期区间。每个 RVA 只计一次，按原件节范围、代码字节及重定位校验。累计范围是申报的代码区间，函数边界另按可得的原件元数据核对。支持的内部函数交付还会逐址比较调用表中的导入调用和 RIP 相对数据引用。

`historical_listing` 分别核对历史行的原件字节和独立指令边界。证明起点后才核对缺漏，并单列已证的 NOP 或 INT3。与原件字节吻合且边界待核的行记录在 `unproven_boundaries`，有重叠时列出已证指令的起点。边界依据包含从原件出发的控制流，以及受支持的 x64 C 作用域表和 MSVC FH4 异常继续地址。`exception_continuations` 记录异常入口依据。`mixed_baseline` 用受信的原件级跳转清单复验已知 CLR 绑定，并核对它们在反汇编和主表的登记情况。构造调用用原件 IL 指令边界和 token 验证，关联 C 源码的检查限于受支持的段寄存器取值序列。[Windows x64 异常处理](https://learn.microsoft.com/en-us/cpp/build/exception-handling-x64) · [MSVC FH4 元数据](https://devblogs.microsoft.com/cppblog/making-cpp-exception-handling-smaller-on-x64/)

主表可引用补充的 ASM 与 IL。验收器按文件和行号定位，独立核对指令或 IL 站点、原件中的槽或 token 及主表申报。历史跳转和本轮原件跳转分别计数。累计回编从 `reassembly.json` 和 `s<轮号>/reassembly-delta.json` 发现轮次，逐轮核对前序清单指纹，用各段源码实际重编，并核对原件字节和重定位。

COM 核验从提交的调用点和工厂关系出发，独立解码原件中创建接口、传递接收对象及触发虚表调用的指令。只有接口来源可证时才使用该接口的虚表布局。报告分别列出成员、字节位移和运行时目标证据。[接口定义](https://learn.microsoft.com/en-us/windows/win32/api/oaidl/nn-oaidl-idispatch)

历史覆盖范围可通过 `--reference-evidence` 与 `--reference-evidence-sha256` 显式绑定。清单位于候选目录外，声明原件 SHA-256，并用 `files` 中的 `instruction_listing` 或 `clr_thunks` 记录参考文件的相对 `path` 与 `sha256`。清单的 `schema` 为 `static-reference-evidence-v1`。批量输入对应字段为 `reference_evidence` 和 `reference_evidence_sha256`。参考资料用来指定复核范围，验收器仍用原件逐项作判断。

ppexec 第十三号的 `submitted_callback_paths` 使用原件 PE 和提交的路径证据复验节权限门控及一条指定调用方的参数传递。结论分别受原版节表、已证调用方和提交路径条件约束。回调目标全集仍需另外证明。

### 间接转移登记与有界跳转表

`missing_transfer_registration` 对已有主表漏登结论逐址补充登记情况，区分仅有可定位的受支持附表行、主表和受支持附表均无登记、附表登记待核。目标和调用者证据沿用各自专项。主表漏登的判定口径沿用原要求。

`bounded_switch_paths` 从已证 AMD64 指令、无符号比较和原件只读数据核对受支持的单层相对 RVA 跳转表。报告保留选择范围、表区间、有序目标和各目标的边界依据。跨表竞争的指令起点保留待核。该专项覆盖界内分支的静态映射，运行时目的仍待核。

### BIFF8 工作簿与 VBA 工程

BIFF8 交付可用 `workbook.json` 描述原件记录，包含记录 ID 和原始载荷，支持从定义名称的结构字段复验记录字节。验收器独立读取原件 Workbook 流，检查记录顺序、载荷与定义名称公式令牌。原件首记录为 BIFF8 Globals BOF。本专项也适用于未提交 VBA 的工作簿。

带工程清单的 VBA 窗体核验把展示头、原生属性和模块源、FRX 中的设计器资源分别与原件核对。对于受支持的 BIFF8 工程清单，项目专项比较 CFB 存储及其类标识、宿主 Document 绑定、OVBA 目录和申报资源。OVBA 目录只允许运用格式定义的源码偏移规范化。缓存统计、编辑后的回读和 Windows 行为各有证据要求。专项结果随整件报告列出，整件通过仍须满足完整标准。

## 全项目分母和批量输入

下面的例子沿用上面的原件和交付。把三份来源清单和逐件总表下载到同一工作目录，再提交本机可供核对的材料。首次下载需要联网；验收器会自行核验这些清单的指纹。

```powershell
$work = New-Item -ItemType Directory -Path (Join-Path ([IO.Path]::GetTempPath()) ([guid]::NewGuid().ToString()))
$raw = 'https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/773260c1033e524cebe000699409f5708bebfda0'
foreach ($group in 'plus','properties','shared') {
    Invoke-WebRequest "$raw/inventories/2026-11-19/$group/01-needs-reverse/files.csv" -OutFile "$work/$group-scope.csv"
}
Invoke-WebRequest "$raw/逆向成果/逐件总表.csv" -OutFile "$work/inventory.csv"
$inputs = @(@{ product = 'Plus'; path = $logical; sha256 = $sha; original = $original; delivery = $delivery })
ConvertTo-Json -InputObject $inputs | Set-Content -Encoding utf8 "$work/inputs.json"
python -B $tool project --inventory "$work/inventory.csv" --inventory-sha256 '116e75d149828855b8dcf398226dbb509f50fe304c017c1a7fb09fcdfb4f1862' --source-scopes $work.FullName --inputs "$work/inputs.json"
```

`--inputs` 接受 JSON 数组。每项含 `product`、`path`、`sha256`、`original`、`delivery`，可选 `rebuilt`，也可同时指定 `provider` 和 `provider_sha256`。前三项共同匹配母表身份。本地路径可以是绝对路径，或相对于该 JSON 的路径。未提供材料的项也会出现在结果中。重复绑定、未知绑定、空母表或母表指纹不符均无法给出项目通过。

指定 `--source-scopes` 时，再核对固定提交的三份“需要逆向”原件清单，目录内分别命名 `plus-scope.csv`、`properties-scope.csv`、`shared-scope.csv`。校验器内固定了三份原始 SHA-256。同一内容保留全部来源记录号；总表之外的原件进入分母，也可以绑定本地材料。以这次快照计，来源记录 8,191 条，去重后 1,397 个原件，公开总表 1,394 件。省略此参数时结论仅覆盖提供的母表，输出的 `scope` 会明确这一点。这三份清单的范围为项目已分类的需要逆向内容，产品整体的安装完备性和 Windows 行为有各自的验收阶段。[Plus 来源](https://github.com/DenseFLoe/Aspen-for-mac/blob/773260c1033e524cebe000699409f5708bebfda0/inventories/2026-11-19/plus/01-needs-reverse/files.csv) · [Properties 来源](https://github.com/DenseFLoe/Aspen-for-mac/blob/773260c1033e524cebe000699409f5708bebfda0/inventories/2026-11-19/properties/01-needs-reverse/files.csv) · [共享来源](https://github.com/DenseFLoe/Aspen-for-mac/blob/773260c1033e524cebe000699409f5708bebfda0/inventories/2026-11-19/shared/01-needs-reverse/files.csv)

完整 JSON 可用标准输出重定向保存。`rows[].proof.checks[]` 给出每个专项的判据、指标与差异位置。`rows[].source_rows` 指向原始清单，按 CSV 逻辑行编号，表头为 1。`inventory_status` 是输入快照的历史状态。`counts` 给出整件状态总数，`pass_by_basis` 分别计数本次完成的整件源码回编核验和既有整件裁定回放。运行回归测试可用 `python -B -m unittest discover -s tools/reverse_acceptance`。
