# NATIVE-337 提交

- task_id: NATIVE-337
- owner: tietoumiao
- assigned_seq: 1
- PR: https://github.com/DenseFLoe/Aspen-for-mac/pull/387
- 证据提交: 32bd3a95bb023795e948dc426cc45a2280386c45
- original: issue-materials/337/FindComponent.dll
- original_sha256: 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02（任务卡固定值，已复核）
- 工具: IDA 9.5（idat.exe）+ Hex-Rays，auto_wait 后枚举函数

## 判定

```sh
python handoff/assignments/check-native-coverage.py NATIVE-337
```

输出：`checked 300 coverage rows, 296 tool-native entries, 178 call records, 0 declared gaps`，退出码 **0**。

## 交付内容

| 文件 | 摘要 |
| --- | --- |
| `run.json` | 原件 SHA-256、IDA 版本/命令、范围、限制、native_reported_count=296 |
| `native-functions.csv` | 296 个原生函数（IDA 识别，含自动命名） |
| `coverage.csv` | 300 行：115 个原件锚点 + 其余工具函数；全部 covered |
| `calls.csv` | 178 条：166 条导入调用（external）+ 12 条数据引用（data） |
| `code/native.asm` | 296 个函数逐指令反汇编，行首 RVA + 真实字节 |
| `code/native.c` | Hex-Rays 还原的可编辑 C（296/296 反编译成功） |

## 验收范围对照

- 原件地址锚点 115/115 覆盖：.pdata BeginAddress、PE 入口、可执行导出、原生 MethodDef RVA 取并集；其中 4 个为函数片段（0x33B1/0x382F/0x4706/0x4988），已映射至父函数并在 note 点名。
- 工具发现的其他函数：296 个全部列入 `native-functions.csv` 与 `coverage.csv`，无遗漏。
- 外部调用：166 条导入调用逐址给出 IAT 槽与指令行号。
- 数据引用：12 条（字符串/常量表）逐址标注目标 RVA。
- 缺口：0。

## 限制（未验证项）

- 仅静态分析，无运行期动态验证。
- 函数边界以 IDA 9.5 自动分析为准；异常目录片段不单独成函数，源码与父函数共用。
