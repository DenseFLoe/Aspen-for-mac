# zedstwu.dll 第九号提交

NATIVE-350，assigned_seq=9，owner upstream。固定原件是 Aspen Plus V15.0 Engine/Xeq 的 41.0.0.609 版 Windows AMD64 DLL，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。两处宿主入口均实现并通过函数级指令及引用静态比对。 [任务卡](../../assignments/NATIVE-350-s9.md) · [本轮文件指纹](s9-manifest.sha256)

| DSWU_UDL01I 调用 | 宿主半开区间 | 指令 | 匹配字节 | COFF REL32 | 导入调用 | RIP 数据引用 |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| 0x7a9a | [0x9c40, 0xb97a) | 1,140 | 7,482 | 298 | 81 | 215 |
| 0x889a | [0x2640, 0x78a6) | 3,461 | 21,094 | 1,085 | 189 | 893 |

Ghidra 12.2 交叉核实业务流程，Capstone 5.0.6 与 iced-x86 1.21.0 逐址核对原件的指令长度、分支目标、RIP 操作数和重定位字段。Zig 0.13.0 重新编译包含 AMD64 内联汇编的 C 文件。根据原件符号地址应用 COFF 重定位后，28,576 字节均吻合。源码使用可编辑指令、分支标签和具名数据及导入符号。0x2640 的 17 处对齐 NOP 使用固定宽度编码。 [0x9c40 实现](s9/sub_180009C40.c) · [0x2640 实现](s9/sub_180002640.c) · [编译、重定位与散列记录](s9/host-evidence.json)

整件仍待修复。上一轮的 121 个缺口中，0x9c40 和 0x2640 两行更新为已核实。入口总数 255，已核 136，缺口 119。原 44 处未决间接转移的记录继续保留，均位于两个宿主区间之外。其中 0x2640 的直接调用到达 0xcc00 和 0xccd0，两处各有一个独立待绑定的间接跳转。0x9c40 的两个内部调用目标 0xb980 和 0x1000 仍有实现缺口。第一轮的复制路径和版本资源与第五号的四个业务导出继续使用基线成果。 [覆盖表](coverage.csv) · [调用和未决引用](calls.csv) · [跨函数直接转移](internal-transfers.csv)

函数对象按原地址绑定以验证指令与引用。被引用数据对象、被调例程和 Windows 展开信息仍需要各自的恢复与整件绑定。完整 DLL 的链接、Windows 对照和产品行为属于后续验收。

从仓库根复算任务卡输入和覆盖检查，从本件目录运行宿主重组。使用 Python 3.9+，安装 pefile 2024.8.26、Capstone 5.0.6、iced-x86 1.21.0，并传入 Zig 0.13.0 的路径。

```text
python -B handoff/outbox/NATIVE-350/check-s9-input.py <zedstwu.dll>
python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <zedstwu.dll>
python -B s9/check-hosts.py <zedstwu.dll> <zig> --output host-evidence.json
```

覆盖检查按当前登记输出 255 行、3,567 条引用、119 个已申报缺口，退出 2。宿主重组独立复跑退出 0。
