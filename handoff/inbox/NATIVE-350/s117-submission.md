# NATIVE-350 s117 交付

upstream，assigned_seq=117，交付 UTC 2026-11-23T11:04:12Z，基线 `c8ec21865e2a9afc48873757ec1da993ceaf2f26`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15f9c,0x15fd8)`，片段 SHA-256 `54bc5b80c9f5e36504c1d7a7a77b3d507b81ad2073c3f0c59fbb20682c4b1aec`。

回编 60 字节、17 条解码指令、3 处 REL32、12 字节 .pdata、12 字节 .xdata 均匹配。旧分析将 0x15f9c 命名为 _RTC_Initialize。实际两条 LEA 的 RVA 均为 0x1bf78；0x15fcb 用无符号严格小于控制循环，所以本原件区间为空，直接返回。通用循环每次推进 8 字节、跳过空指针，加载回调到 RAX 后经 0x194b8 调度。原件 PE Load Config 将 0x194b8 标记为 GuardCFDispatchFunctionPointer，DIR64 使其磁盘初值指向 0x18520（jmp rax）。已核磁盘绑定，保留不可由这条路径确认的运行时落点。

255 个入口中 171 个覆盖、84 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s117/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s117/manifest.sha256) SHA-256 `16d18ac418c8343a88b0b19db07489a52e77e795284c22420dfa5d4789408501`。
