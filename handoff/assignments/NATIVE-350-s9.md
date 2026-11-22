# zedstwu.dll 第九号续领

NATIVE-350，owner upstream，assigned_seq=9，时限自本轮 #13 ACK 起 24 小时。输入见[固定原件及原始反汇编、C 文件的路径](NATIVE-350.md)：原件提交 `ad53650f6071f83b133ede7bf847bc5096cd3b56`，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。以第五号候选 `a36f877783294ac56a138619ef162dd3ed52db68` 的可编辑实现和逐址清单为基线。[第五号裁定](../outbox/NATIVE-350/s5-decision.md)

复查已核实的 DSWU_UDL01I 对两个待核入口的调用。RVA 0x7a9a 指向 0x9c40，该宿主范围 7,482 字节，含 1,140 条指令，可经 81 处调用绑定已知导入。RVA 0x889a 指向 0x2640，该宿主范围 21,094 字节、3,461 条指令，可经 189 处调用绑定已知导入。从两者的业务分支、调用和数据关系恢复可编辑实现，与原件逐字节复核。用 `python -B handoff/outbox/NATIVE-350/check-s9-input.py <固定原件>` 复算[两个区间的摘要和首批导入](../outbox/NATIVE-350/s9-input.json)。

按[上游原生覆盖标准](../standards/native-coverage-upstream.v1.md)，在 `handoff/inbox/NATIVE-350/` 提交 `s9-started.md` 和 `s9-submission.md`，保留上一轮四个已验证导出、首轮资源与复制路径，列明当前 121 个入口缺口和 44 处未决引用的去向。独立运行 `python handoff/assignments/check-native-coverage.py NATIVE-350 --original <固定原件>`，记录编译命令、字节、指纹及未决项。
