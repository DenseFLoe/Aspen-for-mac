using System;
using System.Runtime.InteropServices;
using System.Threading;

internal sealed class HostEnvelope : IDisposable
{
    internal const string ScopeEnvironment = "DSH_RESOURCE_HOST_SCOPE";
    private const int MemoryUsageInformation = 28;
    private const uint QueryJob = 4;
    private const uint QueryProcess = 0x1000;
    private readonly Guid id;
    internal readonly IntPtr Job;
    internal readonly ulong Limit;

    [StructLayout(LayoutKind.Sequential)]
    private struct MemoryUsage
    {
        public ulong Committed, PeakCommitted;
    }

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr OpenJobObject(uint access, bool inherit, string name);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind, out MemoryUsage usage, int bytes, IntPtr returned);

    private static string Name(Guid id) { return @"Local\DSHHostEnvelope-" + id.ToString("N"); }

    internal static IntPtr Create(Guid id) { return SharedObjects.CreateHostJob(Name(id)); }

    private HostEnvelope(Guid id, IntPtr process)
    {
        this.id = id;
        Job = OpenJobObject(QueryJob, false, Name(id));
        DiffGuard.Require(Job != IntPtr.Zero, "open the host budget for read-only accounting");
        try
        {
            bool member;
            DiffGuard.Require(ToolBudget.IsProcessInJob(process, Job, out member), "check the host budget membership");
            if (!member) throw new InvalidOperationException("The process does not belong to the specified host budget.");
            Limit = ToolBudget.ReadMemoryLimit(Job);
            ReadCommitted();
        }
        catch
        {
            DiffGuard.CloseHandle(Job);
            throw;
        }
    }

    internal static HostEnvelope OpenInherited(IntPtr process)
    {
        string value = Environment.GetEnvironmentVariable(ScopeEnvironment);
        if (string.IsNullOrEmpty(value)) return null;
        Guid id;
        if (!Guid.TryParseExact(value, "N", out id) || id == Guid.Empty)
            throw new InvalidOperationException("The DSH host budget identifier is invalid.");
        return new HostEnvelope(id, process);
    }

    internal SharedCounters BindPermit(string name)
    {
        SharedCounters metadata = new SharedCounters(name + "-host-id", 2);
        byte[] value = id.ToByteArray();
        metadata.Write(0, BitConverter.ToInt64(value, 0));
        metadata.Write(1, BitConverter.ToInt64(value, 8));
        return metadata;
    }

    internal static HostEnvelope OpenForPermit(string name, IntPtr process)
    {
        EventWaitHandle bound;
        if (!EventWaitHandle.TryOpenExisting(name + "-host-bound", out bound)) return OpenInherited(process);
        using (bound)
        using (SharedCounters metadata = new SharedCounters(name + "-host-id", 2))
        {
            byte[] value = new byte[16];
            Array.Copy(BitConverter.GetBytes(metadata.Read(0)), 0, value, 0, 8);
            Array.Copy(BitConverter.GetBytes(metadata.Read(1)), 0, value, 8, 8);
            Guid id = new Guid(value);
            if (id == Guid.Empty) throw new InvalidOperationException("The host budget for this permit is unavailable.");
            return new HostEnvelope(id, process);
        }
    }

    internal void CheckRequest(ulong bytes)
    {
        if (bytes > Limit)
            throw new InvalidOperationException("The tool's memory reservation exceeds this DSH host's total job limit.");
    }

    internal ulong ReadCommitted()
    {
        MemoryUsage usage;
        DiffGuard.Require(QueryInformationJobObject(Job, MemoryUsageInformation, out usage,
            Marshal.SizeOf(typeof(MemoryUsage)), IntPtr.Zero), "measure the host job's commit charge");
        return usage.Committed;
    }

    internal bool HasHeadroom(IntPtr[] jobs, ulong next)
    {
        ulong committed = ReadCommitted();
        if (committed >= Limit || next > Limit - committed) return false;
        ulong remaining = Limit - committed - next;
        foreach (IntPtr job in jobs)
        {
            if (job == IntPtr.Zero || !CountsAgainstHost(job)) continue;
            ulong reserved = ToolBudget.ReadMemoryLimit(job);
            if (reserved > remaining) return false;
            remaining -= reserved;
        }
        return true;
    }

    private bool CountsAgainstHost(IntPtr job)
    {
        foreach (int pid in MemoryPressure.ReadJobProcessIds(job, ToolBudget.ReadActiveProcesses(job)))
        {
            IntPtr process = ToolBudget.OpenProcess(QueryProcess, false, pid);
            if (process == IntPtr.Zero) continue;
            try
            {
                bool stillInJob, inHost;
                if (ToolBudget.IsProcessInJob(process, job, out stillInJob) && stillInJob
                    && ToolBudget.IsProcessInJob(process, Job, out inHost)) return inHost;
            }
            finally { DiffGuard.CloseHandle(process); }
        }
        // There is no verified representative. Retain its full reservation.
        return true;
    }

    public void Dispose() { DiffGuard.CloseHandle(Job); }
}
