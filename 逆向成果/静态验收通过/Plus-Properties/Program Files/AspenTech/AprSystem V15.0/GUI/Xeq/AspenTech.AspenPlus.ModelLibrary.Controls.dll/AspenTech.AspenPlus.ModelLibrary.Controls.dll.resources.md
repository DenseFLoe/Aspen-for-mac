# AspenTech.AspenPlus.ModelLibrary.Controls.dll · 资源及结构对照

本轮 20261119-01，原文件静态逆向归档已完成。该说明只适用于此原件哈希。

- 产品为 Aspen Plus V15 与独立 Aspen Properties V15 共用。安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.ModelLibrary.Controls.dll`。文件版本 `41.0.0.614`，原 SHA-256 `9ba840c0becd41bcc929409b2f30e47a74bb652efdd5b684625cc972af86fdf1`。
- 两份安装包的 MSI、CAB、成员名、来源行和清单 SHA-256 见 `.local/reverse-round-20261119-01/prior-evidence/9ba840c0becd/identity.json`。7-Zip 26.06 分别从两包输出相应成员，该文件与安装件的三方字节指纹一致。
- 本份成果为 `.local/reverse-round-20261119-01/01-completed/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.ModelLibrary.Controls.dll.resources.json`，SHA-256 `13d0876cf500dc6a67aa8eaf8492579baa72429de6030a9236871a8d98019d80`。原文件内含 Win32 版本信息。en-US 卫星的 themes/generic.baml 有 273 个布局节点；GetTemplateChild 的四个原名均在该布局中找到，模板字节和解析结构均保留。
- TypeDef 24（含无成员的 CLR 模块类型）、Field 104、Property 70、Event 8、MethodDef 263。原表与带符号 IL 声明令牌逐项相等。
- 263 个有体方法共 3185 条指令。原件经 dnfile 0.18.0 与 dncil 1.0.2 独立解析，核对全部指令偏移、操作码、操作数字节，及 5 个异常区的边界、类别和捕获类型。无体声明 0 个，逐个原因见 `.local/reverse-round-20261119-01/prior-evidence/9ba840c0becd/coverage.json`。
- ILSpy 与 ICSharpCode.Decompiler 9.1.0.7988；C# 逐行映射与既有整件文本仅统一换行和首尾空白再比对，各 ILFunction 的警告及失败标记均已检查。独立 IL 清单含原构造函数、折叠事件访问器及其他隐式成员，C# 声明与行号详见 `.local/reverse-round-20261119-01/prior-evidence/9ba840c0becd/source-map.json`。原版明确抛出的 NotImplementedException 有 4 个，原字节及对应 C# 行已列入 coverage.json。
- 原文件内含 Win32 版本信息。en-US 卫星的 themes/generic.baml 有 273 个布局节点；GetTemplateChild 的四个原名均在该布局中找到，模板字节和解析结构均保留。 原生资源依据 pefile 2024.8.26 解析；各资源集的逐字节数据保存在资源表 `data_hex` 中，同时保留结构、成员名、尺寸与 SHA-256。
- 依赖边界。主题卫星补足模板资源证据，MMControls 与 Localization 按本程序集调用的接口边界记录。 本阶段已解释影响文件完整性的问题；下一步按相同原哈希复用，Windows 构建、运行及行为对照留待后续阶段。
- 复核脚本在 `.local/reverse-round-20261119-01/prior-evidence`，操作及日志索引见同目录 `operations.md`。本次只作静态检查。
