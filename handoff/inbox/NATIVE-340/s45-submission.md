# NATIVE-340 s45 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ 106eb83d05ac50c9e14e7eb079014857a9117ab3
- 本轮 head：见 #13
- 保留：#450 的 237 槽 / 122 MethodDef / 228 回编桩、0x21AE 两分支、EH 0x3568 / finally IL_0025–IL_002C

## 1. 反例注入（决定性）

生成器 `tool/gate_evidence_340.py` 的表完全由字节解码得到：条件码来自 0x28F7 的 opcode，比较操作数来自 0x28F3 的 mod/rm/disp/imm，两条分支的 AL 立即数来自 0x28F9 与 0x28FD，节属性来自节头 +0x24。注入 = 在字节副本上改一个字节再跑同一个解码器。

| 注入 | 条件码 | 取跳 | 目标 | AL 立即数 | al_for_slot | 消费端跳过 |
| --- | --- | --- | --- | --- | --- | --- |
| 基线 | `jge` | False | 0x28FD | {"0x28F9":0,"0x28FD":1} | 0 | **True** |
| `jge`→`jl`（0x28F7: 7D→7C） | `jl` | True | 0x28FD | {"0x28F9":0,"0x28FD":1} | **1** | **False** |
| 立即数 1→2（0x28FE: 01→02） | `jge` | False | 0x28FD | {"0x28F9":0,"0x28FD":**2**} | 0 | True |

- 注入 1：同一负 Characteristics 下，条件码改为 `jl` 后变为**取跳**、**AL=1**、消费端**不跳过**；分支目标不变，说明读的是 opcode 不是结论。
- 注入 2：证据表原样反映新的立即数 **2**（`al_immediates["0x28FD"]=2`），且分支结构字段不变。

## 2. 控制失败必须非零退出并列出失败项

`tool/audit_340_s45.py` 的控制集（24 条：EH 9 + 真件 5 + 注入 10）任一失败即 `return 1` 并打印 `FAILED ITEM: <名称>`。实测反例：

```
$ python -B tool/audit_340_s45.py --expect-skip 0     # 故意给出与原件相反的预期
CONTROL FAILED: slot_skipped=True (expected False)
FAILED ITEMS: [slot_skipped]
[exit 1]
```

正常路径 `python -B tool/audit_340_s45.py` → 24/24 PASS，exit 0。

## 3. Characteristics ≠ 页保护

- `Characteristics`（节头 +0x24，本件 0xC0000040，符号位置位）是**文件内节属性**，静态判据读的是它；
- **页保护**（PAGE_*，VirtualProtect/VirtualQuery）是运行期概念，文件里没有编码；
- 主表第 288 行 note 已加口径说明：本条只对文件属性与静态分支下结论，不对运行期页保护下结论。代码里两者是两个独立字段（`section_characteristics` / `page_protection = "runtime only" `）。

## 4. EH 读器扩展（ECMA-335）

- small（12B：`u2 flags/u2 tryOff/u1 tryLen/u2 handlerOff/u1 handlerLen/u4 classToken`）与 fat（24B）两种布局，按 kind 的 0x40 位选择；
- `MoreSects`(0x80) 可串联多个数据节，逐段读取（测了 fat|0x80+small、small|0x80+fat 两种配对）；
- 校验 try/handler 范围必须落在 IL 内（越界拒绝）；
- 遇到支持范围外的节类型，抛 `UnsupportedSection`，报文给出**具体 RVA / kind / size**，该件停止判定（不硬读）。

合成测试 9 项 + 真件 5 项全 PASS。

## 5. 指纹（两套命令 + 规则 + 完整摘要）

```
python -B tool/gen_fingerprints_340.py --set receipt --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s29-fingerprints.json
python -B tool/gen_fingerprints_340.py --set round --base-head 106eb83d05ac50c9e14e7eb079014857a9117ab3 --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s45-fingerprints.json --rules-out handoff/inbox/NATIVE-340/code/s45-fingerprints.md
```

实际输出：`receipt: 50 files` / `round: 74 files`。选择规则、纳入路径与逐个 SHA-256 全表在 `code/s45-fingerprints.md`（脚本生成）。
**`code/README.md` 在两套集内**：`receipt["code/README.md"]` 与 `round.files["code/README.md"]` 均存在。该文件此前只存在于远端、本地缺失，本轮从 #450 head 复原并按「产物无工具署名」口径重写（去掉了旧文案里的工具名）。

## 6. 判定（真实退出码）

```
$ python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340
checked 1105 coverage rows, 354 tool-native entries, 559 call records, 0 declared gaps
exit code: 2

$ pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original <原件> -Unit handoff/inbox/NATIVE-340
exit code: 0
```
