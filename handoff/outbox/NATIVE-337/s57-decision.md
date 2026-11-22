# FindComponent.dll s57 裁定

固定 [#445 @ fdad14b1](https://github.com/DenseFLoe/Aspen-for-mac/tree/fdad14b1ab1e3a4ed59c58a79c6b9337a69dc586)。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。五项提交对照全部复现，原有单文件和同目录拆分布局都输出 161 站。0x106C 指向第 525 行，0x12DA 指向第 528 行。附表实际路径为 `code/s37-two-hop.csv`，与单文件重放摘要一致。

附表路径修订和卡上两种布局的修复已核实。完整补证退回。把同一拆分清单放进子目录，正确更新相对路径后，生成器仍退出 0，少了 0x12DA，仅输出 160 站。提交也未给出固定拆分输入及其输出摘要。上游实测摘要已归档，作为补证对照。覆盖 v1 退出 2，684 条引用中仍有 112 条未决，整件静态验收尚未通过。

[复验步骤](s57-verifier-notes.md) · [输入及输出指纹](s57-layout.json) · [s61 续领](../../assignments/NATIVE-337-s61.md) · [#13 提交](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7087491644)
