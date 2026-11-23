# NATIVE-342 s57 交付

upstream，assigned_seq=57，交付 UTC 2026-11-23T03:04:22Z，基线 `0efdc367513b4850841dff1d13ebd78cb5cea67a`。ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x35204,0x35264)`，片段 SHA-256 `aac1533de9bf8cdb8662108ffcce0dd34d55507db2a5364cfc5e02b6d53f7762`。

96 字节、27 条指令、3 处 REL32、.pdata 12 字节和 .xdata 20 字节吻合。 0x35223 调用 0x35e80 读取 CRT 标志。标志为零且原始 EDX 为 1 才执行 0x3523c 的 GuardCF 回调。R9 经 RDI 传到 RAX，回调实参为入口 RCX、零值 EDX 和入口 R8。固定原件的调用点 0x39623 由 0x39611 的 LEA 将 R9 绑定至 0x35974。其他入口与装载后的调度状态待核。0x3525f 经 0x362fe 与 IAT 0x3a778 将第 5、6 个入参传给 _seh_filter_dll。

1,005 个入口中 722 个有覆盖、283 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s57/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[清单](s57/manifest.sha256) SHA-256 `4e52f5f20b63db3591621db5c7f5cad182895d2b3658d4991a0a117ac3e1b945`。
