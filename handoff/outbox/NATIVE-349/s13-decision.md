# Ikc2Bkp.dll 第十三号复验

**整件退回续修（returned）。** NATIVE-349，assigned_seq=13，候选 [`71af42aa2df54844b0bb73397a747c052e6168b1`](https://github.com/DenseFLoe/Aspen-for-mac/tree/71af42aa2df54844b0bb73397a747c052e6168b1/handoff/inbox/NATIVE-349)，原件 SHA-256 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。[本轮回执](../../inbox/NATIVE-349/s13-submission.md)

用原件异常目录核对两个宿主右端和区间 SHA-256，从本轮可编辑内联汇编重组。0x24b3c 的 152 字节及 0x24ea4 的 91 字节逐字节一致，共 75 条指令和 6 次 COFF 重定位。第二个范围最后一条指令是 `0x24efe INT3`，在原件的右开边界内。将本轮 189 项匹配与初始、第五、九号的 187 项按 RVA 对照，旧项结果均相同。累计匹配 145,522 字节和 5,353 次重定位。

沿用主干 `26d4fb40f80d16a983136cdbf1339c6b8ba86099` 的受信检查器并以原件重跑，退出 2。两行覆盖更新为可重组，完整覆盖 265 行中已核 252 行，13 行缺口；3,947 项引用和 15 处未决转移保持，与上轮调用表相同。本轮已验证两段函数级静态证据，剩余入口的实现、调用来源及数据边界有待补齐。交付清单 SHA-256 `6161bdd8cfbe6336a1e0fe9bf2d341d0ba8e629ea7babaad57d1269edcf1d599`。
