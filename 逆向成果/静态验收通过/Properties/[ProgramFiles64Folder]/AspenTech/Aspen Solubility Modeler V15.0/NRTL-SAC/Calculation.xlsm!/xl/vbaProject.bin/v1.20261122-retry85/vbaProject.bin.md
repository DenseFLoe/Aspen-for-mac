# vbaProject.bin

**静态验收通过（2026-11-21）。** 恢复 17 个 VBA 模块共 61,387 字节、69 个过程，以及 frmHTE 的四个原生窗体设计流。宿主、依赖和控件的实机对照留待 Windows 阶段。

## 原件和旧报告

- Aspen Properties 的 Aspen Solubility Modeler V15.0 安装载荷。原安装及内层路径为 Properties/[ProgramFiles64Folder]/AspenTech/Aspen Solubility Modeler V15.0/NRTL-SAC/Calculation.xlsm!/xl/vbaProject.bin。清单未记内层文件的独立版本。
- 从 codex/reverse-unsuccessful-85 的固定准备提交 9559b75390876346c69b185dbaaba18692a7af75 取原件。仓库路径为 原版文件/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Solubility Modeler V15.0/NRTL-SAC/Calculation.xlsm!/xl/vbaProject.bin。
- 原件 226,816 字节，SHA-256 为 2ee31997f86026cbc84fdda380790a4ca2c9a4805358b29c1991cfc9b755ba10。本机已安装工作簿内 xl/vbaProject.bin 的指纹独立复核一致。安装载荷与本机工作簿是清单中的两条同指纹来源。
- 旧报告使用 PE 工具，因缺 DOS 文件头退出。原件文件头为 D0 CF 11 E0 A1 B1 1A E1，内部为 OLE/VBA 工程。旧报告经 GitHub 连接器回读，blob 为 fbe74454f92d5a90c873ac9a6695ed3923443206。[旧制作者报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Properties/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Solubility%20Modeler%20V15.0/NRTL-SAC/Calculation.xlsm%21/xl/vbaProject.bin/v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/vbaProject.bin.md)

## 源码和静态对照

使用现有 Python 3.12.14、olefile 0.47、oletools 0.60.2 和 pcodedmp 1.2.6。PROJECT、PROJECTwm 和 VBA/dir 均对应全部 17 个源码模块。根据每个 MODULEOFFSET 读取压缩源码，olevba 和独立 MS-OVBA 解码器的 17 份结果逐字节相同，保留代码页 1252、换行和属性。[MS-OVBA 模块流](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/c66b58a6-f8ba-4141-9382-0612abce9926)

已归类并记录 59 个 OLE 流，覆盖 17 个模块流、4 个设计流、3 个项目元数据流、1 个项目版本相关缓存流和 34 个 __SRP_* 缓存流。缓存流用于对照，重建以源码和设计资源为输入。Sheet4 和 frmHTE 的源模块只含属性，相应缓存中均无过程声明。

本件 VBA7 64 位缓存的版本字段为 0x00B5。pcodedmp 对项目名称索引大于 0xBE 的值额外减 1，在 Sheet15、Sheet5、Sheet12 共误读 18 个声明。本件跳过该减量后，69 个声明位置的名称全部对应，操作码计数保持相同。逐过程核对循环、块 If 终止、错误处理和提前退出计数，差异为零。逐过程核对 240 条字符串常量，出现次数全部匹配。四个语句的加载顺序差异均能定位为先评估右侧，再计算赋值目标 Range。

关键复核位置包括 ThisWorkbook.Workbook_open 的加载项检查和初始化，Sheet8.Worksheet_SelectionChange 的选中单元格与图表更新，Sheet15.cmdDrawTernaryPhaseDiagram_Click、Sheet5.cmdDQPD_Click 和 Sheet12.btnDraw_Click 的分支、循环、单元格读写及图表调用。

## 窗体和宿主

frmHTE 的 CompObj、VBFrame、f、o 四个原始流可按原流名无损恢复。对照了四个标签的名称、标题、位置、尺寸和类型。原流保留其他序列化控件属性，Sheet8 源码使用窗体显示计算进度。[MS-OVBA Designer Storages](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/f614ae64-1b3d-47be-a166-0e10b8230026)

使用外层原工作簿选定 ThisWorkbook 和 14 个工作表 CodeName，核对 56 个 VB_Control 属性与工作表 ActiveX 记录、注册类标识及 28 个控件事件入口。证据保留 Excel Calculator、ATCO、Pfsplot、MSForms、许可组件及帮助库的引用元数据和外层包的三份 VBA 签名部件路径。

## 复核和本地保护

vbaProject.bin.evidence.json 包含逐模块、逐过程、逐流和宿主绑定证据。vbaProject.bin.designer.json 包含原窗体流和布局。使用本件 work 内脚本可重跑校验，顺序为 pcodedmp -d、audit.py、pcode_adjusted.py、将 audit.py 的缓存输入切换到 pcode-adjusted.txt 并将其 JSON 输出改为 audit-adjusted.json、prepare.py、literal_check.py。

local-only/vbaProject.bin.Sheet8.cls 含工作表保护口令，在本地正式目录中保留。原件 PROJECT 含口令相关保护字段，两份原始缓存反汇编也会带入口令。公开交接按 handover.json 的 shareable_files 白名单选取文件。外层工作簿中的单元格公式、数据库和项目长期保护归档均未复制。

窗体采用代码与逐流设计资源交付。文档模块按原工作簿或工作表 CodeName 应用。Excel/VBE 的源码与窗体导入、依赖加载和行为对照留待 Windows 阶段，本轮未执行宏或回编。

| 模块 | 源码字节 | 过程数 | 范围 |
| --- | ---: | ---: | --- |
| Sheet1 | 1019 | 3 | 源码 |
| Sheet2 | 494 | 2 | 源码 |
| Sheet3 | 3185 | 5 | 源码 |
| ThisWorkbook | 3838 | 2 | 源码 |
| Sheet13 | 1014 | 3 | 源码 |
| Sheet14 | 7812 | 5 | 源码 |
| Sheet6 | 1015 | 3 | 源码 |
| Sheet7 | 1015 | 3 | 源码 |
| Module1 | 7168 | 2 | 源码 |
| Sheet8 | 8420 | 6 | 仅本地 |
| frmHTE | 343 | 0 | 源码 |
| Sheet10 | 3549 | 4 | 源码 |
| Sheet11 | 2244 | 4 | 源码 |
| Sheet15 | 4445 | 6 | 源码 |
| Sheet5 | 10435 | 16 | 源码 |
| Sheet12 | 5092 | 5 | 源码 |
| Sheet4 | 299 | 0 | 源码 |

| 正式文件 | SHA-256 | 范围 |
| --- | --- | --- |
| local-only/vbaProject.bin.Sheet8.cls | 0f75058987c2c5a18280fd4606c585648cd7fe3f2022d858babb602da394055a | 仅本地 |
| local-only/vbaProject.bin.Sheet8.cls.md | 60f1b9b773ad42abaca3b0a3fd1ce81c7c0f97ebdd03b3ed069a7598a9308d5e | 仅本地 |
| vbaProject.bin.Module1.bas | 0045c734e36603c5ed69722a0bfc227ee3eb833197fbd797a2b94420f8f81ba1 | 正式成果 |
| vbaProject.bin.Module1.bas.md | 35bb9eb71bc935e2dc5bad62994e092f7b2cc4349db24fad96e7fa27d16dfc20 | 正式成果 |
| vbaProject.bin.Sheet1.cls | 6eb775c8b245e2c4602690a6063914ebb1d39be29cf2c18ac07cf0303aff713d | 正式成果 |
| vbaProject.bin.Sheet1.cls.md | b855975aa2c4e81834b60b698e361bdf1032184214e31c428cdff8342e5b2006 | 正式成果 |
| vbaProject.bin.Sheet10.cls | 7ab43854d0ad09cca734ffadbbf47443684c1f1700b89aae0429b696efb44206 | 正式成果 |
| vbaProject.bin.Sheet10.cls.md | c54f0ddc1be2bfd82a4505319fde819f0950721d1563a3ae7f7f93326d1aa6ea | 正式成果 |
| vbaProject.bin.Sheet11.cls | 0ad1af6ea249f91d708cc5a0bb0c1165d4a80aa7017230966687205d338195c3 | 正式成果 |
| vbaProject.bin.Sheet11.cls.md | f37dbfd26b75ef7fdacf4ba40033b8b0168ca271dcc5f47c03c9369a587932b5 | 正式成果 |
| vbaProject.bin.Sheet12.cls | 302bf8b6debbb01bc773f692beb1a2c623da7cebe4c4fa4357ad569797f292a7 | 正式成果 |
| vbaProject.bin.Sheet12.cls.md | e913ae0e09df1f88ff64b5fecf4555322093737b7b2db03e2692bf007e4f8369 | 正式成果 |
| vbaProject.bin.Sheet13.cls | 92739b615460f865f95e2004ef3931ed54e7b7bb56b538622df05161ce77efaa | 正式成果 |
| vbaProject.bin.Sheet13.cls.md | 4f2d0b5eb41ca67b199b1e26a76f63a090e090bf7cabd721583cc431854d01a6 | 正式成果 |
| vbaProject.bin.Sheet14.cls | 5061450b5034a8a6d2989c341ebc95adb8d630650d79ef6f82380c3ec92fb91e | 正式成果 |
| vbaProject.bin.Sheet14.cls.md | 83d9c1bd77111da98ace5f948076731be401d8d548570c1242d1fddf1274f9bd | 正式成果 |
| vbaProject.bin.Sheet15.cls | e2520098ca9644a18d1c757720d16181c54e217905e520e2e9417208dcdf44f0 | 正式成果 |
| vbaProject.bin.Sheet15.cls.md | bd39fdfdc9abf827850a7ab15f090ea9b429559b31e45ca84897c6581c4e8632 | 正式成果 |
| vbaProject.bin.Sheet2.cls | 880b18f6c41899add1b86b4845a3ef57d9d183f5de281e46f50f2782a34ba5bd | 正式成果 |
| vbaProject.bin.Sheet2.cls.md | c24f6203101114225e348d5ca2acf6e6b5a52a5030f302ceef09d26af28b416b | 正式成果 |
| vbaProject.bin.Sheet3.cls | b9e1d2960cfddc256447e9315497952f073c3e74e68b36f83ef73f34fd3f647a | 正式成果 |
| vbaProject.bin.Sheet3.cls.md | 6ad4e7045f8957e36e774635309a44ea6f01d18459d669f6fe275fd450946d21 | 正式成果 |
| vbaProject.bin.Sheet4.cls | 12a0f7735c6438a01176ea862764077f158f4cf3ceec0025bc7bea6477a8f5e1 | 正式成果 |
| vbaProject.bin.Sheet4.cls.md | f2287812518bd42250f824992054b83bd9de4c723f71649ac6ff87a5e8d36baa | 正式成果 |
| vbaProject.bin.Sheet5.cls | 1599cd22f02765483a6651808fc9f0644f21a64d62990d9e360afe08ad3a5f11 | 正式成果 |
| vbaProject.bin.Sheet5.cls.md | f80d580b78a0593587705529c9bbfa7d40c7aa41254a6fa286fd591bbff376cd | 正式成果 |
| vbaProject.bin.Sheet6.cls | c8fc7c1cbbd52bb4da758d07b47ef6d0b781bef853225528cef7ff7c550a438c | 正式成果 |
| vbaProject.bin.Sheet6.cls.md | 1683f720ac0c98f94847e6b0238f2cd18bc2d2350c01068d9ee73cf5adf0ca50 | 正式成果 |
| vbaProject.bin.Sheet7.cls | 174c269ba1b5ecb7d9d8338b8b8cc03f194977f5436cbf31c5175c43c8b7c66a | 正式成果 |
| vbaProject.bin.Sheet7.cls.md | fba60824e4a0833fa50d96f0c224e5c6d31344fb9d22f1c05539faa451193375 | 正式成果 |
| vbaProject.bin.ThisWorkbook.cls | 2a0439928f41e3a4b9b457b2fa5b022d7062bf99ed51790fe1ce8828c047ec6c | 正式成果 |
| vbaProject.bin.ThisWorkbook.cls.md | 28ad0c17ef9578b63e3cdf126303b28af1503bbc88d66a0aa1bb0d17d4f95973 | 正式成果 |
| vbaProject.bin.designer.json | d010e8ea8772bcc868ba0f5f1a9e31a3faeffb90f7a8b86f39b6d395ac6b7065 | 正式成果 |
| vbaProject.bin.designer.json.md | 3a350c01705c1aaedb2df357d269ca5b3f0ab9f228f1cd8c15b2f72f11f24b81 | 正式成果 |
| vbaProject.bin.evidence.json | e3c820b2278dddb795e155b047096fbf04436a111157853a764d75a592192360 | 正式成果 |
| vbaProject.bin.evidence.json.md | 99d5ab9cd5dc4b0268cc96b01a8fc55ab9347d29be00c51d6afe733bb46e1db7 | 正式成果 |
| vbaProject.bin.frmHTE.frm.vba | 953867dd63f57db314449a483677265c62db0ec8775ef2bcadb60f84ec14aaa8 | 正式成果 |
| vbaProject.bin.frmHTE.frm.vba.md | 10a5a6af6ecd0bb32e7e759b49634f6121dfac7a14ad92391dc52bc8a3138df2 | 正式成果 |
