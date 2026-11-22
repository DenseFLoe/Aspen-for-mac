# NATIVE-341 第五号分配 · mmstruct.dll

执行方为 tietoumiao，`assigned_seq=5`，时限从本轮 #13 分配 ACK 起 24 小时。原件归属 Plus-Properties，原路径 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmstruct.dll`。固定原件为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/341/mmstruct.dll`，530,472 字节，SHA-256 为 `bb9a2422bffe3a6aaa6c2a533ef7b4ef25d14092560d519bc93b94e216ce4870`。[原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/341/mmstruct.dll)

前轮输入为 [PR #402](https://github.com/DenseFLoe/Aspen-for-mac/pull/402) 的 `b6d41c2c8d5df88be8eef96ab665a61f801ba58a`。按下列 SHA-256 取用逐件材料。

| 材料 | SHA-256 |
| --- | --- |
| [第一轮裁定](../outbox/NATIVE-341/s1-decision.md) | `c0d89fdc345e854b7ad0d6abb345884c179559962beb26733e3bcee24c6ed1b6` |
| [独立复核与逐文件指纹](../outbox/NATIVE-341/s1-audit.json) | `087596b8cce72c0100d3452ee5e238a5eea5cf78808a4509a0b24382fa66beb4` |
| [地址清单](../outbox/NATIVE-341/s1-addresses.csv) | `5a8010753ba6fb5e17d3a79ee1199f7e1c49a0bef8036cc71d5a2f706faa62ae` |

沿用原件核实的 1,665 个锚点和 3,461 个直接 IAT 调用或跳转。对照下列逐址证据续修。

1. 复核此前移出的 1,034 个间接转移和两表均漏的 85 个位置。可确定的调用保留原指令和目标依据，待解调用在 calls.csv 登记 unresolved 并给出恢复条件。
2. 从 `0x103b` 的 LoadLibraryA、`0x1012` 的 GetProcAddress、`0x1018` 的指针写入，追到 16 个经 `0x79fa0` 调用 sorresdll.dll!GetSorResStringEx 的位置，例如 `0x5530` 和 `0x557a`。完整地址已列在复核 JSON 的 resolved_indirect 中。
3. 为 1,007 个调用点关联对应的 133 个 IAT 跳板、槽位、最终导入。补足重要数据关系，例为 `0x44474` 和 `0x44481` 装入同一临界区对象 `0x9b868`。核对必要数据和资源，保留已确认范围与剩余缺口。

按[覆盖扩展标准](../standards/native-coverage-extension.v1.md)、[原生覆盖标准](../standards/native-coverage-evidence.v1.md)及[静态验收标准](../standards/static-acceptance.v2.md)复验。在 `handoff/inbox/NATIVE-341/` 提交修订，沿用固定原件；开工、交付分别写 `s5-started.md` 和 `s5-submission.md`，在 #13 报产物 PR 和完整 head。从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-341`。0 表示机械检查通过，2 表示有已申报缺口，1 表示输入或材料有误。上游逐址复核后另行裁定整件。
