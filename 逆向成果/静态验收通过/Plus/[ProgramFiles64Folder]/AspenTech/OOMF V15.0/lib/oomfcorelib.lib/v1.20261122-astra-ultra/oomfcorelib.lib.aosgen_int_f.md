# oomfcorelib.lib.aosgen_int_f.s

原件为 Aspen Plus V15（OOMF V15.0）安装成员 `Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，117,484 字节，SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。MSI 未登记该文件的独立版本字段。

**已通过整件静态验收。** 此汇编文件恢复 `x64\Release\aosgen_int_f.obj` 的全部内容。文件打开和关闭使用原 Fortran 描述符及调用参数。全局初始化保留浮点无序分支和有符号整数比较，并通过对应导入指针写入。

成员大小 1,962 字节，原件及回编成员的 SHA-256 均为 `5f2c493bafbed30a44340b165ae5688e6a70293bb950339ca4d1149efdda8b34`。汇编源码的 SHA-256 为 `ec458784c54e8ac7d48658475b9e8f96409382323a0c065b31c888238090213f`。

| 函数 | 原 .text 起点 | 终点（不含） | 指令数 | 源码行 |
| --- | ---: | ---: | ---: | ---: |
| `GENSOLV_FOPEN` | 0x0 | 0xd6 | 44 | 33 |
| `GENSOLV_FCLOSE` | 0xd6 | 0x134 | 22 | 87 |
| `SET_GLOBAL_COMMONS` | 0x134 | 0x192 | 21 | 118 |

成员含 5 个节、20 条重定位，代码末尾有 2 个填充 NOP。原符号表、节标志、COMMON 声明、外部符号和链接器指令按本成员实际内容归档。

逐函数指纹、展开记录与节核对结果见 [静态证据](evidence/static-verification.json)。构建命令和 Windows 对照阶段的边界见 [整件说明](oomfcorelib.lib.md)。
