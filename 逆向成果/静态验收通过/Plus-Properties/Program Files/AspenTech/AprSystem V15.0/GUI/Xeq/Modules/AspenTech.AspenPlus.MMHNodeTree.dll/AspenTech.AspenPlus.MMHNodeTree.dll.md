# AspenTech.AspenPlus.MMHNodeTree.dll · 整程序集 C#

第 20261119-02 轮，原文件静态逆向归档已完成。版本为 41.0.0.614，原件 SHA-256 为 `48df7cfdf332591d83ace7883898d3a9f47971c41da16618555179e22221a073`。

- 此文件为 Aspen Plus V15 与独立 Aspen Properties V15 共用。原安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AspenTech.AspenPlus.MMHNodeTree.dll`。.local/reverse-round-20261119-02/nodetree-evidence/identity.json 保存两个原版 MSI/CAB 的完整路径、包内成员和原分类行。两个包及本机安装件共三条来源，字节指纹逐件相同。
- 本份整程序集 C#保存在 `.local/reverse-round-20261119-02/01-completed/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AspenTech.AspenPlus.MMHNodeTree.dll.cs`，SHA-256 为 `71bca854da84211963a48066c3fd77729b8bbb6e2d26bcb2164e04b7c191b78f`。保留全部 9 个用户类型和程序集声明。两个 COM 参数属性改用显式访问器，并保留原件声明的参数、获取/设置顺序与封送。可按 com-projection.json、correction.diff 和 coverage.json 的访问器令牌复核。自动生成的构造函数、事件访问器和字段初始化的实际 IL 均有行号记录。
- 完整性覆盖 9 个用户类型和无成员模块类型、71 个方法、27 个字段、26 个属性、2 个事件。61 个有体方法共 575 条指令和 4 个异常区。6 个嵌入 COM 接口函数及 4 个保留虚表槽在原件中无体。原有两处空鼠标处理器均由 IL 的 ret 核实。
- `.local/reverse-round-20261119-02/nodetree-evidence/coverage.json` 记录成员令牌、C# 序列点、精确 IL 行号、方法指纹、程序集和依赖边界。资源的结构、文本及字节保存在 `.local/reverse-round-20261119-02/nodetree-evidence/resources.json`。工具版本、可重复执行的命令和签名修正经过见 `.local/reverse-round-20261119-02/nodetree-evidence/operations.md`。
- 控件按命名注册，依据输入 COM 节点生成树并更新选择提示。依赖关联核对到 Unity、Composite、WPF 和两份嵌入的 COM 接口。静态完整性所需的引用、参数和资源均已核实。下一阶段在 Windows 对照原版容器注册、COM 节点输入及界面交互。
