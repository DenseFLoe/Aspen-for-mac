# NATIVE-340 s65 独立复验

原件 WrapSaveMergeNNFiles.dll 的 SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。固定上游主干 `85a00df048174880027d84a5cb4a2d006f78f82c`，候选 `ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e`，相较 `42dc0c03af69288288b70589a6f3064b7887494c` 增改 13 路。 [候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e) · [差异](https://github.com/DenseFLoe/Aspen-for-mac/compare/42dc0c03af69288288b70589a6f3064b7887494c...ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e) · [原件读取结果](s65-il-evidence.json)

### 通过的子项

覆盖 v1 退出 2，1105 覆盖行、354 原生入口、559 调用、0 申报缺口，仍有 13 条托管与 15 条原生未决。PowerShell 交付检查、九节与十节链、s57 原件复核均退出 0。两次独立运行候选审计均退出 0，退出前报告 12 项通过，两次均与固定交付目录逐文件一致。两套清单重算为 67 与 101 项，均与固定提交逐字节一致。

.NET PEReader 得到 35 条 EH 子句，类型、try 和 handler 边界、七个 CatchType 及四个 filter 的语义偏移与交付一致。独立读取确认四个 filter 在 IL_000B、IL_000B、IL_000F、IL_001E 读到 pop，handler 在 IL_0018、IL_0018、IL_001C、IL_002B，前两个字节都为 FE11。两条 IL_0004 calli 均读取签名 `0001010F01`，前四条指令为 ldarg.0、stloc.0、ldarg.1、ldloc.0。

### 三个原件间接调用生产者站点缺证

按 MethodDef 遍历完整 IL，核实 0x06000056 有八个调用方法、十一处直接站点，交付 `code/s65-calli.csv` 与 `calls.csv` 各只列八处。固定候选审计在加入同方法的第一条引用后执行 break，第 12 项按八个方法数制订，未覆盖同方法的其余调用站点。0x06000057 在模块中直接引用这两个 MethodDef 的扫描范围内为零，保留对其他来源的恢复条件。

| 原件遗漏调用站点 | 提供函数指针的 ldftn |
| --- | --- |
| 0x0600000B IL_0044 | 0x06000006 |
| 0x0600001F IL_0087 | 0x06000026 |
| 0x06000091 IL_0077 | 0x06000023 |

本轮确认的是候选审计的站点去重错误，以及覆盖 v1 无法定位这三处差异带来的人工复核量。审计工具 SHA-256 `ee0a266434faae0536e260773f08ed7bb51af7d7edb29801c37b7571ea8897bb`，覆盖 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`，method_body.py SHA-256 `02b89ef611474f7fdda0a2f75fb10587e14a643d93b32de239a8e7b0bd3b00f3`。按方法与调用偏移保留每条站点，方法数单独统计。对同一原件比较完整十一行和删去 0x0600000B IL_0044 后刷新指纹的交付，预期分别无差异和准确报告遗漏一行。现有固定交付包含八行，独立复验实际定位三行。

### 复跑

`CAND`、`MAIN`、`ORIGINAL` 分别为固定候选、主干根目录和原件，`UNIT` 为 CAND/handoff/inbox/NATIVE-340，`COPY` 为交付目录的独立可写副本，`REVIEW` 为当前复验产物目录。

```text
python -B MAIN/handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission UNIT
pwsh -NoProfile -File MAIN/handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit UNIT
python -B MAIN/handoff/outbox/NATIVE-340/s45-eh-chain.py --candidate CAND
python -B MAIN/handoff/outbox/NATIVE-340/s57-review.py CAND --original ORIGINAL
python -B CAND/tool/audit_340_s65.py --binary ORIGINAL --folder COPY
python -B CAND/tool/gen_fingerprints_340.py --set receipt --base-head 42dc0c03af69288288b70589a6f3064b7887494c --unit UNIT --out receipt.json
python -B CAND/tool/gen_fingerprints_340.py --set round --base-head 42dc0c03af69288288b70589a6f3064b7887494c --unit UNIT --out round.json
pwsh -NoProfile -File REVIEW/s65-il-evidence.ps1 -Original ORIGINAL -Unit UNIT
```
