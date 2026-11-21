# AspenTech.Visualisation.Controls.Assistant.W1.dll · 整程序集 C#

本轮 20261119-01，原文件静态逆向归档已完成。该说明只适用于此原件哈希。

- 产品为 Aspen Plus V15 与独立 Aspen Properties V15 共用。安装路径为 `C:/Program Files/Common Files/AspenTech Shared/AspenTech.Visualisation.Controls.Assistant.W1.dll`。文件版本 `27.0.0.25`，原 SHA-256 `8940700237f8d1372118930ba845573f59ec9f7f392e3e6381d3a22f290c3583`。
- 两份安装包的 MSI、CAB、成员名、来源行和清单 SHA-256 见 `.local/reverse-round-20261119-01/prior-evidence/8940700237f8/identity.json`。7-Zip 26.06 分别从两包输出相应成员，该文件与安装件的三方字节指纹一致。
- 本份成果为 `.local/reverse-round-20261119-01/01-completed/Plus-Properties/Program Files/Common Files/AspenTech Shared/AspenTech.Visualisation.Controls.Assistant.W1.dll.cs`，SHA-256 `39d3b14654ece4021c813426dc2db6feb3f83fe937f0b7bce5359aab167e2747`。助手的加载、XML 处理、导航、渲染、弹窗及 COM 互操作均纳入方法台账。六个 C# 闭包类在元数据及带符号 IL 逐一可查。27 个抽象或接口声明、8 个运行时委托声明及 1 个 COM 保留虚表槽均由原件标记证明无 IL 体。
- TypeDef 47（含无成员的 CLR 模块类型）、Field 129、Property 65、Event 3、MethodDef 254。原表与带符号 IL 声明令牌逐项相等。
- 218 个有体方法共 4931 条指令。原件经 dnfile 0.18.0 与 dncil 1.0.2 独立解析，核对全部指令偏移、操作码、操作数字节，及 36 个异常区的边界、类别和捕获类型。无体声明 36 个，逐个原因见 `.local/reverse-round-20261119-01/prior-evidence/8940700237f8/coverage.json`。
- ILSpy 与 ICSharpCode.Decompiler 9.1.0.7988；C# 逐行映射与既有整件文本仅统一换行和首尾空白再比对，各 ILFunction 的警告及失败标记均已检查。独立 IL 清单含原构造函数、折叠事件访问器及其他隐式成员，C# 声明与行号详见 `.local/reverse-round-20261119-01/prior-evidence/8940700237f8/source-map.json`。原版明确抛出的 NotImplementedException 有 1 个，原字节及对应 C# 行已列入 coverage.json。
- 原件内含 Win32 图标、组图标及文件版本，CLR 中一个资源集为空，另一个有 2 份 BAML、3 幅 PNG 和 1 幅 ICO。两份布局内的全部连接编号均与其助手控件 Connect 方法对应。 原生资源依据 pefile 2024.8.26 解析；各资源集的逐字节数据保存在资源表 `data_hex` 中，同时保留结构、成员名、尺寸与 SHA-256。
- 依赖边界。CLR/WPF、System.Web、XML 及已声明 GUID 的 COM 服务在接口处停链；UI 和 COM 运行时行为留待 Windows 阶段。 本阶段已解释影响文件完整性的问题；下一步按相同原哈希复用，Windows 构建、运行及行为对照留待后续阶段。
- 复核脚本在 `.local/reverse-round-20261119-01/prior-evidence`，操作及日志索引见同目录 `operations.md`。本次只作静态检查。
