# AspenTech.AspenPlus.WpfPropertyControl.dll · 整程序集 C#

本轮 20261119-01，原文件静态逆向归档已完成。该说明只适用于此原件哈希。

- 产品为 Aspen Plus V15 与独立 Aspen Properties V15 共用。安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.WpfPropertyControl.dll`。文件版本 `41.0.0.614`，原 SHA-256 `7c889e92d1ac9a1f9093388376cf5c7e5c05e556fd377b65bee508c5cba2355d`。
- 两份安装包的 MSI、CAB、成员名、来源行和清单 SHA-256 见 `.local/reverse-round-20261119-01/prior-evidence/7c889e92d1ac/identity.json`。7-Zip 26.06 分别从两包输出相应成员，该文件与安装件的三方字节指纹一致。
- 本份成果为 `.local/reverse-round-20261119-01/01-completed/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.WpfPropertyControl.dll.cs`，SHA-256 `99e29e23e817e9724d299ef6fc34d9afb6daf2f711bb8c58e6fe7c18d9d4250c`。托管属性设置页、属性变更事件及初始化逻辑均纳入方法台账。合成静态/实例构造函数、字段初始化和事件访问器可按 MethodDef 跳到带操作数字节的实现。
- TypeDef 20（含无成员的 CLR 模块类型）、Field 168、Property 98、Event 8、MethodDef 249。原表与带符号 IL 声明令牌逐项相等。
- 249 个有体方法共 3128 条指令。原件经 dnfile 0.18.0 与 dncil 1.0.2 独立解析，核对全部指令偏移、操作码、操作数字节，及 0 个异常区的边界、类别和捕获类型。无体声明 0 个，逐个原因见 `.local/reverse-round-20261119-01/prior-evidence/7c889e92d1ac/coverage.json`。
- ILSpy 与 ICSharpCode.Decompiler 9.1.0.7988；C# 逐行映射与既有整件文本仅统一换行和首尾空白再比对，各 ILFunction 的警告及失败标记均已检查。独立 IL 清单含原构造函数、折叠事件访问器及其他隐式成员，C# 声明与行号详见 `.local/reverse-round-20261119-01/prior-evidence/7c889e92d1ac/source-map.json`。原版明确抛出的 NotImplementedException 有 0 个，原字节及对应 C# 行已列入 coverage.json。
- 原文件内含 Win32 版本信息。en-US 卫星包含 7 份 BAML 和 28 幅 BMP。逐个 URI 匹配 BAML，把 7 份布局内的连接编号集合逐页与 IComponentConnector.Connect 的 case 核对，每幅图像均完成读取。 原生资源依据 pefile 2024.8.26 解析；各资源集的逐字节数据保存在资源表 `data_hex` 中，同时保留结构、成员名、尺寸与 SHA-256。
- 依赖边界。en-US 卫星为本文件的布局接口证据。工程控件、本地化程序集、第三方颜色控件和 WPF 依赖以实际引用边界记录。 本阶段已解释影响文件完整性的问题；下一步按相同原哈希复用，Windows 构建、运行及行为对照留待后续阶段。
- 复核脚本在 `.local/reverse-round-20261119-01/prior-evidence`，操作及日志索引见同目录 `operations.md`。本次只作静态检查。
