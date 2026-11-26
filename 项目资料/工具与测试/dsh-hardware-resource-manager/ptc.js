import { availableParallelism } from 'node:os';
import NodePtcRuntime from '@deepseek-ai/dsh-ptc-runtime-node';
import { authoritySnapshot } from './authority.js';

function evaluatorQueue(limit, admissionOpen) {
  const waiting = new Set();
  let active = 0;
  let closed = false;
  let checking = false;
  let retry;

  async function admit() {
    if (checking || retry || closed || active >= limit || waiting.size === 0) return;
    checking = true;
    try {
      while (!closed && active < limit && waiting.size > 0) {
        const ticket = waiting.values().next().value;
        const open = await admissionOpen();
        if (closed || !waiting.has(ticket)) continue;
        if (!open) {
          retry = setTimeout(() => { retry = undefined; void admit(); }, 250);
          return;
        }
        waiting.delete(ticket);
        ticket.detach();
        active++;
        ticket.resolve(() => {
          active--;
          void admit();
        });
      }
    } catch {
      cancel(() => true, 'The hardware pressure check failed before PTC evaluation could start.');
    } finally {
      checking = false;
    }
  }

  function cancel(test, message) {
    for (const ticket of waiting) {
      if (test(ticket)) ticket.cancel(message);
    }
  }

  return {
    acquire(signal, sessionId, standingMode, owner) {
      if (closed) return Promise.resolve('PTC evaluator stopped while waiting for resources.');
      if (signal?.aborted) return Promise.resolve('PTC execution canceled before evaluator admission.');
      return new Promise(resolve => {
        const onAbort = () => ticket.cancel('PTC execution canceled before evaluator admission.');
        const ticket = {
          sessionId,
          standingMode,
          owner,
          resolve,
          detach: () => signal?.removeEventListener('abort', onAbort),
          cancel(message) {
            waiting.delete(ticket);
            ticket.detach();
            resolve(message);
          },
        };
        waiting.add(ticket);
        signal?.addEventListener('abort', onAbort, { once: true });
        void admit();
      });
    },
    cancelSession(sessionId, mode) {
      cancel(ticket => ticket.sessionId === sessionId && ticket.standingMode !== mode,
        'Sandbox authority changed while waiting for a PTC evaluator.');
    },
    cancelOwner(owner) {
      cancel(ticket => ticket.owner === owner, 'PTC state owner was released before evaluator admission.');
    },
    close() {
      closed = true;
      clearTimeout(retry);
      cancel(() => true, 'PTC evaluator stopped while waiting for resources.');
    },
    status: () => ({ waiting: waiting.size, active, maxActive: limit, closed }),
  };
}

function aborted(policy, message) {
  return {
    logs: [],
    error: { kind: 'abort', message },
    ...(policy && { sandbox: { mode: policy.mode, denied: false } }),
  };
}

export default class ResourcePtcRuntime extends NodePtcRuntime {
  static inject = [...NodePtcRuntime.inject, 'dshHardwareResourceManager'];

  constructor(ctx, config) {
    super(ctx, config);
    const manager = ctx.get('dshHardwareResourceManager');
    const queue = evaluatorQueue(Math.min(8, availableParallelism()), () => manager.evaluatorAdmissionOpen());
    this.evaluatorQueue = queue;
    this.evaluatorOwners = new WeakSet();
    ctx.on('session/event', (session, event) => {
      if (event.type === 'sandbox/mode') queue.cancelSession(session.id, event.data.mode);
    }, { global: true });
    ctx.effect(() => () => queue.close(), 'DSH PTC evaluator admission');
  }

  evaluatorStatus() {
    return this.evaluatorQueue.status();
  }

  async run(spec) {
    const policy = spec.sandboxPolicy;
    if (this.disposed || policy === undefined) return super.run(spec);
    const { sessionId } = policy;
    const findSession = () => sessionId === undefined ? undefined : this.ctx.get('sessions')?.get(sessionId);
    const session = findSession();
    const currentPolicy = this.ctx.sandboxPolicy.resolve({ session });
    const standing = authoritySnapshot(currentPolicy);
    const owner = this.retainsState ? spec.stateOwner : undefined;
    if (owner !== undefined && this.evaluatorOwners.has(owner)) {
      throw new Error('persistent PTC does not accept concurrent runs for one state owner');
    }
    if (owner !== undefined) this.evaluatorOwners.add(owner);
    let release;
    try {
      const decision = await this.evaluatorQueue.acquire(spec.signal, sessionId, currentPolicy.mode, spec.stateOwner);
      if (typeof decision === 'string') return aborted(policy, decision);
      release = decision;
      if (spec.signal?.aborted || this.disposed) {
        return aborted(policy, 'PTC execution canceled before evaluator admission.');
      }
      if (session !== findSession() || standing !== authoritySnapshot(this.ctx.sandboxPolicy.resolve({ session }))) {
        return aborted(policy, 'Sandbox authority changed while waiting for a PTC evaluator.');
      }
      return await super.run(spec);
    } finally {
      if (owner !== undefined) this.evaluatorOwners.delete(owner);
      release?.();
    }
  }

  release(owner) {
    if (owner !== undefined) this.evaluatorQueue.cancelOwner(owner);
    return super.release(owner);
  }
}
