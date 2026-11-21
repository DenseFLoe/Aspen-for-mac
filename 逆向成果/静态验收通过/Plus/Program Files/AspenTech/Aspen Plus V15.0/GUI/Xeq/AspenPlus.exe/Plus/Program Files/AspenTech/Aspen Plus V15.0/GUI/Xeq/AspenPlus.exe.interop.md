# AspenPlus.exe.interop.json 的静态逆向说明

原件为 Aspen Plus V15 `GUI/Xeq/AspenPlus.exe`，版本 `41.0.0.614`，SHA-256 `006d17165e434fb9263c5614844352604a72cf727a929a7174f1aca002c39bf9`。安装包成员和两条来源见[逐件说明](AspenPlus.exe.md)。

本材料通过静态验收。`original` 保存六个 COM 导入接口、21 个无 IL 体的方法定义和三个属性的声明顺序、标记、继承关系、签名、特性与封送方式。`windows_build_metadata` 记录 Windows 重建时需要恢复的原版元数据。

以 Mono.Cecil 0.11.6.0 从原件读取声明，再用 Roslyn 对已恢复源码中的 COM 声明单独生成内存样件。核对发现六个接口多出 `BeforeFieldInit`，两个接口多列传递祖先，四个 `_VtblGap` 的方法标记与实现标记不同，两个属性 setter 的入参名不同。按本清单改回这些元数据，再将样件写入内存并读回，已记录的类型、方法与属性元数据全部与原版匹配。Windows 阶段对照实际 COM 调用。

[COM 接口元数据](AspenPlus.exe.interop.json)

本文件 SHA-256 `41744d83a1a3c72d5e58f190eccb8244fc9f8b921249f4c8b89f1c5c9b9c9494`。
