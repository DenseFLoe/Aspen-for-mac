# vbaProject.bin

## 结论

**静态验收通过。** 从原件恢复 7 个可编辑 VBA 模块，复核 181 个过程和 212 个宿主 ActiveX 绑定。

## 来源

- 产品为 Properties，随 Aspen Solubility Modeler V15.0 安装。清单未记录该成员的独立版本。VBA 缓存版本字段为 `0x00B5`，项目平台为 Win64，源码代码页为 Windows-1252。
- 安装路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Solubility Modeler V15.0/NRTL-SAC/Regression.xlsm!/xl/vbaProject.bin`，本次输入取自 `DenseFLoe/Aspen-for-mac` 分支 `codex/reverse-unsuccessful-85` 的固定提交 `9559b75390876346c69b185dbaaba18692a7af75`，仓库路径为 `原版文件/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Solubility Modeler V15.0/NRTL-SAC/Regression.xlsm!/xl/vbaProject.bin`。
- 原件 532,992 字节，SHA-256 为 `248e460a2ca979b61e9b76b3b660841957af4386d7a4af85a4a18f029fe8658c`。同一提交中历史制作者报告的 Git blob 为 `dde1babbe794d78b3ae7124b4b66d1a62ee51792`。报告所遇 DOS 头识别错误源于用 PE 解析器读取 CFB 文件。原件头为 `D0 CF 11 E0 A1 B1 1A E1`。

## 源码、项目和宿主

| 原件流 | 文件 | 源码偏移（十进制） | VBA 过程 | 工作表控件 |
| --- | --- | ---: | ---: | ---: |
| `VBA/ThisWorkbook` | `ThisWorkbook.cls` | 9533 | 2 | — |
| `VBA/Sheet1` | `Sheet1.cls` | 3801 | 4 | 4 |
| `VBA/Sheet10` | `Sheet10.cls` | 100265 | 57 | 74 |
| `VBA/Sheet11` | `Sheet11.cls` | 145803 | 110 | 134 |
| `VBA/Sheet12` | `Sheet12.cls` | 1008 | 0 | 0 |
| `VBA/Module1` | `Module1.bas` | 10265 | 6 | — |
| `VBA/COMAddinHelper` | `COMAddinHelper.bas` | 2931 | 2 | — |

- 使用 Python 3.12.14、olefile 0.47 和 oletools 0.60.2 读取 CFB、严格解析 `PROJECT` 和 `VBA/dir`，按各模块的 `MODULEOFFSET` 解压。归档前重新解压并对比 7 份交付文件的每个字节，保留原编码、换行、`VB_*` 属性和空的 Sheet12 文档模块。使用 pcodedmp 1.2.6 检查缓存。27 个流逐项记录大小和 SHA-256。存储只有 `VBA`，其中的 `_VBA_PROJECT` 与 16 个 `__SRP_*` 流属于版本相关缓存，保留流指纹。原件无独立 UserForm 设计器存储。
- `project/PROJECT.redacted.txt` 记录项目名称、文档和标准模块、宿主类型及工作区。项目引用的库 ID 和版本在 `evidence/coverage.json`，包括 OLE Automation、Office、Forms、SLMServerCLS、Aspen Properties Excel Calculator 和 Aspen Plus GUI 类型库。重新装配时将 5 份文档模块绑定到宿主中同名 CodeName 的文档代码页，并导入两个标准模块。模块流源码保留属性行，可按 Excel 文档模块的装配方式使用。
- 只读检查本机已安装的同名 `Regression.xlsm`，其 SHA-256 为 `1b7d06872c829af52c73c0a650af2ed6bb4a3b4eb50d5cf6d01e96f50b7c3f4b`。内层 `xl/vbaProject.bin` 与固定提交输入哈希相同。沿 `workbook.xml` 关系找到各工作表、原 CodeName、控件的关系 ID、VML shapeId、ActiveX XML 与状态二进制。212 个去重控件均与源码 `VB_Control` 名称匹配。对照资料逐项保存在 `evidence/host-bindings.json`，包含控件类型、事件名、来源部件与指纹。实际控件和布局由宿主工作簿承载，沿已核验的宿主部件取用。

## 实现核对

- pcodedmp 1.2.6 对本件缓存在用户标识符槽位超过 `0xBE` 时多减一。例如 `0392` 原显示为 `CboSwitch3`，原名称表下一槽为 `CboSol4_Change`。对所有 134 个显示错位的定义核对原编号和目标槽，均相差一槽。仅在本件的分析副本中取消该分支，重导出后 181 个过程的种类、名称、顺序和结束指令匹配。原件和共享工具字节保持原状。
- 缓存核对使用的是原件指令。Win64 显示降级包括自定义参数类型、后续参数链和可见性，源码保留原声明。比如 `COMAddinHelper.Invoke` 的缓存含空串常量默认表达式、`Ld args` 和两参数 `Invoke` 成员调用，源码保留可选的 `args As Variant`。关闭事件的 `id_FFFF` 出现在读取 `Name` 成员的接收者位置，对应源码的 `Me.Name`。
- `evidence/coverage.json` 为每个过程记录源码行和 `evidence/pcode-corrected.txt` 中的定义所在行。抽查工作簿启动和关闭的分支及授权调用（反汇编第 73、293 行），两张工作表打开模拟的错误分支（第 760、12862 行）、运行和回填的调用顺序（第 1247、13338 行）、输入与回归权重写入（第 2572、14575、12649、19423 行），以及结果回填、图表轴和数值舍入（第 10115、17594、11804、18770、12305、19272 行）。调用、分支、循环及算术指令与对应源码相符。
- Excel、Aspen COM 加载项、模拟文档及许可证环境下的编译和运行行为留待 Windows 对照阶段。建议沿原 CodeName 复核打开、计算、错误提示、图表刷新、保存关闭及资源释放。

## 成果与本地限制

- `vbaProject.bin.source.local-only.zip` 共 98,724 字节，SHA-256 为 `7e508c18c81428072332983f756860c9641343d800f5dd956f54058f95f9c820`。已重新打开并检验全部 ZIP 成员、CRC 和内容字节。
- **源码包仅限本地。** `Sheet10.cls`、`Sheet11.cls` 和反汇编含工作表保护口令。工作目录的 `project.txt` 与输入包含项目保护字段 `CMG`、`DPB`、`GC`。归档内的项目文本已省略这些字段。本说明只记录字段、位置和指纹，可独立交接。
- 格式基准见 [Microsoft MS-OVBA](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/575462ba-bf67-4190-9fac-c275523c75fc)。反汇编工具见 [pcodedmp](https://github.com/bontchev/pcodedmp)。

