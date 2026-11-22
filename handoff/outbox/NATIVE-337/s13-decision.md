# FindComponent.dll 第十三号复验

**退回续修（returned）。** NATIVE-337，assigned_seq=13，候选 [#411@43017ac0901a450784de1678b55d2f501641b75c](https://github.com/DenseFLoe/Aspen-for-mac/tree/43017ac0901a450784de1678b55d2f501641b75c/handoff/inbox/NATIVE-337)。固定原件提交 64670801de54e990f975aaeda06e89340c0e4e08，路径 `issue-materials/337/FindComponent.dll`，SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。已保留两份 s13 原始回执。交付发在 #13 7079346489、7079359523、7079447161；回执内部日期早于正式派发，因此台账按上游本轮确认时间落账。

复跑主干 `63f12578ef185f22e72b01076e81420b595a9499` 的检查器得 290 覆盖行、290 工具入口、510 调用记录、0 个申报入口缺口，退出 2。用原件逐条比对候选 5,019 条指令，并按地址、IAT 槽、导入名和 #392 固定版本独立比较，363 个直接导入站点全数吻合。99 处未决在主表、原附件、推导表的地址集合吻合。原 300 个覆盖键仍缺 13 个，另新增 3 个键位于同一原件异常目录宿主 `[0x11e0,0x1319)`。其中六条旧指令仍未列出。0 个申报入口缺口不能代表整件覆盖去重无缺口。

- 13 处旧分派位置和 99 处附件的交集为零。原件 PE Load Config 给出 GuardCF 分派槽 `0x7670`，磁盘值指向 `0x6050 JMP RAX`。十二处走该槽的 call/jmp 当前记成 data，跳板本身在主表缺失。12 个地址和终端跳板见[逐址证据](s13-sites.csv)。静态可证明分派路径，运行时最终目标未知时保留 unresolved。
- 99 处中有 97 条内存操作数和两条寄存器操作数。`0x4a7c CALL RAX` 从 `0x4a64` 的全局读取取值。另有 `0x53f2 CALL R9`，在 `0x53eb` 从同一 GuardCF 槽取值，可登记已证明的分派路径。两条推导栏均为空。
- 64 个 COM 位置均还只标 unresolved。原件有三处通过 `CoCreateInstance` 和同一 `IID_IDispatch` 的工厂证据，可用于标明槽和成员。实现地址仍需按实际来源保留未决。161 个直接 caller→thunk→IAT 关联已用原件验证，当前主表无相应关联，候选反汇编仅覆盖其中 153 处。
- `metrics.json` 的 calls.csv 指纹与固定 head 的实际字节不同。实际 SHA-256 为 `da1f101a810c76f93ab9237ccb4993dc997c7ee8bd960e8a6c7d72a7fab752f4`，候选自报 `63b101e148188f3653f1a3d1a810c74656a6f5da1cc80e5592b837d2c90510b9`。复验未执行候选生成器。候选 C 是反编译伪代码，整件实现、类型和资源覆盖仍需证明。

[独立复核 JSON](s13-recheck.json) · [复验命令](s13-replay.md) · [续领卡](../../assignments/NATIVE-337-s17.md)
