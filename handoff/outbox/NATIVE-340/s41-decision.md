# NATIVE-340 s41 裁定

退回补正。[#450 @ 106eb83](https://github.com/DenseFLoe/Aspen-for-mac/tree/106eb83d05ac50c9e14e7eb079014857a9117ab3)，原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。上游以 [#13 交付通知](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7086620363) 时间补登开工与提交。开工回执写的时间早于该轮分配，原件照录。

原件结论已核实。jge 取 0x28FD 时 AL=1，落空 AL=0。固定槽在 `.data`，节头 Characteristics 为 `0xC0000040`，因此 0x2197 取跳，0x21A4 的单次读取在另一条执行路径。仅修改内存页保护不会改变这段代码读取的 PE 节头值。0x3524 有 54 字节 IL，0x3568 有一条 finally，handler 为 IL_0025–IL_002C。

1. 固定生成器重跑出 46 个 receipt 指纹和 68 个 round 指纹，提交分别为 45、67，均少 `code/README.md`。已声明路径的哈希逐项一致。
2. 只换 jge→jl，工具解出 jl 后仍以 signed>=0 选分支。独立复验预期 AL=1、继续执行，实际 AL=0、跳过。审计输出 14 项通过，主表保留 jge 字面描述。只把取跳分支的 AL=1 改为 2，审计报 1 项控制失败却退出 0，主表仍写 1。
3. 提交里的 small 和 fat 测试 IL 长 4 字节，handler 从 4 开始占 1 字节，超出范围。独立有效的 small、fat 单节及 MoreSects 清除对照均读对。越界的单变量样本仍读出条款。串联 small→fat 的对照只读出首条。

覆盖检查为 1,105 覆盖、354 原生入口、559 调用、0 声明缺口，退出 2。有 13 条托管和 15 条原生调用未决。主干 PowerShell 任务检查退出 0，按表核对 45 项。[独立复验](s41-independent.json) [复跑原始记录](s41-review.json) [验收器对照](s41-verifier-notes.md) [s45 续领卡](../../assignments/NATIVE-340-s45.md)
