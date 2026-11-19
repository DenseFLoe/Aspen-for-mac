# 启动页控件的托管代码

- 产品为 Aspen Plus、独立 Aspen Properties。安装相对路径为 `AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.Controls.StartPage.Wpf.dll`。两套安装包各自的 MSI、`APRS~273.cab`、成员键及指纹见本轮 `identity.json`。
- 原件为 97,320 字节。文件与程序集版本均为 `31.0.0.5`，自带的说明版本为 `V14.0`。本次直接读取安装位置并核对原件 SHA-256 为 `73193ded5722619da8d661035129f6a38968acad4ce371de83f0cc8158950b34`。
- 整件 C# SHA-256 为 `ae77a919d7fbf6f49c174811c4393ca15bf09d0033007982bef834d396ab6542`。托管实现已通过静态核验。整件归档判定和配套资源见本轮 `signoff.json`。

旧 C# 仅选取 `StartPage`。本轮在 .NET Framework 4.8 参考环境使用 ILSpy 9.1.0.7988 库的 `DecompileWholeModuleAsSingleFile`，关闭调试符号读取，保留声明和源代码行号。14 个顶层类型均出现在源码正文。3 个编译器生成的嵌套类型保留在附录，成员分别对应 RSS 刷新完成、首次接收响应和继续读取响应的闭包。三个回调体可在正文第 1217、1394、1412 行定位。

`code-coverage.json` 按原始定义令牌记录 245 个方法、94 个字段、87 个属性和 5 个事件。全部方法均有 IL 实现，总计 8,688 个指令字节。200 个方法通过 ILSpy 序列点关联到源码，20 个自动属性访问器逐条核对字段令牌和读写指令。对初次输出折叠的 25 个方法单独按令牌展开，源码附录保留构造器和事件访问器等实现。正文和定点展开均无反编译诊断。Roslyn 5.0 的 C# 语法检查没有诊断。

`StartPageUriConverter.ConvertBack` 的返回值在反编译后看似没有随 URI 检查而改变。定点核对令牌 `0x060000c9`，原件依次丢弃 `UnsetValue` 和成功构造的 URI，捕获异常后与成功路径共用返回原输入的指令。归档保留此实现。

程序集声明使用 WPF、XAML、System.Xml.Linq、.NET 基础类库及 `AspenTech.Visualisation.Controls.Support.Wpf`。主件中的连接器、图片加载和字符串访问器需结合配套资源阅读。代码中可定位外部命令、宿主委托、RSS 加载、调度定时器和导航的调用位置。界面交互、宿主命令、运行时语言选择、异步刷新和网络访问均留待 Windows 重建对照。

工作脚本位于 `.local/reverse-work-20261119-08-code/`。按 `export.ps1`、`select_gaps.py`、`expand_gaps.ps1`、`cover.py` 的顺序生成源码和令牌对应关系。`check-syntax.ps1` 和 `finalize.py` 记录语法及定点检查。各脚本与工具指纹、解析目录和逐项结果列于本轮根目录的 `code-coverage.json`。
