# NATIVE-340 s69 独立复验

**整件未通过静态验收。** 0x06000056 的 11 个 IL 调用站已补齐。两个包装方法的访问属性报告有误，0x06000057 的指针来源仍未绑定。覆盖 v1 退出 2，主表仍有 13 个托管、15 个原生未决调用。

主干基线 `0efdc367513b4850841dff1d13ebd78cb5cea67a`。候选 [#450](https://github.com/DenseFLoe/Aspen-for-mac/pull/450) 固定提交 `5ca17f4987251f32be4772955c8b9be3185b9c62`，父提交 `ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e`。PR 共改动 159 个路径，本次提交触及 11 个，另有 148 个沿用的改动路径。开始回执记载 2026-11-23 02:40:00 UTC，本轮提交时间 02:48:51 UTC，两条交付回执分别发表于 02:51:58、02:53:09 UTC。[首次回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7090274429) · [补充回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7090289801)

原件 WrapSaveMergeNNFiles.dll 的 SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。复验读取原始 PE/CLI 字节，未载入该 DLL。Windows 行为对照留给重建阶段。

| 核对项 | 独立结果 |
| --- | --- |
| 调用站 | 扫描 167 个有 IL 实现的方法。0x06000056 有 8 个直接调用方法、11 个站，附表每条的方法、偏移、操作码、包装器、ldftn 及实参都吻合。主表列出的 11 组方法、偏移和 ldftn 也吻合。0x06000057 无直接 IL 站。 |
| 补回的站 | 0B@0044 → 06，实参 ldarg.0。1F@0087 → 26，实参取局部 4 的地址。91@0077 → 23，取局部 2 的地址。补充回执把 1F@0087 解释成局部 3。 |
| EH、签名与指纹 | 35 个 EH 子句逐一吻合。两个包装器在 IL_0004 采用独立签名 0x11000075，blob 为 0001010F01。两个集合的 71、107 个路径及 SHA-256 全部吻合。提交说明曾写 70，以磁盘核对的 71 为准。 |
| 访问属性和相同 IL | .NET 元数据读出两方法的 Flags 均为 **0x4013**，含 Assembly、Static、HasSecurity。ImplFlags 均为 0，RVA 分别为 0x3E08、0x3E4C。候选表和主表写成 privatescope/0x0。两份 IL 共用完整 SHA-256 `cf6b47445b3281297d160b230f3d5a4c08006679b0b937098c432073b5ee0b0d`，候选 il_sha256 只写前 32 个字符。 |
| 元数据引用 | 两方法都归属 <Module>，未找到同 RVA 的其他 MethodDef、同名或以它为父项的 MemberRef、直接连接的 MethodImpl 和 MethodSpec。两个独立令牌可有相同 IL。 |
| 混合模式入口 | 原件有四个 RIP 相对跳转与四个 CLR 修补槽配对。对于 56，RVA 5574、557A 分别跳到 19600、19608。对于 57，5584、558A 分别跳到 19610、19618。每对槽的类型依次为 0x2、0xA。PE 唯一导出位于 50A0。DIR64 重定位中未找到直接指向这四个跳转或槽的指针。以上证据确认模块内入口，实际调用这些入口及向其传入 arg0 的生产者尚待识别。 |

修复优先从 MethodDef 表读取 Flags 和 ImplFlags，按实际标记宽度解码 MemberRefParent、MethodDefOrRef，并用正反输入验证引用统计。更正主表、访问表、回执及完整 IL 指纹；把 57 的缺口限定为已识别入口上尚未证实的来路。在没有实参来源证据时保留未决。对站点、35 个子句和两套指纹同步复验。[实测数据](s69-recheck.json) · [复现和工具反馈](s69-verifier-notes.md)
