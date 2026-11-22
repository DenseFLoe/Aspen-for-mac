# NATIVE-338 第五号分配 · Happ.dll

执行方为 tietoumiao，`assigned_seq=5`，时限从本轮 #13 分配 ACK 起 24 小时。原件归属 Plus-Properties，原路径 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Happ.dll`。固定原件为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/338/Happ.dll`，634,920 字节，SHA-256 为 `7d4964f25cee38127a0b68fd3c0360c79c030f4c6ed24aa2d2e50b68e008936a`。[原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/338/Happ.dll)

前轮输入为 [PR #398](https://github.com/DenseFLoe/Aspen-for-mac/pull/398) 的 `2dae2f74ef4fd86e4eaeab00852b2fb6c3c3a6db`。按下列 SHA-256 取用逐件材料。

| 材料 | SHA-256 |
| --- | --- |
| [第一轮裁定](../outbox/NATIVE-338/s1-decision.md) | `5e9067da3d35ac9be122dad6df0b872bbc35df0f68b7a2de53a988db0e39cae0` |
| [独立复核与逐文件指纹](../outbox/NATIVE-338/s1-audit.json) | `6bfbaaf797a80d8787c4d94f555681c4cab13ad52555b0c59c9a1ae7be4bfde4` |
| [地址清单](../outbox/NATIVE-338/s1-addresses.csv) | `cbf8f068af133c005c1423f54dcd4d105a4fbab0def044d16db3d9ef7313c4d2` |

沿用原件核实的 1,522 个锚点和 4,266 个直接 IAT 调用或跳转。对照下列逐址证据续修。

1. 恢复 `0x25b90` 的实际函数体（异常目录至 `0x25ccb`，`0x283e4` 调入），把 coverage 行指向真实实现。核对 `0x3f478` 的 44 字节选择表、`0x3f3cc` 的分派、11 项选择与 7 个不同目标，关联到宿主实现。如果仍有缺口，按真实证据登记。
2. 依据原件复核此前移出的 2,630 个间接转移和两表均漏的 50 个位置。可确定的调用保留原指令和目标依据，待解调用在 calls.csv 登记 unresolved 并给出恢复条件。重要数据或表亦应关联，例为 `0x1007` 将 `0x777e0` 交给 InitializeCriticalSectionEx。
3. 为已列的 1,121 个调用点关联对应的 171 个 IAT 跳板、槽位和最终导入。核对必要数据和资源，保留已确认范围与剩余缺口。

按[覆盖扩展标准](../standards/native-coverage-extension.v1.md)、[原生覆盖标准](../standards/native-coverage-evidence.v1.md)及[静态验收标准](../standards/static-acceptance.v2.md)复验。在 `handoff/inbox/NATIVE-338/` 提交修订，沿用固定原件；开工、交付分别写 `s5-started.md` 和 `s5-submission.md`，在 #13 报产物 PR 和完整 head。从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-338`。0 表示机械检查通过，2 表示有已申报缺口，1 表示输入或材料有误。上游逐址复核后另行裁定整件。
