# -*- coding: utf-8 -*-
"""Prove the value-reading path is covered: corrupting the row stride in read() must be visible."""
import struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
import cli_tables
from pe_reader import PE


def field_sample(data, off, mutate):
    T = cli_tables.read(data, off, _mutate_row_size=mutate)
    def val(table, idx, field):
        rows = T["rows"].get(table) or []
        return rows[idx][field] if idx < len(rows) else "<short>"
    return {
        "MemberRef[3].Class": val(10, 2, "Class"),
        "MemberRef[3].Name": val(10, 2, "Name"),
        "MethodDef[5].Flags": val(6, 4, "Flags"),
        "CustomAttribute[7].Type": val(12, 6, "Type"),
        "TypeDef[9].TypeName": val(2, 8, "TypeName"),
    }


def main():
    data = Path("_t13/orig/WrapSaveMergeNNFiles.dll").read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    normal = field_sample(data, off, False)
    broken = field_sample(data, off, True)
    diffs = [(k, normal[k], broken[k]) for k in normal if normal[k] != broken[k]]
    for k, a, b in diffs:
        print("LOCATED %s: normal=%r mutated=%r" % (k, a, b))
    print("read-mutate: fields=%d changed=%d" % (len(normal), len(diffs)))
    return 0 if diffs else 1


if __name__ == "__main__":
    sys.exit(main())
