# NATIVE-340 s17 逐项核对（脚本生成，勿手改）

上游给的 out/s5-native-fixup-targets.csv（126 行）逐行回读原件校验，再由 tool/audit_340_s17.py 落表。

## 1. 126 行 vs 原件（逐址）

- 逐址校验项：site 指令必须解成 jmp/call qword ptr [rip+disp32] 且目标＝slot；slot 必须是 CLI VTableFixups 条目且 Type＝flags；槽值必须＝method_token；token 必须是 MethodDef 且 RVA/名字一致。
- 126/126 全部通过，0 行对不上；失败行：无。
- native_asm_line 列与本轮清单：0 行行号一致（4 行行号偏移、122 行当前清单无该地址）。该列来自 #393（s5 构建）的清单，行号不可跨构建复用；本轮按 site RVA 重新落 code/native-fixup-sites.asm。
- token 复用的 4 条（同一 MethodDef 两个槽/两个 site）：0x06000020 <- 0x50a4,0x50aa；0x06000004 <- 0x50c4,0x50ca；0x06000005 <- 0x5114,0x511a；0x06000007 <- 0x5124,0x512a

## 2. 122 个缺失位置

- 126 行中 4 行（0x50aa, 0x50ca, 0x511a, 0x512a）已在既有原生清单里，其余 122 行按原件字节补成 code/native-fixup-sites.asm 桩 + code/native-fixup-sites.c 实现 + native-functions / coverage 各 122 行。
- 122 个桩全部是 jmp qword ptr [fixup slot]，槽内静态值是 MethodDef token，槽由 CLR 加载器改写。

## 3. 126 条 native -> managed 边

- 全部登记进 calls.csv：class=boundary，callee 带槽 RVA + token + MethodDef RVA，note 带运行期待核条件。
- 4 条原 unresolved 行就地升级为 boundary（槽/token/RVA 补全），另 122 条新增。

## 4. 237 槽统计（与 126 分开）

- CLI VTableFixups 仍是 237 条 entry / 237 槽 / 122 个不同 MethodDef token（code/vtable-fixups.csv，s13 产物保持）。
- 126 是「.nep 桩 -> 槽 -> 方法」的边数，只是 237 槽的一个子集（115 条 Type 0x2 + 11 条 Type 0xA），两者不混算。

## 5. newobj

- 16 个外部 ctor 边按 IL 行号 + 目标补入主表（code/newobj-sites.il），Caller 为所属 MethodDef。
- 5 个本模块构造调用（MethodDef .ctor）保留在 code/newobj.csv，未混入外部边。

## 6. 保留项

- 19 个非空 TypeDef 的 MethodList 范围不变（code/typedef-ranges.csv）。
- 旧 61 条跨界边原样保留，boundary 现为 187 = 61 旧 + 126 新。

## 7. 0x3660

- 恢复 GS 与间接加载语义：mov rax, qword ptr GS:[0x30] -> mov rax, qword ptr [RAX+0x8] -> ret；native.c 同步为 __readgsqword(0x30) + [peb+8] 间接加载（行数不变，既有行号引用不失效）。

## 8. 当前计数

| 指标 | 值 |
| --- | --- |
| rows | 999 |
| funcs | 248 |
| external | 226 |
| boundary | 187 |
| unresolved | 35 |
| gaps | 0 |
| vtable_fixup_slots | 237 |
| vtable_fixup_distinct_targets | 122 |
| fixup_edges | 126 |
| fixup_edges_ok | 126 |

calls 行数：448（external 226 / boundary 187 / unresolved 35）。
