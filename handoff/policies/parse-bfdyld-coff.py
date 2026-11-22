#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""parse-bfdyld-coff.py -- 独立解析 COFF 目标文件的文件头/节表/符号表。

用途：证明 nonPE 件里存在可执行代码，不能因 PE 解析失败写 functions=N/A。

示例（BFDYLD.obj，Git blob eda5f8fe191dcdecc59d2bc0961cf882ad8b1318）:
  python -B parse-bfdyld-coff.py --obj BFDYLD.obj
期望: size=5629 sha256=194e88b4...703ec0
      machine=0x8664 nsec=7 nsyms=51 optsz=0
      .text rawsize=1792 nreloc=59
      BFDYLD section=1 value=0 type=0x20 storageclass=2
"""
import argparse
import hashlib
import struct
import sys


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--obj', required=True)
    a = ap.parse_args()
    d = open(a.obj, 'rb').read()
    print('size=%d sha256=%s' % (len(d), hashlib.sha256(d).hexdigest()))
    if d[:2] == b'MZ':
        print('has DOS header (this is a PE, not a bare COFF object)')
    mach, nsec, tstamp, symoff, nsyms, optsz, chars = struct.unpack_from('<HHIIIHH', d, 0)
    print('machine=0x%04x nsec=%d nsyms=%d optsz=%d characteristics=0x%04x'
          % (mach, nsec, nsyms, optsz, chars))
    off = 20 + optsz
    secs = []
    for i in range(nsec):
        name = d[off:off + 8].rstrip(b'\0').decode('latin1')
        vsz, va, rsz, rp, relp, lnp, nrel, nln, sc = struct.unpack_from('<IIIIIIHHI', d, off + 8)
        print('sec%d %-8s vsize=%d rawsize=%d rawptr=%d nreloc=%d flags=0x%08x'
              % (i + 1, name, vsz, rsz, rp, nrel, sc))
        secs.append((name, rsz))
        off += 40
    for i in range(nsyms):
        o = symoff + 18 * i
        name = d[o:o + 8].rstrip(b'\0')
        val = struct.unpack_from('<I', d, o + 8)[0]
        sec = struct.unpack_from('<h', d, o + 12)[0]
        typ = struct.unpack_from('<H', d, o + 14)[0]
        sclass = struct.unpack_from('<b', d, o + 16)[0]
        if b'BFDYLD' == name or (sec > 0 and val == 0 and typ == 0x20 and sclass == 2):
            print('symbol %r section=%d value=%d type=0x%02x storageclass=%d'
                  % (name, sec, val, typ, sclass))
    return 0


if __name__ == '__main__':
    sys.exit(main())
