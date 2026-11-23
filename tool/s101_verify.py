# -*- coding: utf-8 -*-
"""s105 product-path verifier.

Reads three independent inputs and cross-checks them:
  * required attachment: <item>/s97-registration.json (deployment metadata)
  * real delivery table: <item>/code/s81-showdialog.csv (what we ship)
  * original binary listing:   <item>/code/native.asm vs the pinned original

ShowDialog is located by FULL TYPE NAME + METHOD NAME (not by index), then signature and RVA
are compared. Missing attachment / no match / contradiction => exit non-zero naming file,type,member,field.
"""
import argparse, csv, json, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pe_reader import PE, parse_asm

SITES = {0x13DD: 5, 0x137F: 7}
WANT_TYPE = 'AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver'
WANT_IFACE = 'AspenTech.AspenPlus.WpfFindComponent.IFindComponentDriver'
WANT_METHOD = 'ShowDialog'
WANT_SIG = '2001080E'
WANT_IMPL_RVA = 'A848'
REG = 's97-registration.json'
TABLE = 'code/s81-showdialog.csv'


def _fail(kind, where, field, expected, found):
    print('CONFLICT file=%s type=%s member=%s field=%s expected=%s found=%s'
          % (where, _type, _member, field, expected, found))
    return 1


_type = '-'
_member = '-'


def verify_listing(folder, binary):
    data = Path(binary).read_bytes()
    pe = PE(data)
    listing = {addr: b.hex() for (ln, addr, b, t, r) in parse_asm(str(Path(folder) / 'code' / 'native.asm'))[1]}
    bad = 0
    for site, n in SITES.items():
        orig = data[pe.filepos(site):pe.filepos(site) + n].hex()
        got = listing.get(site)
        if got is None or not got.startswith(orig):
            print('CONFLICT site=0x%X kind=listing-mismatch original=%s listing=%s' % (site, orig, got or '-'))
            bad += 1
    print('listing-check: sites=%d conflicts=%d' % (len(SITES), bad))
    return 3 if bad else 0


def _find_method(doc, type_name):
    for tname, node in doc.items():
        if not isinstance(node, dict):
            continue
        full = (node.get('namespace', '') + '.' + tname).strip('.')
        if full != type_name:
            continue
        for m in node.get('methods') or []:
            if m.get('name') == WANT_METHOD:
                return tname, m
    return None, None


def verify_signature(folder):
    reg = Path(folder) / REG
    if not reg.exists():
        print('CONFLICT file=%s type=%s member=%s field=attachment expected=present found=absent'
              % (REG, WANT_TYPE, WANT_METHOD))
        print('signature-check: conflicts=1')
        return 3
    doc = json.loads(reg.read_text(encoding='utf-8'))
    rc = 0
    for want_type, role in ((WANT_TYPE, 'implementation'), (WANT_IFACE, 'interface')):
        tname, m = _find_method(doc, want_type)
        if not m:
            print('CONFLICT file=%s type=%s member=%s field=name expected=%s found=absent'
                  % (REG, want_type, WANT_METHOD, WANT_METHOD))
            rc = 3
            continue
        sig = m.get('signature', '')
        rva = str(m.get('rva', ''))
        if sig != WANT_SIG:
            print('CONFLICT file=%s type=%s member=%s field=signature expected=%s found=%s'
                  % (REG, want_type, WANT_METHOD, WANT_SIG, sig))
            rc = 3
        if role == 'implementation' and rva.upper().lstrip('0X') != WANT_IMPL_RVA:
            print('CONFLICT file=%s type=%s member=%s field=rva expected=%s found=%s'
                  % (REG, want_type, WANT_METHOD, WANT_IMPL_RVA, rva))
            rc = 3
    # delivery table must carry the same signature and RVA
    tbl = Path(folder) / TABLE
    if not tbl.exists():
        print('CONFLICT file=%s type=%s member=%s field=table expected=present found=absent'
              % (TABLE, WANT_TYPE, WANT_METHOD))
        rc = 3
    else:
        rows = {r['item']: r for r in csv.DictReader(open(tbl, encoding='utf-8'))}
        for item, want in (('id-sig-impl', WANT_SIG), ('id-sig-interface', WANT_SIG)):
            got = rows.get(item, {}).get('instruction', '')
            if got != want:
                print('CONFLICT file=%s type=%s member=%s field=signature expected=%s found=%s'
                      % (TABLE, WANT_TYPE, WANT_METHOD, want, got or '-'))
                rc = 3
        impl_note = rows.get('id-sig-impl', {}).get('meaning', '')
        if WANT_IMPL_RVA.lower() not in impl_note.lower():
            print('CONFLICT file=%s type=%s member=%s field=rva expected=%s found=%s'
                  % (TABLE, WANT_TYPE, WANT_METHOD, WANT_IMPL_RVA, impl_note[:40]))
            rc = 3
    print('signature-check: conflicts=%d' % (1 if rc else 0))
    return rc


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--listing', action='store_true')
    ap.add_argument('--signature', action='store_true')
    a = ap.parse_args()
    rc = 0
    if a.listing:
        rc |= verify_listing(a.folder, a.binary)
    if a.signature:
        rc |= verify_signature(a.folder)
    return rc


if __name__ == '__main__':
    sys.exit(main())
