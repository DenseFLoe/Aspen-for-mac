# -*- coding: utf-8 -*-
"""s109 verifier: deployment metadata + interface-implementation edge + numeric RVA compare."""
import argparse, csv, json, os, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pe_reader import PE, parse_asm

SITES = {0x13DD: 5, 0x137F: 7}
NS = 'AspenTech.AspenPlus.WpfFindComponent'
IMPL_TYPE = 'FindComponentDriver'
IFACE_TYPE = 'IFindComponentDriver'
METHOD = 'ShowDialog'
SIG = '2001080E'
IMPL_RVA = 0xA848
IFACE_RVA = 0
REG = 's97-registration.json'
TABLE = 'code/s81-showdialog.csv'
DEPLOY_SHA = '04E68B8ECA60B732E661BF322D74B6F042ABEBA9EA801E2E2E410C1BE007B5D5'


def parse_attachment(path):
    doc = json.loads(Path(path).read_text(encoding='utf-8'))
    r64 = doc.get('Registry64', {})
    pe = doc.get('PE', {})
    types = {}
    for tname in (IMPL_TYPE, IFACE_TYPE):
        node = doc.get(tname)
        if not isinstance(node, dict):
            continue
        methods = [m for m in (node.get('methods') or []) if m.get('name') == METHOD]
        types[tname] = {
            'full': (node.get('namespace') or NS) + '.' + tname,
            'interfaces': node.get('interfaces') or [],
            'method': methods[0] if methods else None,
            'all_methods': node.get('methods') or [],
        }
    return doc, r64, pe, types


def verify_signature(folder):
    bad = 0
    reg = Path(folder) / REG
    if not reg.exists():
        print('CONFLICT file=%s object=%s field=attachment expected=present found=absent' % (REG, NS + '.' + IMPL_TYPE))
        print('signature-check: conflicts=1')
        return 3
    doc, r64, pe, types = parse_attachment(reg)

    # 1) deployment identity from the attachment
    got_sha = (pe.get('sha256') or '').upper()
    if got_sha != DEPLOY_SHA:
        print('CONFLICT file=%s object=%s field=deployment.sha256 expected=%s found=%s'
              % (REG, 'PE', DEPLOY_SHA, got_sha or '-'))
        bad += 1

    impl = types.get(IMPL_TYPE)
    iface = types.get(IFACE_TYPE)
    for role, node in (('interface', iface), ('implementation', impl)):
        if not node:
            print('CONFLICT file=%s object=%s.%s field=type expected=present found=absent' % (REG, NS, role, ))
            bad += 1
            continue
        m = node['method']
        if not m:
            print('CONFLICT file=%s object=%s field=method expected=%s found=absent' % (REG, node['full'], METHOD))
            bad += 1
            continue
        if m.get('signature') != SIG:
            print('CONFLICT file=%s object=%s field=signature expected=%s found=%s'
                  % (REG, node['full'], SIG, m.get('signature')))
            bad += 1

    # 2) interface-implementation edge
    edge_ok = impl and any(IFACE_TYPE in str(x) for x in impl['interfaces'])
    if not edge_ok:
        print('CONFLICT file=%s object=%s field=InterfaceImpl expected=%s found=%s'
              % (REG, impl['full'] if impl else NS + '.' + IMPL_TYPE, IFACE_TYPE, (impl or {}).get('interfaces', [])))
        bad += 1

    # 3) RVA: NUMERIC comparison, never substring (A848 vs A8480)
    if iface and iface['method']:
        raw_i = str(iface['method'].get('rva', ''))
        try:
            got_i = int(raw_i, 16)
        except ValueError:
            got_i = -1
        if got_i != IFACE_RVA:
            print('CONFLICT file=%s object=%s field=rva expected=0x%X found=0x%X (%s)'
                  % (REG, iface['full'], IFACE_RVA, got_i, raw_i))
            bad += 1
    if impl and impl['method']:
        raw = str(impl['method'].get('rva', ''))
        try:
            got = int(raw, 16)
        except ValueError:
            got = -1
        if got != IMPL_RVA:
            print('CONFLICT file=%s object=%s field=rva expected=0x%X found=0x%X (%s)'
                  % (REG, impl['full'], IMPL_RVA, got, raw))
            bad += 1

    # 4) delivery table must agree
    tbl = Path(folder) / TABLE
    if not tbl.exists():
        print('CONFLICT file=%s object=%s field=table expected=present found=absent' % (TABLE, NS + '.' + IMPL_TYPE))
        bad += 1
    else:
        rows = {r['item']: r for r in csv.DictReader(open(tbl, encoding='utf-8'))}
        for item in ('id-sig-impl', 'id-sig-interface'):
            got = rows.get(item, {}).get('instruction', '')
            if got != SIG:
                print('CONFLICT file=%s object=%s field=signature expected=%s found=%s'
                      % (TABLE, NS + '.' + IMPL_TYPE, SIG, got or '-'))
                bad += 1
        import re as _re
        note = rows.get('id-sig-impl', {}).get('meaning', '')
        m_rva = _re.search(r'rva\s+0x([0-9A-Fa-f]+)', note)
        got_rva = int(m_rva.group(1), 16) if m_rva else -1
        if got_rva != IMPL_RVA:
            print('CONFLICT file=%s object=%s field=rva expected=0x%X found=%s'
                  % (TABLE, NS + '.' + IMPL_TYPE, IMPL_RVA,
                     ('0x%X' % got_rva) if got_rva >= 0 else (note[:40] or '-')))
            bad += 1
    print('signature-check: conflicts=%d' % bad)
    return 3 if bad else 0


def verify_listing(folder, binary):
    data = Path(binary).read_bytes()
    pe = PE(data)
    listing = {addr: b.hex() for (ln, addr, b, t, r) in parse_asm(str(Path(folder) / 'code' / 'native.asm'))[1]}
    bad = 0
    for site, n in SITES.items():
        orig = data[pe.filepos(site):pe.filepos(site) + n].hex()
        got = listing.get(site)
        if got is None or got != orig:  # exact bytes for this instruction, not a prefix
            print('CONFLICT site=0x%X kind=listing-mismatch original=%s listing=%s' % (site, orig, got or '-'))
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
        rc |= verify_signature(a.folder)
    return rc


if __name__ == '__main__':
    sys.exit(main())
