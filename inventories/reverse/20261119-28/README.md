# 第 20261119-28 轮 · 自定义表单库

`AspenTech.AspenPlus.MMForms.CustomForms.dll` 通过整件静态逆向验收。旧稿仅覆盖 3 个方法，本轮已恢复完整 C#、3 份 XAML、4 份字符串 RESX 和 Windows 版本资源。[逐件说明](../../../reverse/01-completed/20261119-28/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/AspenTech.AspenPlus.MMForms.CustomForms.dll.md) · [发布清单](../../../reverse/01-completed/20261119-28/publication.csv)

| 操作 | 原版实现 |
| --- | --- |
| 提交当前编辑 | 通用存值事件和流程图嵌入表事件进入同一方法。嵌入表的活动页、单元格和宿主控件须齐备，且宿主正在编辑、键盘焦点已离开时，才把焦点移回活动网格。 |
| 保存布局 | 独立窗口直接保存，嵌入表在同一路径的独立窗口未打开时保存。按页签顺序收集布局并序列化，每段最多 76 个 UTF-16 码元。找到 `Input.VIEWS` 后倒序清除旧子项，再依次写入新段。 |
| 使用物流报表属性 | 自定义表单先识别并解析剪贴板的特殊报表路径，提取物流和物性模板。重新计算时遍历各页数据行，分别去重物流和模板，再调度网格表单库的引擎接口。 |

8 个存值与保存方法均有源码位置、IL 偏移及原始方法体指纹。另复核上轮标记的 6 个调用方和 10 处报表调用。[操作入口](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/control-entrypoints.json) · [报表调用](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/gridforms-calls.json)

## 静态验收

- 核对 413 个方法定义、398 个 IL 方法体、12,122 条指令和 78 个异常处理区。3 个迭代器、3 个内嵌 COM 契约及 45 个显式接口槽均有对应核对。完整源码静态编译为 0 个错误、4 项警告。[逐方法索引](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/methods.csv) · [托管验收](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/managed-audit.json)
- 三份 WPF 布局已回编并逐页核对，共 37 个对象、9 个具名字段、2 次点击事件订阅和 4 个命令绑定。流程图放置操作和新建按钮用到的两张外部图标已按资源键定位并解码。[布局](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/ui-audit.json) · [图像引用](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/external-images.json)
- 主库与日、俄、简中三份语言表共 103 个字符串键值，四份 RESX 回编后的资源流分别与原件逐字节一致。新页签名实际取自独立的本地化库。按本机安装和默认日语回退顺序，会取到中性表中的 `Tab {0}`。另验证了 1,134 字节的主库版本资源。[字符串回编](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/resx-readback.json) · [语言回退](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/japanese-fallback.json) · [版本资源](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/resources.json)

本轮按主库哈希增加 1 件已完成原件，累计 **33 / 1,397**，覆盖 98 条不同来源。三份卫星提供配套资源。原版宿主内的表单编辑、保存重开和结果显示留待 Windows 重建对照。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

继续建模对话框库 `AspenTech.AspenPlus.MMDialogs.dll`。原件有 995 个方法定义，旧档只单独选取了 76 个顶层类型中的 1 个。已记录模型冲突、文件格式和原油分析库三个对话框的初始化方法令牌与指纹。[下一件](../../../reverse/01-completed/20261119-28/Plus-Properties/evidence/next.json)
