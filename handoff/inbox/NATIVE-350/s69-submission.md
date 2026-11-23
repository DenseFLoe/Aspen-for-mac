# NATIVE-350 s69 交付

upstream，assigned_seq=69，交付 UTC 2026-11-23T02:02:06Z，基线 `85a00df048174880027d84a5cb4a2d006f78f82c`。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x18690,0x186a9)`，片段 SHA-256 `a54e4ac5b75e2d5ec0f89911437c11b2337c7e57f480b9eff0b262da1f5c3a7f`。

25 字节与原件吻合，含 9 条可达指令、1 字节 INT3 填充和 1 处 REL32。异常表记录 12 字节，展开信息 8 字节，均吻合。0x18699 从 RDX 指向的帧基址偏移 0x20 读取 1 字节到 CL，0x1869c 调用 0x15c74。目标保存并检查 CL，调用返回后恢复栈和 RBP。0x186a8 为填充。0x1c120 的展开信息记录 32 字节栈分配与 RBP 保存。

255 个入口中 158 个有覆盖、97 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s69/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、capstone 5.0.6, pefile 2024.8.26, iced-x86 1.21.0。覆盖 v1 返回 2。成对用例的局部回编返回 0 → 1。[清单](s69/manifest.sha256) SHA-256 `c839f49348ccb033c37a45dd5f51c39ac97cf75bfce9bc652c92f17078beccbe`。
