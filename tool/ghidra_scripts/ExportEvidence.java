// ExportEvidence.java -- tool-neutral per-function export: EA, SIZE, real bytes, INSTR, pseudo-C.
// args[0] = output directory (absolute). args[1] = optional JSON-ish anchor list file (one hex RVA per line).
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.util.headless.HeadlessScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;

public class ExportEvidence extends HeadlessScript {

    private static String hex(byte[] b) {
        StringBuilder sb = new StringBuilder();
        for (byte x : b) sb.append(String.format("%02x", x));
        return sb.toString();
    }

    private static String safe(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) sb.append(Character.isLetterOrDigit(c) || c == '_' || c == '.' || c == '@' || c == '$' ? c : '_');
        String r = sb.toString();
        return r.length() > 80 ? r.substring(0, 80) : r;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) throw new IllegalArgumentException("ExportEvidence: output directory required");
        File outdir = new File(args[0]);
        if (!outdir.isDirectory() && !outdir.mkdirs()) throw new IllegalStateException("cannot create outdir");
        File cdir = new File(outdir, "c");
        if (!cdir.isDirectory() && !cdir.mkdirs()) throw new IllegalStateException("cannot create cdir");

        long base = currentProgram.getImageBase().getOffset();
        if (args.length > 1 && new File(args[1]).isFile()) {
            List<String> lines = Files.readAllLines(Paths.get(args[1]));
            Listing listing = currentProgram.getListing();
            for (String ln : lines) {
                ln = ln.trim();
                if (ln.isEmpty()) continue;
                long rva = Long.decode(ln);
                Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + rva);
                if (getFunctionAt(a) == null) {
                    try {
                        disassemble(a);
                        new CreateFunctionCmd(a).applyTo(currentProgram, monitor);
                    } catch (Exception e) {
                        println("ANCHOR-FAIL " + ln + " " + e.getClass().getSimpleName());
                    }
                }
            }
        }
        if (analysisTimeoutOccurred()) {
            try (Writer w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(outdir, "analysis.timeout")), StandardCharsets.UTF_8))) {
                w.write("analysisTimeoutOccurred\n");
            }
            return;
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        List<Function> funcs = new ArrayList<>();
        for (Function f : fm.getFunctions(true)) funcs.add(f);

        DecompInterface dif = new DecompInterface();
        dif.toggleCCode(true);
        dif.openProgram(currentProgram);

        try (Writer fw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(outdir, "funcs.tsv")), StandardCharsets.UTF_8));
             Writer iw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(outdir, "instr.tsv")), StandardCharsets.UTF_8))) {
            fw.write("entry\tend\tname\tdecomp\tcfile\n");
            iw.write("entry\taddr\tbytes\ttext\n");
            for (Function f : funcs) {
                Address ep = f.getEntryPoint();
                long entry = ep.getOffset() - base;
                long end = f.getBody().getMaxAddress().getOffset() - base + 1;
                int ok = 0;
                String cname = String.format("%08x__%s.c", entry, safe(f.getName()));
                File cf = new File(cdir, cname);
                try {
                    DecompileResults res = dif.decompileFunction(f, 120, monitor);
                    if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                        String c = res.getDecompiledFunction().getC();
                        try (Writer cw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(cf), StandardCharsets.UTF_8))) {
                            cw.write(c);
                        }
                        ok = 1;
                    }
                } catch (Exception e) {
                    ok = 0;
                }
                if (ok == 0) {
                    try (Writer cw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(cf), StandardCharsets.UTF_8))) {
                        cw.write("/* decompile-unavailable for " + f.getName() + " at EA " + String.format("%x", entry) + " */\n");
                    }
                }
                fw.write(String.format("%x\t%x\t%s\t%d\t%s%n", entry, end, f.getName(), ok, "c/" + cname));
                try {
                    InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
                    while (it.hasNext()) {
                        Instruction ins = it.next();
                        long at = ins.getAddress().getOffset() - base;
                        iw.write(String.format("%x\t%x\t%s\t%s%n", entry, at, hex(ins.getBytes()),
                                 ins.getMnemonicString() + " " + ins.getDefaultOperandRepresentation(0)));
                    }
                } catch (RuntimeException e) {
                    iw.write(String.format("%x\t%x\t\t; instruction-read-error%n", entry, entry));
                }
            }
        }
        dif.dispose();
        Files.write(new File(outdir, "done.txt").toPath(), Arrays.asList("ok"));
    }
}
