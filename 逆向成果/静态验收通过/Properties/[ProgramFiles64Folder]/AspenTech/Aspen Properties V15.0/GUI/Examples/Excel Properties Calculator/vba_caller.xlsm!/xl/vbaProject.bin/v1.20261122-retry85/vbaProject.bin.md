# vbaProject.bin

## 静态验收通过

原件是 Excel 宏工作簿内的 CFB（复合文档）格式 VBA 项目。旧报告用 `dnfile` 和 `pefile` 查找 DOS/PE 文件头，未抽取代码。本次从 CFB 流目录和 VBA 模块记录恢复全部 5 份可编辑源码，并用同一原件的 P-code 核对 24 个过程。

## 来源与指纹

- 产品为 Properties，安装来源为 Aspen Properties V15.0。清单未记本成员的独立文件版本。VBA 缓存版本为 `0xB5`，`SYSKIND=3` 表示 64 位 Windows，外部引用中的 V12.1 是原始路径。
- 原安装及内层路径为 `Properties/[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/GUI/Examples/Excel Properties Calculator/vba_caller.xlsm!/xl/vbaProject.bin`。
- 从 `DenseFLoe/Aspen-for-mac` 的 `codex/reverse-unsuccessful-85` 固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75` 下的 `原版文件/` 对应路径取件。旧制作者报告同提交，版本目录为 `v0.20261121-w2`，报告 blob 为 `d00533dd3fe0fd5701d3e8225757b264ffe5935c`。
- `input/vbaProject.bin` 为 141,312 字节，SHA-256 为 `4e0bf2a2925b54c25f94911bdcce38a391f65ccb4667ea10841545c6dda8ba6f`。同批 `vba_caller.xlsm`（SHA-256 `10b51a5d9521fb78e6d1d90ad9ec3a46e9afa2e397a7f91ba8dddc9ab8f43dc0`）的同名成员和本文件逐字节一致。
- 同目录 `vbaProject.bin.source.zip` 的 SHA-256 为 `99776707b6c850572d0b12d63776232a4f7aaaf892195badd36a692d5a090f16`。

## 源码、资源与验收证据

从 CFB 原件读取 `VBA/dir`，按各模块记录的 `MODULEOFFSET` 解压，用 Windows-1252 严格解码验证，按原始编码和行尾保存源码。核对 `PROJECT` 的 5 条模块类型记录、`PROJECTwm` 的 5 对 ANSI/Unicode 名称和每份源码中的 `VB_Name`。CFB 只有 `VBA` 一个子存储，15 个流已逐一登记大小和指纹。其中 5 个模块流、`PROJECT`、`PROJECTwm` 和 `VBA/dir` 所需的模块、项目及引用信息已恢复。其余为 `_VBA_PROJECT` 及 6 个 `__SRP_*` 缓存流。未发现 UserForm 或其他设计器存储。格式判定依据见 [MS-OVBA 模块流规范](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/c66b58a6-f8ba-4141-9382-0612abce9926)和 [VBA 存储规范](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/b693e0ba-489f-4ac8-ac9d-6387fb5779bb)。

| 成果包内可编辑源码 | CFB 源流 | 源码行 | 过程 | 参数 |
| --- | --- | ---: | ---: | ---: |
| `vba/ThisWorkbook.cls` | `VBA/ThisWorkbook` | 8 | 0 | 0 |
| `vba/Sheet1.cls` | `VBA/Sheet1` | 8 | 0 | 0 |
| `vba/LogFile.cls` | `VBA/LogFile` | 298 | 8 | 8 |
| `vba/Example.bas` | `VBA/Example` | 819 | 15 | 22 |
| `vba/Lib.bas` | `VBA/Lib` | 33 | 1 | 0 |

从本件单独重新解码并核对 1,137 个 VBA 逻辑行，包括 241 处分支及其他控制语句、429 处调用或索引操作数、304 个字符串常量、153 个数值常量及 180 条注释。过程名称、缓存内的起止位置、参数名、传递方式和可选标记有逐过程对应。内建参数类型对照缓存记录。自定义类型和参数默认值保留原压缩源码，并记录缓存中的类型记录。两份文档模块只有属性，过程数为零。复验生成的五份模块证据和源码逐份对照同指纹的外层工作簿验收包并一致。

- `Example.bas` 第 25–117 行覆盖入口分派、可选的 `properties.aprbkp` 路径、连接初始化及失败处理。后续过程覆盖组分查询、单位、相平衡及物性调用。物性计算由外部 Aspen 加载项执行。
- `LogFile.cls` 第 45–298 行覆盖日志选择、追加或覆盖、文件及目录检查、写入关闭和异常路径。
- `Lib.bas` 第 5–32 行覆盖引用遍历、`IsBroken` 分支及错误处理。
- `evidence/project.json` 记录全部存储和流的覆盖、项目成员类型、引用、来源及工具版本。`evidence/modules/` 分模块记录流指纹、源码行、过程范围、参数和定位到行号的 P-code 核对证据。

## 复查步骤

使用 Python 3.12.14、olefile 0.47、oletools 0.60.2 和 pcodedmp 1.2.6。复查时将 `evidence/reproduce/` 内脚本放在本件 `scratch/`，同级 `input/` 放入哈希相同原件，Python 环境提供上述库。依次执行 `inspect_item.py`、`references.py`、`verify_cache.py`，生成 `structure.json`、`references.json`、`coverage.json` 和 `stage/source/`。本次复用同批的行解析及缓存校验逻辑，在单独的 CFB 输入上重跑。

缓存解码按本件 `0xB5` 版本修正较高的外部标识符索引，按 64 位参数记录的 `+24` 指针遍历参数，并识别 `0xFFFE` 返回槽。缓存原始标识符 `0x00DE` 的 5 处使用点与源码的 `VBA.Len` 一一对应。该对照用来检查关键行为与源码覆盖。归档已回读，逐成员和 ZIP CRC 均通过。

## 重建边界与本地保留

在 Excel VBA 项目中将两个 `.bas` 作为标准模块、`LogFile.cls` 作为类模块，并把文档模块内容对应到宿主已有的 `ThisWorkbook` 和 `Sheet1`。本件范围止于 `vbaProject.bin`，外层工作簿的关系和 XML 布局由同批工作簿件提供。引用包括 `stdole`、`Office`、`VBIDE` 和 `Aspen Properties.xls`。原始项目引用路径指向 V12.1 的 `Engine/Xeq/Aspen Properties.xla`，实际加载 V15.0 XLA、Excel 调用、日志写入和物性输出留待 Windows 重建对照。

`input/vbaProject.bin` 内的 `PROJECT` 流含项目保护字段 `CMG`、`DPB` 和 `GC` 的原始值，标记为仅本地保留。成果包只保留字段名和非保护记录，已核对归档成员不含三项保护值。未发现需按项目永久本地保护的数据库、公式归档或凭据。

