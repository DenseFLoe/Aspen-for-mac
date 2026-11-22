# NATIVE-340 s41 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ 88bbe3130f561d2cdd76b3652cfbc3ab3a901a23
- 本轮 head：见 #13
- 保留：#450 的 237 槽跳转 / 122 MethodDef / 228 回编桩 / MethodDef RVA 0x3524 / EH RVA 0x3568 / finally 范围

## 1. jge 的两条分支（由原件字节解出，非硬编码）

| 指令 | 地址 | 去向 | 返回值 |
| --- | --- | --- | --- |
| `cmp dword ptr [rdx+0x24],0` | 0x28F3 | 判据：节 Characteristics（+0x24） | — |
| `jge` | 0x28F7 | **取：0x28FD**（`mov al,1`） | **al=1**（signed ≥ 0 ⇒ 符号位清 ⇒ 不可写） |
| 落空 | 0x28F9 | `xor al,al` → `jmp 0x2907` | **al=0**（signed < 0 ⇒ 符号位置位 ⇒ 可写） |

消费端：`0x2195 test al,al` + `0x2197 jz 0x21B1` ⇒ **al==0 才跳到 0x21B1（跳过 0x2199–0x21B0）**；al!=0 才落入正分支。

## 2. 固定 .data 槽被门禁跳过 + 0x21A4 的分支

- 固定槽 `0x19B78` ∈ `.data`，Characteristics `0xC0000040`（signed 负、可写）⇒ `jge` 落空 ⇒ al=0 ⇒ `jz` 取跳 ⇒ **节门禁跳过**。
- 因此 `0x21A4 mov rax,[rbx]`（单次读取）与 `0x21AE call r9` 只在 **0x2199–0x21B0 这一支（非可写节）**；本映像里该支不可达（除非运行期改节保护）。上一版「可写→走调用」是反的，已更正。
- 空槽判定仍在 `0x2187/0x218B`；`0x218D mov rcx,rax` 传槽地址给 `0x2874`。

## 3. 生成器从原件提取

- `tool/x86_340.py`：解码 `cmp/jcc/xor al/mov al/test al/jz`，从字节得到 jcc 目标/落空地址、两分支的 al 返回值、`IMAGE_SECTION_HEADER.Characteristics`，`slot_skipped` 由「signed 判据结果 + 消费端条件」推导，脚本内没有 jge/al 的字面结论。
- 控制项（14 条）含：jge 目标=mov al,1 路径、落空返回 0、消费端 al==0 跳过、固定 .data 槽被跳过、0x21A4 位于正分支。

## 4. EH 读器：small + fat

- `tool/method_body.py` 按 kind 的 0x40 位选择布局：fat 子句 24 字节，small 子句按 ECMA-335 II.25.4.6 为 `u2 flags/u2 tryOff/u1 tryLen/u2 handlerOff/u1 handlerLen/u4 classToken` = 12 字节；`MoreSects`(flags&0x8) 控制是否读 EH 节，size 必须恰好容纳整数条子句。
- 合成镜像测试：fat 解析、small 解析、MoreSects 清空、size 不一致拒绝，4/4 PASS；真件 5 项控制亦 PASS。

## 5. 两套指纹命令（可从固定提交直接跑）

```
python -B tool/gen_fingerprints_340.py --set receipt --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s29-fingerprints.json
python -B tool/gen_fingerprints_340.py --set round --base-head 88bbe3130f561d2cdd76b3652cfbc3ab3a901a23 --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s41-fingerprints.json
```

实际输出：

```
receipt: 45 files -> handoff/inbox/NATIVE-340/code/s29-fingerprints.json
round: 65 files -> handoff/inbox/NATIVE-340/code/s41-fingerprints.json
```

- `s29-fingerprints.json` 是上游脚本读取的**扁平** {path: sha256} 映射（旧格式，保持兼容）；`s41-fingerprints.json` 是当轮回执（含 base_head / count / files）。旧 `s37-fingerprints.json`、`s33-fingerprints.json` 保留为历史。

## 6. 逐项对照（上游脚本输出）

- `original_callback`：bytes_217f / bytes_21a4 / bytes_28f3 / callback_slot 0x19B78 / writable_section .data / flags 0xC0000040 / raw_end 0x19A00 / virtual_end 0x19B80 / guards / transfer —— 与本轮 calls.csv 第 288 行 note 逐项一致。
- 候选：calls 559、boundary 303、external 228、managed 13、native 15、ctor rows 5、fingerprint 45 / mismatches 0。

## 7. 判定（真实退出码）

```
$ python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340
checked 1105 coverage rows, 354 tool-native entries, 559 call records, 0 declared gaps
exit code: 2

$ pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original <原件> -Unit handoff/inbox/NATIVE-340
exit code: 0   (fingerprint 45 / mismatches 0)
```
