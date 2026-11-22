# azeotropesearch.lib

## 原件与结论

**静态验收通过。** 交付固定布局的可编辑 NASM 汇编和 COFF 档案构建定义。由这些文件重新构建的 87,990 字节静态库，与原件逐字节一致。Windows 链接、运行与数值行为留待项目的 Windows 重建阶段。

- 产品为 Aspen Plus，原路径为 `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Lib/azeotropesearch.lib`。安装路径与交付介质标明 V15.0，清单没有单列该库的版本。
- 原件来自 `DenseFLoe/Aspen-for-mac` 分支 `codex/reverse-unsuccessful-85` 的固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75`，仓库内路径为 `原版文件/Plus/` 加上述原路径。SHA-256 为 `2d899bf19778990ef879b9c8dfaf07b57ed65cff287ad56bf722f15fefb0c2e2`。
- 本机 Plus 清单 `inventories/2026-11-19/plus/01-needs-reverse/files.csv` 的同路径同指纹行定位到 `Process Modeling (Aspen Plus) V15 (64bit).msi` 的 `APRS~228.cab`，成员为 `azeotropesearch.lib.9DD71637_68A3_4F40_BE0C_34ABF98F3116`。
- 通过 GitHub 连接器读取固定提交中 `逆向成果/未成功/Plus/<原路径>/v0.20261121-w2/制作者报告/azeotropesearch.lib.md`，报告 blob 为 `d27afae0b34e92d3b869b3acdc4f394345847206`。前次 dnfile/pefile 以 PE 读取失败。本轮按静态库档案头解析，拆出 18 个 AMD64 COFF 对象和 3 个档案目录记录。

## 源码与构建

每个 `*.obj.asm` 对应一个原 COFF 成员，保留入口、局部分支标签、带符号的重定位注释及已初始化的非代码区段。COFF 的头、符号和辅助记录、字符串表、重定位、归档成员目录和填充由 `archive-layout.json` 按区域保留。未初始化数据的长度、对齐和链接器指令也随 COFF 结构保留。`coff-map.json` 将这些记录解码成按原始成员、区段号、符号号和偏移查询的视图。原编译语言的高级源码、参数名和类型注释未恢复。本件以汇编层级验收。

使用 Node.js v24.22.3 与 NASM 3.02（含 NDISASM）核验。构建从此目录的汇编与布局定义生成新库，输入路径无需指向原件或拆出的对象。输出使用新文件名。

```powershell
node .\build.cjs 'C:\path\to\nasm.exe' 'C:\path\to\azeotropesearch-rebuilt.lib'
```

构建默认要求与原件指纹一致。预期改变指纹时可显式设 `ASPEN_ALLOW_EDITED_LIB=1`。修改时须保持区段尺寸、各重定位字段和栈展开引用的偏移；若移动这些内容，需要同时更新 COFF 布局定义、相关重定位、符号和展开记录。跨成员调用的占位操作数由链接重定位绑定，汇编行末标明符号与原始加数。73 条多前缀 NOP 保留原始编码，属于对齐用的无操作指令。

## 核验记录

- 用便携 JDK 25.0.5.1+2 启动 Ghidra 12.2 Headless，逐件以 `MS Common Object File Format (COFF)` 和 `x86:LE:64:default/windows` 分析，使用 `ExportAzeotrope.java` 导出内存块、入口、指令、重定位和伪代码。先对照原始 COFF 符号与区段，再用 NDISASM 核对连续指令和原始编码，用 NASM 重汇编并对照地址、指令长度、每个成员的内容及整件档案内容。
- 18/18 个代码成员、18/18 个原始函数入口、179 个 COFF 区段、38,369 字节代码、1,038 条重定位均有对应源码或布局定义。两个链接器符号目录交叉核对出同样的 53 个符号—成员索引项。`build-verification.json` 记录整库和 18 个对象的重建指纹，`verification.json` 记录独立逐字节比较及覆盖结果。
- `FUNEQ2` 的 5 个 Ghidra 导入告警来自区段符号重定位。`.text+0x036a` 引用第 27 段 `.rdata`，表内四条 `REL32` 按索引解析到 `.text+0x0377/0x0adc/0x0737/0x073f`。使用 `RepairFuneq2Analysis.java` 将这些记录应用到独立 Ghidra 分析副本，经重新分析补齐 578 条先前未识别的非 NOP 指令，并核对所有分支落点与指令边界。见 `ghidra-funeq2-dispatch.txt` 和 `verification.json`。原件与回编库都保留供链接器应用的记录。
- 另外 48 条 Ghidra 导入告警是 16 个成员 `.pdata` 的 `ADDR32NB`。逐组用原 COFF 区段符号和加数核对，依次定位到各 `.text` 起点、`.text` 末尾及 `.xdata` 的栈展开记录。全部记录随原结构精确保留。
- 关键逻辑定位使用各汇编行末的原 `.text` 相对偏移。`NORML` 从 `0x0080` 累加输入，`0x0090–0x00a8` 执行乘系数、除总和并写出。`FU2NRM` 的 `0x00b7–0x00d4` 保留缩放、平方累加、开方及乘回系数的指令与顺序。`STABILITY_RCM` 在 `0x0315`、`0x044d` 调用 `CALC_EQUILIBRIUM`，在 `0x0644` 调用 `DGEEV`，同原件保留重定位绑定。逐字节一致同时覆盖浮点常量、比较条件、异常展开数据和间接分支。
- `verification.json` 的 `libraryInternalRefs` 记录可由本库符号目录定位的引用，`externalRefs` 记录 `CALC_EQUILIBRIUM`、`COMP_DRIV`、`DGEEV` 及 Intel Fortran 运行库等库外符号。Windows 阶段使用原构建环境的链接上下文核验这些外部绑定并进行运行对照。

`artifacts.sha256` 记录本交付目录除清单自身外的成果和证据指纹。交付内容源自本件有权取用的原件及本轮自编工具和验收证据。没有发现凭据或项目永久本地保护资料。原版和重建库、拆包对象、工具二进制、完整日志及 Ghidra 工程留在本地作业位置。
