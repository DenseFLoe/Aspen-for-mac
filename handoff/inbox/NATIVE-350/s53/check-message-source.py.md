# check-message-source.py 的复验说明

使用 Zig 0.13.0、Capstone 5.0.6、iced-x86 1.21.0、pefile 2024.8.26 和本件 verify.py。从仓库根运行 `python -B handoff/inbox/NATIVE-350/s53/check-message-source.py ORIGINAL ZIG --evidence-dir OUTPUT`。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15000,0x15176)`，374 字节，范围 SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`。 本文件 SHA-256 `135a44f70f609be64027d8764ee2f4377a63229201e364161c5a1dcde673274c`。

整件已覆盖 154/255 个入口，仍有 101 个入口及 26 条引用待核，静态验收未通过。 [本轮回执](../s53-submission.md)
