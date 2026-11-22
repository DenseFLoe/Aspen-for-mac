# CLR 引用与传递依赖

本次读取 GitHub 主干提交 `7ba3491dda331a04fa25298ba9bb7cee809bb0da` 中 `inventories/2026-11-19/{plus,properties,shared}/01-needs-reverse/files.csv` 的全部 `PE-CLR-*` 记录，包含 IL-only 和混合程序集。三张来源表之间有重叠。Properties Enterprise Database Server 使用独立的产品标签。结果描述这三张清单内的静态绑定，Windows、.NET 框架、第三方或其他 Aspen 产品在清单外提供的程序集不会自动加入。

| 原件清单 | 全部记录 | CLR 记录（含重复来源） |
|---|---:|---:|
| Plus | 3,791 | 1,639 |
| Properties | 1,866 | 908 |
| shared | 2,534 | 1,289 |
| 合计 | 8,191 | 3,836 |

对 562 个不同原件 SHA-256 逐件读取元数据，537 件由相同哈希的本机文件提供，25 件从原版 CAB 读取。每份原件均已按清单校验 SHA-256。同一安装位置及相同内容的重复来源合并，一个原件安装在不同目录则分别计算依赖。合并后共 625 个位置节点，562 件原件自身共有 5,714 条 AssemblyRef 元数据行，按位置展开共有 6,049 条引用边。

| 按位置统计的静态解析结果 | 引用数 |
|---|---:|
| 同目录解析 | 1,239 |
| 同产品解析 | 542 |
| 扩展到全库解析 | 0 |
| 库内没有此名称 | 3,833 |
| 有同名文件，身份不符 | 78 |
| 同一优先级有相同身份但不同内容的候选 | 357 |

共解析 1,781 条。其余 4,268 条逐条保留，共涉及 390 个不同引用身份。625 个根的传递闭包均含未解析项，单根最多到达 176 个节点（含根）。例如，`mscorlib` 在这里有 595 条找不到库内候选的直接引用。结果不涉及外部运行库的实际装载情况。

## 两种运行方式

Windows 需要 Python 3.11+ 和命令 `pwsh`（实测 PowerShell 7.6.9），清单模式按需通过系统 `tar.exe` 读取 CAB，通过 Windows Installer 只读接口读取 MSI 流。脚本不执行输入程序集。以下命令在已交付扫描器的目录执行，示例中 `python` 表示可用的 Python 3.11+。

任意给定程序集目录可直接执行下列命令。扫描器按 PE/CLR 头递归识别文件，无需原件清单。省略 `--root` 时为所有程序集计算闭包；指定根时，仍从整个库索引候选。`--product` 可重复传入以标注多个产品或共享路径，同一程序集可归属多方。每个参数中的路径都应位于 `--library` 下。省略产品标注时，整个目录视为一个产品。

```powershell
$lib = 'C:\Program Files\AspenTech\Aspen Plus V15.0'
python -B scan.py --library $lib --product "Plus=$lib" --root "$lib\GUI\Xeq\AspenTech.AspenPlus.CustomModels.dll" --out "$env:TEMP\aspen-clr-directory"
```

该目录实测检查全部 2,245 个文件，索引 46 个程序集、264 条直接引用，其中 19 条在同目录解析，4 条在同产品解析。选定的 CustomModels 根到达 13 个节点（含根），含 81 条未解析引用。只标注 `--product "Modules=$lib\GUI\Xeq\Modules"` 重跑时，后 4 条走全库层级，选定根闭包相同。

复现完整原件清单扫描需要三份固定提交的原始 CSV，并能读取其中记录的安装位置或原版安装介质。三个输入文件的 SHA-256 在扫描开始时核验。若介质换了位置，可传 `--media-dir <aspenonesuite目录>`。输出目录应单独指定，原始二进制仅在系统临时目录按需暂存。

```powershell
$pin = '7ba3491dda331a04fa25298ba9bb7cee809bb0da'
$inputDir = Join-Path $env:TEMP 'aspen-clr-inputs'
New-Item -ItemType Directory -Force $inputDir | Out-Null
foreach ($name in 'plus','properties','shared') {
    $uri = "https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/$pin/inventories/2026-11-19/$name/01-needs-reverse/files.csv"
    Invoke-WebRequest -Uri $uri -OutFile (Join-Path $inputDir "$name.csv")
}
python -B scan.py --inventory-dir $inputDir --out "$env:TEMP\aspen-clr-inventory"
```

## 绑定规则与逐根查阅

1. 由 `System.Reflection.Metadata` 读取 Assembly/AssemblyRef 的名称、四段版本、区域性、公钥标记及内容类型。元数据带完整公钥时按 CLR 规则派生 token；身份查询区分版本、区域性、token 和内容类型。保留原始 flags，不执行版本重定向。
2. 优先比较引用者的逻辑安装目录，再比较至少有一个共同归属的产品，最后比较整个索引。已核实位置的 GAC 原件使用清单给出的目标路径。未核实位置的 MSI 根目录占位符和 Binary 表流不推断为同目录。最先匹配的层级内若候选 SHA-256 不唯一，记为歧义；相同 SHA-256 多位置的等价候选按固定路径顺序取首个，所有同层候选 ID 留在 CSV。
3. `assemblyrefs.csv` 每行保留一条元数据引用，含引用者路径、引用身份、解析状态、目标路径、选择层级及候选 ID。`assemblyref_rid` 是该来源程序集元数据表从 1 开始的行号。同名不同内容的引用者用 `source_id` 区分。
4. `closure.json` 的 `nodes` 提供节点 ID、原路径、SHA-256、产品归属和程序集身份。`origins` 的数字是各来源 CSV 从 1 开始的逻辑记录号（表头为 1）。`roots[id].reachable` 含根自身，沿已解析边各访问一次。`roots` 中每条记录按 `id` 查找；使用 `--root` 时仅返回选定的根。`unresolved` 中每个边号都能在同一个 JSON 的 `unresolved_edges` 按 `edge_id` 找到引用者、缺失身份、原因和候选。相同身份由不同调用者引用时分别列出。

独立复核对全部 6,049 条引用验证了目标身份或未解析条目，并从 CSV 重算所有 625 份闭包，结果一致。另以 Windows PowerShell 的 .NET Framework 反射只读 API 对照三个实验原件，Engine.Structures、CustomModels 和 HybridModelUtilities 分别有 4、31、4 条直接引用，全部身份与 CSV 一致。
