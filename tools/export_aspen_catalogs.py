"""Export local Aspen data tables as UTF-8 JSONL without copying database binaries.

SQL uses Windows integrated authentication and SELECT only. Configuration and
administrative tables are inventoried by name/count, never read for secrets.
The raw APED value table is explicitly marked encoded storage, NOT plaintext
thermodynamic values; pair it with the installed-API export and coverage report.
"""
import argparse
import base64
import datetime
import decimal
import hashlib
import json
import sqlite3
from pathlib import Path

DATABASES = ("APV150", "NISTV150", "APESV150", "FACTV150")


def tagged(value):
    if isinstance(value, bytes):
        return {"$blob_base64": base64.b64encode(value).decode("ascii"), "bytes": len(value)}
    if isinstance(value, decimal.Decimal):
        return {"$decimal": str(value)}
    if isinstance(value, (datetime.datetime, datetime.date, datetime.time)):
        return {"$iso8601": value.isoformat(), "type": type(value).__name__}
    raise TypeError(type(value).__name__)


def dumps(value):
    return json.dumps(value, ensure_ascii=False, allow_nan=False, default=tagged, separators=(",", ":"))


def sqlite_text(value):
    try:
        return value.decode("utf-8")
    except UnicodeDecodeError:
        return {"$text_hex": value.hex(), "bytes": len(value)}


def write_json(path, value):
    with path.open("x", encoding="utf-8", newline="\n") as stream:
        stream.write(dumps(value) + "\n")


def sha256(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def write_rows(path, cursor, expected):
    names = [column[0] for column in cursor.description]
    count = 0
    temporary = path.with_suffix(path.suffix + ".partial")
    with temporary.open("x", encoding="utf-8", newline="\n") as stream:
        for row in cursor:
            stream.write(dumps(dict(zip(names, row))) + "\n")
            count += 1
    if count != expected:
        raise RuntimeError(f"Row count mismatch for {path.name}: {count} != {expected}")
    if path.exists():
        raise FileExistsError(path)
    temporary.rename(path)
    return {"file": path.name, "rows": count, "bytes": path.stat().st_size, "sha256": sha256(path)}


def connect(database):
    import pyodbc
    if database not in DATABASES:
        raise ValueError("Unexpected database")
    return pyodbc.connect("DRIVER={ODBC Driver 17 for SQL Server};SERVER=.;DATABASE="
                          + database + ";Trusted_Connection=yes;Encrypt=no;",
                          readonly=True, autocommit=True, timeout=10)


def records(cursor):
    names = [column[0] for column in cursor.description]
    return [dict(zip(names, row)) for row in cursor]


def export_sql(database, output):
    output.mkdir(parents=True, exist_ok=False)
    connection = connect(database)
    try:
        tables = records(connection.execute("""
            SELECT SCHEMA_NAME(schema_id) AS [schema],name FROM sys.tables ORDER BY name
        """))
        schema = records(connection.execute("""
            SELECT TABLE_SCHEMA,TABLE_NAME,COLUMN_NAME,DATA_TYPE,ORDINAL_POSITION,
                   IS_NULLABLE,CHARACTER_MAXIMUM_LENGTH,NUMERIC_PRECISION,NUMERIC_SCALE
            FROM INFORMATION_SCHEMA.COLUMNS ORDER BY TABLE_NAME,ORDINAL_POSITION
        """))
        constraints = records(connection.execute("""
            SELECT OBJECT_NAME(fkc.parent_object_id) AS table_name,
                COL_NAME(fkc.parent_object_id,fkc.parent_column_id) AS column_name,
                OBJECT_NAME(fkc.referenced_object_id) AS target_table,
                COL_NAME(fkc.referenced_object_id,fkc.referenced_column_id) AS target_column
            FROM sys.foreign_key_columns fkc ORDER BY table_name,column_name
        """))
        result = {"database": database, "format_version": 1, "tables": [],
                  "columns": schema, "foreign_keys": constraints, "excluded": [],
                  "value_storage_warning": "active_PropValueConst contains encoded source strings. "
                  "Use api/parameters.jsonl for decoded values; do not use these strings as coefficients."}
        for table in tables:
            name = table["name"]
            quoted = "[" + table["schema"].replace("]", "]]") + "].[" + name.replace("]", "]]") + "]"
            expected = connection.execute("SELECT COUNT_BIG(*) FROM " + quoted).fetchval()
            if not name.startswith("active_"):
                result["excluded"].append({"table": name, "rows": expected,
                                           "reason": "administrative_or_inactive_table"})
                continue
            cursor = connection.execute("SELECT * FROM " + quoted)
            entry = write_rows(output / (name + ".jsonl"), cursor, expected)
            after = connection.execute("SELECT COUNT_BIG(*) FROM " + quoted).fetchval()
            if after != expected:
                raise RuntimeError("Source changed during export: " + name)
            entry["table"] = name
            entry["status"] = "encoded_source_storage" if name == "active_PropValueConst" else "exported"
            result["tables"].append(entry)
            print(f"{database}.{name}: {expected}", flush=True)
        write_json(output / "manifest.json", result)
    finally:
        connection.close()


def export_sqlite(path, output):
    output.mkdir(parents=True, exist_ok=False)
    connection = sqlite3.connect(path.resolve().as_uri() + "?mode=ro", uri=True)
    connection.text_factory = sqlite_text
    try:
        connection.execute("PRAGMA query_only=ON")
        connection.execute("BEGIN")
        schema = records(connection.execute("SELECT type,name,tbl_name,sql FROM sqlite_master ORDER BY type,name"))
        result = {"source": str(path), "format_version": 1, "schema": schema, "tables": [],
                  "blob_note": "Binary fields use tagged base64, not decoded scientific values."}
        for item in schema:
            if item["type"] != "table":
                continue
            name = item["name"]
            quoted = '"' + name.replace('"', '""') + '"'
            count = connection.execute("SELECT COUNT(*) FROM " + quoted).fetchone()[0]
            filename = f"table-{len(result['tables']):03d}.jsonl"
            entry = write_rows(output / filename, connection.execute("SELECT * FROM " + quoted), count)
            entry["table"] = name
            entry["columns"] = records(connection.execute("PRAGMA table_info(" + quoted + ")"))
            entry["foreign_keys"] = records(connection.execute("PRAGMA foreign_key_list(" + quoted + ")"))
            result["tables"].append(entry)
            print(f"{path.name}.{name}: {count}", flush=True)
        integrity = connection.execute("PRAGMA integrity_check").fetchall()
        if integrity != [("ok",)]:
            raise RuntimeError("SQLite integrity check failed")
        result["integrity_check"] = "ok"
        write_json(output / "manifest.json", result)
    finally:
        connection.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", required=True, type=Path)
    source = parser.add_mutually_exclusive_group(required=True)
    source.add_argument("--database", choices=DATABASES)
    source.add_argument("--sqlite", type=Path)
    args = parser.parse_args()
    if args.database:
        export_sql(args.database, args.output)
    else:
        export_sqlite(args.sqlite, args.output)


if __name__ == "__main__":
    main()
