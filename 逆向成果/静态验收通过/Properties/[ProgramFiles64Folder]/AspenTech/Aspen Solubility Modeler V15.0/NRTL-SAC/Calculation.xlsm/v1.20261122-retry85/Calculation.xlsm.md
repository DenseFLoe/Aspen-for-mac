# Calculation.xlsm

**静态验收通过。成果包仅限本地。**

## 来源

- 产品为 Aspen Properties。安装来源位于 Aspen Solubility Modeler V15.0 的 NRTL-SAC 目录。工作簿自身版本未登记。
- 原相对路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Solubility Modeler V15.0/NRTL-SAC/Calculation.xlsm`。
- 原件大小 869,469 字节，SHA-256 为 `52674742bc3dd7acb67367c4c72e1c8fe0cfde23b023f9050c1eef84baecf0b0`。本轮从 GitHub 分支 `codex/reverse-unsuccessful-85` 的固定提交 `9559b75390876346c69b185dbaaba18692a7af75` 取件，下载后及取证前均复核指纹。
- 旧报告 `v0.20261121-w2/制作者报告/Calculation.xlsm.md` 用 PE 工具读取失败。本轮改用 ZIP/OOXML、OLE 复合文件和 VBA 模块流解析。VBA 内层原件 `xl/vbaProject.bin` 的 SHA-256 为 `2ee31997f86026cbc84fdda380790a4ca2c9a4805358b29c1991cfc9b755ba10`。

## 交付和复查

| 成果包 | SHA-256 |
| --- | --- |
| `Calculation.xlsm.source.zip` | `36763d879c8fbb1e8dd3c10788045413360715dda3faffa03ed482009be381e7` |

- `opc/` 是可编辑的 OOXML 树，保留原始 XML、公式、关系、字符串、缓存值、样式、图形和二进制资源。用 Python 3 运行 `python repack_ooxml.py opc Repacked.xlsm` 可把编辑后的 OOXML 部件封装到新工作簿。脚本保留现有的 VBA 项目及三份签名资源。未编辑时重新封装，349 个部件的路径和内容逐字节相等。ZIP 元数据和压缩流会变化。
- `vba/` 是 17 份可以直接阅读和修改的 VBA 源文本，保持原 CP1252 字节和模块属性。编辑宏须在 Windows Excel 的 VBA 编辑器对原件副本中的同名宿主模块或窗体应用文本的代码段，普通模块使用 `Module1.bas`。保留工作表的 VBA CodeName、窗体实例及原有控件绑定。`frmHTE.frm.vba` 为窗体代码段，窗体设计器的 `VBFrame`、四个控件的解析记录和 OLE 资源位于 `form/frmHTE/`。修改宏后的签名和编译由 Windows 阶段处理。
- `evidence/coverage.json` 记录逐部件指纹、每张表的公式指纹与控件关系，以及 VBA 模块流、源码偏移、过程名、原始编译标识符和证据定位。`evidence/procedure_checks.json` 记录逐过程核验结果。对应 Python 取证脚本同在 `evidence/`。
- 工具为 Python 3.12.14、olefile 0.47、oletools 0.60.2 和 pcodedmp 1.2.6。复查提取时，在本件隔离目录提供 `input/Calculation.xlsm`、从其 OOXML 提取的 `work/vbaProject.bin`、`work/repack_ooxml.py` 和已有工具路径。按顺序运行 `recover_workbook.py <本件目录>`、`check_procedures.py <本件目录>`。第二步在内存检查原缓存，仅输出结构结果和定位。 [MS-OVBA 模块流规范](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/c66b58a6-f8ba-4141-9382-0612abce9926)

## 静态证据

- OOXML 部件共 349 个，含 14 张工作表、14,579 个单元格公式节点、61 个工作簿定义名称和 20 个图表。原生公式节点含普通 1,842 个、共享 8,894 个、数组 3,843 个。工作簿内的 OPC 关系目标和所用关系 ID 全部可解析。
- 56 个工作表 ActiveX 控件均定位到描述、布局形状及所需持久化属性，含 53 个关联的二进制属性部件和 3 个直接以 XML 保存属性的控件。28 个 VBA 控件事件过程对应到原 CodeName 和控件名。窗体 `frmHTE` 有四个控件，原始窗体资源与单独解出的布局数据一并保存。
- `VBA/dir` 声明、`PROJECT` 模块角色、实际模块流和交付源文本一致。15 个宿主文档模块、1 个普通模块及 1 个窗体模块全部覆盖。逐流按原偏移解压得到的源码与交付文件逐字节一致。源码的 69 个过程与缓存中的 69 个过程逐模块、逐过程对应。
- 原 P-code 缓存版本为 64 位 `0x00B5`。pcodedmp 1.2.6 针对高位索引再减一，导致 `Sheet15`、`Sheet5`、`Sheet12` 的 18 个过程名称偏移。直接从原间接表读取过程标识符并按 `(raw_id >> 1) - 0x107` 查询原项目标识符表，69 个名称与过程种类全部吻合。证据保留原渲染名称、原标识符字和纠正后的名称。
- 69 个过程比较了字符串字面量序列、错误处理、循环、块级分支、选择分支和提前退出的相关指令计数。四处赋值按缓存的实际求值顺序复核，包括 `Sheet12.btnDraw_Click` 第 103 行的三元组成写入，原 P-code 第 88 行先求右侧再解析目标单元格。处理这四处顺序后，所比字符串和控制流计数一致。

## 依赖和后续

- `xl/externalLinks/externalLink1.xml` 保留 12 个来自 `Aspen Properties.xla` 的名称和两条外部路径记录。4,231 个公式节点显式使用外部工作簿索引。现有 Properties 清单把该加载项定位到 `[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/Engine/xeq/Aspen Properties.xla`，SHA-256 为 `d124683bb13ceb5c6a39f661661fc727e67289fdb6257f8bd25b82246dd18919`。`Module1` 通过 Excel COM 加载项集合检查连接，`Sheet14` 调用 `COMAddinHelper.SelectPackage`，`Sheet3` 调用 `getUnits`。这些是运行依赖。
- 实际打开、宏编辑后的编译、加载 Aspen Properties、点击控件、重算、保存重开和数值对照安排在 Windows 重建阶段。
- **仅本地。** 源码 `vba/Sheet8.cls` 的工作表保护相关注释含口令。该源码、内嵌宏项目、原件、反汇编及其衍生副本均按凭据处理。成果包还包含原工作簿的公式及原缓存数据。协调交接只使用这份说明和状态元数据，整份成果包标记为本地保护材料。
