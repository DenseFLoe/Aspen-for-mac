#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""parse-native340-methoddefs.py -- 独立解析混合程序集的 MethodDef 实现标志。

用途：证明「有 CLI 元数据不等于纯托管」。对给定 PE 读取 CLR 头与 #~ 元数据流，
按 MethodDef 表逐行输出 RVA 与 ImplFlags，并按 CodeType 分类：
  CodeType=0 (IL) / 1 (Native) / 2 (OPTIL) / 3 (Runtime)；RVA=0 记为无体声明。

示例（NATIVE-340）:
  python -B parse-native340-methoddefs.py --dll WrapSaveMergeNNFiles.dll
期望: size=107048 sha256=869c4b23...804fec TypeDef=563 MethodDef=188
      il=167 native=19 rva0=2   (188=167+19+2)
"""
import argparse
import collections
import hashlib
import struct
import sys


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--dll', required=True)
    a = ap.parse_args()
    d = open(a.dll, 'rb').read()
    print('size=%d sha256=%s' % (len(d), hashlib.sha256(d).hexdigest()))

    pe = struct.unpack_from('<I', d, 0x3c)[0]
    if d[pe:pe + 4] != b'PE\0\0':
        print('not PE'); return 1
    nsec = struct.unpack_from('<H', d, pe + 6)[0]
    optsz = struct.unpack_from('<H', d, pe + 20)[0]
    opt = pe + 24
    magic = struct.unpack_from('<H', d, opt)[0]
    ddoff = opt + (112 if magic == 0x20b else 96)
    clr_rva = struct.unpack_from('<I', d, ddoff + 8 * 14)[0]
    secs = []
    for i in range(nsec):
        o = opt + optsz + 40 * i
        vs, va, rs, rp = struct.unpack_from('<IIII', d, o + 8)
        secs.append((va, max(vs, rs), rp))

    def r2o(rva):
        for va, vsz, rp in secs:
            if va <= rva < va + vsz:
                return rp + (rva - va)
        return None

    co = r2o(clr_rva)
    if co is None:
        print('no CLR data directory (dir14 rva=0x%x)' % clr_rva); return 1
    md_rva, md_sz = struct.unpack_from('<II', d, co + 8)
    mo = r2o(md_rva)
    print('clr_dir_rva=0x%x metadata_rva=0x%x metadata_size=%d' % (clr_rva, md_rva, md_sz))
    if d[mo:mo + 4] != b'BSJB':
        print('bad metadata root'); return 1
    vlen = struct.unpack_from('<I', d, mo + 12)[0]
    p = mo + 16 + vlen + 2
    nstreams = struct.unpack_from('<H', d, p)[0]
    p += 2
    streams = {}
    for _ in range(nstreams):
        off, sz = struct.unpack_from('<II', d, p)
        p += 8
        e = d.index(b'\0', p)
        streams[d[p:e].decode()] = (mo + off, sz)
        p = (e + 1 + 3) // 4 * 4

    tbl = streams['#~'][0]
    valid = struct.unpack_from('<Q', d, tbl + 8)[0]
    rows = []
    p = tbl + 24
    for i in range(64):
        if valid >> i & 1:
            rows.append(struct.unpack_from('<I', d, p)[0]); p += 4
        else:
            rows.append(0)
    strsz = streams['#Strings'][1]
    S = 2 if strsz < 65536 else 4
    hs = lambda n: 2 if n < 65536 else 4

    def ridx(bits, tabs):
        mx = max(rows[t] for t in tabs)
        return 2 if mx < (1 << (16 - bits)) else 4

    TypeDefOrRef = ridx(2, [2, 1, 27])
    sizes = {
        0: 2 + S + 3 * 2,
        1: ridx(2, [0, 1, 26, 35, 38]) + 2 * S,
        2: 4 + 2 * S + TypeDefOrRef + hs(rows[4]) + hs(rows[6]),
        3: hs(rows[4]), 4: 2 + S + 2, 5: hs(rows[6]),
    }
    off = tbl + 24 + 4 * sum(1 for i in range(64) if valid >> i & 1)
    for i in range(6):
        off += rows[i] * sizes[i]
    cnt = collections.Counter()
    for r in range(rows[6]):
        rva, implf, flags, name, sig, pl = struct.unpack_from('<IHHHHH', d, off + r * 14)
        ct = implf & 0x3
        cnt[(ct, rva == 0)] += 1
    print('TypeDef=%d MethodDef=%d' % (rows[2], rows[6]))
    print('ImplFlags by (CodeType, RVA==0): %s' % dict(sorted(cnt.items())))
    print('il=%d native=%d rva0=%d total=%d'
          % (cnt.get((0, False), 0) + cnt.get((2, False), 0),
             cnt.get((1, False), 0),
             sum(v for (ct, z), v in cnt.items() if z),
             rows[6]))
    return 0


if __name__ == '__main__':
    sys.exit(main())
