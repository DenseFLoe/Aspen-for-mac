"""Inventory and preserve installed supporting data without uploading binaries.

Standard SQLite and Access tables become JSONL. Textual engine data becomes
UTF-8. Unrecognized binary formats are preserved as reversible hex records and
explicitly reported as NOT semantically decoded.
"""
import argparse
import json
from pathlib import Path

from export_aspen_catalogs import dumps, export_sqlite, sha256, write_json, write_rows


def access_export(path, output):
    import pyodbc
    output.mkdir(parents=True, exist_ok=False)
    connection = pyodbc.connect("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ="
                                + str(path) + ";READONLY=TRUE;", readonly=True, autocommit=True)
    try:
        names = sorted(r.table_name for r in connection.cursor().tables(tableType="TABLE"))
        manifest = {"source": str(path), "format_version": 1, "schema": [], "tables": []}
        for number, name in enumerate(names):
            columns = list(connection.cursor().columns(table=name))
            definitions = []
            mapped = []
            for col in columns:
                kind = col.type_name.upper()
                sql_type = "INTEGER" if "INT" in kind else "REAL" if kind in ("DOUBLE", "SINGLE", "REAL") else "BLOB" if "BINARY" in kind else "TEXT"
                definitions.append('"' + col.column_name.replace('"', '""') + '" ' + sql_type)
                mapped.append({"name": col.column_name, "type": sql_type, "source_type": kind})
            ddl = 'CREATE TABLE "' + name.replace('"', '""') + '" (' + ','.join(definitions) + ')'
            manifest["schema"].append({"type": "table", "name": name, "sql": ddl})
            quoted = "[" + name.replace("]", "]]") + "]"
            count = connection.execute("SELECT COUNT(*) FROM " + quoted).fetchval()
            item = write_rows(output / f"table-{number:03d}.jsonl", connection.execute("SELECT * FROM " + quoted), count)
            item.update(table=name, columns=mapped)
            manifest["tables"].append(item)
        write_json(output / "manifest.json", manifest)
    finally:
        connection.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--resume", action="store_true", help="Verify and reuse completed per-source exports")
    parser.add_argument("--program-files", type=Path, default=Path("C:/Program Files/AspenTech"))
    parser.add_argument("--program-data", type=Path, default=Path("C:/ProgramData/AspenTech"))
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=args.resume)
    files = set()
    for root in (args.program_files, args.program_data):
        files.update(p for p in root.rglob("*") if p.is_file() and p.suffix.lower() in
                     (".sqlite", ".db", ".db3", ".sdf", ".mdb", ".accdb", ".mdf"))
    for product in ("AprSystem V15.0", "Aspen Plus V15.0"):
        files.update(p for p in (args.program_files / product / "Engine").rglob("*")
                     if p.is_file() and p.suffix.lower() in (".dat", ".fld", ".ppf", ".mix", ".ilb", ".sdf", ".rpd"))
    inventory = []
    for number, path in enumerate(sorted(files)):
        record = {"source": str(path), "source_bytes": path.stat().st_size}
        if path.parent.name == "APED V15.0" and path.suffix.lower() == ".mdf":
            record.update(status="exported_via_aped", output="../aped/" + path.stem,
                          hash_note="Online MDF is locked by SQL Server; exported table hashes are authoritative.")
        elif path.name in ("TDE9i.sqlite", "TIIS.sqlite", "TDE9m.sqlite", "TDE9r.sqlite") and path.parent.name == "Xeq":
            kind = "tde" if path.name in ("TDE9m.sqlite", "TDE9r.sqlite") else "auxiliary"
            record.update(status="exported_via_database_reader", output="../" + kind + "/" + path.name)
            record["source_sha256"] = sha256(path)
        else:
            record["source_sha256"] = sha256(path)
            target = args.output / f"source-{number:03d}"
            with path.open("rb") as stream:
                header = stream.read(16)
            completed = target / "manifest.json"
            reused = args.resume and completed.is_file()
            if reused:
                previous = json.loads(completed.read_text(encoding="utf-8"))
                if previous["source"] != str(path):
                    raise ValueError("Resume source mismatch")
                for item in previous["tables"]:
                    if sha256(target / item["file"]) != item["sha256"]:
                        raise ValueError("Resume checksum mismatch")
            if header == b"SQLite format 3\x00":
                if not reused:
                    export_sqlite(path, target)
                record.update(status="exported_sqlite", output=target.name)
            elif path.suffix.lower() in (".mdb", ".accdb"):
                if not reused:
                    access_export(path, target)
                record.update(status="exported_access", output=target.name)
            else:
                data = path.read_bytes()
                control_bytes = sum(value < 32 and value not in (9, 10, 12, 13) for value in data)
                text = None
                if not control_bytes:
                    for encoding in ("utf-8", "cp1252"):
                        try:
                            text = data.decode(encoding)
                            if text.encode(encoding) == data:
                                break
                        except UnicodeError:
                            text = None
                if text is not None:
                    target = target.with_suffix(".txt")
                    encoded = text.encode("utf-8")
                    if args.resume and target.exists():
                        if target.read_bytes() != encoded:
                            raise ValueError("Resume text mismatch")
                    else:
                        with target.open("xb") as stream:
                            stream.write(encoded)
                    record.update(status="exported_text", encoding=encoding, output=target.name)
                else:
                    target = target.with_suffix(".hex.jsonl")
                    if args.resume and target.exists():
                        recovered = bytearray()
                        for line in target.open(encoding="utf-8"):
                            row = json.loads(line)
                            if row["offset"] != len(recovered):
                                raise ValueError("Resume offset mismatch")
                            recovered.extend(bytes.fromhex(row["hex"]))
                        if recovered != data:
                            raise ValueError("Resume binary mismatch")
                    else:
                        with target.open("x", encoding="utf-8", newline="\n") as stream:
                            for offset in range(0, len(data), 32):
                                stream.write(dumps({"offset": offset, "hex": data[offset:offset + 32].hex()}) + "\n")
                    record.update(status="opaque_binary_preserved_as_hex", output=target.name,
                                  limitation="Lossless byte preservation only; record structure and numeric meanings are not decoded.")
                record.update(output_sha256=sha256(target), output_bytes=target.stat().st_size)
        inventory.append(record)
        print(path.name + ": " + record["status"], flush=True)
    write_json(args.output / "inventory.json", inventory)


if __name__ == "__main__":
    main()
