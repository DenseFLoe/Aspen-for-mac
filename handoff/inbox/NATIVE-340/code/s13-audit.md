# NATIVE-340 s13 逐项核对（脚本生成，勿手改）

原件 SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec，107048 字节。所有计数由 tool/audit_340_s13.py 从原件字节读表得到。

## 1. CLR VTableFixups

- CLI header 的 VTableFixups 字段（+0x30）＝ 0x16600/0x768；PE data directory 15 ＝ 0x0/0x0。
- 解析 237 条 {RVA, Count, Type}，全部 Type 含宽度位（0x1＝4 字节 / 0x2＝8 字节），非法项 0。
- 槽位总数 237，解析到 122 个不同 MethodDef token，0 个槽落在 MethodDef 表外。
  - Type 0x2：115 条 entry，115 个不同 token
  - Type 0xA：122 条 entry，122 个不同 token
- 与卡上 126 个目标的差异：未能复现 126。可复现的数字是 237 条 entry / 237 槽 / 122 个不同 token（0x6000001–0x60000a4，全部落在 MethodDef 表内）。122+4 只是数值巧合，不能当依据；请上游给出 126 的取数口径（是否含 CFG 守卫间接转移，或按截断前的 244 entry 计）。

## 2. IL newobj

- 共 21 处操作码 0x73：external-ctor 16（token 表 0x0A MemberRef → TypeRef/TypeSpec），internal-ctor 5（token 表 0x06 MethodDef → 本模块 TypeDef）。
- 卡上 16 个 newobj ＝ 其中 external-ctor 的 16 处，已逐址对齐；另有 5 处 internal-ctor，上一轮未单列，本轮一并进表（code/newobj.csv）。

## 3. 非空 TypeDef 的 MethodList 范围

- 非空 TypeDef 19 个，MethodList 区间合计覆盖 188/188 个 MethodDef，无重叠无遗漏：True。
- 逐项区间见 code/typedef-ranges.csv。

## 4. 间接转移

- 原生清单内 call/jmp 共 214 条，其中间接操作数 72 条：IAT 48、CFG 守卫指针 10、vtable 槽 9、寄存器 5。
- 间接转移登记：s9 附件 19 条 + 本轮补登 20 条 = 39 条，全部同时出现在 calls.csv 主表（class=unresolved，逐行带恢复条件）与 code/indirect.csv 附件；明细 code/indirect-native.csv。
- 本轮补登明细：CFG 守卫指针 10 条、寄存器 1 条、vtable 槽 9 条（合计 20）。
- 卡上 11 处其他间接转移对应 CFG 守卫族（10 条 call/jmp [0x1800061B8] + 1 条 jmp rax，全部落在 _guard_dispatch_icall 0x48B0）；另一读法（9 条 vtable 槽 jmp + 2）也已全部登记。

## 5. 0x3660 两次加载

- CLI 视图：MethodDef 0x06000085 flavor=native RVA 0x3660；清 COM 视图（data directory 14 置零的副本）把同一 RVA 当原生代码，code/native.asm 有 FUNC 头与 14 字节。
- 两视图在 RVA 0x3660 的 14 字节完全相同：65488b042530000000488b4008c3（code/loads-3660.csv）。

## 6. 附件逐址校验

- code/indirect.csv 现有 39 行；s9 交付的 19 行全部在 calls.csv 主表可对上：39/39。
- 逐行结论见 code/attachment-check.csv（含每条已核实目标或未决依据）。

## 负向对照（18 项，失败项：无）

- PASS：zeroed entries yield 0 targets
- PASS：out-of-image slot RVA rejected
- PASS：type 0 rejected
- PASS：TypeRef token not a target
- PASS：count 0 rejected
- PASS：MethodDef token resolves (positive control)
- PASS：opcode 0x28 call is not newobj
- PASS：non-.ctor MethodDef rejected
- PASS：non-.ctor MemberRef rejected
- PASS：out-of-range token unresolved
- PASS：TypeRef token unresolved
- PASS：TypeDef ranges cover every MethodDef exactly once
- PASS：only non-empty TypeDefs listed
- PASS：0x3660 bytes identical in both views
- PASS：cleared copy differs only inside the CLI directory entry
- PASS：0x3660 is a native MethodDef in the CLI view
- PASS：0x3660 is not a newobj/calli site owner
- PASS：every attachment row is registered in calls.csv

