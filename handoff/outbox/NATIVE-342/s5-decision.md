# ApwnIPShell.dll 第五轮复验

**returned，整件静态验收未通过。** NATIVE-342，assigned_seq=5。候选提交 `20488adec7e3bfbe702ce1e6a275a1039547962e`，18 份增量按 Git blob 回读。第 5 轮沿用的 Ghidra 源码和地址映射已从先前主干合入本候选。原件提交 64670801de54e990f975aaeda06e89340c0e4e08，SHA-256 为 ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b。交付回执指纹为 178ae7d3b95ce34021d1e8a510fdb80edeea06d7adf9d86052ad288603c72000。[逐件报告](../../inbox/NATIVE-342/ApwnIPShell.dll.md)

上游独立运行主干 `f1ed621740bf27fabf86b4780d9fdcb75df279ca` 的 `python handoff/assignments/check-native-coverage.py NATIVE-342 --original <原件>`，得到 1,005 个入口、7,433 条引用、306 个申报缺口，退出 2。用 Zig 0.13.0 重新执行 s5/reassemble.py，将整份结果与候选 reassembly.json 按字段对照。673 段的 50,900 字节及 2,382 项重定位全部相符；26 个附属于已重组函数的入口另有段内证据。五个重点宿主及其中的七张跳转表均已覆盖。首轮 801 个缺口解决了 496 个，新发现 192 个入口中核实了 191 个。[重组记录](../../inbox/NATIVE-342/s5/reassembly.json) · [第五轮指纹](../../inbox/NATIVE-342/s5/fifth-round.sha256)

尚有 81 个段内入口和 225 个分析器入口缺少足够实现证据，639 个间接转移的实际目标待核实。修订从 0x11f0、0x1570、0x15ab 和 0x15f6 的范围、共享代码及指令边界开始。再将五个重点宿主的间接调用与接收对象和数据对应，逐址更新覆盖后重跑同一判定器。第五轮清单 SHA-256 为 2fe43fa194fa2080690c771e08b97f311b22aed25af4908ca4d24f542d3896de。
