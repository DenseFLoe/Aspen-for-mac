# ApwnIPShell.dll s25 交付

NATIVE-342，owner upstream，assigned_seq=25。提交 2026-11-22T22:33:45Z。固定基线 `08fce6abe7ef487a6b72e3f8974b0d4f8cb999e3`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 0x339a0–0x33a14 的 35 条指令。三处 AMD64 REL32 回填后，116 字节与原件一致。三处 ADDR32NB 回填后 .pdata 的 12 字节一致，.xdata 的 16 字节一致。

输出参数为空时返回 0x80004003。缓存槽是原 RCX+0x40。空缓存时在 0x339e7 调用 ole32.dll!CoCreateInstance，CLSID 在 0x42af8，IID 在 0x42978，外部聚合指针为零，CLSCTX=1，第五参数指向缓存槽。负 HRESULT 直接退出。成功路径或缓存命中时在 0x339f6 写入调用方输出槽，0x339ff 从该接口虚表 +8 调用，符合 IUnknown 的 AddRef 槽位。具体运行时目标保持未决。

1,005 个入口中 714 个有覆盖、291 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s25/check-interface.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[成果指纹](s25/manifest.sha256) SHA-256 `c68866f98d7e29671269f7da8d823b8dfaaf816022bf0521300f756d025dc523`。
