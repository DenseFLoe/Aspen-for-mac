# NATIVE-340 s5 提交（第五号事件续领）

- task_id: NATIVE-340　owner: tietoumiao　assigned_seq: 5
- 原件: issue-materials/340/WrapSaveMergeNNFiles.dll，107,048 字节，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec（本机复核一致）
- 首轮: PR #387 / head 62c68c514c8bcbe5435c6cbc2fcf570388a9a980。

## 逐项补正（对应 s1 裁定第 1–4 条）

1. **0x3660 / MethodDef 0x06000085**：不再只有失败注释。14 字节原始指令（65488b042530000000 488b4008 c3）手工解码，code/native.c L2275–L2280 给出可编辑实现（__readgsqword(0x30) 取 PEB，[+8] 取 ImageBaseAddress 返回），coverage 两行（RVA 0x3660 与 0x06000085）source 指向该实现。计数分开写明：**188 MethodDef = 167 IL 体 + 19 原生实现 + 2 无 RVA 声明**；native-functions.csv **256 项 = 分析器 255 + 手工补入 1（0x3660）**，run.json 的 scope/limitations 明列。
2. **12 处 external 误分类**：24 条旧调用记录改由原件 IL 字节重算——按 IL 偏移处操作码（0x28/0x6F/0x29）读 4 字节 token，MethodDef 表中的原生实现判为 boundary。原 12 条「mscorlib 修饰」external 现全部为 boundary。例：methods.il L22（IL_0018，操作码 28，token 0x06000084 → 原生 RVA 0x476B），与裁定所举例子逐字段一致。calls.csv 现 **boundary 61** 条，note 写 IL 偏移、原始操作码、token 与目标 RVA。
3. **native 侧外部调用 + calli**：native.asm 的 4 处 KERNEL32 导入调用逐址登记——L483 GetSystemTimeAsFileTime（RVA 0x241A）、L486 GetCurrentThreadId（0x2428）、L489 GetCurrentProcessId（0x2434）、L493 QueryPerformanceCounter（0x2444）；methods.il 的 **15/15 处 calli** 全部登记为 unresolved 并给恢复条件。calls.csv 合计 293 行 = 213 external + 61 boundary + 19 unresolved。
4. **类型成员归属**：563 个 TypeDef 全部解析 MethodList 并逐成员落到 code/types.cs（含 token/name/flavor/RVA 注释）。例 TypeDef 0x02000007（WrapSaveMergeNNFiles.WrapCall）MethodList = 0x060000A1 WrapperSaveMergennFiles(RVA 0x1A5C)、0x060000A2 .ctor(RVA 0x1644)，见 types.cs L341–L345。方法体计数按「IL 体 / 原生实现 / 无 RVA 声明」三分，不再把 2 条声明算进 IL 体。

## 判定

~~~sh
python handoff/assignments/check-native-coverage.py NATIVE-340 --original issue-materials/340/WrapSaveMergeNNFiles.dll
checked 1007 coverage rows, 256 tool-native entries, 293 call records, 0 declared gaps
~~~

**exit code 2**。按标准：结构齐备 + 有已申报未决（15 处 calli + 4 处原生间接转移 = 19 条 unresolved），0 缺口；1（材料错误）不成立。

## 交付文件

run.json（scope 计数与 255+1 拆分）/ native-functions.csv（256）/ coverage.csv（1007 = 256 native + 563 type + 188 method，0 gap）/ calls.csv（293）/ code/native.asm、native.c（含 0x3660 实现）、methods.il（IL 偏移与原件字节对齐）、types.cs（逐成员）、metadata.asm（含 MethodList 范围）。开工回执 s5-started.md。

## 限制

- 仅静态分析；无运行期动态验证。
- 19 条 unresolved 的静态边界已逐址写明；恢复条件为运行期断点或指针表初始化分析。
- 原生视图来自清零 CLI COM 目录的副本（RVA 不变），first_bytes 全部取自原件固定哈希文件。

## 为什么不会再被退

- 0x3660 有实现、有行号、coverage 指向实现，不是注释。
- 12 条误分类全部改成 boundary 并附 token 推导链（IL 偏移 → 操作码 → token → RVA），与裁定例子完全吻合。
- 类型成员归属落到 types.cs 逐成员行，MethodList 与原件 CLI 表一致。
