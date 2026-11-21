# 自定义表单库

Aspen Plus V15 与独立 Aspen Properties V15 的安装包分别在 `APRS~433.cab` 中收录了 `AspenTech.AspenPlus.MMForms.CustomForms.dll`。两份包内原件与安装在 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq` 的文件均为 123,944 字节，文件及程序集版本 41.0.0.614，SHA-256 为 `ca9a063e500a53615bce87c85606d7e37ea76269cf26d3f291e0b693cf3d5a0e`。[来源记录](../../../../../evidence/identity.json)

第 28 轮通过整件静态验收。完整可编辑 C# 共 5,682 行，SHA-256 为 `6492d1c0101ca9b3da984abea404578e73cc9b2066ba5095a006a113e57c7081`。ILSpy 9.1.0.7988 导出后，按原版定义令牌核对了 31 个顶层类型、13 个嵌套类型、一个模块定义、177 个字段、81 个属性和 413 个方法。398 个方法有 IL 方法体，另有 9 个抽象声明及 6 个运行时实现声明。逐项对齐 12,122 条 IL 指令和 78 个异常处理区。[逐方法索引](../../../../../evidence/methods.csv) · [托管验收](../../../../../evidence/managed-audit.json)

293 个方法体对应活动源码，20 个折叠方法有附加展开核对，另核对了 85 个自动访问器、3 个迭代器、3 个内嵌 COM 契约及 45 个显式接口槽。Roslyn 静态编译为 0 个错误和 4 项警告，其中 3 项涉及传递依赖版本，1 项为未使用的局部变量。[托管验收](../../../../../evidence/managed-audit.json)

两类存值事件均进入 `StoreValue`，事件触发后是否移交焦点取决于嵌入模式、活动页及单元格编辑状态。保存布局时，独立窗口直接收集页签；嵌入表先查询同一路径的独立窗口是否已打开。布局写入 `Input.VIEWS` 时按段替换子项。另核实了与网格表单主库之间的 10 处调用。[存值与保存入口](../../../../../evidence/control-entrypoints.json) · [报表调用](../../../../../evidence/gridforms-calls.json)

本轮另归档主库内的 3 份可编辑 XAML、4 份字符串 RESX 和 1 份 Windows 版本资源。3 份语言卫星的字符串并入本件资源验收。资源回编、绑定与事件的证据随归档保留。Windows 宿主内的编辑提交、布局保存重开、界面语言切换和引擎返回结果留待重建对照。[布局验收](../../../../../evidence/ui-audit.json) · [资源回编](../../../../../evidence/resx-readback.json) · [日语回退](../../../../../evidence/japanese-fallback.json)
