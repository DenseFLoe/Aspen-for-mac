# build.py

该脚本为 Aspen Plus V15.0 的 `Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Lib/apdelayload.lib` 配套构建工具。本件已通过静态验收。原件 SHA-256 为 `d8c809c76f202e0df54bbc6315f0b16ce5840771099533988bdde0a5727b8afb`，脚本 SHA-256 为 `4426954c0ab9ed2c707c872ba66930850c7f969a948d53b05fb07cc83db457f4`。

## 构建及核对

将 `apdelayload.lib.s` 和 `build.py` 放在同一目录，在该目录运行以下命令。示例假定 Python 和面向 Windows x64 COFF 的 GNU as 位于 PATH，使用新建的输出目录。也可用 `--assembler` 指定汇编器的完整路径。本轮分别使用 Python 3.12.14 和项目现有 `.local-tools/qt/Tools/mingw1310_64/bin/as.exe` 2.39。

~~~powershell
New-Item -ItemType Directory -Force out | Out-Null
python build.py apdelayload.lib.s out/apdelayload.lib --assembler x86_64-w64-mingw32-as --object out/delaylod.obj
Get-FileHash -Algorithm SHA256 -LiteralPath out/apdelayload.lib,out/delaylod.obj
~~~

| 文件 | 字节 | 验收基准 SHA-256 |
| --- | ---: | --- |
| `apdelayload.lib` | 20,658 | `d8c809c76f202e0df54bbc6315f0b16ce5840771099533988bdde0a5727b8afb` |
| `delaylod.obj` | 19,344 | `6facead068ee5957ca9cf3dcd1ac8e15e09df31268e07bd2394fb7333dfec893` |

GNU as 汇编每个具名节、指令和数据表达式。脚本从汇编器返回的对象读取实际节内容、标签值及重定位位置，依据源码末尾的 COFF 声明保留微软原符号名、节顺序、COMDAT 选择和关联节。它按实际节内容重算校验值，从公开符号生成两个归档索引。构建输入只有汇编源码与脚本，Python 使用标准库。原版只在验收时充当比对输入。

全库逐字节复验结果及两次临时源码修改记录见[核验证据](evidence/static-comparison.json)。版本、函数覆盖、栈保护与后续 Windows 验证事项见[逐件说明](apdelayload.lib.md)。

