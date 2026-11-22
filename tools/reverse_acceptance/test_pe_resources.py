import base64
import csv
import hashlib
import importlib.util
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path

try:
    from .pe_resources import check
except ImportError:
    sys.path.insert(0,str(Path(__file__).resolve().parent))
    from pe_resources import check


def fixture():
    # A minimal PE32 with one RCDATA leaf at /10/7/1033.
    b=bytearray(1024)
    b[:2]=b"MZ"
    struct.pack_into("<I",b,60,0x80)
    b[128:132]=b"PE\x00\x00"
    struct.pack_into("<HHIIIHH",b,132,0x14c,1,0,0,0,224,0x2102)
    opt=152
    struct.pack_into("<H",b,opt,0x10b)
    struct.pack_into("<III",b,opt+28,0x400000,0x1000,512)
    struct.pack_into("<II",b,opt+56,0x2000,512)
    struct.pack_into("<I",b,opt+92,16)
    struct.pack_into("<II",b,opt+96+2*8,0x1000,128)
    s=opt+224
    b[s:s+8]=b".rsrc\0\0\0"
    struct.pack_into("<IIII",b,s+8,512,0x1000,512,512)
    struct.pack_into("<I",b,s+36,0x40000040)
    for pos, ident, target in [(0,10,0x80000018),(24,7,0x80000030),(48,1033,72)]:
        struct.pack_into("<HHII",b,512+pos+12,0,1,ident,target)
    data=b"example!"
    struct.pack_into("<IIII",b,512+72,0x1060,len(data),1252,0)
    b[512+96:512+96+len(data)]=data
    row={"type":"10","name":"7","language":"1033","rva":"0x1060","bytes":str(len(data)),
         "code_page":"1252","sha256":hashlib.sha256(data).hexdigest()}
    payload={**row,"content_base64":base64.b64encode(data).decode()}
    return bytes(b),row,payload


@unittest.skipUnless(importlib.util.find_spec("pefile"), "requires pefile")
class ResourceComparisonTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root=Path(self.tmp.name)
        (self.root/"s5").mkdir()
        self.data,self.row,self.payload=fixture()

    def run_case(self, csv_rows, blobs):
        with (self.root/"resources.csv").open("w",newline="",encoding="utf8") as f:
            w=csv.DictWriter(f,self.row.keys()); w.writeheader(); w.writerows(csv_rows)
        if blobs is not None:
            (self.root/"s5"/"resources.json").write_text(json.dumps({"resources":blobs}),encoding="utf8")
        return check(self.data,self.root)

    def test_complete(self):
        r=self.run_case([self.row],[self.payload])
        self.assertEqual(r["status"],"pass",r)
        self.assertEqual(r["metrics"]["delivered_payload_bytes"],8)

    def test_csv_only(self):
        r=self.run_case([self.row],None)
        self.assertEqual(r["status"],"inconclusive")

    def test_payload_byte(self):
        r=self.run_case([self.row],[{**self.payload,"content_base64":"ZXhhbXBsZT8="}])
        self.assertIn("resource_payload_mismatch",[f["code"] for f in r["findings"]])
        self.assertEqual(r["status"],"fail")

    def test_missing_and_extra_keep_count(self):
        r=self.run_case([{**self.row,"language":"0"}],[self.payload])
        self.assertEqual({f["code"] for f in r["findings"]},{"extra_resource","missing_resource"})

    def test_duplicate(self):
        r=self.run_case([self.row],[self.payload,self.payload])
        self.assertEqual(r["status"],"fail")

    def test_rva_and_codepage(self):
        r=self.run_case([{**self.row,"rva":"0x1061","code_page":"0"}],[self.payload])
        self.assertEqual({f.get("field") for f in r["findings"]},{"rva","code_page"})

    def test_corrupt_original_table(self):
        b=bytearray(self.data)
        struct.pack_into("<I",b,512+16+4,0x8000ffff)
        self.data=bytes(b)
        r=self.run_case([self.row],[self.payload])
        self.assertEqual(r["status"],"inconclusive")


if __name__=="__main__":
    unittest.main()

