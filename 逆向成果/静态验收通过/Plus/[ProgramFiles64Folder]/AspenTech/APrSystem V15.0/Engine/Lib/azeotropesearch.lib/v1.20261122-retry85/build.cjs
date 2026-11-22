const fs = require('node:fs');
const path = require('node:path');
const {execFileSync} = require('node:child_process');
const {createHash} = require('node:crypto');

const [assembler, outputFile] = process.argv.slice(2);
if (!assembler || !outputFile) throw Error('Usage: node build.cjs NASM_EXE OUTPUT_LIB');
const layout = require('./archive-layout.json');
const output = path.resolve(outputFile);
const scratch = fs.mkdtempSync(path.join(path.dirname(output), 'azeotropesearch-build-'));
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const sameHash = (bytes, expected) => hash(bytes) === expected;
const archive = Buffer.alloc(layout.size);
const verification = [];
try {
    archive.write('!<arch>\n',0,'ascii');
    let cursor = 8;
    for (const entry of layout.entries) {
        if (entry.offset !== cursor ||
            Buffer.byteLength(entry.memberHeader,'ascii') !== 60) throw Error('Archive layout mismatch');
        const item = Buffer.alloc(entry.size);
        if (entry.assembly) {
            const assembly = path.join(__dirname,entry.assembly);
            const bin = path.join(scratch,'payload.bin');
            fs.copyFileSync(assembly,path.join(scratch,'member.asm'));
            execFileSync(path.resolve(assembler), ['-Werror','-f','bin','-o','payload.bin','member.asm'],
                {cwd:scratch,stdio:'inherit'});
            const assembled = fs.readFileSync(bin);
            let index = 0;
            const written = new Uint8Array(item.length);
            function write(bytes, offset) {
                if (offset < 0 || offset+bytes.length > item.length) throw Error('Out-of-bounds COFF region');
                for (let i=offset;i<offset+bytes.length;i++) {
                    if (written[i]) throw Error('Overlapping COFF regions');
                    written[i] = 1;
                }
                bytes.copy(item,offset);
            }
            for (const chunk of entry.chunks) {
                if (index+chunk.length>assembled.length) throw Error('Missing assembled section for '+entry.assembly);
                write(assembled.subarray(index,index+chunk.length),chunk.fileOffset);
                index += chunk.length;
            }
            if (index !== assembled.length) throw Error('Unexpected assembled length for '+entry.assembly);
            for (const record of entry.records) write(Buffer.from(record.bytes,'hex'),record.offset);
            if (!written.every(Boolean)) throw Error('Incomplete COFF object');
            verification.push({member:entry.assembly, sha256:hash(item), matchesOriginal:sameHash(item,entry.digest)});
        } else {
            const directory = Buffer.from(entry.directoryBytes,'hex');
            if (directory.length !== item.length || !sameHash(directory,entry.digest)) throw Error('Archive directory data changed');
            directory.copy(item);
        }
        archive.write(entry.memberHeader,cursor,60,'ascii');
        cursor += 60;
        item.copy(archive,cursor);
        cursor += item.length;
        const pad = Buffer.from(entry.padding,'hex');
        pad.copy(archive,cursor);
        cursor += pad.length;
    }
    if (cursor !== archive.length) throw Error('Archive length mismatch');
    if (!sameHash(archive,layout.originalSha256) && !process.env.ASPEN_ALLOW_EDITED_LIB) {
        throw Error('Library digest changed; fixed-layout edits require explicit ASPEN_ALLOW_EDITED_LIB=1 after reviewing relocations and unwind metadata');
    }
    fs.writeFileSync(output,archive,{flag:'wx'});
    console.log(JSON.stringify({archiveSha256:hash(archive), matchesOriginal:sameHash(archive,layout.originalSha256),
        bytes:archive.length, members:verification},null,2));
} finally {
    const payload = path.join(scratch,'payload.bin');
    if (fs.existsSync(payload)) fs.unlinkSync(payload);
    const source = path.join(scratch,'member.asm');
    if (fs.existsSync(source)) fs.unlinkSync(source);
    fs.rmdirSync(scratch);
}
