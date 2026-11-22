import io
import json
import logging
import sys
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
compound = (root.parent / "input" / "vbaProject.bin").read_bytes()
with olefile.OleFileIO(io.BytesIO(compound)) as ole:
    proj = vba.VBA_Project(ole, "", "PROJECT", "VBA/dir", relaxed=False)
(root / "references.json").write_text(json.dumps(dict(syskind=proj.syskind, references=handler.rows), indent=2), encoding="utf-8")



