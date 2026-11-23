# NATIVE-337 s77 提交（0x2330 初始化链 + 分类器自算站集）

- 固定候选：#445 @ d4076c4；同一分支 head 前移。

## A. 0x2330 初始化链（按原件逐条）
| 位置 | 指令 | IAT 槽 | 库 | 符号 |
| --- | --- | --- | --- | --- |
| 0x2388 | `CALL qword ptr [0x180007050]` | 0x7050 | KERNEL32.dll | MultiByteToWideChar |
| 0x23A0 | `CALL qword ptr [0x180007648]` | 0x7648 | ole32.dll | CLSIDFromProgID |
| 0x23C8 | `CALL qword ptr [0x180007650]` | 0x7650 | ole32.dll | CoCreateInstance |

- **IID**：0x23B4 `LEA R9,[rip+0x5F4D]` → 0x8308，内容 `00040200 0000 0000 c000 000000000046` = **IID_IDispatch {00020400-0000-0000-C000-000000000046}**。
- **输出指针**：0x23AC `MOV [RBP],RDI`（清零）→ 0x23B0 `LEA RAX,[RBP]` → 0x23BB `MOV [RSP+0x20],RAX`，即 CoCreateInstance 的 ppv 指向 [RBP]。
- **返回路径**：0x23CE `TEST EAX`；失败 0x23D0 `JS 0x23D8` → `XOR EAX,EAX`（返回 NULL）；成功 0x23D2 `MOV RAX,[RBP]`（接口指针）→ 0x23D6 JMP → 返回。

### 0x133D 的 RDI 来源（更正上一轮）
- 0x1338 `CALL 0x180002330` 返回指针在 RAX；**0x133D `MOV RDI,RAX`** 才写入 RDI。
- 0x1340 `TEST RAX` + 0x1343 `JZ 0x1399`：工厂失败（RAX=0）时不进入 RDI 使用路径。
- 因此 RDI = 工厂返回的接口指针（成功时）/ 未定义（失败分支不走）；上一轮把 0x2388 说成 CoCreateInstance 是错的，0x2388 是 MultiByteToWideChar，CoCreateInstance 在 0x23C8。

四条调用记录仍为 0x1389/0x28、0x1396/0x10、0x1444/0x30、0x1457/0x10，附表已更新 init_path/init_evidence 两列（`code/s73-four-calls.csv`）。

## B. 分类器不再读缓存站表
- `tool/s65_counterexamples.py` 每次运行都调用 `s73_stations.derive(原件)` 重新算 161 站；`--stations` 变成可选：给了缓存表就逐字节核对，不一致直接拒绝（`cached station table does not match the fresh derivation`）。
- 配对实验 `tool/s77_tests.py`：同一缺站清单（删 0x106C 指令）跑两次——完整表 → 仍报 missing-listing 0x106C；删掉该行并重算指纹的表 → 退出非 0 并报缓存表与重算不符。两次都不放过。

## C. 保持
- 三布局 161 站 / 0x106C→525 / 0x12DA→528（s45_tests.py E/F）。
- 五组反例 T1–T5、配对实验 PASS。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条未决已申报）

## 指纹
- 见 work/s77-tools.txt（本轮从实际文件生成）
