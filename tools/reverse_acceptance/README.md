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
| `BFDYLD.s` | 对两件固定指纹的 AMD64 COFF，使用已核验的 Zig 在临时目录重组，核对节、数据、符号、辅助记录和重定位。该项可随整体结果保留单独的通过记录。 |

三个固定候选的逐件对照、工具和复跑命令见[原生验收回归记录](native-regression.md)。

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

完整 JSON 可用标准输出重定向保存。`rows[].proof.checks[]` 给出每个专项的判据、指标与差异位置；`rows[].source_rows` 指向原始清单，按 CSV 逻辑行编号，表头为 1。`inventory_status` 是输入快照的历史状态。运行回归测试可用 `python -B -m unittest discover -s tools/reverse_acceptance`。
