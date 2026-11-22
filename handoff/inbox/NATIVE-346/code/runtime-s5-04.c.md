# runtime-s5-04.c
    
此文件为 NATIVE-346 第五轮的可编辑 AMD64 实现，含 24 段，入口从 `0x14884` 至 `0x14e13`。原件为版本 41.0.0.605 的 ppexec.dll，SHA-256 为 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。各函数注释给出原件区间，RVA 符号按原地址绑定。Zig 0.13.0、Windows x86-64 GNU 目标在原件上逐段核实重定位及完整字节。[逐段结果](../s5/reassembly.json) · [整件状态、未决项与复验步骤](../s5-submission.md)
