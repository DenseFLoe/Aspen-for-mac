# 网格表单主库的 C# 发布选取件

这份代码来自 Aspen Plus V15 与独立 Aspen Properties V15 共用的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.GridForms.dll`，文件及程序集版本均为 41.0.0.614。Plus、Properties 的原包成员与安装件均为 528,424 字节，SHA-256 为 `e404e43bee7f55f6927cfa7d411343a3e37a371a286a9d424c05f3db1f85a614`。[归属与原件](../../../../../../evidence/identity.json)

本机整件 C# 的 SHA-256 为 `7914812100645a0c5c8978cc28cc5c0de1807d91d2ccfdc4355263f0ec1b806b`。同目录的 `AspenTech.AspenPlus.MMForms.GridForms.dll.01.cs` 为可编辑选取件，含 34,606 行、1,037,778 字节，SHA-256 为 `6b86db8b367d3275bd515fdf53261410cdc33b9b7d846c9fcdb069fbc917506c`。逐字节比对保留的九个行段，覆盖窗口和网格操作、变量查询、外部引擎调用及直接使用的接口。Roslyn 语法读回通过。[选取范围、令牌与指纹](../../../../../../evidence/code-extraction.json)

本机保存原始曲线点初值、两个切割区间表、组分归一化及其求和、两个浓度缩放显示方法、子属性值汇总，以及重复出现上述初值的静态构造器附录。区间表同属一个字段声明。选取清单给出两项字段声明、五项方法声明和一段静态构造器附录的原始行号及指纹。其余代码仍可见对这些成员的调用。使用完整实现及开展 Windows 行为对照时，以本机整件归档为准。

