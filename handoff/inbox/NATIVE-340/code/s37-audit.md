# NATIVE-340 s37 逐项核对（脚本生成）

基线：#450 head `e8fb4cbcbcbbd5a5020a7ac7a3209a42d80f364d`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 生成器修正（读 MethodDef RVA 与 EH 数据节）

- 旧：EH 子句数取自 fat header 的 `flags >> 8`（0x06000032 得到 48），且按文件偏移对齐、直接把 EH 节头当第一条子句读。
- 新：`tool/method_body.py` 按 fat header 的 Size 半字节取头长，按 RVA 4 对齐到 IL 之后，读 EH 节头（kind byte：0x01 EHTable | 0x40 fat；3 字节 data size），子句数 = (size-4)/entry，并校验节归属与可执行性。
- 控制项：body with EH yields a fat EHTable section=PASS；clause count equals (size-4)/entry=PASS；body without EH yields zero clauses=PASS；stray RVA rejected=PASS；non-executable RVA rejected=PASS

## 2. 0x06000032（验证用例）

| 项 | 实测 |
| --- | --- |
| MethodDef RVA | `0x3524` |
| 方法头 | fat，12 字节，code 54 字节，flags `0xB`（MoreSects） |
| EH 节 | RVA `0x3568`，kind `0x41`（fat EHTable），size 28 |
| 子句数 | 1（finally，Flags=0x2） |
| try | IL_000F-IL_0025（0xF/0x16） |
| handler | IL_0025-IL_002C（0x25/0x7） |
| ClassToken | `0x01000046` |

注：上一版回执写的 `0x1B28` 不是本方法的方法体 RVA，也不是 EH 节 RVA（该地址无方法头、无 EH 节头）；本轮以生成器输出为准：方法体 `0x3524`、EH 节 `0x3568`。

## 3. 0x218D / 0x2874 / 0x2197

- `0x218D` `48 8B C8` = mov rcx, rax：把槽地址（0x29D0 的 LEA 返回值）作为 arg0 传给 0x2874。
- `0x2874`：走 PE 头定位该地址所在节（R8=地址，RDX=节头），`0x28F3` `83 7A 24 00` = cmp dword ptr [rdx+0x24],0 对 Characteristics 做有符号测试，`0x28F7` `7D 04` = jge：符号位清（不可写）→ al=0；符号位置位（IMAGE_SCN_MEM_WRITE=0x80000000，可写）→ al=1。
- `0x2197`：`0x2195` `84 C0` test al,al + `74 18` jz 0x21B1 ⇒ al==0（不可写）才跳过；极性＝可写才调用。固定槽 `0x19B78` 在 .data（Characteristics `0xC0000040`，符号位置位）→ 可写 → 走调用。
- `0x21A4` 的 `mov rax,[rbx]` 只在正分支（0x2199 起）执行一次，范围未扩大。

## 4. 计数

| 指标 | 值 |
| --- | --- |
| external / boundary / unresolved | 228 / 303 / 28 |
| 未决托管 / 原生 | 13 / 15 |
| 237 槽 / 122 MethodDef / 228 回编桩 | 沿用 |

