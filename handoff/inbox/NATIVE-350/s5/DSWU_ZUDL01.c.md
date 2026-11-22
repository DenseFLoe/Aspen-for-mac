# DSWU_ZUDL01

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，文件版本 41.0.0.609。原件 SHA-256 为 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。原件和旧汇编、伪 C 的固定来源见[原任务卡](../../../assignments/NATIVE-350.md)。旧汇编入口位于第 7360 行，旧伪 C 入口位于第 5013 行。

实际解码的 37 个 CALL 全部经导入跳板进入 DMS_IRRCHK、DMS_ERRPRT、for_write_int_fmt 或 for_write_int_fmt_xmit。比较、条件跳转、整数和浮点输入/格式化实参均按原指令恢复，133 个 RIP 相对操作数逐址可查。

原 Windows AMD64 指令保存在[可编辑实现](DSWU_ZUDL01.c)。C 声明用于生成裸函数符号，寄存器和栈参数按汇编实现传递。主体覆盖 [0xbed0, 0xcbdd) 的 565 条指令。使用 Zig 0.13.0 编译为 COFF，按原 RVA 应用 197 处相对重定位，3341 字节逐字节吻合。源码 SHA-256 为 `dcb539c93a50d25cc543dbdfca728c220a763e754ea26582f3012fc797b7883d`，原指令范围 SHA-256 为 `205d24154fd82678c045d62d9a684b45535cf9d6dbf06fe2cfd6b8776f4f2d89`。[逐址证据](business-evidence.json) · [复验脚本](check-business.py)

本导出代码范围已核实。外部依赖按导入符号和 ABI 传递位置绑定；缺少原头文件的参数名称与上层数据类型仍待结合调用方核实。整件状态见[逐件说明](../zedstwu.dll.md)。
