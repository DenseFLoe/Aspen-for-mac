using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Security.Principal;
using System.Text;
using System.Threading;

internal static class ToolBudget
{
    private const ulong GiB = 1024UL * 1024 * 1024;
    private const ulong Limit = 2 * GiB;
    private const ulong CommitReserve = 6 * GiB;
    private const ulong PhysicalReserve = 3 * GiB;
    private const int Slots = 4;
    private const int WaitMilliseconds = 60 * 1000;
    private const uint ProcessAccess = 0x00101101;
    private const uint JobMemoryLimit = 0x200;
    private const uint JobQuery = 0x4;
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
    private struct Performance
    {
        public uint Size;
        public UIntPtr CommitTotal, CommitLimit, CommitPeak, PhysicalTotal, PhysicalAvailable;
        public UIntPtr SystemCache, KernelTotal, KernelPaged, KernelNonpaged, PageSize;
        public uint Handles, Processes, Threads;
    }

    [DllImport("ntdll.dll")]
    private static extern int NtQueryInformationProcess(IntPtr process, int kind,
        out ProcessBasicInformation result, int bytes, out int returned);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern IntPtr OpenProcess(uint access, bool inherit, int pid);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern IntPtr GetCurrentProcess();

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool IsProcessInJob(IntPtr process, IntPtr job, out bool result);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind,
        out BasicAccounting accounting, int bytes, IntPtr returned);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr OpenJobObject(uint access, bool inherit, string name);

    [DllImport("psapi.dll", SetLastError = true)]
    private static extern bool GetPerformanceInfo(ref Performance info, uint bytes);

    internal static int AdmitShell()
    {
        ProcessBasicInformation info;
        int size = Marshal.SizeOf(typeof(ProcessBasicInformation));
        int returned;
        int status = NtQueryInformationProcess(GetCurrentProcess(), 0, out info, size, out returned);
        if (status < 0 || info.Parent == IntPtr.Zero)
            throw new InvalidOperationException("Could not identify the current Niubash process.");

        int parentId = info.Parent.ToInt32();
        using (Process parent = Process.GetProcessById(parentId))
        {
            if (!string.Equals(parent.ProcessName, "niu", StringComparison.OrdinalIgnoreCase))
                throw new InvalidOperationException("The shell budget can only attach to its Niubash parent.");
            IntPtr handle = OpenProcess(ProcessAccess, false, parentId);
            DiffGuard.Require(handle != IntPtr.Zero, "open Niubash for resource limits");
            try
            {
                Admit(handle);
                return 0;
            }
            finally
            {
                DiffGuard.CloseHandle(handle);
            }
        }
    }

    internal static void Admit(IntPtr process)
    {
        string prefix = @"Local\DSHToolBudget-" + WindowsIdentity.GetCurrent().User.Value;
        Stopwatch waiting = Stopwatch.StartNew();
        using (Mutex gate = new Mutex(false, prefix + "-admission"))
        {
            while (waiting.ElapsedMilliseconds < WaitMilliseconds)
            {
                if (DiffGuard.WaitForSingleObject(process, 0) == 0)
                    throw new InvalidOperationException("The command exited before memory admission.");
                bool locked;
                try
                {
                    locked = gate.WaitOne(250);
                }
                catch (AbandonedMutexException)
                {
                    locked = true;
                }
                if (!locked) continue;
                try
                {
                    if (AssignAvailableSlot(prefix, process))
                        return;
                }
                finally
                {
                    gate.ReleaseMutex();
                }
                Thread.Sleep(250);
            }
        }
        throw new TimeoutException("Memory budget busy for 60 seconds. Requeue this tool call when capacity returns.");
    }

    internal static int KeepSlot(string jobName, string eventName)
    {
        IntPtr job = OpenJobObject(JobQuery, false, jobName);
        DiffGuard.Require(job != IntPtr.Zero, "keep the assigned memory slot open");
        try
        {
            using (EventWaitHandle ready = EventWaitHandle.OpenExisting(eventName))
                ready.Set();
            while (ReadActiveProcesses(job) > 0)
                Thread.Sleep(200);
            return 0;
        }
        finally
        {
            DiffGuard.CloseHandle(job);
        }
    }

    private static void StartSlotKeeper(string jobName)
    {
        string eventName = jobName + "-ready-" + Guid.NewGuid().ToString("N");
        using (EventWaitHandle ready = new EventWaitHandle(false, EventResetMode.AutoReset, eventName))
        using (Process current = Process.GetCurrentProcess())
        {
            string file = current.MainModule.FileName;
            StringBuilder command = new StringBuilder();
            DiffGuard.AppendArgument(command, file);
            command.Append(" --dsh-keep-slot ").Append(jobName).Append(' ').Append(eventName);
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

    private static uint ReadActiveProcesses(IntPtr job)
    {
        BasicAccounting accounting;
        DiffGuard.Require(QueryInformationJobObject(job, 1, out accounting,
            Marshal.SizeOf(typeof(BasicAccounting)), IntPtr.Zero), "read memory slot lifetime");
        return accounting.ActiveProcesses;
    }

    private static bool AssignAvailableSlot(string prefix, IntPtr process)
    {
        IntPtr[] handles = new IntPtr[Slots];
        try
        {
            int occupied = 0;
            int firstFree = -1;
            for (int slot = 0; slot < handles.Length; slot++)
            {
                IntPtr job = DiffGuard.CreateJobObject(IntPtr.Zero, prefix + "-slot-" + slot);
                DiffGuard.Require(job != IntPtr.Zero, "open the shared Windows memory slot");
                handles[slot] = job;
                bool alreadyBudgeted;
                DiffGuard.Require(IsProcessInJob(process, job, out alreadyBudgeted),
                    "check whether this command already holds a memory slot");
                if (alreadyBudgeted) return true;

                if (ReadActiveProcesses(job) > 0)
                    occupied++;
                else if (firstFree < 0)
                    firstFree = slot;
            }
            if (firstFree < 0 || !HasHeadroom(occupied)) return false;

            DiffGuard.JobLimits limits = new DiffGuard.JobLimits();
            limits.BasicLimitInformation.LimitFlags = JobMemoryLimit;
            limits.JobMemoryLimit = new UIntPtr(Limit);
            DiffGuard.Require(DiffGuard.SetInformationJobObject(handles[firstFree], 9,
                ref limits, Marshal.SizeOf(limits)), "set 2 GiB command-tree memory limit");
            DiffGuard.Require(DiffGuard.AssignProcessToJobObject(handles[firstFree], process),
                "join the memory-limited command tree without dropping the existing sandbox job");
            StartSlotKeeper(prefix + "-slot-" + firstFree);
            return true;
        }
        finally
        {
            foreach (IntPtr handle in handles)
                if (handle != IntPtr.Zero) DiffGuard.CloseHandle(handle);
        }
    }

    private static bool HasHeadroom(int occupied)
    {
        Performance info = new Performance();
        info.Size = (uint)Marshal.SizeOf(info);
        DiffGuard.Require(GetPerformanceInfo(ref info, info.Size), "measure system memory headroom");
        ulong page = info.PageSize.ToUInt64();
        ulong limit = info.CommitLimit.ToUInt64() * page;
        ulong committed = info.CommitTotal.ToUInt64() * page;
        ulong available = info.PhysicalAvailable.ToUInt64() * page;
        return available >= PhysicalReserve && limit >= committed
            && limit - committed >= CommitReserve + (ulong)(occupied + 1) * Limit;
    }
}
