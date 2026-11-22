"""Independently rebuild the library, check the reference, then verify one editable-code change."""
import argparse
import json
from hashlib import sha256
from pathlib import Path, PureWindowsPath
import shutil
import struct
import subprocess
import sys
import tempfile

SOURCE = Path(__file__).resolve().parent
DIGEST = "7738ce952d97d2f27c6fce67e735f5e710598a8ce1b77746cbe443f611fe4dee"


def require(test, description):
    if not test:
        raise ValueError(description)


def members(archive):
    require(archive[:8] == b"!<arch>\n", "Archive signature")
    rows = {}
    cursor = 8
    while cursor < len(archive):
        head = archive[cursor:cursor+60]
        require(len(head) == 60 and head[58:] == b"\x60\n", "Archive member header")
        size = int(head[48:58])
        data = archive[cursor+60:cursor+60+size]
        require(len(data) == size, "Member payload truncated")
        name = head[:16].rstrip()
        if name == b"//":
            longnames = data
        elif name != b"/":
            start = int(name[1:])
            filename = PureWindowsPath(longnames[start:longnames.index(0,start)].decode()).name
            require(filename not in rows, "Duplicate object name")
            rows[filename] = data
        cursor += 60 + size + size%2
    require(cursor == len(archive), "Archive extent")
    return rows


def section(obj, name, with_relocations=False):
    found = []
    for i in range(struct.unpack_from("<H",obj,2)[0]):
        label, _, _, size, at, rel, _, count, _, _ = struct.unpack_from("<8sIIIIIIHHI",obj,20+40*i)
        if label.rstrip(b"\0").decode() == name and (count or not with_relocations):
            relocations = [struct.unpack_from("<IIH",obj,rel+10*j) for j in range(count)]
            found.append((obj[at:at+size],relocations))
    require(len(found) == 1, f"Expected exactly one matching {name} section")
    return found[0]


def rebuild(source, destination, assembler):
    subprocess.run([sys.executable, "-B", str(source/"nl2sol.lib.build.py"),
                    "--assembler",assembler,"--output",str(destination)],
                   check=True,cwd=destination.parent)
    return destination.read_bytes()


def check(original, assembler, work):
    require(sha256(original).hexdigest() == DIGEST, "Unexpected reference SHA-256")
    regenerated = rebuild(SOURCE,work/"rebuilt.lib",assembler)
    require(regenerated == original, "Rebuild differs from original")
    reference = members(original)
    evidence = json.loads((SOURCE/"nl2sol.lib.verify.json").read_text())
    require(list(reference) == [r["member"] for r in evidence["members"]], "Member sequence")
    for row in evidence["members"]:
        digest = sha256(reference[row["member"]]).hexdigest()
        require(digest == row["original_sha256"] == row["rebuilt_sha256"], row["member"])
    print(f"Identical {len(regenerated):,} bytes and {len(reference)} member fingerprints. SHA-256 {DIGEST}")

    changed_source = work/"changed"
    changed_source.mkdir()
    for name in ("nl2sol.lib.build.py","nl2sol.lib.layout.json"):
        shutil.copyfile(SOURCE/name,changed_source/name)
    source = (SOURCE/"nl2sol.lib.s").read_text(encoding="ascii")
    old = "at_1_0000:\n    push   r15"
    require(old in source.split("# MEMBER ssqfcn.obj")[0], "SSQJAC entry not found")
    (changed_source/"nl2sol.lib.s").write_text(source.replace(old,"at_1_0000:\n    nop\n    push   r15",1),
                                              encoding="ascii")
    edited = members(rebuild(changed_source,work/"edited.lib",assembler))
    require(list(edited) == list(reference), "Member sequence after the edit")
    require([n for n in reference if reference[n] != edited[n]] == ["ssqjac.obj"], "Edit scope")
    original_obj, edited_obj = reference["ssqjac.obj"], edited["ssqjac.obj"]
    text, fixups = section(original_obj,".text")
    new_text, new_fixups = section(edited_obj,".text")
    require(new_text == b"\x90"+text, "Inserted NOP and the following instructions")
    require([(pos+1,idx,typ) for pos,idx,typ in fixups] == new_fixups, "Moved .text fixups")
    table, slots = section(original_obj,".rdata",True)
    new_table, new_slots = section(edited_obj,".rdata",True)
    require(slots == new_slots, "Switch slot identities")
    for pos, _, _ in slots:
        before = struct.unpack_from("<I",table,pos)[0]
        require(struct.unpack_from("<I",new_table,pos)[0] == before+1, "Switch target")
    pdata, _ = section(edited_obj,".pdata")
    require(struct.unpack("<III",pdata) == (0,len(new_text),0), "Function address range")
    xd, _ = section(original_obj,".xdata")
    new_xd, _ = section(edited_obj,".xdata")
    expected = bytearray(xd)
    expected[1] += 1
    slot = 0
    while slot < xd[2]:
        offset = 4+2*slot
        op, info = xd[offset+1]&15, xd[offset+1]>>4
        expected[offset] += 1
        slot += {0:1,1:2 if info==0 else 3,2:1,3:1,4:2,5:3,8:2,9:3,10:1}[op]
    require(slot == xd[2] and bytes(expected) == new_xd, "Unwind record follows the edit")
    print(f"SSQJAC edit updated {len(fixups)} fixups, {len(slots)} switch targets, .pdata and .xdata.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original",required=True,type=Path)
    parser.add_argument("--assembler",default="x86_64-w64-mingw32-as")
    args = parser.parse_args()
    executable = shutil.which(args.assembler)
    if not executable:
        parser.error("Cannot locate the requested assembler")
    with tempfile.TemporaryDirectory() as tmp:
        check(args.original.read_bytes(),str(Path(executable).resolve()),Path(tmp))

