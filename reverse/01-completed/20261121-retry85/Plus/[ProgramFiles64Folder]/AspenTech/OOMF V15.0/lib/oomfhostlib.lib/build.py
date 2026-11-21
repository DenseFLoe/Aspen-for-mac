"""Assemble the three Win64 COFF members and restore both MS library indices."""
import argparse
from pathlib import Path
import struct
import subprocess


MEMBERS = (
    ("mysetenvqq", "-O0", ("MYSETENVQQ",)),
    ("close_his_rpt_file", "-Ox", ("CLOSE_HIS_RPT_FILE",)),
    ("open_his_rpt_file", "-Ox", ("OPEN_HIS_RPT_FILE", "DMOFIL", "DMO_STRLEN", "RESET_HIS_RPT_FILE", "DMO_LOWER")),
)


def names_table(names):
    return b"".join(name.encode("ascii") + b"\0" for name in names)


def archive_member(name, contents):
    header = f"{name:<16}{0:<12}{'':<6}{'':<6}{0:<8}{len(contents):<10}`\n".encode("ascii")
    return header + contents + (b"\n" if len(contents) % 2 else b"")


def make_library(objects):
    long_names = b""
    members = []
    indexed = []
    for index, ((stem, _, public), contents) in enumerate(zip(MEMBERS, objects, strict=True), 1):
        members.append(archive_member(f"/{len(long_names)}", contents))
        long_names += f"x64\\Release\\{stem}.obj".encode("ascii") + b"\0"
        indexed.extend((name, index) for name in public)
    ordered = sorted(indexed)
    count = len(indexed)

    def indices(offsets):
        first = struct.pack(f">{count+1}I", count, *(offsets[i-1] for _, i in indexed))
        first += names_table(name for name, _ in indexed)
        second = struct.pack(f"<{len(offsets)+2}I", len(offsets), *offsets, count)
        second += struct.pack(f"<{count}H", *(i for _, i in ordered))
        second += names_table(name for name, _ in ordered)
        return archive_member("/", first) + archive_member("/", second)

    magic = b"!<arch>\n"
    names = archive_member("//", long_names)
    pos = len(magic) + len(indices([0]*len(members))) + len(names)
    offsets = []
    for member in members:
        offsets.append(pos)
        pos += len(member)
    return magic + indices(offsets) + names + b"".join(members)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--nasm", default="nasm", help="NASM 3.02 executable")
    parser.add_argument("output", type=Path, help="directory for generated objects and library")
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    roots = Path(__file__).resolve().parent
    objects = []
    for stem, opt, _ in MEMBERS:
        output = args.output / (stem + ".obj")
        subprocess.run([args.nasm, "--reproducible", "-w+error", "-f", "win64", opt, "-o", str(output),
                        str(roots / "source" / (stem + ".asm"))], check=True)
        objects.append(output.read_bytes())
    (args.output / "oomfhostlib.lib").write_bytes(make_library(objects))


if __name__ == "__main__":
    main()
