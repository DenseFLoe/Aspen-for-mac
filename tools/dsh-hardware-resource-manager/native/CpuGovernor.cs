using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

internal sealed class CpuGovernor : IDisposable
{
    internal const uint Scale = 10000;
    internal const int SampleMilliseconds = 200;
    internal const uint OperatingReserve = 500;
    private const uint RecoveryPerSample = 200;
    private static readonly long SampleInterval = Stopwatch.Frequency * SampleMilliseconds / 1000;

    private const int Rate = 0, External = 1, Stamp = 2, Total = 3, Idle = 4, FirstJob = 5;
    private readonly SharedCounters state;
    private readonly uint ceiling;

    internal struct CpuTimes
    {
        internal readonly long Total;
        internal readonly long Idle;

        internal CpuTimes(long total, long idle) { Total = total; Idle = idle; }
    }

    // The native fixture substitutes a clock to check resource pressure deterministically.
    internal static Func<CpuTimes?> ReadCpuTimes = ReadWindowsCpuTimes;

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool GetSystemTimes(out long idle, out long kernel, out long user);

    [DllImport("kernel32.dll")]
    private static extern ushort GetActiveProcessorGroupCount();

    private static CpuTimes? ReadWindowsCpuTimes()
    {
        // GetSystemTimes is limited to the current processor group on multi-group hosts.
        if (GetActiveProcessorGroupCount() != 1) return null;
        long idle, kernel, user;
        DiffGuard.Require(GetSystemTimes(out idle, out kernel, out user), "read Windows CPU accounting");
        return new CpuTimes(kernel + user, idle);
    }

    internal CpuGovernor(string prefix, int slots, uint ceiling)
    {
        state = new SharedCounters(prefix + "-cpu-budget-v1", FirstJob + slots);
        this.ceiling = ceiling;
    }

    internal uint? LastRate { get { return Decode(state.Read(Rate)); } }

    internal uint? LastExternalRate
    {
        get { return state.Read(Stamp) == 0 ? null : Decode(state.Read(External) & uint.MaxValue); }
    }

    internal uint? LastSystemRate
    {
        get { return state.Read(Stamp) == 0 ? null : Decode(state.Read(External) >> 32); }
    }

    private static uint? Decode(long encoded)
    {
        return encoded > 0 ? (uint?)(encoded - 1) : null;
    }

    // Each access holds the existing admission mutex. Multiple slot keepers all
    // read the same sample and at most one refreshes it in each interval.
    internal uint? Refresh(IntPtr[] jobs, Func<IntPtr, long> readJobTicks)
    {
        long now = Stopwatch.GetTimestamp();
        long previousStamp = state.Read(Stamp);
        uint? publishedRate = LastRate;
        uint? previousRate = publishedRate.HasValue
            ? (uint?)Math.Min(publishedRate.Value, OperatingLimit(ceiling)) : null;
        if (previousStamp != 0 && now - previousStamp < SampleInterval) return previousRate;

        CpuTimes? before = ReadCpuTimes();
        if (!before.HasValue) return OperatingLimit(ceiling);
        long[] jobTimes = new long[jobs.Length];
        long managedTicks = 0;
        for (int slot = 0; slot < jobs.Length; slot++)
        {
            if (jobs[slot] == IntPtr.Zero) continue;
            jobTimes[slot] = readJobTicks(jobs[slot]);
            // A retired or replaced slot can lose ticks, which conservatively
            // leaves more of the observed load attributed to the rest of Windows.
            managedTicks += Math.Max(0, jobTimes[slot] - state.Read(FirstJob + slot));
        }

        CpuTimes after = ReadCpuTimes().GetValueOrDefault(before.Value);
        long totalTicks = after.Total - state.Read(Total);
        long idleTicks = after.Idle - state.Read(Idle);
        // Discard a partial baseline if a process exits while publishing it.
        state.Write(Stamp, 0);
        if (previousStamp != 0 && totalTicks > 0 && idleTicks >= 0)
        {
            uint external = ExternalRate(totalTicks, idleTicks, managedTicks);
            uint system = ExternalRate(totalTicks, idleTicks, 0);
            uint target = ReadyRate(ceiling, external, system, previousRate);
            // Older keepers use only the low word for external CPU.
            state.Write(External, ((system + 1L) << 32) | (external + 1L));
            state.Write(Rate, target + 1L);
            previousRate = target;
        }

        state.Write(Total, before.Value.Total);
        state.Write(Idle, before.Value.Idle);
        for (int slot = 0; slot < jobTimes.Length; slot++) state.Write(FirstJob + slot, jobTimes[slot]);
        state.Write(Stamp, now);
        return previousRate;
    }

    internal static uint ExternalRate(long totalTicks, long idleTicks, long managedTicks)
    {
        long busy = totalTicks - Math.Min(idleTicks, totalTicks);
        long external = busy - Math.Min(managedTicks, busy);
        return (uint)Math.Ceiling(decimal.Divide(external * (decimal)Scale, totalTicks));
    }

    internal static uint OperatingLimit(uint ceiling)
    {
        return Remaining(ceiling, OperatingReserve);
    }

    internal static uint ReadyRate(uint ceiling, uint external, uint system, uint? prior)
    {
        uint operating = OperatingLimit(ceiling);
        uint remaining = Remaining(operating, external);
        if (!prior.HasValue) return remaining;
        // Whole-machine pressure also catches load that job accounting attributed late.
        if (system >= ceiling)
            return Math.Min(remaining, Remaining(prior.Value, system - operating));
        return Math.Min(remaining, prior.Value + RecoveryPerSample);
    }

    private static uint Remaining(uint limit, uint used) { return limit > used ? limit - used : 0; }

    public void Dispose() { state.Dispose(); }
}
