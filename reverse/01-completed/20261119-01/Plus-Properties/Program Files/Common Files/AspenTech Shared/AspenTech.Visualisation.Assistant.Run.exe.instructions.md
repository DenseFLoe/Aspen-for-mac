# AspenTech.Visualisation.Assistant.Run.exe · 带符号和字节的 IL

本轮 20261119-01，原文件静态逆向归档已完成。该说明只适用于此原件哈希。

- 产品为 Aspen Plus V15 与独立 Aspen Properties V15 共用。安装路径为 `C:/Program Files/Common Files/AspenTech Shared/AspenTech.Visualisation.Assistant.Run.exe`。文件版本 `27.0.0.25`，原 SHA-256 `59a90e21b8dae16538dd56ed4a1f69eb55c033be1f20e0567961c4ce2a7f8d8a`。
- 两份安装包的 MSI、CAB、成员名、来源行和清单 SHA-256 见 `.local/reverse-round-20261119-01/prior-evidence/59a90e21b8da/identity.json`。7-Zip 26.06 分别从两包输出相应成员，该文件与安装件的三方字节指纹一致。
- 本份成果为 `.local/reverse-round-20261119-01/01-completed/Plus-Properties/Program Files/Common Files/AspenTech Shared/AspenTech.Visualisation.Assistant.Run.exe.instructions.il`，SHA-256 `c1deec61782d8570edbdb699b91eff062c9795d6309e78ce1679a5d911d5cc00`。归档按方法令牌保存可读签名、泛型和成员引用、偏移、操作码、操作数字节及异常区；源映射表记录 C# 折叠的成员。入口 Main、启动事件的命令行与文件选择分支、逐文件显示助手窗口和顶层异常事件均可定位。App 的默认构造函数在 IL 中调用 WPF 基类。
- TypeDef 2（含无成员的 CLR 模块类型）、Field 0、Property 0、Event 0、MethodDef 5。原表与带符号 IL 声明令牌逐项相等。
- 5 个有体方法共 108 条指令。原件经 dnfile 0.18.0 与 dncil 1.0.2 独立解析，核对全部指令偏移、操作码、操作数字节，及 0 个异常区的边界、类别和捕获类型。无体声明 0 个，逐个原因见 `.local/reverse-round-20261119-01/prior-evidence/59a90e21b8da/coverage.json`。
- ILSpy 与 ICSharpCode.Decompiler 9.1.0.7988；C# 逐行映射与既有整件文本仅统一换行和首尾空白再比对，各 ILFunction 的警告及失败标记均已检查。独立 IL 清单含原构造函数、折叠事件访问器及其他隐式成员，C# 声明与行号详见 `.local/reverse-round-20261119-01/prior-evidence/59a90e21b8da/source-map.json`。原版明确抛出的 NotImplementedException 有 0 个，原字节及对应 C# 行已列入 coverage.json。
- Win32 图标、组图标、文件版本及应用清单均已逐项保存，图标组的子 ID 和大小闭合。程序集不含 ManifestResource。 原生资源依据 pefile 2024.8.26 解析；各资源集的逐字节数据保存在资源表 `data_hex` 中，同时保留结构、成员名、尺寸与 SHA-256。
- 依赖边界。助手加载与弹窗调用的目标签名位于同轮 W1 程序集。原程序界面、操作系统公共对话框及运行结果留待 Windows 阶段。 本阶段已解释影响文件完整性的问题；下一步按相同原哈希复用，Windows 构建、运行及行为对照留待后续阶段。
- 复核脚本在 `.local/reverse-round-20261119-01/prior-evidence`，操作及日志索引见同目录 `operations.md`。本次只作静态检查。
