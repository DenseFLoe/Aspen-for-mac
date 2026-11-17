"""Build a NEW read-only query database from verified Aspen V15 plaintext exports.

Standard library only. Source data is opened read-only; destinations must not
exist. This is a query catalog, not a thermodynamic parameter interpretation.
"""
import argparse
import hashlib
import json
import sqlite3
from decimal import Decimal, InvalidOperation
from pathlib import Path

VERSION = 1
DATABASES = ("APV150", "NISTV150", "APESV150", "FACTV150")


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def rows(path):
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            yield json.loads(line)


SCHEMA = """
CREATE TABLE metadata(key TEXT PRIMARY KEY, value TEXT NOT NULL);
CREATE TABLE sources(db TEXT, table_name TEXT, file TEXT, sha256 TEXT, row_count INTEGER, PRIMARY KEY(db,table_name));
CREATE TABLE compounds(db TEXT, id TEXT, name TEXT, alias TEXT, cas TEXT, PRIMARY KEY(db,id));
CREATE TABLE identifiers(db TEXT, compound_id TEXT, kind TEXT, value TEXT);
CREATE TABLE properties(db TEXT, id INTEGER, name TEXT, description TEXT, units TEXT, metadata TEXT, PRIMARY KEY(db,id));
CREATE TABLE parameters(db TEXT, cp_id INTEGER, compound_id TEXT, property_id INTEGER, PRIMARY KEY(db,cp_id));
CREATE TABLE databanks(db TEXT, id INTEGER, name TEXT, description TEXT, PRIMARY KEY(db,id));
CREATE TABLE refs(db TEXT, dbc_id INTEGER, cp_id INTEGER, bank_id INTEGER, PRIMARY KEY(db,dbc_id));
CREATE TABLE parameter_values(db TEXT, cp_id INTEGER, element_index INTEGER, value_text TEXT NOT NULL, PRIMARY KEY(db,cp_id,element_index));
CREATE TABLE citations(db TEXT, id INTEGER, record TEXT, PRIMARY KEY(db,id));
CREATE TABLE citation_links(db TEXT, dbc_id INTEGER, citation_id INTEGER);
CREATE TABLE notes(db TEXT, dbc_id INTEGER, note TEXT);
CREATE TABLE data_info(db TEXT, dbc_id INTEGER, record TEXT);
CREATE INDEX identifier_search ON identifiers(value COLLATE NOCASE);
CREATE INDEX identifier_owner ON identifiers(db,compound_id);
CREATE INDEX parameter_owner ON parameters(db,compound_id,property_id);
CREATE INDEX parameter_property ON parameters(db,property_id,compound_id);
CREATE INDEX ref_parameter ON refs(db,cp_id,bank_id);
CREATE INDEX citation_owner ON citation_links(db,dbc_id);
CREATE INDEX note_owner ON notes(db,dbc_id);
CREATE INDEX data_owner ON data_info(db,dbc_id);
CREATE TABLE compound_search_values(db TEXT,compound_id TEXT,property TEXT,cp_id INTEGER,element_index INTEGER,value_text TEXT,value_number REAL,PRIMARY KEY(db,cp_id,element_index));
CREATE INDEX compound_search_owner ON compound_search_values(db,compound_id,property);
"""


def build(source, destination, databases=DATABASES):
    source, destination = Path(source).resolve(), Path(destination).resolve()
    if destination == source or source in destination.parents:
        raise ValueError("Output must be outside the protected source package")
    # Exclusive directory reservation also refuses interrupted previous builds.
    destination.mkdir(parents=True, exist_ok=False)
    output = destination / "catalog.sqlite"
    provenance = []
    conn = sqlite3.connect(output)
    try:
        conn.executescript(SCHEMA)
        for db in databases:
            root = source / "aped" / db
            manifest = json.loads((root / "storage/manifest.json").read_text(encoding="utf-8"))
            if manifest.get("database") != db or manifest.get("format_version") != 1 or "decoded plaintext" not in manifest.get("value_storage_warning", ""):
                raise ValueError("Expected verified plaintext storage: " + db)
            provenance.append([db, "storage/manifest.json", digest(root / "storage/manifest.json")])
            tables = {t["table"]: t for t in manifest["tables"]}

            def verified(name):
                spec = tables[name]
                path = (root / "storage" / spec["file"]).resolve()
                if (root / "storage").resolve() not in path.parents or digest(path) != spec["sha256"]:
                    raise ValueError("Source path/checksum mismatch: " + name)
                count = 0
                for row in rows(path):
                    count += 1
                    yield row
                if count != spec["rows"]:
                    raise ValueError("Source row count mismatch: " + name)
                conn.execute("INSERT INTO sources VALUES (?,?,?,?,?)", (db, name, str(path.relative_to(source)), spec["sha256"], count))

            identifiers = {r["identId"]: r["identName"] for r in verified("active_Identifiers")}
            conn.executemany("INSERT INTO compounds VALUES (?,?,NULL,NULL,NULL)", ((db, str(r["compId"])) for r in verified("active_Compounds")))
            conn.executemany("INSERT INTO identifiers VALUES (?,?,?,?)", ((db, str(r["ciCompoundId"]), identifiers[r["ciIdentifierId"]], r["ciValue"]) for r in verified("active_CompoundIdentifiers")))
            for column, kind in (("name", "NAME"), ("alias", "ALIAS"), ("cas", "CASRN")):
                conn.execute(f"UPDATE compounds SET {column}=(SELECT value FROM identifiers i WHERE i.db=compounds.db AND i.compound_id=compounds.id AND i.kind=? ORDER BY value LIMIT 1) WHERE db=?", (kind, db))
            api_path = root / "api/properties.jsonl"
            provenance.append([db, "api/properties.jsonl", digest(api_path)])
            api = {r["property_id"]: r for r in rows(api_path)}
            conn.executemany("INSERT INTO properties VALUES (?,?,?,?,?,?)", ((db, r["propId"], r["propName"], r["propDescription"], json.dumps(api.get(r["propId"], {}).get("units", [])), json.dumps({"storage": r, "api": api.get(r["propId"])}, ensure_ascii=False)) for r in verified("active_Properties")))
            conn.executemany("INSERT INTO parameters VALUES (?,?,?,?)", ((db, r["cpId"], str(r["cpCompoundId"]), r["cpPropertyId"]) for r in verified("active_CompoundProperty")))
            conn.executemany("INSERT INTO databanks VALUES (?,?,?,?)", ((db, r["dbId"], r["dbName"], r["dbDescription"]) for r in verified("active_Databanks")))
            conn.executemany("INSERT INTO refs VALUES (?,?,?,?)", ((db, r["dbcId"], r["dbcCompoundPropId"], r["dbcDatabankId"]) for r in verified("active_DatabankCompounds")))

            def values():
                for r in verified("active_PropValueConst"):
                    if not isinstance(r["pvcValue"], str):
                        raise ValueError("Original decimal value must remain a string")
                    yield db, r["pvcCompoundPropId"], r["pvcIndex"], r["pvcValue"]
            conn.executemany("INSERT INTO parameter_values VALUES (?,?,?,?)", values())
            # Search-only scalars: use the API's declared single element, never
            # assume that the first stored cell is the property's scalar value.
            for prop_id, spec in api.items():
                name = spec.get("name")
                labels = spec.get("label_ij", [])
                if name not in ("MW", "TB") or spec.get("element_count") != 1 or len(labels) != 1:
                    continue
                if name == "TB" and not any(u.get("type") == "TEMPERATURE" and u.get("default_unit") == "K" for u in spec.get("units", [])):
                    continue
                scalar_rows = conn.execute("SELECT p.compound_id,p.cp_id,v.element_index,v.value_text FROM parameters p CROSS JOIN parameter_values v WHERE p.db=? AND p.property_id=? AND v.db=p.db AND v.cp_id=p.cp_id AND v.element_index=?", (db, prop_id, labels[0]))
                for compound_id, cp_id, element, text in scalar_rows:
                    try:
                        number = Decimal(text)
                    except InvalidOperation:
                        continue
                    # Aspen's missing sentinel is 1E35. Invalid/missing values
                    # remain intact in parameter_values, but cannot match ranges.
                    if not number.is_finite() or number <= 0 or number >= Decimal("1E34"):
                        continue
                    conn.execute("INSERT INTO compound_search_values VALUES (?,?,?,?,?,?,?)", (db, compound_id, name, cp_id, element, text, float(number)))
            if "active_PropValueText" in tables and "active_EnumerationValues" in tables:
                enums = {r["evId"]: r for r in verified("active_EnumerationValues")}
                class_ids = {r[0] for r in conn.execute("SELECT id FROM properties WHERE db=? AND name='COMPCLASS'", (db,))}
                class_parameters = {r[0]: (r[1], r[2]) for r in conn.execute("SELECT cp_id,compound_id,property_id FROM parameters WHERE db=? AND property_id IN (SELECT id FROM properties WHERE db=? AND name='COMPCLASS')", (db, db))}
                for r in verified("active_PropValueText"):
                    owner = class_parameters.get(r["pvtCompoundPropId"])
                    if owner is None:
                        continue
                    enum = enums.get(r["pvtEnumValueId"])
                    if enum is None or enum["evPropId"] not in class_ids or enum["evPropId"] != owner[1]:
                        raise ValueError("Broken compound class enumeration")
                    conn.execute("INSERT INTO compound_search_values VALUES (?,?,?,?,?,?,NULL)", (db, owner[0], "COMPCLASS", r["pvtCompoundPropId"], r["pvtIndex"], enum["evValue"]))
            conn.executemany("INSERT INTO citations VALUES (?,?,?)", ((db, r["citId"], json.dumps(r, ensure_ascii=False)) for r in verified("active_Citations")))
            conn.executemany("INSERT INTO citation_links VALUES (?,?,?)", ((db, r["dbcpcId"], r["dbcpcCitId"]) for r in verified("active_DbcpCitations")))
            conn.executemany("INSERT INTO notes VALUES (?,?,?)", ((db, r["dbcpnId"], r["dbcpnNote"]) for r in verified("active_DbcpNotes")))
            conn.executemany("INSERT INTO data_info VALUES (?,?,?)", ((db, r["dbcpeId"], json.dumps(r, ensure_ascii=False)) for r in verified("active_DbcpDataInfo")))
            conn.commit()
            print("Imported " + db, flush=True)
        # A build is valid only after every import and integrity check succeeds.
        for sql in (
            "SELECT 1 FROM parameters p LEFT JOIN compounds c ON c.db=p.db AND c.id=p.compound_id WHERE c.id IS NULL LIMIT 1",
            "SELECT 1 FROM parameter_values v LEFT JOIN parameters p ON p.db=v.db AND p.cp_id=v.cp_id WHERE p.cp_id IS NULL LIMIT 1",
            "SELECT 1 FROM refs r LEFT JOIN parameters p ON p.db=r.db AND p.cp_id=r.cp_id WHERE p.cp_id IS NULL LIMIT 1",
        ):
            if conn.execute(sql).fetchone():
                raise ValueError("Broken source relation")
        if conn.execute("PRAGMA integrity_check").fetchall() != [("ok",)]:
            raise ValueError("SQLite integrity check failed")
        dataset_id = "aspen-v15-" + hashlib.sha256(json.dumps(provenance, sort_keys=True).encode()).hexdigest()
        counts = {t: conn.execute("SELECT COUNT(*) FROM " + t).fetchone()[0] for t in ("compounds", "identifiers", "parameters", "parameter_values", "refs")}
        conn.executemany("INSERT INTO metadata VALUES (?,?)", (("schema_version", str(VERSION)), ("dataset_id", dataset_id), ("validation", "query-only-unverified-for-calculation"), ("compound_search_version", "1")))
        conn.commit()
    finally:
        conn.close()
    report = {"schema_version": VERSION, "dataset_id": dataset_id, "counts": counts, "sources": provenance, "sha256": digest(output)}
    (destination / "manifest.json").write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
    print(json.dumps({"output": str(output), "dataset_id": dataset_id, "counts": counts}), flush=True)
    return report


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("destination", type=Path)
    args = parser.parse_args()
    build(args.source, args.destination)
