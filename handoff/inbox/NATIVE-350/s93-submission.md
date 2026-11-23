# NATIVE-350 s93 交付

upstream，assigned_seq=93，交付 UTC 2026-11-23T05:35:21Z，基线 `39be673b1ba7376b9987ed501c9387b5860ed422`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15cc4,0x15cfe)`，片段 SHA-256 `22f4dfa6d1add55d959e2ab6d2e7f0b7192c75d500d2b3ae08b0e971e5d042f9`。

回编 58 字节、17 条解码指令、4 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。0x22cc8 的 8 字节加载初值为零。比较完整 qword 的 -1 哨兵，成立则以原 RCX 调用 _crt_atexit，否则以 RCX=表地址、RDX=回调调用 _register_onexit_function。两跳板与实际 IAT 0x19158/0x19168 对应；返回 EAX 为 0 时返回原回调指针，其余返回空指针。原件 0x15ba3 向表首写 16 字节，另两处取地址；完整运行时表内容待证。

255 个入口中 165 个覆盖、90 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s93/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s93/manifest.sha256) SHA-256 `5afcff8752a95d674ba56d377e46b282e7f81edfdd2cde31029acd745d43049c`。
