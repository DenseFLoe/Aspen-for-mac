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
