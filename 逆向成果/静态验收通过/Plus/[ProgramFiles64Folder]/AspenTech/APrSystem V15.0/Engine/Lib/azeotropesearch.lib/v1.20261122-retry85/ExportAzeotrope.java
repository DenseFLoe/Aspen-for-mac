//@category Aspen
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.program.model.symbol.SourceType;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;

public class ExportAzeotrope extends GhidraScript {
    @Override
    protected void run() throws Exception {
        var listing = currentProgram.getListing();
        var output = Path.of(getScriptArgs()[0], currentProgram.getName() + ".txt");
        try (var out = new PrintWriter(Files.newBufferedWriter(output))) {
            out.printf("FORMAT\t%s\t%s\t%s%n", currentProgram.getExecutableFormat(),
                currentProgram.getLanguageID(), currentProgram.getCompilerSpec().getCompilerSpecID());
            for (var block : currentProgram.getMemory().getBlocks()) {
                out.printf("BLOCK\t%s\t%s\t%s\t%b\t%b%n", block.getName(), block.getStart(),
                    block.getEnd(), block.isInitialized(), block.isExecute());
            }
            for (var symbol : currentProgram.getSymbolTable().getAllSymbols(true)) {
                if (symbol.getSource() == SourceType.DEFAULT) continue;
                out.printf("SYMBOL\t%s\t%s\t%s%n", symbol.getAddress(), symbol.getSymbolType(), symbol.getName(true));
            }
            var relocations = currentProgram.getRelocationTable().getRelocations();
            while (relocations.hasNext()) {
                var rel = relocations.next();
                out.printf("RELOC\t%s\t%x\t%s\t%s%n", rel.getAddress(), rel.getType(),
                    rel.getStatus(), rel.getSymbolName());
            }
            var decompiler = new DecompInterface();
            try {
                if (!decompiler.openProgram(currentProgram)) throw new Exception(decompiler.getLastMessage());
                for (var function : listing.getFunctions(true)) {
                    if (function.isExternal()) continue;
                    out.printf("FUNCTION\t%s\t%s\t%s%n", function.getName(), function.getEntryPoint(), function.getBody());
                    var result = decompiler.decompileFunction(function, 60, monitor);
                    if (result.decompileCompleted()) out.print(result.getDecompiledFunction().getC());
                    else out.printf("ERROR\t%s%n", result.getErrorMessage());
                    out.println("END_FUNCTION");
                }
            } finally {
                decompiler.dispose();
            }
            for (var instruction : listing.getInstructions(true)) {
                out.printf("INSN\t%s\t%d\t%s", instruction.getAddress(), instruction.getLength(), instruction);
                for (var reference : instruction.getReferencesFrom()) {
                    out.printf("\t%s:%s", reference.getReferenceType(), reference.getToAddress());
                }
                out.println();
            }
        }
    }
}