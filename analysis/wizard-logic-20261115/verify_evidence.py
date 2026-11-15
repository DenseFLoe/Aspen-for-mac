"""Cross-check extracted evidence against current read-only Aspen inputs.

This checks the evidence pipeline and call locations, not Aspen business results.
Run after inspect_logic.py outputs for the recorded investigation exist.
"""
import argparse
import hashlib
import json
from pathlib import Path

from inspect_logic import ROOT


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("run", type=Path)
    args = ap.parse_args()
    run = args.run.resolve(strict=True)
    rel = run.relative_to(ROOT / ".local")
    if not rel.parts[0].startswith("wizard-logic-analysis-"):
        raise ValueError("Unexpected evidence directory")
    output = run / "checks.json"
    if output.exists():
        raise FileExistsError(output)
    data = {}
    for folder in ("managed-findcomponent", "managed-components", "managed-controls",
                   "managed-wizard", "managed-wrapper", "native-smge-v2",
                   "native-findcomponent-v2", "native-driver-bridge",
                   "native-action-registration", "native-action-dispatch"):
        kind = "managed" if folder.startswith("managed") else "native"
        data[folder] = json.loads((run / folder / (kind + ".json")).read_text(encoding="utf-8"))
    checks = []

    def check(name, condition):
        checks.append({"name": name, "passed": bool(condition)})

    for name, doc in data.items():
        check(name + ": input hash unchanged",
              hashlib.sha256(Path(doc["file"]).read_bytes()).hexdigest() == doc["sha256"])
        if "methods" in doc:
            check(name + ": no IL parse errors", not doc["errors"])
            check(name + ": unique MethodDef tokens",
                  len({m["token"] for m in doc["methods"]}) == len(doc["methods"]))

    def method(group, suffix):
        found = [m for m in data[group]["methods"] if m["name"].endswith(suffix)]
        if len(found) != 1:
            raise ValueError((group, suffix, len(found)))
        return found[0]

    def calls(suffix, group="managed-findcomponent"):
        return [i["operand"].split("::")[-1] for i in method(group, suffix)["calls"]]

    c = calls("ElectrolyteForm10::OnForward")
    expected = ["WriteElecWizardFlagM", "WriteChemRecordM", "WriteHcompRecordM", "SetGlobalOpsetM"]
    check("electrolyte writes before final page", all(x in c for x in expected) and
          [c.index(x) for x in expected] == sorted(c.index(x) for x in expected))
    check("early finish writes base components", "WriteNewBaseCompsM" in calls("ElectrolyteForm12::OnFinished"))
    check("base next checks reaction availability",
          any(isinstance(i["operand"], str) and i["operand"].endswith("::g_reactions")
              for i in method("managed-findcomponent", "ElectrolyteForm11::OnForward")["il"]))
    c = calls("SFEAssistantStep2::OnFinished")
    check("new SFE chemistry write order", all(x in c for x in ("GenerateComponent", "GenerateChemisty", "GenerateReaction")) and
          c.index("GenerateComponent") < c.index("GenerateChemisty") < c.index("GenerateReaction"))
    check("wizard Finish invokes page callbacks", "OnFinished" in calls("WizardControl::Finish", "managed-wizard"))
    check("electrolyte list double click reuses add handler", "btnMove_Click" in calls("ElectrolyteForm11::lstAvailableComp_MouseDoubleClick"))
    check("SFE list double click reuses remove handler", "btnRemove_Click" in calls("SFEAssistantStep1::lstSelectedComp_MouseDoubleClick"))
    check("reorder context invokes bound command", "Execute" in calls("MMScrollAreaMS::OnRoutedReorderRecordCommand", "managed-controls"))
    check("native command action name", any(i["operand"] == "gxSFEAssistantMain" for i in method("managed-controls", "MmgExtensions::GxSFEAssistantMain")["il"]))

    native = {f["name"]: f for f in data["native-smge-v2"]["functions"]}
    chem = native["write_chem_record"]
    check("native write_chem_record includes chained unwind continuation", len(chem["chunks"]) == 2 and chem["chunks"][-1][1] == "0x1d3bec")
    check("native chemistry calls component writer", any("write_new_base_comps" in c["refs"] for c in chem["calls"]))
    check("native chemistry reaches global field", any(s["value"] == "GCHEMISTRY" for s in chem["strings"]))
    free_calls = native["clear_alloced_rxn_space"]["calls"]
    check("candidate cleanup has two MDfree calls", len(free_calls) == 2 and all("mmg.dll!MDfree" in c["refs"] for c in free_calls))
    for target in ("ShowElecWizard", "ShowSFEAssistantMain"):
        check("COM bridge names " + target, any(s["value"] == target for f in data["native-driver-bridge"]["functions"] for s in f["strings"]))
    for target in ("gxElectrolyteWizard", "gxSFEAssistantMain"):
        check("native dispatch calls " + target, any("FINDCOMPONENT.dll!"+target in c["refs"] for f in data["native-action-dispatch"]["functions"] for c in f["calls"]))

    result = {"passed": sum(c["passed"] for c in checks), "total": len(checks),
              "managed_methods": sum(len(d.get("methods", [])) for d in data.values()),
              "checks": checks, "scope": "Static evidence integrity; not runtime or numerical validation"}
    output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in result.items() if k != "checks"}))
    if result["passed"] != result["total"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
