# NATIVE-340 s37 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ e8fb4cbcbcbbd5a5020a7ac7a3209a42d80f364d
- 本轮 head：见 #13
- 判定（两条都跑，真实退出码）：
  - python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340 → exit 2
  - pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original <原件> -Unit handoff/inbox/NATIVE-340 → exit 0

## 1. 生成器修正（根因）

旧 `tool/audit_340_s33.py` 的 `method_body()` 有两处读法错误：

1. **EH 子句数当成了 fat header 的 `flags >> 8`**。0x06000032 的 header flags = 0x300b，右移得 0x30 = 48 条——上一版审计页就这么写的。真值是 1 条。
2. **EH 数据节没有按节读**：直接在 IL 之后按文件偏移对齐读 24 字节子句，把 EH 节头（kind 0x41 + 3 字节 size）当成第一条子句；头长也写死 12 字节，而不是用 fat header 的 Size 半字节。

新 `tool/method_body.py`：

- 头长取 `(header>>12)&0xF` 个 dword；
- 按 **RVA** 4 对齐到 IL 之后（不是文件偏移）；
- 读 EH 节头：kind byte 低 6 位必须 0x01（EHTable）、0x40 = fat；3 字节 data size；子句数 = (size-4)/entry（fat 24 字节 / small 12 字节）；
- 校验 MethodDef RVA 必须落在可执行节，且 body+EH 不越节；节跨度用 max(SizeOfRawData, VirtualSize)（.data 零填充尾部由此可寻址）。

控制项 5 条全过（含「无 EH 的方法必须 0 条」「越界 RVA 必须拒」「非可执行 RVA 必须拒」）。

## 2. 0x06000032 验证

| 项 | 实测 |
| --- | --- |
| MethodDef RVA | `0x3524`（fat，12 字节头，code 54 字节，flags 0xB MoreSects） |
| EH 节 | RVA `0x3568`，kind `0x41`（fat EHTable），size 28 |
| 子句数 | **1**（finally，Flags=0x2） |
| try | IL_000F–IL_0025（0xF/0x16） |
| handler | **IL_0025–IL_002C**（0x25/0x7） |
| ClassToken | `0x01000046` |

上一版回执写的 `0x1B28` 不是本方法的方法体 RVA、也不是 EH 节 RVA：该地址没有方法头（无 0x3 低两位的 fat 头）、也没有 EH 节头（kind 不为 0x41/0x01），且没有任何 MethodDef 的 RVA 等于它。本轮以生成器输出为准。

## 3. 三处指令语义（按原件字节）

- `0x218D` `48 8B C8` = **mov rcx, rax**：把槽地址（0x29D0 的 LEA 返回值 0x19B78）作为 arg0 传给 0x2874。
- `0x2874`：用 PE 头定位该地址所在节（R8=地址，RDX=节头）；`0x28F3` `83 7A 24 00` = cmp dword ptr [rdx+0x24],0 是**有符号**测试，`0x28F7` `7D 04` = jge：符号位清（不可写）→ al=0；符号位置位（IMAGE_SCN_MEM_WRITE 0x80000000，可写）→ al=1。
- `0x2197` `74 18` = jz 0x21B1，配合 `0x2195` `84 C0` test al,al ⇒ **al==0（不可写）才跳过**；极性 = 可写才调用。固定槽 `0x19B78` 在 .data（Characteristics `0xC0000040`，符号位置位）⇒ 可写 ⇒ 走调用。
- `0x21A4` `mov rax,[rbx]` 只在正分支（0x2199 起）执行一次，范围未扩大。

## 4. 重生成

- 主表 calls.csv 559 行：external 228 / boundary 303 / unresolved 28（托管 13 + 原生 15，附表由主表生成：code/s37-unresolved-*.csv）。
- 审计页 code/s37-audit.md（脚本生成）；回执指纹 code/s37-fingerprints.json 在审计页定稿后生成；
  上游脚本按路径读 code/s29-fingerprints.json（本轮已用同一批文件的新哈希刷新，旧回执留在 code/s33-fingerprints.json）。
- metrics.json 新增 s37_* 字段；run.json 记 s37_base_head = #450。

## 5. 逐项比对（上游脚本输出）

`original_callback`: bytes_217f / bytes_21a4 / bytes_28f3 / callback_slot 0x19B78 / writable_section .data /
flags 0xC0000040 / raw_end 0x19A00 / virtual_end 0x19B80 / guards（0x2187/0x218B null、0x2190→0x2874 测试、0x2197 跳过）/
transfer（0x21A4 单次读、0x21AE call R9→0x48B0 JMP RAX）。
候选字段：calls 559、boundary 303、external 228、managed 13、native 15、ctor rows 5、fingerprint 58 / mismatches 0。

复现：`python -B tool/audit_340_s37.py` → `python -B _t14/refresh_fp.py`（刷新 s29-fingerprints.json）→ 两条判定命令。
