# Ikc2Bkp.dll 第九号提交

NATIVE-349，assigned_seq=9，owner upstream。[任务卡与固定来源](../../assignments/NATIVE-349-s9.md)。原件 SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`，第五号基线候选为 `bd51e24c0b9a7c87bea21e32bb8c955b31ce4a1e`。

两个 CRT 宿主各有 132 和 139 字节，覆盖 75 条指令及 25 处 COFF 重定位。两个退出表分别传给已核实的初始化导入，常规返回、调用后的后继和尾部字节均已比对。[恢复源码](code/verified-10.h) · [分支、寄存器和数据复核](s9/crt-evidence.json)

所有 187 个实现合计 145,279 字节及 5,347 处重定位。其中 185 个旧实现与四个先前已验证的展开入口保持相同结果。原 17 个入口缺口中两项已修复，其余 15 项仍列在覆盖表；3,947 条引用中有 15 处此前已申报的未决转移。整件依 [逐件说明](Ikc2Bkp.dll.md) 继续修复。

在本目录执行 `python -B reassemble.py <原件> <Zig 0.13.0>` 和 `python -B s9/check-crt.py <原件> <Zig 0.13.0> --output <输出 JSON>`，两者均以原件和实际代码为输入。在仓库根执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>`，得到 265 个入口、3,947 条引用、15 个入口缺口，退出 2。[本轮指纹](s9-manifest.sha256)
