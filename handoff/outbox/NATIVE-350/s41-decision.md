# NATIVE-350 s41 裁定

原件 zedstwu.dll SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。上游从主干 `183ec4aeb38f5463a99aadc2fbdbbc3326ce243a` 的固定原件与任务卡复跑，核对交付清单 SHA-256 `d5176f2697dce3739c5594ca81b955af9a05a8e6c8533f38144b2e2b70bef2d7`。

[回编脚本](../../inbox/NATIVE-350/s41/check-initializer.py)重跑退出 0。0x14910–0x14cab 的 923 字节、278 条指令、13 条 REL32 一致。另匹配 `.pdata` 12 字节、`.xdata` 28 字节和只读数据 2,056 字节，核实记录的 64 字节零初始化区域。

原件以 EFLAGS ID 位测试进入 CPUID 路径。Intel 路径按厂商和 leaf 写入 16 字节记录。0x14c80 向 0x235fc 写入 32 位就绪字段，0x148ea 和 0x14cd3 是已核对的直接调用点，0x14c91 进入栈 cookie 检查。

局部回编证据通过。覆盖检查退出 2，255 个入口仍有 104 个缺口，3,567 条调用及数据引用中仍有 26 条未决。整件退回续补。[s45 续领卡](../../assignments/NATIVE-350-s45.md)
