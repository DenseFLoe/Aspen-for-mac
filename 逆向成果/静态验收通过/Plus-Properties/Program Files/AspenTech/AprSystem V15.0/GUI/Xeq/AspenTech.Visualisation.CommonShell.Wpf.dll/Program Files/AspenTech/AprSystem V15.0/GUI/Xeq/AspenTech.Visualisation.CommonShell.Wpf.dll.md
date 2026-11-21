# 共用窗口宿主

Aspen Plus V15 与 Aspen Properties V15 的安装包均在 `APRS~260.cab` 中提供 `AspenTech.Visualisation.CommonShell.Wpf.dll`。两个包内成员与安装目录 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/` 中的原件均为 293,928 字节，程序集和文件版本为 31.0.0.5，SHA-256 为 `fcc8f69733e5e97475245d15cb45c900117ba0e0a5ffc231412797465516b6d3`。[三条来源、CAB 成员与目标路径](../../../../../evidence/identity.json)

本轮通过整件静态逆向验收。同目录可编辑 C# 为 11,489 行，SHA-256 为 `ddb4dbbb71bd68018c8468364e175ba763f41d10427ac8101bc82dbb5b6b83ff`。旧稿有独立输出的顶层类型仅 1 个，本轮已覆盖 61 个顶层类型和 50 个嵌套类型，包括旧稿遗漏的 `AspenHelpAbout`。连同模块定义共核对 112 个类型定义、313 个字段、191 个属性、3 个事件和 954 个方法定义。[工具、编译诊断和方法覆盖](../../../../../evidence/managed-audit.json) · [逐方法定位](../../../../../evidence/methods.csv)

916 个方法体含 18,944 条 IL 指令和 130 个异常处理区。另有 30 个抽象声明、4 个由运行时提供的方法和 4 个本机调用声明。逐方法索引记录原始方法令牌、指令数、方法体指纹与 C# 位置。原始 IL 清单保存在本机。窗口复用、带取消处理的显示与关闭流程已与原件调用位置逐项核对。[窗口调用](../../../../../evidence/window-actions.json)

窗口重命名回调保留了原件中两个独立的捕获对象。三个迭代器均显式恢复，逐一核对了 13 个正常出口与异常释放路径。静态编译零错误，有 3 条未使用局部变量警告。808 个方法的回编指令、归一化操作数、跳转目标和异常处理区均匹配原件，其中包括全部 88 个折叠方法。编译器额外生成 2 个支持类型，并给两个无字段和静态构造函数的 COM 接口添加了 BeforeFieldInit 标记。[迭代器及折叠方法](../../../../../evidence/special-methods.json) · [编译与接口差异](../../../../../evidence/managed-audit.json)

主件内嵌 6 份布局，已恢复可编辑 XAML 并与原 BAML 对照 1,509 个有序节点、15 个字段连接和 3 处事件订阅。5 个布尔字面量回编后改变大小写，已核对属性类型与值。图像按原键名归档 31 项，30 个 PNG、1 个 ICO。叶形按钮读取路径含 `images/`，同名原图位于根目录。`images/zoom100pct_32.png` 的实际内容为 ICO。两处均保留原件行为和命名。[布局](../../../../../evidence/ui-audit.json) · [图像读取路径](../../../../../evidence/image-lookups.json) · [图像指纹](../../../../../evidence/resource-asset-index.csv)

Windows 版本资源回编后 982 字节与原件完全一致。版本字符串表中的 ProductVersion 保留为 V14.0。Windows 重建后对照跨窗口复用、显示前取消、普通及强制关闭、主题与图标显示，重点检查叶形按钮的资源解析结果。[版本资源](../../../../../evidence/resources.json)
