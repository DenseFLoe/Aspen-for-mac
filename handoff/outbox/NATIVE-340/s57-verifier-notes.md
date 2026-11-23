# NATIVE-340 s57 复验

固定 [#450 @ 817183580e8e59b82c3389a2cdf0a01c6ecb1e96](https://github.com/DenseFLoe/Aspen-for-mac/tree/817183580e8e59b82c3389a2cdf0a01c6ecb1e96) 和原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。按 [s57 任务卡](../../assignments/NATIVE-340-s57.md) 与 [覆盖证据 v1](../../standards/native-coverage-evidence.v1.md) 核对。以比较接口固定前一候选与本轮提交的 17 条增改路径，逐条核对 Git blob。沿用上轮已核实的未变路径，本件目录共 100 个文件。两套指纹 57 与 87 项均复跑一致。覆盖 v1 返回 2，1105 条覆盖、354 个原生入口、559 条调用、0 条覆盖缺口，另有 13 个托管和 15 个原生未决调用。PowerShell 返回 0，57 项指纹无差异。

用 `python -B handoff/outbox/NATIVE-340/s57-review.py CANDIDATE_ROOT --original ORIGINAL` 复跑下列三项。候选审计另在交付目录副本运行两次 `python -B tool/audit_340_s57.py --binary ORIGINAL --folder REPLAY_UNIT`，均退出 0，11 项内部检查报告通过，10 个输出的字节与固定提交相同。逐项输入指纹、命令所用版本和输出见 [复验记录](s57-recheck.json)。

## 分支说明与实际选择不一致

`audit_340_s57.py` SHA-256 `03842cc018eadacf74c94e930d38b3d373967ede716e0deddd6ac30ef878297d`。承接 [s53 的分支说明问题](s53-verifier-notes.md)。本轮原件说明中的值与地址顺序已纠正。只改文件映射 RVA `0x28FE` 的立即数 1→2 后，`.data` 的节属性仍为 `0xC0000040`，`jge` 落空，实际执行 `0x28F9` 的 `xor al,al`，随后 `jz` 跳过回调。预期记录目标路径 AL=2、实际 AL=0、跳过为真。分支事实表已给出这些值，但主表与五份原生附表写作“落空 al=2 跳过”，审计仍返回 0。应由三态解码记录分别生成候选路径值与实际值，并断言输出。复跑原件、只改 `jge→jl`、只改取跳立即数三个用例，主表与附表的实际 AL 应依次是 0、1、0，跳过依次是真、假、真。

## 逐节虚拟范围取了 raw 边界

`audit_340_s57.py` 同版本。独立从原件 MethodDef、IL 方法头和 EH 节字节确认 25 节及 35 条子句，13 finally、11 fault、7 catch、4 filter，交付的子句字节字段均吻合。`.text` 的 raw 末端为 `0x4A00`，原始 `VirtualSize` 末端为 `0x4968`。25 行 `virt_end` 仍用 `max(SizeOfRawData, VirtualSize)` 生成，全部打印 `0x4A00`。两套指纹和审计均通过。这 25 节仍处于真实虚拟范围内。应单独读出两个边界，让输出复用读取器实际采用的边界。回归用原件 `0x0600000B`，预期 `raw_end=0x4A00`、`virt_end=0x4968`，宽度及条数仍为 24 字节和 2 条。

## 文件截在 EH 节头时，错误缺少定位

`method_body.py` SHA-256 `0cb11e5efb68d43f6cb09decbd7a3bb7a8561a50a642d113969b2d4cc17a7536`。承接 [s53 的边界问题](s53-verifier-notes.md)。本轮两种混排、9／10 节链、整节后端的三类截短和缺失后继诊断均已复现。独立夹具先运行完整 276 字节版本，读取 10 节。只将实际文件缩为 250 字节，最后一节 RVA `0x24F8` 对应的四字节节头只余两字节，raw 和 virtual 均仍为 276 字节。预期报告 FILE 截短与首个不可读偏移 `0xFA`，实测 `IndexError: index out of range`。读取器在检查三条边界前已经读取四个头字节。建议在读取节头前单独核对四字节范围，再按申报长度核对整节。回归要求完整版本仍读完 10 节，文件 250 字节版返回有位置的 FILE 错误，且 raw 和 virtual 单独缩至 250 字节时各自报告首个失效 RVA `0x24FA`。

