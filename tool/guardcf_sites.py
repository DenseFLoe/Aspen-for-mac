# -*- coding: utf-8 -*-
"""s17 step 1: register the 13 historical GuardCF dispatch sites in the main call table."""
import argparse, csv, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402

SLOT_RVA = 0x7670


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--sites', default='_t13/s17_s13-sites.csv')
    a = ap.parse_args()
    folder = Path(a.folder)
    data = open(a.binary, 'rb').read()
    pe = PE(data)
    rows = [r for r in csv.DictReader(open(a.sites, encoding='utf-8-sig')) if r['group'] == 'omitted-transfers']
    # verify the load-config slot
    lc = pe.directory(10)[0]
    p = pe.filepos(lc)
    slot_va = struct.unpack_from('<Q', data, p + 0x78)[0]
    slot_val = struct.unpack_from('<Q', data, pe.filepos(slot_va - pe.imagebase))[0]
    assert slot_va - pe.imagebase == SLOT_RVA, hex(slot_va - pe.imagebase)
    assert slot_val - pe.imagebase == 0x6050, hex(slot_val - pe.imagebase)

    asms = sorted(folder.glob('code/native*.asm'))
    addr2line = {}
    funcs = []
    for fn in asms:
        _, insns = parse_asm(str(fn))
        for (ln, addr, b, text, raw) in insns:
            addr2line[addr] = (fn.name, ln, b.hex(), text)
    for fn in asms:
        for line in open(fn, encoding='utf-8'):
            m = line.split() if line.startswith('; FUNC') else []
            if len(m) >= 3:
                lo = int(m[2].split('-')[0], 16); hi = int(m[2].split('-')[1], 16)
                funcs.append((lo, hi))
    def containing(rva):
        return next((lo for lo, hi in funcs if lo <= rva < hi), None)

    calls = list(csv.DictReader(open(folder / 'calls.csv', encoding='utf-8')))
    by_line = {}
    for r in calls:
        if '#L' in r['listing']:
            by_line.setdefault((r['listing'].split('#')[0], int(r['listing'].split('#L')[1].split('-')[0])), r)

    verified, changed, added = [], 0, 0
    for row in rows:
        rva = int(row['rva'], 16)
        raw = data[pe.filepos(rva):pe.filepos(rva) + len(row['original_bytes']) // 2].hex()
        same = raw == row['original_bytes'].lower()
        if rva == 0x6050:
            entry = addr2line[rva]
            calls.append(dict(kind='native', caller='0x6050',
                              callee='dynamic: GuardCFDispatchFunctionPointer slot 0x7670 -> 0x6050 (JMP RAX)',
                              **{'class': 'unresolved'},
                              listing='code/%s#L%d-L%d' % (entry[0], entry[1], entry[1]),
                              note='跳板本体（原件字节 ffe0 = jmp rax）；分派槽 0x7670 磁盘值 0x180006050；运行期目标未知，恢复条件＝断点取 rax'))
            added += 1
        else:
            ident = addr2line[rva]
            key = (ident[0], ident[1])
            r = by_line.get(key)
            if r is None:
                calls.append(dict(kind='native', caller='0x%X' % containing(rva),
                                  callee='dynamic via GuardCF slot 0x7670 -> 0x6050 JMP RAX',
                                  **{'class': 'unresolved'},
                                  listing='code/%s#L%d-L%d' % (ident[0], ident[1], ident[1]),
                                  note='历史 GuardCF 分派位置；原件 LoadConfig.GuardCFDispatchFunctionPointer=0x7670，磁盘值 0x180006050；静态分派路径已证，运行期目标未知'))
                added += 1
            else:
                r['class'] = 'unresolved'
                r['callee'] = 'dynamic via GuardCF slot 0x7670 -> 0x6050 JMP RAX'
                r['note'] = '历史 GuardCF 分派位置（原记 data，已按 s13-sites.csv 改判）；槽 0x7670 磁盘值 0x180006050；静态分派路径已证，运行期目标未知'
                changed += 1
        verified.append(dict(rva='0x%X' % rva, original_bytes=row['original_bytes'], file_bytes=raw,
                             match='yes' if same else 'no', route='slot 0x7670 -> 0x6050 JMP RAX',
                             note='trampoline' if rva == 0x6050 else 'dispatch site'))
    with open(folder / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(calls)
    with open(folder / 'code' / 'guardcf-sites.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['rva', 'original_bytes', 'file_bytes', 'match', 'route', 'note'])
        w.writeheader(); w.writerows(verified)
    print('verified %d (match %d); reclassified %d; added %d; calls now %d' % (
        len(verified), sum(1 for v in verified if v['match'] == 'yes'), changed, added, len(calls)))


if __name__ == '__main__':
    main()
