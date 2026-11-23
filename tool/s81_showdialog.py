# -*- coding: utf-8 -*-
"""s81: recover ShowDialog argument/result semantics inside 0x1320-0x1483."""
import csv, struct, sys
from pathlib import Path

sys.path.insert(0, 'tool')
from pe_reader import PE, parse_asm

OUT = Path('handoff/inbox/NATIVE-337/code/s81-showdialog.csv')
ASM = Path('handoff/inbox/NATIVE-337/code/native.asm')
DLL = Path('_t13/orig/FindComponent.dll')

ITEMS = [
    ('name-string', '0x1345', 'LEA RAX,[rip+0x64D4] -> 0x7820', 'UTF-16LE "ShowDialog" (0x7820)'),
    ('locale', '0x1357', 'CALL qword ptr [0x180007060]', 'KERNEL32.dll!GetUserDefaultLCID -> lcid'),
    ('getidsofnames', '0x1389', 'CALL qword ptr [RBX+0x28]', 'IDispatch::GetIDsOfNames(this=RCX/RDI, rgszNames=RDX(0x82F8 slot array), cNames=[RSP+0x20], lcid=R9D, rgDispId=[RSP+0x28])'),
    ('dispid-out', '0x1365', 'MOV qword ptr [RSP+0x28],RCX (RCX=&[RSP+0xC8])', 'rgDispId buffer at [RSP+0xC8]; DISPID written by GetIDsOfNames'),
    ('branch-hr', '0x138E', 'JNS 0x1800013A0', 'HRESULT >= 0 -> build DISPPARAMS and Invoke; < 0 -> Release and return 0'),
    ('invoke', '0x1444', 'CALL qword ptr [RBX+0x30]', 'IDispatch::Invoke(dispIdMember=RDX from [RSP+0xC8], riid=R8=0x82F8 IID_NULL, lcid=R9D, wFlags=[RSP+0x20]=DISPATCH_METHOD, pDispParams=[RSP+0x28], pVarResult=[RSP+0x30], pExcepInfo=[RSP+0x38], puArgErr=[RSP+0x40])'),
    ('dispparams', '0x13A2', 'MOV [RSP+0x58],RSI; MOV [RSP+0x60],R14; LEA RAX,[RSP+0x68]; MOV [RSP+0x50],RAX', 'DISPPARAMS at [RSP+0x50]: rgvarg=&[RSP+0x68], rgdispidNamedArgs=0, cArgs/cNamedArgs from R14(1) region'),
    ('result', '0x1449', 'CMOVNS ESI,[RSP+0x88]', 'on HRESULT >= 0 load success value into ESI; 0x1469 MOV EAX,ESI -> int/bool return'),
    ('release-fail', '0x1396', 'CALL qword ptr [RAX+0x10]', 'Release() on GetIDsOfNames failure path'),
    ('release-ok', '0x1457', 'CALL qword ptr [RDX+0x10]', 'Release() after Invoke'),
    ('fail-path', '0x133D', 'MOV RDI,RAX; TEST RAX; JZ 0x1399; XOR EAX,EAX', 'factory failure -> RDI=0, return 0 (false); documented failure path'),
]


def main():
    data = DLL.read_bytes()
    pe = PE(data)
    _, ins = parse_asm(str(ASM))
    by = {a: (l, b, t) for (l, a, b, t, r) in ins}
    rows = []
    for item, rva, evidence, meaning in ITEMS:
        a = int(rva, 16)
        ln, b, t = by.get(a, (0, b'', ''))
        rows.append(dict(item=item, rva=rva, instruction=t, bytes=b.hex(),
                         asm='code/native.asm#L%d' % ln if ln else '',
                         evidence=evidence, meaning=meaning))
    OUT.parent.mkdir(parents=True, exist_ok=True)
    with open(OUT, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
        w.writeheader(); w.writerows(rows)
    for r in rows:
        print(r['item'], r['rva'], r['instruction'])


if __name__ == '__main__':
    main()
