# size-control.json

固定原件与其余交付，隔离副本只改 size_t 传入值从 -1 到 -2，并重算指纹。覆盖 v1 两次均为 2，局部回编 0→1，首差 RVA 0x18580。逐条复跑覆盖检查和局部回编即可重现。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x18550,0x185a6)`，86 字节，片段 SHA-256 `48838f1e44a19a9df9b6312e94bc9c7a4fc6acaaac53037e3a59289946d53351`。 本文件 SHA-256 `432a320cb9cb69c02f58966b993022611bdb7fa82e2bd44d198a95a9a3481103`。

整件覆盖 155/255 个入口，仍缺 100 个入口和 26 条引用，静态验收未通过。 [回执](../s57-submission.md)
