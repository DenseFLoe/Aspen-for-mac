# oomfcorelib.lib.rtcfg_f.s

原件为 Aspen Plus V15（OOMF V15.0）安装成员 `Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，117,484 字节，SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。MSI 未登记该文件的独立版本字段。

**已通过整件静态验收。** 此汇编文件恢复 `x64\Release\rtcfg_f.obj` 的全部内容。迭代历史、变量与方程分析、敏感性计算。源码保留全部格式化输出调用、栈探测、工作区与 COMMON 引用。数据节中的格式包按 32 位字和带长度的文本字段表达。

成员大小 81,200 字节，原件及回编成员的 SHA-256 均为 `1ab7a0d026572454603dbff39ee30f970e8e343bbc0917ac99cdb5aa059d2620`。汇编源码的 SHA-256 为 `e023abfe950b4e7d2bbef44805db95425f7e735b438ecacfde27c781976bc99b`。

| 函数 | 原 .text 起点 | 终点（不含） | 指令数 | 源码行 |
| --- | ---: | ---: | ---: | ---: |
| `CFG_WRITE_ITERATION_HISTORY` | 0x0 | 0x51e | 244 | 317 |
| `CFG_ANALYZE_VAR` | 0x51e | 0x2e24 | 1,947 | 576 |
| `CFG_PRINT_ANALYZE_VAR` | 0x2e24 | 0x51fa | 1,683 | 2624 |
| `CFG_SENSITIVITY` | 0x51fa | 0xa112 | 3,696 | 4382 |
| `CFG_ANALYZE_EQNS` | 0xa112 | 0xcaf4 | 1,977 | 8235 |

成员含 7 个节、1,117 条重定位，代码末尾有 0 个填充 NOP。原符号表、节标志、COMMON 声明、外部符号和链接器指令按本成员实际内容归档。

逐函数指纹、展开记录与节核对结果见 [静态证据](evidence/static-verification.json)。构建命令和 Windows 对照阶段的边界见 [整件说明](oomfcorelib.lib.md)。
