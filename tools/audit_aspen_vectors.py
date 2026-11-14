"""Compare ordered API vectors with stored cells using the API's own IJ/JI labels.

This validates representation, not thermodynamic equations or unit conversions.
The exact decimal strings and both representations remain unchanged.
"""
import argparse
import hashlib
import itertools
import json
from pathlib import Path

from export_aspen_catalogs import DATABASES, dumps, write_json
from verify_aspen_plaintext import rows


def signature(values):
    return hashlib.sha256("|".join(format(float(v) + 0.0, ".14g") for v in values).encode()).digest()


def audit(folder):
    metadata = {r["name"]: r for r in rows(folder / "api/properties.jsonl")}
    expected = {}
    for cp_id, group in itertools.groupby(rows(folder / "values/constant-values.jsonl"), lambda r: r["cp_id"]):
        cells = list(group)
        prop = metadata.get(cells[0]["property"])
        if prop is None:
            continue
        if prop["interaction_type"] == "Unary":
            layout = prop["label_ij"]
        elif prop["interaction_type"] in ("Binary", "Pair"):
            layout = [index for pair in zip(prop["label_ij"], prop["label_ji"]) for index in pair]
        else:
            continue
        by_index = {r["element_index"]: r["value"] for r in cells}
        values = [by_index.get(index, 1e35) for index in layout]
        expected[cp_id] = signature(values)
    matched = different = unmapped = 0
    with (folder / "api-layout-differences.jsonl").open("x", encoding="utf-8", newline="\n") as stream:
        for record in rows(folder / "api/parameters.jsonl"):
            cp_id = record["cp_id"]
            if cp_id not in expected:
                unmapped += 1
            elif signature(record["value"]) == expected[cp_id]:
                matched += 1
            else:
                different += 1
                stream.write(dumps(record) + "\n")
    result = {"database": folder.name, "ordered_vector_matches": matched,
              "ordered_vector_differences": different, "unmapped_api_records": unmapped,
              "method": "Unary: LabelIJ; Binary/Pair: interleaved LabelIJ/LabelJI. Missing cells: 1e35. Compare 14 significant digits.",
              "limitation": "Stored source cells are retained even when the API drops them. No formula or unit-conversion equivalence is claimed."}
    write_json(folder / "vector-validation.json", result)
    print(dumps(result), flush=True)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, required=True)
    args = parser.parse_args()
    write_json(args.root / "vector-validation.json", [audit(args.root / "aped" / db) for db in DATABASES])


if __name__ == "__main__":
    main()
