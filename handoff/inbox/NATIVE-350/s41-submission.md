# zedstwu.dll s41 交付

NATIVE-350，owner upstream，assigned_seq=41。交付 UTC 2026-11-22T22:06:54Z。原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，基线 `183ec4aeb38f5463a99aadc2fbdbbc3326ce243a`。

恢复 0x14910–0x14cab 的 923 字节与 278 条指令，13 处 REL32 与原件一致。.pdata 的 12 字节和 .xdata 的 28 字节均匹配。独立回编还核对 2,056 字节只读 Vendor/描述符数据与 64 字节零初始化存储。原件以 EFLAGS ID 位测试进入 CPUID 路径，Intel 路径比较 EBX/EDX/ECX，按 leaf 4 或 leaf 2 的条件写入 16 字节记录。0x14c80 写入 0x235fc 的 32 位就绪字段，0x148ea 与 0x14cd3 是已核对的直调入口，0x14c91 直调 0x18110 检查栈 cookie。

覆盖 255 个入口中的 151 个，尚余 104 个入口缺口和 26 条未决引用。整件未通过静态验收。

使用 Zig 0.13.0、Capstone 5.0.7、pefile 2024.8.26 与 iced-x86 1.21.0。从仓库根运行 `python -B handoff/inbox/NATIVE-350/s41/check-initializer.py ORIGINAL ZIG --evidence-dir OUTPUT`。[覆盖复跑](s41/coverage-check.txt) · [成果指纹](s41/manifest.sha256) `d5176f2697dce3739c5594ca81b955af9a05a8e6c8533f38144b2e2b70bef2d7`。
