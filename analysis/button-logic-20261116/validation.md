# 核验与交付边界

日期：2026-11-16。核验对象是本轮**分析证据**，不是移植版功能、原版运行成功或热力学计算正确性。

| 检查 | 结果 | 证据 / 范围 |
| --- | --- | --- |
| 安装文件身份 | 11 个安装源 SHA-256 与提取时一致 | [evidence-index.json](evidence-index.json)；不是全安装目录完整性检查 |
| 与前轮哈希连续 | 共享安装源与 other-button-logic 轮索引一致 | checks.json「hash continuity」 |
| 托管方法定位 | 316 个索引方法三元组（name/token/rva）全部复算一致 | verify_evidence.py；含重载，按三元组而非名字匹配 |
| 原生入口 | 3 个索引函数（gxUserDefWizard/gxReorderComp/sub_21d0）RVA 一致 | 导出表与 pdata 范围；未声明所有间接调用已解析 |
| 证据断言 | **18/18 通过** | [checks.json](checks.json)：共享 RVA、CanInvoke 体、默认 Status=2、SMreorderM 重放、Cancel 零写入、COM 名称、导出 RVA |
| 数据资产 | 本轮前后均 3,226 个文件 | `.local/property-database/` 计数与基线一致；本轮所有输出均为新目录，未写入受保护路径；未做逐文件内容哈希复核的声明 |
| 原版动态观察 | **本轮未进行** | 无点击、无界面读取；前轮输入接口 `GetCursorPos 0x80070005` 受阻记录见 `.local/other-button-logic/runtime/` |
| 移植版编译/测试 | 未运行 | 本轮无源码实现 |
| Git | 新分支 `codex/button-logic-exploration`，仅提交本目录发布件 | 大体积反编译/IL 产物留 `.local/`（被 .gitignore 忽略） |

## 工具陷阱与已修正范围

1. `CxsSolver/CxsCase` 不在 `AspenTech.AspenCxs.CxsViewModel.dll`（V）中定义，V 仅有 TypeRef；首次对 V 的提取得 0 方法，不能作为“函数不存在”的证据。改提 `AspenTech.AspenCxs.dll`（X）后成功。
2. dnfile 对 V 发出 `invalid compressed int` 元数据告警（与前轮一致）；本轮未依赖 V 的新提取，状态机制结论全部来自 X。
3. `mmg.dll` 无 `gxUserDefWizard` 导出；字符串归属扫描确认分派注册在 `fimmtop.dll`、COM 桥在 `FindComponent.dll`，避免把“mmg 无导出”误读为入口不存在。
4. 主功能区 Run/Stop/Undo 等不在静态 BAML：静态目录差集只覆盖布局按钮，shell 代码命令另轨统计；两者不可相加当作“全部按钮”。
5. ProblemModes 常量表未直接解码；0/1/4 的映射由 IL 分支与反编译用法交叉确认，2/3 仅按枚举顺序推断，报告中已标明。
6. 空的失败提取目录（managed-solver-gates、managed-reorder-dialog 首跑）保留作过程记录，不在索引有效证据范围；未清理受保护路径。

## 复核入口

```powershell
& .local-tools/research/venv/Scripts/python.exe -X utf8 analysis/button-logic-20261116/verify_evidence.py
& .local-tools/research/venv/Scripts/python.exe -X utf8 analysis/button-logic-20261116/reproduce.py --out .local/button-logic-repro-<name>
```

verify 读取已保存证据与安装文件复算哈希/定位；reproduce 在新目录重跑索引范围内提取并自动 verify。两者都不执行 Aspen 程序代码。

本轮没有把分析报告当成任何开发阶段或按钮业务功能已完成的证明。