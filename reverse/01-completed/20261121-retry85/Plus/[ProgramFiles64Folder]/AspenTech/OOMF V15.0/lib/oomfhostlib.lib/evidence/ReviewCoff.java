// Export native COFF analysis in separate, local files.
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

public class ReviewCoff extends GhidraScript {
    @Override
    public void run() throws Exception {
        Path destination = Path.of(getScriptArgs()[0], currentProgram.getName() + ".txt");
        DecompInterface decompiler = new DecompInterface();
        if (!decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException(decompiler.getLastMessage());
        }

        try (PrintWriter out = new PrintWriter(Files.newBufferedWriter(destination, StandardCharsets.UTF_8))) {
            out.println(currentProgram.getExecutableFormat() + " " + currentProgram.getLanguageID());
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                out.printf("BLOCK %s %s..%s size=%d X=%s%n",
                    block.getName(), block.getStart(), block.getEnd(), block.getSize(), block.isExecute());
            }
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                out.printf("%nFUNCTION %s %s %s%n", fn.getEntryPoint(), fn.getName(), fn.getBody());
                DecompileResults result = decompiler.decompileFunction(fn, 60, monitor);
                out.println(result.decompileCompleted() && result.getDecompiledFunction() != null
                    ? result.getDecompiledFunction().getC()
                    : "DECOMPILATION FAILED: " + result.getErrorMessage());

                for (Instruction instruction : currentProgram.getListing().getInstructions(fn.getBody(), true)) {
                    out.printf("%s %-30s %s%n", instruction.getAddress(),
                        HexFormat.of().formatHex(instruction.getBytes()), instruction);
                }
            }
            var relocations = currentProgram.getRelocationTable().getRelocations();
            while (relocations.hasNext()) {
                var reloc = relocations.next();
                out.printf("RELOC %s %s %04x %s%n", reloc.getAddress(), reloc.getStatus(),
                    reloc.getType(), reloc.getSymbolName());
            }
        } finally {
            decompiler.dispose();
        }
    }
}
