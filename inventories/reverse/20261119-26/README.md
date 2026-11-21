# 第 20261119-26 轮 · 网格表单控件库

Aspen Plus 和 Aspen Properties 共用的 `AspenTech.AspenPlus.MMForms.GridForms.Controls.dll` 通过整件静态验收。两套安装包内的主库与安装件内容一致。旧稿选取两个顶层类型，本轮已归档全部 542 个方法的可编辑 C#、12 份 XAML 和 PE 版本资源。[逐件说明](../../../reverse/01-completed/20261119-26/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/AspenTech.AspenPlus.MMForms.GridForms.Controls.dll.md) · [发布清单](../../../reverse/01-completed/20261119-26/publication.csv)

| 原版操作 | 从代码和布局核实的行为 |
| --- | --- |
| 路径导航 | 换根时从新根的子节点逐段匹配原选择的文本路径。各段按当前区域设置区分大小写，任何一段找不到就选中新根。 |
| 工作表命名 | 输入框的 `MaxLength` 为 21。去掉首尾空白后有内容，确定按钮才启用。点击后调用外部名称校验，收到错误文本就显示提示并保留窗口。校验通过后设置确认结果并关闭。 |
| 变量列表 | 查询文本变化时先发出携带新旧值的事件，再刷新状态栏。同步选择时先清除数据行的选择标记，再标记网格中当前选中的行。 |

14 个入口方法均有原始令牌、方法体指纹、IL 偏移与 C# 行号，工作表和变量列表的字段及事件另有布局证据。真实窗口的操作与显示留待 Windows 宿主对照。[入口及分支](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/control-entrypoints.json) · [布局核验](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/ui-audit.json)

## 整件核验

- 41 个顶层类型与 16 个嵌套类型共含 542 个方法体。逐令牌核对全部 7,377 条 IL 指令、23 个异常处理区和 17 条显式接口映射。补回 XML 枚举器在异常退出时释放资源的原始逻辑。Roslyn 静态编译有 0 个错误和 1 项原版旧 API 警告。[托管核验](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/managed-audit.json) · [逐方法索引](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/methods.csv)
- 6 份带代码后置的布局和 6 份主题字典全部通过 WPF 静态读回。已核对 35 个字段连接、12 处事件订阅，并确认代码和布局共引用 36 个可定位的本地化字符串键。[布局核验](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/ui-audit.json) · [本地化](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/localization.json)
- 主库及卫星安装件签名有效。1,222 字节的版本资源回编后与原件逐字节相同。11 个图标均已解码，按内容是 5 个 PNG、6 个 ICO。键 `images/uponelevel16.png` 的原始内容是 ICO，按原键名和字节保存在本机。[版本资源](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/resources.json) · [签名](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/signing.json) · [图像索引](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/resource-asset-index.csv)

累计 31 / 1,397 个不同原件通过静态验收，覆盖 92 条不同来源。本轮在 Plus、Properties、Properties 重复子清单和共用索引中同步对应记录。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

接续直接使用这批控件的网格表单主库 `AspenTech.AspenPlus.MMForms.GridForms.dll`。原件含 3,084 个方法定义，旧稿选取 173 个顶层类型中的 1 个。已定位变量查询窗的创建、字段设置和结果读取，并记录了 18 个调用方方法的原始令牌及调用位置。[下一件及调用证据](../../../reverse/01-completed/20261119-26/Plus-Properties/evidence/next.json)
