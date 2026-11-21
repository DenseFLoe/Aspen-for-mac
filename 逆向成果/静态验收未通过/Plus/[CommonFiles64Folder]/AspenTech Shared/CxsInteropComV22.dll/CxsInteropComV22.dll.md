# CxsInteropComV22.dll 静态验收

## 当前结论

**静态验收未通过，交修复组，复验组为 1。** 这轮核对了已交付的 x64 原生 COM DLL 的伪 C、反汇编与原件结构。可编辑交付缺少参与 COM 注册和激活的资源及内部对象表定义。Windows 行为对照留到重建阶段。

## 原件与现有交付

- Aspen Plus V15.0，`Plus/[CommonFiles64Folder]/AspenTech Shared/CxsInteropComV22.dll`，文件及产品版本均为 `41.0.0.0`，189,992 字节，SHA-256 为 `00501719049fd979b6159fc7aa617f1b70b28c3ba0d76a52c4d7560a978aaa09`。按既有安装包来源表复用 `AspenC~5.cab` 中的 `cxsinteropcomv22.dll.EE6C3CBB_DF50_4232_91D3_85932AA31A5F`，与本地只读提取件重新比对 SHA-256。
- W2 与分支交付的伪 C 共用 blob `ab538f836795d404a8493e9ad906ffa6043286f8`（SHA-256 `dad361489c62888569b3de39c9381feff081a76d2527513b180f903eb6eb981a`）。反汇编共用 blob `1b7b0ec00b7e48bf61fa2861c4b6e440399ef6b2`（SHA-256 `64b178962a822ec941548d7ba7e4b1bf27b8dcf8c09954d96cf96fa163b4cfa6`）。各自只复核一次。
- [现有伪 C](分支交付/decompiled/CxsInteropComV22.dll.c.txt) · [现有反汇编](分支交付/disasm/CxsInteropComV22.dll.asm.txt) · [W2 制作者报告](v0.20261121-w2/制作者报告/CxsInteropComV22.dll.md)

## 覆盖记录

- `pefile 2024.8.26` 从 PE 读出机器类型 `0x8664`、CLR 目录为零、镜像基址 `0x180000000`。两份正文按 `FUNC` 头的地址和名称比较，650 个条目一一对应，其中 `.text` 649 个，`.orpc` 1 个。入口 RVA `0x9910` 与导出 RVA `0x6dd0`、`0x6e00`、`0x6fa0`、`0x7020` 都有对应条目。
- `pefile` 从 `.pdata` 读出 513 个运行时范围。以 `BeginAddress` 对照反汇编地址，444 个为两份正文均有的函数头，69 个落在已列出的指令地址上。按反汇编地址行去重得到 23,531 个地址，`Capstone 5.0.7` 从原件对应 RVA 解码首条指令均有结果。这个检查确认地址可对应原件，未逐条比对操作数或者验证全部控制流。伪 C 有两处 `JUMPOUT` 指向原反汇编列为 `0xCC` 的地址，这两处未用于本轮判退。
- PE 的 `.rsrc` 有 7 个资源叶节点，语言均为 `1033`。交付目录只有两种正文及其报告，未见注册脚本、类型库或对应可编辑定义。伪 C 中的 `FindResourceW`、`LoadResource`、`LoadTypeLib` 保留了运行时依赖。下表列出原件中需要定位的内容。

| 资源类型 | ID | RVA | 字节数 |
| --- | ---: | ---: | ---: |
| REGISTRY | 101 | `0x2d578` | 137 |
| REGISTRY | 102 | `0x2d608` | 731 |
| REGISTRY | 103 | `0x2d8e8` | 766 |
| TYPELIB | 1 | `0x2dbe8` | 9,780 |
| RT_STRING | 7 | `0x30220` | 64 |
| RT_VERSION | 1 | `0x2d200` | 888 |
| RT_MANIFEST | 2 | `0x30260` | 381 |

## 影响验收的缺口

- 在 Ghidra 12.2 以 PE 方式导入同一原件，聚焦反编译 VA `0x180006e00`、`0x180006fa0` 和 `0x180007020`。`DllGetClassObject` 查找 CLSID，读取从 VA `0x180027050` 与 `0x180027058` 引用的对象表边界，并从表项读取类工厂回调及缓存。交付的伪 C 仍以 `qword`、`off` 和 `_UNKNOWN` 等引用表示内部数据，未交付构造这张表的等效定义。表项的布局、CLSID 与工厂回调映射直接决定能否返回原件对应的 COM 类。
- `DllRegisterServer`（RVA `0x6fa0`）和 `DllUnregisterServer`（RVA `0x7020`）的 COM 依赖仍需用原件的注册资源和类型库补齐。修复时从原件核对 REGISTRY 101–103、TYPELIB 1 与清单资源，形成可编辑定义，逐项核对类、接口、GUID、资源 ID、对象表布局及引用目标。发布粒度遵循项目资产规则。修复后转回一组复验。
