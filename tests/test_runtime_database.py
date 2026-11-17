"""Synthetic data only: no installed Aspen data is distributed with tests."""
from contextlib import closing
import json
import sqlite3
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from build_runtime_database import build, digest


def fixture(root, database):
    storage = root / "aped" / database / "storage"
    storage.mkdir(parents=True)
    tables = {
        "active_Identifiers": [{"identId": 2, "identName": "NAME"}, {"identId": 5, "identName": "SYNONYM"}],
        "active_Compounds": [{"compId": 1}],
        "active_CompoundIdentifiers": [{"ciCompoundId": 1, "ciIdentifierId": 2, "ciValue": "TEST-WATER"}, {"ciCompoundId": 1, "ciIdentifierId": 5, "ciValue": "中文别名"}],
        "active_Properties": [{"propId": 3, "propName": "TEST", "propDescription": "Synthetic parameter"}],
        "active_CompoundProperty": [{"cpId": 7, "cpCompoundId": 1, "cpPropertyId": 3}],
        "active_Databanks": [{"dbId": 9, "dbName": "SYNTHETIC", "dbDescription": "Test only"}],
        "active_DatabankCompounds": [{"dbcId": 11, "dbcCompoundPropId": 7, "dbcDatabankId": 9}],
        "active_PropValueConst": [{"pvcCompoundPropId": 7, "pvcIndex": 100, "pvcValue": "123.456789012345678901"}],
        "active_Citations": [{"citId": 12, "citTitle": "Synthetic provenance"}],
        "active_DbcpCitations": [{"dbcpcId": 11, "dbcpcCitId": 12}],
        "active_DbcpNotes": [{"dbcpnId": 11, "dbcpnNote": "No calculation claim"}],
        "active_DbcpDataInfo": [{"dbcpeId": 11, "dbcpeDataType": "test"}],
    }
    specs = []
    for name, data in tables.items():
        path = storage / (name + ".jsonl")
        path.write_text("".join(json.dumps(r, ensure_ascii=False) + "\n" for r in data), encoding="utf-8")
        specs.append({"table": name, "file": path.name, "rows": len(data), "sha256": digest(path)})
    (storage / "manifest.json").write_text(json.dumps({"database": database, "format_version": 1, "value_storage_warning": "pvcValue is decoded plaintext.", "tables": specs}), encoding="utf-8")
    api = storage.parent / "api"
    api.mkdir()
    (api / "properties.jsonl").write_text(json.dumps({"property_id": 3, "units": [{"type": "TEST-UNIT", "default_unit": "unit"}], "labels": ["X"], "label_ij": [100]}) + "\n", encoding="utf-8")


class RuntimeDatabaseTest(unittest.TestCase):
    def test_search_index_uses_declared_scalar_units_and_enumerations(self):
        with tempfile.TemporaryDirectory() as tmp:
            source, output = Path(tmp) / "source", Path(tmp) / "runtime"
            fixture(source, "APV150")
            storage = source / "aped/APV150/storage"
            manifest = json.loads((storage / "manifest.json").read_text())

            def table(name, records):
                path = storage / (name + ".jsonl")
                path.write_text("".join(json.dumps(r) + "\n" for r in records), encoding="utf-8")
                manifest["tables"] = [t for t in manifest["tables"] if t["table"] != name]
                manifest["tables"].append({"table": name, "file": path.name, "rows": len(records), "sha256": digest(path)})

            table("active_Properties", [{"propId": i, "propName": name, "propDescription": name} for i, name in ((1, "COMPCLASS"), (354, "MW"), (549, "TB"))])
            table("active_CompoundProperty", [{"cpId": i, "cpCompoundId": 1, "cpPropertyId": prop} for i, prop in ((7, 354), (8, 549), (9, 1), (10, 354), (11, 354))])
            table("active_PropValueConst", [
                {"pvcCompoundPropId": 7, "pvcIndex": 1386, "pvcValue": "18.015300000000000001"},
                {"pvcCompoundPropId": 7, "pvcIndex": 0, "pvcValue": "999"},
                {"pvcCompoundPropId": 8, "pvcIndex": 1885, "pvcValue": "373.15"},
                {"pvcCompoundPropId": 10, "pvcIndex": 1386, "pvcValue": "1E35"},
                {"pvcCompoundPropId": 11, "pvcIndex": 1386, "pvcValue": "invalid"}])
            table("active_EnumerationValues", [{"evId": 4, "evPropId": 1, "evIndex": 0, "evValue": "Synthetic class"}])
            table("active_PropValueText", [{"pvtCompoundPropId": 9, "pvtIndex": 0, "pvtEnumValueId": 4}])
            (storage / "manifest.json").write_text(json.dumps(manifest), encoding="utf-8")
            api = storage.parent / "api/properties.jsonl"
            api.write_text("\n".join(json.dumps(r) for r in [
                {"property_id": 354, "name": "MW", "element_count": 1, "label_ij": [1386]},
                {"property_id": 549, "name": "TB", "element_count": 1, "label_ij": [1885], "units": [{"type": "TEMPERATURE", "default_unit": "K"}]}]) + "\n", encoding="utf-8")
            before = {str(p): digest(p) for p in source.rglob("*") if p.is_file()}
            build(source, output, ("APV150",))
            with closing(sqlite3.connect(output / "catalog.sqlite")) as conn:
                self.assertEqual(conn.execute("SELECT property,value_text FROM compound_search_values ORDER BY cp_id").fetchall(), [("MW", "18.015300000000000001"), ("TB", "373.15"), ("COMPCLASS", "Synthetic class")])
                self.assertEqual(conn.execute("SELECT count(*) FROM parameter_values").fetchone()[0], 5)
                self.assertEqual(conn.execute("SELECT value FROM metadata WHERE key='compound_search_version'").fetchone()[0], "1")
            self.assertEqual(before, {str(p): digest(p) for p in source.rglob("*") if p.is_file()})
            # Without verified Kelvin metadata, TB remains available as raw data
            # but is not eligible for temperature range comparisons.
            specs = [json.loads(line) for line in api.read_text().splitlines()]
            specs[1]["units"] = []
            api.write_text("\n".join(json.dumps(r) for r in specs) + "\n")
            build(source, Path(tmp) / "no-units", ("APV150",))
            with closing(sqlite3.connect(Path(tmp) / "no-units/catalog.sqlite")) as conn:
                self.assertEqual(conn.execute("SELECT count(*) FROM compound_search_values WHERE property='TB'").fetchone()[0], 0)

    def test_exact_values_namespaced_identity_provenance_and_no_overwrite(self):
        with tempfile.TemporaryDirectory() as tmp:
            source, output = Path(tmp) / "source", Path(tmp) / "runtime"
            for db in ("APV150", "NISTV150"):
                fixture(source, db)
            before = {str(p): digest(p) for p in source.rglob("*") if p.is_file()}
            report = build(source, output, ("APV150", "NISTV150"))
            self.assertEqual(report["counts"]["parameter_values"], 2)
            with closing(sqlite3.connect((output / "catalog.sqlite").as_uri() + "?mode=ro", uri=True)) as conn:
                self.assertEqual(conn.execute("SELECT value_text FROM parameter_values").fetchall(), [("123.456789012345678901",)] * 2)
                self.assertEqual(conn.execute("SELECT count(*) FROM compounds WHERE id='1'").fetchone()[0], 2)
                self.assertEqual(conn.execute("SELECT value FROM identifiers WHERE kind='SYNONYM'").fetchone()[0], "中文别名")
                self.assertIn("Synthetic provenance", conn.execute("SELECT record FROM citations").fetchone()[0])
                self.assertEqual(conn.execute("SELECT count(*) FROM sources").fetchone()[0], 24)
                with self.assertRaises(sqlite3.OperationalError):
                    conn.execute("DELETE FROM compounds")
            with self.assertRaises(FileExistsError):
                build(source, output, ("APV150",))
            with self.assertRaises(ValueError):
                build(source, source / "forbidden", ("APV150",))
            self.assertEqual(before, {str(p): digest(p) for p in source.rglob("*") if p.is_file()})

    def test_checksum_failure_is_not_published(self):
        with tempfile.TemporaryDirectory() as tmp:
            source, output = Path(tmp) / "source", Path(tmp) / "runtime"
            fixture(source, "APV150")
            (source / "aped/APV150/storage/active_Compounds.jsonl").write_text('{"compId":2}\n', encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "checksum"):
                build(source, output, ("APV150",))
            self.assertFalse((output / "manifest.json").exists())
            with closing(sqlite3.connect(output / "catalog.sqlite")) as conn:
                self.assertEqual(conn.execute("SELECT count(*) FROM metadata").fetchone()[0], 0)


if __name__ == "__main__":
    unittest.main()
