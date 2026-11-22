# VBEXAMP.xlsm

## 结论与来源

**通过静态验收（2026-11-21）。** 原工作簿中的 18 个 VBA 模块均已恢复为可编辑文本。对照了原件的 31 个过程、工作簿资源及按钮入口。Excel 和 Aspen Plus 的实际运行留待 Windows 对照阶段。

- 产品为 Aspen Plus。安装位置对应 V15.0。清单未记独立工作簿版本，代码中 `OpenSim` 原样保存 `V15.0` 和 `41.0`。
- 原安装路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/VBDotNetexample/VBEXAMP.xlsm`。
- 原件来自 `DenseFLoe/Aspen-for-mac` 的 `codex/reverse-unsuccessful-85` 固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75`，仓库原件路径为 `原版文件/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/VBDotNetexample/VBEXAMP.xlsm`。按原件完整字节核验 47,572 字节，SHA-256 为 `8cfb7e1340f37d5a8344b28188591c5f419de1ecf4d1c071e05934974343faee`。
- 旧报告记录 `PEFormatError: DOS Header magic not found`，Git blob `9b312441746772ec8a047e5b74e80294bd89b3f0`。本次按 ZIP/OOXML → CFB → VBA 的结构处理，原件可完整解析。[固定提交中的原制作者报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/VBDotNetexample/VBEXAMP.xlsm/v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/VBEXAMP.xlsm.md)

## 交付与覆盖

- `VBA/` 含 14 个标准模块 `.bas`、1 个工作簿对象模块和 3 个工作表对象模块 `.cls`。文本保留 VBA 属性、注释和 CRLF，按原项目代码页 1252 解码并写成 UTF-8。每个模块可无损转回原编码，逐件指纹见 `evidence/part-and-stream-manifest.json` 的 `vba_project.modules`。三个工作表对象只有对象属性，工作簿的 `Workbook_Open` 有空过程体。
- `OOXML/` 按原名保留 19 个包成员（含内容类型清单），逐件内容指纹与原包一致。包括 3 张普通工作表、空的 Excel 4.0 宏表 `Macro1`、共享字符串、样式、主题及按钮的绘图、VML 和属性。宏表没有单元格、公式或工作簿定义名称。原 `xl/vbaProject.bin` 用作工作簿模板的一部分，保留项目引用和原始缓存。
- `PROJECT`、压缩 `dir` 和 18 个模块流逐项对应。CFB 共 58 个流（含 36 个 `__SRP_*` 版本相关缓存），唯一存储目录为 `VBA`，没有 UserForm 或嵌入控件代码。与宿主对象的绑定由工作簿和工作表的 `codeName` 对照。按钮是表单控件：`Sheet1` 的形状 1025 通过 `rId4` 连到 `xl/ctrlProps/ctrlProp1.xml`，绘图使用同一 ID，工作表及 VML 都登记 `[0]!RunAllExamples.Main`。
- Windows 对照可从 `OOXML/` 生成 Excel 工作簿模板，ZIP 根目录直接存放这些包成员，以 `.xlsm` 保存。源码改动应在 VBE 导入对应的标准模块，工作表和工作簿代码写回现有宿主对象模块。包里的 VBA 部件保持原始字节，目录中的文本编辑需要经 VBE 写回才会体现在工作簿中。

## 静态复验

- 用 Python 3.12.14 的 `zipfile` 与 `ElementTree` 检查 ZIP CRC、内容类型及 15 条内部关系。用 olefile 0.47 读取 CFB，oletools 0.60.2 的 `VBA_Project.parse_modules()` 解析 `PROJECT` 和 `dir`，按每一模块的 `MODULEOFFSET` 再读取压缩源段，对照输出的原编码字节。
- 用 pcodedmp 1.2.6 执行 `python -m pcodedmp.pcodedmp -d -o pcode.txt vbaProject.bin`，并以源码行与 p-code 行零基编号建立对应。对齐 497 条逻辑行，其中 397 条非空行。对照 31 个过程签名、90 个字符串、68 个整数、642 个标识符操作数、159 个运算符、40 个结构分支检查点及 15 个错误转移。签名、源码行和 p-code 行索引在 `evidence/module-verification.json`，反汇编见 `evidence/vba-pcode.txt`。
- pcodedmp 1.2.6 对 64 位参数链和自定义返回类型的展示有局限。逐条按过程记录参数首址字段（记录起点 +56）及参数记录的下一项字段（+24）追链，用参数类型字段（+16）、过程返回类型字段（+60）及对象表交叉核对。由此确认 `readFromRegistry` 的 `strRegistryKey, strDefault`、`UnitsString` 的 `ihAPsim, nRow, nCol`，以及 `OpenSimulation` 的 `IHapp` 返回类型。原始 dump 的 `<crash>` 是类型显示文本，项目记录、方法体和原源流均支持对应签名。
- `RunAllExamples.Main` 顺序为打开一次模拟，调用 11 个示例，最后关闭。`OpenSim` 的注册表读取、空路径回退、打开 `pfdtut.bkp` 及失败消息均有对应操作码。`ListBlocks.Status` 按原顺序使用状态位掩码。`UnitsConversion.UnitsString` 保留行列减 1 和异常后返回空串。`Run.RunExample` 保留 B6 塔级数输入、空输入退出、写参数、重算与再次提示的循环。各检查点可按源码和 p-code 行索引定位。
- 复验仅读文件、解析格式与类型库。旧报告适用的 PE 工具报错已由正确的文件格式和原件覆盖证据澄清。依据 [MS-OVBA 模块流](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/c66b58a6-f8ba-4141-9382-0612abce9926)、[项目成员](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/1883ad6a-628b-47e0-aac0-c292a87655bc)、[SRP 缓存](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/26f8053a-61ed-4c6a-a5ef-8b9933b67ef5)和 [pcodedmp 文档](https://github.com/bontchev/pcodedmp/blob/master/README.md)。

## 依赖、发布标记和待验证事项

- 原项目 `dir` 引用 OLE Automation 2.0、Microsoft Office 对象库 2.0、Happ 15.0（GUID `8E567520-F9BA-11CF-90B2-0000C0A810C4`，原描述 Aspen Plus GUI 40.0 Type Library）和 Windows Script Host Object Model 1.0。用 `LoadTypeLibEx(REGKIND_NONE)` 只读核实本机同 GUID 的 Happ 22.0（Aspen Plus GUI 41.0）及 Windows Script Host 1.0，见 `evidence/installed-typelibs.json`。原引用未改写。本机有代码对应的 `pfdtut.bkp`，仅核对路径。
- Windows 对照需确认 Excel 打开和保存、按钮分派、原 Happ 15.0 项目引用在实际部署中的解析、COM 打开模拟、所有示例输出和异常路径。本轮未启动 Excel 或 Aspen Plus。
- 未发现凭据或项目永久本地保护资产。已确认 VBA 项目密码字段是空密码标记，包内无加密条目、外部关系或数据连接。原 `OOXML/xl/printerSettings/printerSettings1.bin` 带模板制作环境的 UNC 打印机路径，`OOXML/docProps/core.xml` 带作者和最后修改者元数据。两份源资源原样留在本地成果，报告和证据未展示其值。[MS-OVBA ProjectPassword](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/79685426-30fe-43cd-9cbf-7f161c3de7d8)

