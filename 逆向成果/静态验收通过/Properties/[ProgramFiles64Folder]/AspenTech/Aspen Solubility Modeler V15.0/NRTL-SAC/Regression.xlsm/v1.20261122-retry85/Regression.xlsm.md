# Regression.xlsm

## 结论

**通过静态验收。** 7 个 VBA 模块已恢复为可编辑源码，867 个工作簿资源部件已按原路径归档。代码与原缓存、控件与工作簿关系的核对均通过。

原件为 Excel OOXML 宏工作簿，内含 64 位 VBA7 项目（CFB 复合文件 `xl/vbaProject.bin`，缓存版本 `0xB5`）。旧报告用 dnfile 和 pefile 解析整份工作簿，停在 DOS 文件头检查。本轮按 ZIP、OOXML、CFB 和 VBA 格式取证。 [Microsoft MS-OVBA 模块流](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/c66b58a6-f8ba-4141-9382-0612abce9926)

## 来源和指纹

- 产品为 Properties，分发版本为 Aspen Solubility Modeler V15.0。分类清单未登记独立文件版本。工作簿 `ThisWorkbook.cls` 第 11–14 行的内部显示版本常量为 `41.0.0.1000`。
- 安装路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Solubility Modeler V15.0/NRTL-SAC/Regression.xlsm`。来源清单 `inventories/2026-11-19/properties/01-needs-reverse/files.csv` 第 1864 行登记 Properties V15 64 位安装包中的 `ASM_NR~2.cab/regression.xlsm.B60C7E88_8BBD_4F70_9DBF_CC56ECD405B7`。
- 只读原件取自 `DenseFLoe/Aspen-for-mac` 的 `codex/reverse-unsuccessful-85` 固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75`，路径为 `原版文件/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Solubility Modeler V15.0/NRTL-SAC/Regression.xlsm`。旧报告取自同一提交，Git blob 为 `b5bf3c038f25065ca2ac9e7db23ea2e0d5a1fd41`。
- 原件为 728,062 字节，SHA-256 为 `1b7d06872c829af52c73c0a650af2ed6bb4a3b4eb50d5cf6d01e96f50b7c3f4b`。
- 同目录源码和资源包 `Regression.xlsm.source.local-only.zip` 的 SHA-256 为 `a0acfac67c1db3fb09013cb2cd8ad5f5ea0e530ba859b6171e5830eba017ea75`。

## VBA 源码与原件对照

用 Python 3.12.14、olefile 0.47、oletools 0.60.2 和 pcodedmp 1.2.6。沿 `VBA/dir` 的模块记录和 `MODULEOFFSET` 解压源码，复核原模块流和 `PROJECT` 声明。输出沿用原记录的 Windows-1252 字节、属性和换行。清单 `evidence/structure.json` 列出 27 个 CFB 流的指纹和各源码偏移。该项目的 CFB 只有 `VBA` 子存储，模块表中无设计器模块。

| 模块 | 原源码行数 | 过程数 |
| --- | ---: | ---: |
| `ThisWorkbook.cls` | 170 | 2 |
| `Sheet1.cls` | 46 | 4 |
| `Sheet10.cls` | 1,927 | 57 |
| `Sheet11.cls` | 3,049 | 110 |
| `Sheet12.cls` | 8 | 0 |
| `Module1.bas` | 182 | 6 |
| `COMAddinHelper.bas` | 34 | 2 |

检查项目属性时，`Sheet12` 的 8 行全是模块属性，原缓存也没有可执行行。其余 6 个模块的 181 个过程逐件列入 `evidence/cache/`。对照本件 VBA7 x64 缓存时修正了 pcodedmp 对高位外部标识符索引的偏移，再按模块顺序将 5,150 个 VBA 逻辑行和 15,100 条缓存指令对齐。核对 181 个过程名称、1,613 条控制语句、1,346 个调用或索引操作数、1,815 个字符串和 538 个数值。缓存证据按模块记录原源码和从零起算的缓存行号。

`evidence/signatures.json` 补查 19 个参数的名称、传递方式及可选标记。14 个内建类型可直接从缓存核对，5 个自定义类型保留源码声明和原缓存类型描述符。补查 7,042 个名称或标签操作数、2,921 个运算或赋值标记、132 条错误分支及其操作数，结果见 `evidence/operands.json`。另核对 `ThisWorkbook` 两处特殊表示。第 56 行构造指令的原始操作数为 24，指向导入表第 4 条记录。按 x64 布局的 10 字节记录核对偏移 36，标识符 0x023C 对应 clsServer2，解释了工具误显示 New 0 的原因。第 120 行的 `Me.Name` 对应宿主操作数 `id_FFFF` 和随后读取的 `Name` 成员。 比对记录覆盖同一逻辑行的运算符计数、名称及错误处理操作数，完整表达式求值顺序留待 Windows 对照。

- `ThisWorkbook` 第 33–99 行是打开、欢迎页状态和许可证交互，第 101–169 行处理保存询问、取消、关闭模拟和许可证回收。
- `Sheet10` 第 130–173 行及 `Sheet11` 第 191–235 行处理选择和打开 Aspen 模拟文件。纯溶剂的 `cmd_Run_Click` 在 `Sheet10` 第 271–413 行，二元溶剂的对应入口在 `Sheet11` 第 335–489 行。两路都保留输入、COM 加载项调用、结果读取和错误路径。
- `Sheet10` 第 1712–1823 行及 `Sheet11` 第 2832–2943 行保留正值筛选和对角线比较图绘制。`Sheet10` 第 1869–1881 行和 `Sheet11` 第 3038–3049 行保留回归权重处理。二元溶剂分支另有 `Sheet11` 第 2771–2829 行的溶解度输入处理。
- `Module1` 第 123–160 行检查加载项连接，`COMAddinHelper` 第 17–34 行根据 ProgID 取得 Properties 自动化对象。

## 工作簿与控件

`ooxml/` 保存除 VBA 容器之外的全部 867 个原版部件，逐件比对字节。460 个 XML、关系文件及 VML 部件均可解析，831 条关系的内部目标都存在。核对了 576 个工作簿定义名称、1 个单元格公式及两张图表所在资源。三份原 VBA 签名及其关系作为来源资源原样保留。签名有效性及替换 VBA 后的签名重新生成留待 Windows 重建。

| 工作表 | 宿主代号 | ActiveX | 有处理过程的 ActiveX | 工作表事件 |
| --- | --- | ---: | ---: | ---: |
| AspenSolubilityModeler | `Sheet1` | 4 | 1 | 3 |
| Pure Solvent | `Sheet10` | 74 | 44 | 2 |
| Binary Solvent | `Sheet11` | 134 | 94 | 2 |
| Solvent List | `Sheet12` | 0 | 0 | 0 |

沿工作表关系定位 ActiveX XML，再沿各自关系定位 212 份状态流。逐项核对工作表的 Choice/Fallback 名称、形状 ID、DrawingML 锚点、VML 形状、二进制流的 CLSID 和记录长度。本件的 XML 与 BIN 编号逐项一致，绑定以关系目标为准。控件表按每页 25 项存于 `evidence/layout/`。139 个控件事件过程逐项关联到宿主与源码行，另外有 7 个工作表事件和 2 个工作簿事件。XML 中没有 `linkedCell`、`listFillRange` 属性绑定，VBA 对控件、单元格和 Aspen 节点的读写由原源码和缓存对照记录。ActiveX MSForms 状态以原始资源保留，包括属性记录之外的尾部数据。设计器中的实际显示和控件交互留待 Windows 对照。 [Microsoft MS-OFORMS 控件属性](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-oforms/6e6be17c-10ba-4d6a-aa2f-de92ae9fc803)

## 依赖、复核和材料标记

`evidence/layout/workbook.json` 记录 OLE Automation、Office、MSForms、SLMServerCLS、AspenPropertiesExcelCalculator 和 Happ 类型库引用。已确认原引用路径上的三个 Aspen 类型库文件存在，文件指纹见 `evidence/type-library-files.json`。本轮保留引用和调用边界。许可证有权与无权分支、Excel 加载项注册、Aspen 模拟打开、回归数值与图表输出、保存再打开等留待 Windows 对照。重建时以工作簿及工作表代号恢复五个宿主文档模块，以标准模块导入两个 `.bas`，保留原 OOXML 控件和布局资源并重绑引用。

复核时从包内 `evidence/reproduce/` 取出脚本到同名原件旁的 `work/`，原件放于同级 `input/`。依次运行 `extract.py`、`verify_layout.py`、`verify_cache.py` 、`verify_signatures.py` 和 `verify_operands.py`，并在模块及布局证据中复查页码和指纹。Python 依赖安装在本件隔离目录。源码包归档前已完成 ZIP CRC、成员集合及 SHA-256 回读验证。

**原件及整个源码资源包仅本地保存。** `Sheet10.cls`、`Sheet11.cls` 有工作表保护调用和原始口令，四个工作表 XML 有保护哈希及盐，原授权取件内的 `PROJECT` 流还有 `CMG`、`DPB`、`GC` 原值。完整 VBA 缓存转储和含这些材料的工作目录也仅保留本机。交接记录按文件标记，报告无原始口令及保护字段值。




