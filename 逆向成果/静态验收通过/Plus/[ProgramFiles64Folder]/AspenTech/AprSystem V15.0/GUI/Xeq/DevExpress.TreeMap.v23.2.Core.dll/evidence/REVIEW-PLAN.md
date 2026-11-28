# DevExpress.TreeMap.v23.2.Core.dll 独立复核的预先记录

复核员 `/root/reviewer`。母本为主干 `adbe73b517acac25da87598cce46de033f630ccb` 的单件静态判据。

- 输入：`producer/DevExpress.TreeMap.v23.2.Core.dll.source-v3.zip`，SHA-256 预期 `67c6146f79f59cb337076b6e54f557703249ba59363611359e8c753075672a0e`。安装原件 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.TreeMap.v23.2.Core.dll`，SHA-256 预期 `6b2379f21a1c6f408893b9a94e52ca44fa2546024fc35c6cb6e6d56a8dea46c5`。先验预期 185 个 MethodDef，其中 146 个非零 RVA、39 个抽象定义。原件以外的 DLL 不作为验收比较母本。
- 展开检查：`Expand-Archive -LiteralPath $zip -DestinationPath $clean` 到不存在的目录，列出所有 ZIP 条目、计算每个成员的 SHA-256，核对仅包含源码、必要资源、脚本和验收记录。预期无 DLL、PDB、原件证书文件或载荷回放文件。
- 正向构建：在展开根执行 `python -B .\reproduce.py --csc $csc --framework-refs $framework --devexpress-data $data --out $output --original $original --pefile-dir $pefile`，其中 `$output` 不存在。预期退出 0，源代码、Win32 RES、公钥 blob 加外置的 Roslyn 3.11 与四项编译引用共同产生一个 DLL。仅比较才需要安装原件、PowerShell 7 和 pefile。复核产物 SHA-256 对照预期 `77087b847b6964e530136ca1b47090dadc7bb509f9f93790a933ba68eae08ccf`，不得用该指纹替代逐件证据。
- 独立核验：用同一份 ILDasm 9.0.23 对两 DLL 分别执行 `/BYTES /TOKENS /RAWEH /UTF8 /OUT=<file>`。仅移除 MVID、方法 RVA 注释、进程映射地址注释及资源导出路径日志后，全量 IL 文本预期一致，方法体与抽象方法各自覆盖，原指令与操作数和绑定、异常、类型、字段、属性、程序集引用一致。两 *.res 导出预期逐字节一致。用 pefile 自己检查唯一 RT_VERSION 资源的类型/名/语言/代码页/内容，以及链接入口、唯一外部导入、重定位、CLR 标志和无 CLR 清单资源。保留 Win32 布局和签名的实际差异，预期候选无可验证厂商强名签名和 Authenticode 签名。
- 阴性对照一：复制展开目录，保留已核实构建入口、资源、依赖，将一个可达实现中的整数常量或算术操作单点变更，可复编。预期生成 DLL 的指纹变化，正式比较退出 2，独立 ILDasm 定位一个方法体内差异，资源仍相等。
- 阴性对照二：复制展开目录，保持 C#、公钥、编译引用及比较原件不变，按 RES 结构修改一个仍合法的版本资源值。预期正式比较退出 2，独立资源导出有差，方法/元数据仍相等。
- 适用范围为本程序集的静态完备性和构建复现。不给 WINDOWS 执行、装载、强名/Authenticode 替代签名及其他组件的行为作裁决。

