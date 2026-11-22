# WrapSaveMergeNNFiles.dll 第十三号复验

**退回续修（returned）。** NATIVE-340，assigned_seq=13，[候选 #419](https://github.com/DenseFLoe/Aspen-for-mac/pull/419)，固定 head `b16fc9edf36dd9355e6ff083b3566ea8cbb57fdf`。原件来自 `64670801de54e990f975aaeda06e89340c0e4e08:issue-materials/340/WrapSaveMergeNNFiles.dll`，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。按 [覆盖证据 v1](../../standards/native-coverage-evidence.v1.md) 与 [静态验收 v2](../../standards/static-acceptance.v2.md) 复核；收件两回执保留，候选及工具保留在原 PR。[25 份候选文件指纹](s13-419-manifest.sha256) · [逐址复验](s13-419-recheck.json)

- 原件 CLI +0x30 的表有 237 条、237 个槽、122 个不同 MethodDef，候选槽表逐格吻合。另从固定基线逐条解 126 个原生 JMP，实证 126 个槽、122 个不同且均有 IL 实现的 MethodDef。这组在当前反汇编仅 4 个地址有行号和主表记录，四处均未归入已知的 native → managed 边，其余 122 个位置两表均缺。示例 `0x5004 → 0x19018 → 0x06000001 (RVA 0x10a0)`。
- 21 处 newobj 的原始字节和 token 与附件一致，含 16 个外部、5 个本模块构造调用。21 处都还缺主调用表记录。19 个非空 TypeDef 的方法区间逐 token 匹配原件，覆盖全部 188 个 MethodDef。上一轮的 61 条跨界调用仍在表内。
- 39 条间接证据在主表可定位。0x3660 原件为 `mov rax, gs:[0x30]`，随后 `mov rax, [rax+8]`；两视图取到同样 14 字节。候选 C 沿用仅从 `Self + 8` 读取的旧实现，须补 TEB 的来源及 StackBase 的读取语义。
- 主干检查器 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8` 实跑 877 个覆盖行、126 个分析器识别入口、310 条调用、0 个已申报入口缺口，退出 2。metrics.json 仍然报 19 条间接项及旧调用表指纹。不能据覆盖行数判断完整性。

若用普通目录复跑，把候选和第九号候选目录固定在上述 head 和 `be34d79c8751096529a62b5703b6bfd9f59446e5`。用 `python -B handoff/outbox/NATIVE-340/check-s13-419.py <原件> <候选目录> handoff <第九号目录>` 复查地址，另运行任务卡的检查器。续件见 [第十七号任务卡](../../assignments/NATIVE-340-s17.md)。
