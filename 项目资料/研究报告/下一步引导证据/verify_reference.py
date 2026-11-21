"""Read-only verification of the locally preserved Next walkthrough evidence.

This checks source identities/call edges and an actual engine input/history pair.
It does not replay the GUI, test the port, or certify thermodynamic accuracy.
Vendor inputs, parameters, disassembly and binary results must stay local.
"""
import argparse
import hashlib
import json
import math
import re
from pathlib import Path


HERE = Path(__file__).resolve().parent


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def only(directory, pattern):
    matches = list(directory.glob(pattern))
    require(len(matches) == 1, f"Expected one {pattern} in the run snapshot")
    return matches[0]


def section(text, heading):
    match = re.search(r"(?ms)^" + re.escape(heading) + r"\s*\n(.*?)(?=^\S|\Z)", text)
    require(match is not None, f"Missing input section: {heading}")
    return match.group(1)


def number(text, name):
    match = re.search(r"\b" + re.escape(name) + r"\s*=\s*([-+\d.Ee]+)", text)
    require(match is not None, f"Missing input field: {name}")
    return float(match.group(1))


def load_source(path, expected_hash, expected_names):
    evidence = json.loads(path.read_text(encoding="utf-8"))
    require(evidence["sha256"] == expected_hash, "Unexpected source build")
    require(sha256(Path(evidence["file"])) == expected_hash, "Installed source changed")
    require(not evidence["errors"], "Extraction has parsing errors")
    methods = {method["name"].split(".")[-1]: method for method in evidence["methods"]}
    require(set(methods) == set(expected_names), "Extracted method set differs")
    return methods


def calls(method):
    return [call["operand"] for call in method["calls"]]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--run-dir", required=True, type=Path)
    parser.add_argument("--shell-evidence", required=True, type=Path)
    parser.add_argument("--controls-evidence", required=True, type=Path)
    args = parser.parse_args()
    case = json.loads((HERE / "case.json").read_text(encoding="utf-8"))
    checks = []

    run_dir = args.run_dir.resolve(strict=True)
    manifest = json.loads((run_dir / "snapshot-manifest.json").read_text(encoding="utf-8"))
    require(manifest["files"], "Snapshot manifest is empty")
    for item in manifest["files"]:
        path = (run_dir / item["name"]).resolve(strict=True)
        require(path.parent == run_dir, "Snapshot entry must be a direct child")
        require(path.stat().st_size == item["size"], "Snapshot file size changed")
        require(sha256(path) == item["sha256"], "Snapshot file hash changed")
    checks.append("preserved snapshot file hashes and lengths")
    require(sha256(run_dir / "tutorial-flash-copy.bkp") == case["startingPoint"]["sha256"],
            "Starting tutorial differs from the recorded original")
    checks.append("original tutorial provenance")

    # Decode ASCII syntax only. Locale-specific comments are not interpreted.
    input_text = only(run_dir, "*.in0").read_bytes().decode("ascii", errors="replace")
    history = only(run_dir, "*.his").read_bytes().decode("ascii", errors="replace")
    expected = case["inputs"]
    require(re.search(r"(?m)^IN-UNITS ENG\b", input_text), "Unit set differs")
    require(re.search(r"(?m)^PROPERTIES NRTL\s*$", input_text), "Method differs")
    components = section(input_text, "COMPONENTS")
    require(all(re.search(r"\b" + component + r"\b", components)
                for component in expected["components"]), "Components differ")
    checks.append("engine input components, method and unit set")

    feed = section(input_text, "STREAM 1")
    for name, value in (("TEMP", expected["feed"]["temperatureF"]),
                        ("PRES", expected["feed"]["pressurePsia"]),
                        ("MOLE-FLOW", expected["feed"]["moleFlowLbmolPerHour"])):
        require(number(feed, name) == value, f"Feed {name} differs")
    fractions = re.search(r"MOLE-FRAC\s+METHANOL\s+([\d.]+)\s*/\s*WATER\s+([\d.]+)", feed)
    require(fractions is not None, "Missing feed mole fractions")
    require([float(value) for value in fractions.groups()] == [0.5, 0.5], "Feed composition differs")
    checks.append("committed feed temperature, pressure, flow and composition")

    block = section(input_text, "BLOCK B1 FLASH2")
    require(number(block, "TEMP") == expected["block"]["temperatureF"], "Block temperature differs")
    require(number(block, "PRES") == expected["block"]["pressurePsia"], "Block pressure differs")
    require(re.search(r"BLOCK B1 IN=1 OUT=2 3\b", section(input_text, "FLOWSHEET")), "Topology differs")
    checks.append("committed Flash2 specifications and connections")

    trace = re.search(r"UOS BLOCK B1\s+MODEL: FLASH2.*?KODE\s*=\s*(\d+).*?"
                      r"T\s*=\s*([\d.]+)\s+P\s*=\s*([\d.Ee+-]+)\s+V\s*=\s*([\d.Ee+-]+)",
                      history, re.S)
    require(trace is not None and "Results generated" in history, "No completed Flash2 trace")
    kode, temperature, pressure, vapor = map(float, trace.groups())
    require(kode == 2 and 0 <= vapor <= 1, "Unexpected Flash2 trace status or fraction")
    # Consistency with the user-entered Fahrenheit/psia values, not an EOS check.
    require(math.isclose(temperature, (expected["block"]["temperatureF"] - 32) * 5 / 9 + 273.15,
                         abs_tol=0.0001), "Trace temperature is inconsistent with the input")
    require(math.isclose(pressure, expected["block"]["pressurePsia"] * 6894.757293168,
                         rel_tol=2e-5), "Trace pressure is inconsistent with the input")
    checks.append("completed engine trace and specification unit consistency")

    shell = load_source(args.shell_evidence,
                        "12e4bf717333bb1c59ea5b9863a951fe7e4ac47766373d31efa4c54a1a010d0f",
                        ["ApwnShellWindow::" + name for name in
                         ("OnNextButtonClickedEvent", "NextInput_Executed", "NextInputFn", "NextStatus")])
    controls = load_source(args.controls_evidence,
                           "bd4b5cdf3e6c8ede0dbb54b9297581bb79fa7289fe45c71def67b5bf1107842c",
                           ["MMNextButton::OnClick", "MMTabPage::NextHit", "MMTabStrip::NextHit", "MMViewModel::NextHit"])
    checks.append("two installed assembly identities and eight extracted methods")
    for name in ("OnNextButtonClickedEvent", "NextInput_Executed"):
        require(any(call.endswith("::NextInputFn") for call in calls(shell["ApwnShellWindow::" + name])),
                "Next entry no longer calls the shared executor")
    next_calls = calls(shell["ApwnShellWindow::NextInputFn"])
    commit = next(i for i, call in enumerate(next_calls) if "StoreValueEventArgs::.ctor" in call)
    next_hit = next(i for i, call in enumerate(next_calls) if "ApwnFormContentHost::NextHit" in call)
    require(commit < next_hit, "Form inspection precedes edit-commit event construction")
    require(any(call.endswith("CxsCase::InvokeAction") for call in next_calls), "Missing project action boundary")
    require(any(call.endswith("::OnRunRun") for call in next_calls), "Missing run transition")
    checks.append("shared Next entries, edit-commit ordering and run boundary")
    tab_calls = calls(controls["MMTabStrip::NextHit"])
    require(all(any(call.endswith("::" + getter) for call in tab_calls)
                for getter in ("get_Accessible", "get_Complete", "get_CompletionMessages")),
            "Missing tab accessibility/completion/message gates")
    field_calls = calls(controls["MMViewModel::NextHit"])
    require(any(call.endswith("::ShowNextIncomplete") for call in field_calls), "Missing field guidance")
    checks.append("tab completion gates and field-level incomplete guidance")

    print(json.dumps({"case": case["id"], "passed": len(checks), "checks": checks,
                      "limits": ["No GUI replay", "No port implementation test", "No independent thermodynamic validation"]},
                     ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
