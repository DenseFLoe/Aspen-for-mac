# DSWU_IUDL01

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，文件版本 41.0.0.609。原件 SHA-256 为 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。原件和旧汇编、伪 C 的固定来源见[原任务卡](../../../assignments/NATIVE-350.md)。旧汇编入口位于第 946 行，旧伪 C 入口位于第 507 行。

例程按原次序写入 63 个互异的八字节槽，再直接返回。全部槽位于 [0x241e0, 0x243d8)，映射初值均为零。保存每个指令的原址、目标及常量，含对 0x24378 起一段的提前初始化。实际写入顺序和数值见 JSON 的 ordered_u64_stores。

原 Windows AMD64 指令保存在[可编辑实现](DSWU_IUDL01.c)。C 声明用于生成裸函数符号，寄存器和栈参数按汇编实现传递。主体覆盖 [0x2380, 0x2636) 的 64 条指令。使用 Zig 0.13.0 编译为 COFF，按原 RVA 应用 63 处相对重定位，694 字节逐字节吻合。源码 SHA-256 为 `dbead5b2e08ce1132bd5753ffd744bbccf33f67c3d2bf66818e994ae9b20f592`，原指令范围 SHA-256 为 `c5e669c6e2ead37bd5e7719f0a0df28f6e5ee32b604097db628ea40108cae45a`。[逐址证据](business-evidence.json) · [复验脚本](check-business.py)

本导出代码范围已核实。外部依赖按导入符号和 ABI 传递位置绑定；缺少原头文件的参数名称与上层数据类型仍待结合调用方核实。整件状态见[逐件说明](../zedstwu.dll.md)。
