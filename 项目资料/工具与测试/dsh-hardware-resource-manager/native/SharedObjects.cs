using System;
using System.Runtime.InteropServices;
using System.Security.AccessControl;
using System.Security.Principal;
using System.Threading;
using Microsoft.Win32.SafeHandles;

internal static class SharedObjects
{
    internal const uint MapReadWrite = 0x6;
    // DSH's Windows sandbox uses a Low, write-restricted token whose restricting
    // list includes the logon SID. Scope these grants to our session-local objects.
    private static readonly byte[] Descriptor = Describe("GA");

    [DllImport("advapi32.dll", SetLastError = true)]
    private static extern bool GetTokenInformation(IntPtr token, int kind, IntPtr buffer, int bytes, out int required);

    private static SecurityIdentifier LogonSid(WindowsIdentity identity)
    {
        const int tokenLogonSid = 28;
        int bytes;
        GetTokenInformation(identity.Token, tokenLogonSid, IntPtr.Zero, 0, out bytes);
        if (bytes == 0) return null;
        IntPtr buffer = Marshal.AllocHGlobal(bytes);
        try
        {
            DiffGuard.Require(GetTokenInformation(identity.Token, tokenLogonSid, buffer, bytes, out bytes),
                "read the Windows logon SID");
            if (Marshal.ReadInt32(buffer) == 0) return null;
            return new SecurityIdentifier(Marshal.ReadIntPtr(buffer, IntPtr.Size));
        }
        finally
        {
            Marshal.FreeHGlobal(buffer);
        }
    }

    private static byte[] Describe(string rights)
    {
        using (WindowsIdentity identity = WindowsIdentity.GetCurrent())
        {
            string access = "D:P(A;;" + rights + ";;;" + identity.User.Value + ")";
            SecurityIdentifier logon = LogonSid(identity);
            if (logon != null) access += "(A;;" + rights + ";;;" + logon.Value + ")";
            RawSecurityDescriptor security = new RawSecurityDescriptor(access + "S:(ML;;NW;;;LW)");
            byte[] descriptor = new byte[security.BinaryLength];
            security.GetBinaryForm(descriptor, 0);
            return descriptor;
        }
    }

    internal static Mutex CreateMutex(string name)
    {
        IntPtr handle = Create(name, ObjectKind.Mutex);
        Mutex mutex = new Mutex();
        mutex.SafeWaitHandle.Dispose();
        mutex.SafeWaitHandle = new SafeWaitHandle(handle, true);
        return mutex;
    }

    internal static EventWaitHandle CreateEvent(string name, EventResetMode mode)
    {
        IntPtr handle = Create(name, mode == EventResetMode.ManualReset ? ObjectKind.ManualEvent : ObjectKind.AutoEvent);
        EventWaitHandle signal = new EventWaitHandle(false, mode);
        signal.SafeWaitHandle.Dispose();
        signal.SafeWaitHandle = new SafeWaitHandle(handle, true);
        return signal;
    }

    internal static IntPtr CreateCounters(string name, int bytes)
    {
        IntPtr existing = OpenFileMapping(MapReadWrite, false, name);
        if (existing != IntPtr.Zero) return existing;
        DiffGuard.Require(Marshal.GetLastWin32Error() == 2, "open the shared resource queue counters");
        return Create(name, ObjectKind.Counters, bytes);
    }

    private enum ObjectKind { Mutex, ManualEvent, AutoEvent, Counters, Slot }

    [StructLayout(LayoutKind.Sequential)]
    private struct SecurityAttributes
    {
        public int Length;
        public IntPtr Descriptor;
        public int Inherit;
    }

    [DllImport("kernel32.dll", EntryPoint = "CreateJobObjectW", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr CreateJobObject(ref SecurityAttributes security, string name);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr CreateMutexEx(ref SecurityAttributes security, string name, uint flags, uint access);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr CreateEventEx(ref SecurityAttributes security, string name, uint flags, uint access);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr CreateFileMapping(IntPtr file, ref SecurityAttributes security, uint protection,
        uint highSize, uint lowSize, string name);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    private static extern IntPtr OpenFileMapping(uint access, bool inherit, string name);

    internal static IntPtr CreateSlot(string name)
    {
        return Create(name, ObjectKind.Slot);
    }

    internal static IntPtr CreateHostJob(string name)
    {
        return Create(name, ObjectKind.Slot, 0, Describe("0x4"));
    }

    private static IntPtr Create(string name, ObjectKind kind, int bytes = 0, byte[] descriptor = null)
    {
        const uint synchronize = 0x00100000;
        const uint mutexModifyState = 1;
        const uint eventModifyState = 2;
        const uint manualReset = 1;
        const uint pageReadWrite = 4;
        GCHandle pin = GCHandle.Alloc(descriptor ?? Descriptor, GCHandleType.Pinned);
        try
        {
            SecurityAttributes attributes = new SecurityAttributes();
            attributes.Length = Marshal.SizeOf(attributes);
            attributes.Descriptor = pin.AddrOfPinnedObject();
            IntPtr handle;
            switch (kind)
            {
                case ObjectKind.Mutex:
                    handle = CreateMutexEx(ref attributes, name, 0, synchronize | mutexModifyState);
                    break;
                case ObjectKind.ManualEvent:
                case ObjectKind.AutoEvent:
                    uint flags = kind == ObjectKind.ManualEvent ? manualReset : 0;
                    handle = CreateEventEx(ref attributes, name, flags, synchronize | eventModifyState);
                    break;
                case ObjectKind.Counters:
                    handle = CreateFileMapping(new IntPtr(-1), ref attributes, pageReadWrite, 0, (uint)bytes, name);
                    break;
                default:
                    handle = CreateJobObject(ref attributes, name);
                    break;
            }
            DiffGuard.Require(handle != IntPtr.Zero, "create shared Windows resource " + kind);
            return handle;
        }
        finally
        {
            pin.Free();
        }
    }
}

internal sealed class SharedCounters : IDisposable
{
    private readonly IntPtr mapping;
    private readonly IntPtr view;

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern IntPtr MapViewOfFile(IntPtr file, uint access, uint highOffset, uint lowOffset, UIntPtr bytes);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool UnmapViewOfFile(IntPtr view);

    // Callers serialize creation and updates using the mutex for this mapping.
    internal SharedCounters(string name, int words)
    {
        int bytes = words * sizeof(long);
        mapping = SharedObjects.CreateCounters(name, bytes);
        try
        {
            view = MapViewOfFile(mapping, SharedObjects.MapReadWrite, 0, 0, new UIntPtr((uint)bytes));
            DiffGuard.Require(view != IntPtr.Zero, "map shared Windows resource counters");
        }
        catch
        {
            DiffGuard.CloseHandle(mapping);
            throw;
        }
    }

    internal long Read(int word) { return Marshal.ReadInt64(view, word * sizeof(long)); }

    internal void Write(int word, long value) { Marshal.WriteInt64(view, word * sizeof(long), value); }

    public void Dispose()
    {
        UnmapViewOfFile(view);
        DiffGuard.CloseHandle(mapping);
    }
}
