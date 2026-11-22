# Simdll.dll 导入跳板源码

本件为 Windows AMD64、版本 41.0.0.614。原件 SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。该源码覆盖第五号任务固定的 401 个入口。每个入口的完整函数体都是一条经 RIP 相对导入槽的间接尾跳转。[本轮清单](../../../outbox/NATIVE-344/s5-import-thunks.csv)

`import-thunks.c` 使用 GNU 风格模块级汇编。每一行指定原件入口 RVA 及导入槽 RVA，并注出原件导入表中的 DLL 与名称或序号。宏生成对应入口标签和一条 AMD64 指令。调用方留下的返回地址、参数寄存器和栈直接传给导入目标。编译为 Windows AMD64 COFF 时，每个槽产生一个待解析的外部符号。此处验证范围止于 Simdll 转移控制权的位置。依赖侧各目标的参数类型和实现须由对应模块确认。[可编辑源码](import-thunks.c) · [原件指令](import-thunks.asm)

在有 pefile 2024.8.26、Zig 0.13.0 的环境执行 `python s5/verify.py <Simdll.dll> <zig>`。脚本编译本目录的源码，从实际 COFF 读取符号表和全部重定位，以原件映像入口与 IAT 槽逐一绑定。401 个入口的 2,406 字节全部相等。按入口 RVA 递增连接字节，原件与重组结果的 SHA-256 均为 `fb5d3f57b9e2d2aa34391594da41b4562ae0d7786e64ee8e87530ee73313b714`。输出还核对两个索引、实际资源内容和图标组关系。[验证程序](verify.py) · [本轮结果](rebuild.json)
