import { execFile, spawn } from 'node:child_process';
import path from 'node:path';
import { createInterface } from 'node:readline';

export class HostResourceQueue {
  #launch;
  #connection;
  #closed = false;

  constructor(executable, launch = spawn) {
    this.executable = executable;
    this.#launch = launch;
  }

  acquire(signal, operation) {
    signal?.throwIfAborted();
    if (operation !== undefined && operation !== 'stat') {
      throw new TypeError('Unsupported DSH resource request operation.');
    }
    if (this.#closed) throw new Error('The DSH resource queue has shut down.');
    const connection = this.#connection ?? this.#connect();
    const id = ++connection.sequence;
    return new Promise((resolve, reject) => {
      const cancellation = new AbortController();
      const cancel = () => {
        if (connection.requests.has(id)) this.#write(connection, `cancel ${id}`);
      };
      const abort = () => {
        this.#write(connection, `cancel ${id}`);
        this.#finish(connection, id, signal.reason);
      };
      connection.requests.set(id, { resolve, reject, cancellation, cancel, abort, signal, offered: false });
      signal?.addEventListener('abort', abort, { once: true });
      this.#write(connection, `${operation === 'stat' ? 'request-stat' : 'request'} ${id}`);
    });
  }

  wrapWorker(argv, permit) {
    if (!path.win32.isAbsolute(argv[0] ?? '') || !/^[a-f0-9]{32}$/.test(permit.token)) {
      throw new TypeError('A resource worker needs an absolute executable path and an active permit.');
    }
    return [this.executable, '--dsh-run-permitted', permit.token, ...argv];
  }

  evaluatorAdmissionOpen() {
    return new Promise((resolve, reject) => {
      execFile(this.executable, ['--dsh-evaluator-admission'], { windowsHide: true, timeout: 5_000 }, error => {
        if (!error) resolve(true);
        else if (error.code === 75) resolve(false);
        else reject(error);
      });
    });
  }

  #connect() {
    const child = this.#launch(this.executable, ['--dsh-host-queue'], {
      windowsHide: true, stdio: ['pipe', 'pipe', 'pipe'],
    });
    const connection = { child, requests: new Map(), sequence: 0, stopped: false };
    this.#connection = connection;
    const lines = createInterface({ input: child.stdout, crlfDelay: Infinity });
    lines.on('line', message => this.#receive(connection, message));
    child.stderr.resume();
    child.on('error', error => this.#fail(connection, error));
    child.stdin.on('error', error => this.#fail(connection, error));
    child.on('close', (code, signal) => this.#fail(connection,
      new Error(`The DSH resource queue stopped (${signal ?? code}).`)));
    return connection;
  }

  #receive(connection, message) {
    const [status, idText, value] = message.split(' ');
    const id = Number(idText);
    const request = connection.requests.get(id);
    if (!request) return;
    if (status === 'permit' && !request.offered && /^[a-f0-9]{32}$/.test(value ?? '')) {
      request.offered = true;
      request.resolve({
        token: value,
        bootstrap: path.win32.join(path.win32.dirname(this.executable), 'bash-env.sh'),
        signal: request.cancellation.signal,
        release: request.cancel,
      });
    } else if (status === 'claimed' && request.offered) {
      this.#finish(connection, id);
    } else if (status === 'error') {
      this.#finish(connection, id, new Error(Buffer.from(value ?? '', 'base64').toString('utf8') || 'Resource admission failed.'));
    } else if (status === 'cancelled') {
      this.#finish(connection, id, new Error('The resource request was cancelled.'));
    } else {
      this.#fail(connection, new Error('The DSH resource queue returned an invalid message.'));
    }
  }

  #write(connection, line) {
    if (connection.stopped) return;
    connection.child.stdin.write(line + '\n', error => {
      if (error) this.#fail(connection, error);
    });
  }

  #finish(connection, id, error) {
    const request = connection.requests.get(id);
    if (!request) return;
    connection.requests.delete(id);
    request.signal?.removeEventListener('abort', request.abort);
    if (error) {
      if (request.offered) request.cancellation.abort(error);
      else request.reject(error);
    }
    this.#endWhenDrained(connection);
  }

  #fail(connection, error) {
    if (connection.stopped) return;
    connection.stopped = true;
    if (this.#connection === connection) this.#connection = undefined;
    for (const id of connection.requests.keys()) this.#finish(connection, id, error);
    connection.child.stdin.destroy();
    if (connection.child.exitCode === null && connection.child.signalCode === null) connection.child.kill();
  }

  close() {
    this.#closed = true;
    if (this.#connection) this.#fail(this.#connection, new Error('The DSH resource queue has shut down.'));
  }

  retire() {
    this.#closed = true;
    const connection = this.#connection;
    if (!connection) return;
    // An exiting desktop must not be held open by a historical queue.
    // The native broker sees EOF and releases its tickets when the host exits.
    connection.child.unref?.();
    connection.child.stdin.unref?.();
    connection.child.stdout.unref?.();
    connection.child.stderr.unref?.();
    this.#endWhenDrained(connection);
  }

  #endWhenDrained(connection) {
    if (!this.#closed || connection.stopped || connection.requests.size !== 0) return;
    connection.stopped = true;
    if (this.#connection === connection) this.#connection = undefined;
    // No outstanding permit depends on this broker after all requests settle.
    connection.child.stdin.end();
  }
}
