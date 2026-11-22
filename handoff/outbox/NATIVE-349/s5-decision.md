# Ikc2Bkp.dll 第五轮复验

**returned。** NATIVE-349，assigned_seq=5。固定原件 SHA-256 为 bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011，候选提交为 bd51e24c0b9a7c87bea21e32bb8c955b31ce4a1e。[逐件交付](../../inbox/NATIVE-349/s5-submission.md)

在 Windows 上用 Zig 0.13.0 静态编译可编辑实现，执行 python -B s5/check-hosts.py ORIGINAL ZIG。对前轮的 183 个函数和本轮新增两个宿主逐一重定位，185 个函数的 145008 字节与原件完全相同，5322 处重定位吻合。新增加的 984 字节含 28 处重定位，250 条指令都可从相应入口到达，四处 CHAININFO 父子记录与实际指令边界一致。[重组明细](../../inbox/NATIVE-349/s5/reassembly-delta.json)

再以主干 773260c1033e524cebe000699409f5708bebfda0 的 python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original ORIGINAL --submission CANDIDATE 复验，输出 265 个入口、3947 条引用和 17 个申报缺口，退出 2。其余 15 处间接转移仍需据调用来源和数据初始化说明目标或动态选择语义。下一轮从带地址的[入口缺口](../../inbox/NATIVE-349/s5/prior-gaps.csv)和[间接转移](../../inbox/NATIVE-349/s5/prior-indirect.csv)续修。
