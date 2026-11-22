# DSWU_EUDL01

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，文件版本 41.0.0.609。原件 SHA-256 为 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。原件和旧汇编、伪 C 的固定来源见[原任务卡](../../../assignments/NATIVE-350.md)。旧汇编入口位于第 924 行，旧伪 C 入口位于第 496 行。

RCX 指向 64 位状态值。以无符号比较判断“状态值加 1099”是否超过 98。落在所选区间时，将“状态值加 1000”的栈内地址传给 UU_EOERR。另一分支调用 UU_STAT01，保留原 RCX，将原 R9、RDX、R8 按顺序置于第五至第七个参数位置，第二至第四个参数分别指向 RVA 0x1e440、0x1e3a0、0x19698。两条路径都保留被调方返回的 RAX。

原 Windows AMD64 指令保存在[可编辑实现](DSWU_EUDL01.c)。C 声明用于生成裸函数符号，寄存器和栈参数按汇编实现传递。主体覆盖 [0x2320, 0x237a) 的 20 条指令。使用 Zig 0.13.0 编译为 COFF，按原 RVA 应用 5 处相对重定位，90 字节逐字节吻合。源码 SHA-256 为 `3ab00dd50e03a0b7ad7305016c39f0b4f15894be5588d2fc2f7993584b0b9faf`，原指令范围 SHA-256 为 `53ee5088f5a9489940713b033191aca72b2430a3150ffca24df43fd99016d4e3`。[逐址证据](business-evidence.json) · [复验脚本](check-business.py)

本导出代码范围已核实。外部依赖按导入符号和 ABI 传递位置绑定；缺少原头文件的参数名称与上层数据类型仍待结合调用方核实。整件状态见[逐件说明](../zedstwu.dll.md)。
