# vba_caller.xlsm

## 结论

**通过静态验收。** 原版是 Office Open XML（OOXML）宏工作簿，宏项目在 `xl/vbaProject.bin` 的 CFB 复合文件中。此前报告用 PE 工具打开整份工作簿，在 DOS 头检查处退出，本轮改按 OOXML、CFB 和 MS-OVBA 处理。

## 来源与指纹

- 产品 Properties，发行来源 Aspen Properties V15.0。清单的文件版本为空，工作簿亦无可用的独立文件版本。VBA 项目对 V12.1 路径的引用和工作簿中原保存路径均作为来源元数据保留。
- 安装路径 `[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/GUI/Examples/Excel Properties Calculator/vba_caller.xlsm`。
- 安装包成员 `AP_GUI~1.cab/vba_caller.xlsm.6A91E088_47BE_4B47_800D_141673B91317`。本机 Properties 安装包清单也登记了同指纹的安装副本。
- 取件自 `DenseFLoe/Aspen-for-mac` 的 `codex/reverse-unsuccessful-85` 固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75` 下的 `原版文件/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/GUI/Examples/Excel Properties Calculator/vba_caller.xlsm`。旧报告从同一提交读取，Git blob `59177148aeb4a23dac5c6d13ccecdf0e60e5b3ff`。
- 只读输入 `input/vba_caller.xlsm`，58,277 字节，SHA-256 `10b51a5d9521fb78e6d1d90ad9ec3a46e9afa2e397a7f91ba8dddc9ab8f43dc0`。
- 同目录成果 `vba_caller.xlsm.source.zip`，SHA-256 `928de28506bd5f767351824bf2cf73ddc314b798d1d29c0e92f222ceaaeeb611`。

## 恢复范围与证据

成果包内的 `vba/` 保存 5 个模块的原始可编辑文本，沿用项目代码页 Windows-1252、原行尾和属性。按 `VBA/dir` 的模块记录及 `MODULEOFFSET` 解压，逐个登记模块流及源码 SHA-256。`ooxml/` 保存除宏项目二进制外的全部 9 个原版 XML 部件，逐件与原件 ZIP 内的字节比对。部件、7 条内部关系、15 个 CFB 流、VBA 项目及引用记录均见 `evidence/project.json`。唯一工作表为空，工作簿与工作表的宿主代号分别为 `ThisWorkbook` 和 `Sheet1`，与两份文档模块对应。两份文档模块只有属性，均无过程或事件代码。包中没有 UserForm 存储、绘图、控件、工作表公式或定义名称。

| 可编辑成果 | 原件成员 | 源码行数 | 过程数 | 参数数 |
| --- | --- | ---: | ---: | ---: |
| `vba/ThisWorkbook.cls` | `VBA/ThisWorkbook` | 8 | 0 | 0 |
| `vba/Sheet1.cls` | `VBA/Sheet1` | 8 | 0 | 0 |
| `vba/LogFile.cls` | `VBA/LogFile` | 298 | 8 | 8 |
| `vba/Example.bas` | `VBA/Example` | 819 | 15 | 22 |
| `vba/Lib.bas` | `VBA/Lib` | 33 | 1 | 0 |

核验共对齐 1,137 个去掉属性并合并续行的逻辑行。24 个过程的名称、访问级别和边界，以及 30 个声明参数名称、传递方式和可选标记均能对照。核对了 241 条控制语句、429 个调用或索引操作数、304 个字符串、153 个数值和 180 条注释。内建参数类型对照参数记录；自定义类型的源码名和对应编译描述符分别记录。逐模块分页证据在 `evidence/modules/`，包含每个过程的源码行区间、从零开始的 P-code 行号、参数及关键指令。

- `Example.bas` 第 25–117 行记录入口分派、默认包与 `properties.aprbkp` 的选择、连接初始化和失败抛错。后续过程覆盖组成分数、单位换算、纯组分常数、纯组分和混合物性质、蒸气压与闪蒸调用。性质计算由引用的 Aspen 加载项提供。
- `LogFile.cls` 第 45–298 行保留日志格式选择、追加或覆盖、文件及目录检查、打开日志和错误处理。第 68、74、128、129、132 行的 `VBA.Len` 均与原缓存中相同的成员操作数对应。
- `Lib.bas` 第 5–32 行保留引用遍历、`IsBroken` 分支和错误处理指令。

## 工具与复核方法

使用 Python 3.12.14 的 ZIP 和 XML 解析器、olefile 0.47、oletools 0.60.2（olevba 严格模式）、pcodedmp 1.2.6。MS-OVBA 定义模块源码为独立于实现版本的表示，并以 `MODULEOFFSET` 分隔前置的版本相关性能缓存。[Microsoft 的模块流规范](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/c66b58a6-f8ba-4141-9382-0612abce9926)

原件为 64 位 Windows VBA7 项目，缓存版本 `0xB5`。在这个原件里，pcodedmp 对较高的外部标识符索引多减了 1，旧输出会错指相邻条目，例如把 `ValidateConnection` 显示为 `_B_var_Set`。省略该减法后，过程定义和调用中同一原始 ID 指向正确表项。64 位参数记录的链指针在记录起点 `+24`，按该位置逐个读取，保留正常参数并把末尾标识 `0xFFFE` 识别为函数返回槽。原件 5 处成员操作数 `0x00DE` 都位于 `VBA.Len` 表达式，单独按本件上下文核对。源码中的参数默认值和自定义类型名来自原版压缩源码，未凭旧版反汇编器猜补。

复核时将 `evidence/reproduce/` 四个脚本取出到相同件目录的 `scratch/`，让只读原件位于同级 `input/`，并将固定版本的依赖安装到 `scratch/deps/`。依次运行 `inspect_item.py`、`references.py` 和 `verify_cache.py`。`compare.py` 提供源码逻辑行与缓存解析。检查脚本会在 `scratch/` 生成私有原流或转储，仅用于本地复核。正式文件已做 ZIP CRC、逐成员内容和交付 SHA-256 的回读核验。

## 重建边界与材料标记

标准模块 `Example.bas`、`Lib.bas` 可作为 VBA 模块源。按宿主代号使用 `ThisWorkbook` 和 `Sheet1` 两个现有文档模块。将 `LogFile` 建为同名普通类，代码来自属性后的正文，原属性在第 1–8 行。包内的 `ooxml/` 是可编辑工作簿部件，未组装或启动带宏工作簿。

原 `VBA/dir` 记录了 `stdole`、`Office`、`VBIDE` 及 `Aspen Properties.xls` 项目引用。Aspen 引用的绝对和相对路径均指向 V12.1 的 `Engine/Xeq/Aspen Properties.xla`。本机清单列有 V15.0 同名 XLA，版本替代、引用重绑及 Excel 编译执行留待 Windows 对照。同目录的 `properties.aprbkp` 是选择文件包分支时使用的独立外部输入，其路径和分支已保留。

原件 `input/vba_caller.xlsm` 内的 `PROJECT` 流及工作文件 `scratch/project.private.txt` 含项目保护字段 `CMG`、`DPB`、`GC` 的原值，标记为仅本地。正式包仅保留相关结构和非保护记录，未发现公开交付中需要本地保护的项目数据库、公式归档或凭据。


