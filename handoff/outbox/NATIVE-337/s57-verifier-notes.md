# NATIVE-337 s57 清单路径复验

生成器 `tool/s37_two_hop.py` SHA-256 `91bacaa9e7a7a75f9e344958b42c6a58b85b6861b9985ed060ac7d679ab62ba5`，候选固定 head `fdad14b1ab1e3a4ed59c58a79c6b9337a69dc586`。按 [覆盖证据 v1](../../standards/native-coverage-evidence.v1.md) 对应关系第 4、5 条，调用证据使用本件根目录的相对路径及准确行号。

在隔离工作目录内将固定候选放在 `fixed/`，同哈希原件放在 `fixed/_t13/orig/FindComponent.dll`。将 [布局构造脚本](s57-layout.py) 和 [子目录对照脚本](s57-nested-control.py) 置于同一工作目录，再依次运行 `python -B s57-layout.py fixed` 与 `python -B s57-nested-control.py`。后者复用前者的拆分件，原样移动 `native-part.asm` 到 `code/fragment/`，并只替换调用表中指向该文件的路径。两份对应清单的 SHA-256 相同，详见 [复验记录](s57-layout.json)。

预期仍有 161 站，0x12DA 指向第 528 行。实际同目录版 161、子目录版 160，两个生成命令均退出 0。生成器用非递归 glob 列举文件并用文件名索引，未跟随真实相对路径。建议按完整相对路径定位证据，并在引用缺失时报告具体文件及行；本对照修正后应保留两站、161 站和子目录输出路径。提交中仍需固定两个规定布局的输入及产物指纹，便于复验。
