# -*- coding: utf-8 -*-
"""s93: ShowDialog binding is derived from bytes and carried into the delivery table.

Everything below comes from the original binary / listing bytes, not from prose:
  * ProgID string      0x2375 LEA R8,[rip+disp] -> RVA 0x78A8, ASCII "AspenTech...410"
  * CLSIDFromProgID    0x23A0 CALL [0x180007648]
  * IID_IDispatch      0x23B4 LEA R9,[rip+disp] -> RVA 0x8308 (00020400-0000-0000-c000-000000000046)
  * dispatch name      0x1345 LEA RAX,[rip+disp] -> RVA 0x7820, UTF-16LE "ShowDialog"
  * vt immediate       0x13DD MOV EAX,imm -> VT_BSTR=8
  * riid for calls     0x137F LEA RDX,[rip+disp] -> RVA 0x82F8 (all-zero GUID = IID_NULL)
"""
import argparse, csv, struct, sys
from pathlib import Path

sys.path.insert(0, 'tool')
from pe_reader import PE, parse_asm


def lea_target(data, pe, rva):
    p = pe.filepos(rva)
    b = data[p:p + 7]
    if len(b) < 7 or b[0] not in (0x48, 0x4C) or b[1] != 0x8D:
        return None
    return rva + 7 + struct.unpack_from('<i', b, 3)[0]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--out', default='')
    a = ap.parse_args()
    folder = Path(a.folder)
    data = Path(a.binary).read_bytes()
    pe = PE(data)

    progid_rva = lea_target(data, pe, 0x2375)
    progid = data[pe.filepos(progid_rva):].split(b'\x00')[0].decode('latin-1')
    name_rva = lea_target(data, pe, 0x1345)
    name = data[pe.filepos(name_rva):pe.filepos(name_rva) + 40].decode('utf-16-le', 'replace').split('\x00')[0]
    iid_rva = lea_target(data, pe, 0x23B4)
    iid = data[pe.filepos(iid_rva):pe.filepos(iid_rva) + 16]
    calls_riid_rva = lea_target(data, pe, 0x137F)
    calls_riid = data[pe.filepos(calls_riid_rva):pe.filepos(calls_riid_rva) + 16]
    vt = struct.unpack_from('<I', data, pe.filepos(0x13DD) + 1)[0]

    asm = folder / 'code' / 'native.asm'
    _, ins = parse_asm(str(asm)) if asm.exists() else (None, [])
    by = {addr: (ln, b, t) for (ln, addr, b, t, r) in ins}

    rows = [
        dict(item='binding-progid', rva='0x%X' % progid_rva, derived=progid,
             meaning='registration key resolved at 0x23A0 CLSIDFromProgID; binding = HKCR\\%s\\CLSID' % progid),
        dict(item='binding-name', rva='0x%X' % name_rva, derived=name,
             meaning='dispatch name passed to GetIDsOfNames (UTF-16LE at %#x)' % name_rva),
        dict(item='binding-iid', rva='0x%X' % iid_rva, derived=iid.hex(),
             meaning='IID passed to CoCreateInstance at 0x23C8 = IID_IDispatch'),
        dict(item='calls-riid', rva='0x%X' % calls_riid_rva, derived=calls_riid.hex(),
             meaning='riid passed to GetIDsOfNames/Invoke at 0x1389/0x1444 (all zero = IID_NULL)'),
        dict(item='variant-vt', rva='0x13DD', derived=str(vt),
             meaning='VARIANT vt immediate (8 = VT_BSTR); stride 0x18 from the VariantInit loop at 0x13C0'),
    ]
    out = Path(a.out) if a.out else folder / 'code' / 's81-showdialog.csv'
    for r in rows:
        ln = by.get(int(r['rva'], 16), (None, b'', ''))[0]
        r['asm'] = 'code/native.asm#L%d' % ln if ln else ''
    with open(out, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['item', 'rva', 'derived', 'meaning', 'asm'])
        w.writeheader()
        w.writerows(rows)
    print('progid=%s name=%s iid=%s vt=%d rows=%d -> %s'
          % (progid, name, iid.hex(), vt, len(rows), out))


if __name__ == '__main__':
    main()
