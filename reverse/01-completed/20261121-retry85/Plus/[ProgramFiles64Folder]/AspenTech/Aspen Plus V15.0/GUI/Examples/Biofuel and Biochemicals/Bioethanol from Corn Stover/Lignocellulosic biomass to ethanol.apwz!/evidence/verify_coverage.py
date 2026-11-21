from collections import Counter
from datetime import datetime, timezone
from hashlib import sha256
from pathlib import Path
from struct import unpack_from
import sys

from iced_x86 import Decoder, Formatter, FormatterSyntax

obj = Path(sys.argv[1]).read_bytes()
out = Path(sys.argv[2])
machine, count, timestamp, table, entries, optional, flags = unpack_from("<HHIIIHH", obj)
assert machine == 0x8664 and optional == 0
string_table = table + 18 * entries
assert string_table + unpack_from("<I", obj, string_table)[0] == len(obj)
sections = {}
for i in range(count):
    name, _, _, size, pos, reloc, _, nreloc, _, flags = unpack_from("<8sIIIIIIHHI", obj, 20 + 40*i)
    name = name.rstrip(bytes(1)).decode("ascii")
    payload = obj[pos:pos+size] if pos else bytes(size)
    assert len(payload) == size
    sections[i+1] = (name, payload, pos, reloc, nreloc, flags)

symbols = {}
idx = 0
while idx < entries:
    name, value, section, kind, storage, aux = unpack_from("<8sIhHBB", obj, table + 18*idx)
    if name[:4] == bytes(4):
        start = string_table + int.from_bytes(name[4:], "little")
        name = obj[start:obj.index(0, start)]
    symbols[idx] = (name.rstrip(bytes(1)).decode("ascii"), value, section, kind, storage)
    idx += 1 + aux
assert idx == entries

report = [f"SHA-256: {sha256(obj).hexdigest()}",
          f"COFF timestamp (UTC): {datetime.fromtimestamp(timestamp, timezone.utc).isoformat()}"]
relocations = {}
for name, payload, pos, rel, count, flags in sections.values():
    report.append(f"{name:8} size={len(payload):#05x} raw={pos:#05x} relocation_count={count} flags=0x{flags:08x} "
                  f"sha256={'uninitialized' if not pos else sha256(payload).hexdigest()}")
    fixes = {}
    for i in range(count):
        at, sym, kind = unpack_from("<IIH", obj, rel + 10*i)
        assert kind in (3, 4) and at not in fixes
        sym_name, value, section, *_ = symbols[sym]
        addend = unpack_from("<i", payload, at)[0]
        fixes[at] = (sym_name, value, section, kind, addend)
    relocations[name] = fixes

text = sections[1][1]
decoder = Decoder(64, text)
printer = Formatter(FormatterSyntax.NASM)
printer.rip_relative_addresses = True
code = list(decoder)
assert not any(instruction.is_invalid for instruction in code)
assert sum(instr.len for instr in code) == len(text)
bounds = {instr.ip for instr in code} | {len(text)}

details = []
seen = set()
for instr in code:
    offsets = range(instr.ip, instr.next_ip)
    notes = []
    for at in offsets:
        if at not in relocations[".text"]:
            continue
        name, _, sec, kind, addend = relocations[".text"][at]
        assert at + 4 <= instr.next_ip
        notes.append(f"COFF {at:03x} {'RVA32' if kind == 3 else 'REL32'} {name}{addend:+#x}")
        seen.add(at)
    details.append(f"{instr.ip:03x}  {text[instr.ip:instr.next_ip].hex(' '):30} {printer.format(instr)}"
                   + ("  ; " + ", ".join(notes) if notes else ""))
assert seen == set(relocations[".text"])
out.joinpath("instruction-map.txt").write_text(
    "Offsets are relative to .text. COFF annotations override unlinked operands.\n" + "\n".join(details) + "\n", encoding="utf-8")
report.append(f".text: {len(code)} instructions including alignment NOPs, {len(text)} bytes, "
              f"{len(seen)} relocations each contained in one instruction")
report.append(f"Final instructions: " + ", ".join(f"{instr.ip:03x} {printer.format(instr)}" for instr in code[-4:]))
pdata, xdata = sections[6][1], sections[5][1]
previous_end = 0
for at in range(0, len(pdata), 12):
    start, end, unwind = unpack_from("<III", pdata, at)
    assert start == previous_end and start in bounds and end in bounds
    assert unwind < len(xdata) and unwind % 4 == 0
    assert [relocations[".pdata"][at + i*4][2:4] for i in range(3)] == [(1,3),(1,3),(5,3)]
    previous_end = end
    version, flags = xdata[unwind] & 7, xdata[unwind] >> 3
    slots = xdata[unwind+2]
    assert version == 1
    chain = unwind + 4 + 2*((slots+1)//2*2)
    assert chain <= len(xdata)
    report.append(f".pdata+{at:02x}: .text+{start:03x}..{end:03x}, .xdata+{unwind:02x}, "
                  f"version {version}, flags {flags}, slots {slots}")
    if flags & 4:
        offsets = [chain + i*4 for i in range(3)]
        assert [relocations[".xdata"][i][2:4] for i in offsets] == [(1,3),(1,3),(5,3)]
        values = [relocations[".xdata"][i][1] + relocations[".xdata"][i][4] for i in offsets]
        assert 0 <= values[0] < values[1] <= len(text) and values[2] < len(xdata)
        report.append(f"  chained range .text+{values[0]:03x}..{values[1]:03x}, .xdata+{values[2]:02x}")
assert previous_end == len(text)
assert len(relocations[".xdata"]) == 27
report.append("Relocation counts: " + str(Counter((name, item[3]) for name, rels in relocations.items() for item in rels.values())))
report.append("Common symbol declarations (bytes): " + ", ".join(f"{name}={value}" for name, value, section, *_ in symbols.values() if section == 0 and value))
report.append("Double thresholds and normalization constant:")
for offset in [0x40, 0x48, 0x50]:
    raw = sections[2][1][offset:offset+8]
    report.append(f"  .rdata+{offset:02x} {raw.hex(' ')} = {unpack_from('<d',raw)[0]:.17g}")
report.append("Literal integers and format descriptors:")
for offset in range(0,0x40,8):
    raw = sections[2][1][offset:offset+8]
    report.append(f"  .rdata+{offset:02x} {raw.hex(' ')} = {unpack_from('<Q',raw)[0]}")
out.joinpath("coverage.txt").write_text("\n".join(report) + "\n", encoding="utf-8")

