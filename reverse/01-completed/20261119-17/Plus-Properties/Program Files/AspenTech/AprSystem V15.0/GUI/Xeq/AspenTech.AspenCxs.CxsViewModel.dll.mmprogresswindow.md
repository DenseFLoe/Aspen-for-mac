# MMProgressWindow 进度窗口布局

来源为 Aspen Plus 和 Aspen Properties 共用的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.CxsViewModel.dll`，文件和程序集版本均为 41.0.0.0，原件 SHA-256 为 `5c5f2208066ad33ff8d8da9d76c681f2a3c0c3508cdce9391f1aa585849516c0`。两套 MSI 中的成员与本机安装文件的归属及指纹见本轮 identity.json。

本 XAML 已通过静态布局验收。原件资源表 `AspenTech.AspenCxs.CxsViewModel.g.resources` 内含 `mmprogresswindow.baml`，负载共 1,248 字节，SHA-256 为 `d5e11ef90034c8d4e25bb85309986549aeff24ff99cd76018d94bd72ced70771`。WPF BamlReader 读至流末尾，覆盖 26 个节点与 10 个对象，恢复窗口、Grid、三行三列定义、ProgressBar 和 TextBlock 的结构、属性和命名。可编辑 XAML 的 SHA-256 为 `ed9b82cc50d38fa23a2a88f3946e74ae14e778c9933605d001ab0440c72f8711`。详见 layout-checks.json。

`IComponentConnector.Connect`（0x0600037B）分支 1 将 ProgressBar 写入 `progressBar`，分支 2 将 TextBlock 写入 `txbTimeRemaining`。窗口构造函数 0x06000375 订阅 Closed 和 Closing，对应处理器为 win_Closed（0x06000377）与 MMProgressWindow_Closing（0x06000376）。标题及剩余时间分别读取 MMProgressDlg_Title、MMProgressDlg_ETA。布局中的两个控件直接由 C# 更新，逐项 BAML 记录中有零个声明式 Binding。

Windows 重建时使用页面逻辑路径 `mmprogresswindow.xaml`。`InitializeComponent`（0x0600037A）通过 `/AspenTech.AspenCxs.CxsViewModel;component/mmprogresswindow.xaml` 加载页面。正式 C# 归档保留已恢复的 InitializeComponent、Connect 和命名字段。若以 WPF Page 方式编译此 XAML，在独立重建副本中将同一窗口类型设为 partial，让 WPF 生成的部分类提供这两个方法、`_contentLoaded` 及两个命名字段；在重建副本中去掉对应重复定义，保留原有构造函数和事件处理。实际渲染、关闭行为和进度更新留待 Windows 对照。
