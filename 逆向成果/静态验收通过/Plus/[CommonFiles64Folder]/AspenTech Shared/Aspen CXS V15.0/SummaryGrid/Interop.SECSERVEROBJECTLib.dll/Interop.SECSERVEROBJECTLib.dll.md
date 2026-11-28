# Interop.SECSERVEROBJECTLib.dll

Aspen Plus V15.0 使用的共享 COM 互操作程序集。安装原件在 `C:\Program Files\Common Files\AspenTech Shared\Aspen CXS V15.0\SummaryGrid\Interop.SECSERVEROBJECTLib.dll`，产品与文件版本均为 2015.0.1.361。原相对路径为 `[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/Interop.SECSERVEROBJECTLib.dll`。程序集版本为 4.0.0.0，Culture 为 neutral，PublicKeyToken 为 e0d60c9dbdf192b7。原件 31,608 字节，SHA-256 为 `a1b19af66ce615764eec35d8a5489e426aa2a62cfb2a1f551c13b88b5258e5c1`。

## 来源与范围

本轮按 main `ba0c945804c33338edfb24d193b20f10d35186f5` 的逐件标准制作，对应目录为 `逆向成果/待静态验收/Plus/<原相对路径>/`。该目录既有 C# 与 IL 导出保留原状。历史 v2 ZIP 的 SHA-256 为 `745b72557757ba5a6884e7945feaf28715bd3b1d725a050c303819a2a8859e33`。v2 的 C# 候选 fef9eba5… 对照中有 143 个方法块全等、124 个配对方法缺 override，原件和候选各有 23 个不能按名配对。v2 的 exact 分支整段复用了原件 CLR 元数据。历史 exact 的 290/290 结果仅归于该回放。

本件延续同批完整 IL 候选，早期 IL ZIP 的 SHA-256 为 `6eb2ca6ab0389c644a6a76b179ecd961b5ea0559ae73e4a25e41a5665a8835a3`。逐项补足 ILDasm 文本与 ILAsm 输出之间的声明差异。正式源码为同目录 `Interop.SECSERVEROBJECTLib.dll.il`，必要的版本资源以 `version.json` 保存。此次构建只读取源码、本包 Python 工具、Windows 的 ILAsm 和本次生成的中间文件。保留原件的公钥、属性值、签名和资源值，均以可编辑声明或资源字段参与构建。原件 PE、原 CLR 表/堆、程序集中间二进制、证书、强名称签名字节及原始资源载荷均未作为构建输入。

## 空目录复跑

Windows Python 3.12.10 标准库和 .NET Framework 4 ILAsm。已测试的 ILAsm 位于 `%WINDIR%\Microsoft.NET\Framework\v4.0.30319\ilasm.exe`，版本 4.8.4161.0，SHA-256 为 `8187cb164a61cf4fc4a4f68955f4d3c55c322f7509fc1dbc9b02b2b9feeecd57`。解压到新目录，在包根执行下列命令。也可通过 `--ilasm` 指定等同版本的工具。

```powershell
python -B build.py --out build
Get-FileHash -Algorithm SHA256 build/Interop.SECSERVEROBJECTLib.dll
```

输出为 `build/Interop.SECSERVEROBJECTLib.dll`，24,576 字节，SHA-256 为 `53c4a92c3c4f93e269a18d7e69a9518de8d8bffe4614d87872381c0cfa747d81`。中间文件 `assembly.il` 供追查 ILAsm 输入，`version.res` 从 JSON 重新编码，836 字节，SHA-256 为 `9f60304bae9a41e1e54fbb7f359b3a5e56fe9727c0e59ababb3e30e508d29c1c`。重复构建时另给新的空输出目录。

## 声明与资源

17 张有行的 CLI 表共 2,055 行。逐表记录列在 `proof.json`，包含 290 个原件 MethodDef 的令牌、完整所有者、方法名、签名、标志和 RVA，以及 135 个 MethodImpl 的类、方法体端点与声明端点。逐项按所有者和已解析的引用核对。两边有 36 个 TypeDef（含模块）、48 个字段、290 个无体方法、821 个 Param、27 个 InterfaceImpl、12 个 MemberRef、38 个 Constant、151 个 CustomAttribute、418 个 FieldMarshal、26 个属性和 26 个 MethodSemantics。全部 290 个 MethodDef 的 RVA 为零，原件使用 runtime/internalcall，无 CIL 指令、分支、调用或异常区。接口绑定和返回值、实参的 marshal 信息均由源码构建。程序集引用仅有 mscorlib 4.0.0.0（b77a5c561934e089），没有 P/Invoke 映射。

源码中 `.override` 产生全部 135 个绑定。30 处 `@emit-empty-param` 明示空返回 Param 行；22 处 `__unnamed_cli_parameter__` 明示参数名缺省。构建入口用临时标记令 ILAsm 生成这些行，然后去除临时标记并恢复空名称。根据 `@retain-marshaling-reference` 与空返回参数标记，保留两个未被最终声明引用的构造函数 MemberRef（System.Object::.ctor 和 MarshalAsAttribute::.ctor(UnmanagedType)）及所需类型。字段编组取自 IL 中的 marshal 子句；`@safearray-encoding element-type-only` 明示 36 个 SAFEARRAY 使用仅含元素类型的编码。构建入口去掉 ILAsm 额外生成的空类型名。418 个编组描述符逐字节核对。

唯一 Win32 资源为 RT_VERSION/1/0，772 字节，语言 0，目录代码页 1252，保留字段为 0，载荷 SHA-256 为 `46e05dd0db602b3e8fd6d1af822ddfa57a3784da9028d1c0e49b9b5443811cdf`。固定版本字段、字符串及翻译表由 JSON 独立生成，构建入口从同一资源定义设置 PE 资源代码页。两件托管资源长度均为零，无 WPF 引用、BAML、XAML、界面控件、事件或数据绑定。

## 核对证据与边界

`compare.py` 对安装原件与新 DLL 逐行检查表内容和依赖；`compare_listing.py` 使用 ILDasm 9.0.23 额外比对两边的解引用签名、属性与每条 override 的上下文，仅在同一所有者内排序相邻自定义属性，单列 CorFlags、MVID 与工具注释。`listing-check.json` 记录 2,487 条规范化记录全部相同，规范记录摘要为 `c2ecb0a22478cdaa23372679b776a7981e7c94e6245b7bc98fa2bc0915bf2181`。

下列命令中的 `$Original` 指向本件安装原件。`$ILDasm` 指向 Microsoft ILDasm 9.0.23，工具 SHA-256 为 `79509cec19209578a6b8a7e6aff3e5ae5e75d3a21c59107021f7e99ad4888541`。这两个输入只用于核对。构建入口无需 ILDasm。

```powershell
python -B compare.py "$Original" build/Interop.SECSERVEROBJECTLib.dll fresh-proof.json
python -B compare_listing.py "$ILDasm" "$Original" build/Interop.SECSERVEROBJECTLib.dll fresh-listing
```

PE32、I386、ILONLY，32BITREQUIRED 与 32BITPREFERRED 均为零；两件平台声明均为 AnyCPU。程序集公钥 SHA-256 同为 `105a35adfc3a78042b66f92ddc047f2fa43e20182600e789b2a1f986c97da1cc`。签名差异单列：原件 CorFlags 为 0x9，强名称槽有 128 字节非零签名数据，PE 证书表为 7,032 字节。新件 CorFlags 为 0x1，强名称槽为 128 字节全零，PE 证书表为空。构建时间戳置零，MVID 根据新构建内容生成。元数据堆、部分引用与自定义属性排序、文件布局及整件 SHA 随构建而异。

制作方裁定为原件级静态声明与资源比对通过。当前包交独立复核及总控空目录复跑。实际 COM 服务器调用、Windows 宿主装载与签名策略适用性留待 Windows 重建对照；未执行行为测试。`SHA256SUMS` 覆盖本包所有其他成员。

## 本批验收结论

任务复核员从定版包回编并核对了 17 张 CLI 表、全部 290 个无体方法声明、135 条方法绑定、418 条 COM 封送记录和唯一 Win32 版本资源。总控在另一空目录复跑，产物 SHA-256 和核对结果一致。包的 SHA-256 为 `5e48be11ded4a853d62f0c30fab4acda957754447cb9346032820e8b9f284203`。

[独立复核](evidence/independent-review.json) · [总控复跑](evidence/controller-receipt.json)
