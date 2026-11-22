# FindComponent.dll 第二十一号复验

**退回续修。** NATIVE-337，assigned_seq=21。已复核 [#428 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/b9bcc8630fc4344796d9c4d59e86ec78901ac9ba/handoff/inbox/NATIVE-337) 与 [#13 提交](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7081316967)。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。判定器退出 2，307 个覆盖键、307 个工具入口、684 条调用、0 个申报入口缺口。主表实为 524 external、48 data、112 unresolved。

- 原件的 363 条直接 IAT 位置与 13 处 Guard CF 登记均保持。161 条二跳均核到原件指令、跳板、IAT 槽和主表外部记录，八个先前未归属的尾跳也已补齐。九个非填充指令的起址和字节吻合，27 个差异为 INT3/NOP。
- 三个工厂所用 IID 为 `00020400-0000-0000-c000-000000000046`。64 个槽位含 16 个 GetIDsOfNames、32 个 Release 和 16 个 Invoke。静态证据可确认这些接口成员，服务器实现地址仍需运行时对象与加载模块身份。逐址补齐可复核的恢复条件。
- `code/indirect-resolved.csv` 中 99 条间接转移仍用旧清单行号。例：`0x1389` 写 L237，现 L237 对应 `0x1340`，正确行是 L251。主表相应位置已经正确。将附表生成器按 RVA 关联当前清单，并修正二跳附表 161 条过期的 `primary_class=absent`、指标中的 external/indirect 旧计数。为 `0x12da` 明确记录原件宿主 `0x11e0` 与候选子清单 `0x12bd` 的映射。
- 112 条未决中含 64 条上述 COM、13 条 Guard CF、2 条寄存器调用、33 条其他内存分派。后者有 16 条同属 `0x4706`，优先沿原件接收方来源处理这一组。其余按位点保留静态边界和恢复条件。

[固定候选文件指纹](s21-candidate-blobs.json) · [独立复跑结果](s21-recheck.json)。收件仅登记本件对应的回执及核验证据，候选分支还包含共享工具变更。
