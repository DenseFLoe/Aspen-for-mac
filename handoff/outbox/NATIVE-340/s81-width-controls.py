"""Replay width boundaries against the fixed candidate parser (pefile-free)."""
from hashlib import sha256
import importlib
import json
from pathlib import Path
import struct
import sys

def metadata_fixture(counts, tables):
    # ECMA-335 table stream with 16-bit heaps. Unknown rows use explicit zeroes.
    valid = sum(1 << index for index in counts)
    stream = struct.pack("<IBBBBQQ", 0, 2, 0, 0, 1, valid, 0)
    stream += b"".join(struct.pack("<I", counts[index]) for index in sorted(counts))
    stream += b"".join(tables[index] for index in sorted(tables))
    version = b"v4.0\0\0\0\0"
    strings = b"\0" + bytes(16) + b"MethodName\0"
    header = struct.pack("<IHHII", 0x424A5342, 1, 1, 0, len(version)) + version + struct.pack("<HH", 0, 2)
    offset = len(header) + 32
    headers = struct.pack("<II", offset, len(stream)) + b"#~\0\0"
    headers += struct.pack("<II", offset + len(stream), len(strings)) + b"#Strings\0\0\0\0"
    return header + headers + stream + strings


def widths(cli_tables):
    results = []
    for count in (8191, 8192):
        parent = (count << 3) | 1
        code = struct.pack("<H" if count < 8192 else "<I", parent)
        data = metadata_fixture({1: count, 10: 1}, {1: bytes(count * 6), 10: code + struct.pack("<HH", 17, 29)})
        observed = cli_tables.read(data, 0)["rows"][10][0]
        results.append({"table": "MemberRef", "target_count": count, "input_sha256": sha256(data).hexdigest(),
                        "expected": {"Class": parent, "Name": "MethodName", "Signature": 29}, "observed": observed})
    for count in (16383, 16384, 32768):
        code = "<H" if count < 32768 else "<I"
        body, declaration = 2, 4
        data = metadata_fixture({6: count, 25: 1}, {6: bytes(count * 14),
                                     25: struct.pack("<H", 1) + struct.pack(code, body) + struct.pack(code, declaration)})
        observed = cli_tables.read(data, 0)["rows"][25][0]
        results.append({"table": "MethodImpl", "target_count": count, "input_sha256": sha256(data).hexdigest(),
                        "expected": {"Class": 1, "MethodBody": body, "MethodDeclaration": declaration},
                        "observed": observed})
    for row in results:
        row["match"] = all(row["observed"][key] == value for key, value in row["expected"].items())
    return results



if __name__ == "__main__":
    candidate = Path(sys.argv[1]).resolve()
    sys.path.insert(0, str(candidate / "tool"))
    parser = importlib.import_module("cli_tables")
    results = widths(parser)
    for count in (8191, 8192):
        raw_type = (count << 3) | 2
        data = metadata_fixture({6: count, 12: 1}, {
            6: bytes(14 * count),
            12: struct.pack("<I", 32) + struct.pack("<H" if count < 8192 else "<I", raw_type)
                + struct.pack("<H", 29),
        })
        observed = parser.read(data, 0)["rows"][12][0]
        expected = {"Parent": 32, "Type": raw_type, "Value": 29}
        results.append({"table": "CustomAttributeType", "target_count": count,
                        "input_sha256": sha256(data).hexdigest(), "expected": expected,
                        "observed": observed,
                        "match": all(observed[key] == val for key, val in expected.items())})
    print(json.dumps(results, indent=2))
