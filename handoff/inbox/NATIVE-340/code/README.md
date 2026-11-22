# NATIVE-340 证据目录

由 `work/gen_evidence.py` 从原件（SHA-256 869c4b23598e4330…）与 IDA 9.5 导出结果生成。

| 文件 | 内容 |
| --- | --- |
| `run.json` | 原件哈希、工具版本、命令、范围、限制、分析器报告函数数 |
| `native-functions.csv` | 分析器识别的全部原生函数（RVA, name） |
| `coverage.csv` | 每个标识一行：原生锚点/函数、全部 TypeDef 与 MethodDef、源码与反汇编行号 |
| `calls.csv` | 逐址关联的外部调用、托管→原生边界调用 |
| `code/native.asm` | 原生函数反汇编，行首为 RVA 与真实指令字节 |
| `code/native.c` | Hex-Rays 还原的可编辑 C |
| `code/metadata.asm` | TypeDef/MethodDef token 清单 |
| `code/types.cs` | TypeDef 声明 |
| `code/methods.il` | MethodDef 方法体（IL 反汇编 / 原生实现指针） |

行号引用格式：`code/xxx#L起-L止`，相对本目录。
