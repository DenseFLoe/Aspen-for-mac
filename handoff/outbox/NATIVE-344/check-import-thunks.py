"""Recheck the s1 import-thunk subset and resource index of the pinned Simdll.dll."""
import argparse
import collections
import csv
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import tempfile


DIGEST = "9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601"
INPUT_BLOBS = {
    "coverage.csv": "cb82b9aaff730b71a19f04194bc994cb47a4c339",
    "ghidra/functions.tsv": "aa6ab894a47baa7b1e631ffbd9be1701b8976523",
    "resources.csv": "05cea2c0de596cb4b318707c94e66438af13afb5",
    "references.csv": "ade11dcdc466aed468bc65183ca10ac215e6c601",
}


def rows(path, separator=","):
    with path.open(encoding="utf-8-sig", newline="") as file:
        return list(csv.DictReader(file, delimiter=separator))


def uint(data, pos, width):
    value = data[pos:pos + width]
    assert len(value) == width
    return int.from_bytes(value, "little")


class Image:
    def __init__(self, path):
        self.data = path.read_bytes()
        assert hashlib.sha256(self.data).hexdigest() == DIGEST
        pe = uint(self.data, 60, 4)
        assert self.data[pe:pe + 4] == b"PE\0\0" and uint(self.data, pe+4, 2) == 0x8664
        opt = pe + 24
        assert uint(self.data, opt, 2) == 0x20b
        self.directories = opt + 112
        table = opt + uint(self.data, pe + 20, 2)
        self.sections = []
        for n in range(uint(self.data, pe + 6, 2)):
            hdr = table + n * 40
            rva, size, raw = struct.unpack_from("<III", self.data, hdr + 12)
            self.sections.append((rva, size, raw))

    def read(self, at, size):
        for rva, length, raw in self.sections:
            if rva <= at and at+size <= rva+length:
                offset = raw + at - rva
                result = self.data[offset:offset+size]
                assert len(result) == size
                return result
        raise ValueError(f"Unmapped RVA {at:#x} ({size} bytes)")

    def string(self, at):
        buf = bytearray()
        while self.read(at + len(buf), 1) != b"\0":
            buf.extend(self.read(at + len(buf), 1))
        return buf.decode("ascii")

    def directory(self, index):
        return struct.unpack_from("<II", self.data, self.directories + index*8)

    def imports(self):
        iat = {}
        start, size = self.directory(1)
        for at in range(start, start+size, 20):
            names, _, _, dll_at, slots = struct.unpack("<IIIII", self.read(at, 20))
            if not any((names,dll_at,slots)):
                break
            dll = self.string(dll_at)
            index = 0
            while True:
                item = int.from_bytes(self.read((names or slots)+index*8, 8), "little")
                if not item:
                    break
                slot = slots+index*8
                symbol = f"#{item & 0xffff}" if item >> 63 else self.string(item+2)
                assert slot not in iat
                iat[slot] = dll, symbol
                index += 1
        return iat

    def resources(self):
        start, size = self.directory(2)
        result = {}
        def relative(at, length):
            assert 0 <= at <= at+length <= size
            return self.read(start+at, length)
        def walk(at, key):
            named, numbered = struct.unpack("<HH", relative(at+12, 4))
            for i in range(named+numbered):
                name, dest = struct.unpack("<II", relative(at+16+i*8, 8))
                if name >> 31:
                    off = name & 0x7fffffff
                    n = int.from_bytes(relative(off, 2),"little")
                    ident = relative(off+2, 2*n).decode("utf-16-le")
                else:
                    ident = str(name)
                path = (*key, ident)
                if dest >> 31:
                    assert len(path) < 3
                    walk(dest & 0x7fffffff, path)
                else:
                    assert len(path) == 3 and path not in result
                    rva,n,cp,reserved = struct.unpack("<IIII", relative(dest, 16))
                    assert reserved == 0
                    result[path] = (rva, n, cp, hashlib.sha256(self.read(rva,n)).hexdigest())
        walk(0, ())
        return result


def reassemble(zig, entries):
    # External symbol names explicitly identify IAT-slot RVAs. No target
    # function needs to be loaded to verify this individual tail transfer.
    source = [".text"]
    for rva, _, slot, *_ in entries:
        source.extend([f"entry_{rva:x}:", f"  jmpq *slot_{slot:x}(%rip)"])
    with tempfile.TemporaryDirectory() as scratch:
        tmp = Path(scratch)
        asm = tmp / "imports.s"
        obj = tmp / "imports.obj"
        asm.write_text("\n".join(source)+"\n", encoding="ascii")
        subprocess.run([str(zig), "cc", "-target", "x86_64-windows-gnu",
                        "-c", str(asm), "-o", str(obj)], check=True)
        coff = obj.read_bytes()
    arch, nsects, _, symbols, nsymbols, opt, _ = struct.unpack_from("<HHIIIHH", coff)
    assert arch == 0x8664
    strings = symbols + 18*nsymbols
    for i in range(nsects):
        hdr = 20 + opt + i*40
        if coff[hdr:hdr+8].rstrip(b"\0") == b".text":
            break
    else:
        raise ValueError("COFF lacks .text")
    code_size, data_at, reloc_at = struct.unpack_from("<III", coff, hdr+16)
    nreloc = uint(coff, hdr+32, 2)
    assert code_size == 6*len(entries) and nreloc == len(entries)
    code = coff[data_at:data_at+code_size]
    relocation_slots = {}
    for i in range(nreloc):
        off, index, kind = struct.unpack_from("<IIH", coff, reloc_at+i*10)
        assert kind == 4 and off % 6 == 2 and off not in relocation_slots
        sym = coff[symbols+18*index:symbols+18*index+8]
        if sym[:4] == bytes(4):
            pos = strings + uint(sym,4,4)
            sym = coff[pos:coff.index(b"\0",pos)]
        name = sym.rstrip(b"\0").decode("ascii")
        assert name.startswith("slot_")
        relocation_slots[off] = int(name[5:], 16)
    for i,(rva, original, slot,*_) in enumerate(entries):
        off = 6*i+2
        assert relocation_slots[off] == slot and code[off:off+4] == bytes(4)
        rebuilt = code[off-2:off] + struct.pack("<i",slot-(rva+6))
        assert rebuilt == original
    return {"tool": "Zig "+subprocess.check_output([zig,"version"], text=True).strip(),
            "target":"x86_64-windows-gnu","coff_rel32":nreloc,"bytes_equal":code_size}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("s1", type=Path, help="NATIVE-344 s1 inbox at f1ed6217")
    parser.add_argument("zig", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    image = Image(args.original)
    for file, blob in INPUT_BLOBS.items():
        data = (args.s1 / file).read_bytes()
        header = f"blob {len(data)}\0".encode()
        assert hashlib.sha1(header + data).hexdigest() == blob, file
    coverage = {int(r["key"], 0):r for r in rows(args.s1/"coverage.csv")}
    thunks = rows(args.s1/"ghidra/functions.tsv", "\t")
    imports = image.imports()
    references = {}
    all_reference_sites = set()
    for row in rows(args.s1/"references.csv"):
        for pair in row["owner_rva:instruction_rva_hex"].split():
            owner, site = (int(t,16) for t in pair.split(":"))
            all_reference_sites.add(site)
            if owner == site and row["kind"] == "iat":
                assert site not in references
                references[site] = row["target"]
    entries = []
    for func in thunks:
        site = int(func["rva"], 0)
        data = image.read(site, 6)
        if data[:2] != bytes.fromhex("ff25"):
            continue
        slot = site + 6 + struct.unpack("<i", data[2:])[0]
        if slot not in imports:
            continue
        assert func["state"] == "thunk"
        assert func["ranges_inclusive"] == f"{site:#x}-{site+5:#x}" and int(func["bytes"]) == 6
        assert coverage[site]["state"] == "gap"
        assert coverage[site]["first_bytes"] == image.read(site,8).hex()
        dll, symbol = imports[slot]
        if site in references:
            assert references[site] == f"{dll}!{symbol}"
        entries.append((site, data, slot, dll, symbol, func["listing"],references.get(site,"")))
    entries.sort()
    assert entries and len({r[0] for r in entries}) == len(entries)
    rebuild = reassemble(args.zig.resolve(), entries)
    args.output.mkdir(parents=True, exist_ok=True)
    csv_path = args.output / "s5-import-thunks.csv"
    with csv_path.open("w", encoding="utf-8", newline="") as out:
        writer = csv.writer(out, lineterminator="\n")
        writer.writerow(["entry_rva","end_exclusive","original_bytes","iat_slot","dll","import_name_or_ordinal","s1_ghidra_source","s1_self_iat_reference"])
        for site, data, slot, dll, symbol, listing, previous in entries:
            writer.writerow([hex(site),hex(site+6),data.hex(),hex(slot),dll,symbol,listing,previous])
    original_resources = image.resources()
    expected = {(r["type"],r["name"],r["language"]):(int(r["rva"],0),int(r["bytes"]),int(r["code_page"]),r["sha256"])
                for r in rows(args.s1/"resources.csv")}
    assert expected == original_resources
    gap_count = sum(row["state"] == "gap" for row in coverage.values())
    counts = collections.Counter(dll for _,_,_,dll,*_ in entries)
    result = {"original_sha256":DIGEST,"reference_commit":"f1ed621740bf27fabf86b4780d9fdcb75df279ca",
              "reference_blobs":INPUT_BLOBS,"old_gap_count":gap_count,"matching_entries":len(entries),
              "other_old_gaps":gap_count-len(entries),"iat_slots":len({e[2] for e in entries}),
              "ordinal_import_entries":sum(e[4].startswith("#") for e in entries),
              "named_import_entries":sum(not e[4].startswith("#") for e in entries),
              "dll_counts":dict(sorted(counts.items())),"reassembly":rebuild,
              "previous_self_iat_reference_rows":sum(bool(e[6]) for e in entries),
              "previous_reference_index_sites_absent":sum(e[0] not in all_reference_sites for e in entries),
              "addresses_sha256":hashlib.sha256(csv_path.read_bytes()).hexdigest(),
              "resource_precheck":{"leaves":len(expected),"payload_bytes":sum(r[1] for r in expected.values()),
                  "types":dict(sorted(collections.Counter(key[0] for key in expected).items())),
                  "identities_and_payload_digests_equal":True}}
    with (args.output/"s5-recovery.json").open("w", encoding="utf-8", newline="\n") as out:
        out.write(json.dumps(result,indent=2,ensure_ascii=False)+"\n")
    print(json.dumps(result))


if __name__ == "__main__":
    main()
