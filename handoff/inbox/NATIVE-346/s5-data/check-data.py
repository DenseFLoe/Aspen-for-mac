"""Validate exported storage, retained RIP references and the editable VERSIONINFO tree."""
import argparse
import csv
import hashlib
import json
import re
import struct
from pathlib import Path

import pefile
from iced_x86 import Decoder, Formatter, FormatterSyntax, MemorySizeExt


ORIGINAL = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
FIXED_FIELDS = ("signature struct_version file_version_ms file_version_ls product_version_ms "
                "product_version_ls flags_mask flags os type subtype date_ms date_ls").split()


def digest(data):
    return hashlib.sha256(data).hexdigest()


def align(n):
    return (n + 3) & ~3


def read_version(raw, start, limit):
    size, count, kind = struct.unpack_from("<3H", raw, start)
    end = start + size
    if not 6 < size or end > limit:
        raise ValueError("version block extent")
    pos = start + 6
    while pos + 2 <= end and raw[pos:pos+2] != b"\0\0":
        pos += 2
    name = raw[start+6:pos].decode("utf-16le")
    value_start = align(pos+2)
    value_end = value_start + count * (2 if kind == 1 else 1)
    if value_end > end:
        raise ValueError(name)
    value = raw[value_start:value_end]
    entry = {"key": name, "type": kind}
    if name == "VS_VERSION_INFO":
        entry["fixed"] = dict(zip(FIXED_FIELDS, struct.unpack("<13I", value)))
    elif kind == 1 and count:
        entry["text"] = value.decode("utf-16le")
    elif count:
        entry["words"] = list(struct.unpack(f"<{count//2}H", value))
    subs = []
    pos = value_end
    while align(pos) < end:
        child, pos = read_version(raw, align(pos), end)
        subs.append(child)
    if subs:
        entry["children"] = subs
    return entry, end


def encode_version(node):
    if "fixed" in node:
        value = struct.pack("<13I", *(node["fixed"][name] for name in FIXED_FIELDS))
    elif "text" in node:
        value = node["text"].encode("utf-16le")
    elif "words" in node:
        value = struct.pack(f"<{len(node['words'])}H", *node["words"])
    else:
        value = b""
    count = len(value) // (2 if node["type"] == 1 else 1)
    body = bytearray(struct.pack("<3H", 0, count, node["type"]))
    body.extend((node["key"]+"\0").encode("utf-16le"))
    body.extend(bytes(align(len(body))-len(body)))
    body.extend(value)
    for child in node.get("children", []):
        body.extend(bytes(align(len(body))-len(body)))
        body.extend(encode_version(child))
    struct.pack_into("<H", body, 0, len(body))
    return bytes(body)


def data_refs(pe, listing, first, end):
    seen = {}
    formatter = Formatter(FormatterSyntax.INTEL)
    for line in listing.read_text(encoding="utf-8").splitlines():
        m = re.match(r"^([0-9a-f]{8})  ([0-9a-f]{2}(?: [0-9a-f]{2})*)  ", line)
        if not m:
            continue
        site, raw = int(m[1], 16), bytes.fromhex(m[2])
        if raw != pe.get_data(site, len(raw)):
            raise ValueError(f"listing bytes at {site:#x}")
        ins = Decoder(64, raw, ip=site).decode()
        if ins.is_invalid or ins.len != len(raw):
            raise ValueError(f"instruction at {site:#x}")
        if not ins.is_ip_rel_memory_operand:
            continue
        target = ins.ip_rel_memory_address
        if first <= target < end:
            seen[site] = (site, target, MemorySizeExt.size(ins.memory_size), formatter.format(ins))
    return sorted(seen.values())


def examine(original, listing, folder, check):
    image = original.read_bytes()
    if digest(image) != ORIGINAL:
        raise ValueError("original SHA-256")
    pe = pefile.PE(data=image)
    section = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".data")
    start = section.VirtualAddress
    end = start + section.Misc_VirtualSize
    symbols = sorted((s.address, s.name.decode("ascii"), s.ordinal)
                     for s in pe.DIRECTORY_ENTRY_EXPORT.symbols if start <= s.address < end)
    first = symbols[0][0]
    raw_section = section.get_data()
    backed = raw_section[first-start:min(len(raw_section),end-start)]
    if any(backed) or any(first <= rel.rva < end and rel.type
                          for block in pe.DIRECTORY_ENTRY_BASERELOC for rel in block.entries):
        raise ValueError("storage initializer or relocation changed")
    outputs = {}
    refs = data_refs(pe, listing, first, end)
    import io
    def table(filename, columns, rows):
        buf = io.StringIO()
        writer = csv.writer(buf, lineterminator="\n")
        writer.writerow(columns)
        writer.writerows(rows)
        outputs[filename] = buf.getvalue().encode()
    groups = []
    ref_export = []
    for index, (rva, name, ordinal) in enumerate(symbols):
        bound = symbols[index+1][0] if index+1 < len(symbols) else end
        local = [row for row in refs if rva <= row[1] < bound]
        groups.append([name,ordinal,hex(rva),hex(bound),bound-rva,
                       len([row for row in local if row[1] == rva]),len(local)])
        ref_export += [(hex(site),hex(target),name,hex(target-rva),width,ins)
                       for site,target,width,ins in local]
    table("export-intervals.csv", ["name","ordinal","rva","next_label_or_section_end",
          "interval_bytes","exact_base_sites","interval_sites"], groups)
    table("storage-references.csv", ["site","target","preceding_export","distance_from_label",
          "instruction_memory_bytes","instruction"], ref_export)
    def json_bytes(obj):
        return (json.dumps(obj, ensure_ascii=False, indent=2)+"\n").encode("utf-8")
    resources = [(t.id, n.id, lang.id, lang.data.struct)
                 for t in pe.DIRECTORY_ENTRY_RESOURCE.entries for n in t.directory.entries
                 for lang in n.directory.entries]
    if len(resources) != 1:
        raise ValueError("resource tree")
    typ, name, lang, leaf = resources[0]
    raw = pe.get_data(leaf.OffsetToData, leaf.Size)
    node, used = read_version(raw, 0, len(raw))
    if used != len(raw) or encode_version(node) != raw:
        raise ValueError("VERSIONINFO round trip")
    version_model = {"resource_type":typ,"id":name,"language":lang,"code_page":leaf.CodePage,"root":node}
    outputs["version-resource.json"] = json_bytes(version_model)
    if check and encode_version(json.loads((folder/"version-resource.json").read_bytes())["root"]) != raw:
        raise ValueError("committed version resource")
    summary = {"original_sha256":ORIGINAL,"section_rva":hex(start),"first_export":hex(first),
               "virtual_end":hex(end),"mapped_bytes":end-first,"file_backed_zero_bytes":len(backed),
               "virtual_zero_bytes":end-first-len(backed),"base_relocations_in_span":0,
               "exports":len(symbols),"distinct_reference_sites_from_listing":len(refs),
               "exact_base_sites":sum(r[5] for r in groups),"resource_bytes":len(raw),
               "version_resource_sha256":digest(raw),"version_roundtrip":True}
    outputs["data-check.json"] = json_bytes(summary)
    for name, data in outputs.items():
        if check:
            if (folder/name).read_bytes() != data:
                raise ValueError(name)
        else:
            (folder/name).write_bytes(data)
    print(json.dumps(summary))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("listing", type=Path)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    examine(args.original, args.listing, Path(__file__).resolve().parent, args.check)
