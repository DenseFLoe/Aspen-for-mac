# MSVBVM50.DLL

## 0. 摘要
- status=failed_analyze
- reason=ida_timeout 900s
- tool=IDA 9.5 + Hex-Rays
- prevtool=Ghidra 12.1.4
- sha256=4aef0066e8e4bad65018ec85d46b902303155ec2d8f049f3803e571005a90ff0
- size=1347344
- 原始终端行：
```
ITEM MSVBVM50.DLL status=failed_analyze reason=Timeout: idat.exe exceeded 900s
```
- 该件为 VB6 运行时（msvbvm/VB6 VM），IDA 9.5 在 900 s 内未完成自动分析，建议单独离线分析。
- 偏离仓库 AGENTS：本件仅记录失败与原始原因，未伪造反汇编/伪 C 正文。

## 1. 缺口与待验证
- 全函数反汇编与伪 C 未产出〔待验证：需单件离线分析或更大超时〕
- decompile 语义未复核〔无法判定〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/FM20.DLL.c.txt` sha256=a9e9cc0afa05365a2b396e881fe8ca33d7f4c88186f4b7d9d2680b8a461f2f6a bytes=4075147
- `decompiled/ROBOEX32.DLL.c.txt` sha256=e45edffd1f44d05f4a05c56a7898ffb2e81155b79f336a446703293fda7f5f6a bytes=2199402
- `decompiled/XPOPT32.DLL.c.txt` sha256=244693b06f1f4fd5cb8135eb3fe9e2584138f417c055a596fb65fe0075c2d4a7 bytes=4866097
- `decompiled/mfc42.dll.c.txt` sha256=034585327aab43b4a03fcfe54c0e6e38614055bc6a78a41808b03a5a9a4c5b75 bytes=4281392
- `decompiled/mscomctl.OCX.c.txt` sha256=a4137e95ce0addafb1a0bc1a4d00ca469d9a6b9f8d296f670ee20872393ccad4 bytes=3735062
- `decompiled/msvbvm60.dll.c.txt` sha256=1c0dbd7525fb13a4dc9e63560926feaea3757df334866f2b5af4902b2170327b bytes=5560983
- `decompiled/og702as.dll.c.txt` sha256=6cdf295c819ed853d670d235ce689d46e6da110d7d4167366a7d04e52d1f57fd bytes=5235967
- `decompiled/og70nod.dll.c.txt` sha256=0ac2a8d4478a20db197d6c8796ec7c56b51478175c1759d2583b37af6f6b0d52 bytes=6173584
- `decompiled/og70nodbas.dll.c.txt` sha256=21843d1165632de9e242c55696e27cbd6e0b24059562d03489c9ca242d8fed2f bytes=5768352
- `decompiled/olch2x32.ocx.c.txt` sha256=eddea89f78942f60a71ef074dd22f953ee24aacd233bf4d248e786aca2568792 bytes=4561825
- `decompiled/olch2x7.ocx.c.txt` sha256=e2cdb7c62518e3b3489ab9aeffe04b8ddf1a8bc76218b7589901a6af35ef4879 bytes=5310460
- `decompiled/olch3x32.ocx.c.txt` sha256=0e993e84ae972f597a057a5e6aeb4e2b05b76b6a25b32d04c632b424a096604f bytes=3813429
- `decompiled/olch3x7.ocx.c.txt` sha256=f033112b3606983dd58022be5012e325823067357e4f377620f814b0697fb639 bytes=4485983
- `decompiled/otp60as.dll.c.txt` sha256=411a7eb702ca32b6e5fa38f523dbeb53633dc19a4b9f1787d36b90edfa35b4ee bytes=5741804
- `disasm/FM20.DLL.asm.txt` sha256=6911afd55fce626f5d25c7cc17671fb8281f3577d29451d4e3d179a7f3c28fdb bytes=7912345
- `disasm/ROBOEX32.DLL.asm.txt` sha256=8763564e8c399c9075e54bcf4e2353a2431d6d56fc783179083aca82727ebd30 bytes=4435372
- `disasm/XPOPT32.DLL.asm.txt` sha256=003b09ae7927c18c9f60f3d5530afed3feddceed026bea85509a095de2b902f9 bytes=10441808
- `disasm/mfc42.dll.asm.txt` sha256=7a273a5cdaa9d4104c89c1dc02334930386f440d4e366a207d79bffdeaa7f225 bytes=7496254
- `disasm/mscomctl.OCX.asm.txt` sha256=5e09800b373c761a60bc8186da84df02e50c063a55cdad354a01d392f5fab933 bytes=7635161
- `disasm/msvbvm60.dll.asm.txt` sha256=c4f91180fa4763f5eee8ad7926b6be365a6674688e28cb591ef1771c33e88bb5 bytes=9662881
- `disasm/og702as.dll.asm.txt` sha256=0b25ada00c654010ba3bc0e68b0ecd73e0d6217c351bdd47ef97e738310db570 bytes=10293138
- `disasm/og70nod.dll.asm.txt` sha256=729483469532a28aa529ec4e30af46c02658a5163c482c49f6bdcd062d709e9d bytes=13078377
- `disasm/og70nodbas.dll.asm.txt` sha256=85a48c6572880307726fe1ca95d487940666d2d4efe5dae5223f4aa2f96b9f6e bytes=12181754
- `disasm/olch2x32.ocx.asm.txt` sha256=5054fec4835e9ca941425b0c73556cc35bcbbacb275c6bc042bbb479565e0915 bytes=11027194
- `disasm/olch2x7.ocx.asm.txt` sha256=7d7704b73a383b32e99f0385e146d68906d361db27c6e21396af8e5d2b9be913 bytes=12632208
- `disasm/olch3x32.ocx.asm.txt` sha256=68a9c57a5f355ff9c57820a0e5b11ce07d21d2b15da3d9238f35b6ae493e397a bytes=9067582
- `disasm/olch3x7.ocx.asm.txt` sha256=a99d2f218c52b89e580715347d1bf650700bcc23ce148e03f622952a5972c57f bytes=10431777
- `disasm/otp60as.dll.asm.txt` sha256=16936f87fa4f439d7b7a3da22b7b1c0a958dea774d342c96480b0a0e157a3c32 bytes=11657471
