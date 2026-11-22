//@category Aspen
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.SourceType;

public class RepairFuneq2Analysis extends GhidraScript {
    @Override
    protected void run() throws Exception {
        var memory = currentProgram.getMemory();
        var text = memory.getBlock(".text").getStart();
        Address table = null;
        for (var block : memory.getBlocks()) {
            if (block.getName().equals(".rdata") && block.getSize() == 24) {
                if (table != null) throw new Exception("Jump table block is ambiguous");
                table = block.getStart();
            }
        }
        if (table == null) throw new Exception("Jump table not found");
        var leaOperand = text.add(0x36a);
        var delta = table.subtract(leaOperand.add(4));
        memory.setInt(leaOperand, Math.toIntExact(delta));
        var jump = text.add(0x375);
        if (!disassemble(jump)) throw new Exception("Cannot disassemble indirect branch");
        var references = currentProgram.getReferenceManager();
        for (var reference : references.getReferencesFrom(jump)) {
            if (reference.getReferenceType().isJump()) references.delete(reference);
        }
        for (int index = 0; index < 4; index++) {
            var field = table.add(4 * index);
            int addend = memory.getInt(field);
            var destination = text.add(addend - 4 * (index + 1));
            memory.setInt(field, Math.toIntExact(destination.subtract(table)));
            references.addMemoryReference(jump,destination,RefType.COMPUTED_JUMP,SourceType.USER_DEFINED,0);
            disassemble(destination);
            println("COFF switch entry " + index + " " + field + " -> " + destination);
        }
    }
}