# FindComponent.dll s37 复验

任务 NATIVE-337，assigned_seq=37，原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。固定候选 [#445@5d0b4f3](https://github.com/DenseFLoe/Aspen-for-mac/tree/5d0b4f3aae5886f7d441a7dfc5a6c64e160e7952/handoff/inbox/NATIVE-337)。按[任务卡](../../assignments/NATIVE-337-s37.md)与[原生覆盖证据 v1](../../standards/native-coverage-evidence.v1.md)复跑。此轮补证为 returned，整件未通过静态验收。

- 核对了 57 份件内及 PR 文件。主干 `check-s33.py` 返回 0。161 条首跳、IAT 槽、导入符号、候选与原件宿主、ASM 和主表行全吻合。两版附表字节相同，当前 s37 回执的三个摘要均正确。0x12da 的原件宿主为 0x11e0，候选宿主为 0x12bd。64 条 COM 与 16 条对象槽的逐址证据通过，直接 IAT 为 363。
- 交付说明提到 `tool/s37_two_hop.py`、`tool/s37_receipts.py`，固定 head 均返回 404。任务卡要求交付生成器并绑定指纹。请发布可复跑的脚本，以同一原件重生附表与本轮收据。旧轮回执保留在旧 head。
- 主干覆盖脚本返回 2，307/307/684/0，保留 112 条 unresolved。验收器 1.6 返回 2，仍有间接目标、原版资源字节与源码等价性待核。 [逐址复跑结果](s37-recheck.json)

主干 [fd5d755 的验收器 1.7](https://github.com/DenseFLoe/Aspen-for-mac/tree/fd5d755d824f903e9c5b2682260cc69bf8e1b9ad/tools/reverse_acceptance) 复跑返回 2，源树 SHA-256 `7ae119806e8934f0e882519f3806b300fc24d8586ebe5475c09da963e157f58f`。
