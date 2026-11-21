# Aspen Plus 模型库

`AspenTech.AspenPlus.ModelLibrary.dll` 位于 `Program Files/AspenTech/Aspen Plus V15.0/GUI/Xeq/Modules/`。Aspen Plus V15 原版安装包的 CAB 成员与本机安装件都是 172,584 字节，SHA-256 为 `6e49cd8e54bcd47c2227caa85cd7105080d9b5aa96f7ffdf497f745e899ebe2d`，文件与程序集版本均为 41.0.0.614。两条来源共用同一件静态验收结果。[来源、包内成员与安装路径](../../../../../../evidence/identity.json)

第 31 轮通过整件静态逆向验收。同目录的 C# 共 10,479 行，SHA-256 为 `aab9c04314f7ccf2819a9aab0352164cceb474fdf4b29e78a26b42d6d2cc6418`。按原件定义令牌核对 53 个顶层类型、27 个嵌套类型、模块定义、477 个字段、151 个属性、2 个事件和 865 个方法。829 个方法体共含 18,695 条 IL 指令及 78 个异常处理区，其余为 20 个抽象声明、12 个运行时提供的方法和 4 个本机调用。[逐方法索引](../../../../../../evidence/methods.csv) · [工具版本、回编差异与验收](../../../../../../evidence/managed-audit.json)

图标、分类、模型和两种记录树遍历涉及五个迭代器。本轮显式恢复了它们的状态机，保留原件枚举结束及释放时的字段操作。静态回编时嵌入原版 `Interop.Aosapfs` 与 `Interop.Happ` 的类型，核对 11 个 COM 类型、76 个显式接口槽及 4 个本机调用。68 个被编译器折叠的方法在归一化私有名称后逐指令匹配。[折叠方法和迭代器核验](../../../../../../evidence/special-methods.json)

旧稿仅单独恢复了 `ModelLibraryPresenter`。其中 4 个方法留下 17 条类型推断诊断，涉及模型库面板、库管理窗口、分类窗口和新增库窗口。本轮逐条映射到原始指令偏移，整件源码已消除这些诊断。静态编译为零错误，出现两条字段警告（CS0649 × 1, CS0414 × 1），其中`bfTime` 未赋值，`m_designPath` 赋值后未读取。[旧诊断与方法指纹](../../../../../../evidence/legacy-diagnostics.json)

en-US 卫星提供 22 份布局和 26 个图像流。22 份 XAML 核对了 2,388 个 BAML 节点、159 个连接号、145 处字段连接与 155 处事件挂接。11 个 PNG 和 15 个 ICO 的全部 27 帧已解码，原图按键名保存在本机归档。代码中的 221 次资源访问和 XAML 中的 176 次访问共对应 301 个不同字符串键，含四类物流的标签。主库的 Windows 版本资源以 RC 文本恢复，回编后 1,102 字节与原件一致。[布局和绑定](../../../../../../evidence/ui-audit.json) · [图像清单](../../../../../../evidence/resource-assets.json) · [版本资源](../../../../../../evidence/resources.json) · [语言资源引用](../../../../../../evidence/localization.json)

加载模型库时，程序单独处理物流分类，批处理模式下跳过 `ACM Models`。管理窗口保存勾选结果后会通知其他界面。编辑器首次加载内置库时隐藏保存按钮。可编辑的用户库在关闭时会保存更改。Windows 重建阶段复核宿主返回的数据、批处理模式下的分类顺序、窗口交互和保存结果。[13 个方法的调用和原始指纹](../../../../../../evidence/model-library-actions.json)
