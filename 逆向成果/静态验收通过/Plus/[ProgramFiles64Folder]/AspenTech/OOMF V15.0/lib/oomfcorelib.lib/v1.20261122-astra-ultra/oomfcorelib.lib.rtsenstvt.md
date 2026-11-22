# oomfcorelib.lib.rtsenstvt.s

原件为 Aspen Plus V15（OOMF V15.0）安装成员 `Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，117,484 字节，SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。MSI 未登记该文件的独立版本字段。

**已通过整件静态验收。** 此汇编文件恢复 `x64\Release\rtsenstvt.obj` 的全部内容。敏感性计算与诊断输出，保留原间接回调、BSS 工作指针、Fortran 输出及停止调用。

成员大小 8,656 字节，原件及回编成员的 SHA-256 均为 `60f5c152ad84e8bc2f58fefbb59211c333f4e5b4121b2f00a9f8fe7fdd455ddc`。汇编源码的 SHA-256 为 `ecc5bd4ad92ffa53b5c14aa6d7441cb8b03d393890978de39685b2fa694e0a04`。

| 函数 | 原 .text 起点 | 终点（不含） | 指令数 | 源码行 |
| --- | ---: | ---: | ---: | ---: |
| `RTSENSITIVITY` | 0x0 | 0x1266 | 935 | 52 |
| `CONTACT_ME` | 0x1266 | 0x162f | 166 | 1039 |

成员含 6 个节、77 条重定位，代码末尾有 1 个填充 NOP。原符号表、节标志、COMMON 声明、外部符号和链接器指令按本成员实际内容归档。

逐函数指纹、展开记录与节核对结果见 [静态证据](evidence/static-verification.json)。构建命令和 Windows 对照阶段的边界见 [整件说明](oomfcorelib.lib.md)。
