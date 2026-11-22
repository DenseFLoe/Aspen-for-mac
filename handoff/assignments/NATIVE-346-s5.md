# NATIVE-346 第五号事件续领

执行方 upstream，assigned_seq=5。时限从本轮 #13 ACK 起算 24 小时。原件、产品路径和下载来源见[首轮任务卡](NATIVE-346.md)。固定提交 64670801de54e990f975aaeda06e89340c0e4e08 的 issue-materials/346/ppexec.dll，138,280 字节，SHA-256 为 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a。

首轮在 [固定裁定](../outbox/NATIVE-346/s1-decision.md) 留下 82 个入口和 30 条间接转移待查。新复查已解出 0x8d40 和 0x8e10 两处内存操作分派器，每个分派器按三层掩码或默认条件选择四个地址，并写入对应缓存。[原件复查命令源文件](../outbox/NATIVE-346/s5-selectors.py) · [结果](../outbox/NATIVE-346/s5-selectors.json)

将这两处分派及其快速路径的寄存器、缓存读写、分支目标与可编辑实现逐一核对，继续核验 0x8ea0、0xa6c0、0xe040 和其他原件范围。区分有原件依据的确定目标与仍依赖运行时状态的转移。逐址登记新增覆盖、剩余实现与资源/导出数据缺口，保留首轮来源。

交付目录为 handoff/inbox/NATIVE-346/，回执用 s5-started.md 和 s5-submission.md。适用 [上游原生覆盖标准](../standards/native-coverage-upstream.v1.md)。从仓库根目录执行 `python handoff/assignments/check-native-coverage.py NATIVE-346`，本地复用固定原件时加 `--original <原件>`。重组对照按首轮 rebuild.py 的固定工具执行，另记录扩展范围和逐段字节、重定位的核对结果。
