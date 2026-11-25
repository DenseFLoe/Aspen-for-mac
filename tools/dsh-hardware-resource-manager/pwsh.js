import { AsyncLocalStorage } from 'node:async_hooks';
import SandboxPwshExecutor from '@deepseek-ai/dsh-pwsh-sandbox';
import { authoritySnapshot } from './authority.js';

const pwshCalls = new AsyncLocalStorage();
const electronRunners = new WeakSet();

export default class ResourcePwshExecutor extends SandboxPwshExecutor {
  static inject = [...SandboxPwshExecutor.inject, 'dshHardwareResourceManager'];

  constructor(ctx, config) {
    super(ctx, config);
    ctx.on('tools/execute', (exec, next) => {
      const session = exec.name === 'pwsh' ? exec.agent?.session : undefined;
      if (!session) return next();
      const authority = authoritySnapshot(ctx.sandboxPolicy.resolve({ session }));
      return pwshCalls.run({ session, authority }, next);
    });
  }

  async executeArgv(spec, argvOrPrepare, onStarted) {
    const manager = this.ctx.get('dshHardwareResourceManager');
    const call = pwshCalls.getStore();
    const standingAuthority = call?.authority ?? authoritySnapshot(this.ctx.sandboxPolicy.resolve());
    const verifyAuthority = () => {
      const current = this.ctx.sandboxPolicy.resolve({ session: call?.session });
      if (authoritySnapshot(current) !== standingAuthority) {
        throw new Error('DSH PowerShell authority changed while preparing the command.');
      }
    };
    let permit;
    try {
      const processHandle = await super.executeArgv(spec, async signal => {
        verifyAuthority();
        const argv = typeof argvOrPrepare === 'function' ? await argvOrPrepare(signal) : argvOrPrepare;
        signal.throwIfAborted();
        permit = await manager.acquire(signal);
        try {
          signal.throwIfAborted();
          permit.signal.throwIfAborted();
          verifyAuthority();
          const guarded = manager.wrapWorker(argv, permit);
          if (process.versions.electron && argv[0].toLowerCase() === process.execPath.toLowerCase()) {
            electronRunners.add(guarded);
          }
          return guarded;
        } catch (error) {
          permit.release();
          throw error;
        }
      }, onStarted);
      const release = () => permit?.release();
      void processHandle.done.then(release, release);
      return processHandle;
    } catch (error) {
      permit?.release();
      throw error;
    }
  }

  spawnSpec(spec, stdoutMaxBytes, signal, argv) {
    const spawn = super.spawnSpec(spec, stdoutMaxBytes, signal, argv);
    if (electronRunners.has(argv)) {
      spawn.env = { ...spawn.env, ELECTRON_RUN_AS_NODE: '1' };
    }
    return spawn;
  }
}
