# NATIVE-340 s81 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ f847024](https://github.com/DenseFLoe/Aspen-for-mac/tree/f8470240a320318bd82ef58f9f0e84e311022be1)。主干基线 0554621e9ac0d627fad1e399d8868da06d1482e6。

198 个候选路径已按 Git blob 和 SHA-256 核验，两套清单 90/132 项吻合。原件 PEReader 复算 167 个 IL 摘要全合，四槽原值和 token 差异为零。覆盖 v1 实测 1105/354/559/0，退出 2，13 托管和 15 原生引用未决。两个 0x0A 槽的位名、MethodImpl 一基 RID、HeapSizes 及生产表流的列宽仍需修订。s81 审计对不在原件中的额外摘要 token 仍退出 0。

裁定 returned。覆盖命令、输入和实测见[复验记录](s81-verifier-notes.md)。交付复验证据 SHA-256 4734c67d6aa548a2412564296ff6510e50c47986a4b1f58d964ee83fd48b641a。

[开工证据](../../inbox/NATIVE-340/s81-started.md) · [交付回执](../../inbox/NATIVE-340/s81-submission.md) · [续领卡](../../assignments/NATIVE-340-s85.md)
