// Export Ikc2Bkp native function bodies for comparison at their original entry RVAs.
//@category Aspen
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.MemoryBlock;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Locale;

public class ExportIkc extends GhidraScript {
    private static final String ORIGINAL = "bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011";

    private static String cell(String text) {
        return "\"" + text.replace("\"", "\"\"").replace('\n',' ').replace('\r',' ') + "\"";
    }

    @Override
    public void run() throws Exception {
        if (!ORIGINAL.equalsIgnoreCase(currentProgram.getExecutableSHA256())) {
            throw new IllegalArgumentException("wrong program SHA-256");
        }
        Path output = Path.of(getScriptArgs()[0]);
        Path code = output.resolve("code");
        Files.createDirectories(code);
        DecompInterface engine = new DecompInterface();
        engine.toggleCCode(true);
        engine.toggleSyntaxTree(false);
        if (!engine.openProgram(currentProgram)) {
            throw new IllegalStateException(engine.getLastMessage());
        }
        int count = 0, exported = 0, part = 0, line = 1;
        BufferedWriter body = null;
        String filename = "";
        Address imageBase = currentProgram.getImageBase();
        try (BufferedWriter table = Files.newBufferedWriter(output.resolve("decompiler-functions.csv"),StandardCharsets.UTF_8)) {
            table.write("rva,name,body_bytes,body_ranges,thunk,success,source,diagnostic\n");
            FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
            while (funcs.hasNext()) {
                monitor.checkCancelled();
                Function function = funcs.next();
                Address entry = function.getEntryPoint();
                MemoryBlock block = currentProgram.getMemory().getBlock(entry);
                if (block == null || !block.isExecute() || function.isExternal()) continue;
                long rva = entry.subtract(imageBase);
                count++;
                DecompileResults result = engine.decompileFunction(function, 90, monitor);
                boolean ok = result.decompileCompleted() && result.getDecompiledFunction() != null;
                String ref = "";
                if (ok) {
                    String raw = result.getDecompiledFunction().getC().replace("\r\n","\n").replace('\r','\n').strip();
                    if (!raw.isEmpty()) {
                        if (body == null || line > 3500) {
                            if (body != null) body.close();
                            filename = String.format(Locale.ROOT,"ghidra-%02d.c",++part);
                            body = Files.newBufferedWriter(code.resolve(filename),StandardCharsets.UTF_8);
                            line = 1;
                        }
                        String header = String.format(Locale.ROOT,"/* RVA 0x%x, %s */\n",rva,function.getName().replace("*/",""));
                        body.write(header);
                        body.write(raw);
                        body.write("\n\n");
                        int end = line + raw.split("\n",-1).length;
                        ref = "code/" + filename + "#L" + line + "-L" + end;
                        line = end + 2;
                        exported++;
                    } else ok = false;
                }
                table.write(String.format(Locale.ROOT,"0x%x,%s,%d,%d,%b,%b,%s,%s\n",
                    rva,cell(function.getName()),function.getBody().getNumAddresses(),function.getBody().getNumAddressRanges(),
                    function.isThunk(),ok,cell(ref),cell(result.getErrorMessage() == null ? "" : result.getErrorMessage())));
            }
        } finally {
            if (body != null) body.close();
            engine.dispose();
        }
        println("Ikc2Bkp native function entries " + count + ", C bodies " + exported + ", source parts " + part);
    }
}

