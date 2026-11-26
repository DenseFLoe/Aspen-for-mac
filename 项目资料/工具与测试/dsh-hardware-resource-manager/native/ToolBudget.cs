using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.Principal;
using System.Text;
using System.Threading;

internal static class ToolBudget
{
    private const ulong GiB = 1024UL * 1024 * 1024;
    private const ulong Limit = 2 * GiB;
    private const ulong StatLimit = GiB / 4;
    private const uint UsageLimitPercent = 95;
    private const uint CpuRateLimit = UsageLimitPercent * 100;
    private const uint CpuHardCapEnabled = 0x5;
    private const int CpuRateInformation = 15;
    private const int Slots = 4;
    internal const int StandaloneWaitMilliseconds = 60 * 1000;
    private const int PollMilliseconds = 250;
    private const uint WaitTimeout = 258;
    private const int FileNotFound = 2;
    private const uint ProcessAccess = 0x00101101;
    private const uint JobQuery = 0x4;
    private const uint JobSetAttributes = 0x2;
    private const uint CreateNoWindow = 0x08000000;

    [StructLayout(LayoutKind.Sequential)]
    private struct ProcessBasicInformation
    {
        public IntPtr ExitStatus, Peb, Affinity, Priority, Process, Parent;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct BasicAccounting
    {
        public long TotalUser, TotalKernel, PeriodUser, PeriodKernel;
        public uint Faults, TotalProcesses, ActiveProcesses, TerminatedProcesses;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct CpuRate
    {
        public uint Flags, Rate;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct Performance
    {
        public uint Size;
        public UIntPtr CommitTotal, CommitLimit, CommitPeak, PhysicalTotal, PhysicalAvailable;
        public UIntPtr SystemCache, KernelTotal, KernelPaged, KernelNonpaged, PageSize;
        public uint Handles, Processes, Threads;
    }

    internal struct MemorySnapshot
    {
        internal readonly ulong PhysicalTotal, PhysicalAvailable, CommitLimit, Committed;

        internal MemorySnapshot(ulong physicalTotal, ulong physicalAvailable, ulong commitLimit, ulong committed)
        {
            PhysicalTotal = physicalTotal;
            PhysicalAvailable = physicalAvailable;
            CommitLimit = commitLimit;
            Committed = committed;
        }
    }

    // The native fixture substitutes pressure snapshots without loading the whole machine.
    internal static Func<MemorySnapshot> MeasureMemory = ReadMemory;

    [DllImport("ntdll.dll")]
    private static extern int NtQueryInformationProcess(IntPtr process, int kind,
        out ProcessBasicInformation result, int bytes, out int returned);

    [DllImport("kernel32.dll", SetLastError = true)]
    internal static extern IntPtr OpenProcess(uint access, bool inherit, int pid);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern bool QueryFullProcessImageName(IntPtr process, uint flags, StringBuilder image, ref int size);

    [DllImport("kernel32.dll", SetLastError = true)]
    internal static extern bool IsProcessInJob(IntPtr process, IntPtr job, out bool result);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind,
        out BasicAccounting accounting, int bytes, IntPtr returned);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind,
        out CpuRate rate, int bytes, IntPtr returned);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool SetInformationJobObject(IntPtr job, int kind, ref CpuRate limits, int bytes);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr OpenJobObject(uint access, bool inherit, string name);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind,
        out DiffGuard.JobLimits limits, int bytes, IntPtr returned);

    [DllImport("psapi.dll", SetLastError = true)]
    private static extern bool GetPerformanceInfo(ref Performance info, uint bytes);

    internal static int AdmitShell(string permit = null)
    {
        ProcessBasicInformation info;
        int size = Marshal.SizeOf(typeof(ProcessBasicInformation));
        int returned;
        int status = NtQueryInformationProcess(DiffGuard.GetCurrentProcess(), 0, out info, size, out returned);
        if (status < 0 || info.Parent == IntPtr.Zero)
            throw new InvalidOperationException("Could not identify the current Niubash process.");

        IntPtr handle = OpenProcess(ProcessAccess, false, info.Parent.ToInt32());
        DiffGuard.Require(handle != IntPtr.Zero, "open Niubash for resource limits");
        try
        {
            StringBuilder parentImage = new StringBuilder(32768);
            int length = parentImage.Capacity;
            DiffGuard.Require(QueryFullProcessImageName(handle, 0, parentImage, ref length), "identify Niubash for resource limits");
            if (!string.Equals(Path.GetFileName(parentImage.ToString()), "niu.exe", StringComparison.OrdinalIgnoreCase))
                throw new InvalidOperationException("The shell budget can only attach to its Niubash parent.");
            if (permit == null) Admit(handle, Timeout.Infinite);
            else ClaimPermit(handle, SessionPrefix(), permit, HasHeadroom);
            return 0;
        }
        finally
        {
            DiffGuard.CloseHandle(handle);
        }
    }

    internal static void Admit(IntPtr process, int maxWaitMilliseconds)
    {
        Admit(process, maxWaitMilliseconds, SessionPrefix(), HasHeadroom);
    }

    internal static string SessionPrefix()
    {
        using (WindowsIdentity identity = WindowsIdentity.GetCurrent())
            return @"Local\DSHToolBudget-" + identity.User.Value;
    }

    internal static int PrintStatus()
    {
        Console.WriteLine(Status(SessionPrefix()));
        return 0;
    }

    internal static string Status(string prefix)
    {
        int pending;
        using (AdmissionQueue queue = new AdmissionQueue(prefix)) pending = queue.PendingCount();

        int active = 0;
        uint cpuRate = 0;
        ulong reservedMemory = 0, envelopeLimit = 0, envelopeCommitted = 0;
        using (HostEnvelope envelope = HostEnvelope.OpenInherited(DiffGuard.GetCurrentProcess()))
        {
            if (envelope != null)
            {
                envelopeLimit = envelope.Limit;
                envelopeCommitted = envelope.ReadCommitted();
            }
        }
        uint? cpuTarget, externalCpu, systemCpu;
        long memoryTrims;
        using (Mutex gate = SharedObjects.CreateMutex(prefix + "-admission"))
        {
            AdmissionQueue.Enter(gate);
            try
            {
                using (CpuGovernor governor = new CpuGovernor(prefix, Slots, CpuRateLimit))
                {
                    cpuTarget = governor.LastRate;
                    externalCpu = governor.LastExternalRate;
                    systemCpu = governor.LastSystemRate;
                }
                using (MemoryPressure memory = new MemoryPressure(prefix)) memoryTrims = memory.TrimmedProcesses;
                for (int slot = 0; slot < Slots; slot++)
                {
                    IntPtr job = OpenSlot(SlotName(prefix, slot), JobQuery);
                    if (job == IntPtr.Zero) continue;
                    try
                    {
                        if (ReadActiveProcesses(job) == 0) continue;
                        active++;
                        reservedMemory += ReadMemoryLimit(job);
                        CpuRate rate = ReadCpuRate(job);
                        if (rate.Flags == CpuHardCapEnabled) cpuRate += rate.Rate;
                    }
                    finally
                    {
                        DiffGuard.CloseHandle(job);
                    }
                }
            }
            finally
            {
                gate.ReleaseMutex();
            }
        }
        MemorySnapshot memoryInfo = MeasureMemory();
        return string.Format(CultureInfo.InvariantCulture,
            "{{\"waiting\":{0},\"active\":{1},\"maxActive\":{2},\"limitPercent\":{3}," +
            "\"cpuHardCapPercent\":{4},\"memoryLimitPerTreeBytes\":{5}," +
            "\"physicalTotalBytes\":{6},\"physicalAvailableBytes\":{7},\"commitLimitBytes\":{8},\"committedBytes\":{9}," +
            "\"cpuTargetPercent\":{10},\"externalCpuPercent\":{11}," +
            "\"physicalMemoryPressure\":{12},\"commitMemoryPressure\":{13},\"memoryTrimmedProcesses\":{14}," +
            "\"systemCpuPercent\":{15},\"cpuOperatingLimitPercent\":{16}," +
            "\"memoryReservedBytes\":{17},\"statMemoryLimitPerTreeBytes\":{18}," +
            "\"hostMemoryLimitBytes\":{19},\"hostCommittedBytes\":{20},\"cpuPressure\":{21}}}",
            pending, active, Slots, UsageLimitPercent, cpuRate / 100m, Limit,
            memoryInfo.PhysicalTotal, memoryInfo.PhysicalAvailable, memoryInfo.CommitLimit, memoryInfo.Committed,
            PercentOrNull(cpuTarget), PercentOrNull(externalCpu),
            HasPhysicalPressure(memoryInfo) ? "true" : "false", HasCommitPressure(memoryInfo) ? "true" : "false", memoryTrims,
            PercentOrNull(systemCpu), PercentOrNull(CpuGovernor.OperatingLimit(CpuRateLimit)), reservedMemory, StatLimit,
            envelopeLimit == 0 ? "null" : envelopeLimit.ToString(CultureInfo.InvariantCulture),
            envelopeLimit == 0 ? "null" : envelopeCommitted.ToString(CultureInfo.InvariantCulture),
            HasCpuPressure(systemCpu) ? "true" : "false");
    }

    private static string PercentOrNull(uint? rate)
    {
        return rate.HasValue ? (rate.Value / 100m).ToString(CultureInfo.InvariantCulture) : "null";
    }

    private static CpuGovernor OpenCpuGovernor(string prefix, Mutex gate)
    {
        AdmissionQueue.Enter(gate);
        try { return new CpuGovernor(prefix, Slots, CpuRateLimit); }
        finally { gate.ReleaseMutex(); }
    }

    internal static void Admit(IntPtr process, int maxWaitMilliseconds, string prefix, Func<int, ulong, bool> hasHeadroom)
    {
        EnsureRunning(process);
        if (AlreadyBudgeted(prefix, process)) return;

        string gateName = prefix + "-admission";
        Stopwatch waiting = Stopwatch.StartNew();
        using (Mutex gate = SharedObjects.CreateMutex(gateName))
        using (AdmissionQueue queue = new AdmissionQueue(prefix))
        using (AdmissionQueue.ProcessExit cancelled = new AdmissionQueue.ProcessExit(process))
        using (HostEnvelope host = HostEnvelope.OpenInherited(process))
        using (AdmissionQueue.Ticket ticket = queue.Enqueue())
        using (CpuGovernor governor = OpenCpuGovernor(prefix, gate))
        {
            if (host != null) host.CheckRequest(Limit);
            while (true)
            {
                EnsureRunning(process);
                int remaining = WaitRemaining(waiting, maxWaitMilliseconds);
                if (!queue.WaitForTurn(ticket, cancelled, remaining, PollMilliseconds)) continue;

                // Keep the queue free while its head assigns a Windows job.
                AdmissionQueue.Enter(gate);
                try
                {
                    WaitRemaining(waiting, maxWaitMilliseconds);
                    if (AssignAvailableSlot(prefix, process, Limit, hasHeadroom, governor, host)) return;
                }
                finally
                {
                    gate.ReleaseMutex();
                }
                EnsureRunning(process, PollMilliseconds);
            }
        }
    }

    private static string PermitName(string prefix, string token)
    {
        Guid id;
        if (!Guid.TryParseExact(token, "N", out id)) throw new ArgumentException("Invalid resource permit.");
        return prefix + "-permit-" + id.ToString("N");
    }

    internal static bool OfferPermit(string prefix, bool stat, WaitHandle cancelled, Action registered, Action<string> offer,
        Func<int, ulong, bool> hasHeadroom)
    {
        ulong requested = stat ? StatLimit : Limit;
        using (HostEnvelope host = HostEnvelope.OpenInherited(DiffGuard.GetCurrentProcess()))
        using (Mutex gate = SharedObjects.CreateMutex(prefix + "-admission"))
        using (AdmissionQueue queue = new AdmissionQueue(prefix))
        using (AdmissionQueue.Ticket ticket = queue.Enqueue())
        using (CpuGovernor governor = OpenCpuGovernor(prefix, gate))
        {
            registered();
            if (host != null) host.CheckRequest(requested);
            while (!cancelled.WaitOne(0))
            {
                if (!queue.WaitForTurn(ticket, cancelled, Timeout.Infinite, PollMilliseconds)) continue;

                IntPtr[] jobs = new IntPtr[Slots];
                bool available;
                AdmissionQueue.Enter(gate);
                try
                {
                    int firstFree;
                    int occupied = OpenSlots(prefix, jobs, out firstFree);
                    uint? cpuRate = governor.Refresh(jobs, ReadJobCpuTicks);
                    if (cpuRate.HasValue) DistributeCpu(jobs, occupied, cpuRate.Value);
                    available = firstFree >= 0 && !HasCpuPressure(governor.LastSystemRate)
                        && cpuRate.GetValueOrDefault() > (uint)occupied
                        && ReservationFits(jobs, occupied, requested, hasHeadroom, host);
                }
                finally
                {
                    CloseSlots(jobs);
                    gate.ReleaseMutex();
                }
                if (available && !cancelled.WaitOne(0)) return HandOffPermit(prefix, stat, gate, cancelled, offer, host);
                cancelled.WaitOne(PollMilliseconds);
            }
            return false;
        }
    }

    private static bool HandOffPermit(string prefix, bool stat, Mutex gate, WaitHandle cancelled, Action<string> offer,
        HostEnvelope host)
    {
        string token = Guid.NewGuid().ToString("N");
        string name = PermitName(prefix, token);
        using (Mutex lifetime = SharedObjects.CreateMutex(name + "-lifetime"))
        using (EventWaitHandle claimed = SharedObjects.CreateEvent(name + "-claimed", EventResetMode.ManualReset))
        using (EventWaitHandle statPermit = stat ? SharedObjects.CreateEvent(name + "-stat", EventResetMode.ManualReset) : null)
        using (SharedCounters hostId = host == null ? null : host.BindPermit(name))
        using (EventWaitHandle hostBound = host == null ? null : SharedObjects.CreateEvent(name + "-host-bound", EventResetMode.ManualReset))
        {
            AdmissionQueue.Enter(lifetime);
            int result;
            bool consumed;
            try
            {
                offer(token);
                result = WaitHandle.WaitAny(new WaitHandle[] { claimed, cancelled }, 120 * 1000);
            }
            finally
            {
                AdmissionQueue.Enter(gate);
                try
                {
                    consumed = claimed.WaitOne(0);
                    lifetime.ReleaseMutex();
                }
                finally
                {
                    gate.ReleaseMutex();
                }
            }
            if (!consumed && result == WaitHandle.WaitTimeout)
                throw new TimeoutException("The host did not claim the resource permit within 120 seconds.");
            return consumed;
        }
    }

    internal static void ClaimPermit(IntPtr process, string prefix, string token, Func<int, ulong, bool> hasHeadroom)
    {
        string name = PermitName(prefix, token);
        using (Mutex gate = SharedObjects.CreateMutex(prefix + "-admission"))
        using (Mutex lifetime = Mutex.OpenExisting(name + "-lifetime"))
        using (EventWaitHandle claimed = EventWaitHandle.OpenExisting(name + "-claimed"))
        using (CpuGovernor governor = OpenCpuGovernor(prefix, gate))
        using (HostEnvelope host = HostEnvelope.OpenForPermit(name, process))
        {
            ulong requested = PermitMemoryLimit(name);
            if (host != null) host.CheckRequest(requested);
            while (true)
            {
                EnsureRunning(process);
                AdmissionQueue.Enter(gate);
                try
                {
                    if (PermitExpired(lifetime) || claimed.WaitOne(0))
                        throw new InvalidOperationException("The resource permit has ended.");
                    if (AssignAvailableSlot(prefix, process, requested, hasHeadroom, governor, host))
                    {
                        claimed.Set();
                        return;
                    }
                }
                finally
                {
                    gate.ReleaseMutex();
                }
                EnsureRunning(process, PollMilliseconds);
            }
        }
    }

    private static ulong PermitMemoryLimit(string name)
    {
        EventWaitHandle statPermit;
        if (!EventWaitHandle.TryOpenExisting(name + "-stat", out statPermit)) return Limit;
        using (statPermit) return StatLimit;
    }

    private static bool PermitExpired(Mutex lifetime)
    {
        try
        {
            if (!lifetime.WaitOne(0)) return false;
        }
        catch (AbandonedMutexException) { /* The parent host stopped. */ }
        lifetime.ReleaseMutex();
        return true;
    }

    private static int WaitRemaining(Stopwatch waiting, int maxWaitMilliseconds)
    {
        if (maxWaitMilliseconds == Timeout.Infinite) return Timeout.Infinite;
        long remaining = maxWaitMilliseconds - waiting.ElapsedMilliseconds;
        if (remaining <= 0) throw new TimeoutException("Timed out waiting for a resource slot. The command did not start.");
        return (int)remaining;
    }

    private static void EnsureRunning(IntPtr process, uint wait = 0)
    {
        uint result = DiffGuard.WaitForSingleObject(process, wait);
        if (result == 0)
            throw new InvalidOperationException("The command exited before memory admission.");
        DiffGuard.Require(result == WaitTimeout, "check whether the command is still pending");
    }

    internal static int KeepSlot(string jobName, string eventName, string prefix)
    {
        IntPtr job = OpenJobObject(JobQuery, false, jobName);
        DiffGuard.Require(job != IntPtr.Zero, "keep the assigned memory slot open");
        CpuGovernor governor = null;
        MemoryPressure memory = null;
        try
        {
            // The launcher holds this mutex until the assignment succeeds or fails.
            using (Mutex gate = Mutex.OpenExisting(prefix + "-admission"))
            {
                using (EventWaitHandle ready = EventWaitHandle.OpenExisting(eventName))
                    ready.Set();
                int pollsUntilMemory = 0;
                while (true)
                {
                    uint active;
                    AdmissionQueue.Enter(gate);
                    try
                    {
                        active = ReadActiveProcesses(job);
                        if (active == 0)
                        {
                            DiffGuard.CloseHandle(job);
                            job = IntPtr.Zero;
                        }
                        try
                        {
                            if (governor == null) governor = new CpuGovernor(prefix, Slots, CpuRateLimit);
                            RedistributeCpu(prefix, governor);
                        }
                        catch (Win32Exception) { /* Keep the live job open and retry on the next pass. */ }
                        if (job == IntPtr.Zero) return 0;
                        if (memory == null && pollsUntilMemory == 0)
                        {
                            try { memory = new MemoryPressure(prefix); }
                            catch (Win32Exception) { /* Resource sampling cannot stop an active job. */ }
                        }
                    }
                    finally
                    {
                        gate.ReleaseMutex();
                    }
                    if (pollsUntilMemory-- == 0)
                    {
                        try { if (memory != null) memory.Observe(job, active, gate); }
                        catch (Win32Exception) { /* Process access and memory sampling are best effort. */ }
                        pollsUntilMemory = 2;
                    }
                    Thread.Sleep(CpuGovernor.SampleMilliseconds);
                }
            }
        }
        finally
        {
            if (memory != null) memory.Dispose();
            if (governor != null) governor.Dispose();
            if (job != IntPtr.Zero) DiffGuard.CloseHandle(job);
        }
    }

    private static void StartSlotKeeper(string jobName, string prefix)
    {
        string eventName = jobName + "-ready-" + Guid.NewGuid().ToString("N");
        using (EventWaitHandle ready = SharedObjects.CreateEvent(eventName, EventResetMode.AutoReset))
        using (Process current = Process.GetCurrentProcess())
        {
            string file = current.MainModule.FileName;
            StringBuilder command = new StringBuilder();
            DiffGuard.AppendArgument(command, file);
            command.Append(" --dsh-keep-slot ").Append(jobName).Append(' ').Append(eventName).Append(' ').Append(prefix);
            DiffGuard.StartupInfo startup = new DiffGuard.StartupInfo();
            startup.Size = Marshal.SizeOf(startup);
            DiffGuard.ProcessInfo keeper;
            DiffGuard.Require(DiffGuard.CreateProcess(file, command, IntPtr.Zero, IntPtr.Zero,
                false, CreateNoWindow, IntPtr.Zero, null, ref startup, out keeper),
                "start a memory slot keeper without inheriting command output handles");
            try
            {
                if (ready.WaitOne(3000)) return;
                DiffGuard.TerminateProcess(keeper.Process, 2);
                throw new InvalidOperationException("The memory slot keeper did not confirm its Windows job handle.");
            }
            finally
            {
                DiffGuard.CloseHandle(keeper.Thread);
                DiffGuard.CloseHandle(keeper.Process);
            }
        }
    }

    private static BasicAccounting ReadAccounting(IntPtr job)
    {
        BasicAccounting accounting;
        DiffGuard.Require(QueryInformationJobObject(job, 1, out accounting,
            Marshal.SizeOf(typeof(BasicAccounting)), IntPtr.Zero), "read memory slot lifetime");
        return accounting;
    }

    internal static uint ReadActiveProcesses(IntPtr job) { return ReadAccounting(job).ActiveProcesses; }

    private static long ReadJobCpuTicks(IntPtr job)
    {
        BasicAccounting accounting = ReadAccounting(job);
        return accounting.TotalKernel + accounting.TotalUser;
    }

    private static IntPtr OpenSlot(string jobName, uint access)
    {
        IntPtr job = OpenJobObject(access, false, jobName);
        if (job == IntPtr.Zero)
            DiffGuard.Require(Marshal.GetLastWin32Error() == FileNotFound, "open the shared Windows memory slot");
        return job;
    }

    private static string SlotName(string prefix, int slot)
    {
        return prefix + "-slot-" + slot;
    }

    private static bool AlreadyBudgeted(string prefix, IntPtr process)
    {
        for (int slot = 0; slot < Slots; slot++)
        {
            IntPtr job = OpenSlot(SlotName(prefix, slot), JobQuery);
            if (job == IntPtr.Zero) continue;
            try
            {
                bool alreadyBudgeted;
                DiffGuard.Require(IsProcessInJob(process, job, out alreadyBudgeted),
                    "check whether this command already holds a memory slot");
                if (alreadyBudgeted) return true;
            }
            finally
            {
                DiffGuard.CloseHandle(job);
            }
        }
        return false;
    }

    private static int OpenSlots(string prefix, IntPtr[] jobs, out int firstFree)
    {
        int occupied = 0;
        firstFree = -1;
        for (int slot = 0; slot < jobs.Length; slot++)
        {
            jobs[slot] = OpenSlot(SlotName(prefix, slot), JobQuery | JobSetAttributes);
            if (jobs[slot] != IntPtr.Zero)
                occupied++;
            else if (firstFree < 0)
                firstFree = slot;
        }
        return occupied;
    }

    private static void CloseSlots(IntPtr[] jobs)
    {
        foreach (IntPtr job in jobs)
            if (job != IntPtr.Zero) DiffGuard.CloseHandle(job);
    }

    private static CpuRate ReadCpuRate(IntPtr job)
    {
        CpuRate rate;
        DiffGuard.Require(QueryInformationJobObject(job, CpuRateInformation, out rate,
            Marshal.SizeOf(typeof(CpuRate)), IntPtr.Zero), "read the shared CPU hard cap");
        return rate;
    }

    private static void DistributeCpu(IntPtr[] jobs, int occupied, uint budget)
    {
        if (occupied == 0) return;
        // Windows requires a positive rate. A saturated host receives no new jobs.
        uint share = Math.Max(1U, Math.Min(budget, CpuRateLimit) / (uint)occupied);
        CpuRate rate = HardCpuRate(share);
        int size = Marshal.SizeOf(rate);
        CpuRate[] existing = new CpuRate[jobs.Length];
        for (int slot = 0; slot < jobs.Length; slot++)
        {
            IntPtr job = jobs[slot];
            if (job == IntPtr.Zero) continue;
            existing[slot] = ReadCpuRate(job);
            // Lower high shares first so transition order cannot temporarily overcommit CPU.
            if (existing[slot].Flags == rate.Flags && existing[slot].Rate > rate.Rate)
            {
                DiffGuard.Require(SetInformationJobObject(job, CpuRateInformation, ref rate, size),
                    "lower the shared CPU hard cap");
                existing[slot] = rate;
            }
        }
        for (int slot = 0; slot < jobs.Length; slot++)
        {
            if (jobs[slot] == IntPtr.Zero || (existing[slot].Flags == rate.Flags && existing[slot].Rate == rate.Rate)) continue;
            DiffGuard.Require(SetInformationJobObject(jobs[slot], CpuRateInformation, ref rate, size),
                "set the shared CPU hard cap");
        }
    }

    private static CpuRate HardCpuRate(uint rate)
    {
        return new CpuRate { Flags = CpuHardCapEnabled, Rate = rate };
    }

    private static void SetHostCpuLimit(IntPtr job, uint budget)
    {
        CpuRate rate = HardCpuRate(budget);
        DiffGuard.Require(SetInformationJobObject(job, CpuRateInformation, ref rate, Marshal.SizeOf(rate)),
            "set the aggregate host CPU hard cap");
    }

    internal static void WaitForHost(IntPtr job, IntPtr process, Action resume)
    {
        uint applied = CpuGovernor.OperatingLimit(CpuRateLimit);
        SetHostCpuLimit(job, applied);
        // This launcher stays outside the host job so it can restore CPU shares
        // even while the host and all of its children are heavily throttled.
        using (CpuGovernor governor = new CpuGovernor(@"Local\DSHHost-" + Guid.NewGuid().ToString("N"), 1, CpuRateLimit))
        {
            IntPtr[] jobs = new IntPtr[] { job };
            try
            {
                // Measure background load while the new host is still suspended.
                governor.Refresh(jobs, ReadJobCpuTicks);
                Stopwatch startup = Stopwatch.StartNew();
                int remaining;
                while ((remaining = CpuGovernor.SampleMilliseconds - (int)startup.ElapsedMilliseconds) >= 0)
                {
                    uint outcome = DiffGuard.WaitForSingleObject(process, (uint)(remaining + 1));
                    if (outcome == 0) return;
                    DiffGuard.Require(outcome == WaitTimeout, "wait for the suspended host CPU sample");
                }
                applied = RefreshHostLimit(job, jobs, governor, applied);
            }
            catch (Win32Exception) { /* Keep the already-installed hard cap. */ }
            resume();
            while (true)
            {
                uint outcome = DiffGuard.WaitForSingleObject(process, CpuGovernor.SampleMilliseconds);
                if (outcome == 0) return;
                DiffGuard.Require(outcome == WaitTimeout, "wait for the managed host process");
                try { applied = RefreshHostLimit(job, jobs, governor, applied); }
                catch (Win32Exception) { /* Retain the last successful kernel limit and retry. */ }
            }
        }
    }

    private static uint RefreshHostLimit(IntPtr job, IntPtr[] jobs, CpuGovernor governor, uint applied)
    {
        uint budget = Math.Max(1U, governor.Refresh(jobs, ReadJobCpuTicks).GetValueOrDefault(applied));
        if (budget != applied) SetHostCpuLimit(job, budget);
        return budget;
    }

    private static void RedistributeCpu(string prefix, CpuGovernor governor)
    {
        IntPtr[] jobs = new IntPtr[Slots];
        try
        {
            int unused;
            int occupied = OpenSlots(prefix, jobs, out unused);
            uint? budget = governor.Refresh(jobs, ReadJobCpuTicks);
            for (int slot = 0; slot < jobs.Length; slot++)
            {
                if (jobs[slot] == IntPtr.Zero || ReadActiveProcesses(jobs[slot]) != 0) continue;
                DiffGuard.CloseHandle(jobs[slot]);
                jobs[slot] = IntPtr.Zero;
                occupied--;
            }
            if (budget.HasValue) DistributeCpu(jobs, occupied, budget.Value);
        }
        finally
        {
            CloseSlots(jobs);
        }
    }

    internal static ulong ReadMemoryLimit(IntPtr job)
    {
        DiffGuard.JobLimits limits;
        DiffGuard.Require(QueryInformationJobObject(job, 9, out limits,
            Marshal.SizeOf(typeof(DiffGuard.JobLimits)), IntPtr.Zero), "read the command-tree memory limit");
        ulong bytes = limits.JobMemoryLimit.ToUInt64();
        return (limits.BasicLimitInformation.LimitFlags & DiffGuard.JobMemoryLimit) != 0 && bytes > 0 ? bytes : Limit;
    }

    private static ulong ReservedMemory(IntPtr[] jobs, ulong next)
    {
        foreach (IntPtr job in jobs)
            if (job != IntPtr.Zero) next = checked(next + ReadMemoryLimit(job));
        return next;
    }

    private static bool ReservationFits(IntPtr[] jobs, int occupied, ulong requested,
        Func<int, ulong, bool> hasHeadroom, HostEnvelope host)
    {
        return !HasMemoryPressure(MeasureMemory()) && hasHeadroom(occupied, ReservedMemory(jobs, requested))
            && (host == null || host.HasHeadroom(jobs, requested));
    }

    private static bool AssignAvailableSlot(string prefix, IntPtr process, ulong memoryLimit,
        Func<int, ulong, bool> hasHeadroom, CpuGovernor governor, HostEnvelope host)
    {
        IntPtr[] jobs = new IntPtr[Slots];
        try
        {
            int firstFree;
            int occupied = OpenSlots(prefix, jobs, out firstFree);
            uint? budget = governor.Refresh(jobs, ReadJobCpuTicks);
            if (budget.HasValue) DistributeCpu(jobs, occupied, budget.Value);
            if (firstFree < 0 || HasCpuPressure(governor.LastSystemRate) || budget.GetValueOrDefault() <= (uint)occupied) return false;
            if (!ReservationFits(jobs, occupied, memoryLimit, hasHeadroom, host)) return false;

            string jobName = SlotName(prefix, firstFree);
            IntPtr job = SharedObjects.CreateSlot(jobName);
            try
            {
                DiffGuard.JobLimits limits = new DiffGuard.JobLimits();
                limits.BasicLimitInformation.LimitFlags = DiffGuard.JobMemoryLimit | DiffGuard.KillOnJobClose;
                limits.JobMemoryLimit = new UIntPtr(memoryLimit);
                DiffGuard.Require(DiffGuard.SetInformationJobObject(job, 9,
                    ref limits, Marshal.SizeOf(limits)), "set the command-tree memory limit");
                StartSlotKeeper(jobName, prefix);
                budget = governor.Refresh(jobs, ReadJobCpuTicks);
                if (HasCpuPressure(governor.LastSystemRate) || budget.GetValueOrDefault() <= (uint)occupied
                    || !ReservationFits(jobs, occupied, memoryLimit, hasHeadroom, host))
                {
                    if (budget.HasValue) DistributeCpu(jobs, occupied, budget.Value);
                    return false;
                }
                // Apply all lower shares before admitting a process into the new job.
                jobs[firstFree] = job;
                DistributeCpu(jobs, occupied + 1, budget.Value);
                EnsureRunning(process);
                DiffGuard.Require(DiffGuard.AssignProcessToJobObject(job, process),
                    "join the memory-limited command tree without dropping the existing sandbox job");
                return true;
            }
            finally
            {
                jobs[firstFree] = IntPtr.Zero;
                DiffGuard.CloseHandle(job);
            }
        }
        finally
        {
            CloseSlots(jobs);
        }
    }

    private static MemorySnapshot ReadMemory()
    {
        Performance info = new Performance();
        info.Size = (uint)Marshal.SizeOf(info);
        DiffGuard.Require(GetPerformanceInfo(ref info, info.Size), "measure system memory headroom");
        ulong page = info.PageSize.ToUInt64();
        return new MemorySnapshot(info.PhysicalTotal.ToUInt64() * page, info.PhysicalAvailable.ToUInt64() * page,
            info.CommitLimit.ToUInt64() * page, info.CommitTotal.ToUInt64() * page);
    }

    internal static bool HasHeadroom(int occupied, ulong planned)
    {
        return HasHostHeadroom(planned);
    }

    internal static bool HasHostHeadroom(ulong bytes)
    {
        MemorySnapshot info = MeasureMemory();
        return !HasMemoryPressure(info) && FitsUsageLimit(info.PhysicalTotal, info.PhysicalAvailable, bytes)
            && info.CommitLimit >= info.Committed && FitsUsageLimit(info.CommitLimit, info.CommitLimit - info.Committed, bytes);
    }

    internal static bool HasPhysicalPressure(MemorySnapshot info)
    {
        return info.PhysicalAvailable <= info.PhysicalTotal / 20;
    }

    private static bool HasCommitPressure(MemorySnapshot info)
    {
        return info.Committed >= info.CommitLimit - info.CommitLimit / 20;
    }

    internal static bool HasCpuPressure(uint? sampledRate)
    {
        return sampledRate.GetValueOrDefault() >= CpuRateLimit;
    }

    private static bool HasMemoryPressure(MemorySnapshot info)
    {
        return HasPhysicalPressure(info) || HasCommitPressure(info);
    }

    internal static bool EvaluatorAdmissionOpen()
    {
        if (HasMemoryPressure(MeasureMemory())) return false;
        CpuGovernor.CpuTimes? before = CpuGovernor.ReadCpuTimes();
        if (before.HasValue)
        {
            Thread.Sleep(CpuGovernor.SampleMilliseconds);
            CpuGovernor.CpuTimes? after = CpuGovernor.ReadCpuTimes();
            if (!after.HasValue) return false;
            long total = after.Value.Total - before.Value.Total;
            long idle = after.Value.Idle - before.Value.Idle;
            if (total <= 0 || idle < 0 || HasCpuPressure(CpuGovernor.ExternalRate(total, idle, 0)))
                return false;
        }
        return !HasMemoryPressure(MeasureMemory());
    }

    private static ulong RequiredIdle(ulong total)
    {
        ulong ceiling = total / 100 * UsageLimitPercent + total % 100 * UsageLimitPercent / 100;
        return total - ceiling;
    }

    internal static bool FitsUsageLimit(ulong total, ulong available, int occupied)
    {
        return FitsUsageLimit(total, available, (ulong)(occupied + 1) * Limit);
    }

    private static bool FitsUsageLimit(ulong total, ulong available, ulong planned)
    {
        ulong reserve = RequiredIdle(total);
        return available >= reserve && available - reserve >= planned;
    }
}
