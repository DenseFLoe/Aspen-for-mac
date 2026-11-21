# urcny6.obj

**整件静态验收通过。** 原件是 Aspen Plus 的 Nylon 6 示例用户速率常数例程，格式为 Windows AMD64 COFF 可重定位目标文件。交付可编辑的 NASM 汇编、回编脚本，以及同一示例包内带有原厂声明的 Fortran 伴随源码。

## 来源

- 产品与交付版本为 Aspen Plus V15.0。清单未登记对象的独立版本，COFF 头时间戳为 2018-01-08 21:53:42 UTC。
- 原路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/urcny6.obj`。固定准备提交为 `9559b75390876346c69b185dbaaba18692a7af75`，从该提交的原版文件目录取出并置为只读。大小 2,352 字节，SHA-256 为 `72133372b496109596e519013bddf9428e169925ba50a2c08c3c5394da2a450a`。[固定提交中的原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E5%8E%9F%E7%89%88%E6%96%87%E4%BB%B6/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/urcny6.obj)
- 旧报告用 PE 解析器读取 COFF 对象，报缺少 DOS 文件头。本轮改用 COFF 读取，确认机器字 `0x8664`、5 个节、可选头长度 0，以及具有函数类型的外部符号 `URCNY6`。[旧报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/urcny6.obj/%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/urcny6.obj.md)
- 伴随源码 `urcny6.f` 从已安装的同指纹 `nylon6.apwz` 直接读取。包 SHA-256 为 `4c6af90152bafe91189a5d41b6e21f2eadab684c5e0cbe252ec7c2b0064195f6`，源码 SHA-256 为 `b8cd7f6b09e09e30da1fb2dd76a93ed08c33379a3ec540b226d32129c7663108`。两项均与 `inventories/2026-11-19/plus/` 的既有清单吻合。

## 交付与覆盖

| 文件 | 用途 |
| --- | --- |
| [urcny6.obj.asm](urcny6.obj.asm) | 完整可编辑的 Windows x64 汇编。覆盖唯一函数、三个静态索引、链接指令、两张栈展开表及外部符号。 |
| [urcny6.obj.build.ps1](urcny6.obj.build.ps1) | 调用 NASM 生成 COFF，并恢复原件的两项栈展开节属性及两个符号的函数类型标记。 |
| [urcny6.obj.f](urcny6.obj.f) | 同包原厂固定格式 Fortran，按原字节保存。可对照高层逻辑和 51 参数声明，汇编为本轮回编验收基准。 |
| [urcny6.obj.verification.json](urcny6.obj.verification.json) | 节大小、属性、指纹、23 条重定位、符号表和 15 处等价编码的逐项记录。 |

| 原件区域（节内偏移） | 静态核对 |
| --- | --- |
| `.text + 0x000–0x020` | Win64 序言保存 R15、RBP、XMM7，读取 `DMS_NCOMP` 导入地址及已经保存的 ACA、ACID-E 位置。 |
| `.text + 0x021–0x224` | 从第 6 个实参 IDSCC 按 16 字节记录读取标识，每轮比较两个，最后处理奇数尾项。匹配 ACA、ACID-E、ACA-R 即覆盖相应 1 基位置。Fortran 主循环还检测 AMINE-E，相关索引仅用于未被消费的 DEN2，因此原件中没有这项扫描。 |
| `.text + 0x225–0x273` | 第 46、50、51 个实参分别为 CSS、NURC、RCUSER。按索引是否为正取 ACA 与 ACID-E 浓度，无条件写第一项，而后检查 NURC 是否至少为 2。 |
| `.text + 0x274–0x371` | 从 CSS 读取 ACID-E 与 ACA-R，按原索引计算分母。通过 `__imp_DMS_RGLOB` 取偏移 8 的 RMIN。保留 `COMISD/JBE` 对相等及无序值的零值分支、除法及乘法顺序、输出 2–9 的写入条件。NURC 等于 7 时仍写第 8 项，与 Fortran 第 350 和 357 行一致。 |
| `.text + 0x372–0x37f` | 恢复非易失寄存器和 RSP 后返回，`0x37f` 为尾部 NOP。 |
| `.bss` | 24 字节零初始化，ITCO、IACA、IREP 三个 64 位索引按原顺序保存并跨调用保留。原件对第 2 项及之后的分母加载未重新检查这些索引，恢复件保留该行为。 |
| `.pdata` / `.xdata` | 原件的三个作用范围为 `[0,0x58)`、`[0x58,0x191)`、`[0x191,0x380)`，并分别引用 `.xdata` 中偏移 `0`、`0x10`、`0x28` 的展开记录。两节原始负载和 9 条 RVA 重定位均匹配。 |
| `.drectve` | 八条默认库指令逐字节匹配。 |

## 证据与复查

Ghidra 12.2 PUBLIC 以 `MS Common Object File Format (COFF)`、`x86:LE:64:default:windows` 导入，确认唯一函数 `URCNY6` 和完整可执行范围。通过 `ghidra-headless.cmd` 的 `-import` 和 `-postScript ExportUrcny6.java` 导出。Ghidra 报告了 15 条节符号重定位未自动应用。逐条读取原 COFF 符号索引与加数，12 条 `.text` 重定位实际引用 `.bss` 的 `0/8/16`，另外 3 条 `.pdata` 重定位实际引用 `.xdata` 的 `0/0x10/0x28`。回编后按节名、节内偏移和类型核对全部 23 条重定位。[Microsoft COFF 格式](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format)

NASM 3.02 生成的回编对象经脚本校正节属性和符号类型后，5 个节的大小、属性及原件全部符号的名称、类型、值和存储类相符。NDISASM 3.02 对原件与回编件的 `.text` 逐条解码，197 条指令和尾部 NOP 的偏移、长度、助记符和操作数全部一致。15 处字节差异是寄存器间 `XOR/ADD/CMP` 使用了另一种编码，前后解码和地址均一致。NASM 另写入汇编文件名、内部汇编标签及绝对节标记。[NASM Win64 对象格式](https://www.nasm.us/doc/nasm09.html)

本机 `work/` 中保留 `ghidra-export.txt`、`ghidra.log`、`ExportUrcny6.java`、`Read-Coff.ps1` 和 `Verify-Urcny6.ps1` 供复查。Ghidra 工程位于 `%LOCALAPPDATA%/AspenReverse/ghidra-projects/retry85-72133372b496109596e519013bddf9428e169925ba50a2c08c3c5394da2a450a/`。在交付文件目录可用下列命令回编到既有的独立构建目录。脚本在输出目录内使用短相对路径调用汇编器。已从最终归档路径实测回编，和验收回编对象的字节差异限于 COFF 时间戳。

```powershell
.\urcny6.obj.build.ps1 -Nasm nasm.exe -OutputPath '<独立构建目录>/urcny6.obj'
```

## 依赖与待验证

- 机器代码通过 `__imp_DMS_NCOMP` 和 `__imp_DMS_RGLOB` 访问数据，代码中没有调用指令。已从已安装 Aspen `AprSystem V15.0/Engine/Commons` 核对 `NCOMP_NCC` 位于块首，`RGLOB_RMIN` 是第二个 REAL*8。其他 COMMON 块及默认链接库保留为对象文件的外部边界。
- Fortran 的 11 个直接 include 文件均在已安装的 Commons 目录内。原厂 Fortran 的具体编译命令未经证实，Fortran 未单独回编。这一来源限制不影响已经回编并逐指令核对的汇编交付。宿主链接、装载、Windows 调用及数值对照留待对应阶段。
- 本件正式交付未包含凭据、受永久保护的数据库或其导出、公式提取归档、安装包、工具包和构建产物。Fortran 伴随源码保留原厂版权声明。

## 成果指纹

- `urcny6.obj.asm`  `1dda986aa4294c01c6615f9f5c29b83661ff338a2bdfd7d39a1bbdb577fad1eb`
- `urcny6.obj.build.ps1`  `af7f274a75cf896160f6939ef10b539ab6c2e5ca8d0788b7fc331ee03e0f12a5`
- `urcny6.obj.f`  `b8cd7f6