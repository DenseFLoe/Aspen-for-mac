# oomfutilslib.lib 回编器

`oomfutilslib.lib.build.py` 用于从同目录的 `oomfutilslib.lib.asm` 生成完整的 Win64 COFF 库。脚本逐条调用 AsmTK/AsmJit，再从可编辑声明生成节、数据、重定位、符号表、长名称和两份库索引。指令编码采用本机已有的 x64dbg 版 `asmjit.dll` 导出的 `XEDParseAssemble` 接口。[上游调用方式](https://github.com/x64dbg/x64dbg/blob/development/src/dbg/assemble.cpp)

- 原件为 Plus/OOMF V15.0 的 `oomfutilslib.lib`，SHA-256 为 `5b4fdd8b8728e16ba802f472c356613456625f0d400122b3503d03b5e920a23c`。此回编器已对完整原件验证。脚本 SHA-256 为 `fe62c966acc038784e4d64cd3f519141fb3380ac015c60da09594313d596fae5`。
- 已验证工具为 Windows x64 Python 3.12.14 以及项目安装的 x64dbg 2026-05-27 快照；其 x64 `asmjit.dll` SHA-256 为 `4b174ef05228587823cc30c6bd55a1103480b29669e17ada05992116bba22422`。[工具发布](https://github.com/x64dbg/x64dbg/releases/tag/2026.05.27)
- `.member` 开始一个对象。`.symbol` 记录类型和可见性，`.index` 控制成员对库索引公开的符号。`reloc(symbol, addend)` 产生原 COFF 名称的相对重定位，可在加数中使用同节的标签差。跳转的 `short`、`long` 和少数寄存器指令的 `modrm` 显式选择编码。修改使短跳转超出范围时，可将对应分支改为 `long`。
- `.unwind` 下的声明按标签记录序言内的位置，`.rva` 生成映像相对的重定位。改变栈分配或寄存器保存方式时，应同步改动对应展开声明。字符、数值或预留空间可直接在数据节定义中编辑。

在 Windows PowerShell 中将以下三个路径设置为实际位置，其中 `$workDir` 是已有的独立临时目录。输出应写到临时目录。

~~~powershell
$aspenRoot = 'C:/Users/Administrator/Desktop/Aspen'
$sourceDir = (Get-Location).Path
$workDir = (Get-Item -LiteralPath $env:TEMP).FullName
$python = Join-Path $aspenRoot '.local-tools/research/venv/Scripts/python.exe'
$asmjit = Join-Path $aspenRoot '.local/reverse-tools/x64dbg/release/x64/asmjit.dll'
$rebuilt = Join-Path $workDir 'oomfutilslib-rebuilt.lib'
& $python -B (Join-Path $sourceDir 'oomfutilslib.lib.build.py') (Join-Path $sourceDir 'oomfutilslib.lib.asm') $rebuilt --asmjit $asmjit
Get-FileHash -LiteralPath $rebuilt -Algorithm SHA256
~~~

原始交付的回编 SHA-256 与上列原件 SHA-256 相同。除这两个源文件、Python 标准库及 AsmJit 外，回编不需要原件、历史分析数据、对象文件或网络。下一阶段由 Windows 工程引入回编库做链接和行为对照。
