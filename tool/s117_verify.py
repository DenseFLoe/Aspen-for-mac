# -*- coding: utf-8 -*-
"""s113 verifier: independent deployment identity + duplicate-key rejection + exact interface identity."""
import argparse, csv, json, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pe_reader import PE, parse_asm
from ident import same_ident

SITES = {0x13DD: 5, 0x137F: 7}
NS = 'AspenTech.AspenPlus.WpfFindComponent'
IMPL = 'FindComponentDriver'
IFACE = 'IFindComponentDriver'
METHOD = 'ShowDialog'
SIG = '2001080E'
IMPL_RVA = 0xA848
IFACE_RVA = 0x0
CLSID = '{09DC53C4-47A0-4AE0-9422-5675D014F182}'
PE_SHA = '04E68B8ECA60B732E661BF322D74B6F042ABEBA9EA801E2E2E410C1BE007B5D5'
REG = 's97-registration.json'
TABLE = 'code/s81-showdialog.csv'
CLASS = 'AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver'


class DuplicateKey(Exception):
    pass


def no_dupes(pairs):
    'object_pairs_hook: reject the same key twice with different values (never last-wins).'
    out = {}
    for k, v in pairs:
        if k in out and out[k] != v:
            raise DuplicateKey('duplicate key %r: %r vs %r' % (k, out[k], v))
        out[k] = v
    return out


def load_attachment(path):
    try:
        return json.loads(Path(path).read_text(encoding='utf-8'), object_pairs_hook=no_dupes), None
    except DuplicateKey as exc:
        return None, str(exc)


def _method(node):
    for m in (node.get('methods') or []):
        if m.get('name') == METHOD:
            return m
    return None


def _full(node, tname):
    return ((node.get('namespace') or '') + '.' + tname).strip('.')


def verify(folder):
    bad = 0
    reg = Path(folder) / REG
    if not reg.exists():
        print('CONFLICT file=%s object=%s field=attachment expected=present found=absent' % (REG, NS + '.' + IMPL))
        return 3
    doc, dup = load_attachment(reg)
    if dup:
        print('CONFLICT file=%s object=attachment field=duplicate_key expected=unique found=%s' % (REG, dup))
        return 3

    impl_node = doc.get(IMPL) or {}
    iface_node = doc.get(IFACE) or {}

    # 1) registry identity
    got_clsid = str((doc.get('Registry64') or {}).get('CLSID', ''))
    if got_clsid.upper() != CLSID.upper():
        print('CONFLICT file=%s object=Registry64 field=CLSID expected=%s found=%s' % (REG, CLSID, got_clsid or '-'))
        bad += 1

    # 1b) registry class must match the CLSID's class identity
    got_class = str((doc.get('Registry64') or {}).get('class', ''))
    if got_class != CLASS:
        print('CONFLICT file=%s object=Registry64 field=class expected=%s found=%s' % (REG, CLASS, got_class or '-'))
        bad += 1

    # 2) deployment PE identity
    got_sha = str((doc.get('PE') or {}).get('sha256', '')).upper()
    if got_sha != PE_SHA:
        print('CONFLICT file=%s object=PE field=sha256 expected=%s found=%s' % (REG, PE_SHA, got_sha or '-'))
        bad += 1

    # 3) full type identity (namespace must be exact, not a prefix)
    for tname, node in ((IMPL, impl_node), (IFACE, iface_node)):
        if not node:
            print('CONFLICT file=%s object=%s.%s field=type expected=present found=absent' % (REG, NS, tname))
            bad += 1
            continue
        full = _full(node, tname)
        if full != NS + '.' + tname:
            print('CONFLICT file=%s object=%s field=namespace expected=%s found=%s' % (REG, full, NS, node.get('namespace')))
            bad += 1

    # 4) interface-implementation edge: exact full identity of each listed interface
    edges = [str(x) for x in (impl_node.get('interfaces') or [])]
    want_edge = IFACE
    # .NET type names are case-sensitive: a bare lowercase name is a different type
    edge_ok = any(e.split('.')[-1] == want_edge and ('.' not in e or e == NS + '.' + want_edge)
                  for e in edges)
    if not edge_ok:
        print('CONFLICT file=%s object=%s field=InterfaceImpl expected=%s found=%s'
              % (REG, NS + '.' + IMPL, want_edge, edges))
        bad += 1

    # 5) method signatures and numeric RVAs
    for tname, node, want_rva in ((IFACE, iface_node, IFACE_RVA), (IMPL, impl_node, IMPL_RVA)):
        m = _method(node) if node else None
        if not m:
            print('CONFLICT file=%s object=%s field=method expected=%s found=absent' % (REG, NS + '.' + tname, METHOD))
            bad += 1
            continue
        if m.get('signature') != SIG:
            print('CONFLICT file=%s object=%s field=signature expected=%s found=%s'
                  % (REG, NS + '.' + tname + '.' + METHOD, SIG, m.get('signature')))
            bad += 1
        try:
            got_rva = int(str(m.get('rva', '')), 16)
        except ValueError:
            got_rva = -1
        if got_rva != want_rva:
            print('CONFLICT file=%s object=%s field=rva expected=0x%X found=0x%X'
                  % (REG, NS + '.' + tname + '.' + METHOD, want_rva, got_rva))
            bad += 1

    # 6) delivery table agrees
    tbl = Path(folder) / TABLE
    if not tbl.exists():
        print('CONFLICT file=%s object=%s field=table expected=present found=absent' % (TABLE, NS + '.' + IMPL))
        bad += 1
    else:
        rows = {}
        for r in csv.DictReader(open(tbl, encoding='utf-8')):
            k = r['item']
            if k in rows and rows[k] != r:
                print('CONFLICT file=%s object=%s field=duplicate_row expected=unique found=duplicate row %r' % (TABLE, k, k))
                bad += 1
                continue
            rows.setdefault(k, r)
        for item in ('id-sig-impl', 'id-sig-interface'):
            got = rows.get(item, {}).get('instruction', '')
            if got != SIG:
                print('CONFLICT file=%s object=%s field=signature expected=%s found=%s'
                      % (TABLE, NS + '.' + IMPL, SIG, got or '-'))
                bad += 1
        import re
        note = rows.get('id-sig-impl', {}).get('meaning', '')
        m_rva = re.search(r'rva\s+0x([0-9A-Fa-f]+)', note)
        got_rva = int(m_rva.group(1), 16) if m_rva else -1
        if got_rva != IMPL_RVA:
            print('CONFLICT file=%s object=%s field=rva expected=0x%X found=%s'
                  % (TABLE, NS + '.' + IMPL, IMPL_RVA, '0x%X' % got_rva if got_rva >= 0 else '-'))
            bad += 1
    print('signature-check: conflicts=%d' % bad)
    return 3 if bad else 0


def verify_listing(folder, binary):
    data = Path(binary).read_bytes()
    pe = PE(data)
    listing = {a: b.hex() for (ln, a, b, t, r) in parse_asm(str(Path(folder) / 'code' / 'native.asm'))[1]}
    bad = 0
    for site, n in SITES.items():
        orig = data[pe.filepos(site):pe.filepos(site) + n].hex()
        if listing.get(site) != orig:
            print('CONFLICT site=0x%X kind=listing-mismatch original=%s listing=%s' % (site, orig, listing.get(site) or '-'))
            bad += 1
    print('listing-check: sites=%d conflicts=%d' % (len(SITES), bad))
    return 3 if bad else 0


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
        rc |= verify(a.folder)
    return rc


if __name__ == '__main__':
    sys.exit(main())
