import re

import struct, sys, json, csv

class PE:
    def __init__(self, data):
        self.data = data
        pe = struct.unpack_from("<I", data, 60)[0]
        opt = pe + 24
        self.magic = struct.unpack_from("<H", data, opt)[0]
        self.imagebase = struct.unpack_from("<Q", data, opt + 24)[0]
        self.nsec = struct.unpack_from("<H", data, pe + 6)[0]
        start = opt + struct.unpack_from("<H", data, pe + 20)[0]
        self.secs = []
        for i in range(self.nsec):
            pos = start + 40 * i
            vsize = struct.unpack_from("<I", data, pos + 8)[0]
            rva, size, raw = struct.unpack_from("<III", data, pos + 12)
            flags = struct.unpack_from("<I", data, pos + 36)[0]
            self.secs.append(dict(rva=rva, size=size, raw=raw, vsize=vsize,
                                  exec=bool(flags & 0x20000000),
                                  name=data[pos:pos+8].rstrip(b"\0").decode("latin-1")))
        self.opt = opt
    def directory(self, i):
        return struct.unpack_from("<II", self.data, self.opt + 112 + i*8)
    def filepos(self, rva):
        for s in self.secs:
            if s["rva"] <= rva < s["rva"] + s["size"]:
                return s["raw"] + rva - s["rva"]
        raise ValueError("RVA %#x outside" % rva)
    def indir(self, rva):
        return rva <= 0x7fffffff and self.in_code(rva)
    def in_code(self, rva):
        for s in self.secs:
            if s["exec"] and s["rva"] <= rva < s["rva"] + s["size"]:
                return True
        return False
    def iat(self):
        """slot rva -> (library, name_or_ordinal)"""
        out = {}
        rva, size = self.directory(1)
        if not rva: return out
        pos = self.filepos(rva)
        d = self.data
        while True:
            oft, ts, fc, name_rva, ft = struct.unpack_from("<IIIII", d, pos)
            if not name_rva: break
            lib = d[self.filepos(name_rva):d.index(b"\0", self.filepos(name_rva))].decode("latin-1")
            j = 0
            thunk_base = self.filepos(oft) if oft else None
            while True:
                if thunk_base is not None:
                    t = struct.unpack_from("<Q", d, thunk_base + j*8)[0]
                    if not t: break
                    if t & 0x8000000000000000:
                        nm = "#%d" % (t & 0xffff)
                    else:
                        srva = t & 0x7fffffffffffffff
                        p = self.filepos(srva) + 2
                        nm = d[p:d.index(b"\0", p)].decode("latin-1")
                else:
                    # fall back to IAT contents (bound imports): skip
                    break
                out[ft + j*8] = (lib, nm)
                j += 1
            pos += 20
        return out
    def cstr(self, rva, limit=120):
        p = self.filepos(rva)
        e = self.data.index(b"\0", p)
        b = self.data[p:e]
        if len(b) < 2 or len(b) > limit: return None
        try:
            s = b.decode("utf-8")
        except UnicodeDecodeError:
            try: s = b.decode("latin-1")
            except Exception: return None
        if not all(31 < ord(c) < 127 for c in s): return None
        return s

def parse_asm(path):
    lines = open(path, encoding="utf-8-sig").read().splitlines()
    out = []
    for i, ln in enumerate(lines):
        if not ln or ln.startswith(";") or ln[0] not in "0123456789abcdefABCDEF":
            continue
        m = re.match(r"^([0-9A-Fa-f]{8})  ((?:[0-9A-Fa-f]{2} ?)+?)  +(.*)$", ln)
        if not m: continue
        addr = int(m.group(1), 16)
        by = m.group(2).replace(" ", "")
        out.append((i+1, addr, bytes.fromhex(by), m.group(3), ln))
    return lines, out

def scan(path, dll):
    pe = PE(open(dll, "rb").read())
    iat = pe.iat()
    lines, insns = parse_asm(path)
    hits = []
    datarefs = []
    indirect = []
    for (ln, addr, b, text, raw) in insns:
        # FF /2 call or /4 jmp with RIP-relative modrm (mod=00 rm=101): FF 15 / FF 25, optional REX prefix
        off = 0
        b0 = b
        if len(b) >= 3 and b[0] in (0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f):
            off = 1
        if len(b) >= off+6 and b[off] == 0xFF and (b[off+1] & 0xC7) == 0x05:
            disp = struct.unpack_from("<i", b, off+2)[0]
            tgt = addr + len(b) + disp
            if tgt in iat:
                lib, nm = iat[tgt]
                hits.append(dict(line=ln, at=addr, slot=tgt, lib=lib, name=nm, op=b[off+1] >> 3))
                continue
            # RIP-relative memory operand to non-IAT data
            s = None
            if not pe.in_code(tgt):
                try: s = pe.cstr(tgt)
                except ValueError: s = None
            datarefs.append(dict(line=ln, at=addr, target=tgt, name=(nm if False else None), string=s, text=text))
        # FF /2 with modrm mod!=00 (register+disp indirect call)
        if len(b) >= off+2 and b[off] == 0xFF and (b[off+1] & 0xC0) != 0xC0 and b[off+1] & 0xC7 != 0x05:
            indirect.append(dict(line=ln, at=addr, text=text, bytes=b.hex()))
        # register-indirect call: FF D0..D7
        if len(b) >= off+2 and b[off] == 0xFF and (b[off+1] & 0xF8) == 0xD0:
            indirect.append(dict(line=ln, at=addr, text=text, bytes=b.hex()))
    return dict(iat=iat, hits=hits, datarefs=datarefs, indirect=indirect, lines=lines)

if __name__ == "__main__":
    r = scan(sys.argv[1], sys.argv[2])
    print("iat slots", len(r["iat"]), "iat hits", len(r["hits"]), "unique", len({h["at"] for h in r["hits"]}))
    print("datarefs", len(r["datarefs"]), "strings", sum(1 for d in r["datarefs"] if d["string"]))
    print("indirect", len(r["indirect"]))
    json.dump(r["hits"], open(sys.argv[3], "w"), indent=0)
