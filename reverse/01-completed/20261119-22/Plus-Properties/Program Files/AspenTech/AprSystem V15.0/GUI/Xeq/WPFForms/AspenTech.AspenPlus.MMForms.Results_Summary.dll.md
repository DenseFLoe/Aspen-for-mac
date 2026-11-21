# AspenTech.AspenPlus.MMForms.Results_Summary.dll

**状态为已完成。** Aspen Plus 与独立 Aspen Properties 共用的结果汇总表单，程序集和文件版本均为 `41.0.0.614`。原路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Results_Summary.dll`。Plus 和 Properties 原版 MSI 的 File 序号分别为 1883 和 1520。两套安装包的成员与安装件均为 311,336 字节，SHA-256 为 `ee4a01851204b6132e175cd96758cbc0b589cf915914883331aa93ba06703363`。[来源记录](../../../../../../evidence/identity.json)

## 托管代码与旧缺口

- 完整 C# 的 SHA-256 为 `78c7896633c97b3f3f2eedd265d3a8a3ac5a6dec17432ec03d3337b682d10f0d`。ILSpy `9.1.0.7988` 整库导出覆盖 85 个顶层类型与 50 个嵌套类型。用 dnfile 和 dncil 检查定义令牌、32,790 条原指令的偏移与操作数、19 个 finally 与 11 个 catch 区间。保留 2 项抽象声明，原件中的其余 1,732 个方法均有实现。[托管验收](../../../../../../evidence/managed-audit.json)
- 1,554 个方法与可编辑 C# 的可见范围对应。174 项构造函数、静态初始化和事件访问器逐令牌展开，与 Roslyn 静态生成的调用、字段操作和字面量序列核对一致。4 个自动属性访问器对应原件的后备字段。3 个编译器生成类型、9 个隐式字段及 38 条显式接口映射均可复核。[折叠成员](../../../../../../evidence/folded-members.json) · [托管验收](../../../../../../evidence/managed-audit.json)
- 旧稿的 185 条诊断均定位到运行状态汇总视图模型的静态初始化方法 `0x06000186`，原始偏移全部能对应恢复代码范围。[旧稿诊断对照](../../../../../../evidence/legacy-diagnostics.json)

## 页面与资源

- 主库的 38 个页面加载地址与 en-US 卫星程序集逐项对应。物料流汇总有显示和格式选择、物流表与复制按钮，以及承载结果的表格。表格的 `DataCopying` 与 `PreparingCellValuesForCopy` 在构造函数中挂接。热流汇总的显示选项和两个可滚动结果区均可定位原版字段。[页面清单](../../../../../../evidence/ui-pages.csv) · [布局核对](../../../../../../evidence/ui-audit.json) · [卫星来源](../../../../../../evidence/satellite-identity.json)
- 主库的版本信息可从同目录 RC 回编，1,166 字节资源与原件逐字节一致。宿主的外部页面和本地化资源沿已查明的引用加载。[版本说明](AspenTech.AspenPlus.MMForms.Results_Summary.dll.version.md) · [本地化证据](../../../../../../evidence/localization.json)

## Windows 对照

在内存中静态生成分析用程序集时，Roslyn 报 12 条 CS1702 版本提示及 2 条未使用局部变量警告。已对照两款宿主的程序集重定向配置。实际装载、汇总页中的动态列和复制结果、三处蒸馏曲线标题的 `IsMMEnabled` 数据上下文、运行状态选项卡向外部页面传递 `status_var` 的结果，留待 Windows 重建后对照。本机逐定义 C#/IL 核对及页面记录的指纹见本轮签核 `.local/reverse-round-20261119-22/signoff.json`。
