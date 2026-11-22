; Windows AMD64 original instruction bytes. Addresses are image RVAs.
000166c2  49 83 e8 02  sub r8,2
000166c6  48 83 c2 02  add rdx,2
000166ca  48 f7 c1 04 00 00 00  test rcx,4
000166d1  0f 84 c2 fe ff ff  je 0000000000016599h
000166d7  44 8b 12  mov r10d,[rdx]
000166da  44 89 11  mov [rcx],r10d
000166dd  49 83 e8 04  sub r8,4
000166e1  48 83 c2 04  add rdx,4
000166e5  48 83 c1 04  add rcx,4
000166e9  e9 ab fe ff ff  jmp 0000000000016599h
000166f0  4c 8b 8a 50 ff ff ff  mov r9,[rdx-0B0h]
000166f7  4c 89 89 50 ff ff ff  mov [rcx-0B0h],r9
000166fe  4c 8b 9a 58 ff ff ff  mov r11,[rdx-0A8h]
00016705  4c 89 99 58 ff ff ff  mov [rcx-0A8h],r11
0001670c  4c 8b 8a 60 ff ff ff  mov r9,[rdx-0A0h]
00016713  4c 89 89 60 ff ff ff  mov [rcx-0A0h],r9
0001671a  4c 8b 92 68 ff ff ff  mov r10,[rdx-98h]
00016721  4c 89 91 68 ff ff ff  mov [rcx-98h],r10
00016728  4c 8b 8a 70 ff ff ff  mov r9,[rdx-90h]
0001672f  4c 89 89 70 ff ff ff  mov [rcx-90h],r9
00016736  4c 8b 92 78 ff ff ff  mov r10,[rdx-88h]
0001673d  4c 89 91 78 ff ff ff  mov [rcx-88h],r10
00016744  4c 8b 4a 80  mov r9,[rdx-80h]
00016748  4c 89 49 80  mov [rcx-80h],r9
0001674c  4c 8b 52 88  mov r10,[rdx-78h]
00016750  4c 89 51 88  mov [rcx-78h],r10
00016754  4c 8b 4a 90  mov r9,[rdx-70h]
00016758  4c 89 49 90  mov [rcx-70h],r9
0001675c  4c 8b 52 98  mov r10,[rdx-68h]
00016760  4c 89 51 98  mov [rcx-68h],r10
00016764  4c 8b 4a a0  mov r9,[rdx-60h]
00016768  4c 89 49 a0  mov [rcx-60h],r9
0001676c  4c 8b 52 a8  mov r10,[rdx-58h]
00016770  4c 89 51 a8  mov [rcx-58h],r10
00016774  4c 8b 4a b0  mov r9,[rdx-50h]
00016778  4c 89 49 b0  mov [rcx-50h],r9
0001677c  4c 8b 52 b8  mov r10,[rdx-48h]
00016780  4c 89 51 b8  mov [rcx-48h],r10
00016784  4c 8b 4a c0  mov r9,[rdx-40h]
00016788  4c 89 49 c0  mov [rcx-40h],r9
0001678c  4c 8b 52 c8  mov r10,[rdx-38h]
00016790  4c 89 51 c8  mov [rcx-38h],r10
00016794  4c 8b 4a d0  mov r9,[rdx-30h]
00016798  4c 89 49 d0  mov [rcx-30h],r9
0001679c  4c 8b 52 d8  mov r10,[rdx-28h]
000167a0  4c 89 51 d8  mov [rcx-28h],r10
000167a4  4c 8b 4a e0  mov r9,[rdx-20h]
000167a8  4c 89 49 e0  mov [rcx-20h],r9
000167ac  4c 8b 52 e8  mov r10,[rdx-18h]
000167b0  4c 89 51 e8  mov [rcx-18h],r10
000167b4  4c 8b 4a f0  mov r9,[rdx-10h]
000167b8  4c 89 49 f0  mov [rcx-10h],r9
000167bc  4c 8b 52 f8  mov r10,[rdx-8]
000167c0  4c 89 51 f8  mov [rcx-8],r10
000167c4  c3  ret
000167c5  4c 8b 8a 4f ff ff ff  mov r9,[rdx-0B1h]
000167cc  4c 89 89 4f ff ff ff  mov [rcx-0B1h],r9
000167d3  4c 8b 8a 57 ff ff ff  mov r9,[rdx-0A9h]
000167da  4c 89 89 57 ff ff ff  mov [rcx-0A9h],r9
000167e1  4c 8b 8a 5f ff ff ff  mov r9,[rdx-0A1h]
000167e8  4c 89 89 5f ff ff ff  mov [rcx-0A1h],r9
000167ef  4c 8b 8a 67 ff ff ff  mov r9,[rdx-99h]
000167f6  4c 89 89 67 ff ff ff  mov [rcx-99h],r9
000167fd  4c 8b 8a 6f ff ff ff  mov r9,[rdx-91h]
00016804  4c 89 89 6f ff ff ff  mov [rcx-91h],r9
0001680b  4c 8b 8a 77 ff ff ff  mov r9,[rdx-89h]
00016812  4c 89 89 77 ff ff ff  mov [rcx-89h],r9
00016819  4c 8b 8a 7f ff ff ff  mov r9,[rdx-81h]
00016820  4c 89 89 7f ff ff ff  mov [rcx-81h],r9
00016827  4c 8b 4a 87  mov r9,[rdx-79h]
0001682b  4c 89 49 87  mov [rcx-79h],r9
0001682f  4c 8b 4a 8f  mov r9,[rdx-71h]
00016833  4c 89 49 8f  mov [rcx-71h],r9
00016837  4c 8b 4a 97  mov r9,[rdx-69h]
0001683b  4c 89 49 97  mov [rcx-69h],r9
0001683f  4c 8b 4a 9f  mov r9,[rdx-61h]
00016843  4c 89 49 9f  mov [rcx-61h],r9
00016847  4c 8b 5a a7  mov r11,[rdx-59h]
0001684b  4c 89 59 a7  mov [rcx-59h],r11
0001684f  4c 8b 52 af  mov r10,[rdx-51h]
00016853  4c 89 51 af  mov [rcx-51h],r10
00016857  4c 8b 4a b7  mov r9,[rdx-49h]
0001685b  4c 89 49 b7  mov [rcx-49h],r9
0001685f  4c 8b 5a bf  mov r11,[rdx-41h]
00016863  4c 89 59 bf  mov [rcx-41h],r11
00016867  4c 8b 52 c7  mov r10,[rdx-39h]
0001686b  4c 89 51 c7  mov [rcx-39h],r10
0001686f  4c 8b 4a cf  mov r9,[rdx-31h]
00016873  4c 89 49 cf  mov [rcx-31h],r9
00016877  4c 8b 5a d7  mov r11,[rdx-29h]
0001687b  4c 89 59 d7  mov [rcx-29h],r11
0001687f  4c 8b 52 df  mov r10,[rdx-21h]
00016883  4c 89 51 df  mov [rcx-21h],r10
00016887  4c 8b 4a e7  mov r9,[rdx-19h]
0001688b  4c 89 49 e7  mov [rcx-19h],r9
0001688f  4c 8b 5a ef  mov r11,[rdx-11h]
00016893  4c 89 59 ef  mov [rcx-11h],r11
00016897  4c 8b 52 f7  mov r10,[rdx-9]
0001689b  4c 89 51 f7  mov [rcx-9],r10
0001689f  44 8a 4a ff  mov r9b,[rdx-1]
000168a3  44 88 49 ff  mov [rcx-1],r9b
000168a7  c3  ret
000168a8  4c 8b 8a 4e ff ff ff  mov r9,[rdx-0B2h]
000168af  4c 89 89 4e ff ff ff  mov [rcx-0B2h],r9
000168b6  4c 8b 8a 56 ff ff ff  mov r9,[rdx-0AAh]
000168bd  4c 89 89 56 ff ff ff  mov [rcx-0AAh],r9
000168c4  4c 8b 8a 5e ff ff ff  mov r9,[rdx-0A2h]
000168cb  4c 89 89 5e ff ff ff  mov [rcx-0A2h],r9
000168d2  4c 8b 8a 66 ff ff ff  mov r9,[rdx-9Ah]
000168d9  4c 89 89 66 ff ff ff  mov [rcx-9Ah],r9
000168e0  4c 8b 8a 6e ff ff ff  mov r9,[rdx-92h]
000168e7  4c 89 89 6e ff ff ff  mov [rcx-92h],r9
000168ee  4c 8b 8a 76 ff ff ff  mov r9,[rdx-8Ah]
000168f5  4c 89 89 76 ff ff ff  mov [rcx-8Ah],r9
000168fc  4c 8b 8a 7e ff ff ff  mov r9,[rdx-82h]
00016903  4c 89 89 7e ff ff ff  mov [rcx-82h],r9
0001690a  4c 8b 4a 86  mov r9,[rdx-7Ah]
0001690e  4c 89 49 86  mov [rcx-7Ah],r9
00016912  4c 8b 4a 8e  mov r9,[rdx-72h]
00016916  4c 89 49 8e  mov [rcx-72h],r9
0001691a  4c 8b 4a 96  mov r9,[rdx-6Ah]
0001691e  4c 89 49 96  mov [rcx-6Ah],r9
00016922  4c 8b 4a 9e  mov r9,[rdx-62h]
00016926  4c 89 49 9e  mov [rcx-62h],r9
0001692a  4c 8b 4a a6  mov r9,[rdx-5Ah]
0001692e  4c 89 49 a6  mov [rcx-5Ah],r9
00016932  4c 8b 4a ae  mov r9,[rdx-52h]
00016936  4c 89 49 ae  mov [rcx-52h],r9
0001693a  4c 8b 4a b6  mov r9,[rdx-4Ah]
0001693e  4c 89 49 b6  mov [rcx-4Ah],r9
00016942  4c 8b 4a be  mov r9,[rdx-42h]
00016946  4c 89 49 be  mov [rcx-42h],r9
0001694a  4c 8b 4a c6  mov r9,[rdx-3Ah]
0001694e  4c 89 49 c6  mov [rcx-3Ah],r9
00016952  4c 8b 4a ce  mov r9,[rdx-32h]
00016956  4c 89 49 ce  mov [rcx-32h],r9
0001695a  4c 8b 4a d6  mov r9,[rdx-2Ah]
0001695e  4c 89 49 d6  mov [rcx-2Ah],r9
00016962  4c 8b 4a de  mov r9,[rdx-22h]
00016966  4c 89 49 de  mov [rcx-22h],r9
0001696a  4c 8b 4a e6  mov r9,[rdx-1Ah]
0001696e  4c 89 49 e6  mov [rcx-1Ah],r9
00016972  4c 8b 4a ee  mov r9,[rdx-12h]
00016976  4c 89 49 ee  mov [rcx-12h],r9
0001697a  4c 8b 4a f6  mov r9,[rdx-0Ah]
0001697e  4c 89 49 f6  mov [rcx-0Ah],r9
00016982  66 44 8b 4a fe  mov r9w,[rdx-2]
00016987  66 44 89 49 fe  mov [rcx-2],r9w
0001698c  c3  ret
0001698d  4c 8b 8a 4d ff ff ff  mov r9,[rdx-0B3h]
00016994  4c 89 89 4d ff ff ff  mov [rcx-0B3h],r9
0001699b  4c 8b 8a 55 ff ff ff  mov r9,[rdx-0ABh]
000169a2  4c 89 89 55 ff ff ff  mov [rcx-0ABh],r9
000169a9  4c 8b 8a 5d ff ff ff  mov r9,[rdx-0A3h]
000169b0  4c 89 89 5d ff ff ff  mov [rcx-0A3h],r9
000169b7  4c 8b 8a 65 ff ff ff  mov r9,[rdx-9Bh]
000169be  4c 89 89 65 ff ff ff  mov [rcx-9Bh],r9
000169c5  4c 8b 8a 6d ff ff ff  mov r9,[rdx-93h]
000169cc  4c 89 89 6d ff ff ff  mov [rcx-93h],r9
000169d3  4c 8b 8a 75 ff ff ff  mov r9,[rdx-8Bh]
000169da  4c 89 89 75 ff ff ff  mov [rcx-8Bh],r9
000169e1  4c 8b 8a 7d ff ff ff  mov r9,[rdx-83h]
000169e8  4c 89 89 7d ff ff ff  mov [rcx-83h],r9
000169ef  4c 8b 4a 85  mov r9,[rdx-7Bh]
000169f3  4c 89 49 85  mov [rcx-7Bh],r9
000169f7  4c 8b 4a 8d  mov r9,[rdx-73h]
000169fb  4c 89 49 8d  mov [rcx-73h],r9
000169ff  4c 8b 4a 95  mov r9,[rdx-6Bh]
00016a03  4c 89 49 95  mov [rcx-6Bh],r9
00016a07  4c 8b 4a 9d  mov r9,[rdx-63h]
00016a0b  4c 89 49 9d  mov [rcx-63h],r9
00016a0f  4c 8b 4a a5  mov r9,[rdx-5Bh]
00016a13  4c 89 49 a5  mov [rcx-5Bh],r9
00016a17  4c 8b 4a ad  mov r9,[rdx-53h]
00016a1b  4c 89 49 ad  mov [rcx-53h],r9
00016a1f  4c 8b 4a b5  mov r9,[rdx-4Bh]
00016a23  4c 89 49 b5  mov [rcx-4Bh],r9
00016a27  4c 8b 4a bd  mov r9,[rdx-43h]
00016a2b  4c 89 49 bd  mov [rcx-43h],r9
00016a2f  4c 8b 4a c5  mov r9,[rdx-3Bh]
00016a33  4c 89 49 c5  mov [rcx-3Bh],r9
00016a37  4c 8b 4a cd  mov r9,[rdx-33h]
00016a3b  4c 89 49 cd  mov [rcx-33h],r9
00016a3f  4c 8b 4a d5  mov r9,[rdx-2Bh]
00016a43  4c 89 49 d5  mov [rcx-2Bh],r9
00016a47  4c 8b 4a dd  mov r9,[rdx-23h]
00016a4b  4c 89 49 dd  mov [rcx-23h],r9
00016a4f  4c 8b 4a e5  mov r9,[rdx-1Bh]
00016a53  4c 89 49 e5  mov [rcx-1Bh],r9
00016a57  4c 8b 4a ed  mov r9,[rdx-13h]
00016a5b  4c 89 49 ed  mov [rcx-13h],r9
00016a5f  4c 8b 4a f5  mov r9,[rdx-0Bh]
00016a63  4c 89 49 f5  mov [rcx-0Bh],r9
00016a67  66 44 8b 4a fd  mov r9w,[rdx-3]
00016a6c  44 8a 52 ff  mov r10b,[rdx-1]
00016a70  66 44 89 49 fd  mov [rcx-3],r9w
00016a75  44 88 51 ff  mov [rcx-1],r10b
00016a79  c3  ret
00016a7a  4c 8b 8a 4c ff ff ff  mov r9,[rdx-0B4h]
00016a81  4c 89 89 4c ff ff ff  mov [rcx-0B4h],r9
00016a88  4c 8b 8a 54 ff ff ff  mov r9,[rdx-0ACh]
00016a8f  4c 89 89 54 ff ff ff  mov [rcx-0ACh],r9
00016a96  4c 8b 8a 5c ff ff ff  mov r9,[rdx-0A4h]
00016a9d  4c 89 89 5c ff ff ff  mov [rcx-0A4h],r9
00016aa4  4c 8b 8a 64 ff ff ff  mov r9,[rdx-9Ch]
00016aab  4c 89 89 64 ff ff ff  mov [rcx-9Ch],r9
00016ab2  4c 8b 8a 6c ff ff ff  mov r9,[rdx-94h]
00016ab9  4c 89 89 6c ff ff ff  mov [rcx-94h],r9
00016ac0  4c 8b 8a 74 ff ff ff  mov r9,[rdx-8Ch]
00016ac7  4c 89 89 74 ff ff ff  mov [rcx-8Ch],r9
00016ace  4c 8b 8a 7c ff ff ff  mov r9,[rdx-84h]
00016ad5  4c 89 89 7c ff ff ff  mov [rcx-84h],r9
00016adc  4c 8b 4a 84  mov r9,[rdx-7Ch]
00016ae0  4c 89 49 84  mov [rcx-7Ch],r9
00016ae4  4c 8b 4a 8c  mov r9,[rdx-74h]
00016ae8  4c 89 49 8c  mov [rcx-74h],r9
00016aec  4c 8b 4a 94  mov r9,[rdx-6Ch]
00016af0  4c 89 49 94  mov [rcx-6Ch],r9
00016af4  4c 8b 4a 9c  mov r9,[rdx-64h]
00016af8  4c 89 49 9c  mov [rcx-64h],r9
00016afc  4c 8b 4a a4  mov r9,[rdx-5Ch]
00016b00  4c 89 49 a4  mov [rcx-5Ch],r9
00016b04  4c 8b 4a ac  mov r9,[rdx-54h]
00016b08  4c 89 49 ac  mov [rcx-54h],r9
00016b0c  4c 8b 4a b4  mov r9,[rdx-4Ch]
00016b10  4c 89 49 b4  mov [rcx-4Ch],r9
00016b14  4c 8b 4a bc  mov r9,[rdx-44h]
00016b18  4c 89 49 bc  mov [rcx-44h],r9
00016b1c  4c 8b 4a c4  mov r9,[rdx-3Ch]
00016b20  4c 89 49 c4  mov [rcx-3Ch],r9
00016b24  4c 8b 4a cc  mov r9,[rdx-34h]
00016b28  4c 89 49 cc  mov [rcx-34h],r9
00016b2c  4c 8b 4a d4  mov r9,[rdx-2Ch]
00016b30  4c 89 49 d4  mov [rcx-2Ch],r9
00016b34  4c 8b 4a dc  mov r9,[rdx-24h]
00016b38  4c 89 49 dc  mov [rcx-24h],r9
00016b3c  4c 8b 4a e4  mov r9,[rdx-1Ch]
00016b40  4c 89 49 e4  mov [rcx-1Ch],r9
00016b44  4c 8b 4a ec  mov r9,[rdx-14h]
00016b48  4c 89 49 ec  mov [rcx-14h],r9
00016b4c  4c 8b 4a f4  mov r9,[rdx-0Ch]
00016b50  4c 89 49 f4  mov [rcx-0Ch],r9
00016b54  44 8b 4a fc  mov r9d,[rdx-4]
00016b58  44 89 49 fc  mov [rcx-4],r9d
00016b5c  c3  ret
00016b5d  4c 8b 8a 4b ff ff ff  mov r9,[rdx-0B5h]
00016b64  4c 89 89 4b ff ff ff  mov [rcx-0B5h],r9
00016b6b  4c 8b 8a 53 ff ff ff  mov r9,[rdx-0ADh]
00016b72  4c 89 89 53 ff ff ff  mov [rcx-0ADh],r9
00016b79  4c 8b 8a 5b ff ff ff  mov r9,[rdx-0A5h]
00016b80  4c 89 89 5b ff ff ff  mov [rcx-0A5h],r9
00016b87  4c 8b 8a 63 ff ff ff  mov r9,[rdx-9Dh]
00016b8e  4c 89 89 63 ff ff ff  mov [rcx-9Dh],r9
00016b95  4c 8b 8a 6b ff ff ff  mov r9,[rdx-95h]
00016b9c  4c 89 89 6b ff ff ff  mov [rcx-95h],r9
00016ba3  4c 8b 8a 73 ff ff ff  mov r9,[rdx-8Dh]
00016baa  4c 89 89 73 ff ff ff  mov [rcx-8Dh],r9
00016bb1  4c 8b 8a 7b ff ff ff  mov r9,[rdx-85h]
00016bb8  4c 89 89 7b ff ff ff  mov [rcx-85h],r9
00016bbf  4c 8b 4a 83  mov r9,[rdx-7Dh]
00016bc3  4c 89 49 83  mov [rcx-7Dh],r9
00016bc7  4c 8b 4a 8b  mov r9,[rdx-75h]
00016bcb  4c 89 49 8b  mov [rcx-75h],r9
00016bcf  4c 8b 4a 93  mov r9,[rdx-6Dh]
00016bd3  4c 89 49 93  mov [rcx-6Dh],r9
00016bd7  4c 8b 4a 9b  mov r9,[rdx-65h]
00016bdb  4c 89 49 9b  mov [rcx-65h],r9
00016bdf  4c 8b 4a a3  mov r9,[rdx-5Dh]
00016be3  4c 89 49 a3  mov [rcx-5Dh],r9
00016be7  4c 8b 4a ab  mov r9,[rdx-55h]
00016beb  4c 89 49 ab  mov [rcx-55h],r9
00016bef  4c 8b 4a b3  mov r9,[rdx-4Dh]
00016bf3  4c 89 49 b3  mov [rcx-4Dh],r9
00016bf7  4c 8b 4a bb  mov r9,[rdx-45h]
00016bfb  4c 89 49 bb  mov [rcx-45h],r9
00016bff  4c 8b 4a c3  mov r9,[rdx-3Dh]
00016c03  4c 89 49 c3  mov [rcx-3Dh],r9
00016c07  4c 8b 4a cb  mov r9,[rdx-35h]
00016c0b  4c 89 49 cb  mov [rcx-35h],r9
00016c0f  4c 8b 4a d3  mov r9,[rdx-2Dh]
00016c13  4c 89 49 d3  mov [rcx-2Dh],r9
00016c17  4c 8b 4a db  mov r9,[rdx-25h]
00016c1b  4c 89 49 db  mov [rcx-25h],r9
00016c1f  4c 8b 4a e3  mov r9,[rdx-1Dh]
00016c23  4c 89 49 e3  mov [rcx-1Dh],r9
00016c27  4c 8b 4a eb  mov r9,[rdx-15h]
00016c2b  4c 89 49 eb  mov [rcx-15h],r9
00016c2f  4c 8b 4a f3  mov r9,[rdx-0Dh]
00016c33  4c 89 49 f3  mov [rcx-0Dh],r9
00016c37  44 8b 4a fb  mov r9d,[rdx-5]
00016c3b  44 8a 52 ff  mov r10b,[rdx-1]
00016c3f  44 89 49 fb  mov [rcx-5],r9d
00016c43  44 88 51 ff  mov [rcx-1],r10b
00016c47  c3  ret
00016c48  4c 8b 8a 4a ff ff ff  mov r9,[rdx-0B6h]
00016c4f  4c 89 89 4a ff ff ff  mov [rcx-0B6h],r9
00016c56  4c 8b 8a 52 ff ff ff  mov r9,[rdx-0AEh]
00016c5d  4c 89 89 52 ff ff ff  mov [rcx-0AEh],r9
00016c64  4c 8b 8a 5a ff ff ff  mov r9,[rdx-0A6h]
00016c6b  4c 89 89 5a ff ff ff  mov [rcx-0A6h],r9
00016c72  4c 8b 8a 62 ff ff ff  mov r9,[rdx-9Eh]
00016c79  4c 89 89 62 ff ff ff  mov [rcx-9Eh],r9
00016c80  4c 8b 8a 6a ff ff ff  mov r9,[rdx-96h]
00016c87  4c 89 89 6a ff ff ff  mov [rcx-96h],r9
00016c8e  4c 8b 8a 72 ff ff ff  mov r9,[rdx-8Eh]
00016c95  4c 89 89 72 ff ff ff  mov [rcx-8Eh],r9
00016c9c  4c 8b 8a 7a ff ff ff  mov r9,[rdx-86h]
00016ca3  4c 89 89 7a ff ff ff  mov [rcx-86h],r9
00016caa  4c 8b 4a 82  mov r9,[rdx-7Eh]
00016cae  4c 89 49 82  mov [rcx-7Eh],r9
00016cb2  4c 8b 4a 8a  mov r9,[rdx-76h]
00016cb6  4c 89 49 8a  mov [rcx-76h],r9
00016cba  4c 8b 4a 92  mov r9,[rdx-6Eh]
00016cbe  4c 89 49 92  mov [rcx-6Eh],r9
00016cc2  4c 8b 4a 9a  mov r9,[rdx-66h]
00016cc6  4c 89 49 9a  mov [rcx-66h],r9
00016cca  4c 8b 4a a2  mov r9,[rdx-5Eh]
00016cce  4c 89 49 a2  mov [rcx-5Eh],r9
00016cd2  4c 8b 4a aa  mov r9,[rdx-56h]
00016cd6  4c 89 49 aa  mov [rcx-56h],r9
00016cda  4c 8b 4a b2  mov r9,[rdx-4Eh]
00016cde  4c 89 49 b2  mov [rcx-4Eh],r9
00016ce2  4c 8b 4a ba  mov r9,[rdx-46h]
00016ce6  4c 89 49 ba  mov [rcx-46h],r9
00016cea  4c 8b 4a c2  mov r9,[rdx-3Eh]
00016cee  4c 89 49 c2  mov [rcx-3Eh],r9
00016cf2  4c 8b 4a ca  mov r9,[rdx-36h]
00016cf6  4c 89 49 ca  mov [rcx-36h],r9
00016cfa  4c 8b 4a d2  mov r9,[rdx-2Eh]
00016cfe  4c 89 49 d2  mov [rcx-2Eh],r9
00016d02  4c 8b 4a da  mov r9,[rdx-26h]
00016d06  4c 89 49 da  mov [rcx-26h],r9
00016d0a  4c 8b 4a e2  mov r9,[rdx-1Eh]
00016d0e  4c 89 49 e2  mov [rcx-1Eh],r9
00016d12  4c 8b 4a ea  mov r9,[rdx-16h]
00016d16  4c 89 49 ea  mov [rcx-16h],r9
00016d1a  4c 8b 4a f2  mov r9,[rdx-0Eh]
00016d1e  4c 89 49 f2  mov [rcx-0Eh],r9
00016d22  44 8b 4a fa  mov r9d,[rdx-6]
00016d26  66 44 8b 52 fe  mov r10w,[rdx-2]
00016d2b  44 89 49 fa  mov [rcx-6],r9d
00016d2f  66 44 89 51 fe  mov [rcx-2],r10w
00016d34  c3  ret
00016d35  4c 8b 8a 49 ff ff ff  mov r9,[rdx-0B7h]
00016d3c  4c 89 89 49 ff ff ff  mov [rcx-0B7h],r9
00016d43  4c 8b 8a 51 ff ff ff  mov r9,[rdx-0AFh]
00016d4a  4c 89 89 51 ff ff ff  mov [rcx-0AFh],r9
00016d51  4c 8b 8a 59 ff ff ff  mov r9,[rdx-0A7h]
00016d58  4c 89 89 59 ff ff ff  mov [rcx-0A7h],r9
00016d5f  4c 8b 8a 61 ff ff ff  mov r9,[rdx-9Fh]
00016d66  4c 89 89 61 ff ff ff  mov [rcx-9Fh],r9
00016d6d  4c 8b 8a 69 ff ff ff  mov r9,[rdx-97h]
00016d74  4c 89 89 69 ff ff ff  mov [rcx-97h],r9
00016d7b  4c 8b 8a 71 ff ff ff  mov r9,[rdx-8Fh]
00016d82  4c 89 89 71 ff ff ff  mov [rcx-8Fh],r9
00016d89  4c 8b 8a 79 ff ff ff  mov r9,[rdx-87h]
00016d90  4c 89 89 79 ff ff ff  mov [rcx-87h],r9
00016d97  4c 8b 4a 81  mov r9,[rdx-7Fh]
00016d9b  4c 89 49 81  mov [rcx-7Fh],r9
00016d9f  4c 8b 4a 89  mov r9,[rdx-77h]
00016da3  4c 89 49 89  mov [rcx-77h],r9
00016da7  4c 8b 4a 91  mov r9,[rdx-6Fh]
00016dab  4c 89 49 91  mov [rcx-6Fh],r9
00016daf  4c 8b 4a 99  mov r9,[rdx-67h]
00016db3  4c 89 49 99  mov [rcx-67h],r9
00016db7  4c 8b 4a a1  mov r9,[rdx-5Fh]
00016dbb  4c 89 49 a1  mov [rcx-5Fh],r9
00016dbf  4c 8b 4a a9  mov r9,[rdx-57h]
00016dc3  4c 89 49 a9  mov [rcx-57h],r9
00016dc7  4c 8b 4a b1  mov r9,[rdx-4Fh]
00016dcb  4c 89 49 b1  mov [rcx-4Fh],r9
00016dcf  4c 8b 4a b9  mov r9,[rdx-47h]
00016dd3  4c 89 49 b9  mov [rcx-47h],r9
00016dd7  4c 8b 4a c1  mov r9,[rdx-3Fh]
00016ddb  4c 89 49 c1  mov [rcx-3Fh],r9
00016ddf  4c 8b 4a c9  mov r9,[rdx-37h]
00016de3  4c 89 49 c9  mov [rcx-37h],r9
00016de7  4c 8b 4a d1  mov r9,[rdx-2Fh]
00016deb  4c 89 49 d1  mov [rcx-2Fh],r9
00016def  4c 8b 4a d9  mov r9,[rdx-27h]
00016df3  4c 89 49 d9  mov [rcx-27h],r9
00016df7  4c 8b 4a e1  mov r9,[rdx-1Fh]
00016dfb  4c 89 49 e1  mov [rcx-1Fh],r9
00016dff  4c 8b 4a e9  mov r9,[rdx-17h]
00016e03  4c 89 49 e9  mov [rcx-17h],r9
00016e07  4c 8b 4a f1  mov r9,[rdx-0Fh]
00016e0b  4c 89 49 f1  mov [rcx-0Fh],r9
00016e0f  44 8b 4a f9  mov r9d,[rdx-7]
00016e13  66 44 8b 52 fd  mov r10w,[rdx-3]
00016e18  44 8a 5a ff  mov r11b,[rdx-1]
00016e1c  44 89 49 f9  mov [rcx-7],r9d
00016e20  66 44 89 51 fd  mov [rcx-3],r10w
00016e25  44 88 59 ff  mov [rcx-1],r11b
00016e29  c3  ret
00016e30  83 3d f9 c7 00 00 02  cmp dword ptr [23630h],2
00016e37  0f 85 33 06 00 00  jne 0000000000017470h
00016e3d  48 f7 c1 0f 00 00 00  test rcx,0Fh
00016e44  0f 85 6e 07 00 00  jne 00000000000175B8h
00016e4a  4d 33 c9  xor r9,r9
00016e4d  4c 3b 05 e4 b3 00 00  cmp r8,[22238h]
00016e54  0f 8f 26 05 00 00  jg 0000000000017380h
00016e5a  48 f7 c2 0f 00 00 00  test rdx,0Fh
00016e61  0f 84 89 05 00 00  je 00000000000173F0h
00016e67  4c 8d 15 92 f7 00 00  lea r10,[26600h]
00016e6e  4c 8b da  mov r11,rdx
00016e71  49 83 e3 0f  and r11,0Fh
00016e75  f3 0f 6f 02  movdqu xmm0,[rdx]
00016e79  66 0f 7f 01  movdqa [rcx],xmm0
00016e7d  48 83 c2 10  add rdx,10h
00016e81  49 2b d3  sub rdx,r11
00016e84  48 83 c1 10  add rcx,10h
00016e88  49 83 e8 10  sub r8,10h
00016e8c  66 0f 6f 0a  movdqa xmm1,[rdx]
00016e90  43 ff 24 da  jmp qword ptr [r10+r11*8]
00016e94  4c 8d 15 e5 f7 00 00  lea r10,[26680h]
00016e9b  4d 8b c8  mov r9,r8
00016e9e  49 c1 e9 04  shr r9,4
00016ea2  49 c1 e1 04  shl r9,4
00016ea6  49 03 c9  add rcx,r9
00016ea9  49 03 d1  add rdx,r9
00016eac  4d 2b c1  sub r8,r9
00016eaf  49 c1 e9 04  shr r9,4
00016eb3  43 ff 24 ca  jmp qword ptr [r10+r9*8]
00016ec0  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00016ec5  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
00016eca  48 8d 52 20  lea rdx,[rdx+20h]
00016ece  4d 8d 40 e0  lea r8,[r8-20h]
00016ed2  66 0f 73 d9 01  psrldq xmm1,1
00016ed7  66 0f 6f d3  movdqa xmm2,xmm3
00016edb  66 0f 73 fb 0f  pslldq xmm3,0Fh
00016ee0  66 0f eb d9  por xmm3,xmm1
00016ee4  49 83 f8 20  cmp r8,20h
00016ee8  66 0f 73 da 01  psrldq xmm2,1
00016eed  66 0f 6f c8  movdqa xmm1,xmm0
00016ef1  66 0f 73 f8 0f  pslldq xmm0,0Fh
00016ef6  66 0f eb c2  por xmm0,xmm2
00016efa  66 0f 7f 19  movdqa [rcx],xmm3
00016efe  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
00016f03  48 8d 49 20  lea rcx,[rcx+20h]
00016f07  7d b7  jge short 0000000000016EC0h
00016f09  e9 5b 04 00 00  jmp 0000000000017369h
00016f10  49 83 e8 20  sub r8,20h
00016f14  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00016f19  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
00016f1e  48 83 c2 20  add rdx,20h
00016f22  66 0f 73 d9 02  psrldq xmm1,2
00016f27  66 0f 6f d3  movdqa xmm2,xmm3
00016f2b  66 0f 73 fb 0e  pslldq xmm3,0Eh
00016f30  66 0f eb d9  por xmm3,xmm1
00016f34  66 0f 73 da 02  psrldq xmm2,2
00016f39  66 0f 6f c8  movdqa xmm1,xmm0
00016f3d  66 0f 73 f8 0e  pslldq xmm0,0Eh
00016f42  66 0f eb c2  por xmm0,xmm2
00016f46  66 0f 7f 19  movdqa [rcx],xmm3
00016f4a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
00016f4f  48 83 c1 20  add rcx,20h
00016f53  49 83 f8 20  cmp r8,20h
00016f57  7d b7  jge short 0000000000016F10h
00016f59  e9 0b 04 00 00  jmp 0000000000017369h
00016f60  49 83 e8 20  sub r8,20h
00016f64  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00016f69  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
00016f6e  48 83 c2 20  add rdx,20h
00016f72  66 0f 73 d9 03  psrldq xmm1,3
00016f77  66 0f 6f d3  movdqa xmm2,xmm3
00016f7b  66 0f 73 fb 0d  pslldq xmm3,0Dh
00016f80  66 0f eb d9  por xmm3,xmm1
00016f84  66 0f 73 da 03  psrldq xmm2,3
00016f89  66 0f 6f c8  movdqa xmm1,xmm0
00016f8d  66 0f 73 f8 0d  pslldq xmm0,0Dh
00016f92  66 0f eb c2  por xmm0,xmm2
00016f96  66 0f 7f 19  movdqa [rcx],xmm3
00016f9a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
00016f9f  48 83 c1 20  add rcx,20h
00016fa3  49 83 f8 20  cmp r8,20h
00016fa7  7d b7  jge short 0000000000016F60h
00016fa9  e9 bb 03 00 00  jmp 0000000000017369h
00016fb0  49 83 e8 20  sub r8,20h
00016fb4  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00016fb9  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
00016fbe  48 83 c2 20  add rdx,20h
00016fc2  66 0f 73 d9 04  psrldq xmm1,4
00016fc7  66 0f 6f d3  movdqa xmm2,xmm3
00016fcb  66 0f 73 fb 0c  pslldq xmm3,0Ch
00016fd0  66 0f eb d9  por xmm3,xmm1
00016fd4  66 0f 73 da 04  psrldq xmm2,4
00016fd9  66 0f 6f c8  movdqa xmm1,xmm0
00016fdd  66 0f 73 f8 0c  pslldq xmm0,0Ch
00016fe2  66 0f eb c2  por xmm0,xmm2
00016fe6  66 0f 7f 19  movdqa [rcx],xmm3
00016fea  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
00016fef  48 83 c1 20  add rcx,20h
00016ff3  49 83 f8 20  cmp r8,20h
00016ff7  7d b7  jge short 0000000000016FB0h
00016ff9  e9 6b 03 00 00  jmp 0000000000017369h
00017000  49 83 e8 20  sub r8,20h
00017004  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00017009  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
0001700e  48 83 c2 20  add rdx,20h
00017012  66 0f 73 d9 05  psrldq xmm1,5
00017017  66 0f 6f d3  movdqa xmm2,xmm3
0001701b  66 0f 73 fb 0b  pslldq xmm3,0Bh
00017020  66 0f eb d9  por xmm3,xmm1
00017024  66 0f 73 da 05  psrldq xmm2,5
00017029  66 0f 6f c8  movdqa xmm1,xmm0
0001702d  66 0f 73 f8 0b  pslldq xmm0,0Bh
00017032  66 0f eb c2  por xmm0,xmm2
00017036  66 0f 7f 19  movdqa [rcx],xmm3
0001703a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001703f  48 83 c1 20  add rcx,20h
00017043  49 83 f8 20  cmp r8,20h
00017047  7d b7  jge short 0000000000017000h
00017049  e9 1b 03 00 00  jmp 0000000000017369h
00017050  49 83 e8 20  sub r8,20h
00017054  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00017059  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
0001705e  48 83 c2 20  add rdx,20h
00017062  66 0f 73 d9 06  psrldq xmm1,6
00017067  66 0f 6f d3  movdqa xmm2,xmm3
0001706b  66 0f 73 fb 0a  pslldq xmm3,0Ah
00017070  66 0f eb d9  por xmm3,xmm1
00017074  66 0f 73 da 06  psrldq xmm2,6
00017079  66 0f 6f c8  movdqa xmm1,xmm0
0001707d  66 0f 73 f8 0a  pslldq xmm0,0Ah
00017082  66 0f eb c2  por xmm0,xmm2
00017086  66 0f 7f 19  movdqa [rcx],xmm3
0001708a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001708f  48 83 c1 20  add rcx,20h
00017093  49 83 f8 20  cmp r8,20h
00017097  7d b7  jge short 0000000000017050h
00017099  e9 cb 02 00 00  jmp 0000000000017369h
000170a0  49 83 e8 20  sub r8,20h
000170a4  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
000170a9  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
000170ae  48 83 c2 20  add rdx,20h
000170b2  66 0f 73 d9 07  psrldq xmm1,7
000170b7  66 0f 6f d3  movdqa xmm2,xmm3
000170bb  66 0f 73 fb 09  pslldq xmm3,9
000170c0  66 0f eb d9  por xmm3,xmm1
000170c4  66 0f 73 da 07  psrldq xmm2,7
000170c9  66 0f 6f c8  movdqa xmm1,xmm0
000170cd  66 0f 73 f8 09  pslldq xmm0,9
000170d2  66 0f eb c2  por xmm0,xmm2
000170d6  66 0f 7f 19  movdqa [rcx],xmm3
000170da  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
000170df  48 83 c1 20  add rcx,20h
000170e3  49 83 f8 20  cmp r8,20h
000170e7  7d b7  jge short 00000000000170A0h
000170e9  e9 7b 02 00 00  jmp 0000000000017369h
000170f0  49 83 e8 20  sub r8,20h
000170f4  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
000170f9  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
000170fe  48 83 c2 20  add rdx,20h
00017102  66 0f 73 d9 08  psrldq xmm1,8
00017107  66 0f 6f d3  movdqa xmm2,xmm3
0001710b  66 0f 73 fb 08  pslldq xmm3,8
00017110  66 0f eb d9  por xmm3,xmm1
00017114  66 0f 73 da 08  psrldq xmm2,8
00017119  66 0f 6f c8  movdqa xmm1,xmm0
0001711d  66 0f 73 f8 08  pslldq xmm0,8
00017122  66 0f eb c2  por xmm0,xmm2
00017126  66 0f 7f 19  movdqa [rcx],xmm3
0001712a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001712f  48 83 c1 20  add rcx,20h
00017133  49 83 f8 20  cmp r8,20h
00017137  7d b7  jge short 00000000000170F0h
00017139  e9 2b 02 00 00  jmp 0000000000017369h
00017140  49 83 e8 20  sub r8,20h
00017144  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00017149  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
0001714e  48 83 c2 20  add rdx,20h
00017152  66 0f 73 d9 09  psrldq xmm1,9
00017157  66 0f 6f d3  movdqa xmm2,xmm3
0001715b  66 0f 73 fb 07  pslldq xmm3,7
00017160  66 0f eb d9  por xmm3,xmm1
00017164  66 0f 73 da 09  psrldq xmm2,9
00017169  66 0f 6f c8  movdqa xmm1,xmm0
0001716d  66 0f 73 f8 07  pslldq xmm0,7
00017172  66 0f eb c2  por xmm0,xmm2
00017176  66 0f 7f 19  movdqa [rcx],xmm3
0001717a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001717f  48 83 c1 20  add rcx,20h
00017183  49 83 f8 20  cmp r8,20h
00017187  7d b7  jge short 0000000000017140h
00017189  e9 db 01 00 00  jmp 0000000000017369h
00017190  49 83 e8 20  sub r8,20h
00017194  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00017199  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
0001719e  48 83 c2 20  add rdx,20h
000171a2  66 0f 73 d9 0a  psrldq xmm1,0Ah
000171a7  66 0f 6f d3  movdqa xmm2,xmm3
000171ab  66 0f 73 fb 06  pslldq xmm3,6
000171b0  66 0f eb d9  por xmm3,xmm1
000171b4  66 0f 73 da 0a  psrldq xmm2,0Ah
000171b9  66 0f 6f c8  movdqa xmm1,xmm0
000171bd  66 0f 73 f8 06  pslldq xmm0,6
000171c2  66 0f eb c2  por xmm0,xmm2
000171c6  66 0f 7f 19  movdqa [rcx],xmm3
000171ca  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
000171cf  48 83 c1 20  add rcx,20h
000171d3  49 83 f8 20  cmp r8,20h
000171d7  7d b7  jge short 0000000000017190h
000171d9  e9 8b 01 00 00  jmp 0000000000017369h
000171e0  49 83 e8 20  sub r8,20h
000171e4  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
000171e9  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
000171ee  48 83 c2 20  add rdx,20h
000171f2  66 0f 73 d9 0b  psrldq xmm1,0Bh
000171f7  66 0f 6f d3  movdqa xmm2,xmm3
000171fb  66 0f 73 fb 05  pslldq xmm3,5
00017200  66 0f eb d9  por xmm3,xmm1
00017204  66 0f 73 da 0b  psrldq xmm2,0Bh
00017209  66 0f 6f c8  movdqa xmm1,xmm0
0001720d  66 0f 73 f8 05  pslldq xmm0,5
00017212  66 0f eb c2  por xmm0,xmm2
00017216  66 0f 7f 19  movdqa [rcx],xmm3
0001721a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001721f  48 83 c1 20  add rcx,20h
00017223  49 83 f8 20  cmp r8,20h
00017227  7d b7  jge short 00000000000171E0h
00017229  e9 3b 01 00 00  jmp 0000000000017369h
00017230  49 83 e8 20  sub r8,20h
00017234  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00017239  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
0001723e  48 83 c2 20  add rdx,20h
00017242  66 0f 73 d9 0c  psrldq xmm1,0Ch
00017247  66 0f 6f d3  movdqa xmm2,xmm3
0001724b  66 0f 73 fb 04  pslldq xmm3,4
00017250  66 0f eb d9  por xmm3,xmm1
00017254  66 0f 73 da 0c  psrldq xmm2,0Ch
00017259  66 0f 6f c8  movdqa xmm1,xmm0
0001725d  66 0f 73 f8 04  pslldq xmm0,4
00017262  66 0f eb c2  por xmm0,xmm2
00017266  66 0f 7f 19  movdqa [rcx],xmm3
0001726a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001726f  48 83 c1 20  add rcx,20h
00017273  49 83 f8 20  cmp r8,20h
00017277  7d b7  jge short 0000000000017230h
00017279  e9 eb 00 00 00  jmp 0000000000017369h
00017280  49 83 e8 20  sub r8,20h
00017284  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00017289  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
0001728e  48 83 c2 20  add rdx,20h
00017292  66 0f 73 d9 0d  psrldq xmm1,0Dh
00017297  66 0f 6f d3  movdqa xmm2,xmm3
0001729b  66 0f 73 fb 03  pslldq xmm3,3
000172a0  66 0f eb d9  por xmm3,xmm1
000172a4  66 0f 73 da 0d  psrldq xmm2,0Dh
000172a9  66 0f 6f c8  movdqa xmm1,xmm0
000172ad  66 0f 73 f8 03  pslldq xmm0,3
000172b2  66 0f eb c2  por xmm0,xmm2
000172b6  66 0f 7f 19  movdqa [rcx],xmm3
000172ba  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
000172bf  48 83 c1 20  add rcx,20h
000172c3  49 83 f8 20  cmp r8,20h
000172c7  7d b7  jge short 0000000000017280h
000172c9  e9 9b 00 00 00  jmp 0000000000017369h
000172d0  49 83 e8 20  sub r8,20h
000172d4  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
000172d9  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
000172de  48 83 c2 20  add rdx,20h
000172e2  66 0f 73 d9 0e  psrldq xmm1,0Eh
000172e7  66 0f 6f d3  movdqa xmm2,xmm3
000172eb  66 0f 73 fb 02  pslldq xmm3,2
000172f0  66 0f eb d9  por xmm3,xmm1
000172f4  66 0f 73 da 0e  psrldq xmm2,0Eh
000172f9  66 0f 6f c8  movdqa xmm1,xmm0
000172fd  66 0f 73 f8 02  pslldq xmm0,2
00017302  66 0f eb c2  por xmm0,xmm2
00017306  66 0f 7f 19  movdqa [rcx],xmm3
0001730a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001730f  48 83 c1 20  add rcx,20h
00017313  49 83 f8 20  cmp r8,20h
00017317  7d b7  jge short 00000000000172D0h
00017319  eb 4e  jmp short 0000000000017369h
00017320  49 83 e8 20  sub r8,20h
00017324  66 0f 6f 5a 10  movdqa xmm3,[rdx+10h]
00017329  66 0f 6f 42 20  movdqa xmm0,[rdx+20h]
0001732e  48 83 c2 20  add rdx,20h
00017332  66 0f 73 d9 0f  psrldq xmm1,0Fh
00017337  66 0f 6f d3  movdqa xmm2,xmm3
0001733b  66 0f 73 fb 01  pslldq xmm3,1
00017340  66 0f eb d9  por xmm3,xmm1
00017344  66 0f 73 da 0f  psrldq xmm2,0Fh
00017349  66 0f 6f c8  movdqa xmm1,xmm0
0001734d  66 0f 73 f8 01  pslldq xmm0,1
00017352  66 0f eb c2  por xmm0,xmm2
00017356  66 0f 7f 19  movdqa [rcx],xmm3
0001735a  66 0f 7f 41 10  movdqa [rcx+10h],xmm0
0001735f  48 83 c1 20  add rcx,20h
00017363  49 83 f8 20  cmp r8,20h
00017367  7d b7  jge short 0000000000017320h
00017369  4c 8d 15 d0 ec 00 00  lea r10,[26040h]
00017370  49 03 d3  add rdx,r11
00017373  49 03 c8  add rcx,r8
00017376  49 03 d0  add rdx,r8
00017379  43 ff 24 c2  jmp qword ptr [r10+r8*8]
00017380  48 8d 49 40  lea rcx,[rcx+40h]
00017384  48 8d 52 40  lea rdx,[rdx+40h]
00017388  4d 8d 40 c0  lea r8,[r8-40h]
0001738c  0f 18 82 80 01 00 00  prefetchnta [rdx+180h]
00017393  f3 0f 6f 42 c0  movdqu xmm0,[rdx-40h]
00017398  f3 0f 6f 4a d0  movdqu xmm1,[rdx-30h]
0001739d  49 83 f8 40  cmp r8,40h
000173a1  66 0f e7 41 c0  movntdq [rcx-40h],xmm0
000173a6  66 0f e7 49 d0  movntdq [rcx-30h],xmm1
000173ab  f3 0f 6f 52 e0  movdqu xmm2,[rdx-20h]
000173b0  f3 0f 6f 5a f0  movdqu xmm3,[rdx-10h]
000173b5  66 0f e7 51 e0  movntdq [rcx-20h],xmm2
000173ba  66 0f e7 59 f0  movntdq [rcx-10h],xmm3
000173bf  7d bf  jge short 0000000000017380h
000173c1  4c 8d 15 b8 f2 00 00  lea r10,[26680h]
000173c8  4d 8b c8  mov r9,r8
000173cb  49 c1 e9 04  shr r9,4
000173cf  49 c1 e1 04  shl r9,4
000173d3  49 03 c9  add rcx,r9
000173d6  49 03 d1  add rdx,r9
000173d9  4d 2b c1  sub r8,r9
000173dc  49 c1 e9 04  shr r9,4
000173e0  0f ae f8  sfence
000173e3  43 ff 24 ca  jmp qword ptr [r10+r9*8]
000173f0  66 0f 6f 02  movdqa xmm0,[rdx]
000173f4  66 0f 6f 4a 10  movdqa xmm1,[rdx+10h]
000173f9  66 0f 7f 01  movdqa [rcx],xmm0
000173fd  66 0f 7f 49 10  movdqa [rcx+10h],xmm1
00017402  4d 8d 40 80  lea r8,[r8-80h]
00017406  66 0f 6f 52 20  movdqa xmm2,[rdx+20h]
0001740b  66 0f 6f 5a 30  movdqa xmm3,[rdx+30h]
00017410  66 0f 7f 51 20  movdqa [rcx+20h],xmm2
00017415  66 0f 7f 59 30  movdqa [rcx+30h],xmm3
0001741a  66 0f 6f 42 40  movdqa xmm0,[rdx+40h]
0001741f  66 0f 6f 4a 50  movdqa xmm1,[rdx+50h]
00017424  49 81 f8 a8 00 00 00  cmp r8,0A8h
0001742b  66 0f 7f 41 40  movdqa [rcx+40h],xmm0
00017430  66 0f 7f 49 50  movdqa [rcx+50h],xmm1
00017435  66 0f 6f 52 60  movdqa xmm2,[rdx+60h]
0001743a  66 0f 6f 5a 70  movdqa xmm3,[rdx+70h]
0001743f  48 8d 92 80 00 00 00  lea rdx,[rdx+80h]
00017446  66 0f 7f 51 60  movdqa [rcx+60h],xmm2
0001744b  66 0f 7f 59 70  movdqa [rcx+70h],xmm3
00017450  48 8d 89 80 00 00 00  lea rcx,[rcx+80h]
00017457  7d 97  jge short 00000000000173F0h
00017459  4c 8d 15 e0 eb 00 00  lea r10,[26040h]
00017460  49 03 c8  add rcx,r8
00017463  49 03 d0  add rdx,r8
00017466  43 ff 24 c2  jmp qword ptr [r10+r8*8]
00017470  4c 3b 05 c1 ad 00 00  cmp r8,[22238h]
00017477  7f 77  jg short 00000000000174F0h
00017479  eb 05  jmp short 0000000000017480h
00017480  4c 8b 0a  mov r9,[rdx]
00017483  4c 8b 52 08  mov r10,[rdx+8]
00017487  4d 8d 40 c0  lea r8,[r8-40h]
0001748b  4c 89 09  mov [rcx],r9
0001748e  4c 89 51 08  mov [rcx+8],r10
00017492  4c 8b 5a 10  mov r11,[rdx+10h]
00017496  4c 8b 4a 18  mov r9,[rdx+18h]
0001749a  4c 89 59 10  mov [rcx+10h],r11
0001749e  4c 89 49 18  mov [rcx+18h],r9
000174a2  49 83 f8 40  cmp r8,40h
000174a6  4c 8b 52 20  mov r10,[rdx+20h]
000174aa  4c 8b 5a 28  mov r11,[rdx+28h]
000174ae  4c 89 51 20  mov [rcx+20h],r10
000174b2  4c 89 59 28  mov [rcx+28h],r11
000174b6  4c 8b 4a 30  mov r9,[rdx+30h]
000174ba  4c 8b 52 38  mov r10,[rdx+38h]
000174be  48 8d 52 40  lea rdx,[rdx+40h]
000174c2  4c 89 49 30  mov [rcx+30h],r9
000174c6  4c 89 51 38  mov [rcx+38h],r10
000174ca  48 8d 49 40  lea rcx,[rcx+40h]
000174ce  7f b0  jg short 0000000000017480h
000174d0  4c 8d 15 69 eb 00 00  lea r10,[26040h]
000174d7  4a 8d 14 02  lea rdx,[rdx+r8]
000174db  4a 8d 0c 01  lea rcx,[rcx+r8]
000174df  43 ff 24 c2  jmp qword ptr [r10+r8*8]
000174f0  49 83 e8 40  sub r8,40h
000174f4  0f 18 82 80 01 00 00  prefetchnta [rdx+180h]
000174fb  4c 8b 0a  mov r9,[rdx]
000174fe  4c 0f c3 09  movnti [rcx],r9
00017502  4c 8b 52 08  mov r10,[rdx+8]
00017506  4c 0f c3 51 08  movnti [rcx+8],r10
0001750b  4c 8b 5a 10  mov r11,[rdx+10h]
0001750f  4c 0f c3 59 10  movnti [rcx+10h],r11
00017514  4c 8b 4a 18  mov r9,[rdx+18h]
00017518  4c 0f c3 49 18  movnti [rcx+18h],r9
0001751d  4c 8b 52 20  mov r10,[rdx+20h]
00017521  4c 0f c3 51 20  movnti [rcx+20h],r10
00017526  4c 8b 5a 28  mov r11,[rdx+28h]
0001752a  4c 0f c3 59 28  movnti [rcx+28h],r11
0001752f  4c 8b 4a 30  mov r9,[rdx+30h]
00017533  4c 0f c3 49 30  movnti [rcx+30h],r9
00017538  4c 8b 52 38  mov r10,[rdx+38h]
0001753c  4c 0f c3 51 38  movnti [rcx+38h],r10
00017541  48 8d 52 40  lea rdx,[rdx+40h]
00017545  48 8d 49 40  lea rcx,[rcx+40h]
00017549  49 83 f8 40  cmp r8,40h
0001754d  7d a1  jge short 00000000000174F0h
0001754f  0f ae f8  sfence
00017552  e9 79 ff ff ff  jmp 00000000000174D0h
00017557  f3 0f 6f 42 80  movdqu xmm0,[rdx-80h]
0001755c  66 0f 7f 41 80  movdqa [rcx-80h],xmm0
00017561  f3 0f 6f 4a 90  movdqu xmm1,[rdx-70h]
00017566  66 0f 7f 49 90  movdqa [rcx-70h],xmm1
0001756b  f3 0f 6f 52 a0  movdqu xmm2,[rdx-60h]
00017570  66 0f 7f 51 a0  movdqa [rcx-60h],xmm2
00017575  f3 0f 6f 5a b0  movdqu xmm3,[rdx-50h]
0001757a  66 0f 7f 59 b0  movdqa [rcx-50h],xmm3
0001757f  f3 0f 6f 42 c0  movdqu xmm0,[rdx-40h]
00017584  66 0f 7f 41 c0  movdqa [rcx-40h],xmm0
00017589  f3 0f 6f 4a d0  movdqu xmm1,[rdx-30h]
0001758e  66 0f 7f 49 d0  movdqa [rcx-30h],xmm1
00017593  f3 0f 6f 52 e0  movdqu xmm2,[rdx-20h]
00017598  66 0f 7f 51 e0  movdqa [rcx-20h],xmm2
0001759d  f3 0f 6f 5a f0  movdqu xmm3,[rdx-10h]
000175a2  66 0f 7f 59 f0  movdqa [rcx-10h],xmm3
000175a7  4c 8d 15 92 ea 00 00  lea r10,[26040h]
000175ae  49 03 d0  add rdx,r8
000175b1  49 03 c8  add rcx,r8
000175b4  43 ff 24 c2  jmp qword ptr [r10+r8*8]
000175b8  4c 8b 0a  mov r9,[rdx]
000175bb  4c 89 09  mov [rcx],r9
000175be  48 83 c1 08  add rcx,8
000175c2  48 83 c2 08  add rdx,8
000175c6  49 83 e8 08  sub r8,8
000175ca  e9 7b f8 ff ff  jmp 0000000000016E4Ah
000175cf  44 8b 0a  mov r9d,[rdx]
000175d2  44 89 09  mov [rcx],r9d
000175d5  48 83 c1 04  add rcx,4
000175d9  48 83 c2 04  add rdx,4
000175dd  49 83 e8 04  sub r8,4
000175e1  44 8b 0a  mov r9d,[rdx]
000175e4  44 89 09  mov [rcx],r9d
000175e7  48 83 c1 04  add rcx,4
000175eb  48 83 c2 04  add rdx,4
000175ef  49 83 e8 04  sub r8,4
000175f3  44 8b 0a  mov r9d,[rdx]
000175f6  44 89 09  mov [rcx],r9d
000175f9  48 83 c2 04  add rdx,4
000175fd  48 83 c1 04  add rcx,4
00017601  49 83 e8 04  sub r8,4
00017605  e9 40 f8 ff ff  jmp 0000000000016E4Ah
00017610  49 83 f8 01  cmp r8,1
0001763c  4c 8d 1d ed f0 00 00  lea r11,[26730h]
00017653  43 ff 24 c3  jmp qword ptr [r11+r8*8]
00017666  4c 8d 1d 83 f0 00 00  lea r11,[266F0h]
00017681  43 ff 24 cb  jmp qword ptr [r11+r9*8]
000178f7  83 3d 32 bd 00 00 02  cmp dword ptr [23630h],2
0001790d  4c 8d 1d 5c f2 00 00  lea r11,[26B70h]
0001792f  43 ff 24 d3  jmp qword ptr [r11+r10*8]
0001798b  4c 8d 1d 6e f2 00 00  lea r11,[26C00h]
000179a2  43 ff 24 c3  jmp qword ptr [r11+r8*8]
00017e93  4c 3b 05 96 a3 00 00  cmp r8,[22230h]
00017edb  4c 8d 1d 1e ed 00 00  lea r11,[26C00h]
00017ee5  43 ff 24 c3  jmp qword ptr [r11+r8*8]
00017f41  4c 8d 1d b8 ec 00 00  lea r11,[26C00h]
00017f4b  43 ff 24 c3  jmp qword ptr [r11+r8*8]
00017f50  4c 3b 05 d9 a2 00 00  cmp r8,[22230h]
00017f8d  4c 8d 1d 9c e7 00 00  lea r11,[26730h]
00017f98  43 ff 24 c3  jmp qword ptr [r11+r8*8]
00017fe5  4c 8d 1d 44 e7 00 00  lea r11,[26730h]
00017ff0  43 ff 24 c3  jmp qword ptr [r11+r8*8]
00017ff4  ff 25 1e 10 00 00  jmp qword ptr [19018h]
00017ffa  ff 25 20 10 00 00  jmp qword ptr [19020h]
00018000  ff 25 22 10 00 00  jmp qword ptr [19028h]
00018006  ff 25 24 10 00 00  jmp qword ptr [19030h]
0001800c  ff 25 26 10 00 00  jmp qword ptr [19038h]
00018012  ff 25 28 10 00 00  jmp qword ptr [19040h]
00018018  ff 25 2a 10 00 00  jmp qword ptr [19048h]
0001801e  ff 25 2c 10 00 00  jmp qword ptr [19050h]
00018024  ff 25 2e 10 00 00  jmp qword ptr [19058h]
0001802a  ff 25 30 10 00 00  jmp qword ptr [19060h]
00018030  ff 25 32 10 00 00  jmp qword ptr [19068h]
00018036  ff 25 34 10 00 00  jmp qword ptr [19070h]
0001803c  ff 25 36 10 00 00  jmp qword ptr [19078h]
00018042  ff 25 38 10 00 00  jmp qword ptr [19080h]
00018048  ff 25 3a 10 00 00  jmp qword ptr [19088h]
0001804e  ff 25 3c 10 00 00  jmp qword ptr [19090h]
00018054  ff 25 3e 10 00 00  jmp qword ptr [19098h]
0001805a  ff 25 40 10 00 00  jmp qword ptr [190A0h]
00018060  ff 25 aa 0f 00 00  jmp qword ptr [19010h]
00018066  ff 25 44 10 00 00  jmp qword ptr [190B0h]
0001806c  ff 25 46 10 00 00  jmp qword ptr [190B8h]
00018072  ff 25 48 10 00 00  jmp qword ptr [190C0h]
00018078  ff 25 5a 10 00 00  jmp qword ptr [190D8h]
0001807e  ff 25 4c 10 00 00  jmp qword ptr [190D0h]
00018084  ff 25 3e 10 00 00  jmp qword ptr [190C8h]
0001808a  ff 25 a0 10 00 00  jmp qword ptr [19130h]
00018090  ff 25 82 10 00 00  jmp qword ptr [19118h]
00018096  ff 25 84 10 00 00  jmp qword ptr [19120h]
0001809c  ff 25 d6 10 00 00  jmp qword ptr [19178h]
000180a2  ff 25 90 10 00 00  jmp qword ptr [19138h]
000180a8  ff 25 c2 10 00 00  jmp qword ptr [19170h]
000180ae  ff 25 b4 10 00 00  jmp qword ptr [19168h]
000180b4  ff 25 a6 10 00 00  jmp qword ptr [19160h]
000180ba  ff 25 98 10 00 00  jmp qword ptr [19158h]
000180c0  ff 25 8a 10 00 00  jmp qword ptr [19150h]
000180c6  ff 25 7c 10 00 00  jmp qword ptr [19148h]
000180cc  ff 25 6e 10 00 00  jmp qword ptr [19140h]
000180d2  ff 25 30 10 00 00  jmp qword ptr [19108h]
000180d8  ff 25 4a 10 00 00  jmp qword ptr [19128h]
000180de  ff 25 a4 10 00 00  jmp qword ptr [19188h]
