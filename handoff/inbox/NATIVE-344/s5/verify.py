"""Compile the delivered C source, apply AMD64 REL32 fixups and check the original DLL."""
import argparse
import base64
from collections import Counter
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import pefile


ORIGINAL = "9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601"
SCOPE = "d8e77cf9c69026b4911f1081384214529a511318ec8be8577537c98df8e3b214"
HERE = Path(__file__).resolve().parent
INBOX = HERE.parent


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_object(data):
    machine, nsections, _, symbols_at, nsymbols, optional, _ = struct.unpack_from("<HHIIIHH", data)
    assert machine == 0x8664
    sections = [20+optional+i*40 for i in range(nsections)]
    text_index, hdr = next((i+1, h) for i,h in enumerate(sections) if data[h:h+8] == b".text\0\0\0")
    length, text_at, reloc_at = struct.unpack_from("<III", data, hdr+16)
    nreloc, = struct.unpack_from("<H", data, hdr+32)
    string_at = symbols_at + 18*nsymbols
    names = {}
    entries = {}
    i = 0
    while i < nsymbols:
        off = symbols_at + 18*i
        short = data[off:off+8]
        if short[:4] == bytes(4):
            start = string_at + int.from_bytes(short[4:],"little")
            name = data[start:data.index(b"\0", start)].decode("ascii")
        else:
            name = short.rstrip(b"\0").decode("ascii")
        value, section, _, storage, naux = struct.unpack_from("<IhHBB",data,off+8)
        names[i] = name, section, storage
        if name.startswith("entry_"):
            assert section == text_index and storage == 2
            address = int(name[6:],16)
            assert address not in entries
            entries[address] = value
        i += 1+naux
    slots = {}
    for i in range(nreloc):
        offset, sym, kind = struct.unpack_from("<IIH",data,reloc_at+i*10)
        name, section, storage = names[sym]
        assert kind == 4 and section == 0 and storage == 2 and name.startswith("slot_")
        assert offset not in slots
        slots[offset] = int(name[5:],16)
    return data[text_at:text_at+length], entries, slots


def verify_thunks(pe, zig, card):
    assert digest(card.read_bytes()) == SCOPE
    planned = {int(r["entry_rva"],0):r for r in rows(card)}
    coverage = {int(r["key"],0):r for r in rows(INBOX/"coverage.csv")}
    calls = {int(r["caller"],0):r for r in rows(INBOX/"calls.csv") if r["listing"].startswith("s5/import-thunks.asm#L")}
    listing = (HERE/"import-thunks.asm").read_text(encoding="utf-8").splitlines()
    source = (HERE/"import-thunks.c").read_text(encoding="utf-8").splitlines()
    with tempfile.TemporaryDirectory() as temp:
        obj = Path(temp) / "imports.obj"
        subprocess.run([zig,"cc","-target","x86_64-windows-gnu","-std=c11","-c",str(HERE/"import-thunks.c"),"-o",str(obj)],check=True)
        code, entries, slots = read_object(obj.read_bytes())
    assert entries.keys() == planned.keys() == calls.keys()
    assert sorted(entries.values()) == list(range(0, 6*len(entries),6))
    assert set(slots) == {pos+2 for pos in entries.values()} and len(code)==6*len(entries)
    imagebase = pe.OPTIONAL_HEADER.ImageBase
    imports = {imp.address-imagebase: (d.dll.decode("ascii"), "#"+str(imp.ordinal) if imp.import_by_ordinal else imp.name.decode("ascii"))
               for d in pe.DIRECTORY_ENTRY_IMPORT for imp in d.imports}
    original_entries = bytearray()
    relocated_entries = bytearray()
    for site in sorted(entries):
        row = planned[site]
        off = entries[site]
        assert code[off:off+6] == bytes.fromhex("ff2500000000")
        slot = slots[off+2]
        assert slot == int(row["iat_slot"],0)
        dll, name = imports[slot]
        assert (dll,name) == (row["dll"],row["import_name_or_ordinal"])
        orig = pe.get_data(site,6)
        rebuilt = code[off:off+2] + struct.pack("<i", slot-site-6)
        assert int(row["end_exclusive"],0)==site+6 and orig==rebuilt==bytes.fromhex(row["original_bytes"])
        original_entries.extend(orig)
        relocated_entries.extend(rebuilt)
        cov, call = coverage[site], calls[site]
        assert cov["state"] == "covered" and cov["first_bytes"] == pe.get_data(site,8).hex()
        assert cov["listing"] == call["listing"] and call["class"] == "external" and call["callee"] == dll+"!"+name
        asm = listing[int(cov["listing"].split("#L")[1])-1]
        assert asm.startswith(f"{site:#x}  {orig.hex(' ')}  jmp ") and asm.endswith(f"{slot:#x} {dll}!{name}")
        assert cov["source"].startswith("s5/import-thunks.c#L")
        line = source[int(cov["source"].split("#L")[1])-1]
        assert line == f"FORWARD({site:x}, {slot:x}); /* {dll}!{name} */"
    iat_sites = {}
    for row in rows(INBOX/"references.csv"):
        if row["kind"] != "iat":
            continue
        for pair in row["owner_rva:instruction_rva_hex"].split():
            owner, site = (int(x,16) for x in pair.split(":"))
            if owner == site and site in planned:
                assert site not in iat_sites
                iat_sites[site] = row["target"]
    assert iat_sites == {site:rec["dll"]+"!"+rec["import_name_or_ordinal"] for site,rec in planned.items()}
    count = len(planned)
    return dict(original_sha256=ORIGINAL, source_sha256=digest((HERE/"import-thunks.c").read_bytes()),
        compiler="Zig "+subprocess.check_output([zig,"version"],text=True).strip(),
        code_bytes=len(code), object_entry_symbols=count, rel32_records=len(slots),
        distinct_iat_slots=len(set(slots.values())), equal_original_and_relocated_bytes=len(original_entries),
        original_entry_order_sha256=digest(original_entries), relocated_entry_order_sha256=digest(relocated_entries),
        covered_states=dict(Counter(r["state"] for r in coverage.values())), indexed_thunk_calls=len(calls),
        old_missing_iat_sites=sum(not r["s1_self_iat_reference"] for r in planned.values()))


def verify_resources(pe):
    evidence = json.loads((HERE/"resources.json").read_text(encoding="utf-8"))
    expected = {}
    for kind in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for item in kind.directory.entries:
            for lang in item.directory.entries:
                key = tuple(str(e.name) if e.name is not None else str(e.id) for e in (kind,item,lang))
                d = lang.data.struct
                assert key not in expected
                expected[key] = d.OffsetToData,d.Size,d.CodePage
    delivered = {}
    edges = []
    for rec in evidence["resources"]:
        key = tuple(rec[k] for k in ("type","name","language"))
        assert key not in delivered
        rva, size, cp = expected[key]
        assert (rva,size,cp) == (int(rec["rva"],0),int(rec["bytes"]),int(rec["code_page"]))
        data = base64.b64decode(rec["content_base64"],validate=True)
        assert len(data) == size and data == pe.get_data(rva,size) and digest(data) == rec["sha256"]
        delivered[key] = data
        if key[0] == "14":
            reserved, kind, n = struct.unpack_from("<HHH", data)
            assert reserved == 0 and kind == 1 and len(data) == 6+14*n
            for index in range(n):
                w,h,colors,zero,planes,bits,nbytes,ident=struct.unpack_from("<BBBBHHIH",data,6+14*index)
                assert zero == 0 and expected["3",str(ident),key[2]][1] == nbytes
                edges.append(dict(group=key[1],language=key[2],index=index,icon=ident,width=w or 256,
                                  height=h or 256,colors=colors,planes=planes,bits_per_pixel=bits,expected_bytes=nbytes))
    assert expected.keys() == delivered.keys() and edges == evidence["group_icon_edges"]
    return dict(leaves=len(delivered),bytes=sum(map(len,delivered.values())),
                types=len({r[0] for r in delivered}),icon_groups=len({(e["group"],e["language"]) for e in edges}),
                group_icon_links=len(edges),distinct_linked_icons=len({(e["icon"],e["language"]) for e in edges}))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    parser.add_argument("zig",type=Path)
    parser.add_argument("--card",type=Path,default=INBOX.parents[1]/"outbox/NATIVE-344/s5-import-thunks.csv")
    args = parser.parse_args()
    data = args.original.read_bytes()
    assert digest(data) == ORIGINAL
    pe = pefile.PE(data=data)
    report = verify_thunks(pe,str(args.zig.resolve()),args.card)
    report["resources"] = verify_resources(pe)
    print(json.dumps(report,sort_keys=True))
