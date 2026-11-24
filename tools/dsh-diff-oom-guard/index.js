import { spawnSync } from 'node:child_process';
import { createHash } from 'node:crypto';
import {
  existsSync, mkdirSync, mkdtempSync, readFileSync, renameSync, rmdirSync, unlinkSync, writeFileSync,
} from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

export const name = 'dsh-diff-oom-guard';

const sourceFile = fileURLToPath(new URL('./native/DiffGuard.cs', import.meta.url));

function gnuDiffPath(explicitPath) {
  if (explicitPath !== undefined && (typeof explicitPath !== 'string' || !path.isAbsolute(explicitPath))) {
    throw new Error('gnuDiff must be an absolute path to GNU diff.exe.');
  }
  const gitRoots = [
    process.env.ProgramFiles && path.join(process.env.ProgramFiles, 'Git'),
    process.env.LOCALAPPDATA && path.join(process.env.LOCALAPPDATA, 'Programs', 'Git'),
    path.join(os.homedir(), '.cache', 'codex-runtimes', 'codex-primary-runtime',
      'dependencies', 'native', 'git'),
  ];
  const candidates = explicitPath
    ? [explicitPath]
    : gitRoots.filter(Boolean).map(root => path.join(root, 'usr', 'bin', 'diff.exe'));

  for (const candidate of candidates) {
    if (!existsSync(candidate) || path.basename(candidate).toLowerCase() !== 'diff.exe') continue;
    const probe = spawnSync(candidate, ['--version'], {
      encoding: 'utf8', windowsHide: true, timeout: 5_000, maxBuffer: 16_384,
    });
    if (probe.status === 0 && /^diff \(GNU diffutils\)/m.test(probe.stdout)) return candidate;
  }
  throw new Error('GNU diff was not found. Install Git for Windows or set gnuDiff to its diff.exe.');
}

function bashQuote(value) {
  return "'" + value.replaceAll("'", "'\\''") + "'";
}

function toNiubashPath(absolutePath) {
  const match = /^([a-z]):[\\/](.*)$/i.exec(absolutePath);
  if (!match) throw new Error('The DSH home for Diff OOM Guard must be on a local Windows drive.');
  return '/' + match[1].toLowerCase() + '/' + match[2].replaceAll('\\', '/');
}

function startupScript(directory, inheritedStartup) {
  const startup = inheritedStartup ? `. ${bashQuote(inheritedStartup)}\n` : '';
  return startup + [
    'if [ "${DSH_SHELL-}" = 1 ] && [ "${NIU_SKIP_WINUXCMD_ACTIVATION-}" = 1 ] && [ -n "${NIU_ROOT-}" ]; then',
    `  export PATH=${bashQuote(toNiubashPath(directory))}:"$PATH"`,
    '  hash -r',
    'fi',
    '',
  ].join('\n');
}

function buildGuard(root, gnuDiff, inheritedStartup) {
  const source = readFileSync(sourceFile);
  const key = createHash('sha256')
    .update(source).update(readFileSync(fileURLToPath(import.meta.url)))
    .update('\0' + gnuDiff + '\0' + (inheritedStartup ?? ''))
    .digest('hex').slice(0, 24);
  const directory = path.join(root, key);
  const bootstrap = path.join(directory, 'bash-env.sh');
  const script = startupScript(directory, inheritedStartup);
  const pathFile = path.join(directory, 'gnu-diff.txt');
  const binary = path.join(directory, 'diff.exe');
  const isReady = () => existsSync(bootstrap) && existsSync(binary) && existsSync(pathFile)
      && readFileSync(bootstrap, 'utf8') === script
      && readFileSync(pathFile, 'utf8') === gnuDiff;
  if (isReady()) return bootstrap;
  if (existsSync(directory)) throw new Error(`Diff Guard build directory is incomplete: ${directory}`);

  const compiler = path.join(process.env.WINDIR || 'C:\\Windows', 'Microsoft.NET',
    'Framework64', 'v4.0.30319', 'csc.exe');
  if (!existsSync(compiler)) throw new Error('The .NET Framework x64 C# compiler was not found.');
  mkdirSync(root, { recursive: true });
  const stage = mkdtempSync(path.join(root, 'build-'));
  const stagedExe = path.join(stage, 'diff.exe');
  const stagedPath = path.join(stage, 'gnu-diff.txt');
  const stagedStartup = path.join(stage, 'bash-env.sh');
  try {
    const result = spawnSync(compiler, [
      '/nologo', '/optimize+', '/platform:x64', '/target:exe', '/out:' + stagedExe, sourceFile,
    ], { encoding: 'utf8', windowsHide: true, timeout: 30_000, maxBuffer: 65_536 });
    if (result.status !== 0) {
      throw new Error('Could not build Diff Guard: ' +
        (result.error?.message || result.stderr || result.stdout || String(result.status)).trim());
    }
    writeFileSync(stagedPath, gnuDiff, { flag: 'wx' });
    writeFileSync(stagedStartup, script, { flag: 'wx' });
    try {
      renameSync(stage, directory);
    } catch (error) {
      if (!isReady()) throw error;
    }
  } finally {
    if (existsSync(stage)) {
      for (const file of [stagedExe, stagedPath, stagedStartup]) {
        if (existsSync(file)) unlinkSync(file);
      }
      rmdirSync(stage);
    }
  }
  return bootstrap;
}

export function apply(ctx, config = {}) {
  if (process.platform !== 'win32' || process.arch !== 'x64') return;
  const inheritedStartup = process.env.BASH_ENV;
  if (inheritedStartup && !path.isAbsolute(inheritedStartup)) {
    throw new Error('Diff Guard can chain an existing BASH_ENV only when it is an absolute file path.');
  }
  const root = path.resolve(process.env.DSH_HOME || path.join(os.homedir(), '.dsh'), name);
  const bootstrap = buildGuard(root, gnuDiffPath(config.gnuDiff), inheritedStartup);
  ctx.on('dispose', () => {
    if (process.env.BASH_ENV !== bootstrap) return;
    if (inheritedStartup === undefined) delete process.env.BASH_ENV;
    else process.env.BASH_ENV = inheritedStartup;
  });
  process.env.BASH_ENV = bootstrap;
}
