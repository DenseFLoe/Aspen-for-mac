"""Test existing VBA source-file comparisons without storing any recovered module."""
import codecs
import io
import json
import sys
import tempfile
import unittest
import zipfile
from pathlib import Path
from unittest.mock import patch

try:
    from . import office_vba as v
except ImportError:
    sys.path.insert(0,str(Path(__file__).resolve().parent))
    import office_vba as v


class VbaAcceptanceTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root=Path(self.tmp.name)
        self.folder=self.root/"VBA"
        self.folder.mkdir()
        self.original={"alpha.bas":b"public value\r\n\r\n","sheet.cls":b"attribute sheet\r\n"}
        for name,data in self.original.items():
            (self.folder/name).write_bytes(data)

    def result(self):
        with patch.object(v,"_original",return_value=(self.original,"cp1252","OOXML",0)):
            return v.check(b"",self.root)

    def test_exact(self):
        r=self.result()
        self.assertEqual(r["status"],"pass",r)
        self.assertEqual(r["metrics"]["comparisons"],{"exact_bytes":2})

    def test_same_count_replaced(self):
        (self.folder/"alpha.bas").rename(self.folder/"other.bas")
        r=self.result()
        self.assertEqual(r["status"],"fail")
        self.assertEqual({i["code"] for i in r["findings"]},{"extra_editable_module","missing_editable_module"})

    def test_no_strip_blank_lines(self):
        (self.folder/"alpha.bas").write_bytes(b"public value\n")
        r=self.result()
        self.assertEqual(r["status"],"fail")
        self.assertNotIn("public value", json.dumps(r))

    def test_explicit_codepage_and_line_endings(self):
        raw="André\r\n\r\n".encode("cp1252")
        utf8="André\n\n".encode("utf8")
        self.assertEqual(v._relation(raw,codecs.BOM_UTF8+utf8,"cp1252"),"explicit_utf8_text")
        self.assertEqual(v._relation(raw,utf8,"cp1252"),"unverified_encoding")
        self.assertEqual(v._relation(raw,raw.replace(b"\r\n",b"\n"),"cp1252"),"project_codepage_text")

    def test_ambiguous_source_roots(self):
        (self.root/"vba-src").mkdir()
        self.assertEqual(self.result()["status"],"inconclusive")

    def test_corrupt_input(self):
        r=v.check(b"not a workbook",self.root)
        self.assertEqual(r["status"],"inconclusive")

    def test_linked_workbook_is_the_host(self):
        ns="http://schemas.openxmlformats.org/package/2006/relationships"
        root="http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument"
        vba="http://schemas.microsoft.com/office/2006/relationships/vbaProject"
        out=io.BytesIO()
        with zipfile.ZipFile(out,"w") as z:
            z.writestr("_rels/.rels", f'<Relationships xmlns="{ns}"><Relationship Type="{root}" Target="other/workbook.xml"/></Relationships>')
            z.writestr("xl/workbook.xml","<workbook/>")
            z.writestr("xl/_rels/workbook.xml.rels",f'<Relationships xmlns="{ns}"><Relationship Type="{vba}" Target="vbaProject.bin"/></Relationships>')
            z.writestr("xl/vbaProject.bin",b"irrelevant")
        with self.assertRaisesRegex(v.Unverified,"primary_workbook_not_bound"):
            v._compound(out.getvalue())


if __name__=="__main__":
    unittest.main()

