"""Replay the nine- and ten-section s45 evidence against a fixed candidate."""
import argparse
import hashlib
from pathlib import Path
import struct
import sys


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--candidate", type=Path, required=True)
    options = parser.parse_args()
    sys.path.insert(0, str(options.candidate.resolve() / "tool"))
    import method_body

    for count in (9, 10):
        rva = 0x1000
        data = bytearray(0x3000)
        # Each try contains nop and leave.s; each finally contains endfinally.
        code = bytes([0, 0xDE, 1, 0xDC]) * count + bytes([0x2A])
        struct.pack_into("<HHII", data, rva, 0x300B, 8, len(code), 0)
        data[rva + 12:rva + 12 + len(code)] = code
        section_rva = (rva + 12 + len(code) + 3) & ~3
        for index in range(count):
            kind = 0x41 if index == count - 1 else 0xC1
            struct.pack_into("<BBBBIIIIII", data, section_rva, kind, 28, 0, 0,
                             2, index * 4, 3, index * 4 + 3, 1, 0)
            section_rva += 28
        pe = method_body._FakePE(data, [
            dict(rva=rva, size=0x1000, raw=rva, vsize=0x1000, exec=True, name=".text")
        ])
        header = method_body.header(data, pe, rva)
        sections = method_body.data_sections(bytes(data), pe, header)
        print(f"{hashlib.sha256(data).hexdigest()} expected={count} "
              f"returned={len(sections)} last_more={sections[-1]['more']}")


if __name__ == "__main__":
    main()
