"""Rebuild a portable SQLite database from a JSONL catalog or a TDE SQL export.

Python standard library only; works without Aspen, SQL Server, or Windows.
This creates a NEW database and validates row counts and SQLite integrity.
"""
import argparse
import base64
import json
import itertools
import sqlite3
import uuid
from pathlib import Path

from export_aspen_catalogs import sha256


def identifier(name):
    return '"' + name.replace('"', '""') + '"'


def untag(value):
    if isinstance(value, dict):
        if "$text_hex" in value:
            result = bytes.fromhex(value["$text_hex"])
            if len(result) != value["bytes"]:
                raise ValueError("Invalid UTF-8 TEXT length mismatch")
            return result
        if "$blob_base64" in value:
            result = base64.b64decode(value["$blob_base64"], validate=True)
            if len(result) != value["bytes"]:
                raise ValueError("BLOB length mismatch")
            return result
        if "$decimal" in value:
            return value["$decimal"]
        if "$iso8601" in value:
            return value["$iso8601"]
        raise ValueError("Unknown tagged field")
    return value


def execute_sql_file(connection, path):
    statement = ""
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            statement += line
            if line.rstrip().endswith(";") and sqlite3.complete_statement(statement):
                connection.execute(statement)
                statement = ""
    if statement.strip():
        raise ValueError("Incomplete SQL statement in " + str(path))


def restore(source, destination):
    manifest = json.loads((source / "manifest.json").read_text(encoding="utf-8"))
    # Reserve without truncating an existing file, including an empty one.
    with destination.open("xb"):
        pass
    connection = sqlite3.connect(destination)
    try:
        if (source / "schema.sql").is_file():
            execute_sql_file(connection, source / "schema.sql")
        for table in sorted(manifest["tables"], key=lambda t: t["table"] == "sqlite_sequence"):
            path = source / table["file"]
            if sha256(path) != table["sha256"]:
                raise ValueError("Checksum mismatch: " + table["file"])
            name = table["table"]
            if path.suffix == ".sql":
                execute_sql_file(connection, path)
            else:
                if "database" in manifest:
                    columns = [c for c in manifest["columns"] if c["TABLE_NAME"] == name]
                    names = [c["COLUMN_NAME"] for c in columns]
                    types = [{"int": "INTEGER", "bit": "INTEGER", "bigint": "INTEGER",
                              "float": "REAL", "real": "REAL", "binary": "BLOB", "varbinary": "BLOB"}
                             .get(c["DATA_TYPE"], "TEXT") for c in columns]
                    connection.execute("CREATE TABLE " + identifier(name) + " (" +
                                       ",".join(identifier(n) + " " + t for n, t in zip(names, types)) + ")")
                else:
                    ddl = next(item["sql"] for item in manifest["schema"] if item["type"] == "table" and item["name"] == name)
                    if name == "sqlite_sequence":
                        if not connection.execute("SELECT 1 FROM sqlite_master WHERE name='sqlite_sequence'").fetchone():
                            temporary = "export_sequence_" + uuid.uuid4().hex
                            connection.execute("CREATE TABLE " + temporary + " (id INTEGER PRIMARY KEY AUTOINCREMENT)")
                            connection.execute("DROP TABLE " + temporary)
                        connection.execute("DELETE FROM sqlite_sequence")
                    else:
                        connection.execute(ddl)
                    names = [c["name"] for c in table["columns"]]
                prefix = "INSERT INTO " + identifier(name) + " (" + ",".join(map(identifier, names)) + ") VALUES ("
                with path.open(encoding="utf-8") as stream:
                    def records():
                        for line in stream:
                            row = json.loads(line)
                            if set(row) != set(names):
                                raise ValueError("Unexpected columns")
                            yield [row[n] for n in names]
                    def mask(row):
                        return tuple(isinstance(v, dict) and "$text_hex" in v for v in row)
                    for typed, group in itertools.groupby(records(), mask):
                        query = prefix + ",".join("CAST(? AS TEXT)" if raw else "?" for raw in typed) + ")"
                        connection.executemany(query, (tuple(untag(v) for v in row) for row in group))
            actual = connection.execute("SELECT COUNT(*) FROM " + identifier(name)).fetchone()[0]
            if actual != table["rows"]:
                raise ValueError("Restored row count mismatch: " + name)
            connection.commit()
            print(f"Restored {name}: {actual}", flush=True)
        if (source / "post-schema.sql").is_file():
            execute_sql_file(connection, source / "post-schema.sql")
        elif "database" not in manifest:
            for item in manifest["schema"]:
                if item["type"] != "table" and item.get("sql"):
                    connection.execute(item["sql"])
        if "database" in manifest:
            for table, column in (("active_CompoundProperty", "cpId"),
                                  ("active_DatabankCompounds", "dbcCompoundPropId"),
                                  ("active_PropValueConst", "pvcCompoundPropId"),
                                  ("active_CompoundIdentifiers", "ciCompoundId")):
                connection.execute("CREATE INDEX " + identifier("export_" + column) + " ON " + identifier(table) + " (" + identifier(column) + ")")
        connection.commit()
        if connection.execute("PRAGMA integrity_check").fetchall() != [("ok",)]:
            raise ValueError("Restored SQLite integrity check failed")
    finally:
        connection.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("destination", type=Path)
    args = parser.parse_args()
    restore(args.source, args.destination)


if __name__ == "__main__":
    main()
