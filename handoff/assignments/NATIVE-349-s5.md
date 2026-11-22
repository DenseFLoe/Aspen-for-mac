# NATIVE-349 第五号事件续领

owner 为 upstream，assigned_seq=5，时限自本轮 #13 ACK 起 24 小时。固定输入为 64670801de54e990f975aaeda06e89340c0e4e08 的 issue-materials/349/Ikc2Bkp.dll，SHA-256 为 bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011。已有交付固定在 `20488adec7e3bfbe702ce1e6a275a1039547962e`。[原件及产品路径](NATIVE-349.md) · [第一轮裁定](../outbox/NATIVE-349/s1-decision.md)

上游用 Capstone 5.0.6 从两个入口的首指令跟踪直接分支、跳转及顺序后继，调用按返回后继续，终点采用固定原件异常表。0x22da0 至 0x23025 的 154 条指令和 0x2ee0 至 0x3033 的 96 条指令均可由各自入口到达。前者包含以 0x22df6、0x2300a 开始的两个展开片段，后者包含 0x2f05、0x302b。0x22dd2 的调用指令为 ff15f0330000，经导入槽 0x261c8 绑定 fopen，0x26660 为以 NUL 结尾的读模式字符串。这组原件证据支持合并相应片段作完整函数静态对照。[原件异常边界](../inbox/NATIVE-349/runtime-ranges.csv) · [首轮函数范围](../inbox/NATIVE-349/body-ranges.csv)

先为这两处补齐可编辑实现、指令边界、控制流和 COFF 重组证据，保留原指令编码与重定位，核对错误返回及重要数据。按第一轮清单列出全部 23 个缺口和 15 处间接转移的本轮去向，已核实的 183 个回编实现和 59 个段内入口须可复查。适用[上游原生覆盖标准](../standards/native-coverage-upstream.v1.md)，从仓库根运行 `python handoff/assignments/check-native-coverage.py NATIVE-349`。可用 `--original <原件>` 指定已核实的本地副本。另复跑本件 reassemble.py，在逐件报告记录字节与重定位差异。

交付目录为 handoff/inbox/NATIVE-349/。使用 s5-started.md、s5-submission.md 并保留首轮证据。整件继续依照静态验收要求另行裁定。
