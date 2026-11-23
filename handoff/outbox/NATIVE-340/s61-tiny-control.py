"""Compare tiny CLI IL extents in two fixtures and every tiny method in the pinned DLL."""
import argparse
from hashlib import sha256
import json
from pathlib import Path
import re
import struct
import sys


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("candidate", type=Path)
    parser.add_argument("--original", required=True, type=Path)
    args = parser.parse_args()
    sys.path.insert(0, str(args.candidate.resolve() / "tool"))
    import il_disasm
    import md_reader
    import method_body
    from pe_reader import PE

    blob = args.original.read_bytes()
    digest = sha256(blob).hexdigest()
    assert digest == "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
    pe = PE(blob)
    cli_rva, _ = pe.directory(14)
    md_rva = struct.unpack_from("<I", blob, pe.filepos(cli_rva) + 8)[0]
    methods = md_reader.parse(blob, pe.filepos(md_rva))["methods"]
    unit = args.candidate / "handoff/inbox/NATIVE-340"
    listings = {}
    for line in (unit / "code/methods.il").read_text(encoding="utf-8-sig").splitlines():
        header = re.match(r"// MethodDef (0x[0-9A-F]+) ",line)
        if header:
            token = int(header[1], 16)
            listings[token] = []
        ins = re.match(r"\s*IL_([0-9A-Fa-f]+):\s+(\S+)",line)
        if ins:
            listings[token].append((int(ins[1], 16), ins[2]))

    class FixturePE:
        secs = [dict(rva=0x4000,size=4,vsize=4,exec=True,name=".text")]
        @staticmethod
        def filepos(rva):
            return rva - 0x4000

    fixtures = []
    for op in (0, 1):
        data = bytes([0x0A, op, 0x2A, 0xCC])
        hdr = method_body.header(data,FixturePE(),0x4000)
        fixtures.append(dict(input=data.hex(), sha256=sha256(data).hexdigest(),
                             expected_size=data[0] >> 2, expected_il=data[1:3].hex(),
                             actual_size=hdr["code_size"], actual_il=hdr["il"].hex()))
    tiny = []
    for method in methods:
        if not method["rva"] or method["flavor"] != "IL":
            continue
        rva, token = method["rva"], method["token"]
        p = pe.filepos(rva)
        tag = blob[p]
        if tag & 3 != 2:
            continue
        size = tag >> 2
        expected_il = blob[p+1:p+1+size]
        hdr = method_body.header(blob, pe, rva)
        view = il_disasm.body(blob, pe.filepos, rva)
        decoded = [(off, name) for off, name, _, _ in il_disasm.decode(expected_il)]
        tiny.append(dict(token=f"0x{token:08X}",rva=hex(rva),header=hex(tag),first_il=hex(blob[p+1]),
                         expected_size=size, actual_size=hdr["code_size"], returned_size=len(hdr["il"]),
                         listing_generator_bytes_match=view == expected_il,
                         published_offsets_mnemonics_match=listings[token] == decoded))
    wrong = [m for m in tiny if m["actual_size"] != m["expected_size"] or m["returned_size"] != m["expected_size"]]
    print(json.dumps(dict(original_sha256=digest, fixtures=fixtures, tiny_methods=len(tiny),
                          incorrect_extent=len(wrong), new_reader_failures=wrong,
                          listing_generator_body_differences=[m["token"] for m in tiny if not m["listing_generator_bytes_match"]],
                          published_offset_mnemonic_differences=[m["token"] for m in tiny if not m["published_offsets_mnemonics_match"]]),
                     ensure_ascii=True, indent=2))


if __name__ == "__main__":
    main()
