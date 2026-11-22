"""Synthetic MSForms exports. Compound-file fixture contains only inert miniature streams."""
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import tempfile
import unittest
import uuid
from unittest.mock import patch

if __package__:
    from . import office_forms as forms, office_vba as office
else:
    import office_forms as forms
    import office_vba as office

FREE, END, FAT = 0xffffffff, 0xfffffffe, 0xfffffffd


def compound_file(streams):
    """Write a small CFB v3 directory and mini-stream for three flat resource streams."""
    def directory(name, typ, child, left, right, start, size, clsid=None):
        utf16 = (name + "\0").encode("utf-16le")
        return struct.pack("<64sHBBIII16sIQQIQ", utf16, len(utf16), typ, 1, left, right, child,
                           uuid.UUID(clsid).bytes_le if clsid else bytes(16), 0, 0, 0, start, size)
    mini = bytearray()
    chain = []
    entries = []
    # CFB directory ordering uses length then case-insensitive UTF-16 name.
    for i, (name, payload) in enumerate(sorted(streams.items(), key=lambda p: (len(p[0]),p[0].upper()))):
        first = len(chain)
        chunks = (len(payload)+63)//64
        mini.extend(payload.ljust(chunks*64, b"\0"))
        chain.extend(list(range(first+1, first+chunks)) + [END])
        entries.append(directory(name, 2, FREE, 1 if i==1 else FREE, 3 if i==1 else FREE, first, len(payload)))
    assert len(entries)==3 and len(mini)<=512
    root = directory("Root Entry", 5, 2, FREE, FREE, 2, len(mini), forms.FORM_CLASS)
    header = bytearray(512)
    header[:8] = bytes.fromhex("d0cf11e0a1b11ae1")
    struct.pack_into("<HHHHH", header, 24, 0x3e, 3, 0xfffe, 9, 6)
    struct.pack_into("<9I", header, 40, 0, 1, 0, 0, 4096, 1, 1, END, 0)
    struct.pack_into("<109I", header, 76, 3, *([FREE]*108))
    return (header + root + b"".join(entries) + struct.pack("<128I", *(chain+[FREE]*(128-len(chain))))
            + mini.ljust(512,b"\0") + struct.pack("<128I", END, END, END, FAT, *([FREE]*124)))


@unittest.skipUnless(importlib.util.find_spec("olefile"), "install the Excel reader dependency olefile")
class ExportPair(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.folder = self.root / "vba-src"
        self.folder.mkdir()
        self.original = b"independent original identity"

    def export(self, name, caption, width, height):
        prefix=("TestVba",name)
        stream=("TestVba","VBA","CodeStream")
        name_line=f'Attribute VB_Name = "{name}"'
        hidden='Attribute VB_Customizable = False'
        code=(name_line+"\r\n"+hidden+"\r\nOption Explicit\r\n\r\n").encode()
        frame=[b"VERSION 5.00", f"Begin {{{forms.FORM_CLASS}}} {name}".encode(),
               f'   Caption = "{caption}"'.encode(), b"   ClientTop = 125", f"   ClientWidth = {width}".encode(),
               b"   ClientLeft = 10",f"   ClientHeight = {height}".encode()]
        version=b"   TypeInfoVer = 3"
        raw=b"\r\n".join([*frame,version,b"End",b""])
        frmpath=self.folder/(name+".frm")
        frmpath.write_bytes(b"\r\n".join([*frame,f' OleObjectBlob = "{name}.frx":0000'.encode(),b"End",
                                          name_line.encode(), b"Option Explicit",b"",b""]))
        def field(value):
            return struct.pack("<I",len(value))+value
        head=bytes.fromhex("0100feff030a0000ffffffff")
        fields=field(b"Test Forms\0")+field(b"Embedded Object\0")
        end=bytes.fromhex("f439b271")+bytes(12)
        comp=head+bytes(16)+fields+field(b"")+end
        export_comp=head+uuid.UUID(forms.FORM_CLASS).bytes_le+fields+field(b"Forms.Form.1\0")+end
        root_comp=self.root/"project"/prefix[0]/name/"01_CompObj"
        root_comp.parent.mkdir(parents=True)
        root_comp.write_bytes(comp)
        controls=("Example "+caption).encode()
        binary=compound_file({"f":controls,"o":b"payload","\x01CompObj":export_comp})
        frxpath=self.folder/(name+".frx")
        frxpath.write_bytes(struct.pack("<6I",0x8424c,len(binary),0,0,width+20,height+135)+binary)
        form=dict(file=frxpath.relative_to(self.root).as_posix(),type_info_line=version.decode(),
                  native_attributes=[dict(index=1,line=hidden)])
        row=dict(name=name, role="BaseClass", stream=list(stream),file=frmpath.relative_to(self.root).as_posix(),
                 original_text_offset=12,form=form)
        document=dict(original_sha256=hashlib.sha256(self.original).hexdigest(),modules=[row],
                      resources=[dict(path=[*prefix,"\x01CompObj"],file=root_comp.relative_to(self.root).as_posix())],
                      storages=[dict(path=list(prefix),clsid="")])
        manifest=self.root/"project.json"
        manifest.write_text(json.dumps(document),encoding="utf8")
        streams={forms.FRAME:raw,forms.COMP:comp,("f",):hashlib.sha256(controls).digest(),
                 ("o",):hashlib.sha256(b"payload").digest()}
        info=(name,stream,12,prefix,{():""},streams)
        def read_original(data, form_data):
            form_data[frmpath.name.casefold()] = info
            return {frmpath.name.casefold():code},"cp1252","BIFF",None
        reader=patch.object(office,"_original",side_effect=read_original)
        reader.start()
        self.addCleanup(reader.stop)
        return document,manifest,frmpath,frxpath,root_comp,controls

    def status(self):
        return office.check(self.original,self.root)["status"]

    def test_distinct_layout(self):
        self.export("Picker","Choose a category",3475,1215)
        self.assertEqual(self.status(),"pass")

    def test_plain_source_form_keeps_source_only_scope(self):
        _, manifest, frm, frx, _, _ = self.export("ShortForm","Flat source",800,690)
        expected, _, _, _ = office._original(self.original,{})
        frm.write_bytes(expected[frm.name.casefold()])
        frx.unlink()
        manifest.write_text('{"package":"plain module text"}', encoding="utf8")
        report = office.check(self.original, self.root)
        self.assertEqual(report["status"],"pass")
        self.assertEqual(report["metrics"]["comparisons"],{"exact_bytes":1})

    def test_envelope_and_resource_controls(self):
        doc,manifest,frm,frx,comp,controls=self.export("FilterPanel","Filter",1710,804)
        self.assertEqual(self.status(),"pass")
        for path,old,new in [(frm,b"FilterPanel",b"OtherPanel"),(frm,b'Caption = "Filter"',b'Caption = "Limit"'),
                             (frm,b"Option Explicit",b"Option Compare Text"),(manifest,b'Customizable = False',b'Customizable = True'),
                             (manifest,b"BaseClass",b"Module"),(manifest,b"CodeStream",b"OtherStream"),
                             (comp,b"Test Forms",b"Test Forms2"),(frx,controls,bytes(len(controls))),
                             (frx,b"Forms.Form.1",b"Forms.Form.2")]:
            with self.subTest(path=path.name,changed=old):
                saved=path.read_bytes()
                self.assertIn(old,saved)
                path.write_bytes(saved.replace(old,new,1))
                self.assertEqual(self.status(),"fail")
                path.write_bytes(saved)
        data=bytearray(frx.read_bytes())
        data[16]^=1
        frx.write_bytes(data)
        self.assertEqual(self.status(),"inconclusive")
        frx.unlink()
        self.assertNotEqual(self.status(),"pass")
