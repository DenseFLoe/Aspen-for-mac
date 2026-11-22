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
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;

public class ExportSimFunctions extends GhidraScript {
    private String rva(Address value) {
        return "0x" + Long.toHexString(value.subtract(currentProgram.getImageBase()));
    }

    private String clean(String text) {
        return text.replace('\t', ' ').replace('\r', ' ').replace('\n', ' ');
    }

    @Override
    public void run() throws Exception {
        if (!currentProgram.getExecutableSHA256().equalsIgnoreCase(
                "9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601")) {
            throw new IllegalArgumentException("Original SHA-256 mismatch");
        }
        Path out = Path.of(getScriptArgs()[0]);
        Files.createDirectories(out);
        Files.writeString(out.resolve("version.txt"), Application.getApplicationVersion() + "\n"
                + currentProgram.getExecutableSHA256().toLowerCase() + "\n", StandardCharsets.UTF_8);
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
                    location = "ghidra/" + file + "#L" + line + "-L" + (line+lines-1);
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
