# nl2sol.lib 静态验收

**通过（passed）。** 完整的 x86-64 汇编实现可从三个文本输入独立构建。重建归档与原件同为 203,986 字节，逐字节比较相同。68 个成员的顺序、内容与指纹全部相同。Windows 加载、数值和诊断行为留到后续 Windows 对照阶段。

## 来源

Aspen Plus，APrSystem V15.0。原路径为 `Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Lib/nl2sol.lib`，原件 203,986 字节，SHA-256 为 `7738ce952d97d2f27c6fce67e735f5e710598a8ce1b77746cbe443f611fe4dee`。归档中没有独立库版本字段。 本次取自本机原件副本，复制到本次 input 后再次核对 SHA-256。准备分支为 `codex/reverse-unsuccessful-85`，固定提交为 `9559b75390876346c69b185dbaaba18692a7af75`，原文件直接存于 Git 中。[固定提交原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E5%8E%9F%E7%89%88%E6%96%87%E4%BB%B6/Plus/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/Engine/Lib/nl2sol.lib)

主干旧报告记录了 PE 解析器的 DOS 头错误。本机上一轮材料已按 COFF 归档取证，保留 70 个入口的 Ghidra 清单和其中 16 个入口的 C。此轮对实际使用的 68 份历史拆分对象逐份与本次原件成员比较，再以原件的字节、重定位和符号定义恢复整库。[主干旧报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/main/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/Engine/Lib/nl2sol.lib/v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/nl2sol.lib.md)

## 实现与核验

| 范围 | 原件对应内容与复验结果 |
| --- | --- |
| 指令与入口 | 68 个可执行节，共 84,799 字节。16,901 条含对齐 NOP 的指令均以助记符恢复。长 NOP 的额外操作数宽度前缀单独写出。70 个入口含 `i1mach.obj` 的 I1MACH、I1MCR1，以及 `d1mach.obj` 的 D1MACH、I1MCRY。每个入口的机器指令、分支、浮点运算次序、寄存器与栈访问随成员回编逐字节吻合。 |
| Ghidra 交叉核对 | 对照已取证的 Ghidra 12.2 原件节内指令记录，16,825 条覆盖 84,113 字节。其余 76 段共 686 字节均为对齐 NOP，也已纳入汇编和回编比较。 |
| 求解与分派 | SSQFCN 和 SSQJAC 各有 26 个按题号 2–27 索引的表项，INITPT 有 24 个按题号 4–27 索引的表项。全库 154 个跳转表槽以真实代码标签和正确的表基址表示。DRN2G 至 DG7LIT、DRN2GB 至 DG7ITB 的跨成员调用及成员内控制流、数组寻址完整保留。DG7LIT 与 DG7ITB 均使用节内偏移 0 和 48 的两张分派表。 |
| 数据与 ABI | 全部 565 个节含初始化数据、常数、BSS、Fortran 诊断格式、链接器指令与 x64 展开记录。1,582 条重定位中，代码 REL32 为 1,260 条，跳转表 REL32 为 154 条，函数表 ADDR32NB 为 168 条。库内各项重定位目标索引、加数、符号可见性、节选择和辅助记录随回编逐字节吻合。 |
| 库边界 | 两张归档链接索引各含 121 个符号项。单独链接应用时有 17 个库外符号，包括数学函数、Intel 内存及 Fortran I/O 接口和 `_fltused`。完整清单在核验证据中。D9MACH 在 `d1mach.obj` 中的 COFF 节号为 0、存储类为外部、值为 304。它是归档索引可见的 304 字节 common 符号。GNU ar 与 nm 能读取重建归档及符号索引。 |

### 编辑验证

另取交付源码副本，在 SSQJAC 第一条 push 前插入一条 NOP 并重建。该成员的 97 个代码重定位位置和 26 个跳转表目标均增加 1。函数结束偏移由 5,835 变为 5,836。展开序言由 116 变为 117，18 个展开操作的指令偏移也增加 1。其余 67 个成员逐字节保持一致。测试副本与正式成果分别存放。

### 复查方法

将 `nl2sol.lib.s`、`nl2sol.lib.layout.json`、`nl2sol.lib.build.py` 放在同一目录。汇编中用 `# MEMBER` 定位原对象，用 `def_` 定位原符号，用 `ref_` 对应重定位目标。各个 `at_` 标签以原节号与原偏移命名。提供 x86-64 Windows 目标的 GNU as。以下命令在成果目录执行，将路径参数替换成本机实际位置。使用本项目环境时，Python 为 `.local-tools/research/venv/Scripts/python.exe`，汇编器为 `.local-tools/qt/Tools/mingw1310_64/bin/as.exe`，均相对 Aspen 根目录。

```powershell
python .\nl2sol.lib.build.py --assembler C:\path\to\as.exe --output .\rebuilt.lib
Get-FileHash -Algorithm SHA256 -LiteralPath .\rebuilt.lib
python .\nl2sol.lib.check.py --original C:\path\to\original\nl2sol.lib --assembler C:\path\to\as.exe
```

预期重建 SHA-256 为 `7738ce952d97d2f27c6fce67e735f5e710598a8ce1b77746cbe443f611fe4dee`。复查脚本同时核对交付的 `nl2sol.lib.verify.json`，并独立重复上述源码修改。制作使用 GNU objdump 2.39、GNU as 2.39 和 Python 3.12.14。静态验收范围内的缺口已关闭。下一阶段按原调用方连接运行库，比较相同输入下的求解结果、状态码和诊断输出。

## 成果指纹

| 文件 | 字节 | SHA-256 |
| --- | ---: | --- |
| `nl2sol.lib.build.md` | 932 | `6c306fbbb87edea5c4ac79cdb61b6876d929034d6ce05da9636fe0ae6c633d0b` |
| `nl2sol.lib.build.py` | 8535 | `e13998840be9e4f2ccce033f0954d988a7ff65ec1760c2eb46917e0ecaaa8a75` |
| `nl2sol.lib.check.md` | 884 | `3f776fddc5840e0fda83dbd6bad672e970e0e4fb42b9dade9e89225b8869076d` |
| `nl2sol.lib.check.py` | 5647 | `a7252637d6d01c55393be7895def8f398e4361c5445812fcf7a0373c1970dff5` |
| `nl2sol.lib.layout.json` | 68478 | `d3101ee711e746421990603d622c5663ceda30cc6250f47a257b18ad5f40b109` |
| `nl2sol.lib.layout.md` | 1052 | `bbc80cf739ea8d0acd75158da8be1be8491db3d58b4f0618ae5ab0b40a5cb18a` |
| `nl2sol.lib.s` | 719382 | `3ac69ab43c96d7181972235eaca10a05916243796a0a8c7bc19634d024c36a3b` |
| `nl2sol.lib.verify.json` | 38759 | `17ef3f66e0434cd95c82f8593b980d3944a55180c34edde5e9f0eef17363df62` |
| `nl2sol.lib.verify.md` | 927 | `9a3e924038a6def8cebaea2d9418fdfa488d7ed07a38314c76f72a3ef192afec` |
