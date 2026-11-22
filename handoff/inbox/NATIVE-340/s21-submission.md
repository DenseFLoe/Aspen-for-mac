# NATIVE-340 s21 提交

- 分支：tietoumiao/native-340-s21（基于 #430 / tietoumiao/native-340-s17 @ 5671a75）
- head：见 #13
- 判定：```sh
  python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <固定原件> --submission handoff/inbox/NATIVE-340
  checked 1105 coverage rows, 354 tool-native entries, 554 call records, 0 declared gaps
  exit code: 2
  ```

## 一句话结论

上游 111 条逐址证据**逐址 111/111 全部对上原件**（106 漏登、5 未决）；106 条漏登已进主表，5 条未决升级为 boundary；
122 个空 C 桩改成 naked 间接尾跳实现，**回编 122/122 通过**（另 106 个新桩同样 106/106 通过）；0x0a000019 的 TypeSpec
属主补为 [System]System.Collections.Generic.LinkedList<System.Object>。

## 三层（成因 / 流程修正 / 自证）

# 成因
s17 只落了上游给的 126 条边，把 .nep 当成「每个 site 一个函数」，因而漏掉同一 16 字节块里另一条带直接前驱的槽跳转
（0x5000 的 EB 08 落到 0x500A，后者才是另一张 vtable 的入口）；同时 s17 的 C 桩只有注释、函数体为空，回编后是
「立刻返回」，与原件尾跳语义不符。

# 流程修正
- tool/audit_340_s21.py：对 111 条证据逐项回读原件（指令字节、jmp 目标、slot 的 Type/槽值、MethodDef RVA），并从
  .nep 原始字节恢复每条的直接前驱（EB 08）。不匹配只标 FAIL，不进主表。
- 106 条补成 code/native-fixup-sites-s21.asm（逐条 jmp 一行）+ .c（可编辑桩），native-functions / coverage 各 +106；
  5 条未决就地升级为 boundary（callee 带槽 RVA + token + MethodDef RVA）。
- code/native-fixup-sites.c 重写为 naked 尾跳实现；tool/verify_stubs_340.py 解析 AMD64 COFF，逐符号校验
  「6 字节 FF 25 + 指令+2 处 REL32 重定位指向该槽符号」，并把对象 SHA-256 记进 code/recompile-verify.json。
- cli_tables 补 TypeSpec 签名解析（含 ResolutionScope 与 TypeDefOrRef 是两种编码的修正），il_newobj 用它解出
  0x0a000019 的属主；0x3660 的 PEB 措辞改为寄存器/地址语义。

# 自证
- 111/111 逐址通过、0 失败；前驱全为 EB 08（111/111），逐条 predecessor_rva/bytes 见 code/s21-extra-sites.csv。
- 回编：code/native-fixup-sites.c（122 桩）与 code/native-fixup-sites-s21.c（106 桩）经 zig cc 编译，
  COFF 校验 122/122、106/106 通过，0 失败。
- 三个量分开：原件槽跳转 237（126+111 全部进表）、不同 MethodDef 122、运行期落点静态未定（0）。
- 126 条已核定边与 61 条旧边未改动。

## 本轮实跑指标（脚本生成）

| 指标 | 值 |
| --- | --- |
| 上游 111 条逐址通过 | 111 / 111 |
| 漏登补入 / 未决升级 | 106 / 5 |
| 122 桩回编 | 122 / 122 |
| 106 新桩回编 | 106 / 106 |
| calls.csv | 554（external 226 / boundary 298 / unresolved 30） |
| coverage.csv | 1105 |
| native-functions.csv | 354 |
| 槽跳转 / 不同 MethodDef / 运行期落点 | 237 / 122 / 未定 |
| 检查器 exit | 2 |

## 产物

code/s21-extra-sites.csv（111 行，含前驱证据）、code/native-fixup-sites-s21.asm/.c（106）、
code/native-fixup-sites.c（122，naked 尾跳）、code/recompile-verify.json（逐桩回编结果）、code/s21-audit.md、
code/newobj.csv（TypeSpec 属主修正）、更新后的 calls.csv / coverage.csv / native-functions.csv / metrics.json / run.json。

复现：`python -B tool/audit_340_s21.py --apply` → `python -B tool/render_340_s21.py` → 判定命令。
