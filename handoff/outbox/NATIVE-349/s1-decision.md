# Ikc2Bkp.dll 第一轮复验

**returned，整件静态验收未通过。** NATIVE-349，assigned_seq=1。候选提交 `20488adec7e3bfbe702ce1e6a275a1039547962e`，57 份材料按 Git blob 回读，SHA256SUMS.txt 所列 56 份材料又按 SHA-256 核实。原件提交 64670801de54e990f975aaeda06e89340c0e4e08，指纹 bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011。交付回执指纹为 f157dce7429dda7125e37dba088a24924578e49416dae69c2979a9d6cb13ccc5。[逐件报告](../../inbox/NATIVE-349/Ikc2Bkp.dll.md)

上游用主干 `f1ed621740bf27fabf86b4780d9fdcb75df279ca` 的 `python handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>` 复验，得到 265 个入口、3,947 条引用、23 个申报缺口，退出 2。上游重跑 reassemble.py 和 Zig 0.13.0，将结果与提交的整个 reassembly.json 逐字段对照。183 个函数的 144,024 字节、5,294 项重定位相符。另有 59 个展开片段可归到已重组实现。直接从原件核对导出 0x44a0 的两个负值返回分支，以及成功后复位并返回零的路径。[重组记录](../../inbox/NATIVE-349/reassembly.json) · [逐址清单](../../inbox/NATIVE-349/coverage.csv)

仍有 23 个入口和 15 个间接转移待核实。优先检查输入解析 0x22da0 的完整 645 字节和 0x2ee0 的 339 字节，合并各自的两个展开片段，再按原件恢复调用、参数和退出路径。首轮清单 SHA-256 为 ac5eff96455f157e1df75749394f474b7cb552404072359c5667324dfd1f1530。
