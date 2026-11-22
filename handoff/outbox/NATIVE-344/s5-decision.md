# Simdll.dll 第五轮复验

**退回续修（returned）。** 候选提交 `dd3d4469537d072aecf76630cf8f7d1f4ead9cd7`，assigned_seq=5，原件 SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。从候选树回读清单中的 55 个文件，逐项核对 Git blob 和 SHA-256。[本轮提交回执](../../inbox/NATIVE-344/s5-submission.md)

从主干 `773260c1033e524cebe000699409f5708bebfda0` 取受信判定器，使用 `python -B handoff/assignments/check-native-coverage.py NATIVE-344 --original <原件>` 得到 1,379 行覆盖、1,379 个分析入口、434 条重点引用及 959 个申报缺口，退出 2。用 Zig 0.13.0 重新编译提交的跳板 C 源，并在每条指令原 RVA 应用对应的 REL32 重定位。401 个具名入口、401 个不同 IAT 槽及全部 2,406 字节与原件相符。这 401 项通过专项复核，连同首轮 19 项，共有 420 个已核实入口。

独立复跑 `s5/verify.py` 与 `verify_references.py`，原 11,254 组引用补齐到 11,299 组，直接 IAT 转移增至 1,961 处。已从原件回读 9 类资源的 50 个叶节点和 20,368 字节，并确认 12 个图标组内 14 条引用均指向相应图标资源。资源原文与指纹保存在[逐件交付](../../inbox/NATIVE-344/Simdll.dll.md)。

整件仍有 959 个入口缺少完整实现与逻辑对照，247 个间接转移待说明。续修时优先把 0x31540 主例程及 0x3163a、0x32580 两个展开片段的控制流、调用和数据与源代码对接，再逐址核对其余报告项及相关窗口资源的实际使用。第一轮至第五轮已验证的跳板、叶函数与资源证据可直接复用。

本轮提交回执 SHA-256 为 `1c9e0d2a7d33cb4880ece9a6eb11205a10a40f0b5a0c42ee1ed79599c77c5077`，产物指纹清单为 `b8b924d66a3ae646c0d4eabbf286bea85716cba658ef2f8752895244ca977e03`，跳板重组记录为 `aba7de0c1eefc19034c8270218728b6a652d9ddae885b1f02138aaaa7a3eb91b`。
