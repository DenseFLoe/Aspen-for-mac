# DevExpress.Images.v23.2.dll

**静态验收通过。** Aspen Plus V15.0，安装路径 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Images.v23.2.dll`，文件与程序集版本均为 23.2.4.0。固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75` 中的 `原版文件/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Images.v23.2.dll`。复用本机 `.local/aspen-plus-github-inputs-20261120-225559-578/originals/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/GUI/Xeq/DevExpress.Images.v23.2.dll`，文件 8,831,088 字节，SHA-256 `569c25ba89a835b68705e036853b28a83c7c2884ae68bd972ab5202fe251bee4`。旧报告（Git blob `001d9b36e4a45d9410df7eef0279a611d072831f`）的 DOS 头错误来自 132 字节、SHA-256 `a15e165d0d9384106ec0bd5290f7378065587e28a3fc3d4cf18724c2cbdb90af` 的输入。已核验原件为 ILOnly、StrongNameSigned，目标 .NET Framework 4.5.2，公钥令牌 b88d1754d700e49a。

## 源码与证据

- 使用共享 ILSpy 9.1.0.7988，运行 `dotnet <ilspycmd.dll> --disable-updatecheck <原件>` 导出单文件 C#，加 `-il` 导出 IL。源码将 GetFiles 的 foreach 直接作用于原版静态数组以对应迭代器初始化。
- 使用本机 Roslyn 4.9.2（`.local/work-20261119-56-npgsql/roslyn-4.9.2/tasks/netcore/bincore/csc.dll`）回编。参数为 `/langversion:10 /noconfig /nostdlib+ /target:library /optimize+ /debug:portable /publicsign+`，`/out` 使用原程序集文件名。从原件元数据提取公开公钥用作 `/keyfile`。引用系统 .NET Framework v4 的 mscorlib、System、System.Core、System.Drawing 和本机原件同目录的 DevExpress.Data.v23.2、DevExpress.Drawing.v23.2（均为 23.2.4.0）。托管资源用 `/resource:<文件>,DevExpress.Images.v23.2.g.resources,public`，Win32 资源用 `/win32res:<文件>`。
- `members.csv` 覆盖 30 个类型、229 个字段、23 个属性。无事件、字段 RVA 数据或控件布局。Mono.Cecil 比对原件和回编的 IL，复用 `.local/work-20261119-46/CanonicalBodies.cs` 的指令、分支目标、异常区域及操作数归一化。三个闭包按所属类型和用途将 DisplayClass16_0、7_0、8_0 分别映射到 DisplayClass21_0、10_0、11_0。`methods.csv` 覆盖双方全部 160 个定义，其中 142 个方法体相同，2 个为原版抽象声明，16 个差异见 `il-differences.txt`。6,814 项的 ImagesAssemblyImageList 与 XAF 图像表初始化均进入方法体相同比较。
- 原始 CLR 资源容器 7,188,246 字节，从原件提取并嵌回，逐字节相同。枚举核实 7,248 项，包括 4,614 PNG、2,632 SVG 以及程序集自身的 SHP、DBF 各 1 项。Win32 仅有 VERSIONINFO（类型 16、ID 1、语言 0），以 .res 交付，其 982 字节版本数据嵌回后逐字节相同，数据 SHA-256 为 `7b42795e4dcce6201ddfd818a52127ef7968b30215e36d6a5361cc24852458ff`。

## IL 差异复核

| 原件方法令牌尾号 | 核对结果 |
| --- | --- |
| 10、30、92 | switch 和布尔分支经共享局部变量返回，分支值、后缀条件及默认分支相同。 |
| 17、34、5b、68、70、8e、90 | 立即读回的临时变量被省略。构造、空值分支、查询排序和路径编码的操作顺序一致。 |
| 1b | 用 dup 替代局部变量，两边先判 null。非空分支的 call 和 callvirt 指向同一非虚 SvgBitmap.get_SvgImage，已在同版本 Drawing 元数据中确认。 |
| 27 | 分类键、重复键、资源读取及字典写入一致。返回引用经临时变量跨出 try，两边最终均先在 finally 释放读取器再返回同一对象。 |
| 46 | 两边在缺键时将新列表写入字典，再追加图像项。回编使用临时变量转存列表。组名比较、阈值和三处枚举释放一致。 |
| 80、81 | KeyValuePair 值参数复制到局部再取地址，属性读取和判断一致。 |
| 95 | MoveNext 省去图像项临时局部变量。延迟初始化、路径顺序、OrdinalIgnoreCase、PNG 筛选、挂起恢复及自然结束清空数组字段一致。提前释放的方法体已单独比对相同。 |

Windows 重建对照仍须核对强名称签名和程序集绑定、位图与 SVG 查询、尺寸和调色板、资源枚举和缓存行为。本轮公签仅用于静态回编比对。交付材料中未见凭据或项目永久保护材料。

## 交付指纹
- DevExpress.Images.v23.2.dll.cs SHA-256 4aed4d37cecd7f18a3c0610a24b3757d355804cce88679b88e1eb34792430ca5
- DevExpress.Images.v23.2.dll.version.res SHA-256 8d8f5577bba077ad32d2f481a6e464bf8768a42c7cef57c90aee0f2670e03967
- DevExpress.Images.v23.2.g.resources SHA-256 9e91c70bc91e0a11c07c6411bf1c48b3d0ecbcb44030a4a1d7729fabdb4d61ed
- il-differences.txt SHA-256 c64fa6c05c6d1a02f9778a4ce8a24b6d57794958790a7b32101057aeed7262f4
- members.csv SHA-256 c4ce014b078a3567a136478fe36858e10a19a05c7b6810e8f65d0686d7134f76
- methods.csv SHA-256 a26fc131292a7358802094174f2eda8f70dce2a852f47b51570ea691c3a3ec15
