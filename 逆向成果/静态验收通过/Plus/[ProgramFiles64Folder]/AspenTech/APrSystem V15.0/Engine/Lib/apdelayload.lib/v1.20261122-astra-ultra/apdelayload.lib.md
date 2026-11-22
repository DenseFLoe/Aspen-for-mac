# apdelayload.lib 静态复验

**通过。** 从 [AMD64 汇编源码](apdelayload.lib.s) 独立汇编并封装后，回编库的 20,658 个字节与原件逐字节一致。两个链接索引、唯一对象成员，以及上轮缺失的异常展开栈保护均已核回。逐节、逐函数和逐条展开记录见[静态比对证据](evidence/static-comparison.json)。

## 原件

| 项目 | 核实结果 |
| --- | --- |
| 产品和原路径 | Aspen Plus V15.0，`Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Lib/apdelayload.lib` |
| 安装包来源 | `Process Modeling (Aspen Plus) V15 (64bit).msi` 配套 `APRS~228.cab`，成员 `apdelayload.lib.9DD71637_68A3_4F40_BE0C_34ABF98F3116` |
| 准备分支 | `DenseFLoe/Aspen-for-mac` 的 `codex/reverse-unsuccessful-85`，提交 `9559b75390876346c69b185dbaaba18692a7af75`，仓库路径为 `原版文件/` 加上表所列产品和原路径 |
| 本次输入 | 本地已提取的同哈希副本，位于项目内 `.local/aspen-plus-github-inputs-20261120-225559-578/originals/` 加原安装相对路径 |
| 完整库 SHA-256 | `d8c809c76f202e0df54bbc6315f0b16ce5840771099533988bdde0a5727b8afb` |
| 对象成员 | `delaylod.obj`，成员数据起点 1,314，长度 19,344，SHA-256 为 `6facead068ee5957ca9cf3dcd1ac8e15e09df31268e07bd2394fb7333dfec893` |
| 版本证据 | 安装路径标注 V15.0。版本选择函数引用字符串 `41.0`、`609`、`April 07 2025`。COFF 记录的编译器为 MSVC 19.40.33812，成员时间戳为 2025-04-07 19:12:09 UTC。 |

主干旧报告记录了按 PE/CLR 读取时找不到 DOS 头。真实文件以 `!<arch>\n` 起始，内含两个链接索引、一个长名称表和一个 AMD64 COFF 对象。上轮以该对象恢复了 C++，其回编件缺少异常展开时的 6 个 `__GSHandlerCheck` 引用。本次保留同一归档成员的指令、重定位、栈帧布局和异常数据。[主干旧报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/main/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/Engine/Lib/apdelayload.lib/README.md)

## 代码、数据与依赖

源码以原函数名、具名数据、分支标签和符号引用表达实现。复用了同一成员的 Ghidra 12.2 指令边界，在未重定位的原节和回编节上分别使用 Capstone 5.0.7 解码。五个代码节共 6,737 字节，其中 6,488 字节对应 1,648 条指令，56 字节对应两张跳转表，其余 193 字节为函数间填充。两张表的全部 14 个入口均落在已核对的指令边界。

| 范围 | 原件与回编件的核对 |
| --- | --- |
| 版本和产品选择 | 4 个 `zever_*` 函数保留两字符版本缓冲区及边界检查、1 至 8 的版本字符串分派、错误格式串和产品代码选择。 |
| 注册表和路径 | `Get_AspTop`、`Get_APrSystem_Top`、`GetOOMFTop`、`GetRegistryValue`、`AddToPath` 保留键名、访问掩码、读取及关闭顺序、环境变量读写和失败分支。 |
| 参数及短路径 | `parse_line` 的计数与写入路径、引号和反斜线分支，以及 `searchargs`、`GetShortName`、`ConvertPathsToShortName` 的调用和缓冲区操作逐字节吻合。 |
| 延迟加载通知 | `NotifyHook` 的首次处理标志、六项通知表、Common Files、AOS、OOMF、APrSystem 和当前产品路径的处理顺序均保留。 |
| CRT 及链接 | 4 个 CRT 包装入口完整。两个链接索引各含同样的 15 个函数和 1 个数据符号。计入 3 个内部函数，共 18 个实现。20 个未定义符号按原件作为外部边界保留，详见证据的 `undefined_symbols`。 |
| 数据、资源与构建记录 | 22 个节涵盖字符串、可写状态、链接指令、代码、函数表、展开数据、CodeView 编译记录和节校验。两端 332 个重定位以及符号类型、存储类别、COMDAT 关联均一致。未发现独立资源或第二个代码对象。 |

## 上轮缺口复验

原件 26 条函数展开范围中，有 6 条直接指定栈保护处理器，11 条链式记录绑定到父范围。源码对范围起止、处理器、父记录和序言内指令使用符号表达式。逐条解析两端的 `.pdata` 和 `.xdata` 后，范围、展开操作、父链和处理器数据一致。以下偏移均为原节内十六进制偏移。

| 函数 | 主代码节起点 | 展开数据节 #15 的处理器重定位位置 | 栈保护附加数据 |
| --- | ---: | ---: | ---: |
| Get_AspTop | 0x380 | 0x24 | 0xc0 |
| Get_APrSystem_Top | 0x4b0 | 0x3c | 0xc0 |
| GetOOMFTop | 0x5d0 | 0x50 | 0x1c0 |
| GetShortName | 0xaa0 | 0xdc | 0x140 |
| ConvertPathsToShortName | 0xb50 | 0xf8 | 0x250 |
| NotifyHook | 0xcb0 | 0x130 | 0x620 |

## 复现与指纹

使用 Python 3.12.14 和面向 Windows x64 的 GNU as 2.39。运行方法见[构建说明](build.md)。Microsoft COFF/PE Dumper 14.29.30145.0 独立读出 16 个公开链接符号以及分属四个函数表的 1、1、1、23 条记录。

正式源码回编后，整库和对象成员的长度、SHA-256 均与上表相同。另在临时副本进行两次独立修改。默认产品码由 1 改为 2 时，初始化数据节和对应校验随之改变。将 `zever_set_productcode` 中的比较常数从 2 改为 3 时，主代码节仅偏移 `0x354` 的立即数发生变化。两次实验的异常展开记录均与基线相同。

| 成果 | SHA-256 |
| --- | --- |
| `apdelayload.lib.s` | `4b5985b679beb4d0d04d7859b838a6b4362c8f8e3ff82ef6afc10618cf9bd0e6` |
| `build.py` | `4426954c0ab9ed2c707c872ba66930850c7f969a948d53b05fb07cc83db457f4` |
| `evidence/static-comparison.json` | `864999519431e01374cd4b8ac946688c59ae69422099d4c3adb97746cc1cbe2c` |

本次整件静态验收已完成。Windows 重建对照阶段再验证宿主触发延迟加载时的注册表读取、PATH 变更、短路径 API 和异常展开行为。

