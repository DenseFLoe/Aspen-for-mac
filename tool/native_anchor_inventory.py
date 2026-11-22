# -*- coding: utf-8 -*-
"""Enumerate original PE anchors: .pdata BeginAddress + entry point + executable exports."""
import argparse, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE  # noqa: E402


def anchors(data, pe):
    out = set()
    pe_off = struct.unpack_from('<I', data, 60)[0]
    out.add(struct.unpack_from('<I', data, pe_off + 24 + 16)[0])
    uw, usz = pe.directory(3)
    p = pe.filepos(uw)
    for off in range(p, p + usz, 12):
        out.add(struct.unpack_from('<I', data, off)[0])
    exp, _ = pe.directory(0)
    if exp:
        q = pe.filepos(exp)
        ordinal, n, names, fn, strings, ords = struct.unpack_from('<IIIIII', data, q + 16)
        for i in range(n):
            t = struct.unpack_from('<I', data, pe.filepos(fn) + 4 * i)[0]
            if pe.in_code(t):
                out.add(t)
    return sorted(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--binary', required=True)
    ap.add_argument('--json', default='')
    a = ap.parse_args()
    data = Path(a.binary).read_bytes()
    got = anchors(data, PE(data))
    print('anchors=%d first=0x%X last=0x%X' % (len(got), got[0], got[-1]))
    if a.json:
        Path(a.json).write_text(json.dumps(got), encoding='utf-8')


if __name__ == '__main__':
    main()
