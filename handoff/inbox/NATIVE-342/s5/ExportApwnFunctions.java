// Export the bodies and bounds Ghidra actually identifies in the pinned image.
// @category Aspen
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.framework.Application;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Data;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;

public class ExportApwnFunctions extends GhidraScript {
    private String rva(Address value) {
        return "0x" + Long.toHexString(value.subtract(currentProgram.getImageBase()));
    }

    private String clean(String text) {
        return text.replace('\t', ' ').replace('\r', ' ').replace('\n', ' ');
    }

    @Override
    public void run() throws Exception {
        if (!currentProgram.getExecutableSHA256().equalsIgnoreCase(
                "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b")) {
            throw new IllegalArgumentException("Original SHA-256 mismatch");
        }
        Path out = Path.of(getScriptArgs()[0]);
        Files.createDirectories(out);
        Files.writeString(out.resolve("version.txt"), Application.getApplicationVersion() + "\n"
                + currentProgram.getExecutableSHA256().toLowerCase() + "\n", StandardCharsets.UTF_8);
        long[][] tables = {
            {0xdd54,0xea48,0}, {0x13367,0x134f4,0}, {0x1fedd,0x20278,0},
            {0x21c5a,0x228cc,0x228d8}, {0x21ca4,0x22908,0x22918},
            {0x21d30,0x22990,0x22a30}, {0x22bac,0x22edc,0x22ef4}
        };
        try (BufferedWriter sw = Files.newBufferedWriter(out.resolve("switches.tsv"), StandardCharsets.UTF_8)) {
            sw.write("site\towner\tinstruction\tflows\ttable_type\tselector_type\n");
            for (long[] item : tables) {
                Address site = currentProgram.getImageBase().add(item[0]);
                Instruction ins = currentProgram.getListing().getInstructionAt(site);
                Function owner = currentProgram.getFunctionManager().getFunctionContaining(site);
                StringBuilder flows = new StringBuilder();
                if (ins != null) for (Address target : ins.getFlows()) {
                    if (flows.length() > 0) flows.append(' ');
                    flows.append(rva(target));
                }
                String[] types = {"", ""};
                for (int i = 1; i <= 2; i++) if (item[i] != 0) {
                    Data data = currentProgram.getListing().getDefinedDataContaining(currentProgram.getImageBase().add(item[i]));
                    types[i-1] = data == null ? "undefined" : data.getDataType().getDisplayName();
                }
                sw.write(String.join("\t", rva(site), owner == null ? "" : rva(owner.getEntryPoint()),
                    ins == null ? "" : clean(ins.toString()), flows.toString(), types[0], types[1]) + "\n");
            }
        }
        DecompInterface decompiler = new DecompInterface();
        decompiler.toggleSyntaxTree(false);
        decompiler.toggleCCode(true);
        if (!decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException(decompiler.getLastMessage());
        }
        int count = 0, part = 0, line = 1, chars = 0;
        BufferedWriter source = null;
        String file = "";
        try (BufferedWriter index = Files.newBufferedWriter(out.resolve("functions.tsv"), StandardCharsets.UTF_8)) {
            index.write("rva\tname\tranges_inclusive\tbytes\tstate\tlisting\tmessage\n");
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                monitor.checkCancelled();
                Function f = functions.next();
                if (f.isExternal()) continue;
                String start = rva(f.getEntryPoint());
                StringBuilder ranges = new StringBuilder();
                for (AddressRange range : f.getBody().getAddressRanges()) {
                    if (ranges.length() > 0) ranges.append(' ');
                    ranges.append(rva(range.getMinAddress())).append('-').append(rva(range.getMaxAddress()));
                }
                DecompileResults result = decompiler.decompileFunction(f, 45, monitor);
                String body = "";
                String state = "missing";
                String location = "";
                String message = result.getErrorMessage();
                if (result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    body = result.getDecompiledFunction().getC().replace("\r", "").strip();
                    state = f.isThunk() ? "thunk" : body.contains("WARNING") ? "warning" : "generated";
                    if (source == null || chars > 128000) {
                        if (source != null) source.close();
                        file = String.format("part-%02d.c", ++part);
                        source = Files.newBufferedWriter(out.resolve(file), StandardCharsets.UTF_8);
                        chars = 0;
                        line = 1;
                    }
                    String block = "/* RVA " + start + " */\n" + body + "\n";
                    int lines = (int)block.chars().filter(c -> c == '\n').count();
                    location = "s5/ghidra/" + file + "#L" + line + "-L" + (line+lines-1);
                    source.write(block + "\n");
                    line += lines+1;
                    chars += block.length()+1;
                }
                index.write(String.join("\t", start, clean(f.getName()), ranges.toString(),
                        Long.toString(f.getBody().getNumAddresses()), state, location,
                        message == null ? "" : clean(message)) + "\n");
                count++;
            }
        } finally {
            if (source != null) source.close();
            decompiler.dispose();
        }
        println("Exported " + count + " function records in " + part + " parts");
    }
}
