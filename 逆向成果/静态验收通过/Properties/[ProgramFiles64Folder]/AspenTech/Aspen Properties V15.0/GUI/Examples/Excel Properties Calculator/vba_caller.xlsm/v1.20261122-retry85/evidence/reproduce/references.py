import io
import json
import logging
import sys
import zipfile
from pathlib import Path
root = Path(__file__).resolve().parent
sys.path.insert(0, str(root / "deps"))
import olefile
import oletools.olevba as vba
vba.log.logger.propagate = False
class RefHandler(logging.Handler):
    rows = []
    def emit(self, record):
        text = record.getMessage()
        if text.startswith("REFERENCE "):
            self.rows.append(text)
handler = RefHandler()
vba.log.logger.addHandler(handler)
vba.log.logger.setLevel(logging.DEBUG)
with zipfile.ZipFile(root.parent / "input" / "vba_caller.xlsm") as f:
    compound = f.read("xl/vbaProject.bin")
with olefile.OleFileIO(io.BytesIO(compound)) as ole:
    proj = vba.VBA_Project(ole, "", "PROJECT", "VBA/dir", relaxed=False)
    print("syskind", proj.syskind, proj.syskind_name)
    print("\n".join(handler.rows))
(root / "references.json").write_text(json.dumps(dict(syskind=proj.syskind, references=handler.rows), indent=2), encoding="utf-8")


