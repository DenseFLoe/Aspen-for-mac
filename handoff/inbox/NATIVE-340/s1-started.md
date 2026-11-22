# NATIVE-340 开工回执

- task_id: NATIVE-340
- owner: tietoumiao
- assigned_seq: 1
- started_utc: 2026-11-22T08:35Z
- original: issue-materials/340/WrapSaveMergeNNFiles.dll
- original_sha256: 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec
- original_size: 107048 字节（以任务卡固定 SHA-256 复核通过）
- 类型: 混合程序集（原生 + CLR）
- 范围: 按 standards/native-coverage-evidence.v1.md 交付 run.json / native-functions.csv / coverage.csv / calls.csv 与反汇编、可编辑源码
- 计划: IDA 9.5 headless 全函数导出（auto_wait 后枚举）+ Hex-Rays 反编译；CLR 元数据由原件 CLI 表解析、IL 方法体由 IDA CLR 加载器反汇编，原生视图用清零 COM 目录的副本（RVA 不变）；异常目录/入口/导出锚点逐址映射
- 验收: 覆盖 75 个原生锚点、563 个 TypeDef、188 个 MethodDef、外部与跨界调用
- 判定命令: `python handoff/assignments/check-native-coverage.py NATIVE-340`
