# NATIVE-340 s77 末次增量复核

从已收件 `858a23f9070d0a99555b695082d4dc57a4c13258` 到 [#450 新头](https://github.com/DenseFLoe/Aspen-for-mac/tree/4d0a79787d8a093e721e5873519e8387f3fa4a13) 共九路差异。审计表头、报告和预检入口更新，两套更新后的交付指纹复算分别为 83、123，差异均为空。槽位释义、MethodImpl 解码表达式与生产表流列宽问题仍在；原件复验和 returned 继续适用。

新 `tool/preflight.py` SHA-256 `7189db9f23d1672ed5ea995a8fa3ba2c59bfff1ef28f4a6de296a85f3a9bf64c`，blob `b44f6a0a75d58edfdc0f2d80a68eb366e9de047a`。固定头读取 `tool/det_registry.py` 和 `tool/preflight_fetch.py` 均返回 404。原件按任务卡 SHA-256 固定。分别用干净工具目录执行以下两个入口以隔离 L2 依赖。

~~~powershell
python -I -B tool/preflight.py --task NATIVE-340 --skip-l1 --item-dir CANDIDATE --original ORIGINAL
python -I -B tool/preflight.py --task NATIVE-340 --skip-l1 --head 4d0a79787d8a093e721e5873519e8387f3fa4a13 --original ORIGINAL
~~~

预期两个入口都能加载固定版本的检测器并输出检查结果。实测均 exit 1，首种缺 `det_registry`，第二种缺 `preflight_fetch`，均未进入检测。建议将依赖纳入可回读工具包并固定清单。在干净目录中以同一真实候选验证两个入口均产生报告。只删一项声明依赖的对照应明确报告缺包和路径。 [裁定](s77-decision.md) · [对照](https://github.com/DenseFLoe/Aspen-for-mac/compare/858a23f9070d0a99555b695082d4dc57a4c13258...4d0a79787d8a093e721e5873519e8387f3fa4a13)