# zedstwu.dll 第十七号续领

NATIVE-350，owner upstream，assigned_seq=17，自本轮 #13 ACK 起 24 小时。固定原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，来源见[初始卡](NATIVE-350.md)。第十三号候选 `c57d3a0349dff208bf2a4ef1bd32e9c03ac8a569` 及[复验](../outbox/NATIVE-350/s13-decision.md)可直接复用。

从 0x2640 的三条原件调用接续，0x2df5 指向 0xcc00，0x4c3d 与 0x4c4f 指向 0xccd0。两段先读取零初始化缓存槽 0x22d10、0x22d18，非零时转移至 RAX，零时进入 0xcc20、0xccf0。后两段实际分别在 0xcc9d、0xcd6a 写回缓存并跳到所选目标。原件异常目录限定范围如下。

| 范围 | 字节和指令 | 原字节 SHA-256 |
| --- | --- | --- |
| `[0xcc20,0xccae)` | 142 字节，42 条 | `d25c5f9a4ea3339b97f047574f61c736fd8cb0a78a3735349d8193e0ae6271a2` |
| `[0xccf0,0xcd7b)` | 139 字节，42 条 | `27bca968dd058c0cb373da3371931cd42eab602fba2189e301534e633b6d69dc` |

把两段直接调用入口和两段初始化器恢复为可编辑实现，逐指令核对缓存写入及所有可达候选，说明原件实际的选择条件。保留其余入口和间接转移的逐址记录。按[原生补证标准](../standards/native-coverage-upstream.v1.md)执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <固定原件>`，交 s17 双回执和固定候选。
