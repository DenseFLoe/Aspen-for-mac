using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.AccessControl;
using System.Text;
using System.Threading;

internal static class Fixture
{
    [StructLayout(LayoutKind.Sequential)]
    private struct CpuRate { public uint Flags, Rate; }

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr OpenJobObject(uint access, bool inherit, string name);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind,
        out CpuRate rate, int bytes, IntPtr returned);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool QueryInformationJobObject(IntPtr job, int kind,
        out DiffGuard.JobLimits limits, int bytes, IntPtr returned);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern IntPtr VirtualAlloc(IntPtr address, UIntPtr size, uint allocation, uint protection);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool VirtualFree(IntPtr address, UIntPtr size, uint allocation);

    private static int Main(string[] args)
    {
        try
        {
            CpuGovernor.ReadCpuTimes = FixtureCpuTimes;
            string memoryFixture = Environment.GetEnvironmentVariable("DSH_RESOURCE_FIXTURE_MEMORY");
            if (memoryFixture != null) ToolBudget.MeasureMemory = () => FixtureMemory(memoryFixture);
            switch (args[0])
            {
                case "--dsh-run-host":
                    return DiffGuard.Main(args);
                case "--dsh-evaluator-admission":
                    return DiffGuard.Main(args);
                case "cpu-pressure":
                    Console.WriteLine(ToolBudget.HasCpuPressure(uint.Parse(args[1])));
                    return 0;
                case "--dsh-keep-slot":
                    return ToolBudget.KeepSlot(args[1], args[2], args[3]);
                case "observe":
                    return WaitForTicket(args[1], args[2]);
                case "cpu":
                    PrintRates(args[1]);
                    return 0;
                case "status":
                    Console.WriteLine(ToolBudget.Status(args[1]));
                    return 0;
                case "host-queue":
                    return new HostQueue(args[1], Console.Out, (occupied, planned) => HasTestCapacity(args[2], occupied, planned)).Run(Console.In);
                case "claim":
                    ToolBudget.ClaimPermit(DiffGuard.GetCurrentProcess(), args[1], args[2],
                        (occupied, planned) => HasTestCapacity(args[3], occupied, planned));
                    Console.WriteLine("admitted");
                    HoldUntil(args[4]);
                    return 0;
                case "memory":
                    Console.WriteLine(ToolBudget.FitsUsageLimit(ulong.Parse(args[1]), ulong.Parse(args[2]), int.Parse(args[3])));
                    return 0;
                case "external-cpu":
                    Console.WriteLine(CpuGovernor.ExternalRate(long.Parse(args[1]), long.Parse(args[2]), long.Parse(args[3])));
                    return 0;
                case "cpu-target":
                    Console.WriteLine(CpuGovernor.ReadyRate(9500, uint.Parse(args[1]), uint.Parse(args[2]), uint.Parse(args[3])));
                    return 0;
                case "hold":
                    HoldUntil(args[1]);
                    return 0;
                case "resident":
                    HoldResidentMemory(args[1]);
                    return 0;
                case "host-memory":
                    return ProbeHostLimits(args[1], args[2] == "bounded");
                case "host-member":
                    return HoldHostCommit(args[1]);
                case "host-admission":
                    return ProbeHostAdmission(args[1], args[2], args[3]);
                case "host-rates":
                    return PrintHostRates(args[1]);
                case "process-memory":
                    using (Process target = Process.GetProcessById(int.Parse(args[1])))
                        Console.WriteLine(target.WorkingSet64 + " " + target.PrivateMemorySize64);
                    return 0;
                case "admit":
                    ToolBudget.Admit(DiffGuard.GetCurrentProcess(), int.Parse(args[4]), args[1],
                        (occupied, planned) => HasTestCapacity(args[2], occupied, planned));
                    if (args[5] == "nested")
                        ToolBudget.Admit(DiffGuard.GetCurrentProcess(), 0, args[1], (_, planned) => false);
                    if (args[5] == "descendant")
                        StartDescendant(args[3]);
                    Console.WriteLine("admitted");
                    if (args[5] == "resident") HoldResidentMemory(args[3]);
                    else if (args[5] != "descendant") HoldUntil(args[3]);
                    return 0;
                default:
                    throw new ArgumentException("Unknown test operation");
            }
        }
        catch (TimeoutException error)
        {
            Console.Error.WriteLine(error.Message);
            return 75;
        }
        catch (Exception error)
        {
            Console.Error.WriteLine(error);
            return 2;
        }
    }

    private static Process StartFixture(string[] args, bool clearHostScope)
    {
        StringBuilder command = new StringBuilder();
        foreach (string arg in args)
        {
            if (command.Length != 0) command.Append(' ');
            DiffGuard.AppendArgument(command, arg);
        }
        ProcessStartInfo start = new ProcessStartInfo(typeof(Fixture).Assembly.Location, command.ToString());
        start.UseShellExecute = false;
        start.CreateNoWindow = true;
        start.RedirectStandardInput = true;
        start.RedirectStandardOutput = true;
        if (clearHostScope) start.EnvironmentVariables.Remove(HostEnvelope.ScopeEnvironment);
        return Process.Start(start);
    }

    private static IntPtr HostPressure()
    {
        IntPtr allocation = VirtualAlloc(IntPtr.Zero, new UIntPtr(224 * 1024 * 1024), 0x3000, 4);
        DiffGuard.Require(allocation != IntPtr.Zero, "allocate the host pressure fixture");
        return allocation;
    }

    private static int ProbeHostAdmission(string prefix, string capacity, string release)
    {
        using (HostEnvelope host = HostEnvelope.OpenInherited(DiffGuard.GetCurrentProcess()))
        {
            if (host == null || host.Limit != 448UL * 1024 * 1024) return 10;
            string scope = Environment.GetEnvironmentVariable(HostEnvelope.ScopeEnvironment);
            IntPtr writable = OpenJobObject(2, false, @"Local\DSHHostEnvelope-" + scope);
            if (writable != IntPtr.Zero)
            {
                DiffGuard.CloseHandle(writable);
                return 11;
            }
            if (Marshal.GetLastWin32Error() != 5) return 12;
            ulong before = host.ReadCommitted();
            using (Process broker = StartFixture(new string[] { "host-queue", prefix, capacity }, false))
            {
                broker.StandardInput.AutoFlush = true;
                broker.StandardInput.WriteLine("request 1");
                string error = broker.StandardOutput.ReadLine();
                if (error == null || !error.StartsWith("error 1 ", StringComparison.Ordinal)) return 13;
                string reason = Encoding.UTF8.GetString(Convert.FromBase64String(error.Substring(8)));
                if (!reason.Contains("exceeds this DSH host's total job limit")) return 14;

                IntPtr pressure = HostPressure();
                try
                {
                    if (host.ReadCommitted() < before + 224UL * 1024 * 1024) return 15;
                    broker.StandardInput.WriteLine("request-stat 2");
                    var offer = broker.StandardOutput.ReadLineAsync();
                    if (offer.Wait(450)) return 16;
                    DiffGuard.Require(VirtualFree(pressure, UIntPtr.Zero, 0x8000), "release host pressure before permit");
                    pressure = IntPtr.Zero;
                    if (!offer.Wait(6000) || offer.Result == null || !offer.Result.StartsWith("permit 2 ", StringComparison.Ordinal))
                        return 17;

                    pressure = HostPressure();
                    using (Process claim = StartFixture(new string[] { "claim", prefix, offer.Result.Substring(9), capacity, release }, true))
                    {
                        var admitted = claim.StandardOutput.ReadLineAsync();
                        if (admitted.Wait(450)) return 18;
                        DiffGuard.Require(VirtualFree(pressure, UIntPtr.Zero, 0x8000), "release host pressure before claim");
                        pressure = IntPtr.Zero;
                        if (!admitted.Wait(6000) || admitted.Result != "admitted") return 19;
                        if (broker.StandardOutput.ReadLine() != "claimed 2") return 20;
                        File.WriteAllText(release, "");
                        if (!claim.WaitForExit(6000) || claim.ExitCode != 0) return 21;
                    }
                }
                finally
                {
                    if (pressure != IntPtr.Zero) VirtualFree(pressure, UIntPtr.Zero, 0x8000);
                    File.WriteAllText(release, "");
                    broker.StandardInput.Close();
                }
                if (!broker.WaitForExit(6000) || broker.ExitCode != 0) return 22;
            }
        }
        Console.WriteLine("host memory verified at offer and at claim");
        return 0;
    }

    private static int HoldHostCommit(string release)
    {
        IntPtr bytes = VirtualAlloc(IntPtr.Zero, new UIntPtr(144 * 1024 * 1024), 0x3000, 4);
        if (bytes == IntPtr.Zero)
        {
            Console.WriteLine("commit refused by Windows");
            return 17;
        }
        try
        {
            Console.WriteLine("committed 144 MiB");
            HoldUntil(release);
            return 0;
        }
        finally
        {
            DiffGuard.Require(VirtualFree(bytes, UIntPtr.Zero, 0x8000), "release fixture memory");
        }
    }

    private static int ProbeHostLimits(string release, bool bounded)
    {
        if (bounded)
        {
            string prefix = ToolBudget.SessionPrefix();
            for (int slot = 0; slot < 4; slot++)
            {
                IntPtr command = OpenJobObject(4, false, prefix + "-slot-" + slot);
                if (command == IntPtr.Zero) continue;
                try
                {
                    bool holdsSlot;
                    DiffGuard.Require(ToolBudget.IsProcessInJob(DiffGuard.GetCurrentProcess(), command, out holdsSlot),
                        "check the host did not consume a command slot");
                    if (holdsSlot) return 8;
                }
                finally { DiffGuard.CloseHandle(command); }
            }
            CpuRate rate;
            DiffGuard.Require(QueryInformationJobObject(IntPtr.Zero, 15, out rate,
                Marshal.SizeOf(typeof(CpuRate)), IntPtr.Zero), "inspect the host CPU job");
            if (rate.Flags != 5 || rate.Rate == 0 || rate.Rate > 9000) return 3;
            DiffGuard.JobLimits limits;
            DiffGuard.Require(QueryInformationJobObject(IntPtr.Zero, 9, out limits,
                Marshal.SizeOf(typeof(DiffGuard.JobLimits)), IntPtr.Zero), "inspect the aggregate host memory limit");
            if (limits.JobMemoryLimit.ToUInt64() != 256UL * 1024 * 1024) return 4;
        }
        StringBuilder arguments = new StringBuilder("host-member ");
        DiffGuard.AppendArgument(arguments, release);
        ProcessStartInfo member = new ProcessStartInfo(typeof(Fixture).Assembly.Location, arguments.ToString());
        member.UseShellExecute = false;
        member.RedirectStandardOutput = true;
        member.CreateNoWindow = true;
        using (Process first = Process.Start(member))
        {
            try
            {
                if (first.StandardOutput.ReadLine() != "committed 144 MiB") return 5;
                using (Process second = Process.Start(member))
                {
                    string expected = bounded ? "commit refused by Windows" : "committed 144 MiB";
                    if (second.StandardOutput.ReadLine() != expected) return 6;
                    File.WriteAllText(release, "");
                    second.WaitForExit();
                    first.WaitForExit();
                    if (first.ExitCode != 0 || second.ExitCode != (bounded ? 17 : 0)) return 7;
                }
            }
            finally
            {
                File.WriteAllText(release, "");
            }
        }
        Console.WriteLine(bounded ? "host aggregate limit enforced" : "both control allocations succeeded");
        return 0;
    }

    private static int PrintHostRates(string release)
    {
        Stopwatch elapsed = Stopwatch.StartNew();
        uint previous = 0;
        while (!File.Exists(release) && elapsed.ElapsedMilliseconds < 15000)
        {
            CpuRate rate;
            DiffGuard.Require(QueryInformationJobObject(IntPtr.Zero, 15, out rate,
                Marshal.SizeOf(typeof(CpuRate)), IntPtr.Zero), "inspect the live aggregate CPU limit");
            if (rate.Flags != 5 || rate.Rate == 0 || rate.Rate > 9000) return 3;
            if (rate.Rate != previous)
            {
                Console.WriteLine("host CPU rate " + rate.Rate);
                previous = rate.Rate;
            }
            Thread.Sleep(25);
        }
        return File.Exists(release) ? 0 : 75;
    }

    private static CpuGovernor.CpuTimes? FixtureCpuTimes()
    {
        string directory = Environment.GetEnvironmentVariable("DSH_RESOURCE_FIXTURE_CPU");
        if (directory == null)
        {
            long elapsed = Stopwatch.GetTimestamp();
            return new CpuGovernor.CpuTimes(elapsed, elapsed);
        }
        string[] snapshots = Directory.GetFiles(directory, "cpu-time-*");
        Array.Sort(snapshots, StringComparer.Ordinal);
        string[] fields = Path.GetFileName(snapshots[snapshots.Length - 1]).Split('-');
        return new CpuGovernor.CpuTimes(long.Parse(fields[3]), long.Parse(fields[4]));
    }

    private static ToolBudget.MemorySnapshot FixtureMemory(string directory)
    {
        ulong physicalAvailable = File.Exists(Path.Combine(directory, "at-physical-threshold")) ? 5UL
            : File.Exists(Path.Combine(directory, "physical-pressure")) ? 6UL : 14UL;
        ulong committed = File.Exists(Path.Combine(directory, "at-commit-threshold")) ? 95UL
            : File.Exists(Path.Combine(directory, "commit-pressure")) ? 96UL : 70UL;
        return new ToolBudget.MemorySnapshot(100, physicalAvailable, 100, committed);
    }

    private static void HoldResidentMemory(string release)
    {
        byte[] data = new byte[48 * 1024 * 1024];
        const int page = 4096;
        for (int i = 0; i < data.Length; i += page) data[i] = (byte)(i / page + 1);
        Console.WriteLine("resident");
        HoldUntil(release);
        for (int i = 0; i < data.Length; i += page)
            if (data[i] != (byte)(i / page + 1)) throw new InvalidDataException("Resident buffer content changed.");
        Console.WriteLine("intact");
    }

    private static bool HasTestCapacity(string path, int occupied, ulong planned)
    {
        try
        {
            string capacity = File.ReadAllText(path);
            if (capacity.StartsWith("bytes:", StringComparison.Ordinal))
                return planned <= ulong.Parse(capacity.Substring(6));
            return capacity.Length == 0 || occupied < int.Parse(capacity);
        }
        catch (FileNotFoundException)
        {
            return false;
        }
    }

    private static void PrintRates(string prefix)
    {
        for (int slot = 0; slot < 4; slot++)
        {
            IntPtr job = OpenJobObject(4, false, prefix + "-slot-" + slot);
            if (job == IntPtr.Zero) continue;
            try
            {
                CpuRate rate;
                DiffGuard.Require(QueryInformationJobObject(job, 15, out rate, Marshal.SizeOf(typeof(CpuRate)), IntPtr.Zero),
                    "read the CPU hard cap");
                DiffGuard.JobLimits limits;
                DiffGuard.Require(QueryInformationJobObject(job, 9, out limits, Marshal.SizeOf(typeof(DiffGuard.JobLimits)), IntPtr.Zero),
                    "read the process tree memory limit");
                if ((limits.BasicLimitInformation.LimitFlags & 0x200) == 0 || limits.JobMemoryLimit.ToUInt64() != 2UL * 1024 * 1024 * 1024)
                    throw new InvalidOperationException("The process tree lost its 2 GiB memory limit.");
                Console.WriteLine(rate.Flags + ":" + rate.Rate);
            }
            finally { DiffGuard.CloseHandle(job); }
        }
    }

    private static void HoldUntil(string release)
    {
        Stopwatch elapsed = Stopwatch.StartNew();
        while (!File.Exists(release) && elapsed.ElapsedMilliseconds < 15000)
            Thread.Sleep(20);
        if (!File.Exists(release)) throw new InvalidOperationException("The test did not release its fixture.");
    }

    private static void StartDescendant(string release)
    {
        using (Process current = Process.GetCurrentProcess())
        using (Process child = Process.Start(new ProcessStartInfo(current.MainModule.FileName, "hold \"" + release + "\"")
        {
            UseShellExecute = false,
            CreateNoWindow = true,
        }))
        {
            Console.WriteLine("descendant " + child.Id);
        }
    }

    private static int WaitForTicket(string prefix, string sequence)
    {
        Stopwatch elapsed = Stopwatch.StartNew();
        string name = prefix + "-fifo-ticket-" + sequence;
        while (elapsed.ElapsedMilliseconds < 3000)
        {
            EventWaitHandle alive;
            if (EventWaitHandle.TryOpenExisting(name, EventWaitHandleRights.Synchronize, out alive))
            {
                alive.Dispose();
                return 0;
            }
            Thread.Sleep(20);
        }
        return 1;
    }
}
