# EntityFramework.dll 静态验收

**整件静态验收通过。** 原件为 Aspen Plus 与 Aspen Properties V15.0 共用的 Entity Framework 6.4.4，文件版本为 `6.400.420.21404`。安装原件位于 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/EntityFramework.dll`，SHA-256 为 `ff42bca704605e187abb45523868b15128d6af1c28ad40a4579d507d34a953b2`。旧报告读取 Git LFS 指针，本轮从安装原件恢复源码。

交付包含完整 IL、17 项托管资源、Win32 版本资源、组装脚本和上游 Apache 2.0 许可证。ILDasm 9.0.23 导出源码后，按原件方法头补回 994 个空局部变量表的 `InitLocals` 标志，并恢复原有的程序集 `DebuggableAttribute`。归档中编译用的 IL SHA-256 为 `694516e8d42194a048125ca176f139601e8d7ef23d41700be87ef54d73ff448e`。[源码包](EntityFramework.dll.source.7z) · [上游许可证](https://github.com/dotnet/ef6/blob/v6.4.4/LICENSE.txt)

| 核对范围 | 结果 |
| --- | --- |
| 方法与声明 | 27,829 个 CIL 方法体和 1,020 项无体声明按 MethodDef 令牌一致。逐指令对照操作码、分支、数值、引用目标及 2,668 个异常处理区。 |
| 程序集与类型 | 3,523 项类型定义、11 项程序集引用、公开密钥、程序集特性、字段、属性、事件与重写关系均已核对。 |
| 资源与初始化数据 | 17 项托管资源、1 项 Win32 版本资源和 41 项 FieldRVA 数据逐项一致。原托管资源区的 59 字节全零对齐由 ILAsm 紧排省去。 |
| 原件可执行节 | 已核销 CIL、入口导入跳转与各数据结构。其余字节全为零填充。 |

从仅包含交付文件的空目录运行组装脚本并重复上述比对。独立回编样本 SHA-256 为 `e2b919f845a947b27892c93a083bd89c713b7a294e778a0c8778225161662c05`。回编保留程序集公开密钥，产物无强名签名和 Authenticode 签名，PE 调试目录由原发布构建提供。Windows 上的签名、加载及行为对照留待重建阶段。[核验摘要及成员指纹](evidence/static-summary.json) · [逐方法摘要](evidence/methods.tsv.xz) · [资源及字段证据](evidence/resources-and-fields.json)

## 复编

用 7-Zip 将源码包解到空目录。在该目录用 PowerShell 运行以下命令，组装使用 Windows 自带的 .NET Framework x64 ILAsm。

```powershell
./build.ps1 -Output './out/EntityFramework.dll'
```
