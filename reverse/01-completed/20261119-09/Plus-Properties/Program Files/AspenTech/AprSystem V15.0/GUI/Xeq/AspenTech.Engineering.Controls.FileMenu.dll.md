# 文件菜单控件的托管代码

本件属于 Aspen Plus 与独立 Aspen Properties，安装位置为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Engineering.Controls.FileMenu.dll`。两个产品的原包定位与成员指纹见本轮 `identity.json`。原件 87,592 字节，文件版本和程序集版本均为 `15.0.0.0`，SHA-256 为 `db81bd19b9a31b5a560fe0c91ef62ce66d79e768a8d17809e32f618da5814b2f`。

整件 C# 已通过托管实现的静态核验，成果 SHA-256 为 `164afe2d0f3e7acf27c9a5a32478f0def36c61f130946a45d9e1650dc8e742c9`。本轮 `code-coverage.json` 将原始定义令牌映射到此文件的行号。布局、颜色资源与界面连接另见配套成果，整件验收见 `signoff.json`。

旧档选取了 `FileMenuControl`、`FileMenuItem` 与 `FileMenuTemplateManager`。本轮从已核对指纹的安装件恢复全部 23 个顶层类型，包括模板选择、按单位筛选、宽度换算、滚动处理和菜单数据对象等旧档遗漏的 20 个类型。原程序集没有嵌套类型和事件定义。原始 47 个字段、19 个属性及 124 个有 IL 方法体的定义均已对照。指令字节合计 6,201 字节。

在 .NET Framework 4.8 解析环境使用 ILSpy 9.1.0.7988 的 `DecompileWholeModuleAsSingleFile` 读取整件，关闭 PDB。102 个方法按 IL 与 C# 序列点定位。两个 `Children` 自动访问器按原字段令牌及读、写指令核对。15 个隐式实例构造器和 5 个折入字段初值的静态构造器按令牌定点展开，保存在源码附录。两组反编译均无 IL 函数警告。

宽度转换器 `SyncWidthConverter.Convert` 的初始导出将可空类型写成 C# 模式，Roslyn 报告 CS8116。原始令牌 `0x06000025` 的类型参数为 `Nullable<Double>`，存在值时读取 Double 并减去 17，结果为正时装箱为 Double，其余路径装箱整型零。按可空值的装箱规则将该处改为匹配装箱的 Double，保留原返回分支及其类型。修订后对整件使用 Roslyn 5.0 做静态语法及类型检查，诊断均为零。指令、分支和类型签名见 `code-coverage.json` 的 `targeted_checks`。

反向路径转换器的令牌 `0x06000011` 在原件中构造并返回异常对象。原菜单选择事件处理器 `0x06000030` 与鼠标抬起处理器 `0x0600006d` 均只有一条返回指令。源码保留这三处实现。

程序集引用 .NET 基础库、WPF 和 XAML。调用边界包括宿主传入的菜单数据、命令及参数、自定义模板、资源查找、WPF 鼠标事件和自动化滚动接口。宿主交互、命令执行、模板渲染和滚动效果留到 Windows 重建对照。复核脚本在 `.local/reverse-work-20261119-09-code/`，依次运行 `export.ps1`、`select_gaps.py`、`expand_gaps.ps1`、`cover.py`、`check-semantics.ps1 initial`、`fix-width.py`、`check-semantics.ps1 final`、`check-syntax.ps1` 和 `finalize.py`。工具及脚本指纹见覆盖表。
