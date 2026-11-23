"""Reproduce s97 controls on the pinned candidate, its parent, original and package-local PEReader output."""
import argparse
from hashlib import sha256
import importlib.util
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import pefile


def load(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def run(path, *args):
    p = subprocess.run([sys.executable, "-B", str(path), *map(str, args)], capture_output=True,
                       encoding="utf-8", errors="replace")
    return dict(exit=p.returncode, stdout=p.stdout.strip(), stderr=p.stderr.strip())


def digest(data):
    return sha256(data).hexdigest()


def replace_once(data, before, after):
    assert data.count(before) == 1
    return data.replace(before, after)


def main():
    ap = argparse.ArgumentParser()
    for name in ["candidate", "parent", "original", "width_fixture_script", "pereader_output"]:
        ap.add_argument(name, type=Path)
    args = ap.parse_args()
    candidate, parent, original, script, reader = (p.resolve() for p in vars(args).values())
    rel = Path("handoff/inbox/NATIVE-340")
    unit = candidate / rel
    tool = candidate / "tool"
    helper = load(script, "independent_width")
    current = load(tool / "cli_tables.py", "current_cli")
    previous = load(parent / "tool/cli_tables.py", "previous_cli")
    raw = original.read_bytes()
    pe = pefile.PE(data=raw)
    clr = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress
    meta, = struct.unpack("<I", pe.get_data(clr + 8, 4))
    parsed = current.read(raw, pe.get_offset_from_rva(meta))["rows"]
    sdk = json.loads(reader.read_bytes())
    kinds = {"TypeDefinition":2, "TypeReference":1, "ModuleReference":26, "MethodDefinition":6,
             "TypeSpecification":27, "MemberReference":10}
    mismatch = []
    for section, tbl, fields in [("refs",10,[("parent","Class")]), ("impls",25,[("body","MethodBody"),
                                          ("decl","MethodDeclaration")]), ("cattrs",12,[("type","Type")])]:
        assert len(sdk[section]) == len(parsed.get(tbl, []))
        for item, row in zip(sdk[section], parsed.get(tbl, [])):
            for sdk_key, cli_key in fields:
                expected = (kinds[item[sdk_key+"_kind"]], item[sdk_key+"_rid"])
                if row["_decoded"][cli_key] != expected:
                    mismatch.append([section, row["_row"], cli_key])
    report = dict(head="38b6814d15332a90258f2caa42169b6f52e5bad4", original_sha256=digest(raw),
                  pereader=dict(sha256_matches=sdk["sha256"]==digest(raw), mismatches=mismatch,
                                counts={k:v for k,v in sdk.items() if k.endswith("_rows")}))
    report["fingerprints"] = {}
    for name in ["s29", "s97"]:
        path = unit / "code" / (name+"-fingerprints.json")
        obj = json.loads(path.read_bytes())
        mapping = obj.get("files", obj)
        report["fingerprints"][name] = dict(entries=len(mapping), sha256=digest(path.read_bytes()),
            mismatch=[p for p,h in mapping.items() if digest((unit/p).read_bytes()) != h])
    report["script_sha256"] = {name:digest((tool/name).read_bytes()) for name in
          ["s97-site-owners.py","s93-width-controls.py","cli_tables.py","verify_il_digests.py",
           "audit_340_s89.py","pereader_340/Program.cs","pereader_340/pereader_340.csproj"]}
    report["implmap"] = []
    for forward, field_count, method_count in [(2,1,0),(3,0,1)]:
        # Both target RID=1. ECMA-335 MemberForwarded uses one tag bit.
        counts = {28:1,26:1}
        rows = {26:bytes(2),28:struct.pack("<HHHH", 0,forward,17,1)}
        if field_count:
            counts[4]=1; rows[4]=bytes(6)
        if method_count:
            counts[6]=1; rows[6]=bytes(14)
        data = helper.metadata_fixture(counts, rows)
        report["implmap"].append(dict(raw=forward,input_sha256=digest(data),
            expected=[4 if field_count else 6,1],
            previous=previous.read(data,0)["rows"][28][0]["_decoded"]["MemberForwarded"],
            current=current.read(data,0)["rows"][28][0]["_decoded"]["MemberForwarded"]))
    calls = (unit/"calls.csv").read_bytes()
    with TemporaryDirectory(dir=Path.cwd()) as temp:
        t = Path(temp)
        sample = t/rel
        sample.mkdir(parents=True)
        shutil.copyfile(unit/"native-functions.csv",sample/"native-functions.csv")
        source = tool/"s97-site-owners.py"
        owner = b"native,0x2B74,KERNEL32.dll!GetModuleHandleW,"
        listing = b"code/native.asm#L1509,IAT thunk"
        report["owner_controls"] = []
        for label, expect, data in [
            ("relocated_intact",0,calls),
            ("only_owner_0x2B7A",1,replace_once(calls,owner,owner.replace(b"0x2B74",b"0x3660"))),
            ("only_listing_0x4711",1,replace_once(calls,listing,listing.replace(b"L1509",b"L1510"))),
            ("only_note_word_0x4711",1,replace_once(calls,listing,listing.replace(b"IAT thunk",b"IAT jump"))),
        ]:
            (sample/"calls.csv").write_bytes(data)
            report["owner_controls"].append(dict(case=label,expected_exit=expect,sha256=digest(data),**run(source,t)))
        # Also preserve all source files in the baseline for comparison with the relocated two-input run.
        report["owner_controls"].insert(0,dict(case="as_delivered",expected_exit=0,sha256=digest(calls),
                                               **run(source,candidate)))
        modified = t/"tool"/"cli_tables.py"
        modified.parent.mkdir()
        src = (tool/"cli_tables.py").read_bytes()
        bad = replace_once(src,b"return codedsize(kind[1], kind[2])",b"return 2")
        modified.write_bytes(bad)
        report["width_controls"] = {}
        for label, root in [("as_delivered",candidate),("only_actual_reader_width_changed",t)]:
            own = run(tool/"s93-width-controls.py",root)
            ext = run(script,root)
            rows = json.loads(ext["stdout"])
            report["width_controls"][label] = dict(parser_sha256=digest((root/"tool/cli_tables.py").read_bytes()),
                 candidate_probe=own, independent_exit=ext["exit"],
                 tests=[dict(table=r["table"],count=r["target_count"],match=r["match"],
                             sha256=r["input_sha256"]) for r in rows])
    print(json.dumps(report, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
