# NATIVE-350 s113 交付

upstream，assigned_seq=113，交付 UTC 2026-11-23T10:09:28Z，基线 `19f94421ea3b724df2b27f65f71832db0259f34d`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15f40,0x15f9b)`，片段 SHA-256 `8585200104557f7b6cb9f862521c227b0d4f37278a44eecde7e5ad32bc5dd2e9`。

回编 91 字节、27 条解码指令、3 处 REL32、12 字节 .pdata、12 字节 .xdata 均匹配。读取 EXCEPTION_POINTERS 中的记录指针。代码为 0xe06d7363、参数数为 4，且第一个参数在 0x19930520–0x19930522 或为 0x1994000 时进入 C++ 终止路径。0x18072 与 0x18078 提供异常记录和上下文的线程局部槽地址，写入后转 0x180cc。其他分支返回 EAX=0，并恢复 RBX、RDI。

255 个入口中 170 个覆盖、85 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s113/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s113/manifest.sha256) SHA-256 `3baf5cf9aa5a1fcdd67b2be056df2747ec30e41b430bd0fdffdf6f64a71d36e5`。
