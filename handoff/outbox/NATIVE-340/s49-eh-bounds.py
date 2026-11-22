import hashlib
import json
from pathlib import Path
import struct
import sys

root = Path(sys.argv[1]).resolve()
sys.path.insert(0, str(root / "tool"))
import method_body
from audit_340_s49 import eh_chain_tests

class PE:
    def __init__(self, data_size):
        self.secs = [dict(raw=0, rva=0x2400, size=data_size, vsize=data_size, exec=True, name=".text")]

    def filepos(self, rva):
        if not (0x2400 <= rva < 0x2400 + self.secs[0]["size"]):
            raise ValueError("unmapped RVA")
        return rva - 0x2400


def case(count, missing=False):
    code = bytes([0, 0xDE, 1, 0xDC]) * count + b"\x2a"
    buf = bytearray(struct.pack("<HHII", 0x300B, 8, len(code), 0) + code)
    buf += bytes(-len(buf) % 4)
    for i in range(count):
        fat = i % 2 != 0
        kind = 1 | (0x40 if fat else 0) | (0x80 if i + 1 < count else 0)
        row = (2, 4 * i, 3, 4 * i + 3, 1, 0)
        clause = struct.pack("<IIIIII" if fat else "<HHBHBI", *row)
        buf.extend(bytes([kind, 4 + len(clause), 0, 0]) + clause)
    limit = len(buf) - (4 if missing else 0)
    pe = PE(limit)
    rec = dict(count=count, mapped_file_bytes=limit, physical_file_bytes=len(buf),
               filesize_sha256=hashlib.sha256(buf).hexdigest())
    try:
        header, eh, clauses = method_body.read(buf, pe, 0x2400)
        rec.update(sections=eh["section_count"], clauses=len(clauses),
                   offsets=[c["try_offset"] for c in clauses], status="accepted")
    except (ValueError, IndexError, struct.error) as e:
        rec.update(status="rejected", error=str(e))
    return rec


print(json.dumps(dict(head="ac9d6b69cdcfe99f9b2147e0c8c12f01787bae93",
                      parser_sha256=hashlib.sha256((root / "tool/method_body.py").read_bytes()).hexdigest(),
                      candidate_eh_tests=eh_chain_tests(),
                      existing_parser_suite=method_body.synthetic_tests(),
                      independent=[case(9), case(10), case(10, True)]), indent=2))
