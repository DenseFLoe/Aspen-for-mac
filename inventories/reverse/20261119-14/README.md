# 第 20261119-14 轮 · 模拟操作窗口

Aspen Plus 与 Aspen Properties 共用的 `AspenTech.AspenPlus.WpfSimdll.dll` 已通过整件静态验收。源码可追到宿主实际使用的三个入口。模拟报告入口打开 `ShowBlockTempDlg`，Properties 模式的报告入口调用求解器的 `DisplayReport`，模拟重新初始化入口返回 `ReinitDlg` 的确认结果。[源码与验收证据](../../../reverse/01-completed/20261119-14/)

| 核对项 | 结果 |
| --- | --- |
| 来源 | Plus 和 Properties MSI 的文件序号分别为 1967 和 1604。两个安装包成员及共用安装件对应同一 SHA-256 `0937ef8eb140cbc27ce4a6f06505e81e494e058d396310cd665a5155f09a1720`。原件为 41.0.0.614 版，133,672 字节。 |
| 代码 | 65 个顶层类型、9 个嵌套类型，以及单独的模块定义。已核对 505 个字段、848 个方法、226 个属性及 17 个事件。旧档的 59 个不同方法均有对应令牌。 |
| 实现与声明 | 831 个方法有 IL 实现。620 个由序列点定位，136 个自动属性访问器逐一对应后备字段，75 个折叠方法按令牌在源码附录展开。另外 16 个为抽象方法，1 个为外部声明。15,987 条指令和 56 个异常处理分支均已对到原件。两处 ConvertBack 抛出的 NotImplementedException 已在原件中确认。 |
| 窗口与资源 | 英语卫星资源中的 24 个页面与主件的 24 个初始化方法逐一对应。已核对 161 个连接编号、154 次字段赋值和 56 处事件连接，登记 233 个显式绑定。主件唯一的 Windows 版本资源已恢复为 RC 文本，编译读回的 1,046 字节与原件一致。 |
| 阶段边界 | 完成范围为主件的源码、声明、布局连接及资源。窗口显示、事件投递和求解器实际执行结果留待 Windows 重建对照。 |

本机正式成果及同名说明位于 `.local/reverse-round-20261119-14/01-completed/Plus-Properties/` 下的原安装路径。轮次根目录的 `evidence/` 保存逐定义映射及带原始指令字节的本机校验材料。[归档指纹](artifacts.csv) · [发布文件清单](../../../reverse/01-completed/20261119-14/publication.csv)

本轮更新 3 条不同来源，在 Plus 总表、Properties 总表、Properties 重复子表和共用表中分别对应 3、2、2、3 行。累计完成 19 / 1,397 个不同原件，涉及 56 条不同来源。[本轮来源变更](status-delta.csv) · [累计台账](ledger.csv)

## 下一轮

接续 `AspenTech.AspenPlus.Infrastructure.dll`，SHA-256 为 `052e0a0e54d287397457200d4bdb87a0051ecff751f42d941114fa5e3c02908f`。本件有 17 个方法通过 33 条构造或调用指令引用该程序集，包括发送重新初始化事件、更新文档状态和刷新窗口。该依赖的旧档只单独导出了 333 个顶层类型中的 5 个，下轮从整件方法令牌覆盖入手。[调用点与旧档依据](../../../reverse/01-completed/20261119-14/Plus-Properties/evidence/handoff.json)
