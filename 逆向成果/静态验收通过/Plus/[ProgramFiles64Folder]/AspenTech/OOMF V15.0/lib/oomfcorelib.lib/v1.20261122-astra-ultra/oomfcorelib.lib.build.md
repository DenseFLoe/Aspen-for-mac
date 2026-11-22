# oomfcorelib.lib.build.py

原件为 Aspen Plus V15（OOMF V15.0）安装成员 `Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，117,484 字节，SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。MSI 未登记该文件的独立版本字段。

构建器从同目录的六份汇编源码生成六个 AMD64 COFF 成员和 Microsoft 静态库。用 GNU as 组装指令和可编辑数据，将节尾标记、标签及 GNU as 产生的重定位换算为原 COFF 格式，随后生成两个链接器索引及长成员名表。源码顶部的 `@symbol` 声明保留符号类别和次序，`@section` 保留节标志。成员构建时戳取自 `@member` 声明。源文件或暂存对象中的局部标签用于计算位置。

`coff_ref.` 保留同成员符号或节符号上的显式重定位。`coff_rel32_4.` 对应跟有 4 字节立即数的 RIP 相对操作数。`coff_rva.` 对应展开表的映像相对地址。COMMON 符号以原始大小保留在相关 COFF 符号表中，同名符号在归档索引中按原映射选择成员。

本轮使用 CPython 3.12.14 和目标为 `x86_64-w64-mingw32` 的 GNU as 2.39。输入为六份 `.s` 文件，输出到调用者指定的空目录。用法见 [整件说明](oomfcorelib.lib.md)。构建脚本 SHA-256 为 `57a5cca7f03c32511d7db476cb4b5ba1a027a1e57bfaba4e122bb14cb16b98db`。六个成员及整库均已逐字节对回原件。Windows 行为验证留到后续阶段。[静态证据](evidence/static-verification.json)
