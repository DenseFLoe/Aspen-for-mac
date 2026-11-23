# replay.py

使用 Zig 的 LLVM 汇编器产生 COFF，逐项核对原件字节、重定位、参数和展开。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x186a9,0x186f3)`，片段 SHA-256 `aa7c30e248012be77ecefdc2b6d6a0935f7bd5b1e442a705eec07623bde18aab`。

255 个入口中 160 个有覆盖、95 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。 [交付回执](../s73-submission.md)
