"""Export TDE9r/m via the installed TDE.dll's database reader, on LOCAL COPIES.

Windows x64 / Aspen V15 ABI only. No passwords, keys, or native implementation
are extracted. Only SELECT/PRAGMA queries run. Output is standard SQLite SQL;
text is readable, while BLOB and embedded-NUL values use lossless SQL hex.
"""
import argparse
import ctypes as ct
import os
from pathlib import Path

from export_aspen_catalogs import sha256, write_json


def identifier(value):
    return '"' + value.replace('"', '""') + '"'


def literal(value):
    return "'" + value.replace("'", "''") + "'"


class TdeReader:
    def __init__(self, library, source):
        if ct.sizeof(ct.c_void_p) != 8:
            raise RuntimeError("Requires a 64-bit Python process")
        for name in ("TDE9r.sqlite", "TDE9m.sqlite", "TIIS.sqlite"):
            if not (source / name).is_file() or (source / name).stat().st_size == 0:
                raise FileNotFoundError("Local copy required: " + name)
        # The vendor library resolves its three input files against cwd. Refuse
        # missing copies to prevent it from creating an empty database instead.
        self.old_cwd = Path.cwd()
        os.chdir(source)
        self.dll_directory = os.add_dll_directory(str(library.parent))
        self.dll = ct.CDLL(str(library))
        self.connection = self.bind("?GetConnection@@YAPEAVConnectionClass@@H@Z", ct.c_void_p, [ct.c_int])
        self.ctor = self.bind("??0RecordSetClass@@QEAA@XZ", ct.c_void_p, [ct.c_void_p])
        self.dtor = self.bind("??1RecordSetClass@@QEAA@XZ", None, [ct.c_void_p])
        self.initialize = self.bind("?Initialize@RecordSetClass@@QEAA_NPEAVConnectionClass@@PEBD_N2@Z",
                                   ct.c_bool, [ct.c_void_p, ct.c_void_p, ct.c_char_p, ct.c_bool, ct.c_bool])
        self.eof = self.bind("?Eof@RecordSetClass@@QEAA_NXZ", ct.c_bool, [ct.c_void_p])
        self.next = self.bind("?MoveNext@RecordSetClass@@QEAAXXZ", None, [ct.c_void_p])
        self.size = self.bind("?ArraySize@RecordSetClass@@QEAAJPEBD@Z", ct.c_long, [ct.c_void_p, ct.c_char_p])
        self.copy = self.bind("?CopyCharArray@RecordSetClass@@QEAAXPEADPEBD_N@Z", None,
                              [ct.c_void_p, ct.c_void_p, ct.c_char_p, ct.c_bool])
        self.missing = self.bind("?IsMissing@RecordSetClass@@QEAA_NPEBD@Z", ct.c_bool,
                                 [ct.c_void_p, ct.c_char_p])

    def bind(self, name, result, arguments):
        function = getattr(self.dll, name)
        function.restype = result
        function.argtypes = arguments
        return function

    def rows(self, slot, query, columns):
        if not query.startswith(("SELECT ", "PRAGMA ")):
            raise ValueError("Only read queries are supported")
        # Overallocated, zero-initialized storage for the V15 exported wrapper.
        # Construction/destruction are performed by the same installed DLL.
        recordset = ct.create_string_buffer(4096)
        self.ctor(recordset)
        try:
            for attempt in range(3):
                if self.initialize(recordset, self.connection(slot), query.encode("utf-8"), False, False):
                    break
                if attempt == 2:
                    raise RuntimeError("TDE query initialization failed")
                self.dtor(recordset)
                self.ctor(recordset)
            while not self.eof(recordset):
                row = []
                for column in columns:
                    name = column.encode("utf-8")
                    if self.missing(recordset, name):
                        row.append(None)
                        continue
                    size = self.size(recordset, name)
                    if size < 0 or size > 128 * 1024 * 1024:
                        raise RuntimeError("Unexpected native field size")
                    buffer = ct.create_string_buffer(size + 1)
                    self.copy(recordset, buffer, name, False)
                    row.append(buffer.raw[:size].decode("utf-8"))
                yield row
                self.next(recordset)
        finally:
            self.dtor(recordset)

    def scalar(self, slot, query):
        return next(self.rows(slot, query, ["data"]))[0]

    def close(self):
        os.chdir(self.old_cwd)
        self.dll_directory.close()


def export(reader, slot, source, output):
    output.mkdir(parents=True, exist_ok=False)
    files = list(reader.rows(slot, "PRAGMA database_list", ["name", "file"]))
    actual = next(Path(path).resolve() for name, path in files if name == "main")
    if actual != source.resolve():
        raise RuntimeError("TDE resolved an unexpected source file")
    source_hash = sha256(source)
    schema = [dict(zip(("type", "name", "sql"), row)) for row in reader.rows(slot,
        "SELECT type,name,sql FROM sqlite_master WHERE sql IS NOT NULL ORDER BY type,name", ["type", "name", "sql"])]
    tables = [item for item in schema if item["type"] == "table"]
    manifest = {"format_version": 1, "source": source.name, "source_sha256": source_hash,
                "native_sqlite_version": reader.scalar(slot, "SELECT sqlite_version() AS data"),
                "tables": [], "schema": schema}
    with (output / "schema.sql").open("x", encoding="utf-8", newline="\n") as stream:
        for item in tables:
            stream.write(item["sql"] + ";\n")
    with (output / "post-schema.sql").open("x", encoding="utf-8", newline="\n") as stream:
        for item in schema:
            if item["type"] != "table":
                stream.write(item["sql"] + ";\n")
    for number, table in enumerate(tables):
        name = table["name"]
        quoted = identifier(name)
        columns = [row[0] for row in reader.rows(slot, "PRAGMA table_info(" + quoted + ")", ["name"])]
        count = int(reader.scalar(slot, "SELECT CAST(COUNT(*) AS TEXT) AS data FROM " + quoted))
        # quote() alone truncates strings containing NUL; use a typed hex literal
        # for those strings only. BLOBs are already preserved by SQLite quote().
        terms = []
        for column in columns:
            col = identifier(column)
            terms.append("CASE WHEN typeof(" + col + ")='text' AND instr(" + col + ",char(0))>0 "
                         "THEN 'CAST(X'''||hex(" + col + ")||''' AS TEXT)' ELSE quote(" + col + ") END")
        expression = literal("INSERT INTO " + quoted + " VALUES(") + "||" + "||','||".join(terms) + "||');'"
        target = output / f"table-{number:03d}.sql"
        written = 0
        # Native recordsets materialize results. Bound each query to avoid loading
        # a multi-million-row database in memory; rowid keyset paging avoids OFFSET.
        last = None
        with target.with_suffix(".sql.partial").open("x", encoding="utf-8", newline="\n") as stream:
            while written < count:
                where = "" if last is None else " WHERE rowid>" + str(last)
                query = "SELECT CAST(rowid AS TEXT) AS row_id," + expression + " AS data FROM " + quoted + where + " ORDER BY rowid LIMIT 2000"
                batch = list(reader.rows(slot, query, ["row_id", "data"]))
                if not batch:
                    break
                for row_id, statement in batch:
                    stream.write(statement + "\n")
                    last = int(row_id)
                    written += 1
            if written != count:
                raise RuntimeError("TDE row count mismatch: " + name)
        target.with_suffix(".sql.partial").rename(target)
        manifest["tables"].append({"table": name, "file": target.name, "rows": count,
                                    "bytes": target.stat().st_size, "sha256": sha256(target)})
        print(f"{source.name}.{name}: {count}", flush=True)
    integrity = list(reader.rows(slot, "PRAGMA integrity_check", ["integrity_check"]))
    if integrity != [["ok"]]:
        raise RuntimeError("TDE source integrity check failed")
    if sha256(source) != source_hash:
        raise RuntimeError("TDE source copy changed")
    manifest["integrity_check"] = "ok"
    manifest["source_unchanged"] = True
    write_json(output / "manifest.json", manifest)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source-directory", type=Path, required=True, help="Scratch directory containing all three local copies")
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--library", type=Path, default=Path("C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/TDE.dll"))
    args = parser.parse_args()
    source, output = args.source_directory.resolve(), args.output.resolve()
    if output.exists():
        raise FileExistsError(output)
    reader = TdeReader(args.library.resolve(), source)
    try:
        for slot, name in ((0, "TDE9m.sqlite"), (2, "TDE9r.sqlite")):
            export(reader, slot, source / name, output / name)
    finally:
        reader.close()


if __name__ == "__main__":
    main()
