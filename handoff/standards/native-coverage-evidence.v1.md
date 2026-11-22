# PE 原生及混合程序集覆盖证据 v1

适用于 NATIVE-337、NATIVE-340 的补证交付。上游按任务卡固定的原件 SHA-256 复核。上游另按 [静态验收 v2](static-acceptance.v2.md) 对整件的实现、数据、资源与逻辑作出判断。

## 交付目录

每件写入 `handoff/inbox/<task_id>/`。保留 Ghidra 或同等静态分析工具的反汇编、可编辑实现、实际运行参数和行号。混合程序集同时交付元数据和 IL 证据。已有同哈希成果可复用。二进制输入可从任务卡的固定地址取得。

| 文件 | 内容 |
| --- | --- |
| `run.json` | `original_sha256`、`tool_version`、`command`、`scope`、`limitations` 字符串，及工具本次导出报告的整数 `native_reported_count`。记录分析器、版本、选项、模块基址与无法判定的内容。 |
| `native-functions.csv` | 列 `rva,name`。由分析器导出该原件识别出的全部原生函数，保留自动命名和无导出名称的函数，各 RVA 唯一。函数边界调整写入报告。 |
| `coverage.csv` | 列 `kind,key,state,first_bytes,listing,source,note`。每个标识一行。覆盖原件可见锚点、分析器发现的其他原生函数，混合件另含全部 TypeDef 与 MethodDef。 |
| `calls.csv` | 列 `kind,caller,callee,class,listing,note`。从工具的外部调用、跨界调用或重要数据引用清单逐址关联；note 写调用位置、方向及依据。无法确定的调用写 unresolved，说明如何恢复。 |
| 随附实际证据 | 反汇编、IL、可编辑源码与必要的说明。导出工具自动生成本文所用的行号索引。 |

## 对应关系

1. `kind=native` 的 key 为 RVA。检查器独立读取 x64 异常目录的 BeginAddress、PE 入口、可执行导出和原生 MethodDef RVA，按地址取并集，再合并 native-functions.csv。异常目录可含函数片段，也可能遗漏叶函数。每个原件锚点须映射至实际反汇编和对应源码；片段与父函数共用源码时，在 note 点名父 RVA。只列导出或只数异常表项均不足以宣称整件覆盖。
2. `kind=type` 和 `kind=method` 的 key 是 CLR token。按原件列出所有 TypeDef（含模块伪类型）和 MethodDef。对照声明、实现和成员归属。原生实现的 MethodDef 还需与同 RVA 原生行关联。无 RVA 的 MethodDef 填 `state=declaration`，在 note 说明导入、运行库实现或声明依据。
3. 数值可用十进制或带 `0x` 的十六进制。已核对的行填 `covered`（声明行见上条）。缺口填 `gap` 并写清缺失对象和具体恢复条件。原生覆盖行填 `first_bytes` 为由 RVA 映射到文件位置后连续 8 字节的小写十六进制；短函数的取值可跨其末尾，用于校验地址定位。
4. `listing`、`source` 均为本件目录下相对路径及行号，如 `code/module.asm#L42-L51`、`code/module.cpp#L60-L68`。listing 取相应 RVA、VA 或 token 所在范围，原生清单行从地址及真实指令字节开头。仅有声明的行指向实际声明。原生源码使用 C/C++，混合件可附 C#/IL 源码。在一处定位多个元数据标识时，分别说明各自的成员及作用。
5. calls 的 kind 取 native 或 method；caller 为相应的 RVA 或 token。class 取 `external`、`boundary`、`data` 或 `unresolved`；callee 记实际符号、RVA、token 或待解间接目标。listing 指向该调用或数据引用所在行。跨界边应写明托管/原生方向及跳板；外部或间接目标按证据区分。

## 复核

从仓库根目录运行任务卡的命令，要求 Python 3.9+。脚本默认下载固定提交的该件原件并校验 SHA-256；本机已有同哈希文件时可加 `--original <本地文件>`。加 `--inventory` 可单独输出原件独立清单；这一模式不验提交物。

正常校验返回 0 表示身份、清单、原件锚点、证据文件/行号和引用关系通过机械检查；返回 2 表示结构齐备且存在已申报的缺口或未决调用；返回 1 表示输入或材料错误。上游复验原码与反汇编内容、函数发现范围、调用和数据引用，核实困难或仅有片段的行。证据交付的结果和整件静态验收分别记录。
