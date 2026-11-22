# COFF-BFDYLD-CORN 重组证据提交

owner upstream，assigned_seq=1，原件 SHA-256 `3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a`。此件已于 2026-11-21 通过原件级静态验收。[同包 Fortran 与既有逐件证据](https://github.com/DenseFLoe/Aspen-for-mac/blob/bb7d1c50e2dc60eeefbadd9097a90d7762160df2/reverse/01-completed/20261121-retry85/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/Examples/Biofuel%20and%20Biochemicals/Bioethanol%20from%20Corn%20Stover/Lignocellulosic%20biomass%20to%20ethanol.apwz!/BFDYLD.obj.md)

本轮验证原工作未执行的汇编重组。两个来源的原件仅 COFF 头偏移 4、5 的时间戳字节不同。双方各自的原始 Fortran 均为 5,926 字节，SHA-256 `9c4b6d277af6643d2f199656e6aece7e478290368613b0bd9b5002f799b10fb1`。归档源码继续沿用既有文件。新增的[汇编重组输入](../COFF-BFDYLD/BFDYLD.s)只存一份，由两次独立比较共用。

从仓库根执行 `python -B handoff/assignments/check-coff-bfdyld.py COFF-BFDYLD-CORN`。Python 3.9+，PATH 中安装 clang 或 zig，也可加 `--assembler`、`--original` 和 `--fortran` 指定本机文件。附加 `--details` 可单独重算各节、主符号及辅助数据、逐条重定位与直接调用。现场使用 iced-x86 1.21.0 解码原件，Zig 0.13.0 中的 Clang 18.1.6 以 AMD64 Windows GNU 目标重组，两个来源各自下载、验指纹、汇编和比对均返回 0。[本件记录](result.json)

.text 独有过程为 BFDYLD，入口偏移 0。函数主体及分支块覆盖前 1,780 字节，末尾 12 字节为两条对齐 NOP。全部 375 条指令（含 NOP）均有原节偏移。21 条同义寄存器指令按原 opcode 用 .byte 保存方向编码，注释给出对应助记符和寄存器。其余指令用可编辑助记符。13 条直接外部调用分别为 __chkstk 两处、DMS_IFCMNC 五处、DMS_IRRCHK 两处、for_write_int_fmt 两处、DMS_ERRPRT 两处。五个属性名及数值常量在 .rdata，格式包与 IPROG 在 .data，.bss 保留 416 字节零初始化空间。原有 Fortran 说明给出参数、调用、逻辑及运行库来源。

上游从固定原件重读 7 节、44 个主符号和 7 个辅助条目，得到 116 个重定位（.text 59、.xdata 27、.pdata 30）。重组后七节的大小、标志、全部存储字节（含加数）逐节相同，全部重定位的节内偏移、类型及符号身份相同。44 个主符号的名称、定义节或外部状态、值、类型、存储类别和附属项数相同；10 个展开范围均由 .pdata 和 .xdata 保持。COFF 中节和符号可重新编号，整文件 SHA-256 仅用于固定原件身份。原始 Fortran 的编译器版本、精确参数、链接环境及 Windows 行为仍沿用既有验收说明的待验证范围。
