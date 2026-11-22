# NATIVE-337 开工回执

- task_id: NATIVE-337
- owner: tietoumiao
- assigned_seq: 1
- started_utc: 2026-11-22T08:35Z
- original: issue-materials/337/FindComponent.dll
- original_sha256: 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02
- original_size: 82984 字节（以任务卡固定 SHA-256 复核通过）
- 类型: 原生 AMD64 PE
- 范围: 按 standards/native-coverage-evidence.v1.md 交付 run.json / native-functions.csv / coverage.csv / calls.csv 与反汇编、可编辑源码
- 计划: IDA 9.5 headless 全函数导出（auto_wait 后枚举）+ Hex-Rays 反编译；异常目录/入口/导出锚点逐址映射
- 验收: 覆盖 115 个原件地址锚点、工具发现函数、外部调用和数据引用
- 判定命令: `python handoff/assignments/check-native-coverage.py NATIVE-337`
