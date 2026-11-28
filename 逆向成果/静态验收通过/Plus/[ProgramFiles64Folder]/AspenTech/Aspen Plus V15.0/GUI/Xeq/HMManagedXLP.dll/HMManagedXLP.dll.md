# HMManagedXLP.dll

Aspen Plus V15.0，文件版本与程序集版本均为 23.1.23.0。安装原路径为 `C:\Program Files\AspenTech\Aspen Plus V15.0\GUI\Xeq\HMManagedXLP.dll`，项目原相对路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/HMManagedXLP.dll`。安装原件为 71,760 字节，SHA-256 为 `3186d51b396c281ab10ae71c5ba00d6cebdae09bf17eabacb0a08a24ff556e7f`。

按固定主干 `adbe73b517acac25da87598cce46de033f630ccb` 的标准，本地整件静态验收通过。制作与复核分别由 `/root/producer` 和 `/root/reviewer` 完成。复核员从同一冻结 ZIP 解包，分别使用全包和只含 C#、编译入口及程序集公开公钥的目录复编。任务负责人又在另一空目录复跑，并对照安装原件核对。主干基线中的分类为待静态验收，本轮结果提交总控回读。 [静态验收要求](https://github.com/DenseFLoe/Aspen-for-mac/blob/adbe73b517acac25da87598cce46de033f630ccb/docs/static-acceptance.md)

## 成果和复查入口

- 同目录 `HMManagedXLP.dll.source-v7.zip` 为 39,957 字节，SHA-256 `b4fb8a3812d880be5f6bdaadcb3f7b0dc3a1a418a8f01af8f33cae92cec097a1`。包内同名说明记录文件清单及工具要求。
- 从任务根查看 `RESULT.json` 的完整复跑命令与依赖位置。独立预期、实测与命令在 `review/expected.md`、`review/review.json`。负责人复跑入口为 `lead/run-fresh.ps1`，实测凭据在 `lead/fresh-v7/receipt.json`。
- 编译使用 Python 3.12.10、实测 Windows x64 .NET Runtime 9.0.23、Roslyn 3.8.0 和 NETStandard.Library 2.0.3 的 `netstandard.dll`。编译只读取源码、公开公钥和标准库引用，无需 .NET SDK、Aspen 安装或原件。比较另外读取安装原件，使用项目现有验收器、PowerShell 7.6.9 和 pefile 2024.8.26。
- 直接编译的 `build-output/HMManagedXLP.dll` 为 61,440 字节，SHA-256 `eb77334b8462c4b72663bf50f698763df38c85bcda98fe6edbbe47be2833a574`。本包从夜班 v6 取用可编辑 C# 和公开公钥。构建由编译器直接发射代码、元数据和版本资源。

## 静态覆盖

665 条 MethodDef 逐项配对。406 个有体方法的完整编码跨度合计 15,711 字节，含 13,581 字节 CIL 和 4 条异常处理区，按定义令牌逐项相等。余下 259 条为原件无体的 P/Invoke，声明、映射和调用约定一致。独立复核另检验了调用操作数及签名、布局和封送元数据。全部表及令牌绑定由原始 `#~`、`#Strings`、`#US`、`#Blob` 逐字节相等支持，`#GUID` 的 16 字节差异为 Module MVID。实装原件有 32 TypeDef、174 Field、71 Property、17 MethodImpl、2 FieldMarshal、21 CustomAttribute 和 1 AssemblyRef。方法、特性和资源负对照均被比较入口拒绝。

托管资源与 FieldRVA 均为零。唯一 `RT_VERSION/1/0` 由源码的程序集特性生成，叶载荷 1,168 字节，代码页 0，原件和产物的 SHA-256 均为 `22717259245a968d01b6e7b4b069e94d583e762266485850f613540f61777abc`。PE32、CLR flags、节权限、`mscoree.dll!_CorDllMain` 引导和引导重定位一致。构建生成自身的 MVID、时间戳及调试标记。原件含 10,320 字节 Authenticode 证书表和原强名签名；产物保留公开程序集标识 `a6bddcad966d1a06`，PublicSign 的 128 字节签名槽为零，证书表为空。

## 宿主和外部边界

本件唯一托管引用为 `netstandard, Version=2.0.0.0, PublicKeyToken=cc7b13ffcd2ddd51`。实装 `ModelEquations.dll` 7.0.2.0 以原程序集版本和公钥标识引用此件，IL 清单中有使用本件类型的包装属性及访问器。该证据和本件引用表均未确认 Excel 为实际宿主。现场签名装载及 Excel 调用链留待 Windows 重建对照。

259 条原生声明均指向 `hmxlpxmps`。同目录装机提供方是 x64 `hmxlpxmps.dll` 13.1.23.0，SHA-256 `9c3bb9b814fda2afa3df159e8d617e7f9731a72945f4ba78d4437d0495ca3cea`。其中 258 条声明按名称命中。原件令牌 `0x06000245` 的 `SetBMLMonotoneOption` 在该提供方无准确导出名或对应的 A/W 后缀，提供方有异名 `SetMonotoneOption`。交付保持原件绑定，运行时加载器选择和该入口的可达性留待 Windows 实机对照。证据在任务根 `lead/references.json`、`lead/caller-il.json`、`lead/native-exports.json`。

## 总控静态验收

本机安装范围的产品归属为 Plus。从可编辑 C# 直接回编，核对 406 个 CIL 方法体、259 个 P/Invoke 声明、4 个异常区和 Win32 版本资源。已保留原件的 SetBMLMonotoneOption 绑定，现场提供方的同名导出待 Windows 对照。

总控回编产物与任务回执指纹一致。


## 公开复现入口

从源码 ZIP 内的同名说明运行构建和静态比较。文中的任务根 `RESULT.json` 及任务执行路径供本机交接使用。 已安装提供方的导出记录随件归档。 [导出对照](evidence/native-exports.json)

[源码 ZIP](HMManagedXLP.dll.source-v7.zip) · [独立复核](evidence/review.json) · [总控复跑回执](evidence/controller-receipt.json)
