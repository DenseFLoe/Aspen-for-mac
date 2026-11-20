# AspenTech.AspenPlus.MMForms.PhysicalProperties.dll 可发布 C# 选取件

原件为 Aspen Plus V15 和 Aspen Properties V15 共用的物性表单库，文件版本为 41.0.0.614，安装相对路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.PhysicalProperties.dll`。主库 SHA-256 为 `65ce3da43613a061e2b316c518ef9c6f530ef74cc106544313a3cf70373d45a9`。

本件从第 20261119-25 轮本地全量 C# 中，按顶层类型完整复制 337 个声明，覆盖 1,529 个方法定义。范围包括控件连接、页面加载、声明式绑定、选项显示和转发宿主命令，也包括 NRTL 二元交互参数、二元分析方法、二元参数结果三个页面及其视图模型。其余 159 个顶层类型和编译器折叠方法的附录保存在本地完整归档内。

合并两个审阅清单时，按原件 TypeDef 令牌、命名空间、逐类型内容指纹和原行号逐一复核。选取件保留所有原 using 声明，并为每个类型恢复原命名空间。归档复读核对了全部 337 段声明的原字节。静态编译以原 DLL 提供未选类型及依赖，语法和类型错误均为 0。针对这项校验，Roslyn 给出 584 条同名类型警告和 26 条未用 using 提示。整库专项静态验收见本轮记录，页面操作留待 Windows 宿主对照。

- 本地整库 C# SHA-256 为 `3724b53f52093556212b3bd50af1c058dc37a5e571b4a566fa50ab54e1ed9b53`。
- 此选取件 SHA-256 为 `b78d5c3136952a879a8f8ba50faa0f13ad0647b62cda79e58670e16c578597a5`，文件大小为 741,696 字节。
- `Plus-Properties/evidence/code-extraction.json` 列出每个选中类型的令牌、全名、方法数、审阅依据、整库及选取件行号和 SHA-256，也逐项列出其余类型及保留理由。
