//@category Aspen
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import java.io.BufferedWriter;
import java.nio.file.*;
import java.util.*;

public class ExportIkcFlow extends GhidraScript {
    public void run() throws Exception {
        if (!"bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011".equalsIgnoreCase(currentProgram.getExecutableSHA256()))
            throw new IllegalArgumentException("Wrong original");
        Address base = currentProgram.getImageBase();
        Path root = Path.of(getScriptArgs()[0]);
        try (BufferedWriter ranges = Files.newBufferedWriter(root.resolve("body-ranges.csv"));
             BufferedWriter flow = Files.newBufferedWriter(root.resolve("indexed-flow.csv"))) {
            ranges.write("owner,start,inclusive_end\n");
            flow.write("owner,site,resolved_target\n");
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                MemoryBlock b = currentProgram.getMemory().getBlock(fn.getEntryPoint());
                if (b == null || !b.isExecute() || fn.isExternal()) continue;
                long owner = fn.getEntryPoint().subtract(base);
                for (AddressRange r : fn.getBody().getAddressRanges()) {
                    ranges.write(String.format("0x%x,0x%x,0x%x\n",owner,r.getMinAddress().subtract(base),r.getMaxAddress().subtract(base)));
                }
                for (Instruction i : currentProgram.getListing().getInstructions(fn.getBody(),true)) {
                    if (!i.getFlowType().isComputed()) continue;
                    for (Address addr : i.getFlows()) {
                        if (!addr.getAddressSpace().equals(base.getAddressSpace())) continue;
                        flow.write(String.format("0x%x,0x%x,0x%x\n",owner,i.getAddress().subtract(base),addr.subtract(base)));
                    }
                }
            }
        }
    }
}
