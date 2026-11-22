"""Verify original COFF coverage and statically compare a freshly assembled object."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile
from urllib.parse import quote
from urllib.request import urlopen


ROOT = Path(__file__).resolve().parents[2]
PREFIX = ("等待铁头猫/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/"
          "Examples/Biofuel and Biochemicals/")
COMMIT = "ad53650f6071f83b133ede7bf847bc5096cd3b56"
TASKS = {
    "COFF-BFDYLD": (
        "Biomass characterization/Biofeed converter.apwz!/BFDYLD.obj",
        "194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0"),
    "COFF-BFDYLD-CORN": (
        "Bioethanol from Corn Stover/Lignocellulosic biomass to ethanol.apwz!/BFDYLD.obj",
        "3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a"),
}


def require(test, message):
    if not test:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_coff(data):
    machine, count, _, symptr, nsyms, opt, _ = struct.unpack_from("<HHIIIHH", data)
    require(machine == 0x8664 and opt == 0, "expected AMD64 COFF object")
    sections = {}
    symbols = {}
    for idx in range(count):
        name, _, _, size, raw, rel, _, nrel, _, flags = struct.unpack_from(
            "<8sIIIIIIHHI", data, 20 + 40 * idx)
        name = name.rstrip(b"\0").decode("ascii")
        require(name not in sections, f"duplicate section {name}")
        payload = data[raw:raw + size] if raw else b""
        require(len(payload) == size or not raw, f"short section {name}")
        relocations = [struct.unpack_from("<IIH", data, rel + 10 * j) for j in range(nrel)]
        sections[name] = dict(index=idx+1, size=size, data=payload,
                              relocs=relocations, flags=flags)
    idx = 0
    while idx < nsyms:
        off = symptr + 18 * idx
        name = data[off:off + 8]
        if not int.from_bytes(name[:4], "little"):
            start = symptr + nsyms * 18 + int.from_bytes(name[4:], "little")
            name = data[start:data.index(b"\0", start)]
        value, section, typ, storage, aux = struct.unpack_from("<IhHBB", data, off+8)
        auxiliary = data[off+18:off+18*(1+aux)]
        symbols[idx] = (name.rstrip(b"\0").decode("ascii"), value, section, typ,
                        storage, aux, auxiliary.hex())
        idx += 1 + aux
    return sections, symbols


def rows(sections, symbols):
    secrows = [(k, s["index"], s["size"], len(s["data"]), f'{s["flags"]:#010x}',
                digest(s["data"]), len(s["relocs"])) for k, s in sections.items()]
    symrows = [(i, *s) for i, s in symbols.items()]
    relrows = []
    for name, s in sections.items():
        for off, idx, typ in s["relocs"]:
            require(typ in (3, 4), f"unexpected relocation type {typ}")
            addend, = struct.unpack_from("<i", s["data"], off)
            relrows.append((name, f"{off:#x}", idx, symbols[idx][0],
                            "ADDR32NB" if typ == 3 else "REL32", addend))
    return secrows, symrows, relrows


def normalized_symbols(sections, symbols):
    names = {section["index"]: name for name, section in sections.items()}
    return {index: (name, value, names.get(section, section), typ, storage, aux)
            for index, (name, value, section, typ, storage, aux, _) in symbols.items()}


def call_sites(sections, symbols):
    section = sections[".text"]
    calls = []
    for off, index, typ in section["relocs"]:
        symbol = symbols[index]
        if typ == 4 and section["data"][off-1] == 0xe8 and symbol[2] == 0:
            calls.append((f"{off-1:#x}", f"{off:#x}", symbol[0]))
    return calls


def compare_objects(original, rebuilt):
    sections, symbols = original
    other_sections, other_symbols = rebuilt
    require(set(sections) == set(other_sections), "section names differ")
    source = normalized_symbols(sections, symbols)
    result = normalized_symbols(other_sections, other_symbols)
    require(sorted(source.values(), key=str) == sorted(result.values(), key=str),
            "symbol identity, definition, type, storage or value differs")
    for name, section in sections.items():
        other = other_sections[name]
        require(section["size"] == other["size"], f"{name}: declared size differs")
        require(section["flags"] == other["flags"], f"{name}: flags differ")
        require(section["data"] == other["data"], f"{name}: raw bytes differ")
        expected = sorted((off, typ, source[idx]) for off, idx, typ in section["relocs"])
        actual = sorted((off, typ, result[idx]) for off, idx, typ in other["relocs"])
        require(expected == actual, f"{name}: relocation offsets, types or symbolic targets differ")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("task", nargs="?", default="COFF-BFDYLD", choices=TASKS)
    parser.add_argument("--original", type=Path)
    parser.add_argument("--inventory", action="store_true")
    parser.add_argument("--details", action="store_true", help="print all original section, symbol and relocation rows")
    parser.add_argument("--fortran", type=Path, help="use a local copy of the archived Fortran source")
    parser.add_argument("--assembler", help="path to clang or zig")
    args = parser.parse_args()
    name, expected = TASKS[args.task]
    if args.original:
        data = args.original.read_bytes()
    else:
        url = ("https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/" +
               COMMIT + "/" + quote(PREFIX+name))
        with urlopen(url, timeout=60) as stream:
            data = stream.read()
    require(digest(data) == expected, "original SHA-256 mismatch")
    secs, syms = original = read_coff(data)
    inventories = rows(secs, syms)
    summary = dict(original_sha256=expected, sections=len(secs), text_bytes=secs[".text"]["size"],
                   symbols=len(syms), auxiliary=sum(s[5] for s in syms.values()),
                   relocations=len(inventories[2]))
    if args.details:
        print(json.dumps(dict(sections=inventories[0], symbols=inventories[1],
                              relocations=inventories[2], calls=call_sites(secs, syms))))
        return
    if args.inventory:
        print(json.dumps(summary))
        return
    archive = ("reverse/01-completed/20261121-retry85/" +
               PREFIX.removeprefix("等待铁头猫/") + name)
    archive += "/BFDYLD.obj.f" if args.task == "COFF-BFDYLD" else ".f"
    if args.fortran:
        fortran = args.fortran.read_bytes()
    elif (ROOT / archive).is_file():
        fortran = (ROOT / archive).read_bytes()
    else:
        raw = "https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/"
        with urlopen(raw+"bb7d1c50e2dc60eeefbadd9097a90d7762160df2/"+quote(archive), timeout=60) as stream:
            fortran = stream.read()
    require(digest(fortran) == "9c4b6d277af6643d2f199656e6aece7e478290368613b0bd9b5002f799b10fb1",
            "archived Fortran source fingerprint mismatch")
    summary.update(archived_fortran_sha256=digest(fortran), direct_external_calls=len(call_sites(secs, syms)),
                   text_relocations=len(secs[".text"]["relocs"]),
                   unwind_ranges=len(secs[".pdata"]["data"]) // 12)
    folder = ROOT / "handoff" / "inbox" / args.task
    recorded = json.loads((folder / "result.json").read_text(encoding="utf-8"))
    require(recorded == summary, "submitted coverage record disagrees with original")
    assembly = folder.parent / "COFF-BFDYLD" / "BFDYLD.s"
    assembler = args.assembler or shutil.which("clang") or shutil.which("zig")
    require(assembler, "provide --assembler with clang or zig on this machine")
    command = [str(Path(assembler).resolve())]
    if Path(assembler).stem.lower() == "zig":
        command += ["cc"]
    command += ["--target=x86_64-windows-gnu", "-g0", "-c", str(assembly)]
    with tempfile.TemporaryDirectory() as temp:
        obj = Path(temp)/"rebuilt.obj"
        subprocess.run(command+["-o", str(obj)], check=True)
        compare_objects(original, read_coff(obj.read_bytes()))
    print(json.dumps({**summary, "assembled_sections_and_relocations":"match"}))


if __name__ == "__main__":
    main()
