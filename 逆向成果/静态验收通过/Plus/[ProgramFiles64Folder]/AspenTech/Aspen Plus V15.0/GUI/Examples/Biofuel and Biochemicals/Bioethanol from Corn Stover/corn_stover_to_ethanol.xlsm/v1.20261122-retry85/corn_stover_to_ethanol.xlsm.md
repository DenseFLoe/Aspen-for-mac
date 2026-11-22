# corn_stover_to_ethanol.xlsm

## 结论

**静态验收通过。** 上轮 `v0.20261121-w2` 用 PE 解析器处理了 OOXML 工作簿，报 `DOS Header magic not found`，没有导出源码。本轮拆解 ZIP/OPC 工作簿和内嵌 OLE/VBA 项目，恢复了全部 VBA 源文本和工作簿资源，并复核了控件绑定、宏过程和关键计算。使用原版宏部件重封包时，重读的 77 个解压后部件逐字节与原件一致。

## 原件与成果

- 产品 Aspen Plus。原清单没有记录独立的工作簿版本。安装路径明确属于 Aspen Plus V15.0。
- 原安装相对路径 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Biofuel and Biochemicals/Bioethanol from Corn Stover/corn_stover_to_ethanol.xlsm`。
- 原件从 `DenseFLoe/Aspen-for-mac` 的 `codex/reverse-unsuccessful-85` 固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75` 的 `原版文件/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Biofuel and Biochemicals/Bioethanol from Corn Stover/corn_stover_to_ethanol.xlsm` 取得。字节数 117471，原件 SHA-256 为 `3dbc4ad06bbdf14932701df606fde36a246148d0f1be00465b815e2a9c0ece55`。上轮同名报告从同一提交读回，Git blob 为 `4f7b4927403b1b20bbacf577ccf87c8b14a0ebe0`。
- 正式成果 `corn_stover_to_ethanol.xlsm.source.zip`，SHA-256 为 `2aeabb3dd165ea86d4cc5615b2d284c24a4e1f7bb34fb15f20835efa95c3ef81`。包内 `vba-src/` 为 2 个标准模块和 17 个工作簿或工作表对象模块，保留原 Windows-1252 字节及 VBA 属性。`workbook-parts/` 是其余 76 个 OPC 部件，按原包路径逐字节保留。`evidence/` 含部件、OLE 流和模块指纹、关系和绑定、p-code 与复核脚本。
- 原版 `xl/vbaProject.bin` 内含 VBA 工程保护元数据 `CMG`、`DPB`、`GC`，原件和该二进制保留在本地输入，正式成果只记录这些字段的存在和流指纹。对交付的源码、XML 和宏反汇编文本做了凭据关键词检查，未发现对应内容。成果未引用项目永久保护目录或其材料。

## 静态复核

- **包结构与布局**。原件 ZIP 成员名称唯一，CRC 全过。核验了全部 57 条内部关系和部件内容类型，外部 OPC 关系为 0。16 张工作表的工作表代码名和 `ThisWorkbook` 一一对应 VBA 对象模块。归档保留样式、共享字符串、绘图、VML、4 张控件预览及 ActiveX 和打印机状态。工作表 XML 内有 0 个单元格公式，计算实现在 VBA。见 `evidence/structure.json` 和 `evidence/controls.json`。
- **入口与数据绑定**。 `xl/worksheets/sheet1.xml` 的代码名为 `Sheet3`。沿关系 ID 和形状追到 4 个 ActiveX 定义及状态流。两个按钮对应 `Sheet3.cls` 的两个 `_Click` 过程；两个下拉控件分别写入 `B3`、`B4`，列表来自 `I6:I44`、`K6:K16`，工作表与 VML 的记录相符。保留 Microsoft Forms 控件状态并记录其外部组件边界。
- **模块完整性**。原 OLE 项目有 23 个流，其中 19 个为 `VBA/dir` 声明的模块。按每个模块的原始 `TextOffset` 解压得到对应源码并复算字节指纹。11 个过程分布于 3 个模块，另有 16 个仅含对象属性的模块。对应的 p-code 段结构与源码一致。未发现需另行恢复的 VBA 窗体存储、Excel 4.0 宏表或另一个内嵌程序。
- **关键逻辑**。按模块将 643 条 p-code 行记录（含空行）与去除导出属性行后的源码对齐。逐行对照 845 个名称操作数、128 条控制流指令、104 个字符串和 135 个数值字面量。比较中出现的 9 处字面量顺序差异，已通过栈上的参数及赋值目标复核，分别是后续成员调用的参数提前压栈和赋值左侧在右侧计算后取值。可重查 `evidence/logic-check.json` 的 `stack_order`。重点核对 `Sheet3.cls` 的选文件与运行入口、`MEBAspenGUI.bas` 第 72–74 行获取 Aspen 会话及 `ErrorTrap` 路径、单位表索引和流股读取，以及 `MEBTool.bas` 第 200–203 行的出入差额、阈值保护与相对差额。p-code `MEBTool` 198–201 行保留了相同的减法方向、分母、条件和写入动作。
- **签名差异已定位**。pcodedmp 1.2.6 从参数记录 `+0x14` 读下一项，本工作簿 Win64 记录的链接位于 `+0x18`。原始间接表按实际链接读出 `InitializeSimulatorInterface`、`FillStreams`、`ExtractStream` 的 3、2、6 个参数。在这三个过程的 6 处直接调用中，p-code 参数数与原始签名一致。对 `MEBAspenGUI` 5 个过程逐项核对了名称、类型、顺序、访问范围和可选参数；原表偏移和类型解析见 `evidence/signatures.json`。
- **回装验证**。本轮在内存中以 76 个归档部件加同 SHA-256 原件中的 `xl/vbaProject.bin` 组成工作簿。重新读取后，全部 77 个部件逐字节对照通过。宏未运行，回装未写成可运行的构建产物。

## 复查与 Windows 对照

本地使用 Python 3.12.14 的 `zipfile` 和 `ElementTree`、olefile 0.47、oletools 0.60.2 和 pcodedmp 1.2.6。先以 `python -B -m pcodedmp.pcodedmp -d -o <本件work/pcode.txt> <原件>` 导出指令，再使用包内 `evidence/tools/audit.py <本件目录>` 和 `compare_logic.py <本件目录>`。 `check_signatures.py` 接收原件、导出的 `MEBAspenGUI.bas`、p-code 文本路径和 `--tools <依赖路径>`。重封包证据由 `package.py` 生成。

Windows 重建以本地原工作簿作为对象模块和控件布局的模板。`MEBTool.bas` 和 `MEBAspenGUI.bas` 是标准模块源码；对象模块中的代码应写回原代码名对应的 Excel 对象，以保留事件及绑定。用原件或后续 Excel 编译产物提供 `xl/vbaProject.bin`。原 VBA 工程引用 Office、OLE Automation、Microsoft Forms 及 Aspen Plus GUI 39.0 类型库（`happ.dll`）；实际一次运行还需在 `Set-Up!B1` 指定 Aspen 模型。Windows 阶段验证文件选择、单位控件、Aspen 会话绑定、异常提示，以及相同模型和单位下的表格读写与质量、焓差额。

