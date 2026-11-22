# oomfcorelib.lib.rtanalyzevar.s

原件为 Aspen Plus V15（OOMF V15.0）安装成员 `Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，117,484 字节，SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。MSI 未登记该文件的独立版本字段。

**已通过整件静态验收。** 此汇编文件恢复 `x64\Release\rtanalyzevar.obj` 的全部内容。变量分类、可观测性和冗余分析，含稀疏矩阵行列提取和向量压缩。传址、索引宽度、运算顺序和重复坐标的累加均由原指令保留。

成员大小 11,993 字节，原件及回编成员的 SHA-256 均为 `b0728bbb057014371d3a00d041b976d7df59bbdad868c3afbd7406aafe47765d`。汇编源码的 SHA-256 为 `143d5a37d9f24373e3a94cc6e7fb026c99d397b14842552e65e1b1bc7b10dea4`。

| 函数 | 原 .text 起点 | 终点（不含） | 指令数 | 源码行 |
| --- | ---: | ---: | ---: | ---: |
| `CLASSIFY_VARIABLES` | 0x0 | 0xdc9 | 642 | 30 |
| `SPLIT_THINGS` | 0xdc9 | 0x110c | 191 | 702 |
| `OBSERVABILITY` | 0x110c | 0x1b9c | 530 | 908 |
| `REDUNDANCY` | 0x1b9c | 0x2093 | 251 | 1467 |
| `Z_BASIS` | 0x2093 | 0x2392 | 155 | 1738 |
| `IJ_PRODUCT` | 0x2392 | 0x248f | 64 | 1907 |
| `FIND_COLUMN` | 0x248f | 0x25c4 | 80 | 1982 |
| `FIND_ROW` | 0x25c4 | 0x26f9 | 80 | 2075 |
| `RTPACKVECTOR` | 0x26f9 | 0x2803 | 68 | 2168 |

成员含 5 个节、40 条重定位，代码末尾有 1 个填充 NOP。原符号表、节标志、COMMON 声明、外部符号和链接器指令按本成员实际内容归档。

逐函数指纹、展开记录与节核对结果见 [静态证据](evidence/static-verification.json)。构建命令和 Windows 对照阶段的边界见 [整件说明](oomfcorelib.lib.md)。
