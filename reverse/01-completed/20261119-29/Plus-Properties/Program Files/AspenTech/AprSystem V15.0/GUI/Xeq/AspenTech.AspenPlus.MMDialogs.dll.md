# 建模对话框库

Aspen Plus V15 和独立 Aspen Properties V15 的安装包在各自的 `APRS~456.cab` 中收录了同一份 `AspenTech.AspenPlus.MMDialogs.dll`。安装路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq`。三条来源均为 183,848 字节，文件与程序集版本均为 41.0.0.614，原件 SHA-256 为 `d9fa9a27c589bd987d5e3bfebabec1e9902016c2163e5b6ac9c76b3f5b675b63`。[来源与成员](../../../../../evidence/identity.json)

第 29 轮通过整件静态逆向验收。可编辑 C# 为 13,517 行，SHA-256 为 `47268d764b43c5f9814ec598dfb2418ed83914c6a0d0a64456fb91053eb815b6`。ILSpy 9.1.0.7988 导出后，逐令牌核对了 76 个顶层类型、26 个嵌套类型、模块定义、630 个字段、208 个属性、17 个事件和 995 个方法。927 个方法有 IL 方法体，其余为 46 个抽象声明、18 个本机调用和 4 个 CLR 委托方法。已核对 23,124 条指令和 49 个异常处理区。[逐方法索引](../../../../../evidence/methods.csv) · [托管验收](../../../../../evidence/managed-audit.json)

已核对 69 个显式接口槽和 18 个本机调用的入口及封送。复制标记和导出层次树分别有两种选中记录的枚举方式。为恢复异常退出时的释放顺序，将四个迭代器写成显式状态机并核对 40 个相关方法。9 个静态字段的内容对应窗口选项与按钮编号，回编时长度和数值指纹均与原件一致。[迭代器核验](../../../../../evidence/iterator-checks.json) · [静态初值](../../../../../evidence/static-initializers.json)

对完整源码作内存中的静态编译，得到 0 个错误、4 项警告，涉及未使用或未赋值的局部变量与字段。回编时编译器增加了两个内部属性类型；4 个接口的类型初始化标志和 5 个编译器辅助类型的可见性存在差异。已核对原件的成员签名、字段布局和取值。原件自身三个转换器的反向转换会抛出 `NotImplementedException`。[差异与工具版本](../../../../../evidence/managed-audit.json)

本库从配套 `en-US/AspenTech.AspenPlus.MMDialogs.resources.dll` 加载 40 个窗口及控件布局。已将原版加载方法、事件、字段和绑定与可编辑 XAML 核对。主库另有版本资源和一枚原生图标，卫星内有 21 项图像；可编辑 RC、图片指纹及本机保存位置随档记录。[布局核验](../../../../../evidence/ui-audit.json) · [版本](../../../../../evidence/resources.json) · [原生图标](../../../../../evidence/native-icon.json) · [卫星图像](../../../../../evidence/resource-assets.json)

三个上轮定位的窗口已追踪到输入、选择与返回值。模型冲突窗口分两组返回勾选标志，文件格式提示分别回传复制选择和以后是否提示，原油分析库窗口分别表示所选库与确认或取消。[操作入口](../../../../../evidence/dialog-actions.json)

标记对话框的确定与取消命令参数都引用 `findPropertyWindow`。原始布局和连接器中没有这个名字，已保留原绑定，实际解析结果待宿主对照。

在 Windows 重建阶段，需在原版宿主中对照窗口打开、取消和确认、不同文化的文本与布局，以及选项返回到调用方的结果。
