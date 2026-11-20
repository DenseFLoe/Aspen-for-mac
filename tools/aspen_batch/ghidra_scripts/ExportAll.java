// ExportAll.java — T1N (R1-NATIVE) Ghidra post-script.
// Contract: 01-plan.md §3.3 / taskbook T1N §5 (逐字照抄).
// args[0] = output directory (absolute).
// Writes <outdir>/<programName>.asm.txt and <outdir>/<programName>.c.txt for currentProgram.
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.util.headless.HeadlessScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

public class ExportAll extends HeadlessScript {

    private static String operands(Instruction ins) {
        StringBuilder sb = new StringBuilder();
        int n = ins.getNumOperands();
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            String s = null;
            try {
                s = ins.getDefaultOperandRepresentation(i);
            }
            catch (RuntimeException e) {
                s = "?";
            }
            sb.append(s == null ? "?" : s);
        }
        return sb.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            throw new IllegalArgumentException("ExportAll: args[0] (output directory) is required");
        }
        File outdir = new File(args[0]);
        if (!outdir.isDirectory() && !outdir.mkdirs()) {
            throw new IllegalStateException("ExportAll: cannot create output directory");
        }
        if (analysisTimeoutOccurred()) {
            // do not emit truncated artifacts as if they were a complete analysis
            try (Writer tw = new BufferedWriter(new OutputStreamWriter(
                new FileOutputStream(new File(outdir, currentProgram.getName() + ".timeout")),
                StandardCharsets.UTF_8))) {
                tw.write("analysisTimeoutOccurred\n");
            }
            println("EXPORT-TIMEOUT program=" + currentProgram.getName());
            return;
        }

        String programName = currentProgram.getName();
        FunctionManager fm = currentProgram.getFunctionManager();
        List<Function> funcs = new ArrayList<>();
        for (Function f : fm.getFunctions(true)) {
            funcs.add(f);
        }

        File asmFile = new File(outdir, programName + ".asm.txt");
        File cFile = new File(outdir, programName + ".c.txt");

        int blocks = 0;
        int decomposed = 0;
        int decompFail = 0;
        long asmLines = 0;
        long cLines = 0;

        DecompInterface dif = new DecompInterface();
        dif.toggleCCode(true);
        dif.toggleSyntaxTree(true);
        boolean opened = dif.openProgram(currentProgram);
        if (!opened) {
            println("EXPORT-WARN decompiler openProgram failed; all functions will be DECOMP-FAIL");
        }

        try (Writer aw = new BufferedWriter(
            new OutputStreamWriter(new FileOutputStream(asmFile), StandardCharsets.UTF_8))) {
            aw.write("# LANG " + currentProgram.getLanguageID().toString() + "\n");
            aw.write("# BASE 0x" + Long.toHexString(currentProgram.getImageBase().getOffset()) + "\n");
            // BLOCKS is written after the walk; reserve this line and rewrite below is not possible
            // with a stream, so the header is emitted first with the count of functions collected.
            aw.write("# BLOCKS " + funcs.size() + "\n");
            asmLines += 3;
            for (Function f : funcs) {
                Address ep = f.getEntryPoint();
                aw.write("FUNC " + ep + " " + f.getName() + "\n");
                asmLines++;
                try {
                    InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
                    while (it.hasNext()) {
                        Instruction ins = it.next();
                        aw.write("  " + ins.getAddress() + ": " + ins.getMnemonicString() + " " + operands(ins) + "\n");
                        asmLines++;
                    }
                }
                catch (RuntimeException e) {
                    aw.write("  ; instruction-read-error " + e.getClass().getSimpleName() + "\n");
                    asmLines++;
                }
                aw.write("ENDFUNC\n");
                asmLines++;
                blocks++;
            }
        }

        try (Writer cw = new BufferedWriter(
            new OutputStreamWriter(new FileOutputStream(cFile), StandardCharsets.UTF_8))) {
            for (Function f : funcs) {
                Address ep = f.getEntryPoint();
                String fname = f.getName();
                String body = null;
                String failClass = null;
                try {
                    if (!opened) {
                        failClass = "DecompilerUnavailable";
                    }
                    else {
                        DecompileResults res = dif.decompileFunction(f, 30, monitor);
                        if (res == null) {
                            failClass = "NullDecompileResults";
                        }
                        else if (!res.decompileCompleted()) {
                            String msg = res.getErrorMessage();
                            if (res.isTimedOut()) {
                                failClass = "function_timeout";
                            }
                            else if (res.isCancelled()) {
                                failClass = "cancelled";
                            }
                            else {
                                failClass = "DecompileIncomplete" + (msg == null ? "" : ":" + msg.replace('\n', ' '));
                            }
                        }
                        else {
                            body = res.getDecompiledFunction().getC();
                            if (body == null || body.isBlank()) {
                                body = null;
                                failClass = "EmptyDecompiledFunction";
                            }
                        }
                    }
                }
                catch (Exception e) {
                    failClass = e.getClass().getSimpleName();
                }
                catch (Throwable t) {
                    failClass = t.getClass().getSimpleName();
                }
                if (failClass != null || body == null) {
                    cw.write("// DECOMP-FAIL " + ep + " " + fname + " "
                        + (failClass == null ? "EmptyDecompiledFunction" : failClass) + "\n");
                    cLines++;
                    decompFail++;
                }
                else {
                    cw.write("// FUNC " + ep + " " + fname + "\n");
                    cLines++;
                    for (String line : body.split("\n", -1)) {
                        cw.write(line + "\n");
                        cLines++;
                    }
                    cw.write("// ENDFUNC\n");
                    cLines++;
                    decomposed++;
                }
            }
        }
        finally {
            dif.dispose();
        }

        println("EXPORT program=" + programName + " blocks=" + blocks + " funcs=" + funcs.size()
            + " decompiled=" + decomposed + " decomp_fail=" + decompFail + " asm_lines=" + asmLines
            + " c_lines=" + cLines);
        if (blocks != funcs.size()) {
            println("EXPORT-WARN blocks=" + blocks + " != funcs=" + funcs.size());
        }
    }
}
