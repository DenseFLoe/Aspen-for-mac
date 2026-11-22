"""Check fixed FindComponent s25 references against the original PE and candidate."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct

import capstone
from capstone import x86
import pefile

from importlib.util import module_from_spec, spec_from_file_location
from pathlib import Path

spec = spec_from_file_location("check_s21", Path(__file__).with_name("check-s21.py"))
prior = module_from_spec(spec)
spec.loader.exec_module(prior)


def analyze(original, item):
    previous = prior.verify(original, item)
    pe = pefile.PE(str(original))
    image = pe.get_memory_mapped_image()
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    addresses, owners = prior.listing(item / "code/native.asm", image)
    lines = {site: number for number, site in addresses.items()}
    pdata = sorted((entry.struct.BeginAddress, entry.struct.EndAddress)
                   for entry in pe.DIRECTORY_ENTRY_EXCEPTION)
    def host(site):
        return next(((start,end) for start,end in pdata if start <= site < end), None)

    def decode(site):
        return next(decoder.disasm(image[site:site+16],site,count=1))

    def table(name):
        return prior.rows(item / name)

    receipt = (item / "s25-submission.md").read_text(encoding="utf-8-sig")
    for path, digest in re.findall(r"^- (\S+) ([a-f0-9]{64})$",receipt,re.M):
        assert hashlib.sha256((item/path).read_bytes()).hexdigest() == digest, path

    raw = table("code/indirect-resolved.csv")
    former = table("code/indirect-resolved.prev.csv")
    new_sites = {int(r["callee"].split("@")[1],16) for r in raw}
    assert len(raw) == len(former) == len(new_sites) == 99
    assert [r["callee"] for r in raw] == [r["callee"] for r in former]
    assert all(v["stale"] == 0 and v["tested"] == 99
               for v in previous["indirect_listing_refs"].values())

    call_rows = table("calls.csv")
    by_site = {int(r["callee"].split("@")[1],16):(index,r)
               for index,r in enumerate(call_rows,2) if r["callee"].startswith("indirect@")}
    dataflow = []
    for row in table("code/s25-0x4706-dispatches.csv"):
        site, source = [int(row[key],16) for key in ("insn_rva","source_insn_rva")]
        transfer, load = decode(site), decode(source)
        dest, read = load.operands
        assert transfer.mnemonic == "call" and transfer.operands[0].type == x86.X86_OP_MEM
        assert transfer.operands[0].mem.base == x86.X86_REG_RAX
        assert transfer.operands[0].mem.disp == int(row["vtable_slot"],16)
        assert load.mnemonic == "mov" and dest.reg == x86.X86_REG_RAX
        assert read.type == x86.X86_OP_MEM and read.mem.disp == 0 and read.mem.index == 0
        assert source < site and owners[site] == owners[source] == 0x4706
        assert not any(x86.X86_REG_RAX in decode(p).regs_access()[1]
                       for p in lines if source < p < site)
        number, official = by_site[site]
        assert official["class"] == "unresolved"
        bounds = host(site)
        dataflow.append(dict(site=hex(site),source=hex(source),source_operand=load.op_str,
                             slot=hex(transfer.operands[0].mem.disp),main_table_line=number,
                             asm_line=lines[site],pdata_host=hex(bounds[0]) if bounds else None))

    assert len(dataflow) == len({r["site"] for r in dataflow}) == 16
    fragment=next(entry for entry in pe.DIRECTORY_ENTRY_EXCEPTION if entry.struct.BeginAddress == 0x4706)
    unwind=fragment.unwindinfo
    assert unwind.Flags & 4 and fragment.struct.EndAddress == 0x4988
    chain_rva=fragment.struct.UnwindData+4+2*((unwind.CountOfCodes+1)&~1)
    parent=struct.unpack_from("<III",image,chain_rva)
    assert parent == (0x4690,0x4706,0x93C8)
    assert {r["pdata_host"] for r in dataflow} == {"0x4706"}

    binds = {int(r["rva"],16):r for r in table("code/s21-com-binding.csv")}
    com = table("code/s25-idispatch-slots.csv")
    assert len(com) == len(binds) == 64
    assert {int(r["site"],16) for r in com} == set(binds)
    com_mismatches = [{"site": r["site"], "claimed": r["member"],
                       "original": binds[int(r["site"],16)]["member"]} for r in com
                      if r["member"] != binds[int(r["site"],16)]["member"]]
    owners_table = table("code/s25-host-vs-candidate.csv")
    assert {int(r["insn_rva"],16) for r in owners_table} == new_sites
    wrong_owners = [r["insn_rva"] for r in owners_table
                    if int(r["candidate_owner"],16) != owners[int(r["insn_rva"],16)]]
    host_12da = host(0x12DA)
    target_12da = decode(0x12DA)
    assert host_12da == (0x11E0,0x1319) and owners[0x12DA] == 0x12BD
    assert target_12da.mnemonic == "call" and target_12da.operands[0].imm == 0x5CFC

    return {
        "original_sha256": previous["original_sha256"],
        "prior_controls": previous,
        "new_indirect": {"rows": len(raw), "changed_from_archived": sum(a!=b for a,b in zip(raw,former)),
                         "changed_by_field": {key: sum(a[key]!=b[key] for a,b in zip(raw,former)) for key in raw[0]}},
        "owner_columns": {"rows": len(owners_table), "submitted_differences": sum(r["same"]=="no" for r in owners_table),
                          "incorrect_candidate_owners": wrong_owners},
        "direct_example": {"site": "0x12da", "target": "0x5cfc",
                           "original_range": list(map(hex,host_12da)),
                           "candidate_listing_owner":"0x12bd", "listing_line":lines[0x12DA],
                           "submitted_annex_has_row": any(int(r["insn_rva"],16)==0x12DA for r in owners_table)},
        "memory_dispatch_chain": {"fragment": ["0x4706","0x4988"], "unwind_info": "0x93e8",
                                  "chained_parent": list(map(hex,parent))},
        "memory_dispatches": dataflow,
        "idispatch_annex": {"rows":len(com),"member_matches":len(com)-len(com_mismatches),
                           "member_mismatches":com_mismatches,
                           "missing_displacements":sum(not r["disp"] for r in com),
                           "original_slot_offsets":dict(Counter(r["slot_index"] for r in binds.values()))},
        "unresolved": sum(r["class"]=="unresolved" for r in call_rows),
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    parser.add_argument("candidate",type=Path)
    args=parser.parse_args()
    print(json.dumps(analyze(args.original,args.candidate),ensure_ascii=True,indent=2))
