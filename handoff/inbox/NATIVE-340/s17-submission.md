# NATIVE-340 s17 提交

- 分支：tietoumiao/native-340-s17（基于 tietoumiao/native-340-s13 @ b16fc9e）
- head：见 #13
- 判定：`python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <固定原件> --submission handoff/inbox/NATIVE-340` → exit 2（已申报未决，非失败）

## 一句话结论

上游 126 行 fixup 映射表**逐址 126/126 对得上原件**（site→槽→token→MethodDef RVA/名字全字段一致），
122 个缺失桩已补进原生汇编/调用表，126 条 native→managed 边全部登记为 boundary；237 槽统计单列，不与 126 混算。

## 三层（成因 / 流程修正 / 自证）

# 成因
上一轮把「VTableFixups 目标」当成需要从原件结构推导的量，于是只能给出 237 条 entry / 122 个不同 token，
与卡面 126 对不上；实际 126 是**边数**：.nep 里每个 `jmp qword ptr [fixup slot]` 桩 → 槽 → MethodDef 的一条映射，
上游 s5 构建已经枚举过，本轮拿到表后即可逐行落表，不需要猜。另一半成因是 s9 重建清单时 Ghidra 只保留了 18 个 .nep 桩
（其中 4 个命中该表），其余 122 个桩在清单里消失，导致边没有落点。

# 流程修正
- tool/audit_340_s17.py：先回读原件校验每一行（site 解码必须是 jmp/call [rip+disp32] 且目标＝slot；slot 必须命中 VTableFixups
  条目且 Type＝flags；槽值必须＝method_token；token 必须是 MethodDef 且 RVA/名字一致），任何一项不符只入表标 FAIL，绝不登记为 boundary。
- 122 个缺失桩按原件字节补成 code/native-fixup-sites.asm（每条 jmp 一行）+ code/native-fixup-sites.c（可编辑桩），
  同步 native-functions.csv / coverage.csv 各 122 行；4 个已在清单里的桩就地复用原行。
- 16 个外部 newobj 按 IL 偏移 + 目标补入主表（code/newobj-sites.il），5 个本模块 .ctor 仍留在 code/newobj.csv。
- 0x3660 恢复 GS 与间接加载语义（native.asm 文本补全操作数，native.c 换回 `__readgsqword(0x30)` + [peb+8] 间接加载），
  行数保持不变，既有行号引用全部不失效。
- metrics.json 由脚本重算（不再手填）。

# 自证
- 126/126 逐址通过；失败行 0。native_asm_line 列与本轮清单一行为 0 行一致（4 行行号偏移、122 行无该地址）——
  该列属于 #393 的构建，行号不可跨构建复用，本轮按 site RVA 重落。
- 122 个 missing 之后 calls.csv 从 310 行升到 448 行；boundary 187（61 旧 + 126 新）、external 226（210 + 16 新）、
  unresolved 35（39 - 4 升级）；coverage 999 行、native-functions 248 行（126 分析器函数 + 122 分发桩），
  run.json native_reported_count 同步 248。
- 237 槽统计保持单列（metrics.vtable_fixup_slots=237），126 边单列（metrics.fixup_edges=126）。
- 检查器原始输出见下；退出码为真实退出码（未用管道取值）。

## 本轮实跑指标（脚本生成）

| 指标 | 值 |
| --- | --- |
| fixup 表行 / 逐址通过 | 126 / 126 |
| 补齐分发桩 | 122 |
| native→managed 边（boundary） | 126（4 升级 + 122 新增） |
| calls.csv 行 | 448（external 226 / boundary 187 / unresolved 35） |
| coverage 行 | 999 |
| native-functions 行 | 248（126 + 122） |
| VTableFixups 槽（单列） | 237 |
| newobj（外部边补入 / 内部保留） | 16 / 5 |
| 非空 TypeDef | 19（不变） |
| 旧跨界边 | 61（不变） |
| 检查器 exit | 2 |

## 判定命令与原始输出

```
$ python -B out/localrepo3/handoff/assignments/check-native-coverage.py NATIVE-340 --original _t13/orig/WrapSaveMergeNNFiles.dll --submission handoff/inbox/NATIVE-340
checked 999 coverage rows, 248 tool-native entries, 448 call records, 0 declared gaps
exit code: 2
```

## 产物

code/fixup-targets.csv（126 行，含 line_state/verdict）、code/native-fixup-sites.asm（368 行）、
code/native-fixup-sites.c（978 行）、code/newobj-sites.il（50 行）、code/s17-audit.md、
更新后的 calls.csv / coverage.csv / native-functions.csv / metrics.json / run.json、
code/native.asm（0x3660 操作数补全）。全部 < 1 MB；新增产物无逆向工具署名。

复现：`python -B tool/audit_340_s17.py --apply` → `python -B tool/render_340_s17.py` → 上面的判定命令。
