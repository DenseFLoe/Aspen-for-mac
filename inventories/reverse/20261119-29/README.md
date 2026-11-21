# 第 20261119-29 轮 · 建模对话框库

`AspenTech.AspenPlus.MMDialogs.dll` 通过整件静态逆向验收。旧归档只单独覆盖了 76 个顶层类型中的 1 个，本轮恢复了完整 C# 和 40 份可编辑布局。原件在 Plus 和独立 Properties 安装包中的内容相同。[逐件说明](../../../reverse/01-completed/20261119-29/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/AspenTech.AspenPlus.MMDialogs.dll.md) · [发布清单](../../../reverse/01-completed/20261119-29/publication.csv)

| 窗口 | 从原件确认的行为 |
| --- | --- |
| 模型冲突 | 窗口分别读取已部署和已编辑模型的冲突记录。每条至少需要六个字段，第六个字段为 `Yes` 时预先勾选。确认后，两组分别按原顺序返回逗号分隔的 `1` 或 `0`。 |
| APWZ / BKP 文件格式 | 窗口按产品和文件格式选择提示文本。正常显示时，驱动分别读取是否复制和以后是否提示。脚本模式直接返回不复制，并把“不再提示”设为真。 |
| 原油分析库选择 | 窗口预选第一个库。选中 APAL 时记录选项 0，选中另一项时记录 1。确定和取消通过独立的窗口结果返回。 |

上述三组窗口共核对 20 个方法，包括上轮留下的三个初始化方法体指纹。[方法令牌与操作位置](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/dialog-actions.json)

## 验收结果

- 995 个方法定义逐一匹配，其中 927 个含方法体，共 23,124 条 IL 指令和 49 个异常处理区。已核对 69 个显式接口槽、18 个本机调用及四个迭代器。静态编译为 0 个错误、4 项警告。[逐方法索引](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/methods.csv) · [托管验收](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/managed-audit.json)
- 40 份 XAML 均已回编，与原版核对 199 个界面连接、186 个字段和 105 处事件订阅。原版通过路由事件处理的两处列表表头点击已保留。标记窗口两处命令参数引用的 `findPropertyWindow` 在本页无同名元素，已按原件保留，留待宿主对照。[布局核验](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/ui-audit.json)
- 主库的版本资源和原生图标资源均已回编核对。配套语言卫星有 21 项图像，共 23 帧。可上传的资源声明与指纹已归档，原生图标与卫星图像保存在本机。[版本资源](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/resources.json) · [原生图标](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/native-icon.json) · [卫星图像](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/resource-assets.json)

本轮按主库哈希新增 1 件，累计 **34 / 1,397**，覆盖 **101 条不同来源**。实际窗口显示和返回给宿主的结果留待 Windows 重建对照。[累计台账](ledger.csv) · [本轮来源增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

继续流程图对话框库 `AspenTech.AspenPlus.PfsDialogs.dll`。原件有 525 个方法定义，旧档按名称去重记录了 233 个 IL 方法。已定位控制变量、书签和查找对象三个窗口的初始化方法。[下轮入口](../../../reverse/01-completed/20261119-29/Plus-Properties/evidence/next.json)
