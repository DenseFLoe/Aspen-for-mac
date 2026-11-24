using System;
using System.ComponentModel;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;

internal static class DiffGuard
{
    private const uint CreateSuspended = 4;
    private const uint UseStdHandles = 0x100;
    private const uint ProcessMemoryLimit = 0x100;
    private const uint KillOnJobClose = 0x2000;
    private const int ExtendedLimitInformation = 9;
    private const uint MaximumProcessMemory = 768 * 1024 * 1024;

    [StructLayout(LayoutKind.Sequential)]
    internal struct BasicLimits
    {
        public long PerProcessUserTimeLimit, PerJobUserTimeLimit;
        public uint LimitFlags;
        public UIntPtr MinimumWorkingSetSize, MaximumWorkingSetSize;
        public uint ActiveProcessLimit;
        public UIntPtr Affinity;
        public uint PriorityClass, SchedulingClass;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal struct IoCounters
    {
        public ulong ReadOperations, WriteOperations, OtherOperations;
        public ulong ReadBytes, WriteBytes, OtherBytes;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal struct JobLimits
    {
        public BasicLimits BasicLimitInformation;
        public IoCounters IoInfo;
        public UIntPtr ProcessMemoryLimit, JobMemoryLimit;
        public UIntPtr PeakProcessMemoryUsed, PeakJobMemoryUsed;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal struct StartupInfo
    {
        public int Size;
        public IntPtr Reserved, Desktop, Title;
        public uint X, Y, XSize, YSize, XChars, YChars, Fill, Flags;
        public ushort ShowWindow, ReservedBytes;
        public IntPtr ReservedPointer, Input, Output, Error;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal struct ProcessInfo
    {
        public IntPtr Process, Thread;
        public uint ProcessId, ThreadId;
    }

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    internal static extern IntPtr CreateJobObject(IntPtr attributes, string name);

    [DllImport("kernel32.dll", SetLastError = true)]
    internal static extern bool SetInformationJobObject(IntPtr job, int kind, ref JobLimits limits, int size);

    [DllImport("kernel32.dll", SetLastError = true)]
    internal static extern bool AssignProcessToJobObject(IntPtr job, IntPtr process);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    internal static extern bool CreateProcess(
        string application, StringBuilder command, IntPtr processAttributes,
        IntPtr threadAttributes, bool inheritHandles, uint flags, IntPtr environment,
        string directory, ref StartupInfo startup, out ProcessInfo process);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern IntPtr GetStdHandle(int which);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern uint ResumeThread(IntPtr thread);

    [DllImport("kernel32.dll", SetLastError = true)]
    internal static extern uint WaitForSingleObject(IntPtr handle, uint milliseconds);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool GetExitCodeProcess(IntPtr process, out uint exitCode);

    [DllImport("kernel32.dll", SetLastError = true)]
    internal static extern bool TerminateProcess(IntPtr process, uint exitCode);

    [DllImport("kernel32.dll", SetLastError = true)]
    internal static extern bool CloseHandle(IntPtr handle);

    private static int Main(string[] arguments)
    {
        IntPtr job = IntPtr.Zero;
        ProcessInfo child = new ProcessInfo();
        bool childExited = false;

        try
        {
            if (arguments.Length == 1 && arguments[0] == "--dsh-admit-shell")
                return ToolBudget.AdmitShell();
            if (arguments.Length == 3 && arguments[0] == "--dsh-keep-slot")
                return ToolBudget.KeepSlot(arguments[1], arguments[2]);

            bool budgetedCommand = arguments.Length >= 2 && arguments[0] == "--dsh-run-bounded";
            string home = AppDomain.CurrentDomain.BaseDirectory;
            string executable = budgetedCommand ? arguments[1] :
                File.ReadAllText(Path.Combine(home, "gnu-diff.txt"));
            if (!Path.IsPathRooted(executable) || (!budgetedCommand &&
                !string.Equals(Path.GetFileName(executable), "diff.exe", StringComparison.OrdinalIgnoreCase)))
                throw new InvalidDataException("GNU diff must be configured as an absolute diff.exe path.");
            if (!File.Exists(executable))
                throw new FileNotFoundException("The requested executable does not exist.", executable);

            job = CreateJobObject(IntPtr.Zero, null);
            Require(job != IntPtr.Zero, "create job");
            JobLimits limits = new JobLimits();
            limits.BasicLimitInformation.LimitFlags = KillOnJobClose;
            if (!budgetedCommand)
            {
                limits.BasicLimitInformation.LimitFlags |= ProcessMemoryLimit;
                limits.ProcessMemoryLimit = new UIntPtr(MaximumProcessMemory);
            }
            Require(SetInformationJobObject(job, ExtendedLimitInformation, ref limits, Marshal.SizeOf(limits)),
                "set process lifetime and memory limits");

            StartupInfo startup = new StartupInfo();
            startup.Size = Marshal.SizeOf(startup);
            startup.Flags = UseStdHandles;
            startup.Input = GetStdHandle(-10);
            startup.Output = GetStdHandle(-11);
            startup.Error = GetStdHandle(-12);

            StringBuilder command = new StringBuilder();
            AppendArgument(command, executable);
            for (int i = budgetedCommand ? 2 : 0; i < arguments.Length; i++)
            {
                command.Append(' ');
                AppendArgument(command, arguments[i]);
            }

            Require(CreateProcess(executable, command, IntPtr.Zero, IntPtr.Zero, true,
                CreateSuspended, IntPtr.Zero, null, ref startup, out child), "create suspended tool process");
            if (budgetedCommand) ToolBudget.Admit(child.Process);
            Require(AssignProcessToJobObject(job, child.Process), "attach the tool process to its closing job");
            Require(ResumeThread(child.Thread) != uint.MaxValue, "resume the tool process");
            Require(WaitForSingleObject(child.Process, uint.MaxValue) == 0, "wait for the tool process");
            childExited = true;

            uint result;
            Require(GetExitCodeProcess(child.Process, out result), "read tool exit code");
            return unchecked((int)result);
        }
        catch (TimeoutException error)
        {
            Console.Error.WriteLine("DSH memory budget: " + error.Message);
            return 75;
        }
        catch (Exception error)
        {
            Console.Error.WriteLine("DSH tool guard: " + error.Message);
            return 2;
        }
        finally
        {
            if (child.Process != IntPtr.Zero)
            {
                if (!childExited)
                    TerminateProcess(child.Process, 2);
                CloseHandle(child.Process);
            }
            if (child.Thread != IntPtr.Zero)
                CloseHandle(child.Thread);
            if (job != IntPtr.Zero)
                CloseHandle(job);
        }
    }

    internal static void Require(bool succeeded, string operation)
    {
        if (!succeeded)
        {
            int error = Marshal.GetLastWin32Error();
            throw new Win32Exception(error, operation + ": " + new Win32Exception(error).Message);
        }
    }

    internal static void AppendArgument(StringBuilder command, string argument)
    {
        command.Append('"');
        int slashes = 0;
        foreach (char character in argument)
        {
            if (character == '\\')
            {
                slashes++;
                continue;
            }
            if (character == '"')
                command.Append('\\', slashes + 1);
            command.Append('\\', slashes);
            command.Append(character);
            slashes = 0;
        }
        command.Append('\\', slashes * 2);
        command.Append('"');
    }
}
