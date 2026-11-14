from pathlib import Path
import sqlite3
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from export_aspen_catalogs import export_sqlite, write_rows
from import_aspen_plaintext import restore, execute_sql_file


class PlaintextRoundTrip(unittest.TestCase):
    def test_sqlite_text_null_binary_and_quoted_identifier(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / "source.sqlite"
            with sqlite3.connect(source) as db:
                db.execute('CREATE TABLE "odd table" (id INTEGER, txt TEXT, raw BLOB, missing REAL)')
                expected = (7, "中文\nquoted ' text\x00tail", b"\x00\xff\x01", None)
                db.execute('INSERT INTO "odd table" VALUES(?,?,?,?)', expected)
                db.execute('INSERT INTO "odd table" (id,txt) VALUES(8,CAST(X\'80ff00\' AS TEXT))')
                db.execute('CREATE INDEX custom_id ON "odd table" (id)')
                db.execute('CREATE TABLE serial (id INTEGER PRIMARY KEY AUTOINCREMENT)')
                db.execute('INSERT INTO serial VALUES(5)')
                db.execute('DELETE FROM serial')
            db.close()
            export_sqlite(source, root / "text")
            restore(root / "text", root / "restored.sqlite")
            with sqlite3.connect(root / "restored.sqlite") as db:
                self.assertEqual(db.execute('SELECT * FROM "odd table" WHERE id=7').fetchone(), expected)
                self.assertEqual(db.execute('SELECT hex(txt),typeof(txt) FROM "odd table" WHERE id=8').fetchone(), ('80FF00', 'text'))
                self.assertIsNotNone(db.execute("SELECT name FROM sqlite_master WHERE name='custom_id'").fetchone())
                db.execute('INSERT INTO serial DEFAULT VALUES')
                self.assertEqual(db.execute('SELECT id FROM serial').fetchone(), (6,))
            db.close()
            with self.assertRaises(FileExistsError):
                restore(root / "text", root / "restored.sqlite")

    def test_partial_count_mismatch_is_not_published(self):
        with tempfile.TemporaryDirectory() as directory, sqlite3.connect(":memory:") as db:
            path = Path(directory) / "values.jsonl"
            with self.assertRaises(RuntimeError):
                write_rows(path, db.execute("SELECT 1 AS value"), 2)
            self.assertFalse(path.exists())
            self.assertTrue(path.with_suffix(".jsonl.partial").exists())

    def test_multiline_sql_literals_restore_losslessly(self):
        with tempfile.TemporaryDirectory() as directory, sqlite3.connect(":memory:") as db:
            path = Path(directory) / "data.sql"
            path.write_text("CREATE TABLE data(value);\nINSERT INTO data VALUES('a;\nb');\n"
                            "INSERT INTO data VALUES(CAST(X'610062' AS TEXT));\n", encoding="utf-8")
            execute_sql_file(db, path)
            self.assertEqual(db.execute("SELECT value FROM data").fetchall(), [("a;\nb",), ("a\x00b",)])


if __name__ == "__main__":
    unittest.main()
