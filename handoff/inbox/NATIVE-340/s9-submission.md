# NATIVE-340 s9 提交

- PR: 见 #13
- head: 见 #13

## 三层（成因 / 流程修正 / 自证）

# 成因
首轮把「签名文本里出现 [mscorlib]」当作外部程序集调用：mscorlib 只出现在 modopt(CallConv*) 这类调用约定修饰里，并不是调用目标。分类器没有读 IL call 指令的操作数 token，于是 12 条「调用本模块原生 MethodDef」的记录被误标 external；同时 native 侧的导入调用与 15 处 calli 没有任何登记入口。

# 复现命令
~~~sh
# 取原件、定位 0x06000001 方法体，打印 IL_0018 的操作码与 4 字节操作数
python -B tool/il_disasm.py --binary issue-materials/340/WrapSaveMergeNNFiles.dll --method 0x06000001
# 输出：IL_0018: call 0x06000084  __std_exception_copy  → 原生 MethodDef，RVA 0x476B
~~~

# 流程修正
- tool/il_disasm.py：按原件字节解码 IL（含 call/callvirt/calli 的 4 字节 token），不依赖任何符号文本。
- tool/gen_340_evidence.py：token 命中 MethodDef 表且 flavor=native → boundary（写 token+RVA）；calli → unresolved；native 侧导入调用按 PE 导入槽位扫描，间接转移逐址登记。
- 0x3660（0x06000085）不再留失败注释：14 字节原始指令手工解码并在 code/native.c 给出可编辑实现；计数固定为 188 = 167 IL + 19 原生 + 2 声明，native-functions 256 = 255 + 1 手工。

# 自证
- boundary 61 条：原 12 条误标 external 全部改判，逐条带 IL 偏移、操作码、token、目标 RVA；核定例子 methods.il L22（IL_0018、opcode 28、token 0x06000084 → 0x476B）与交付逐字段一致。
- 15/15 处 calli 与 4 处原生间接转移移入 code/indirect.csv（不属 calls.csv 四类）；native 侧 4 处 KERNEL32 导入调用落 L483/486/489/493。
- checker：877 coverage rows、126 tool-native、271 call records、0 declared gaps；exit 0。

# 下一批如何自动避免
门禁一条：混合件的 IL 调用分类只认「操作数 token 在 MethodDef 表里的 flavor」，禁止用签名文本、程序集名或 ImplMap 判定；calli/间接转移必须逐址落 unresolved。

## 本轮实跑指标（脚本生成，非手填）

| 指标 | 值 |
| --- | --- |
| 分析器函数 | 126 |
| 原件锚点 | 75 |
| coverage 行（缺口） | 877（0） |
| IAT 调用/跳转站点 | 48 |
| 已登记 external | 210 |
| 数据引用 data | 0 |
| 未决 unresolved | 0 |

## 判定命令与原始输出

~~~
checked 877 coverage rows, 126 tool-native entries, 271 call records, 0 declared gaps
~~~

exit code: 0

## 产物

run.json / native-functions.csv / coverage.csv / calls.csv / code/native.asm / code/native.c

以上文件由生成脚本一次产出；本轮未手工编辑任何产物文件，指标与产物 SHA-256 见 metrics.json。
