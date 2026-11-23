
# -*- coding: utf-8 -*-
"""CLI metadata reader: TypeDef (with FieldList/MethodList) and MethodDef."""
import struct

def _cs(data, start):
    return data[start:data.index(b"\0", start)].decode("utf-8")

def parse(data, off):
    assert data[off:off+4] == b"BSJB"
    pos = off + 16 + int.from_bytes(data[off+12:off+16], "little")
    nstreams = int.from_bytes(data[pos+2:pos+4], "little")
    pos += 4
    streams = {}
    for _ in range(nstreams):
        rel, size = struct.unpack_from("<II", data, pos)
        name = _cs(data, pos + 8)
        streams[name] = (off + rel, size)
        pos += 8 + ((len(name) + 4) // 4) * 4
    tstart, _ = streams["#~"]
    sstart, _ = streams["#Strings"]
    heaps = data[tstart+6]
    s = 4 if heaps & 1 else 2
    g = 4 if heaps & 2 else 2
    b = 4 if heaps & 4 else 2
    valid = int.from_bytes(data[tstart+8:tstart+16], "little")
    counts = [0]*64
    p = tstart + 24
    for i in range(64):
        if valid & (1 << i):
            counts[i] = int.from_bytes(data[p:p+4], "little"); p += 4
    def idx(i):
        return 4 if counts[i] >= 65536 else 2
    def coded(bits, tables):
        return 4 if max(counts[i] for i in tables) >= (1 << (16 - bits)) else 2
    sizes = [2 + s + g*3, coded(2, [0,26,35,1]) + s*2,
             4 + s*2 + coded(2, [2,1,27]) + idx(4) + idx(6),
             idx(4), 2 + s + b, idx(6), 8 + s + b + idx(8)]
    starts = []
    for i, size in enumerate(sizes):
        starts.append(p); p += counts[i]*size
    def rows(i):
        for k in range(counts[i]):
            yield starts[i] + k*sizes[i]
    types = []
    method_first = 1
    for k, pos in enumerate(rows(2)):
        name = _cs(data, sstart + int.from_bytes(data[pos+4:pos+4+s], "little"))
        ns = _cs(data, sstart + int.from_bytes(data[pos+4+s:pos+4+2*s], "little"))
        q = pos + 4 + 2*s + sizes[2] - 4 - idx(4) - idx(6)  # not used
        # field/method list offsets: after flags,name,namespace,extends
        base = pos + 4 + 2*s + coded(2, [2,1,27])
        field_list = int.from_bytes(data[base:base+idx(4)], "little")
        method_list = int.from_bytes(data[base+idx(4):base+idx(4)+idx(6)], "little")
        types.append(dict(token=0x02000001+k, name=(ns+"." if ns else "")+name,
                          method_start=method_list))
    # compute method ranges
    for i, t in enumerate(types):
        t["method_end"] = types[i+1]["method_start"] if i+1 < len(types) else counts[6]+1
    methods = []
    for k, pos in enumerate(rows(6)):
        rva = int.from_bytes(data[pos:pos+4], "little")
        impl_flags = int.from_bytes(data[pos+4:pos+6], "little")   # ImplFlags (2 bytes)
        flags = int.from_bytes(data[pos+6:pos+8], "little")        # Flags (2 bytes)
        name = _cs(data, sstart + int.from_bytes(data[pos+8:pos+8+s], "little"))
        methods.append(dict(token=0x06000001+k, rva=rva, flags=flags, impl_flags=impl_flags,
                            flavor=("IL","native","OPTIL","runtime")[impl_flags & 3], name=name,
                            signature=int.from_bytes(data[pos+10:pos+10+2], "little")))
    return dict(types=types, methods=methods)
