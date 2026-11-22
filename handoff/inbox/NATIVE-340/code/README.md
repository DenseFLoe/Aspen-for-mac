# NATIVE-340 证据目录

由 `tool/` 下的解析器从固定原件（SHA-256 869c4b23598e4330…）读出字节后生成，不含人工填写的数值。

| 文件 | 内容 |
| --- | --- |
| `run.json` | 原件哈希、工具版本、命令、范围、限制、分析器报告函数数 |
| `native-functions.csv` | 分析器识别的原生函数与槽跳转桩（RVA, name） |
| `coverage.csv` | 每个标识一行：原生锚点/函数、全部 TypeDef 与 MethodDef、源码与反汇编行号 |
| `calls.csv` | 逐址关联的外部调用、托管↔原生边界调用、未决间接转移 |
| `code/native.asm` | 原生反汇编，行首为 RVA 与真实指令字节 |
| `code/native.c` | 可编辑的 C 还原（含 0x3660 的 GS/间接加载语义） |
| `code/metadata.asm` | TypeDef/MethodDef token 清单 |
| `code/types.cs` | TypeDef 声明 |
| `code/methods.il` | MethodDef 方法体（IL 反汇编） |
| `code/native-fixup-sites*.asm/.c` | .nep 槽跳转桩（naked 间接尾跳，可回编校验） |
| `code/*-unresolved-*.csv` | 未决附表（托管 / 原生分列，由主表生成） |

行号引用格式：`code/xxx#L起-L止`，相对本目录。
