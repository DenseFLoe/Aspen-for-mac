# NATIVE-340 s29 验收器更新痛点

候选为 [PR #446 固定 head](https://github.com/DenseFLoe/Aspen-for-mac/tree/57a2c23f0ac898a0bf9eb27dac524772acc9ad44/handoff/inbox/NATIVE-340)，候选目录 SHA-256 为 `12edd8e3bc5da768c7d8fc41e6f408ea5b8e822db7d0761e694f10e83d560bf1`。原件 SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。判据为 [s29 任务卡](https://github.com/DenseFLoe/Aspen-for-mac/blob/c260f73c2d5043aaa8731e688b0662d4f6ab3bd0/handoff/assignments/NATIVE-340-s29.md) 与[原生覆盖证据 v1](https://github.com/DenseFLoe/Aspen-for-mac/blob/c260f73c2d5043aaa8731e688b0662d4f6ab3bd0/handoff/standards/native-coverage-evidence.v1.md)。

## 原生间接调用的宿主被误认成 CLR 槽跳板

[主干 49cd8ea3](https://github.com/DenseFLoe/Aspen-for-mac/tree/49cd8ea339df68b5b08dfa49589a653d41d4e25e/tools/reverse_acceptance) 的 `verify.py` 1.6，源树 SHA-256 `27fa0c5ac03241a9fc7dead167bdce426ee914b324b8d6cfd1f6353f75ead640`，本机 23 个工具及依赖 blob 与该提交一致。

```powershell
python -B tools/reverse_acceptance/verify.py item --original ORIGINAL --sha256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec --delivery CANDIDATE --delivery-sha256 12edd8e3bc5da768c7d8fc41e6f408ea5b8e822db7d0761e694f10e83d560bf1 --reference-evidence CLR_THUNKS_JSON --reference-evidence-sha256 5100064a4214751ba26289aa6566d062bd4118833929a5c4e8ccadafc1bab2e0
```

参考 manifest 绑定的历史 126 项区间表 SHA-256 为 `c5b93ac648c941b5a788ac856af8f96c232dd230d09830d8b81664b6c18d33f3`。复跑中 126 项历史槽跳、237 项 .nep 跳转、111 项额外前驱、21 项构造调用及 `0x3660` 均通过。[#443 的 s25 旧版误报](https://github.com/DenseFLoe/Aspen-for-mac/blob/c260f73c2d5043aaa8731e688b0662d4f6ab3bd0/handoff/outbox/NATIVE-340/s25-verifier-notes.md) 在本候选上消失。

1.6 仍以 `nep_thunk_missing_or_incorrect_evidence` 报 `0x20cc` 并退出 1。该地址是 `0x21ae` 的宿主，原件指令 `41 ff d1` 是 native CALL R9。主表误加的 `COM vtable slot 0` 应按原件修正，同时保留未决目标。当前验收器把含 `vtable slot` 的自然语言当成 CLR 跳板声明，再用宿主入口解码，导致一条额外的整件失败。建议以明确的 CLR MethodDef / fixup slot 字段或原件已识别的 CLR 跳板地址确定核对范围，把普通 COM/Guard 行留给对应的 native 转移检查。 [主干判定代码](https://github.com/DenseFLoe/Aspen-for-mac/blob/49cd8ea339df68b5b08dfa49589a653d41d4e25e/tools/reverse_acceptance/mixed_baseline.py#L165-L190)

回归固定原件与 #446。更新后，`0x20cc` 无 CLR 跳板失败，`0x21ae` 的原生未决证据仍保留。已在两个候选副本做控制检查。只删除该行 callee 的误标短语，实际 `mixed_baseline` 通过，整件退出 2。再将一条真实 CLR 跳板 `0x5004` 的槽由 `0x19018` 改为 `0x19028`，实际只新增 `0x5004` 的 `baseline_thunk_missing_or_incorrect_evidence`，整件退出 1。两个副本应重新计算候选目录指纹或省略固定目录指纹参数。

## 当轮回执的文件摘要需要独立检查

固定主干的 `check-native-coverage.py`（Git blob `e0b5e9c4617c9fdff9ba8d3179b60f7abad52979`）运行结果为 1105/354/559/0，退出 2。任务卡同时要求本轮交付指纹。覆盖检查无需读取回执，1.6 的目录摘要也没有对账本轮回执，裁定时需额外复核。

```powershell
python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE
pwsh -NoProfile -File check-s29-446.ps1 -Original ORIGINAL -Unit CANDIDATE
```

独立脚本比较本轮 `code/s29-fingerprints.json` 中 53 项，52 项匹配。`code/s29-audit.md` 声明 `80efebf82ee6c66b42d0c7780c091af196fafd2136b404d37c248a14ae85c556`，实际 `f3e72e0daf2e48b5e2653b09c7bb2609e4deebc8acd3cd81bcff388aa62a3b26`。生成器先散列旧审计文档，再写入本轮审计文档。仅将审计页指纹条数从 53 改为 52 可复算出旧摘要。 [生成器写入顺序](https://github.com/DenseFLoe/Aspen-for-mac/blob/57a2c23f0ac898a0bf9eb27dac524772acc9ad44/tool/render_340_s29.py#L8-L14)

建议在按任务卡选中当前回执后增加只读的路径与 SHA-256 对账，输出不符的路径、声明值和实测值。回归用原始 #446 运行，应精确报出一项摘要不符。只在副本将该清单行更新为实际值再运行，应为 53 项一致，覆盖结果仍退出 2。历史 s25 清单按原固定候选重放。
