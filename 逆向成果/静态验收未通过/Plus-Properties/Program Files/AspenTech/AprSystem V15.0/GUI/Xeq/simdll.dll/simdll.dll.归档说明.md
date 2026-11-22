# simdll.dll

**静态验收未通过。** 原台账状态为“暂存”。原名归档只针对 2 个按名称去重的原生函数。已读取符号包括 sub_109c0、submit_proprun；整文件覆盖尚待建立。

后续核对条件：先建立本 PE 的代码段、入口与函数边界表，再用 sub_109c0 的已存 RVA/指令交叉核对其余函数及数据引用。

本目录公开逐件说明。局部逆向正文仅在本地保存。

原件 SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。[原轮次记录](https://github.com/DenseFLoe/Aspen-for-mac/tree/main/inventories/reverse/20261119-01)

## 2026-11-22 第五轮复验

401 个导入跳板重新编译后，2,406 字节与原件吻合。全件 1,379 个入口中已核实 420 个，仍有 959 个入口及 247 处间接转移待核。50 个资源叶已回读。整件仍为静态验收未通过。[本轮裁定与复跑证据](https://github.com/DenseFLoe/Aspen-for-mac/blob/main/handoff/outbox/NATIVE-344/s5-decision.md)
