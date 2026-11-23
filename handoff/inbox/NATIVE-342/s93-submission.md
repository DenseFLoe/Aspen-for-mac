# NATIVE-342 s93 交付

upstream，assigned_seq=93，交付 UTC 2026-11-23T10:09:22Z，基线 `19f94421ea3b724df2b27f65f71832db0259f34d`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x366e0,0x369b6)`，片段 SHA-256 `a37241803bea0d69bc7e8d8cce04d9ac893f4c311b0a1d62d17e1a7e50c0a766`。

回编 726 字节、195 条解码指令、28 处 REL32、12 字节 .pdata、28 字节 .xdata 均匹配。0x36705 和 0x36990 进出受保护路径。描述符位 0 控制 RVA 模式，失败路径以 0xc06d0057 调用 RaiseException。原件由导入地址槽索引定位名称或序数，依次检查通知回调、缓存模块、加载结果、绑定时间戳和首选映像基址，再回退到 GetProcAddress。0x3688c 原子发布模块；0x36965 写最终地址。通知、失败回调和 API 解析后的运行时地址保留待核。

1005 个入口中 732 个覆盖、273 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s93/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s93/manifest.sha256) SHA-256 `4ddd9bb00b34a21ca84c249844c4698137d17810b00efd68cd95fe545c097729`。
