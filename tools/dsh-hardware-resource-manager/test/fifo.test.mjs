import assert from 'node:assert/strict';
import { execFileSync, spawn, spawnSync } from 'node:child_process';
import { randomUUID } from 'node:crypto';
import { mkdtempSync, readdirSync, rmdirSync, unlinkSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import path from 'node:path';
import { test } from 'node:test';
import { setTimeout as delay } from 'node:timers/promises';
import { fileURLToPath } from 'node:url';
import { HostResourceQueue } from '../host-queue.js';

const here = path.dirname(fileURLToPath(import.meta.url));
const native = path.resolve(here, '../native');

async function eventually(check, description) {
  const deadline = performance.now() + 5_000;
  while (performance.now() < deadline) {
    if (check()) return;
    await delay(50);
  }
  assert.fail(description);
}

test('Windows resource slots preserve FIFO, reclaim cancelled tickets and leave CPU headroom', {
  skip: process.platform !== 'win32' || process.arch !== 'x64',
  timeout: 90_000,
}, async t => {
  const directory = mkdtempSync(path.join(tmpdir(), 'dsh-fifo-test-'));
  const exe = path.join(directory, 'fixture.exe');
  const headroom = path.join(directory, 'headroom');
  let prefix = `Local\\DSHToolBudget-test-${randomUUID()}`;
  const tasks = [];
  let sampleCpu = false;
  let sampleMemory = false;
  const fixtureEnv = () => ({
    ...process.env,
    ...(sampleCpu && { DSH_RESOURCE_FIXTURE_CPU: directory }),
    ...(sampleMemory && { DSH_RESOURCE_FIXTURE_MEMORY: directory }),
  });
  t.after(async () => {
    for (const task of tasks) {
      writeFileSync(task.release, '');
      if (!task.done && !/^admitted\r?$/m.test(task.output)) task.child.kill();
    }
    await Promise.all(tasks.map(task => task.exit));
    for (const task of tasks) {
      const descendant = /^descendant (\d+)\r?$/m.exec(task.output);
      if (descendant) await eventually(() => {
        try { process.kill(Number(descendant[1]), 0); return false; }
        catch (error) { if (error.code === 'ESRCH') return true; throw error; }
      }, 'fixture descendant did not exit');
    }
    for (const file of readdirSync(directory)) {
      await eventually(() => {
        try { unlinkSync(path.join(directory, file)); return true; }
        catch (error) {
          if (error.code === 'EPERM' || error.code === 'EBUSY') return false;
          if (error.code === 'ENOENT') return true;
          throw error;
        }
      }, `the native fixture kept ${file} open after its test ended`);
    }
    rmdirSync(directory);
  });

  const compiler = path.join(process.env.WINDIR || 'C:\\Windows', 'Microsoft.NET',
    'Framework64', 'v4.0.30319', 'csc.exe');
  execFileSync(compiler, [
    '/nologo', '/warnaserror+', '/platform:x64', '/main:Fixture', `/out:${exe}`,
    path.join(here, 'Fixture.cs'),
    ...readdirSync(native).filter(file => file.endsWith('.cs')).map(file => path.join(native, file)),
  ], { windowsHide: true, timeout: 15_000 });

  await t.test('host budget caps aggregate commit and CPU without using a command slot', () => {
    const guard = path.join(directory, 'dsh-resource.exe');
    execFileSync(compiler, [
      '/nologo', '/warnaserror+', '/platform:x64', `/out:${guard}`,
      ...readdirSync(native).filter(file => file.endsWith('.cs')).map(file => path.join(native, file)),
    ], { windowsHide: true, timeout: 15_000 });
    const options = { encoding: 'utf8', windowsHide: true, timeout: 15_000 };
    const control = execFileSync(exe, ['host-memory', path.join(directory, 'host-control'), 'control'], options);
    assert.match(control, /both control allocations succeeded/);
    const bounded = execFileSync(guard, ['--dsh-run-host', '256', exe,
      'host-memory', path.join(directory, 'host-bounded'), 'bounded'], options);
    assert.match(bounded, /host aggregate limit enforced/);
    const rejected = spawnSync(guard, ['--dsh-run-host', '25000000', exe,
      'host-memory', path.join(directory, 'host-rejected'), 'bounded'], options);
    assert.equal(rejected.status, 75);
    assert.match(rejected.stderr, /headroom/);
  });

  await t.test('outer host commit gates both permit offer and claim', () => {
    const capacity = path.join(directory, 'host-admission-allowed');
    const release = path.join(directory, 'host-admission-finished');
    writeFileSync(capacity, '');
    const scope = `Local\\DSHToolBudget-host-admission-${randomUUID()}`;
    const result = spawnSync(exe, ['--dsh-run-host', '448', exe,
      'host-admission', scope, capacity, release], {
      encoding: 'utf8', windowsHide: true, timeout: 20_000, env: fixtureEnv(),
    });
    assert.equal(result.status, 0, JSON.stringify({ stdout: result.stdout, stderr: result.stderr, error: result.error?.message }));
    assert.match(result.stdout, /host memory verified at offer and at claim/);
  });

  await t.test('external CPU pressure throttles a live host job and permits gradual recovery', async () => {
    const clock = mkdtempSync(path.join(tmpdir(), 'dsh-host-cpu-clock-'));
    t.after(() => {
      for (const file of readdirSync(clock)) unlinkSync(path.join(clock, file));
      rmdirSync(clock);
    });
    const release = path.join(clock, 'finish');
    let sequence = 0, total = 0, idle = 0;
    function sample(external) {
      const span = 1_000_000_000_000;
      total += span;
      idle += span * (100 - external) / 100;
      writeFileSync(path.join(clock, `cpu-time-${String(++sequence).padStart(5, '0')}-${total}-${idle}`), '');
    }
    sample(30);
    const child = spawn(exe, ['--dsh-run-host', '256', exe, 'host-rates', release], {
      windowsHide: true, env: { ...process.env, DSH_RESOURCE_FIXTURE_CPU: clock },
    });
    let output = '', stderr = '';
    let exited = false;
    child.stdout.setEncoding('utf8').on('data', text => { output += text; });
    child.stderr.setEncoding('utf8').on('data', text => { stderr += text; });
    const exit = new Promise((resolve, reject) => {
      child.on('error', reject);
      child.on('exit', code => { exited = true; resolve(code); });
    });
    const observed = () => Array.from(output.matchAll(/^host CPU rate (\d+)\r?$/gm), match => Number(match[1]));
    async function drive(external, predicate, reason) {
      await eventually(() => {
        assert.equal(exited, false, stderr || output);
        if (predicate(observed())) return true;
        sample(external);
        return false;
      }, reason);
    }
    try {
      await drive(30, rates => rates.length > 0, 'the host did not read its initial CPU cap');
      assert.equal(observed()[0], 6000, 'the first host instructions ran before reserving for external CPU');
      await drive(60, rates => rates.includes(3000), 'host rate did not drop when external CPU reached 60%');
      await drive(100, rates => rates.includes(1), 'saturated system did not throttle the host job');
      const atFloor = observed().indexOf(1);
      await drive(0, rates => rates.slice(atFloor + 1).some(rate => rate > 1), 'host CPU rate did not recover');
      assert.ok(observed().slice(atFloor + 1)[0] <= 1000, output);
    } finally {
      writeFileSync(release, '');
      assert.equal(await exit, 0, stderr || output);
    }
  });

  function start(name, mode = 'hold', wait = -1, token) {
    const release = path.join(directory, name);
    const args = mode === 'outside' ? ['resident', release]
      : token ? ['claim', prefix, token, headroom, release]
      : ['admit', prefix, headroom, release, String(wait), mode];
    const child = spawn(exe, args, { windowsHide: true, env: fixtureEnv() });
    const task = { child, release, output: '', error: '', done: false };
    child.stdout.setEncoding('utf8').on('data', text => { task.output += text; });
    child.stderr.setEncoding('utf8').on('data', text => { task.error += text; });
    task.exit = new Promise((resolve, reject) => {
      child.on('error', reject);
      child.on('exit', code => { task.done = true; resolve(code); });
    });
    tasks.push(task);
    return task;
  }

  const run = (...args) => execFileSync(exe, args, { encoding: 'utf8', windowsHide: true, timeout: 4_000, env: fixtureEnv() }).trim();
  const observe = ticket => run('observe', prefix, String(ticket));
  const release = task => writeFileSync(task.release, '');
  const admitted = task => /^admitted\r?$/m.test(task.output);
  const awaitAdmission = task => eventually(() => {
    if (!admitted(task) && task.done) assert.fail(task.error || 'fixture exited without admission');
    return admitted(task);
  }, 'no admission after resources became available');
  const rates = () => run('cpu', prefix).split(/\r?\n/).filter(Boolean);
  const status = () => JSON.parse(run('status', prefix));
  const matchesRates = (count, rate) => {
    const current = rates();
    return current.length === count && current.every(value => value === `5:${rate}`);
  };
  const expectRates = (count, rate) => assert.deepEqual(rates(), Array(count).fill(`5:${rate}`));

  const total = 32 * 1024 ** 3 + 1;
  const required = 4 * 1024 ** 3 + Math.ceil(total / 20);
  assert.equal(run('memory', String(total), String(required), '1'), 'True');
  assert.equal(run('memory', String(total), String(required - 1), '1'), 'False');
  assert.equal(run('external-cpu', '10000', '5000', '3000'), '2000');
  assert.equal(run('external-cpu', '3', '1', '0'), '6667');
  assert.equal(run('external-cpu', '10000', '7500', '5000'), '0');
  assert.equal(run('cpu-target', '2500', '9400', '6500'), '6500');
  assert.equal(run('cpu-target', '2500', '9500', '6500'), '6000');
  assert.equal(run('cpu-target', '2500', '10000', '6500'), '5500');
  assert.equal(run('cpu-target', '2500', '8900', '5500'), '5700');
  assert.equal(run('cpu-pressure', '9499'), 'False');
  assert.equal(run('cpu-pressure', '9500'), 'True');

  writeFileSync(headroom, '');
  const descendant = start('descendant', 'descendant');
  await awaitAdmission(descendant);
  assert.equal(await descendant.exit, 0);
  expectRates(1, 9000);
  const holders = [start('holder-1'), start('holder-2'), start('holder-3')];
  for (const holder of holders) await awaitAdmission(holder);
  expectRates(4, 2250);

  const first = start('first', 'nested');
  observe(0);
  const cancelledMiddle = start('cancelled-middle');
  observe(1);
  const cancelledHead = start('cancelled-head');
  observe(2);
  const last = start('last');
  observe(3);
  cancelledMiddle.child.kill();
  await cancelledMiddle.exit;
  assert.equal(admitted(first), false);
  assert.equal(admitted(last), false);

  unlinkSync(headroom);
  release(holders[0]);
  assert.equal(await holders[0].exit, 0);
  await eventually(() => matchesRates(3, 3000),
    'CPU headroom was not redistributed on exit');
  assert.equal(admitted(first), false);
  writeFileSync(headroom, '');
  await awaitAdmission(first);
  expectRates(4, 2250);
  assert.equal(admitted(cancelledHead), false);
  assert.equal(admitted(last), false);

  cancelledHead.child.kill();
  await cancelledHead.exit;
  assert.equal(admitted(last), false);
  release(descendant);
  await awaitAdmission(last);
  expectRates(4, 2250);

  const expires = start('expires', 'hold', 500);
  assert.equal(await expires.exit, 75);
  assert.equal(admitted(expires), false);
  for (const task of [first, ...holders.slice(1)]) release(task);
  await eventually(() => matchesRates(1, 9000),
    'the final command did not recover the full CPU share');
  release(last);
  assert.equal(await last.exit, 0);
  await eventually(() => rates().length === 0, 'a completed task kept its slot');

  await t.test('48 simultaneous submissions preserve arrival order through cancellation and slot reuse', async () => {
    unlinkSync(headroom);
    const waiters = [];
    for (let index = 0; index < 48; index++) {
      const task = start(`burst-${index}`);
      waiters.push(task);
      observe(index);
    }
    assert.equal(status().waiting, 48);
    assert.equal(status().active, 0);

    const cancelled = new Set([0, 1, 8, 16, 24, 31, 47]);
    for (const index of cancelled) waiters[index].child.kill();
    await Promise.all([...cancelled].map(index => waiters[index].exit));
    assert.equal(status().waiting, waiters.length - cancelled.size);

    // A single available slot makes the next grant observable even under load.
    writeFileSync(headroom, '1');
    const pending = waiters.filter((_, index) => !cancelled.has(index));
    for (const [index, task] of pending.entries()) {
      await awaitAdmission(task);
      assert.equal(pending.slice(index + 1).some(admitted), false);
      assert.equal(status().cpuHardCapPercent, 90);
      release(task);
      assert.equal(await task.exit, 0);
    }
    await eventually(() => status().waiting === 0 && status().active === 0, 'the burst left waiting or active jobs');
  });

  await t.test('one host process queues 64 requests and hands off only the oldest live request', async () => {
    unlinkSync(headroom);
    const workers = [];
    const manager = new HostResourceQueue(exe, (file, _, options) => {
      const worker = spawn(file, ['host-queue', prefix, headroom], options);
      workers.push(worker);
      return worker;
    });
    const requests = [];
    try {
      for (let id = 0; id < 64; id++) {
        const controller = new AbortController();
        const request = { controller, lease: null, error: null };
        request.done = manager.acquire(controller.signal).then(lease => { request.lease = lease; }, error => { request.error = error; });
        requests.push(request);
      }
      await eventually(() => status().waiting === 64, 'the host did not register all 64 requests');
      assert.equal(workers.length, 1);
      assert.equal(status().active, 0);

      const survivors = [4, 20, 42, 63];
      for (const [id, request] of requests.entries()) {
        if (!survivors.includes(id)) request.controller.abort(new Error('cancelled in the host'));
      }
      await eventually(() => status().waiting === survivors.length, 'cancelled host requests kept tickets');
      writeFileSync(headroom, '1');
      const first = requests[survivors[0]];
      await first.done;
      assert.ok(first.lease, first.error?.message);
      assert.ok(requests[survivors[1]].lease === null);
      first.controller.abort(new Error('cancelled after permit'));
      assert.equal(first.lease.signal.aborted, true);

      for (const [index, id] of survivors.slice(1).entries()) {
        const request = requests[id];
        await request.done;
        assert.ok(request.lease, request.error?.message);
        const child = start(`claim-${id}`, 'hold', -1, request.lease.token);
        await awaitAdmission(child);
        assert.equal(survivors.slice(index + 2).some(later => requests[later].lease), false);
        assert.equal(status().cpuHardCapPercent, 90);
        release(child);
        assert.equal(await child.exit, 0);
      }
      await eventually(() => status().waiting === 0 && status().active === 0, 'the host left waiting or active jobs');
      assert.equal(workers.length, 1);
    } finally {
      manager.close();
      await Promise.all(requests.map(request => request.done));
      await Promise.all(workers.map(worker => new Promise(resolve => {
        if (worker.exitCode !== null || worker.signalCode !== null) resolve();
        else worker.once('close', resolve);
      })));
    }
  });

  await t.test('a retired host drains its existing FIFO ticket while a replacement accepts new work', async () => {
    unlinkSync(headroom);
    const children = [];
    const launch = (file, _, options) => {
      const child = spawn(file, ['host-queue', prefix, headroom], options);
      children.push(child);
      return child;
    };
    const old = new HostResourceQueue(exe, launch);
    const replacement = new HostResourceQueue(exe, launch);
    const firstRequest = old.acquire();
    // Attach observers before any assertions so a fixture failure cannot leave a rejection unhandled.
    firstRequest.catch(() => {});
    try {
      observe(0);
      old.retire();
      assert.throws(() => old.acquire(), /shut down/);
      const secondRequest = replacement.acquire();
      secondRequest.catch(() => {});
      observe(1);
      assert.equal(status().waiting, 2);
      assert.equal(children.length, 2);
      assert.equal(children[0].exitCode, null);

      writeFileSync(headroom, '1');
      const firstLease = await firstRequest;
      assert.equal(firstLease.bootstrap, path.join(directory, 'bash-env.sh'));
      const first = start('retired-first', 'hold', -1, firstLease.token);
      await awaitAdmission(first);
      await eventually(() => children[0].exitCode === 0, 'the retired broker did not drain and exit');
      assert.equal(first.done, false);
      assert.equal(status().waiting, 1);
      release(first);
      assert.equal(await first.exit, 0);

      const secondLease = await secondRequest;
      const second = start('replacement-second', 'hold', -1, secondLease.token);
      await awaitAdmission(second);
      release(second);
      assert.equal(await second.exit, 0);
    } finally {
      old.close();
      replacement.close();
      await Promise.all(children.map(child => new Promise(resolve => {
        if (child.exitCode !== null || child.signalCode !== null) resolve();
        else child.once('close', resolve);
      })));
    }
  });

  await t.test('a retired broker releases its waiting ticket if its host exits', async () => {
    const idlePrefix = `Local\\DSHToolBudget-process-exit-${randomUUID()}`;
    const missingHeadroom = path.join(directory, 'no-headroom');
    const childScript = `
      import { execFileSync, spawn } from 'node:child_process';
      import { setTimeout as delay } from 'node:timers/promises';
      const [module, fixture, prefix, headroom] = process.argv.slice(1);
      const { HostResourceQueue } = await import(module);
      let broker;
      const queue = new HostResourceQueue(fixture, (file, args, options) => {
        broker = spawn(file, ['host-queue', prefix, headroom], options);
        return broker;
      });
      queue.acquire().catch(() => {});
      const deadline = Date.now() + 3000;
      let registered = false;
      while (!registered && Date.now() < deadline) {
        registered = JSON.parse(execFileSync(fixture, ['status', prefix], { windowsHide: true })).waiting === 1;
        if (!registered) await delay(25);
      }
      if (!registered) throw new Error('broker never registered the ticket');
      process.stdout.write(String(broker.pid));
      queue.retire();
    `;
    const pid = Number(execFileSync(process.execPath, ['--input-type=module', '-e', childScript, '--',
      new URL('../host-queue.js', import.meta.url).href, exe, idlePrefix, missingHeadroom,
    ], { encoding: 'utf8', windowsHide: true, timeout: 8_000 }).trim());
    assert.ok(pid > 0);
    await eventually(() => {
      try { process.kill(pid, 0); return false; }
      catch (error) { if (error.code === 'ESRCH') return true; throw error; }
    }, 'the retired broker stayed alive after the host exited');
    assert.equal(JSON.parse(run('status', idlePrefix)).waiting, 0);
  });

  await t.test('stat permits reserve their smaller kernel limits and preserve FIFO behind a full request', async () => {
    prefix = `Local\\DSHToolBudget-test-${randomUUID()}`;
    const queue = new HostResourceQueue(exe, (file, _args, options) => spawn(file, ['host-queue', prefix, headroom], {
      ...options, env: fixtureEnv(),
    }));
    const stat = 256 * 1024 ** 2;
    const full = 2 * 1024 ** 3;
    const capacity = bytes => writeFileSync(headroom, `bytes:${bytes}`);
    const stop = new AbortController();
    const request = (signal, operation) => {
      const offer = queue.acquire(signal, operation);
      void offer.catch(() => {});
      return offer;
    };
    const claim = async (label, offer) => {
      const permit = await offer;
      const task = start(label, 'hold', -1, permit.token);
      await awaitAdmission(task);
      return task;
    };
    try {
      capacity(2 * stat);
      const blocker = request(stop.signal);
      const denied = assert.rejects(blocker, /test full request cancelled/);
      const light = request(undefined, 'stat');
      let lightOffered = false;
      void light.then(() => { lightOffered = true; }, () => {});
      await eventually(() => status().waiting === 2, 'both weighted requests must be registered');
      await delay(300);
      assert.equal(lightOffered, false);
      stop.abort(new Error('test full request cancelled'));
      await denied;

      const first = await claim('weighted-stat-first', light);
      const second = await claim('weighted-stat-second', request(undefined, 'stat'));
      assert.equal(status().statMemoryLimitPerTreeBytes, stat);
      assert.equal(status().memoryReservedBytes, 2 * stat);
      await eventually(() => status().waiting === 0, 'the stat permit claims did not leave the FIFO');
      capacity(full + stat);
      const heavy = request();
      const lastLight = request(undefined, 'stat');
      await eventually(() => status().waiting === 2, 'the later stat must wait behind the larger request');
      assert.equal(status().memoryReservedBytes, 2 * stat);

      release(first);
      await first.exit;
      const third = await claim('weighted-default', heavy);
      assert.equal(status().memoryReservedBytes, full + stat);
      await eventually(() => status().waiting === 1, 'the full permit claim did not leave the FIFO');
      release(second);
      await second.exit;
      const fourth = await claim('weighted-stat-last', lastLight);
      assert.equal(status().memoryReservedBytes, full + stat);
      for (const task of [third, fourth]) release(task);
      await Promise.all([third.exit, fourth.exit]);
      await eventually(() => status().active === 0 && status().waiting === 0, 'weighted tickets or slots remained');
    } finally {
      // Observe both resolutions if an assertion fails before their turns.
      stop.abort(new Error('test full request cancelled'));
      queue.close();
    }
  });

  await t.test('exact physical and commit thresholds pause offer and claim until both recover', async () => {
    sampleMemory = true;
    prefix = `Local\\DSHToolBudget-test-${randomUUID()}`;
    writeFileSync(headroom, '');
    const physical = path.join(directory, 'at-physical-threshold');
    const commit = path.join(directory, 'at-commit-threshold');
    const queue = new HostResourceQueue(exe, (file, _args, options) => spawn(file, ['host-queue', prefix, headroom], {
      ...options, env: fixtureEnv(),
    }));
    const checkEvaluator = () => spawnSync(exe, ['--dsh-evaluator-admission'], {
      windowsHide: true, timeout: 4_000, env: fixtureEnv(),
    }).status;
    const running = start('threshold-running');
    try {
      await awaitAdmission(running);
      writeFileSync(physical, '');
      const ticket = queue.acquire();
      void ticket.catch(() => {});
      let offered = false;
      void ticket.then(() => { offered = true; }, () => {});
      await eventually(() => status().waiting === 1, 'new request did not join the FIFO at 95% physical memory');
      assert.equal(status().physicalMemoryPressure, true);
      assert.equal(checkEvaluator(), 75);
      assert.equal(offered, false);
      assert.equal(running.done, false);

      writeFileSync(commit, '');
      unlinkSync(physical);
      assert.equal(status().physicalMemoryPressure, false);
      assert.equal(status().commitMemoryPressure, true);
      assert.equal(checkEvaluator(), 75);
      assert.equal(offered, false);
      unlinkSync(commit);
      const permit = await ticket;
      writeFileSync(physical, '');
      const claiming = start('threshold-claimant', 'hold', -1, permit.token);
      await delay(450);
      assert.equal(admitted(claiming), false);
      assert.equal(status().active, 1);
      unlinkSync(physical);
      await awaitAdmission(claiming);
      assert.equal(checkEvaluator(), 0);
      for (const task of [running, claiming]) release(task);
      assert.deepEqual(await Promise.all([running.exit, claiming.exit]), [0, 0]);
      await eventually(() => status().waiting === 0 && status().active === 0, 'threshold test left a job or ticket');
    } finally {
      queue.close();
      for (const file of [physical, commit]) {
        try { unlinkSync(file); } catch (error) { if (error.code !== 'ENOENT') throw error; }
      }
      sampleMemory = false;
    }
  });

  await t.test('system CPU pressure lowers live job caps, pauses admission and restores headroom gradually', async () => {
    sampleCpu = true;
    prefix = `Local\\DSHToolBudget-test-${randomUUID()}`;
    writeFileSync(headroom, '');
    let snapshot = 0, systemTotal = 0, systemIdle = 0;
    function recordCpu(externalPercent) {
      const span = 1_000_000_000_000;
      systemTotal += span;
      systemIdle += span * (100 - externalPercent) / 100;
      const sequence = String(++snapshot).padStart(4, '0');
      writeFileSync(path.join(directory, `cpu-time-${sequence}-${systemTotal}-${systemIdle}`), '');
    }
    async function sampleUntil(externalPercent, reached, message) {
      await eventually(() => {
        if (reached()) return true;
        recordCpu(externalPercent);
        return false;
      }, message);
    }

    recordCpu(0);
    const running = start('cpu-running');
    await sampleUntil(0, () => admitted(running), 'idle host did not admit the first job');
    expectRates(1, 9000);
    assert.equal(status().cpuOperatingLimitPercent, 90);

    await sampleUntil(30, () => status().cpuTargetPercent === 60, '30% external load did not preserve the 5 point operating reserve');
    expectRates(1, 6000);

    await sampleUntil(95, () => status().cpuPressure === true, '95% CPU did not close admission');
    assert.equal(status().systemCpuPercent, 95);
    const queued = start('cpu-waiting');
    await eventually(() => status().waiting === 1, 'saturated request did not enter the queue');
    assert.equal(admitted(queued), false);
    assert.equal(running.done, false);

    await sampleUntil(100, () => status().systemCpuPercent === 100, 'saturated CPU sample did not reach the status');
    expectRates(1, 1);

    await sampleUntil(0, () => admitted(queued), 'the queued job did not resume when CPU load subsided');
    assert.ok(status().cpuHardCapPercent <= 10, 'CPU headroom recovered in one unbounded jump');
    for (const task of [running, queued]) release(task);
    await Promise.all([running.exit, queued.exit]);
    await eventually(() => status().active === 0 && status().waiting === 0, 'CPU test left a resource slot or ticket');
  });

  await t.test('physical memory pressure trims only managed working sets before the 95% ceiling', async () => {
    sampleCpu = false;
    sampleMemory = true;
    prefix = `Local\\DSHToolBudget-test-${randomUUID()}`;
    const inside = start('memory-managed', 'resident');
    const outside = start('memory-unmanaged', 'outside');
    await eventually(() => [inside, outside].every(task => /^resident\r?$/m.test(task.output)), 'native fixtures did not load their resident pages');
    const footprint = task => run('process-memory', String(task.child.pid)).split(' ').map(Number);
    const [initialWorkingSet, initialCommit] = footprint(inside);
    const [outsideWorkingSet] = footprint(outside);

    writeFileSync(path.join(directory, 'commit-pressure'), '');
    await delay(850);
    assert.equal(status().commitMemoryPressure, true);
    assert.equal(status().memoryTrimmedProcesses, 0);

    writeFileSync(path.join(directory, 'physical-pressure'), '');
    await eventually(() => status().memoryTrimmedProcesses > 0, 'physical pressure did not invoke the working-set API');
    const [trimmedWorkingSet, retainedCommit] = footprint(inside);
    assert.equal(status().physicalMemoryPressure, false);
    assert.ok(trimmedWorkingSet < initialWorkingSet - 20 * 1024 ** 2, 'Windows did not return a material fraction of the managed working set');
    assert.ok(retainedCommit >= initialCommit - 8 * 1024 ** 2, 'the fixture lost its allocated data');
    assert.ok(footprint(outside)[0] >= outsideWorkingSet - 12 * 1024 ** 2, 'the unmanaged process was unexpectedly trimmed');
    const trims = status().memoryTrimmedProcesses;
    await delay(850);
    assert.equal(status().memoryTrimmedProcesses, trims);

    for (const task of [inside, outside]) release(task);
    assert.deepEqual(await Promise.all([inside.exit, outside.exit]), [0, 0]);
    assert.match(inside.output, /^intact\r?$/m);
    await eventually(() => status().active === 0, 'the managed memory probe retained its slot');
  });
});
