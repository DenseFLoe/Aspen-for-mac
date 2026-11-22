# DSWU_UDL01I

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，文件版本 41.0.0.609。原件 SHA-256 为 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。原件和旧汇编、伪 C 的固定来源见[原任务卡](../../../assignments/NATIVE-350.md)。旧汇编入口位于第 4475 行，旧伪 C 入口位于第 3148 行。

主体包含物料块进入与退出、相态查询、流股状态、计算或闪蒸、错误输出等调用路径。原码中的 73 个 CALL 全指向可定位目标，其中 70 处通过跳板绑定导入。三条模块内调用分别为 0x7a9a→0x9c40、0x889a→0x2640、0x9b5a→0x2320。原件 0x9327 从导入槽取得 PPEXEC_PPROY 地址，0x932e 读取八字节双精度，0x9332 保存到本件 RVA 0x22840。跨件证据见 import-data-evidence.json。两个尚在整件缺口表的内部目标依原 RVA 保留。

原 Windows AMD64 指令保存在[可编辑实现](DSWU_UDL01I.c)。C 声明用于生成裸函数符号，寄存器和栈参数按汇编实现传递。主体覆盖 [0x78b0, 0x9c35) 的 1530 条指令。使用 Zig 0.13.0 编译为 COFF，按原 RVA 应用 547 处相对重定位，9093 字节逐字节吻合。源码 SHA-256 为 `7f9d35e78f2769136734a1f375362253b112952fa4b180f8d8dd501d33c17c8b`，原指令范围 SHA-256 为 `d408cb51ed01143f1e92cd3782863db95cb108d22aa91cd4ce64ea1a198926ad`。[逐址证据](business-evidence.json) · [复验脚本](check-business.py)

本导出代码范围已核实。外部依赖按导入符号和 ABI 传递位置绑定；缺少原头文件的参数名称与上层数据类型仍待结合调用方核实。整件状态见[逐件说明](../zedstwu.dll.md)。
