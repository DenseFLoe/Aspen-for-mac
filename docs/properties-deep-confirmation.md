# Aspen Properties 未确定内容深入核验（2026-11-18）

本轮将 Properties 原未确定的 **3,441 条来源记录**全部明确处理路线，包括 **613 条首选安装来源**。其中 **2,481 个可读内容 SHA-256**逐一检查，不再按后缀抽样后外推；另有 **8 个内容不可读的 MDF/LDF**，通过当前只读 SQL 系统目录确认数据/日志身份。Plus 原分类及原清单保持只读，未开展其他产品自身文件的分类调查。

当前本地入口：`.local/properties-deep-20261118-verified/README.md`。原 `.local/properties-classification-20261118-reorganized/` 及所有历史证据完整保留。

## 当前五份清单

| 清单 | Properties 来源记录 | 首选来源 |
| --- | ---: | ---: |
| 需要逆向 | 1,866 | 1,172 |
| 不需要逆向 | 17,432 | 6,205 |
| 需要逆向中的重复项 | 1,828 | 1,139 |
| 不需要逆向中的重复项 | 10,735 | 5,439 |
| 尚未确定 | 0 | 0 |

两类主清单合计仍为 19,298 条，原来源身份、路径、组件、版本、哈希、统一 analysis_key 及重复关系不变。重复清单是对应类别的附加子集，不能再次相加。已确认的旧记录未重写分类；更新均来自原未确定清单。

## 逐内容检查结果

下表只统计本轮原未确定记录，不代表对应后缀的全部 Properties 文件。数量包括安装与已安装副本、容器内成员。

| 内容 | 来源记录 / 可读不同哈希 | 路线与证据 |
| --- | ---: | --- |
| `.svg` | 2,207 / 1,985 | 公式图像；完整 XML、所有绘图节点和内部引用核对，无脚本、外部对象或事件处理器 |
| `.emf` | 488 / 244 | 矢量图片；逐条 EMR 长度、文件长度、记录数与 EOF 校验 |
| Excel 内 `.bin` | 580 / 169 | 151 个不同 MSForms 控件状态、12 个打印配置、6 个 VBA 签名记录；结合实际包内关系及二进制结构确认，不含另列的 VBA 项目流 |
| `.aprbkp` | 97 / 49 | 全文可解码；MM、版本、机器及模型/物性输入记录，按可读备份解析；其中可读表达式仍须保留 |
| `.xls` | 26 / 14 | 3 个不同内容含 VBA，4 条来源需逆向；其余 22 条来源按工作簿资源处理。全部 OLE 流及 BIFF 记录检查，另核对 VBA、XLM 与工作表类型 |
| `.doc` | 12 / 6 | Word FIB、完整 OLE 流、公式对象及宏检查；按文档资源处理 |
| `.dat` | 5 / 3 | 数据库名清单、物性单位类型表和单位转换表，全文解码并核对具体内容 |
| `.lnk` | 4 / 4 | Shell Link 头、LinkInfo、字符串及 ExtraData 边界；未打开链接目标 |
| `.pdf` | 4 / 2 | 共 28 页，交叉引用、对象及页面文本读取；无附件或活动代码对象 |
| `.aprsdf` | 2 / 1 | 实际头部边界及 `ppexec.dll` 原版路径构造、`DMS_ASGOPN` 调用，确认按引擎数据存储处理 |
| `.hms` | 2 / 1 | 实际头部及 `ApwnIPShell.dll` 将 `propmmg.hms` 传入 `mmg.dll!SetHelpFile`，确认帮助消息资源用途 |
| `.chm` | 2 / 1 | 182 个内容成员完整解压测试通过，成员枚举未发现编译程序载荷；可读帮助脚本直接解析 |
| `.ppt` | 2 / 1 | PowerPoint OLE 流与宏检查，按演示文档资源处理 |
| `.tlb` | 2 / 1 | `LoadTypeLibEx(REGKIND_NONE)` 及全部 TypeInfo 类型读取成功；仅加载接口元数据，无注册或对象实例化 |
| `.mdf`、`.ldf` | 8 / 0 | 当前 `sys.master_files` 的数据库、物理路径、ROWS/LOG 类型和分配大小对应；仅确认身份，不伪造内容哈希 |

Excel ActiveX 的 XML 与 BIN 数字编号存在错位，实际绑定必须沿 `.rels` 的 Target 和关系 ID 追踪；同数字文件名不能作为绑定证据。本轮逐来源核验实际关联、CLSID 和 persistStreamInit。VBA 数字签名经 PKCS#7 结构解析确认为签名数据；这不代表已验证签名有效性或代码完整性。

两个专有二进制格式的读取证据保留原 DLL 来源、Properties 安装归属、SHA-256、PE 异常表确定的函数边界、字符串引用地址、普通/延迟导入和相关反汇编。`sdffil.aprsdf` 的路径构造后进入原版数据管理打开接口；`propmmg.hms` 的字符串参数进入 SetHelpFile。未执行原版 DLL，没有把文件名字符串单独当成调用证据。

## 新确认的 VBA 与归档

| 原文件 | 来源记录 | 恢复的内部模块 |
| --- | ---: | ---: |
| `Mollier.zip!/Mollier/Mollier-01.xls` | 2 | 7 |
| `NRTL-SAC/Calculation.xls` | 1 | 17 |
| `NRTL-SAC/Regression.xls` | 1 | 7 |

共 31 份源文本均保存在新入口的 `02-incomplete/`，保留原安装相对路径，以 `<原文件名>.序号.<模块类型>` 命名，每份配同名 `.md`。`internal-code-members.json` 单列模块原名、OLE 路径、父文件内容哈希、输出哈希、来源及未完成状态。内部模块不是额外安装来源，不加入 19,298 条原来源记录的分母。

源文本提取证明存在可恢复程序，尚未完成 p-code/源文本一致性、窗体资源、依赖、完整性及行为验收。另有 `ApwnIPShell.dll.01.asm` 和 `ppexec.dll.01.asm` 两份读取函数局部反汇编，同样保留原路径并配同名说明，归入 `02-incomplete/`，索引为 `reader-code-evidence.json`。本轮没有程序完成件，没有进行 Windows 或 Mac 编译。

## 验证与边界

- 独立工具从 CSV 复算 19,298 条来源身份和静态字段、旧已确认记录不变、五份清单、重复子集、同哈希分类一致性、全部逐内容证据及 31 份 VBA、2 份局部反汇编的代码/说明配对，全部通过。
- 对本轮输入和 Plus 四份冻结清单前后核对 SHA-256，结果不变。最终独立验证记录为 `validation-final.json`，此前核验快照继续保留；原包内及安装来源按内容哈希引用相同证据。
- 18 项生成式样本测试通过，覆盖损坏图片/BIFF/Shell Link 边界、活动 SVG、二进制内容变化、ActiveX 编号错位、关系 ID 和 CLSID 冲突。没有将原版二进制加入测试仓库。
- **处理路线未确定为零，只表示分类完成。** 8 个 MDF/LDF 内容及 SHA-256 仍不可读；98 条符号安装目标仍未定位，均有独立字段。HMS/SDF 完整二进制语义和数值解码仍未完成，数据可直接用于计算的正确性也未因此确立。
- 所有原版输入、完整逐文件证据、详细清单及 VBA 源文本仅本地保存。数据库/公式长期资产未删除、覆盖或迁移；仓库只提交自编核验工具、无原版内容的测试和汇总文档。

工具为 `tools/confirm_properties_pending.py`、`tools/inspect_properties_readers.py`、`tools/Get-PropertiesSqlCatalogEvidence.ps1` 和 `tools/validate_properties_confirmation.py`，均要求新输出路径，拒绝覆盖历史证据。复核时须提供原五份清单、冻结的 Plus 基线、7-Zip、olefile/oletools/pefile/capstone/cryptography 模块目录及 pypdf 模块目录；输入指纹和逐文件证据保留具体原始来源及处理结果。CSV 中 `category` 为当前路线，`input_category`、`proposed_category` 为此前初分记录，保留用于追溯。
