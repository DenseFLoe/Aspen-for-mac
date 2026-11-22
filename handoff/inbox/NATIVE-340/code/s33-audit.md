# NATIVE-340 s33 审计（本文件定稿后生成指纹）

原件 SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。

## 1. 0x21AE 三点

- 空槽判定：0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（空槽不调用）；另有 0x2190 call 0x2874 的节判据
  （0x28F3 起 14 字节 83 7A 24 00 7D 04 32 C0 EB 0A B0 01 EB 06，测试目标指针所在节是否可写，0x2197 跳过）。
- 节属性：槽 0x19B78 位于 .data（VA 0x19000，raw 结束 0x19A00，虚拟结束 0x19B80），即 raw 之后的零填充尾部，静态未初始化。
- 单次读取：0x21A4 mov rax,[rbx] 对固定槽只读一次；0x21A7 mov r9,[0x61B8] = 0x48B0；0x21AE call r9；
  0x48B0 = FF E0 (JMP RAX)。
- 主表行：calls.csv 第 288 行（callee 与 note 重写，运行期依赖保留）。

## 2. 移除的 COM vtable 读描述

- 1 处：0x21AE 主表行。旧 callee 的 COM vtable slot 0 描述与旧 note 的「再走对象 vtable 槽 0」按原件删除
  （0x21A4 之后原件没有对 RAX 的二次解引用）。

## 3. 0x06000031 IL_0008 绑定

- 原件 IL：IL_0008 calli，签名 token 0x11000043，blob 0101205120610918。
- 接收者：arg0 对象，函数指针取自对象 vtable +0x10。
- loc1 来源：0x06000032 的 finally（RVA 0x3524，48 个 EH 子句）把 loc1 传给 0x06000031；loc1 由 0x06000030 经 CLR 宿主接口取得（clsid CB2F6723-AB3A-11D2-9C40-00C04FA30A3E / riid CB2F6722-AB3A-11D2-9C40-00C04FA30A3E）。
- 绑定范围：仅 0x06000032 的 finally 路径；主表 calls.csv 第 275 行，class 仍 unresolved（被调函数是运行期指针）。

## 4. 未决附表

- 由主表实际生成：托管 13 条（code/s33-unresolved-managed.csv）、原生 15 条（code/s33-unresolved-native.csv），同内容同步到 code/s25-unresolved-*.csv，与主表逐行一致。

## 5. 指标

- external=228 / boundary=303 / unresolved=28；s29_ctor_rows_added=5；237 槽 / 122 MethodDef / 228 回编桩不变。

指纹在本文件定稿后生成（code/s29-fingerprints.json，检查器按其逐个校验）。
