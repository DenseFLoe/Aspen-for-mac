# check-diagnostic.py 的复验说明

使用 Zig 0.13.0、Capstone、iced-x86 1.21.0、pefile 2024.8.26 和交付根目录的 verify.py。从仓库根运行 `python -B handoff/inbox/NATIVE-350/s49/check-diagnostic.py ORIGINAL ZIG --evidence-dir OUTPUT`。脚本仅作静态读取和 COFF 回编。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15180,0x15220)`，160 字节，范围 SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`。 本文件 SHA-256 `e136d7e34aafeccbffac8fcb6e30e6767cd752283faf8b2541f401e78e293980`。

整件覆盖 153/255 个入口，仍有 102 个入口缺口和 26 条未决引用，静态验收未通过。 [本轮回执](../s49-submission.md)
