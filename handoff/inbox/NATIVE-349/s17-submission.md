# Ikc2Bkp.dll 第十七号提交

NATIVE-349，owner upstream，assigned_seq=17。原件 Ikc2Bkp.dll 41.0.0.614，SHA-256 bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011。输入提交、原路径及版本见[同名说明](Ikc2Bkp.dll.md)。11 个新增范围从原件异常目录核实，557 字节、150 条指令、32 处重定位逐字节相符。此前 189 个范围结果逐项保持，共 200 个范围、146,079 字节、5,385 处重定位。

0x24f00 和 0x24f3c 的两个边界分别是同一个 RVA 0x2a600 和 0x2a610，第一次无符号小于比较为假，两个循环从各自入口均绕过间接调用。PE Load Config 的 Guard CF 分派槽 0x26268 在磁盘指向 0x25560 的 JMP RAX。0x25580 转到同一分派槽。0x249f8 的 RAX 由调用方 R9 经 RDI 提供。0x26280 在原件只读 .rdata 中为零，0x34980 在可写 .data 的零填充区，两个回调槽的最终目标仍需生产者或运行态证据。原有 15 个未决记录继续保留。

从本件目录运行 python -B reassemble.py <原件> <Zig 0.13.0> 及 python -B s17/check-dispatch.py <原件>。从仓库根运行 python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>，输出 265 个覆盖行、265 个分析器入口、3947 条引用、2 个入口缺口，退出 2。[转移及初始槽值](s17/dispatch.json)
