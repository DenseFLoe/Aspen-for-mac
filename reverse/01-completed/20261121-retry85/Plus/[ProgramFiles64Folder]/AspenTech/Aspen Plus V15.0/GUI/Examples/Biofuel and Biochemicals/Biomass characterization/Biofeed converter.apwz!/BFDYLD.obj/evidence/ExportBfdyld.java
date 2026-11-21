// Export Ghidra's analysis for comparison with the original COFF tables.
//@category Aspen
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HexFormat;

public class ExportBfdyld extends GhidraScript {
    public void run() throws Exception {
        Path out = Path.of(getScriptArgs()[0]);
        DecompInterface decompiler = new DecompInterface();
        if (!decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException("Cannot open program in decompiler");
        }
        try (PrintWriter summary = new PrintWriter(Files.newBufferedWriter(out.resolve("functions.tsv"), StandardCharsets.UTF_8));
             PrintWriter listing = new PrintWriter(Files.newBufferedWriter(out.resolve("listing.txt"), StandardCharsets.UTF_8));
             PrintWriter code = new PrintWriter(Files.newBufferedWriter(out.resolve("decompiler.c.txt"), StandardCharsets.UTF_8))) {
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                summary.println("BLOCK\t" + block.getName() + "\t" + block.getStart() + "\t" + block.getEnd());
            }
            for (Function fun : currentProgram.getFunctionManager().getFunctions(true)) {
                DecompileResults result = decompiler.decompileFunction(fun, 30, monitor);
                summary.println("FUNCTION\t" + fun.getName() + "\t" + fun.getEntryPoint() + "\t" +
                    fun.getBody().getNumAddresses() + "\t" + fun.getBody() + "\t" + result.decompileCompleted());
                code.println("/* " + fun.getName() + " @ " + fun.getEntryPoint() + " */");
                code.println(result.decompileCompleted() ? result.getDecompiledFunction().getC() : result.getErrorMessage());
            }
            for (Instruction ins : currentProgram.getListing().getInstructions(true)) {
                listing.println(ins.getAddress() + "\t" + HexFormat.of().formatHex(ins.getBytes()) + "\t" + ins);
            }
        } finally {
            decompiler.dispose();
        }
    }
}