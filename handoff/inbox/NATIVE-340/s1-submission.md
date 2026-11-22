# NATIVE-340 提交

- task_id: NATIVE-340
- owner: tietoumiao
- assigned_seq: 1
- PR: https://github.com/DenseFLoe/Aspen-for-mac/pull/387
- 证据提交: 32bd3a95bb023795e948dc426cc45a2280386c45
- original: issue-materials/340/WrapSaveMergeNNFiles.dll
- original_sha256: 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec（任务卡固定值，已复核）
- 工具: IDA 9.5（idat.exe）；CLR 元数据解析 + IL 反汇编（IDA CLR loader）；原生视图用清零 PE COM 目录副本（字节不变、RVA 不变）

## 判定

```sh
python handoff/assignments/check-native-coverage.py NATIVE-340
```

输出：`checked 1007 coverage rows, 256 tool-native entries, 24 call records, 0 declared gaps`，退出码 **0**。

## 交付内容

| 文件 | 摘要 |
| --- | --- |
| `run.json` | 原件 SHA-256、工具/命令、范围、限制、native_reported_count=256 |
| `native-functions.csv` | 256 个原生函数（IDA 255 + 手工解码 1，见限制） |
| `coverage.csv` | 1007 行：75 原生锚点 + 256 原生函数 + 563 TypeDef + 188 MethodDef；1005 covered / 2 declaration |
| `calls.csv` | 24 条：12 external（IL→mscorlib）+ 12 boundary（IL→原生实现 MethodDef） |
| `code/metadata.asm` | TypeDef/MethodDef token 清单 |
| `code/types.cs` | 563 个 TypeDef 声明（元数据重建） |
| `code/methods.il` | 188 个 MethodDef：169 个 IL 方法体反汇编、19 个原生实现指针、2 个仅声明 |
| `code/native.asm` / `code/native.c` | 原生函数反汇编与 Hex-Rays C（256/256） |

## 验收范围对照

- 原生锚点 75/75 覆盖（含 RVA 0x3660 手工解码项与 0x480C thunk）。
- TypeDef 563/563、MethodDef 188/188 全量列出；无 RVA 的 2 个 MethodDef 按标准填 `state=declaration`。
- 外部调用：12 条 IL 调 mscorlib 成员，注明调用方法与行号。
- 跨界调用：12 条托管→原生 boundary（IL call 指向 flavor=native 的 MethodDef，附 token 与原生 RVA）。
- 缺口：0。

## 限制（未验证项）

- TypeDef 行为按 CLI 元数据重建的声明骨架（类名/token/命名空间），成员归属以 `code/metadata.asm` 的 MethodDef 清单与 IL 方法体为准；不宣称完整成员实现。
- 原件为混合程序集，IDA 默认加载器只解析 IL；原生视图由清零 COM 目录的副本取得，所有 first_bytes 与哈希均取自原件。
- IDA 未识别 RVA 0x3660 为函数，已按 14 字节原始指令手工解码并在 asm 中标注 manual。
- 仅静态分析，无运行期动态验证。
