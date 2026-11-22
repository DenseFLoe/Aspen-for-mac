# oomfutilslib.lib 复验记录与核验器

本件为 Plus/OOMF V15.0 的 AMD64 COFF 库。原件及独立回编件 SHA-256 均为 `5b4fdd8b8728e16ba802f472c356613456625f0d400122b3503d03b5e920a23c`。整件静态复验通过。

`oomfutilslib.lib.verification.py` 使用 Python 3.12.14 和 Capstone 5.0.7，独立解析归档和 COFF，不调用回编器。它检查两份索引、每个对象的内容、所有节和重定位。从 COFF 函数符号与 `.pdata` 独立确定函数边界，再从原件指令读取实际分支和数据引用。完成后逐字节比较整个库。COFF 字段按 [Microsoft PE/COFF 规范](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format) 解读。

- 核验脚本 SHA-256 为 `290a8504f63ae67e38c08c1efae60825d35633102eab20ab8e548f86c27b0c87`。
- 实测输出 `oomfutilslib.lib.verification.json` 的 SHA-256 为 `353392529becb3e3fe504a97a35b9cae9b4f0aa224c432431d13b2010f2bb7a4`。其中 `totals` 给出整件计数，`members` 按原库顺序记录对象及所有 84 个函数。函数的 `branches`、`calls`、`data_references` 均记录对象的 `.text` 节内偏移，可分别定位到目标指令、调用符号以及相应数据重定位。各节的标志与长度、COMMON 大小、已初始化及未初始化对象的符号位置一并列出。
- 在临时源码副本，对 `rtxfile.obj` 的 `RTXFILE_MATCH_MD` 于原节偏移 `0x18a6` 插入一条 NOP，并把原 `0x18f8` 的成功返回值常量由 1 改为 2。回编后原目标函数增长 1 字节，后续 `RTXFILE_RESTORE_EXCEPT` 的入口由 `0x190a` 移至 `0x190b`，对应 `.pdata` 区间及后续代码重定位同步改变，另外 15 个对象的内容保持逐字节一致。编辑试验副本位于本轮临时工作区。

使用回编说明中的 PowerShell 变量，为 `$original` 选择经验证的原件路径，然后运行下列命令。在本件工作区，原件为 `input/oomfutilslib.lib`。

~~~powershell
$checked = Join-Path $workDir 'oomfutilslib-verification.json'
& $python -B (Join-Path $sourceDir 'oomfutilslib.lib.verification.py') $original $rebuilt $checked
Get-FileHash -LiteralPath $checked -Algorithm SHA256
~~~

任一身份、布局、覆盖或比较检查失败时，核验器报错并退出。原件定位、旧报告处置和后续 Windows 行为对照范围见 [逐件说明](oomfutilslib.lib.md)。
