# NATIVE-340 s61 独立复验

固定原件 WrapSaveMergeNNFiles.dll，SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。从 GitHub 比对 s57 到 s61 的 20 条增改路径，逐件核对本轮候选交付目录全部 109 个文件、候选 tool 目录 33 个普通文件的大小与 Git blob。回执提及下载 110 个文件，未提供那批文件的完整范围，此处只使用上述两处的固定目录。基线脚本取自主干 7ce64a25。[候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/42dc0c03af69288288b70589a6f3064b7887494c) · [上轮到本轮](https://github.com/DenseFLoe/Aspen-for-mac/compare/817183580e8e59b82c3389a2cdf0a01c6ecb1e96...42dc0c03af69288288b70589a6f3064b7887494c) · [固定主干](https://github.com/DenseFLoe/Aspen-for-mac/tree/7ce64a251d9c5210041903988c016a53b3f85287)

### 已修正的原件证据

覆盖检查实际退出 2，登记 1105 行覆盖、354 个原生入口和 559 条调用，覆盖缺口 0。仍有托管未决调用 13 条，原生未决调用 15 条。PowerShell 退出 0，62 项指纹相符。独立复算两套指纹 62/94 项，路径集、文件 SHA-256 和清单原始字节均一致。候选审计在同一交付副本连续运行两次，退出码均为 0，每次的 109 个文件都与固定提交逐字节一致，11 项检查均通过。

原件 25 个 EH 节、35 条子句，13 finally、11 fault、7 catch、4 filter。0x0600000B 的 raw 末端 0x4A00、virtual 末端 0x4968、单条宽度 24、共 2 条。276 字节夹具读完十节；raw、virtual、file 独立缩到 250 字节，各报出首个失效位置 0x24FA、0x24FA、0xFA。两种宽度顺序和九／十节链回归通过。主表与五份附表都正向匹配三条实际 AL 0/1/0 及跳过真/假/真。立即数改成 2 时，候选路径 AL=2、执行路径 AL=0 均有独立记录。

### 原件四条 filter 的字段语义仍缺失

`s61-clauses.csv` 只给出 `class_token`。四条 filter 的末字段实际是指向方法 IL 的偏移。独立的 .NET PEReader 读取如下。每条在 filter 起点读到 pop，在 handler 的前两字节读到 endfilter（FE 11），每条 CatchType 都为空。已有核验脚本既比较了原始整数，又接受同一个列名，因而未发现语义混淆。候选审计与两套完整指纹也会接受这些行。[ECMA-335 II.25.4.6](https://www.ecma-international.org/wp-content/uploads/ECMA-335_6th_edition_june_2012.pdf) · [.NET ExceptionRegion](https://learn.microsoft.com/en-us/dotnet/api/system.reflection.metadata.exceptionregion)

| MethodDef | filter 起点 | handler 起点 | 交付列 class_token |
| --- | ---: | ---: | --- |
| 0x06000056 | 0x0B | 0x18 | 0x0000000B |
| 0x06000057 | 0x0B | 0x18 | 0x0000000B |
| 0x06000058 | 0x0F | 0x1C | 0x0000000F |
| 0x0600005B | 0x1E | 0x2B | 0x0000001E |

56 和 57 另各有一条 IL_0004 的未决 calli。两件方法清单均显示 ldarg.0 → stloc.0、ldarg.1、ldloc.0、calli 0x11000075。交付只给“指针表初始化或断点”，可先静态说明第一个参数经 loc0 提供目标指针，另一个参数作为入参，核对独立签名和可见调用者。缺少唯一绑定时继续保留 unresolved 并指明缺哪个生产者。

### 通用读取器的一项夹具限制

`method_body.header` 对 tiny 方法先取两个字节再右移两位。相同的单字节头 0A，跟随 00 2A 或 01 2A 均应返回长度 2。实测前者为 2；后者为 66，返回的 IL 混入紧随其后的 CC。该原件 tiny 方法数为 0，因此此现象单列为工具反馈，不影响本轮 25 节复验。该夹具 SHA-256 及现有脚本指纹见记录。

### 复现

`MAIN` 指固定主干，`CAND` 指候选根目录，`UNIT` 为其 handoff/inbox/NATIVE-340，`COPY` 为 UNIT 的可写副本，`REVIEW` 为本报告目录，`ORIGINAL` 为上述固定原件。每次候选审计后核对 COPY 中每个文件相对路径和 SHA-256。新脚本输出测量值，报告和记录说明实际裁定。[脚本与输入指纹、各项原始结果](s61-recheck.json)

```text
python -B MAIN/handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission UNIT
pwsh -NoProfile -File MAIN/handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit UNIT
python -B MAIN/handoff/outbox/NATIVE-340/s45-eh-chain.py --candidate CAND
python -B MAIN/handoff/outbox/NATIVE-340/s57-review.py CAND --original ORIGINAL
python -B CAND/tool/audit_340_s61.py --binary ORIGINAL --folder COPY
python -B CAND/tool/audit_340_s61.py --binary ORIGINAL --folder COPY
python -B CAND/tool/gen_fingerprints_340.py --set receipt --base-head 817183580e8e59b82c3389a2cdf0a01c6ecb1e96 --unit UNIT --out receipt.json
python -B CAND/tool/gen_fingerprints_340.py --set round --base-head 817183580e8e59b82c3389a2cdf0a01c6ecb1e96 --unit UNIT --out round.json
pwsh -NoProfile -File REVIEW/s61-filter-control.ps1 -Original ORIGINAL -Unit UNIT
python -B REVIEW/s61-tiny-control.py CAND --original ORIGINAL
```
