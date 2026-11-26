import { spawnSync } from 'node:child_process';
import { createHash } from 'node:crypto';
import {
  copyFileSync, existsSync, mkdirSync, mkdtempSync, readFileSync, renameSync, rmdirSync, unlinkSync, writeFileSync,
} from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { HostResourceQueue } from './host-queue.js';

export const name = 'dsh-hardware-resource-manager';

const nativeSources = ['DiffGuard.cs', 'ToolBudget.cs', 'AdmissionQueue.cs', 'SharedObjects.cs', 'HostQueue.cs', 'HostEnvelope.cs', 'CpuGovernor.cs', 'MemoryPressure.cs']
  .map(file => fileURLToPath(new URL(`./native/${file}`, import.meta.url)));

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
  if (explicitPath !== undefined) throw new Error('The configured gnuDiff is not GNU diff.exe.');
  return undefined;
}

function bashQuote(value) {
  return "'" + value.replaceAll("'", "'\\''") + "'";
}

function toNiubashPath(absolutePath) {
  const match = /^([a-z]):[\\/](.*)$/i.exec(absolutePath);
  if (!match) throw new Error('The DSH hardware resource manager requires a local Windows drive.');
  return '/' + match[1].toLowerCase() + '/' + match[2].replaceAll('\\', '/');
}

function startupScript(directory, inheritedStartup) {
  const startup = inheritedStartup ? `. ${bashQuote(inheritedStartup)}\n` : '';
  const managedShell = 'if [ "${DSH_SHELL-}" = 1 ] && [ "${NIU_SKIP_WINUXCMD_ACTIVATION-}" = 1 ] && [ -n "${NIU_ROOT-}" ]; then';
  return [
    managedShell,
    `  ${bashQuote(toNiubashPath(path.join(directory, 'dsh-resource.exe')))} --dsh-admit-shell "\${DSH_RESOURCE_PERMIT-}" || exit $?`,
    '  unset DSH_RESOURCE_PERMIT',
    'fi',
    startup + managedShell,
    `  export PATH=${bashQuote(toNiubashPath(directory))}:"$PATH"`,
    '  hash -r',
    'fi',
    '',
  ].join('\n');
}

function buildManager(root, gnuDiff, inheritedStartup) {
  const hash = createHash('sha256');
  for (const source of nativeSources) hash.update(readFileSync(source));
  const key = hash
    .update(readFileSync(fileURLToPath(import.meta.url)))
    .update('\0' + (gnuDiff ?? '') + '\0' + (inheritedStartup ?? ''))
    .digest('hex').slice(0, 24);
  const directory = path.join(root, key);
  const bootstrap = path.join(directory, 'bash-env.sh');
  const script = startupScript(directory, inheritedStartup);
  const pathFile = path.join(directory, 'gnu-diff.txt');
  const binary = path.join(directory, 'dsh-resource.exe');
  const isReady = () => existsSync(bootstrap) && existsSync(binary)
      && readFileSync(bootstrap, 'utf8') === script
      && (!gnuDiff || (existsSync(pathFile) && readFileSync(pathFile, 'utf8') === gnuDiff
        && existsSync(path.join(directory, 'diff.exe'))));
  if (isReady()) return bootstrap;
  if (existsSync(directory)) throw new Error(`DSH resource manager build directory is incomplete: ${directory}`);

  const compiler = path.join(process.env.WINDIR || 'C:\\Windows', 'Microsoft.NET',
    'Framework64', 'v4.0.30319', 'csc.exe');
  if (!existsSync(compiler)) throw new Error('The .NET Framework x64 C# compiler was not found.');
  mkdirSync(root, { recursive: true });
  const stage = mkdtempSync(path.join(root, 'build-'));
  const stagedExe = path.join(stage, 'dsh-resource.exe');
  const stagedDiff = path.join(stage, 'diff.exe');
  const stagedPath = path.join(stage, 'gnu-diff.txt');
  const stagedStartup = path.join(stage, 'bash-env.sh');
  try {
    const result = spawnSync(compiler, [
      '/nologo', '/optimize+', '/platform:x64', '/target:exe', '/out:' + stagedExe,
      ...nativeSources,
    ], { encoding: 'utf8', windowsHide: true, timeout: 30_000, maxBuffer: 65_536 });
    if (result.status !== 0) {
      throw new Error('Could not build the DSH resource manager: ' +
        (result.error?.message || result.stderr || result.stdout || String(result.status)).trim());
    }
    if (gnuDiff) {
      copyFileSync(stagedExe, stagedDiff);
      writeFileSync(stagedPath, gnuDiff, { flag: 'wx' });
    }
    writeFileSync(stagedStartup, script, { flag: 'wx' });
    // Windows can briefly hold the freshly compiled executable open during scanning.
    const retrySignal = new Int32Array(new SharedArrayBuffer(4));
    for (let attempt = 0; ; attempt++) {
      try {
        renameSync(stage, directory);
        break;
      } catch (error) {
        if (isReady()) break;
        if (attempt === 15 || !['EPERM', 'EACCES', 'EBUSY'].includes(error.code)) throw error;
        Atomics.wait(retrySignal, 0, 0, 150);
      }
    }
  } finally {
    if (existsSync(stage)) {
      for (const file of [stagedExe, stagedDiff, stagedPath, stagedStartup]) {
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
    throw new Error('The DSH resource manager requires an absolute BASH_ENV path.');
  }
  const root = path.resolve(process.env.DSH_HOME || path.join(os.homedir(), '.dsh'), name);
  const bootstrap = buildManager(root, gnuDiffPath(config.gnuDiff), inheritedStartup);
  const hostQueue = new HostResourceQueue(path.join(path.dirname(bootstrap), 'dsh-resource.exe'));
  ctx.provide('dshHardwareResourceManager', hostQueue);
  ctx.on('dispose', () => {
    hostQueue.retire();
    if (process.env.BASH_ENV !== bootstrap) return;
    if (inheritedStartup === undefined) delete process.env.BASH_ENV;
    else process.env.BASH_ENV = inheritedStartup;
  });
  process.env.BASH_ENV = bootstrap;
}
