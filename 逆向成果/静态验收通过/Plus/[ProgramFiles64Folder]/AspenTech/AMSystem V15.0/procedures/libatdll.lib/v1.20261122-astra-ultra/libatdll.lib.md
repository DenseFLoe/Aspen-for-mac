# libatdll.lib 静态复验

**整件通过静态验收。** 已从可编辑的 x64 汇编及 COFF 元数据重建全部 5 个成员。回编库与安装原件的 415,920 字节逐字节一致，SHA-256 均为 `aa423ce85b3c9a4bb16ae0c42ea8b939d4fe8f4c78ab98c9086ae4db9fea518f`。构建程序仅读取交付的源码和元数据。原件用于最后的独立对照。

## 原件和已有证据

原相对路径为 `Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/procedures/libatdll.lib`。本轮使用本机 `C:/Program Files/AspenTech/AMSystem V15.0/Procedures/libatdll.lib`。长度和 SHA-256 符合准备分支 `codex/reverse-unsuccessful-85` 上提交 `9559b75390876346c69b185dbaaba18692a7af75` 的非 LFS 原件记录。组件为 AMSystem V15.0，库中版本文本标示 41.0 Apr 11 2025。[固定原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/原版文件/Plus/%5BProgramFiles64Folder%5D/AspenTech/AMSystem%20V15.0/procedures/libatdll.lib)

主干历史报告曾尝试按独立 PE 读取整个库，blob 为 `b8fa17a305793e8be3a5b7a407be4dd3be854ee7`。上一次本地 Ghidra 12.2 分析已拆出 5 个 COFF 对象，报告记录了函数入口、ABI 和指令覆盖缺口。本轮以原库内成员的偏移、长度和内容校验上次的拆分件后复用。[历史报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/main/逆向成果/未成功/Plus/%5BProgramFiles64Folder%5D/AspenTech/AMSystem%20V15.0/procedures/libatdll.lib/v0.20261121-w2/制作者报告/libatdll.lib.md)

## 覆盖与验收

| 成员 | COFF 节 | 函数符号 | 汇编指令 | 指令字节 | 代码节内表字节 | 重定位 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| xos_dll.obj | 216 | 30 | 1,442 | 5,409 | 0 | 1,219 |
| sput_dll_utils.obj | 154 | 30 | 1,295 | 4,790 | 76 | 983 |
| atdll.obj | 6 | 0 | 0 | 0 | 0 | 3 |
| ACMException.obj | 32 | 6 | 90 | 338 | 0 | 126 |
| acm_dll.obj | 144 | 29 | 538 | 1,923 | 0 | 594 |
| **合计** | **552** | **95** | **3,365** | **12,460** | **76** | **2,925** |

94 个可执行节共 12,536 字节。95 个函数符号均落在指令首字节。独立检查了 366 个同节直接控制转移目标、459 个指令内重定位及跳转表的 6 个目标，94 个间接控制转移也在证据中逐条列出。两份链接器索引各有 166 个条目，核对每个名字都指向定义它的对象。恢复全部符号、COMDAT 关联、弱外部符号、BSS、虚表、RTTI、版本及错误文本、CRT 初始化、106 个 .pdata 节、130 个 .xdata 节和 3 个 .xdata$x 节。105 个 .debug$S、5 个 .debug$T 和 1,892 个调试重定位均精确还原。原库内的类型服务器记录保留原 PDB 路径、GUID 和 age。其余 1,033 个重定位也逐项比对。成员、各节和完整归档的核验均已通过。[逐件比对](libatdll.lib.audit.json)

## 旧缺口的逐项结论

- **ACM_Print 的 79 个未解码字节。** sput_dll_utils.obj 第 43 节 +0x656 是 2 字节 NOP，+0x658 起为 6 个四字节 RVA，+0x670 起为 52 个单字节选择值。第 45 节 +0x4E 是 RET 之后的 INT3。第 43 节内的指令在 +0x21D 读选择值，+0x226 读 case RVA，+0x22E 加上映像基址，+0x231 间接跳转。ASCII 0x45 至 0x78 共 52 个选择值均在 0 至 5 之间。6 个 RVA 指向的都是本节指令入口。证据中的 switch 字段列出各分支对应的字符、目标符号和地址。
- **异常路径与分离入口。** 第 45 节 +0 的 ACM_Print$catch$0 建立帧，+0x0D 的 __catch$ACM_Print$0 是其内部标签。第 96 节给出此 funclet 的范围及第 95 节的展开记录。第 88 节引用 __GSHandlerCheck_EH4 和第 90 节的 FH4 描述，第 92 节引用 handler 表，第 93 节将 catch 目标绑定到第 45 节。变参寄存器保存、格式化调用、catch 内的输出和刷新均已恢复。xos_dll.obj 第 27 节与 acm_dll.obj 第 18 节分别恢复 FindSymbol 的清理函数。两者均由 RDX 取得所在帧，从帧 +0x20 取指针，调用带 0x30 长度的 operator delete。
- **两个后备回调。** acm_dll.obj 第 25 节 ACMDUMMY 从进入函数时的 RSP+0x38 读取第 7 个参数指针，第 23 节 ACM13DUMMY 从 RSP+0x80 读取第 16 个参数指针。两者均向指针所指内存写入 8 字节的数值 4。第 43、41 节的取地址函数分别以重定位选用相应回调。安装附带 atdll.h 第 199 至 211 行的两个 C++ 回调类型将这两个位置命名为 iflag。第 102 行声明 ACM_Print 接收状态、格式串和可变参数。
- **初始化与虚表。** sput_dll_utils.obj 第 52 节 ATInitialize 遇空指针返回 0。若输入非空则先清除全局 problem handle；标签 2、3 从 +0x18 设置它。标签 1、2、3 从 +8、+0x10 设置消息及选项处理器，复制 32 字节描述并返回 1。其他标签返回 0。字段与同目录 atdll.h 的 ACMDLLInitializationData 对应。xos_dll.obj 第 187 节、acm_dll.obj 第 114 节保存 RTTI、析构、Initialize 和 FindSymbol 指针目标。装卸、缓存、引用管理、对象字段偏移及调用目标均可在逐成员汇编中复查。安装头文件 SHA-256 为 `c466ea49c17b527ddbfb208a8746a02b5a45f705c3303fbc51f14d8eb33e92e0`。

## 复核方法

工具为 Windows x64 GNU as、ar 与 objdump 2.39，Python 3.12.14 和 Capstone 5.0.7。交付的五份 Intel 语法 .s 提供可编辑的指令、分支、符号引用与数据。构建程序从汇编结果读取机器码和重定位，重建 COFF 节、符号、成员及索引，并从实际节内容计算 .chks64。JSON 保存编译器辅助字段与 CodeView 记录。改变布局时可相应修改展开槽、范围加数、COMDAT 校验和调试偏移。[微软 COFF 格式](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format) · [x64 异常处理和展开](https://learn.microsoft.com/en-us/cpp/build/exception-handling-x64) · [GNU 汇编编码选项](https://sourceware.org/binutils/docs/as/i386_002dMnemonics.html)

在项目根目录打开 PowerShell，将 `$src` 设为本说明所在目录，`$tmp` 设为已有临时目录，使用尚不存在的输出文件名。

```powershell
$python = (Resolve-Path -LiteralPath '.local-tools/research/venv/Scripts/python.exe').Path
$assembler = (Resolve-Path -LiteralPath '.local-tools/qt/Tools/mingw1310_64/bin/as.exe').Path
$original = 'C:/Program Files/AspenTech/AMSystem V15.0/Procedures/libatdll.lib'
$rebuilt = Join-Path $tmp 'rebuilt.lib'
& $python -B (Join-Path $src 'libatdll.lib.build.py') --as $assembler --temp $tmp --out $rebuilt
& $python -B (Join-Path $src 'libatdll.lib.verify.py') --original $original --rebuilt $rebuilt --audit (Join-Path $tmp 'audit.json')
```

独立核验程序分别读取两个库并进行结构和全字节比对。GNU ar 与 objdump 均识别出全部 5 个 AMD64 成员。另在临时源码中将 ACMDUMMY 写入值从 4 改为 7，回编后只改变 acm_dll.obj 第 25 节 +8 的操作数与第 144 节对应的 8 字节节指纹，其他四个成员完全一致。该实验产生的库 SHA-256 为 `fd81b1aef5a0fb4edcbd12eefe9ca83dc124dcf28f8e384ccc3c6a1bff296778`。

本轮验收覆盖该静态库所含的机器级实现、数据、链接结构和调试载荷。主聊天复核后负责 GitHub 发布，Windows 调用方实际装载和运行留到后续重建阶段。[交付指纹](libatdll.lib.fingerprints.sha256)