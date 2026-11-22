# Aspen Properties.xla

**第 7 项，第 1 次返工。整件静态验收通过。** 从本次 ZIP 中的 VBA、工作簿记录和窗体资源重新生成一份 XLA 后，43 个模块共 360,323 字节的 VBA 原文、全部工作簿记录和全部原生窗体流均与原件一致。已从交付 ZIP 重新解包，在新目录独立重跑静态复验和编辑回读。

## 原件

| 项目 | 记录 |
| --- | --- |
| 产品与路径 | Aspen Properties V15.0，`[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/Engine/xeq/Aspen Properties.xla` |
| 原件 | 961,536 字节，SHA-256 `d124683bb13ceb5c6a39f661661fc727e67289fdb6257f8bd25b82246dd18919` |
| 安装来源 | `AProp~16.cab` 成员 `aspen_properties.xla.BCA6FC6B_F074_464B_9D2C_757A6DC7CA6A`。项目安装清单未列独立文件版本。 |
| 实际输入 | 复用本机同哈希安装成员副本，复制到本次 `input/Aspen Properties.xla`。已安装的同路径文件也复算为相同 SHA-256。 |
| 准备分支 | `DenseFLoe/Aspen-for-mac`，`codex/reverse-unsuccessful-85`，提交 `9559b75390876346c69b185dbaaba18692a7af75`。原件路径以 `原版文件/Properties/` 为前缀，Git LFS 为 false。 |
| 成果 | `Aspen Properties.xla.zip`，177,197 字节，71 个成员，SHA-256 `85c30a870a135665f7d46f1407d4334964c3207b8bf3f14e5c253cfa4c236bcc`。包内 `SHA256SUMS` 覆盖其余 70 个成员。 |

主干旧报告的 blob 为 `0b4165cfae0359edc3c06d680e0fa55a9e165edb`，记录了 PE 解析失败。本件是 CFB 内的 BIFF8 加载项。本轮对上一轮本地报告中列出的编译缓存和窗体设计器缺口分别做了复验。[主干旧报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/c5b4dd94e3bebf8a80ef26ba007f8193233c7431/逆向成果/未成功/Properties/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Properties%20V15.0/Engine/xeq/Aspen%20Properties.xla/v0.20261121-w2/制作者报告/Aspen%20Properties.xla.md)

## 逐项复验

| 对象 | 核验结果 |
| --- | --- |
| VBA 模块 | `PROJECT`、`VBA/dir`、原模块流和回读模块一一对应。10 个标准模块、27 个类、2 个文档模块、4 个窗体代码模块均按 CP1252 恢复，原始过程属性、条件编译分支和宿主属性一并保留。 |
| 过程与逻辑 | 原件 x64 `0x00B5` 缓存含 9,738 个行条目。444 个过程的名称、种类、顺序和 444 个显式形参的名称、顺序均与源码对应。147 个有名跳转、错误目标或标签在各自过程的源码中定位。对 10 个关键过程另核对 27 项调用及控制流锚点，详见 `evidence/cache.json`。 |
| 工作簿 | 87,195 字节的 Workbook 流逐字节相同。全部 2,742 条 BIFF8 记录均可由 `workbook.json` 生成。1 张普通工作表，两段 BOF/EOF，2,414 项定义名称。2,413 项保有整数零令牌，1 项保有 3D 引用令牌。代码名称 `ThisWorkbook`、`Sheet1` 与文档模块一致。 |
| 窗体及绑定 | 4 对 `.frm/.frx` 含完整设计器，覆盖 5 个设计器存储和 19 个原生流。回读核对全部持久化字节，另逐站点解码名称、ID、类型、坐标、TabIndex 及对象数据范围。42 个控件均定位，25 个控件事件过程对应具名控件。另行核对窗体初始化、工作簿事件及 `WithEvents` 声明。嵌套的 `frameComment` 对应存储 `i29`，其内有 `lblComment`。 |
| 工程和资源 | 按路径核对原件 101 个流。26 个非缓存资源流逐字节相同，其中包含工作簿、19 个窗体流、工程保护字段和文档属性。43 个模块按展开源码比较；`dir` 展开后仅 43 个源起始偏移改为零。另 1 个工程版本流和 30 个 SRP 流按可移植格式处理。全部原始存储路径与类标识保持一致。 |
| 外部依赖 | `project.json` 记录原件类型库引用，包含 Office、MSForms、ATCO、CAPE-OPEN、Aspen Properties Excel Calculator 和 Happ。源码与声明保留对这些组件的调用。 |

**缓存占位符已定位。** 本件参数链的下一个节点位于参数描述符偏移 `+24`。沿链检查全部 444 个过程，旧工具显示的 163 处 `id_FFFE` 均落在末端返回值槽。计入显式形参之后的节点，共有 208 个该类返回槽；标志均包含 `0x20`，类型形状均与相应返回描述符一致。30 个 `Ld id_FFFF` 在各自过程的源码中均对应显式 `Me`，同一表达式访问的成员逐项相符。`VBACaller.GetConnection` 的返回描述符位于 `0x58`，原始字节为 `1d 00 00 00`，指向对象表第 0 项。其标识符 `0x028a` 解为 `VBConnection`，与原始源码的返回声明和缓存中的 `New VBConnection` 一致。

**窗体已从交付配对文件重新装入 CFB 工程。** 回读比较包括 VBFrame 文本、全部 `f/o` 属性及控件对象、窗体和嵌套控件的 CompObj、存储类标识和设计器尾部数据。临时编辑试验把 `lblGlobalUnitSet` 的 X 坐标从 423 改为 523，同时更改窗体标题、VBA 源文本及一项定义名称。生成文件回读得到全部四处变更，名称增长后的工作表及 DefColWidth 文件偏移也重新定位正确。原件和正式包保留原值。[MS-OFORMS FormControl](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-oforms/219bef34-8932-4287-853d-f8e1dd73edb1) · [公开 FRM/FRX 格式对照样本](https://github.com/viktormax3/vba-macro-project/tree/main/test_data/forms/original)

## 复查与后续阶段

解压成果，按包内 `README.md` 使用 `verify_project.py` 指定原件与新的复验目录。脚本验证成员指纹，重查原件缓存，使用交付源文件生成静态对照文件，然后重新打开并比较。也可直接查 `evidence/static.json` 中的逐流指纹、每个控件的位置、绑定及所属存储。实际工具为 Python 3.12.14、olefile 0.47、oletools 0.60.2、pcodedmp 1.2.6 和 Windows ole32.dll 10.0.20348.2849。

静态对照文件按 MS-OVBA 将工程版本写为 `0xFFFF`，保留原件可互操作的 VBA 源码和工程声明。原件缓存已用于交叉核对。文档属性中三个二进制属性的原值已校验保留。Excel/VBE 实际导入与加载、签名信任、COM 调用、窗体交互和数值比较留到 Windows 对照阶段。本轮 GitHub 发布由协调主聊天复核后进行。[MS-OVBA 版本和缓存](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/4d20e95c-0c17-47d6-84b9-8da95d8ea129) · [MS-OVBA 模块流](https://learn.microsoft.com/en-us/openspecs/office_file_formats/ms-ovba/c66b58a6-f8ba-4141-9382-0612abce9926)

