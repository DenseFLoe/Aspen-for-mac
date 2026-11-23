"""Recheck the fixed s69 submission. The only edits made are in temporary copies."""
import argparse
from collections import Counter
import csv
from hashlib import sha256
import io
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
import tempfile


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def run(*cmd):
    return subprocess.run(list(map(str, cmd)), capture_output=True, text=True,
                          encoding="utf-8", errors="replace")


def rows(path):
    return list(csv.DictReader(io.StringIO(path.read_text(encoding="utf-8-sig"))))


def fingerprints(unit, refresh=False):
    result = {}
    for name, round_set in (("s29", False), ("s69", True)):
        path = unit / f"code/{name}-fingerprints.json"
        doc = json.loads(path.read_bytes())
        expected = {}
        for file in sorted(unit.rglob("*")):
            if not file.is_file() or "fingerprints" in file.name:
                continue
            if not round_set and file.name.endswith(("-started.md", "-submission.md")):
                continue
            expected[file.relative_to(unit).as_posix()] = digest(file)
        if refresh:
            changed = dict(doc, count=len(expected), files=expected) if round_set else expected
            path.write_text(json.dumps(changed, ensure_ascii=False, indent=1)+"\n", encoding="utf-8")
            doc = json.loads(path.read_bytes())
        actual = doc["files"] if round_set else doc
        assert actual == expected
        if round_set:
            assert doc["count"] == len(actual)
        result[name] = {"count":len(actual), "sha256":digest(path)}
    return result


def site_keys(unit):
    path = unit/"code/s69-calli-sites.csv"
    return Counter((r["method"], r["il_offset"], r["op"], r["target"], r["ldftn"], r["arg"].strip())
                   for r in rows(path))


def reference_sites(evidence):
    result = []
    for site in evidence["original_sites"]:
        window = [op.split(":") for op in site["context"].split(",")]
        function, argument = window[-2:]
        assert function[1] == "ldftn"
        arg = argument[1]
        if arg == "ldloca.s":
            arg += f" 0x{int(argument[2],16):X}"
        else:
            assert arg == "ldarg.0"
        result.append(("0x"+site["caller"], "IL_"+site["offset"], site["opcode"],
                       "0x"+site["wrapper"], "0x"+function[2], arg))
    return Counter(result)


def native_evidence(original, slot_lines):
    data = original.read_bytes()
    pe = struct.unpack_from("<I",data,60)[0]
    assert data[pe:pe+4] == b"PE\0\0"
    count = struct.unpack_from("<H",data,pe+6)[0]
    optional = pe+24
    assert struct.unpack_from("<H",data,optional)[0] == 0x20b
    section_table = optional+struct.unpack_from("<H",data,pe+20)[0]
    sections = []
    for i in range(count):
        i = section_table+i*40
        size, rva, raw_size, raw = struct.unpack_from("<4I",data,i+8)
        flags = struct.unpack_from("<I",data,i+36)[0]
        sections.append((rva,raw_size,raw,flags))
    def address(rva):
        for start,size,raw,_ in sections:
            if start <= rva < start+size:
                return raw+rva-start
        raise ValueError(rva)
    def string(rva):
        pos = address(rva)
        return data[pos:data.index(b"\0",pos)].decode("ascii")
    exp, exp_size = struct.unpack_from("<II",data,optional+112)
    base, nfuncs, nnames, funcs, names, ordinals = struct.unpack_from("<6I",data,address(exp)+16)
    exported = [{"ordinal":base+i,"rva":hex(struct.unpack_from("<I", data,address(funcs)+4*i)[0]),"names":[]} for i in range(nfuncs)]
    for i in range(nnames):
        idx = struct.unpack_from("<H",data,address(ordinals)+i*2)[0]
        exported[idx]["names"].append(string(struct.unpack_from("<I",data,address(names)+i*4)[0]))
    targets = {int(line.split("\t")[2],16):line.split("\t")[1] for line in slot_lines}
    thunks = []
    for start,size,raw,flags in sections:
        if not flags & 0x20000000:
            continue
        for m in re.finditer(b"\xff\x25",data[raw:raw+size]):
            off = m.start()
            if off+6 > size:
                continue
            source = start+off
            target = source+6+struct.unpack_from("<i",data,raw+off+2)[0]
            if target in targets:
                thunks.append({"rva":hex(source),"slot":hex(target),"token":targets[target],
                               "bytes":data[raw+off:raw+off+6].hex()})
    thunk_addresses = {int(row["rva"],16) for row in thunks}
    reloc, reloc_size = struct.unpack_from("<II",data,optional+112+5*8)
    image_base = struct.unpack_from("<Q",data,optional+24)[0]
    refs = []
    if reloc_size:
        pos, end = address(reloc), address(reloc)+reloc_size
        while pos < end:
            page, block = struct.unpack_from("<II",data,pos)
            assert block >= 8 and pos+block <= end
            for offset in range(pos+8,pos+block,2):
                encoded = struct.unpack_from("<H",data,offset)[0]
                if encoded >> 12 != 10:
                    continue
                location = page+(encoded&4095)
                value = struct.unpack_from("<Q",data,address(location))[0]-image_base
                if value in thunk_addresses or value in targets:
                    refs.append({"source_rva":hex(location),"target_rva":hex(value)})
            pos += block
    return {"export_directory":[hex(exp),hex(exp_size)],"exports":exported,
            "rip_relative_jmp_candidates":thunks,"dir64_to_thunks_or_slots":refs}


def main():
    parser = argparse.ArgumentParser()
    for name in ("original","fixed","checker","out"):
        parser.add_argument("--"+name, type=Path, required=True)
    args = parser.parse_args()
    unit = args.fixed/"handoff/inbox/NATIVE-340"
    reader = Path(__file__).with_name("s69-read-original.ps1")
    audit = args.fixed/"tool/audit_340_s69.py"
    assert digest(args.checker) == "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
    assert digest(audit) == "a19b517636282ce7820b85022a3712ea6906ce271fdf734772adafd9130ddd6c"
    result = run("pwsh","-NoProfile","-File",reader,"-Original",args.original,"-Unit",unit)
    result.check_returncode()
    evidence = json.loads(result.stdout)
    reference = reference_sites(evidence)
    assert not evidence["eh_differences"] and evidence["eh_clauses"] == 35
    calls = rows(unit/"calls.csv")
    wrappers = {int(c["caller"],16):c for c in calls if c["kind"]=="method" and c["class"]=="unresolved"}
    notes = re.findall(r"([0-9A-F]{3})@(IL_[0-9A-F]+)->(0x[0-9A-F]+)",wrappers[0x06000056]["note"])
    assert Counter(notes) == Counter((r[0][-3:],r[1],r[4]) for r in reference.elements())
    unresolved = Counter(r["kind"] for r in calls if r["class"]=="unresolved")
    def coverage(test):
        p = run(sys.executable,"-B",args.checker,"NATIVE-340","--original",args.original,"--submission",test)
        return {"exit":p.returncode,"output":p.stdout.strip(),"stderr":p.stderr.strip()}
    def case(test, refreshed=False):
        actual = site_keys(test)
        return {"fingerprints":fingerprints(test,refreshed),
                "sites_sha256":digest(test/"code/s69-calli-sites.csv"),
                "missing_sites":list((reference-actual).elements()),
                "extra_sites":list((actual-reference).elements()),"coverage":coverage(test)}
    positive = case(unit)
    assert not positive["missing_sites"] and not positive["extra_sites"]
    with tempfile.TemporaryDirectory(dir=args.out.resolve().parent) as tmp:
        changed = Path(tmp)/"candidate"
        shutil.copytree(unit,changed)
        target = changed/"code/s69-calli-sites.csv"
        lines = target.read_bytes().splitlines(keepends=True)
        kept = [x for x in lines if not (b"0x0600000B" in x and b"IL_0044" in x)]
        assert len(kept)+1 == len(lines)
        target.write_bytes(b"".join(kept))
        negative = case(changed,True)
        assert len(negative["missing_sites"]) == 1 and not negative["extra_sites"]
        assert positive["coverage"] == negative["coverage"] and positive["coverage"]["exit"] == 2
        p = run(sys.executable,"-B",audit,"--binary",args.original,"--folder",changed)
        p.check_returncode()
        regenerated = {"exit":p.returncode,"site_table_restored":target.read_bytes()==(unit/"code/s69-calli-sites.csv").read_bytes(),
                       "access_table_same":(changed/"code/s69-method-access.csv").read_bytes()==(unit/"code/s69-method-access.csv").read_bytes()}
    evidence.update(fixed="5ca17f4987251f32be4772955c8b9be3185b9c62", baseline="0efdc367513b4850841dff1d13ebd78cb5cea67a",
                    reader_sha256=digest(reader), coverage_sha256=digest(args.checker), audit_sha256=digest(audit),
                    candidate_access=rows(unit/"code/s69-method-access.csv"), unresolved=unresolved,
                    native=native_evidence(args.original,evidence["fixups"]),main_call_table_matches=True,
                    original_candidate=positive, one_row_removed=negative, candidate_regeneration=regenerated)
    args.out.write_text(json.dumps(evidence, ensure_ascii=False,indent=2)+"\n",encoding="utf-8")


if __name__ == "__main__":
    main()
