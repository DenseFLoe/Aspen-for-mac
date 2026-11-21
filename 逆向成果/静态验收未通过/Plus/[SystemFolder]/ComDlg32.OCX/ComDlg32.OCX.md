# ComDlg32.OCX 静态验收

2026-11-21，验收一组第 3 轮。**静态验收未通过，移入修复清单。协作者交付后由长期监视聊天复验。**

原件来自 Aspen Plus V15.0 安装介质 Process Modeling (Aspen Plus) V15 (64bit) 的 `Global~5.cab` 成员 `Global_Controls_Comdlg32ocx_f0.576D64B0_7413_11D2_B954_006097C4DE24`，目标路径为 `[SystemFolder]/ComDlg32.OCX`。使用已提取的只读原件。原件为 Microsoft CMDIALOG，安装清单版本为 6.1.98.16，文件版本字符串为 6.01.9816，大小为 155,984 字节，SHA-256 为 `00b5af20504fa3440ef3f9670a49963622d1a3557090e349f465746213761cef`。

## 实测覆盖

- 用 PowerShell `Get-FileHash -LiteralPath` 核对原件及两份 W2 导出。反汇编 SHA-256 为 `9a1f3a7d7fce86dc58706f181621d8b6473b543e665a3cbe5a2c0718282783a7`，伪 C SHA-256 为 `6f1483d813ae8308ee6ad247c5a25eb33beaf0252f820d185a820c91bdf08103`。
- 两份 IDA 9.5 导出各有 451 个唯一函数起点及 451 个 `ENDFUNC` 标记，按 `FUNC` 或 `// FUNC` 行中的地址和名称整理，得到 451 组完全一致的对应记录。伪 C 中有 0 条 `DECOMP-FAIL`。这项比较覆盖导出记录之间的对应关系。
- 用 Python 3.12 的 `struct` 直接读原件 PE 头、导出表及资源目录。文件为 x86 PE32，镜像基址为 `0x217A0000`，PE 入口 RVA 为 `0x12B4`。入口和 5 个导出按基址加 RVA 均可在两份导出中定位。

| 入口或导出 | 序号 | RVA |
| --- | ---: | --- |
| `DllEntryPoint` | | `0x12B4` |
| `DllCanUnloadNow` | 1 | `0x15B0` |
| `DllGetClassObject` | 2 | `0x1694` |
| `DllRegisterServer` | 3 | `0xC5B5` |
| `DllUnregisterServer` | 4 | `0xC5D2` |
| `DLLGetDocumentation` | 5 | `0x7D59` |

## 可编辑资源缺口

从 PE32 可选头的第 2 号数据目录（从 0 起算）依次读取资源类型、ID、语言和数据叶项。原件有 36 个叶项，均为语言 1033。其中包含：

- `TYPELIB/1/1033` 的 RVA 为 `0x16CF4`，大小 25,580 字节，数据头为 `MSFT`。伪 C 有 `LoadTypeLib`、`RegisterTypeLib` 和 `UnRegisterTypeLib` 调用，现有对象目录缺少可编辑类型库定义及对应的接口、成员和类型覆盖表。
- 对话框资源类型为 5，ID 为 10、11、13、15、100、101。伪 C 有以 `0x64`（100）选择模板的 `DialogBoxParamA` 调用，现有对象目录缺少这些模板的可编辑定义，以及控件 ID 与对话框处理函数的对照。
- 其余叶项为 25 个字符串表块、1 个位图、1 个图标、1 个图标组和 1 个版本资源。需逐类核对重建所需资源及原件中的引用。

[现有导出及归档说明](ComDlg32.OCX.%E5%BD%92%E6%A1%A3%E8%AF%B4%E6%98%8E.md)列有已核验的两份代码导出，并链接到制作者报告。复验前需补齐可编辑类型库及对话框资源，以原件核对接口与成员、对话框及控件 ID，并关联原始代码引用。Windows 运行验证留到重建阶段。
