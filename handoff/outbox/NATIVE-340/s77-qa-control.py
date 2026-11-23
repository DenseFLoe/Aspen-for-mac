"""Replay two QA gate controls against QA 786fec74 and the pinned NATIVE-340 original."""
from hashlib import sha256
from importlib.util import module_from_spec, spec_from_file_location
import json
from pathlib import Path
import sys
from tempfile import TemporaryDirectory
from types import SimpleNamespace

GATE_SHA = "988c9d4f0e3cb0f990e7af60a04268aac81906859854e7e373030c227810975f"
ORIGINAL_SHA = "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def fail_module(_task, _item, _original, _context):
    raise ValueError("fixture detector input could not be read")


def ok_module(_task, _item, _original, _context):
    return [], {"rows": 1}


def main(gate, original):
    assert digest(gate) == GATE_SHA and digest(original) == ORIGINAL_SHA
    sys.path.insert(0, str(gate.resolve().parent))
    spec = spec_from_file_location("fixed_qa_gate", gate)
    mod = module_from_spec(spec)
    spec.loader.exec_module(mod)
    real = next(x for x in mod.load_detectors() if x.__name__ == "det_access_flags")
    mod.run_l1 = lambda *_: {"exit": 0}
    mock = SimpleNamespace(__name__="fixture", CATEGORY="fixture", L1_COVERS="no")
    outputs = {}
    cases = (("gate_valid", mock, ok_module), ("gate_raising", mock, fail_module),
             ("access_valid", real, "0x06000001"), ("access_unbound", real, "0x0600FFFF"))
    with TemporaryDirectory() as folder:
        root = Path(folder)
        for name, detector, case in cases:
            root.joinpath(name).mkdir()
            item = root / name
            mod.load_detectors = lambda: [detector]
            if detector is mock:
                mock.detect = case
                rows = None
            else:
                member = item / "access.csv"
                member.write_text(f"token,flags,access\n{case},0x0813,Assembly\n",
                                  encoding="ascii", newline="\n")
                rows = digest(member)
            result = mod.aggregate("NATIVE-340", str(item), str(original))
            out = result["l2"][detector.__name__]
            outputs[name] = {"csv_sha256": rows, "units": result["units"], "l2_exit": result["l2_exit"],
                             "exit": result["exit"], "detector": out}
    print(json.dumps(outputs, indent=2))


if __name__ == "__main__":
    main(*map(Path, sys.argv[1:]))
