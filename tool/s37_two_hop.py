# -*- coding: utf-8 -*-
"""Generate the two-hop table independently from the original binary and the candidate listing.

Derivation (nothing inherited from a previous table):
  1. site bytes in the ORIGINAL binary       -> first hop RVA
  2. first-hop body (FF 25 [rip+disp])       -> IAT slot
  3. IAT slot in the original import table   -> DLL!symbol
  4. original .pdata exception directory     -> original host (fragment begin)
  5. candidate listing FUNC ranges           -> candidate owner (fragment begin)
  6. (owner, listing line) in calls.csv      -> main-table row number

Sites are discovered by scanning the candidate listing for E8/E9 whose target body is a
FF25 thunk, so a row deleted from an old table is recovered independently.
"""
import argparse, csv, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402


def pdata_hosts(data, pe):
    out = []
    uw, usz = pe.directory(3)
    if not uw:
        return out
    p = pe.filepos(uw)
    for off in range(p, p + usz, 12):
        b, e = struct.unpack_from('<II', data, off)
        out.append((b, e))
    return out


def thunk_slot(data, pe, rva):
    try:
        p = pe.filepos(rva)
    except ValueError:
        return None
    b = data[p:p + 8]
    o = 1 if b and 0x40 <= b[0] <= 0x4F else 0
    if len(b) >= o + 6 and b[o] == 0xFF and (b[o + 1] & 0xC7) == 0x05:
        disp = struct.unpack_from('<i', b, o + 2)[0]
        return rva + o + 6 + disp
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--out', default='', help='output csv (default: <folder>/code/s37-two-hop.csv)')
    a = ap.parse_args()
    folder = Path(a.folder)
    data = open(a.binary, 'rb').read()
    pe = PE(data)
    iat = pe.iat()
    hosts = pdata_hosts(data, pe)

    def host_of(rva):
        return next((b for b, e in hosts if b <= rva < e), 0)

    asms = sorted((folder / 'code').rglob('native*.asm'))
    owners, addr2line = [], {}
    for fn in asms:
        for ln in open(fn, encoding='utf-8'):
            m = ln.split() if ln.startswith('; FUNC') else []
            if len(m) >= 3:
                lo, hi = m[2].split('-')
                owners.append((int(lo, 16), int(hi, 16)))
        _, insns = parse_asm(str(fn))
        rel = fn.relative_to(folder).as_posix()
        for (ln, addr, b, text, raw) in insns:
            addr2line[addr] = (rel, ln)

    def owner_of(rva):
        # most specific (innermost) fragment wins when listing ranges overlap
        hits = [lo for lo, hi in owners if lo <= rva < hi]
        return max(hits) if hits else 0

    calls = list(csv.DictReader(open(folder / 'calls.csv', encoding='utf-8')))
    # main-table row is located by (listing file, line); a bare line number is NOT a
    # unique key once the listing is split across native*.asm files.
    row_by_key = {}
    for idx, r in enumerate(calls, start=2):
        ref = r['listing']
        if '#L' not in ref:
            continue
        fpart, lpart = ref.split('#L', 1)
        line = int(lpart.split('-')[0])
        row_by_key.setdefault((fpart, line), []).append(idx)

    def row_for(fname, line, symbol):
        cands = row_by_key.get((fname, line), [])
        if len(cands) == 1:
            return cands[0]
        # ambiguous line: disambiguate with the main-table callee/note, else report none
        hits = [i for i in cands
                if symbol and (calls[i - 2].get('callee', '').strip().lower() == symbol.strip().lower())]
        if len(hits) == 1:
            return hits[0]
        return None

    sites = []
    for addr in sorted(addr2line):
        try:
            p = pe.filepos(addr)
        except ValueError:
            continue
        raw = data[p:p + 5]
        if len(raw) < 5 or raw[0] not in (0xE8, 0xE9):
            continue
        disp = struct.unpack_from('<i', raw, 1)[0]
        hop = addr + 5 + disp
        slot = thunk_slot(data, pe, hop)
        if slot in iat:
            sites.append((addr, hop, slot))

    out = []
    ambiguous = 0
    missing = 0
    for site, hop, slot in sites:
        lib, nm = iat[slot]
        asm = addr2line.get(site)
        owner = '0x%X' % owner_of(site)
        row = row_for(asm[0], asm[1], '%s!%s' % (lib, nm)) if asm else None
        if asm and row is None:
            ambiguous += 1
        if not asm:
            missing += 1
        out.append(dict(site='0x%X' % site,
                        first_hop='0x%X' % hop,
                        iat_slot='0x%X' % slot,
                        import_symbol='%s!%s' % (lib, nm),
                        main_class=calls[row - 2]['class'] if row else '',
                        original_host='0x%X' % host_of(site),
                        candidate_owner=owner,
                        asm='%s#L%d' % (asm[0], asm[1]) if asm else '',
                        calls_row=row or ''))
    out_path = Path(a.out) if a.out else (folder / 'code' / 's37-two-hop.csv')
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['site', 'first_hop', 'iat_slot', 'import_symbol', 'main_class',
                                           'original_host', 'candidate_owner', 'asm', 'calls_row'])
        w.writeheader(); w.writerows(out)
    print('rows %d; discovered_from_listing=%d; ambiguous_calls_row=%d; missing_listing_ref=%d'
          % (len(out), len(sites), ambiguous, missing))


if __name__ == '__main__':
    main()
