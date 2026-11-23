# -*- coding: utf-8 -*-
"""s89: put the same six-parameter / Invoke ABI text in every place that states it.

Places kept in sync: (1) calls.csv note for the four indirect rows, (2) the asm comment block
at the end of code/native.asm (append-only, so instruction line numbers do not move),
(3) tool/s81_showdialog.py, (4) the receipt.
"""
import csv, hashlib, sys
from pathlib import Path

ITEM = Path('handoff/inbox/NATIVE-337')
CALLS = ITEM / 'calls.csv'
ASM = ITEM / 'code' / 'native.asm'
MARK = '; --- s89 ABI reference (append-only block; instruction lines above are unchanged) ---'

GID = ('IDispatch::GetIDsOfNames six params (Windows x64): RCX=this(RDI) RDX=riid(0x82F8 IID_NULL) '
       'R8=rgszNames(&[RSP+0xD0]) R9=cNames(R14D=1) [RSP+0x20]=lcid(GetUserDefaultLCID@0x1357) '
       '[RSP+0x28]=rgDispId(&[RSP+0xC8])')
INV = ('IDispatch::Invoke params 5..9 (Windows x64 stack args after RCX=this RDX=dispIdMember '
       'R8=riid(0x82F8) R9=lcid): [RSP+0x20]=wFlags(1 DISPATCH_METHOD) [RSP+0x28]=pDispParams(&[RSP+0x50]) '
       '[RSP+0x30]=pVarResult(&[RSP+0x80]) [RSP+0x38]=pExcepInfo(0) [RSP+0x40]=puArgErr(0)')
VAR = ('VariantInit contract: 0x13CF CALL OLEAUT32.dll!#8 over the VARIANT array at [RSP+0x68], '
       'stride 0x18, count cArgs([RSP+0x60] low dword); after init vt=8 VT_BSTR (0x13E2) and '
       'union.bstrVal=RBP (0x13E7); cleanup VariantClear OLEAUT32.dll!#9 at 0x1463')

NOTES = {
    '0x1389': 'indirect; ' + GID,
    '0x1396': 'indirect; Release on the GetIDsOfNames failure path (0x138E JNS not taken); ' + GID,
    '0x1444': 'indirect; ' + INV,
    '0x1457': 'indirect; Release after Invoke, before VariantClear at 0x1463; ' + INV,
}


def main():
    rows = list(csv.DictReader(open(CALLS, encoding='utf-8')))
    fields = list(rows[0].keys())
    changed = 0
    for r in rows:
        for site, note in NOTES.items():
            if r['callee'] == 'indirect@' + site:
                if r['note'] != note:
                    r['note'] = note
                    changed += 1
    with open(CALLS, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        w.writerows(rows)

    text = ASM.read_text(encoding='utf-8')
    if MARK not in text:
        block = [MARK,
                 '; ' + GID,
                 '; ' + INV,
                 '; ' + VAR,
                 '; end s89 block']
        ASM.write_text(text.rstrip('\n') + '\n' + '\n'.join(block) + '\n', encoding='utf-8')
        appended = True
    else:
        appended = False
    print('calls_rows_changed=%d asm_appended=%s' % (changed, appended))
    for p in (CALLS, ASM):
        print(hashlib.sha256(p.read_bytes()).hexdigest(), p)


if __name__ == '__main__':
    main()
