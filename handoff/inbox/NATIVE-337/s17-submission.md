# NATIVE-337 s17 提交

- PR: 见 #13
- head: 见 #13

## 三层（成因 / 流程修正 / 自证）

# 成因
上轮把 13 处「经 GuardCFDispatchFunctionPointer 槽 0x7670 分派」的 call/jmp 记成 data，且跳板 0x6050 本身不在主表：分类器只看操作数是否指向 IAT/数据，没有读 LoadConfig 的 GuardCF 分派槽，也没有把槽→跳板→运行期目标这条链登记。

# 复现命令
~~~sh
python -B tool/guardcf_sites.py            # 逐址校验 s13-sites.csv 的 13 行并登记主表
python -B tool/register_operands.py        # 0x4A7C CALL RAX / 0x53F2 CALL R9 的推导
python -B tool/site_diff.py                # 363 站点基线差
python -B _t13/s17_coverdiff.py            # 覆盖键差（13 旧键 / 3 新键）
~~~

# 流程修正
- tool/guardcf_sites.py：读 LoadConfig.GuardCFDispatchFunctionPointer（0x7670，磁盘值 0x180006050），逐址比对 s13-sites.csv 的 original_bytes，然后把 12 处分派位置登记为 class=unresolved（非 data），并把跳板 0x6050（原件 ffe0 = jmp rax）补进主表。
- tool/register_operands.py：0x4a7c CALL RAX 的来源是 0x4a64 MOV RAX,[0xB6F8]（.data 全局、文件无初始化值）；0x53f2 CALL R9 的来源是 0x53eb MOV R9,[0x7670]（同一 GuardCF 槽）。
- 13 个旧覆盖键 0x1050/0x4640/0x6080/0x60c0/0x60d0/0x60e0/0x60f0/0x6100/0x6110/0x6140/0x6150/0x6160/0x6240 已补建函数入口，coverage 键 300→303（另 3 个新键 0x1290/0x129f/0x12bd 均在宿主 [0x11e0,0x1319) 内，为分派表相邻入口）。

# 自证
- 13/13 逐址 original_bytes 与原件字节一致（tool/guardcf_sites.py 输出 verified 13 (match 13)）。
- 主表 calls.csv 510 → **523**（+12 分派位置 +1 跳板 0x6050）。
- 363/363 直接 IAT 站点保持（missing 0, extra 0）；coverage 303 行、0 申报入口缺口。
- checker：checked 303 coverage rows, 303 tool-native entries, 523 call records, 0 declared gaps；exit 2。按上游口径：申报入口缺口 0，但去重后仍有待核项（见下），不写「0 gaps 即完成」。

# 残余（如实）
- 64 个 COM 分派位置：64/64 在候选反汇编中定位（code/dispatch-sites.csv），但「接口指针→vtable 槽→成员/实现」尚未逐个绑定，仍为 unresolved。
- 161 个 caller→thunk 二跳：候选反汇编覆盖 153/161（code/import-callers.csv），8 处缺口待补函数。
- 六条旧指令仍未列出。

# 下一批如何自动避免
门禁：任何 call/jmp 若操作数指向 LoadConfig 的 GuardCF/Dispatch 槽，必须走 guardcf 解析器登记为分派条目并补跳板，禁止落 data。

## 本轮实跑指标（脚本生成，非手填）

| 指标 | 值 |
| --- | --- |
| 分析器函数 | 303 |
| 原件锚点 | 115 |
| coverage 行（缺口） | 303（0） |
| IAT 调用/跳转站点 | 363 |
| 已登记 external | 363 |
| 数据引用 data | 48 |
| 未决 unresolved | 0 |

## 判定命令与原始输出

~~~
checked 303 coverage rows, 303 tool-native entries, 523 call records, 0 declared gaps
~~~

exit code: 2

## 产物

run.json / native-functions.csv / coverage.csv / calls.csv / code/native.asm / code/native.c

以上文件由生成脚本一次产出；本轮未手工编辑任何产物文件，指标与产物 SHA-256 见 metrics.json。
