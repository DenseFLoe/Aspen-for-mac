# NATIVE-340 s41 逐项核对（脚本生成）

基线：#450 head `88bbe3130f561d2cdd76b3652cfbc3ab3a901a23`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 0x2874 的两条分支（由原件字节解出）

| 指令 | 地址 | 去向 | 返回值 |
| --- | --- | --- | --- |
| `cmp dword ptr [rdx+0x24], 0x0` | `0x28F3` | 判据：节 Characteristics(+0x24) | — |
| `jge` | `0x28F7` | 取 NEAR `0x28FD` | al=**1** |
| 落空 | `0x28F9` | `0x28F9` | al=**0** |

判定式：`signed(Characteristics) >= 0` 走 jge 目标（返回 1，表示**不可写**）；否则落空返回 0（**可写**）。

## 2. 节门禁与 0x21A4 的分支

- 消费端：`test al,al` + `jz 0x21B1` ⇒ al==0 跳到 `0x21B1`（跳过 `0x2199-0x21B0`），al!=0 才落入 `0x2199-0x21B0`。
- 固定槽 `0x19B78` 在 `.data`（Characteristics `0xC0000040`，signed=-1073741760，writable=True）⇒ 返回 al=0 ⇒ **节门禁跳过**：`0x21A4` 的 `mov rax,[rbx]` 与 `0x21AE` 的 call r9 只在 `0x2199-0x21B0` 这一支，本映像不执行（除非运行期改节保护）。
- 结论：`0x21A4` 的单次读取位于**非可写分支**（jz 落空），不是无条件路径。

## 3. 生成器

- `tool/x86_340.py`：解码 `cmp/jcc/xor al/mov al/test al/jz` 并从字节推导两条分支的地址与返回值、读 `IMAGE_SECTION_HEADER.Characteristics`，`slot_skipped` 由推导结果算出（脚本无硬编码结论）。
- `tool/method_body.py`：EH 读器同时支持 fat（24 字节）与 small（12 字节，`u2/u2/u1/u2/u1/u4`）布局，由 kind 的 0x40 位选择，`MoreSects` 控制是否读；合成镜像测试 4 项全过。
- 控制项 14 条：body with EH yields a fat EHTable section=PASS；clause count equals (size-4)/entry=PASS；body without EH yields zero clauses=PASS；stray RVA rejected=PASS；non-executable RVA rejected=PASS；fat EHTable parsed=PASS；small EHTable parsed=PASS；MoreSects clear -> no EH section=PASS；inconsistent EH size rejected=PASS；jge target is the mov al,1 path=PASS；jge fall-through returns al=0=PASS；consumer skips on al==0=PASS；fixed .data slot is skipped by the gate=PASS；0x21A4 single read sits on the positive branch=PASS

## 4. 计数

| 指标 | 值 |
| --- | --- |
| external / boundary / unresolved | 228 / 303 / 28 |
| 未决托管 / 原生 | 13 / 15 |

## 5. 指纹（两套命令）

```
python -B tool/gen_fingerprints_340.py --set receipt --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s29-fingerprints.json
python -B tool/gen_fingerprints_340.py --set round --base-head 88bbe3130f561d2cdd76b3652cfbc3ab3a901a23 --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s41-fingerprints.json
```

