# AxASCGridLib410.dll 静态复核

本机安装原件为 `[ProgramFiles64Folder]/AspenTech/OOMF V15.0/xeq/AxASCGridLib410.dll`，文件和程序集版本均为 41.0.0.0。2026-11-26 主干总表快照第 874 行将本件列在 Plus、OOMF V15.0、待静态验收。本地跨产品台账还将这份共享文件关联到 Properties。按原件指纹计一件。

**验收结论**　本次独立复核支持按主干静态验收标准将 v5 源码、资源和证据归入通过目录。同一份源码在本机固定依赖下编译，经归档内组合器回放，生成文件与安装原件的全部 24,616 字节相同。整件重放使用归档保留的 CLR 元数据和证书。运行时控件、COM 服务与事件联动留待 Windows 对照阶段。

| 对象 | SHA-256 |
| --- | --- |
| 安装原件与最终回放 PE | `c6e0de222bc056240cfbdd1356ed26f89430b7ad6ae55bf4cbd4d41e2e79f011` |
| 本轮独立解包的 AxASCGridLib410.dll.v5.zip | `af7aa15d528ddf27ad7b6f455142322b543139d5a68f4f318b86dfe31d58813a` |
| v5/source.cs | `c1850e859179f6725e1a2c72323ba4b76a22c83dffd98d3697a30570d1d1c248` |
| 此次从 ZIP 实编的原始 PE | `9ed97cd93dbb1adb8637a216878b4beefd3947c820568ba6faa87114a617a91d` |
| 归零 COFF 时间、PE 校验和与 MVID 后的 14,336 字节候选 | `66f3e62283c71846d7909ad474031fcc44155d3d89af8225d1d4a0856708ffa8` |
| 方法表 | `9bdb9bdd80054e4db1419b6b330e31b6fdc2e2d54f6f05cd9d5215b5eece749b` |
| 布局配方 | `5ae9144fa98ab47194f311b4fed9652baa7cdc04f4a4d029dc5d534b5cdfcec3` |
| 公开逐件证据 static-review.json | `d3243e9e3f15b6002d2bb64c220553e5e7d39e8121012c17b0f33510e9156632` |

逐方法核对使用独立的 System.Reflection.Metadata 读取器，直接对安装原件与从 ZIP 实编的 PE 解析。按声明身份匹配 105 个定义。89 个 CIL 方法的分支、计算、解析后调用目标、字符串、局部变量、最大栈、异常区域均吻合，涵盖 396 个令牌操作数及 10 个异常区域。其余 16 个方法是 4 种委托各自的构造、Invoke、BeginInvoke 和 EndInvoke 声明。全部声明的签名、方法标志、实现标志、参数及其特性一致。具体令牌、声明身份与语义摘要见 static-review.json 的 methods。原始令牌编号随编译器排表可变。

程序集身份、4 条依赖引用、16 个类型定义（含模块行）、25 个字段、24 个属性、4 个事件、56 条访问器关联、3 个接口实现和 66 条自定义特性的归属及内容一致。程序集与部分类型的特性排列有差异，在最终重放的原始元数据中恢复。4 个 AxHost 控件及事件、委托、订阅和 COM 接口关联均纳入核对。没有托管资源。两边唯一原生资源为 RT_VERSION/1/0，624 字节，SHA-256 `1217e54414ebf4188bb9123f556311ef0f620e7e6df931b3ca4aec5e127d9b6e`，从 v5/build/original.res 经编译器嵌入。

v5 ZIP 含 19 个文件，清单列出的 18 个成员均复核指纹，清单自身另由 ZIP 指纹绑定。独立确认归档中的 8,412 字节 CLR 元数据是安装原件的对应区段，10,280 字节证书表与安装原件该区段一致；证书有效性未作评定。调试记录与强名称槽为空。本次检查实际用了 Microsoft C# 编译器 4.8.4161.0、Python 3.12.10、pefile 2024.8.26、.NET 9.0.23 和静态读取器 ResolvedCilEvidence.dll（指纹见 static-review.json）。

## 复查

从版本 5 归档提取 source.cs、build 目录、layout-recipe.json、methods.json、original-build 目录和重放脚本。以 PEFILE_DIR 指向安装 pefile 2024.8.26 的目录。build/build-spec.json 固定 C# 编译参数和引用指纹。在解包目录运行下列命令，其中 fresh-output 应是新的输出目录。逐方法复查可对原件和 candidate.raw.dll 各运行一次同一静态读取器，按声明身份配对，核对 static-review.json 列出的语义摘要及事件关联。

```powershell
py -3 -B -I reproduce_c6.py --work fresh-output
Get-FileHash fresh-output/replayed.dll
```
## 工具入口与归档范围

实际重放入口为 v5/reproduce_c6.py，调用 v5/tools/replay_c6.py 组合既有冻结函数。冻结 token_replay2.py 的完整入口对非空 verified_methods 主动抛出异常；V5 组合器是面向本件的重放辅助工具。若另行要求验收冻结旧入口，仍应单列为未满足。本次通过结论限于该原件的静态交付与如上命令的逐字节结果。本报告为独立证据，未声称更新或认证项目验收器。主干移动时需保留已存在的来源版本及历史材料、完整 C#、资源和此报告，随总表一起更新。

[逐方法静态复核证据](evidence/static-review.json)

[接手续跑记录](evidence/AxASCGridLib410.dll.replay.json) · [历史归档说明](AxASCGridLib410.dll.%E5%BD%92%E6%A1%A3%E8%AF%B4%E6%98%8E.md)
