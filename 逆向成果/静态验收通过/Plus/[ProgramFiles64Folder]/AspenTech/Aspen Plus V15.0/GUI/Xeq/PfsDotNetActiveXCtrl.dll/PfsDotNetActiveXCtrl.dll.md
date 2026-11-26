# PfsDotNetActiveXCtrl.dll

**静态验收通过。** 原件来自本机 Aspen Plus V15.0，文件和产品版本均为 `41.0.0.614`。原相对路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/PfsDotNetActiveXCtrl.dll`。原件为 24,104 B，SHA-256 为 `4bb238de3a4452fee88a3f4e53f21da95d5af7499ea7fb0ac95deaf495ee41ba`。

以 .NET SDK 9.0.321 附带的 Roslyn 和归档中固定的 270 条引用重新编译[完整 C#](PfsDotNetActiveXCtrl.dll.cs)。独立使用 ILSpy 9.1 按类型和声明对照，67 个完整方法块均匹配。35 个 CIL 方法重绑 7 个令牌后，其方法头、完整指令和异常区逐字节相同。另有 26 个抽象接口声明和 6 个 P/Invoke 声明。按 `InitializeComponent` 和构造方法核对控件尺寸、字体缩放、双缓冲以及 Load、SizeChanged 事件订阅，按 BeginPPSetting、EndPPSetting 核对 ElementHost 与子控件的嵌入和切换。

原件和直接回编件的 1 项 Win32 版本资源和 1 项托管资源内容相等。直接回编件为 13,824 B，SHA-256 为 `ca9ae17df025e68622cb63660df91eac2b2f92dfa983a2abb08732f182870ea7`。固定包 `package3.zip` 的 SHA-256 为 `04ce79a58d3069e4f279e0d6f0413edc64ba25f2d27d7cc6a3791dde5846a077`。从空目录用包内脚本执行 `py -3 token_replay.py <归档路径> <新输出目录>`，编译器、引用和资源按包内指纹核对，Python 环境需提供 pefile。独立复核和本次接手续跑均复现原件的全部 24,104 字节。把控件宽度从 242 改为 243 的副本仍可编译，随后被回放检查拒绝。

直接回编与原件的 CLR 元数据有可定位的差异，例如 Roslyn 给 `IEmbedObject` 增加 `beforefieldinit`。最终映像按包内保留的原件 CLR 元数据、调试记录和证书表恢复布局。界面运行行为及签名有效性留待后续核验。

[独立逐方法复核](evidence/static-review.json) · [接手续跑与编译输入](evidence/PfsDotNetActiveXCtrl.dll.replay.json) · [历史归档说明](PfsDotNetActiveXCtrl.dll.%E5%BD%92%E6%A1%A3%E8%AF%B4%E6%98%8E.md)
