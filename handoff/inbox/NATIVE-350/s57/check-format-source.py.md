# check-format-source.py

复跑 `python -B handoff/inbox/NATIVE-350/s57/check-format-source.py ORIGINAL ZIG --evidence-dir OUTPUT`。依赖 Zig 0.13.0、pefile 2024.8.26、Capstone 5.0.6、iced-x86 1.21.0 及本件既有 verify.py。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x18550,0x185a6)`，86 字节，片段 SHA-256 `48838f1e44a19a9df9b6312e94bc9c7a4fc6acaaac53037e3a59289946d53351`。 本文件 SHA-256 `a6ce226b58cc2f8591d5b773e25271a2bdd052596b2d503af6bb6d154893a822`。

整件覆盖 155/255 个入口，仍缺 100 个入口和 26 条引用，静态验收未通过。 [回执](../s57-submission.md)
