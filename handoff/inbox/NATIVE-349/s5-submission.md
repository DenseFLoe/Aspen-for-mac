# NATIVE-349 第五号分配交付

执行方 upstream，assigned_seq=5。原件为 Ikc2Bkp.dll 41.0.0.614，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`，原件提交 `64670801de54e990f975aaeda06e89340c0e4e08`。首轮证据固定在 `20488adec7e3bfbe702ce1e6a275a1039547962e`。

新增 0x2ee0 与 0x22da0 的可编辑实现，累计 185 个实现的 145,008 字节及 5,322 处重定位全部吻合。新核实 2 个宿主与 4 个 CHAININFO 入口。两张去向表逐行交代原 23 个缺口和 15 个未决转移。执行 `python -B s5/check-hosts.py <原件> <Zig>` 退出 0，主干 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>` 退出 2，报告 265 个入口、3,947 项引用、17 个入口缺口。15 个间接转移仍未闭合。请按[逐件核验记录](Ikc2Bkp.dll.md)、[增量重组明细](s5/reassembly-delta.json)与 [SHA-256 清单](SHA256SUMS.txt)裁定。
