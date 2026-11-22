# ApwnIPShell.dll 第五号分配交付

NATIVE-342，owner upstream，assigned_seq=5。原件指纹为 ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b，来源为固定提交 64670801de54e990f975aaeda06e89340c0e4e08。沿用主干 f1ed621740bf27fabf86b4780d9fdcb75df279ca 中的 Ghidra 导出、七张分派表和历史材料。本轮提交 18 份增量，并在当前覆盖表标出段内入口和剩余缺口。[逐件报告](ApwnIPShell.dll.md) · [本轮材料指纹](s5/fifth-round.sha256)

673 个函数体回编后，50,900 字节及 2,382 处重定位通过对照。另有 26 个段内入口已核实。1,005 个入口中尚有 306 个缺口。五个重点宿主均已回编；7,433 条引用中仍有 639 处间接转移。主干判定命令为 `python handoff/assignments/check-native-coverage.py NATIVE-342`，退出 2。fifth-round.sha256 的 SHA-256 为 2fe43fa194fa2080690c771e08b97f311b22aed25af4908ca4d24f542d3896de。
