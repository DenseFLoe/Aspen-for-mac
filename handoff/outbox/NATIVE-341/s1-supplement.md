# NATIVE-341 第一号分配补件核对

原件 mmstruct.dll，SHA-256 为 bb9a2422bffe3a6aaa6c2a533ef7b4ef25d14092560d519bc93b94e216ce4870。[固定候选](https://github.com/DenseFLoe/Aspen-for-mac/commit/2c6d50ebfff05ecb6215a412bc6c549e0c03d03c) 相对前次裁定的 b6d41c2c8d5df88be8eef96ab665a61f801ba58a 新增 10 个提交、共 13 个文件差异，均在本件收件目录。第一号分配维持原裁定。第五号分配已按 #13 指向的 #403 分支提交 372fca80ee5940ec58951f3d3b243a1ad92e7e1f 发出 ACK。本记录只核对旧轮候选补件。

新增的四份汇编、四份 C 分片分别连接后，和前版的 84,757 行汇编、96,158 行 C 逐字节相等。复核 2,015 条覆盖及其源码、清单引用，4,409 条主表和 1,034 条附件引用；每个新行号指向相同文本，其他业务字段逐行相等。表格指纹与此固定候选的 metrics.json 一致。

在相同原件及候选目录上运行 python handoff/assignments/check-native-coverage.py NATIVE-341 --original <原件> --submission <候选目录>。旧主干检查器 c0853c353b1dd8a3f4eb47695d485540faec6ea5 退出 0。#403 分支提交中的附件核对版 e0b5e9c4617c9fdff9ba8d3179b60f7abad52979 退出 1，检出 1,034 处附件转移在主表缺失。经 0x79fa0 调用 GetSorResStringEx 的 16 处、两表共同漏报的 85 项及 1,007 个调用方至导入跳板的关联尚待补齐。

[第一轮裁定](s1-decision.md)和[逐址清单](s1-addresses.csv)记录恢复条件。下表是固定候选 2c6d50ebfff05ecb6215a412bc6c549e0c03d03c 的全部变更文件指纹。

| 变更文件 | SHA-256 |
| --- | --- |
| calls.csv | e99f44bc3ba20639192e5233a1da29f61335bff2b6cb15b3c410b51649119814 |
| code/indirect.csv | 7952e4050cb134a5d7ac7b392408da1984a4a35b335e70873f79ed59b9dd4f5e |
| code/native-1.asm | c97613fc235caea40ebdbdac2402aa7dcc93f0250cf7caede10a24035b4385c4 |
| code/native-1.c | ef0e16471c80ccbc5c2176502420ea54b0024fa8a34861c7d4d90e8fa11f8be5 |
| code/native-2.asm | e8f5d83cf579c7903a2b345eb2caea10a42857a79013c8fcc57eab6ee346a7fc |
| code/native-2.c | 7932286069de8ceed1f452257082428b5aba41d5e443bb8125fc3d09ed15b6ce |
| code/native-3.asm | d6c82d9cf84ce95cce1d80dc51d040314a7957fc34c7b2b0c08b2ce490772b7e |
| code/native-3.c | bc8630ff33bd3a18345a0b5fb88ebebbd1ec73a8ed5d7a28036c6d50dc481588 |
| code/native-4.asm | b4e2cdce631c203ac03d5a77ed0efe483377151872bd11e13ce955838b9f14eb |
| code/native-4.c | c9f229df3e39374b544d9d74addda471ce7452eaf729f0863001bf7e47c65ea8 |
| coverage.csv | a093716286affb3932490f2fece75c4e155d978c19c7b8054583716407390719 |
| metrics.json | 383b74b6b08ecae8e235cf9d3afd341a5c60ce15aa1420e3fd2af60492f2cee5 |
| s9-submission.md | 88e573c514132edc1c00a5e9f2a318c51073ff355e404e4e2d5aea6eb2fd995d |
