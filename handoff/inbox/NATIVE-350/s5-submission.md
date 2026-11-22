# zedstwu.dll 第五号提交

NATIVE-350，assigned_seq=5，owner upstream。以 [任务卡](../../assignments/NATIVE-350-s5.md) 的 41.0.0.609 版原件为输入，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。[四个可编辑导出、逐件说明与核验工具](s5/) · [本轮清单](s5-manifest.sha256)

使用 Zig 0.13.0 生成 Windows AMD64 COFF，按原 RVA 处理重定位后比对原件。四个导出 EUDL01、IUDL01、UDL01I、ZUDL01 依次匹配 90、694、9,093、3,341 字节，合计 2,179 条指令、812 处相对重定位、13,218 字节。两条导入记录分别核对真实数据读取和缺少已知调用者的导入桩。[各函数字节、分支、调用和指纹](s5/business-evidence.json) · [供需两件原版对照](s5/import-data-evidence.json)

255 个入口中 134 个已核、121 个仍待补齐。3,567 条引用包括 636 条外部、2,887 条数据和 44 条未决。沿用第一轮固定候选 `30717e476e2182c3f62db16f48e37c242043a379` 的原始 ASM/C 输入、可编辑复制路径、资源和原件清单。其余入口需按覆盖表补源码及具体依赖，不计整件通过。

在本件目录可执行 `python -B s5/check-business.py <zedstwu.dll> <zig> --output <输出 JSON>` 和 `python -B s5/check-import-data.py <zedstwu.dll> <ppexec.dll> <原始 IDA 列表> --output <输出 JSON>`。仓库根执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <zedstwu.dll>`。原始 ASM 与 C 的位置与指纹见[第一号任务卡](../../assignments/NATIVE-350.md)。
