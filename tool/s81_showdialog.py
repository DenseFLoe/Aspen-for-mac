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
    ('getidsofnames', '0x1389', 'CALL qword ptr [RBX+0x28]', 'IDispatch::GetIDsOfNames six params (Windows x64): RCX=this(RDI) RDX=riid(0x82F8 IID_NULL) R8=rgszNames(&[RSP+0xD0]) R9=cNames(R14D=1) [RSP+0x20]=lcid(GetUserDefaultLCID@0x1357) [RSP+0x28]=rgDispId(&[RSP+0xC8])'),
    ('dispid-out', '0x1365', 'MOV qword ptr [RSP+0x28],RCX (RCX=&[RSP+0xC8])', 'rgDispId buffer at [RSP+0xC8]; DISPID written by GetIDsOfNames'),
    ('branch-hr', '0x138E', 'JNS 0x1800013A0', 'HRESULT >= 0 -> build DISPPARAMS and Invoke; < 0 -> Release and return 0'),
    ('invoke', '0x1444', 'CALL qword ptr [RBX+0x30]', 'IDispatch::Invoke params 5..9 (Windows x64 stack args after RCX=this RDX=dispIdMember([RSP+0xC8]) R8=riid(0x82F8) R9=lcid): [RSP+0x20]=wFlags(1 DISPATCH_METHOD) [RSP+0x28]=pDispParams(&[RSP+0x50]) [RSP+0x30]=pVarResult(&[RSP+0x80]) [RSP+0x38]=pExcepInfo(0) [RSP+0x40]=puArgErr(0)'),
    ('dispparams', '0x13A2', 'MOV [RSP+0x58],RSI; MOV [RSP+0x60],R14; LEA RAX,[RSP+0x68]; MOV [RSP+0x50],RAX', 'DISPPARAMS at [RSP+0x50]: rgvarg=&[RSP+0x68], rgdispidNamedArgs=0; [RSP+0x60] holds TWO 32-bit fields written by one qword store: cArgs=1 (low dword), cNamedArgs=0 (high dword)'),
    ('result', '0x1449', 'CMOVNS ESI,[RSP+0x88]', 'on HRESULT >= 0 load success value into ESI; 0x1469 MOV EAX,ESI returns int (only the low 32 bits of RAX are meaningful)'),
    ('variant-init', '0x13CF', 'CALL qword ptr [0x1800070f0]', 'VariantInit contract: 0x13CF CALL OLEAUT32.dll!#8 over the VARIANT array at [RSP+0x68], stride 0x18, count cArgs([RSP+0x60] low dword) -> 24 bytes set to VT_EMPTY'),
    ('variant-union', '0x13E7', 'MOV qword ptr [RSP+0x70],RBP', 'union after vt: bstrVal = RBP (BSTR built earlier); only vt (2B) + union pointer (8B) are written after VariantInit'),
    ('result-clear', '0x145B', 'LEA RCX,[RSP+0x80]; CALL qword ptr [0x1800070d0]', 'OLEAUT32.dll!#9 = VariantClear on pVarResult at [RSP+0x80], after the final Release and before returning ESI'),
    ('release-fail', '0x1396', 'CALL qword ptr [RAX+0x10]', 'Release() on GetIDsOfNames failure path'),
    ('release-ok', '0x1457', 'CALL qword ptr [RDX+0x10]', 'Release() after Invoke'),
    ('fail-path', '0x133D', 'MOV RDI,RAX; TEST RAX; JZ 0x1399; XOR EAX,EAX', 'factory failure -> RDI=0, return 0 (false); documented failure path'),
]


def _lea_target(data, pe, rva):
    import struct
    p = pe.filepos(rva)
    b = data[p:p + 7]
    if len(b) < 7 or b[0] not in (0x48, 0x4C) or b[1] != 0x8D:
        return None
    return rva + 7 + struct.unpack_from('<i', b, 3)[0]


def _listing(asm_path, rva):
    from pe_reader import parse_asm
    if not asm_path.exists():
        return None, None
    _, ins = parse_asm(str(asm_path))
    for (ln, addr, b, text, raw) in ins:
        if addr == rva:
            return b.hex(), ln
    return None, None


def binding_rows(data, pe, asm_path):
    """Binding evidence derived from bytes: ProgID, dispatch name, IID, call riid, vt."""
    import struct
    prog = _lea_target(data, pe, 0x2375)
    progid = data[pe.filepos(prog):].split(b'\x00')[0].decode('latin-1')
    nm = _lea_target(data, pe, 0x1345)
    name = data[pe.filepos(nm):pe.filepos(nm) + 40].decode('utf-16-le', 'replace').split('\x00')[0]
    iid_t = _lea_target(data, pe, 0x23B4)
    iid = data[pe.filepos(iid_t):pe.filepos(iid_t) + 16].hex()
    criid_t = _lea_target(data, pe, 0x137F)
    criid = data[pe.filepos(criid_t):pe.filepos(criid_t) + 16].hex()
    vt = struct.unpack_from('<I', data, pe.filepos(0x13DD) + 1)[0]
    return [
        ('binding-progid', '0x%X' % prog, 'ASCII ProgID %s' % progid,
         'registration key for CLSIDFromProgID at 0x23A0; external binding = HKCR\\%s\\CLSID' % progid),
        ('binding-name', '0x%X' % nm, 'UTF-16LE %s' % name,
         'dispatch name resolved through GetIDsOfNames at 0x1389'),
        ('binding-iid', '0x%X' % iid_t, iid,
         'IID for CoCreateInstance at 0x23C8 = IID_IDispatch {00020400-...-46}'),
        ('calls-riid', '0x%X' % criid_t, criid,
         'riid for GetIDsOfNames/Invoke (all zero = IID_NULL)'),
        ('variant-vt', '0x13DD', 'vt immediate %d' % vt,
         'vt TYPE TAG only (8 = VT_BSTR), derived from the MOV EAX,imm at 0x13DD; '
         'the 24-byte element stride (0x18) is a separate property from the VariantInit loop at 0x13C0'),
    ]


def main():
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default=str(DLL))
    ap.add_argument('--out', default='')
    args = ap.parse_args()
    folder = Path(args.folder)
    data = Path(args.binary).read_bytes()
    pe = PE(data)
    _, ins = parse_asm(str(folder / 'code' / 'native.asm'))
    by = {a: (l, b, t) for (l, a, b, t, r) in ins}
    rows = []
    for item, rva, evidence, meaning in ITEMS:
        a = int(rva, 16)
        ln, b, t = by.get(a, (0, b'', ''))
        rows.append(dict(item=item, rva=rva, instruction=t, bytes=b.hex(),
                         asm='code/native.asm#L%d' % ln if ln else '',
                         evidence=evidence, meaning=meaning))
    for item, rva, derived, meaning in binding_rows(data, pe, folder / 'code' / 'native.asm'):
        a = int(rva, 16) if rva.startswith('0x') and len(rva) <= 6 else 0
        ln, b, t = by.get(a, (0, b'', ''))
        site = {'variant-vt': 0x13DD, 'calls-riid': 0x137F}.get(item)
        if site:
            n = 7 if item == 'calls-riid' else 5
            lb, _ln = _listing(folder / 'code' / 'native.asm', site)
            ob = data[pe.filepos(site):pe.filepos(site) + n].hex()
            meaning = meaning + '; listing=%s original=%s listing_matches=%s' % (
                lb or '-', ob, 'yes' if lb and lb == ob else 'no')
        rows.append(dict(item=item, rva=rva, instruction=derived, bytes=b.hex(),
                         asm='code/native.asm#L%d' % ln if ln else '', evidence='derived from bytes',
                         meaning=meaning))
    reg_path = folder / 's97-registration.json'
    if reg_path.exists():
        import json as _json
        reg = _json.loads(reg_path.read_text(encoding='utf-8'))
        r64 = reg.get('Registry64', {})
        pe_info = reg.get('PE', {})
        rows.extend([
            dict(item='deploy-clsid', rva='registration', instruction=r64.get('CLSID', ''),
                 bytes='', asm='', evidence='s97-registration.json Registry64.CLSID',
                 meaning='CLSID for ProgID %s (server %s)' % (r64.get('ProgID', ''), r64.get('server', ''))),
            dict(item='deploy-assembly-sha256', rva='registration', instruction=pe_info.get('sha256', ''),
                 bytes='', asm='', evidence='s97-registration.json PE.sha256',
                 meaning='deployed assembly %s; version %s' % (r64.get('assembly', ''), pe_info.get('assemblyVersion', ''))),
            dict(item='deploy-signature', rva='registration', instruction='PublicKeyToken=null',
                 bytes='', asm='', evidence='s97-registration.json Registry64.assembly',
                 meaning='assembly is not strong-name signed (PublicKeyToken=null); PE sha256 above is the deployment signature'),
        ])
    out_path = Path(args.out) if args.out else OUT
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
        w.writeheader(); w.writerows(rows)
    for r in rows:
        print(r['item'], r['rva'], r['instruction'])


if __name__ == '__main__':
    main()
