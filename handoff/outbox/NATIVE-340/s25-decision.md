# WrapSaveMergeNNFiles.dll 第二十五号复验

**退回续修。** NATIVE-340，assigned_seq=25。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`，固定候选 [#443 @ ad325a41370aab89f74bff4449cb1d82fdb5884a](https://github.com/DenseFLoe/Aspen-for-mac/tree/ad325a41370aab89f74bff4449cb1d82fdb5884a/handoff/inbox/NATIVE-340)。 [#13 提交回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7082825521)

49 个候选 blob 和 47 条提交指纹核对通过。上游旧证据复跑退出 0，仍为 237 个槽跳转、122 个不同 MethodDef、111 条新增槽边、228 个独立回编桩，指标已对齐 237=126+111。固定主干 `ff585268ac8983097b8a229e3d8e49abee61d7e1` 的覆盖检查器核对 1,105 个覆盖行、354 个工具入口、554 条调用、0 个申报入口缺口，退出 2。实测主表有 228 external、298 boundary、28 unresolved（13 托管、15 原生）。

MethodDef `0x06000030` 的两处 calli 使用同一 CLR 宿主接口来源，槽和签名是 `0x68 / 0x11000044` 与 `0x10 / 0x11000043`。external 分类可采信，参数文本须纠正。`IL_000D` 暂存第二参数，`IL_0018` 重载。字段 `0x04000055 @ 0x6330` 的 CB2F6723 实际占 clsid 参数，`0x04000056 @ 0x6320` 的 CB2F6722 实际占 riid 参数。按原件的压栈次序和签名记录。

原生 `0x21ae` 的 R9 来自 `[0x61b8]`，映像槽指向 `0x48b0` 的 JMP RAX。RAX 是对固定回调槽 `0x19b78` 的单次读取，槽地址由 `0x29d0` 的 RIP 相对 LEA 返回。该槽在可写 .data 的零填充尾部。原件 `0x2187/0x218b` 先拦空槽；即使仅将槽设为非零，`0x2190 → 0x2874` 的节检查会因 `Characteristics=0xc0000040` 返回 AL=0，随后 `0x2195/0x2197` 绕过此调用。更新主表中的 COM 对象解释，保留该原版映像的禁用路径证据和其余未决位置。15+15 名单为进入 s25 时基线，需另列当前 13+15。

另发现 5 条本模块构造调用有原件 IL 和构造清单，但缺主表登记。调用方与 IL 偏移为 `0x06000020 / 0x00`、`0x0600002b / 0x07`、`0x0600002c / 0x01`、`0x0600002d / 0x02` 和 `0x060000b4 / 0x0a`。16 条外部构造调用和 126 条历史槽跳转已获独立证据。 [验收器差异](s25-verifier-notes.md)

```text
pwsh -File handoff/outbox/NATIVE-340/check-s25-443.ps1 -Original ORIGINAL -Unit CANDIDATE_ITEM_DIR
python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE_ITEM_DIR
```

PowerShell 7.6.9，System.Reflection.Metadata 10.0，Python 3.12.14，Zig 0.13.0。 [本轮原件证据](s25-recheck.json) · [历史锚点重放](s25-s21-rerun.json) · [候选文件指纹](s25-candidate-blobs.json)
