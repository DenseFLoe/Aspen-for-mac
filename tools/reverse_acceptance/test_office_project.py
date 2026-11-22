"""Independent structural tests for project metadata. Inputs contain no VBA procedures."""
from types import SimpleNamespace
import struct
import unittest

if __package__:
    from . import office_project as project
else:
    import office_project as project


def rec(tag, payload=b""):
    return struct.pack("<HI",tag,len(payload))+payload


def module(name, offset, description):
    name=name.encode()
    return (rec(0x19,name)+rec(0x1a,name)+rec(0x32,name.decode().encode("utf-16le"))
            +rec(0x1c,description)+rec(0x48,b"")+rec(0x31,struct.pack("<I",offset))
            +rec(0x1e,bytes(4))+rec(0x2c,bytes(2))+rec(0x21)+rec(0x2b))


def code_name(name, wide=False):
    return struct.pack("<HB",len(name),int(wide))+name.encode("utf-16le" if wide else "latin-1")


class ProjectMetadataTests(unittest.TestCase):
    def test_module_offset_requires_structural_owner(self):
        names=["Rates","SetPoint"]
        offsets=[100,32]
        pattern=rec(0x31,struct.pack("<I",100))
        prefix=b"independent reference payload "+pattern
        data=(prefix+rec(15,struct.pack("<H",2))+rec(0x13,bytes(2))
              +module(names[0],100,b"notes "+pattern)+module(names[1],32,b"")+rec(0x10))
        modules=[SimpleNamespace(name=n,textoffset=o) for n,o in zip(names,offsets)]
        start=len(prefix)
        fields=project.offset_fields(data,start,modules,"cp1252")
        self.assertEqual([struct.unpack_from("<I",data,fields[n])[0] for n in names],offsets)
        patched=bytearray(data)
        for field in fields.values():
            patched[field:field+4]=bytes(4)
        self.assertEqual(bytes(patched).count(pattern),2)
        wrong=bytearray(data)
        wrong[fields[names[1]]]^=1
        with self.assertRaises(project.Unsupported):
            project.offset_fields(wrong,start,modules,"cp1252")

    def test_document_role_and_name_map(self):
        a=b'Document=CostBook/&H00000003\r\nModule=Lookup\r\n[Workspace]\r\nLookup=42\r\n'
        self.assertEqual(project.declarations(a,"cp1252"),{"CostBook":"Document","Lookup":"Module"})
        self.assertNotEqual(project.declarations(a.replace(b"CostBook",b"CashBook"),"cp1252"),
                            project.declarations(a,"cp1252"))
        pairs=b"".join(n.encode()+b"\0"+n.encode("utf-16le")+bytes(2) for n in ("CostBook","Lookup"))+bytes(2)
        self.assertEqual(project.name_map(pairs,"cp1252"),{"CostBook","Lookup"})
        with self.assertRaises(project.Unsupported):
            project.name_map(pairs.replace("Lookup".encode("utf-16le"),"GetOne".encode("utf-16le")),"cp1252")

    def test_sheet_binding_checks_codename_and_boundsheet_target(self):
        globals_bof=(0x809,struct.pack("<HH",0x600,5))
        sheet_bof=(0x809,struct.pack("<HH",0x600,16))
        book_name=(0x1ba,code_name("CashBook"))
        name=b"Expenses"
        boundsheet=struct.pack("<IBBBB",0,0,0,len(name),0)+name
        at=sum(4+len(data) for _,data in (globals_bof,book_name,(0x85,boundsheet),(10,b"")))
        rows=[globals_bof,book_name,(0x85,struct.pack("<I",at)+boundsheet[4:]),(10,b""),
              sheet_bof,(0x1ba,code_name("CostSheet",True)),(10,b"")]
        self.assertEqual(set(project.host_names(rows)),{"CashBook","CostSheet"})
        changed=rows.copy()
        changed[5]=(0x1ba,code_name("LostSheet",True))
        self.assertNotEqual(project.host_names(rows),project.host_names(changed))
        changed=rows.copy()
        changed[2]=(0x85,rows[2][1].replace(b"Expenses",b"Forecast"))
        self.assertNotEqual(project.host_names(rows),project.host_names(changed))
