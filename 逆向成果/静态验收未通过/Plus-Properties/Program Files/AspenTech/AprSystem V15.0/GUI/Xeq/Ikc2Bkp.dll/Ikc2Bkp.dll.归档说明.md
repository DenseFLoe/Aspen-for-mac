# Ikc2Bkp.dll

**静态验收未通过。** 原台账状态为“暂存”。原名归档只针对 1 个按名称去重的原生函数。已读取符号包括 Ikc2Bkp；整文件覆盖尚待建立。

后续核对条件：先建立本 PE 的代码段、入口与函数边界表，再用 Ikc2Bkp 的已存 RVA/指令交叉核对其余函数及数据引用。

本目录公开逐件说明。局部逆向正文仅在本地保存。

原件 SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。[原轮次记录](https://github.com/DenseFLoe/Aspen-for-mac/tree/main/inventories/reverse/20261119-01)

## 2026-11-22 第九号复验

本轮恢复的两个运行库宿主共 271 字节，25 处重定位后与原件吻合。265 个入口现已核实 250 个，另有 15 个入口和 15 处间接转移待补证，整件继续留在未通过目录。[逐件裁定及三个轮次的实物证据](https://github.com/DenseFLoe/Aspen-for-mac/blob/main/handoff/outbox/NATIVE-349/s9-decision.md)
