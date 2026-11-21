# 第 20261119-19 轮 · Flash2 等表单共用的控件库

`AspenTech.AspenPlus.MMControls.dll` 通过整件静态逆向验收。Flash2 输入和结果页都使用这里的页面基类。本轮归档了完整 C#、11 份可编辑的 WPF 布局、字符串资源及 Windows 版本资源。[源码与逐件说明](../../../reverse/01-completed/20261119-19/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/) · [发布文件与指纹](../../../reverse/01-completed/20261119-19/publication.csv)

原版 Aspen Plus V15 和 Aspen Properties V15 的 MSI File 序号分别为 1941 和 1578。两个包内成员和共用安装件均为版本 41.0.0.614，大小 1,236,520 字节，SHA-256 为 `bd4b5cdf3e6c8ede0dbb54b9297581bb79fa7289fe45c71def67b5bf1107842c`。[来源核对](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/identity.json)

| 范围 | 静态验收结果 |
| --- | --- |
| 方法与接口 | 按原件令牌核对 6,570 个方法定义。其中 6,342 个有 IL 实现，228 个是抽象方法、CLR 委托方法或本机调用声明。逐条核对 142,939 条 IL 指令、643 个异常处理区间和 243 个显式接口映射。[托管验收记录](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/managed-audit.json) |
| 页面导航 | Flash2 两个页面的构造函数均调用 `MMTabPage`。该基类注册 Next 按钮事件，处理方法发布 `NextButtonClickedEvent`。页模型另提供查询未完成项的入口。记录列出了相应方法令牌和 IL 偏移。[导航调用记录](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/navigation.json) |
| 页面与样式 | 8 个界面和 3 个资源字典共含 2,243 个对象。57 个布局连接涉及 39 个控件字段和 46 个事件挂接。另核对了 346 个 Binding、10 个 MultiBinding 及 311 处模板绑定。[逐页清单](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/ui-pages.csv) |
| 资源 | 两个托管资源表含 264 个字符串、11 份 BAML 和 39 个图像条目，其中两个是序列化箭头位图。图像按原资源键和指纹留在本机。Windows 版本资源用 RC 重建后，1,046 字节与原件相同。[本轮归档指纹](artifacts.csv) |

在搜索框遮罩的宽度绑定中，原版使用 `ElementName=SearchTextBox`，同一名称域的控件实际名为 `SearchTextBoxItem`。C# 的同名属性返回这个控件，页面代码中没有找到对该名称的动态注册。已保留原版写法，Windows 对照时需观察遮罩随搜索框调整宽度的表现。[名称域核对](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/ui-audit.json)

从 BAML 恢复样式时，按原类型编号和程序集补回了 3 个字典中 76 处依赖属性的命名空间前缀。最终逐项对照了 3,890 个属性值，11 份 XAML 均由框架读取到末尾，零个未知类型或成员。[最终 XAML 对照](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/xaml-ui-comparison.json)

修复了 C# 还原过程中 `GetCellData` 的局部变量作用域，并转义了与较新 C# 版本冲突的 `field` 标识符。最终 Roslyn 静态检查为零错误。Windows 重建时需复验表格单元格分支、页面导航，以及 Infragistics 与 AspenCxs 的传递引用版本绑定。[修正依据](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/source-repairs.json)

本轮新增 1 个已验收原件，覆盖 3 条不同来源。Plus、Properties、Properties 重复子表和共用视图分别更新 3、2、2、3 行。累计 24 / 1,397 个不同原件通过静态验收，对应 71 条不同来源。[累计台账](ledger.csv) · [本轮变更](status-delta.csv)

## 下一轮

接续混合与分流表单 `AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.dll`。该表单库中有 155 个方法直接调用本轮控件库 373 次，27 个被调用签名均已匹配。下一轮需按混合与分流表单原件核对其 834 个方法定义及相关页面。[调用与原件指纹](../../../reverse/01-completed/20261119-19/Plus-Properties/evidence/next.json)
