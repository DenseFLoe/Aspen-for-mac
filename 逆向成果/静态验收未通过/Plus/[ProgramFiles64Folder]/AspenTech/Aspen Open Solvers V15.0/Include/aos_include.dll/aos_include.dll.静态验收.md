# aos_include.dll 静态验收

2026-11-21，验收四组第 1 轮。**静态验收未通过**，转失败修复组，复验组为 4。

伪 C 中有 4 处变量分配失败，且交付目录缺少可重建的 PE 资源。

## 原件身份

- 产品和原路径为 `Plus/[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Include/aos_include.dll`。
- 来源为 Aspen Plus V15 64 位 MSI 的 `Ars_In~2.cab` 的 `aos_include.dll.B9EEB0DC_5677_47CC_9351_9012BB37AA6B`。本轮复用已提取成员，复算完整原件指纹。
- 文件版本 `41.0.0.11`，原件共 482,856 字节。SHA-256 为 `017dc805c3b123f708c059ca2389ad234cfeeb8a466501016fb6045d693dc5ab`。

## 证据与修复条件

原件为 x64 原生 PE，入口 RVA `0x134C` 在两份正式导出中均能定位，PE 导出目录为空。用 Python 3 直接解析原件 PE，核对 IDA 9.5 / Hex-Rays 的函数和指令地址。反汇编、伪 C 的 2,987 个不同函数起点完全一致，原件 `.pdata` 的 1,511 个异常范围起点均可在反汇编定位。正式伪 C blob `d0a0abd9db46c0e3d6f9ddb4a7a6bf10845520b9` 与反汇编 blob `76e606b1ebae12f61c9966b56a5dd08dd296eea2` 已与本机既有 W2 发布包同件文件指纹交叉核实。

在正式伪 C 搜索 `local variable allocation has failed`，分别定位到 `0x18004F91C`、`0x180055810`、`0x180058D80`、`0x180058E38` 的函数。需按反汇编核对局部变量和寄存器活跃范围，修复受影响实现。原件资源树另含版本资源 `16/1/2057`（888 字节，SHA-256 `bc7c5e0990f323fe76648affe72ba48413d15b10c6c90a21e33024783759c6db`）和清单资源 `24/2/1033`（381 字节，SHA-256 `4bb79dcea0a901f7d9eac5aa05728ae92acb42e0cb22e5dd14134f4421a3d8df`）。当前对象只有报告、伪 C 和反汇编，需补充可编辑的资源重建输入及指纹核对，再交第四组复验。

[既有成果和制作者报告](aos_include.dll.%E5%BD%92%E6%A1%A3%E8%AF%B4%E6%98%8E.md)
