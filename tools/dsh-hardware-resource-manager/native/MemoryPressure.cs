using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Threading;

internal sealed class MemoryPressure : IDisposable
{
    private const int ProcessIdList = 3;
    private const int MoreData = 234;
    private const int ListHeaderBytes = 2 * sizeof(uint);
    private const uint ProcessTrimAccess = 0x1100; // QUERY_LIMITED_INFORMATION | SET_QUOTA.
    private const ulong WorkingSetReservePercent = 7;
    private static readonly long TrimInterval = 8 * Stopwatch.Frequency;

    private readonly SharedCounters counters;
    private long nextTrim;

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind, IntPtr buffer, int bytes, IntPtr returned);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool K32EmptyWorkingSet(IntPtr process);

    internal MemoryPressure(string prefix)
    {
        counters = new SharedCounters(prefix + "-memory-trim-v1", 1);
    }

    internal long TrimmedProcesses { get { return counters.Read(0); } }

    internal void Observe(IntPtr job, uint active, Mutex gate)
    {
        long now = Stopwatch.GetTimestamp();
        if (now < nextTrim) return;
        ToolBudget.MemorySnapshot memory = ToolBudget.MeasureMemory();
        ulong reserve = memory.PhysicalTotal / 100 * WorkingSetReservePercent +
            (memory.PhysicalTotal % 100 * WorkingSetReservePercent + 99) / 100;
        if (memory.PhysicalAvailable >= reserve) return;
        nextTrim = now + TrimInterval;

        // Query and trim outside the shared admission mutex. An allocation or
        // exit in a target process must not delay unrelated FIFO registration.
        int trimmed = TrimWorkingSets(job, active);
        if (trimmed == 0) return;
        AdmissionQueue.Enter(gate);
        try { counters.Write(0, TrimmedProcesses + trimmed); }
        finally { gate.ReleaseMutex(); }
    }

    private static int TrimWorkingSets(IntPtr job, uint active)
    {
        int trimmed = 0;
        foreach (int pid in ReadJobProcessIds(job, active))
            if (pid != 0 && TrimMember(job, pid)) trimmed++;
        return trimmed;
    }

    internal static int[] ReadJobProcessIds(IntPtr job, uint active)
    {
        if (active == 0) return new int[0];
        int capacity = (int)Math.Min(active, 4096U);
        int bytes = ListHeaderBytes + capacity * IntPtr.Size;
        IntPtr buffer = Marshal.AllocHGlobal(bytes);
        try
        {
            Marshal.WriteInt32(buffer, sizeof(uint), 0);
            if (!QueryInformationJobObject(job, ProcessIdList, buffer, bytes, IntPtr.Zero) &&
                Marshal.GetLastWin32Error() != MoreData) return new int[0];
            int returned = Math.Min(capacity, Marshal.ReadInt32(buffer, sizeof(uint)));
            int[] ids = new int[returned];
            for (int index = 0; index < returned; index++)
                ids[index] = unchecked((int)Marshal.ReadIntPtr(buffer, ListHeaderBytes + index * IntPtr.Size).ToInt64());
            return ids;
        }
        finally
        {
            Marshal.FreeHGlobal(buffer);
        }
    }

    private static bool TrimMember(IntPtr job, int pid)
    {
        IntPtr process = ToolBudget.OpenProcess(ProcessTrimAccess, false, pid);
        if (process == IntPtr.Zero) return false;
        try
        {
            // A process can exit after the PID snapshot and Windows can reuse
            // the PID. Check membership on the opened process handle.
            bool member;
            return ToolBudget.IsProcessInJob(process, job, out member) && member && K32EmptyWorkingSet(process);
        }
        finally
        {
            DiffGuard.CloseHandle(process);
        }
    }

    public void Dispose() { counters.Dispose(); }
}
