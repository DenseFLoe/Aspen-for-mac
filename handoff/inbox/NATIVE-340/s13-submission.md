# NATIVE-340 s13 提交

- 起点：PR #393 的 a0b8a11853f70d32870b9d0aa15267572c1ffb0a；本轮 assigned_seq=13。
- 原件：issue-materials/340/WrapSaveMergeNNFiles.dll，107,048 字节，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。
- 检查器：out/localrepo3/handoff/assignments/check-native-coverage.py，SHA-256 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8。

## 三层（成因 / 流程修正 / 自证）

# 成因
s9 只覆盖「IL call 操作数 token → MethodDef」这一条链，CLR VTableFixups、IL newobj、原生侧 call/jmp [指针] 三处没有读表入口：VTableFixups 只在 CLI header（+0x30），PE data directory 15 是 0/0，沿用「读目录 15」的解析器只能得 0 条，卡上 126 个目标无从核对；newobj 从未按 token 落表；原生侧 20 处间接转移（10 处 CFG 守卫指针 + 1 处 jmp rax + 9 处 vtable 槽）既不在 calls.csv 也不在附件里。

# 流程修正
- tool/cli_tables.py：按 ECMA-335 II.22 全表行宽解码（表 0..44）；MemberRefParent 用 3 位、HasFieldMarshal/HasSemantics/MethodDefOrRef/HasSemantics 用 1 位，逐项按规范，不再统一 2 位。
- tool/cli_vtable.py：同时读 CLI header VTableFixups 与 data directory 15，不一致时报差异而不静默取其一；Type 位按 1=4 字节 / 2=8 字节定宽，槽值只在命中 MethodDef 时才算目标。
- tool/il_newobj.py：0x73 操作数按 token 表分流（MethodDef → 本模块 ctor；MemberRef → Class coded index → TypeDef/TypeRef/TypeSpec），不读签名文本。
- tool/audit_340_s13.py：一次生成全部输出表 + 18 项负向对照；未登记的间接站点补进 calls.csv（class=unresolved，逐行恢复条件）与 code/indirect.csv 附件。

# 自证
- VTableFixups：237 条 entry / 237 槽 / 122 个不同 MethodDef token（Type 0xA 122 条、Type 0x2 115 条）；0 条越界、0 条落在 MethodDef 表外。卡上 126 无法复现，见「三档证据」。
- newobj：21 处 = external-ctor 16（卡上 16 与之对齐）+ internal-ctor 5（本轮新增登记）。
- TypeDef：非空 19 个，MethodList 区间合计覆盖 188/188 个 MethodDef，无重叠无遗漏。
- 间接转移：原生清单 call/jmp 214 条，间接操作数 72 条（IAT 48 / CFG 守卫指针 10 / vtable 槽 9 / 寄存器 5）；附件 39 条 = s9 的 19 + 本轮 20，逐条在主表可对上。
- 0x3660：CLI 视图 MethodDef 0x06000085 native；清 COM 视图同 RVA 14 字节完全相同（65488b042530000000488b4008c3），两视图仅 CLI 目录 3 字节不同。
- 61 条已核实跨界调用保留：calls.csv boundary=61。

## 三档证据

| 档 | 内容 |
| --- | --- |
| 已实测 | VTableFixups 237 entry / 122 个不同 token；newobj 21（16 外部 ctor + 5 内部 ctor）；非空 TypeDef 19（覆盖 188/188）；间接站点 72（48 IAT / 10 CFG / 9 vtable / 5 寄存器）；0x3660 两视图 14 字节一致；附件 39 行全部在主表 |
| 未验证 | 卡上「126 个 VTableFixups 目标」：按 CLI header 表实测 237 entry、122 个不同 token，无第三种取数能得 126；待上游给口径（是否并入 4 处寄存器间接转移，或按截断前的 244 entry 计） |
| 无法判定 | 9 处 vtable 槽 jmp 的运行期目标（槽内是 MethodDef token，加载器会改写成入口指针）；10 处 CFG 守卫调用与 1 处 jmp rax 的真实被调者（在 RAX，静态需寄存器溯源） |

## 判定命令与原始输出

~~~
$ python -B out/localrepo3/handoff/assignments/check-native-coverage.py NATIVE-340 \
      --original _t13/orig/WrapSaveMergeNNFiles.dll --submission handoff/inbox/NATIVE-340
checked 877 coverage rows, 126 tool-native entries, 310 call records, 0 declared gaps
exit code: 2
~~~

exit 2 = 结构齐备 + 已申报缺口 39 条（class=unresolved，逐行 note 与恢复条件）；check_indirect_attachment 未报缺失站点。

## 指标（脚本生成，非手填）

| 指标 | 值 |
| --- | --- |
| coverage 行 | 877 |
| native-functions 行 | 126 |
| calls.csv 行 | 310 |
| 其中 external / boundary / unresolved | 210 / 61 / 39 |
| indirect.csv 附件行 | 39 |
| 负向对照 | 18 项全过 |
| 检查器 exit | 2 |

## 产物

code/vtable-fixups.csv（237 行）、code/newobj.csv（21 行）、code/typedef-ranges.csv（19 行）、code/indirect-native.csv（72 行）、code/loads-3660.csv、code/attachment-check.csv（39 行）、code/s13-audit.md / code/s13-audit.json、更新后的 calls.csv（310 行）、code/indirect.csv（39 行）、run.json。全部文件 < 1 MB；本轮新增产物无逆向工具署名（工具名正则命中 0）。

复现：python -B tool/audit_340_s13.py --apply，再按上面命令跑检查器。
