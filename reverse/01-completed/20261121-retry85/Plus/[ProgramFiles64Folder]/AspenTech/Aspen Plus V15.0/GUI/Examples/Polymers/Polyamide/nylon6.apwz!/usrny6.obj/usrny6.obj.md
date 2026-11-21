# usrny6.obj

**静态验收通过。** 可编辑的 NASM 源码和构建脚本恢复了 `USRNY6` 对象文件。回编后逐项核对 5 个节、21 条重定位及 23 个原有命名符号，全部一致。

## 原件与版本

- 产品为 Aspen Plus。安装路径标为 V15.0，清单未记载对象本身的版本。原安装路径 [ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/usrny6.obj。
- 原件来自 `codex/reverse-unsuccessful-85` 的固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75`。1953 字节，SHA-256 `92efb7c09dffeb1ef3cbb0798ca65d9469725ec66d328b18fe0bbb3bb9cbba25`。本次下载、验收及回编对照均使用已校验的只读原件，路径为本件的 `input/usrny6.obj`。[固定提交中的原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E5%8E%9F%E7%89%88%E6%96%87%E4%BB%B6/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/usrny6.obj)
- 上轮使用 PE 解析工具遇到 DOS 头缺失，未产出逆向正文。本轮直接按可重定位的 Windows AMD64 COFF 解析。文件头 Machine 为 `0x8664`，可选头大小为零。[固定提交中的制作者报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/usrny6.obj/v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/usrny6.obj.md)
- 本机安装的 `GUI/Examples/Polymers/Polyamide/usrny6.f` 可用于交叉核对参数、索引和调用流程，SHA-256 `cef8f8014e52f5d47ad69be08df0b48c75fce8cab43be02c53ec1174198b82d3`。偏移、数据大小、重定位和符号以本次 COFF 原件为准。

## 静态验收证据

| 节 | 字节 | 节属性 | 重定位 | 核对内容 |
| --- | ---: | --- | ---: | --- |
| `.text` | 608 | `0x60500020` | 18 | `USRNY6` 位于 `0x000` 至 `0x252`，`0x253` 至 `0x25f` 为两个对齐 NOP。节字节和重定位目标、类型、加数一致。 |
| `.bss` | 24 | `0xc0400080` | 0 | `NBPDIR`、`NBSEG`、`NSEG` 为 3 个 8 字节的静态变量，分别位于 `0x00`、`0x08`、`0x10`。 |
| `.xdata` | 20 | `0x40300000` | 0 | 展开信息逐字节一致，记录 6 个非易失寄存器的保存及 `0x108` 字节栈帧。 |
| `.pdata` | 12 | `0x40300000` | 3 | 函数范围为 `.text+0x000` 至 `.text+0x260`（不含末地址），展开信息指向 `.xdata+0x0`。 |
| `.drectve` | 187 | `0x00100a00` | 0 | 保留原对象的 8 条默认库链接指令，字节及顺序一致。 |

- `.text+0x3d` 调用 `SHS_FIPOLM`。`.text+0x4a` 和 `+0x74` 两处有符号比较，在聚合物目录或链段索引小于等于零时跳到 `+0x241` 返回。两次 `DMS_LOCATI` 调用位于 `+0x57` 和 `+0x81`。
- 正常路径在 `.text+0x23c` 调用 `USR002`，按原顺序转交前 28 个参数指针，并依次追加 `B(KMW)`、`IB(KDSCC)`、`&NSEG` 和 `IB(LIDXSG)`。`KMW` 和 `KDSCC` 分别由 `IPOFF1(306)` 和 `IPOFF4(2)` 推出，取值按原指令以 8 字节步长访问。`USR002` 及其属性计算位于外部例程，本件保留原链接边界。
- 符号核对覆盖公开入口、外部函数、导入地址指针、共用块大小、原局部变量、节符号和 5 条辅助记录。回编的额外符号记录来自 NASM 源文件标记、局部标签和常量。
- Ghidra 12.2 使用 MS COFF 加载器分析原件，定位函数、分支和外部调用。加载器对 7 条 `.bss` 引用及 1 条 `.xdata` 引用报错。以原 COFF 表的符号索引和原始加数逐条恢复，再与回编结果比对。可复查本件 `work/ghidra-import.log`、`work/ghidra-analysis.txt` 和 `work/ndisasm-text.txt`。`ndisasm` 输出按 `.text` 范围取至 `0x25f`。
- NASM 2.16.03 汇编代码，Python 3.12.14 构建脚本保留五个原 COFF 函数符号类型、`.xdata` 和 `.pdata` 节属性、`.pdata` 的原始符号绑定及 `.text+0x45` 的 `REL32_1` 编码。脚本随后对照原对象验证 5 节全部内容、全部重定位和原符号记录。正式目录构建了两次，其中一次加入原件对照。两次回编件的 SHA-256 均为 `1b28d4375f0c4406f8aaa4acc68fc57b8f44a3c175b13951e3caa4929e0f5ab6`。原件与回编件的整文件指纹差异来自 COFF 头的时间戳、表偏移、记录顺序及上述新增局部记录。[NASM Win64 对象格式说明](https://www.nasm.us/doc/nasm09.html)

## 成果与复验

| 文件 | SHA-256 |
| --- | --- |
| `usrny6.obj.asm` | `207a082da8a4f7f3c99cf39380b0bd507ecb1fe649d6a1a907d5410887caa7d9` |
| `usrny6.obj.build.py` | `9bb900f891234e13c835b294e14bc3d4c47aade91e840eb0589a8a6fa3338212` |

从本件工作根目录启动 PowerShell，设置 `$pythonExe` 为 Python 3 的路径，`$nasmExe` 为 NASM 2.16.03 的绝对路径。为 `--out` 选择 `work/` 中的新文件名。正式归档的完整路径超过传统 Windows 路径长度限制时，按下例给脚本加长路径前缀。

```powershell
$archive = Join-Path (Get-Location).Path '01-completed\Plus\[ProgramFiles64Folder]\AspenTech\Aspen Plus V15.0\GUI\Examples\Polymers\Polyamide\nylon6.apwz!\usrny6.obj'
$builder = '\\?\' + (Join-Path $archive 'usrny6.obj.build.py')
& $pythonExe $builder --nasm $nasmExe --out '.\work\usrny6.recheck.obj' --original '.\input\usrny6.obj'
```

交付范围为汇编源码、回编与复验脚本、本说明。凭据及项目永久本地保护材料检查结果为零。工作日志、工具及回编二进制留在本件工作区。Windows 重建阶段仍需核对 Aspen 主程序与 Intel Fortran 运行库的实际链接，以及 Nylon-6 示例正常路径和两个提前返回路径。