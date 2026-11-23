# NATIVE-350 s77 交付

upstream，assigned_seq=77，交付 UTC 2026-11-23T03:04:53Z，基线 `0efdc367513b4850841dff1d13ebd78cb5cea67a`。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x186f3,0x1870b)`，片段 SHA-256 `515c04e0ba3bb82e249e1f52765ba9c74cf63305116d4e5c2393eb92ba558686`。

24 字节逐字节吻合。9 条可执行指令与 0x1870a 的单字节 INT3，代码无重定位，.pdata 12 字节与 0x1c1cc 的 .xdata 8 字节吻合。0x186f8 经 RCX 取异常记录指针，0x186fd 比较记录开头的 DWORD 与 0xc0000005。ECX 先清零，SETZ 写 CL，EAX 在相等时返回 1，其余返回 0。0x15bdc 宿主的 0x1c1bc 范围记录指向该过滤器，0x15c6d 为接续地址，展开处理经 0x18066 绑定 VCRUNTIME140.dll!__C_specific_handler。

255 个入口中 161 个有覆盖、94 个缺口，3,568 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s77/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、capstone 5.0.6, pefile 2024.8.26, iced-x86 1.21.0。覆盖 v1 返回 2。成对用例的局部回编返回 0 → 1。[清单](s77/manifest.sha256) SHA-256 `987ca7f99e977b17f4244f6a0a0af1ae6dc1b7b9daeed434faa0fb8151976116`。
