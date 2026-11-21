# 物流表单库的 Windows 版本资源

Aspen Plus V15 与 Aspen Properties V15 均将本件安装在 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Streams.dll`。两个 MSI 的成员名均为 `aspentech.aspenplus.42.01AE6323_4069_4985_B882_1C2F459EE258`，File 序号依次为 1887、1524。已核对两个安装包、各自 CAB 的当前指纹和既有 FDI 成员记录。两份成员与已安装文件均为 201,768 字节，版本 41.0.0.614，SHA-256 为 `8a5f90aa62dc4d00cdc4706ba995a9117cdbf24cf3d4b7929dfc17aaf512f61b`。本轮 `Plus-Properties/evidence/identity.json` 保存原始记录、安装路径、版本与指纹。

同目录的 `AspenTech.AspenPlus.MMForms.Streams.dll.version.rc` 通过静态资源验收，SHA-256 为 `c05c82222e2893e04ff3d7576f4e45321fa2ec9222e569cb2f0526650b0d3278`。用 dnfile 0.18.0 和 pefile 2024.8.26 遍历原件资源目录，仅有 RT_VERSION 一项，名称 ID 为 1，语言 ID 为 0。RC 恢复了固定版本字段、11 个字符串字段及语言和代码页 0/1200。用 GNU windres 2.39 独立编译 RC，重新读取其版本块后，1,102 字节均与原件一致，版本块 SHA-256 为 `effcfc4eed90db0516a8fe2f805f675f80107695e5dbdb3841334dadde2d561e`。本轮 `Plus-Properties/evidence/resources.json` 记录目录位置、各字段及回读结果。

本件 CLR 资源区的 RVA 和长度均为 0，无 ManifestResource 记录。Mono.Cecil 0.11.6 对 810 个方法定义逐一检查，查到 11 个方法中的 24 处固定字符串调用。16 个外部取值器均按完整签名、取值器 IL 和字符串键对应到三个资源表。另一个方法在第四个表中使用运行时生成的键查询流股类型，分别访问资源管理器和语言属性一次。该表含 192 个字符串，其中与 `rectype_streams_` 前缀相符的键有 `heat`、`material` 和 `work` 三个后缀。若查不到非空文本，该方法沿用传入的原始流股类型值。中性语言为 en-US，最终回退位置为卫星程序集。本轮 `Plus-Properties/evidence/localization.json` 记录固定及动态调用的位置与资源表指纹。

版本资源已完整恢复。Windows 重建后可对照文件属性，并在实际语言环境下核对流股类型的显示文本。
