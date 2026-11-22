# oomfcorelib.lib.rtanalyzeqn.s

原件为 Aspen Plus V15（OOMF V15.0）安装成员 `Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，117,484 字节，SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。MSI 未登记该文件的独立版本字段。

**已通过整件静态验收。** 此汇编文件恢复 `x64\Release\rtanalyzeqn.obj` 的全部内容。方程分析和行列处理，含原间接调用、各自的行列提取入口及浮点常量。

成员大小 6,886 字节，原件及回编成员的 SHA-256 均为 `ade13cf4f192265002b9412a78e70921aec7dbd0678cf9b9024793574bb7ec60`。汇编源码的 SHA-256 为 `647ec2cb641318c8895f342b92d4da149d58a0a99c972d528ac1f2c931d2524f`。

| 函数 | 原 .text 起点 | 终点（不含） | 指令数 | 源码行 |
| --- | ---: | ---: | ---: | ---: |
| `RTANALYZEQN` | 0x0 | 0x93e | 464 | 24 |
| `RTANALYZEQN_ROWS_COLS` | 0x93e | 0x13b9 | 520 | 506 |
| `RT_FIND_COLUMN` | 0x13b9 | 0x14ee | 80 | 1064 |
| `RT_FIND_ROW` | 0x14ee | 0x1623 | 80 | 1157 |

成员含 5 个节、16 条重定位，代码末尾有 1 个填充 NOP。原符号表、节标志、COMMON 声明、外部符号和链接器指令按本成员实际内容归档。

逐函数指纹、展开记录与节核对结果见 [静态证据](evidence/static-verification.json)。构建命令和 Windows 对照阶段的边界见 [整件说明](oomfcorelib.lib.md)。
