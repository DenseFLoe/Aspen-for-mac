# oomfhostlib.lib

2026-11-21 静态复验通过。交付 3 个可编辑的 Windows x64 NASM 汇编文件，覆盖静态库的 3 个对象成员和 7 个公开函数。

## 来源与版本

- 产品为 Aspen Plus。原安装路径为 `[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfhostlib.lib`。安装目录标识 OOMF V15.0，清单未登记该库的独立文件版本。
- 从 `codex/reverse-unsuccessful-85` 固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75` 下载原件。12,000 字节，SHA-256 为 `d48d67029ff1a66fb313fb50fcf413f7b3270e64fc199670f92968b1e9a4d049`，与 Plus 安装包清单相符。清单记录 CAB 成员为 `oomfhostlib.lib.FFB4EB35_331E_4DFD_A406_FAD839196763`，本次复用该记录和已核验的只读输入。[固定提交原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E5%8E%9F%E7%89%88%E6%96%87%E4%BB%B6/Plus/%5BProgramFiles64Folder%5D/AspenTech/OOMF%20V15.0/lib/oomfhostlib.lib)
- 旧报告记录 `unsupported_non_pe`，当时用 PE 解析器打开库文件。本次依据 `!<arch>\n` 签名、双链接索引、长文件名表和 3 个机器类型为 `0x8664` 的 COFF 对象确认原生静态库格式。按成员提取后，使用原生 COFF 路线复验。[旧逐件报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/OOMF%20V15.0/lib/oomfhostlib.lib/%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/oomfhostlib.lib.md) [Microsoft PE/COFF 规范](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#archive-library-file-format)

## 覆盖

| 原归档成员 | 原归档头偏移 | `.text` 入口（段内偏移） | 代码字节 / 填充字节 | 段数 / 重定位数 |
| --- | --- | --- | --- | --- |
| `x64\Release\mysetenvqq.obj` | `0x21e` | `MYSETENVQQ 0x0000` | 17 / 15 | 4 / 4 |
| `x64\Release\close_his_rpt_file.obj` | `0x578` | `CLOSE_HIS_RPT_FILE 0x0000` | 139 / 5 | 5 / 9 |
| `x64\Release\open_his_rpt_file.obj` | `0xa24` | `OPEN_HIS_RPT_FILE 0x0000`、`DMOFIL 0x0910`、`DMO_STRLEN 0x0a10`、`RESET_HIS_RPT_FILE 0x0aa0`、`DMO_LOWER 0x13c0` | 5,205 / 27 | 7 / 188 |

- `MYSETENVQQ` 转发到 `SETENVQQ` 后符号扩展返回值。`CLOSE_HIS_RPT_FILE` 依次将逻辑单元 36、14、6 传给 `for_close`。
- `OPEN_HIS_RPT_FILE` 和 `RESET_HIS_RPT_FILE` 的汇编保留文件名拼接、字符处理、`for_inquire`、`for_open` 与格式化写入及相关条件分支。`RESET_HIS_RPT_FILE` 在重新建立文件前调用同库的 `CLOSE_HIS_RPT_FILE`（`.text+0x0ab9`）。保留三个字符串入口各自的循环、字符判断和出入口。
- 汇编保留原段顺序、长度、属性和对齐，含 `.rdata` 字符及 Fortran 描述数据、`.data` 初始化常量、288 字节 `.bss`、5 项 Windows 展开记录及原 `.drectve` 默认库列表。两个链接索引均解析为同一组 7 个符号到成员的映射。
- `SETENVQQ`、`for_close`、`for_cpystr`、`for_concat`、`for_inquire`、`for_open`、`for_write_int_fmt` 和 `memmove` 的函数体由原 COFF 标成段号 0，本件保留这些链接引用。`__ImageBase` 仍由链接器提供。`CLOSE_HIS_RPT_FILE` 在 open 对象为外部引用，在 close 对象有实际定义。

## 复验方法与结论

1. Python 3.12.14 的 `inspect_coff.py` 校验两个索引、读取长文件名、段表、符号表和重定位，按原成员内容拆出 `.obj`。Ghidra 12.2 以 `x86:LE:64:default` 和 `windows` 编译器规范自动选择 `MS Common Object File Format (COFF)`。`evidence/ReviewCoff.java` 导出函数、反汇编、伪代码和 Ghidra 的重定位状态到工作目录。
2. Ghidra 的 7 个文件内函数均取得函数体。逐字节比较其反汇编所覆盖的 5,361 字节与原件，重定位字段另行核对。覆盖范围外的 47 字节均反汇编为 NOP。Ghidra 在 5 个 `.pdata` 字段和 close 对象的 3 个 `.rdata` 引用处报重定位失败。复验采用原 COFF 符号索引、字段加数与重定位类型解析这 8 处，并与回编目标逐条相等核对。Ghidra 中出现的外部占位入口可在原符号表的未定义项中定位。
3. 用 NASM 3.02 的 --reproducible 模式回编，两次独立构建的指纹一致。Python 重建含双链接索引的 Microsoft `.lib`，由 `verify.py` 重新读取。201 条重定位逐一核对原偏移、类型、外部符号或内部段目标和有效加数。NASM 将部分成员内符号改为段基址加偏移，目标地址一致。公开符号类型、段号和入口偏移一致。所有非代码段在单独核对重定位后逐字节相同。
4. 用 iced-x86 1.22.0 逐条对照 `.text` 的 1,092 条指令（含 NOP）。指令起点和长度一致。清除已核对的重定位字段后，59 条差异为寄存器指令方向位，操作数顺序和寄存器相同。24 条差异是基址与索引寄存器位置交换，两寄存器系数均为 1，默认段一致且有效地址相同。其余指令逐字节一致。改动一个关闭单元实参和一个重定位加数的两次内存验证均触发校验失败。
5. `evidence/comparison.json` 保留成员指纹、段范围、逐条重定位目标、Ghidra 函数定位和全部 83 条编码差异。回编库的 SHA-256 为 `2e2b8f153ddbe7be641310c8e817b07ee7cea0cfeef43c0ca8e927908699fec8`。COFF 符号布局、归档元数据和上述指令编码会造成整库指纹变化。

整件静态验收通过。可维护表示采用 Win64 NASM 汇编。若后续改动函数序言，应同步检查 `.xdata` 展开码及 `.pdata` 中的函数范围。工具未运行原版或重建版，也未执行宿主工程链接。Windows 对照阶段仍需用原 Intel Fortran 和 Windows 链接环境验证宿主加载、文件创建和错误处理。

## 复现

从本成果目录使用 Python 3.12 和 NASM 3.02。验证脚本需要 `iced-x86==1.22.0`。将生成目录设在本件 `work/`。

```powershell
python build.py --nasm $nasmExe $buildDir
python verify.py $originalLib (Join-Path $buildDir 'oomfhostlib.lib') (Join-Path $buildDir 'comparison.json')
python inspect_coff.py $originalLib (Join-Path $buildDir 'original-coff.json') --extract $objectDir
& $ghidraHeadless $ghidraProjectDir oomfhostlib -import $objectDir -processor x86:LE:64:default -cspec windows -scriptPath $evidenceDir -postScript ReviewCoff.java $ghidraExportDir
```

可在第二条命令附加 `--ghidra $ghidraExportDir`，重做 Ghidra 定位与覆盖核对。原 Ghidra 工程位于项目规则指定的 `%LOCALAPPDATA%/AspenReverse/ghidra-projects/retry85-d48d67029ff1a66fb313fb50fcf413f7b3270e64fc199670f92968b1e9a4d049/`，逐成员原始导出位于本件 `work/ghidra/`。NASM 3.02 的 Win64 ZIP SHA-256 为 `161d0bfaff53c2f9e9f3e69fd0672323ebabafd1268976a5cec11be92a19aee7`。[NASM 下载与文档](https://www.nasm.us/)

## 交接文件指纹

| 文件 | SHA-256 |
| --- | --- |
| `source/mysetenvqq.asm` | `50331028dee206eb219dea3f907c85e14b8048106d288abd96f1a2efc9a17519` |
| `source/close_his_rpt_file.asm` | `ed696256f656ea7a00f0628804b0bff0cbc68c07ea290d4ed538efdc9ae209e4` |
| `source/open_his_rpt_file.asm` | `4616a5ac9e82ca17af2f82c86434f3b8d3098867e22035d79127128859c2824f` |
| `build.py` | `2bde19a2f60e2f9a9016fc5136cbf2a012e24312cd6d2ca72b337691cfca2de1` |
| `inspect_coff.py` | `806d250972abf4fc01819bd57d7d1132f7234d7ea760a90b1dc0081e703cf047` |
| `verify.py` | `a96b0409b711417e1489a951907e132915488acf62e8b7991fbd77043bc86889` |
| `evidence/ReviewCoff.java` | `a62c0cada3b85c9aadcbbdbe822b70c49dd29b49fdfa986cde7214427c64e5ae` |
| `evidence/comparison.json` | `9ab1e8847608b8ad029d0f6a9e55effe9205742961fc6ac8e4ec933a73ac092b` |

正式成果经检查，未发现凭据或项目永久本地保护材料。工具安装包、原 Ghidra 工程、工具日志和生成的二进制保存在本地工作位置。
