using System;
using System.Globalization;
using System.Security.AccessControl;
using System.Threading;
using Microsoft.Win32.SafeHandles;

internal sealed class AdmissionQueue : IDisposable
{
    private const int Head = 0;
    private const int Tail = 1;

    private readonly string prefix;
    private readonly Mutex gate;
    private readonly SharedCounters counters;

    internal AdmissionQueue(string budgetPrefix)
    {
        prefix = budgetPrefix + "-fifo";
        gate = SharedObjects.CreateMutex(prefix + "-gate");
        try
        {
            Enter(gate);
            try
            {
                counters = new SharedCounters(prefix + "-counters", 2);
            }
            finally
            {
                gate.ReleaseMutex();
            }
        }
        catch
        {
            gate.Dispose();
            throw;
        }
    }

    internal sealed class Ticket : IDisposable
    {
        internal readonly long Number;
        private readonly EventWaitHandle marker;
        private readonly Mutex lifetime;

        internal Ticket(long number, EventWaitHandle marker, Mutex lifetime)
        {
            Number = number;
            this.marker = marker;
            this.lifetime = lifetime;
        }

        public void Dispose()
        {
            // Remove the queue marker before waking the next waiter.
            marker.Dispose();
            lifetime.ReleaseMutex();
            lifetime.Dispose();
        }
    }

    internal sealed class ProcessExit : WaitHandle
    {
        internal ProcessExit(IntPtr process)
        {
            SafeWaitHandle = new SafeWaitHandle(process, false);
        }
    }

    internal Ticket Enqueue()
    {
        Enter(gate);
        try
        {
            long number = counters.Read(Tail);
            Mutex lifetime = SharedObjects.CreateMutex(TicketName(number) + "-lifetime");
            Enter(lifetime);
            EventWaitHandle marker = null;
            try
            {
                // A marker remains compatible with clients that predate signalled waits.
                marker = SharedObjects.CreateEvent(TicketName(number), EventResetMode.ManualReset);
                counters.Write(Tail, unchecked(number + 1));
                return new Ticket(number, marker, lifetime);
            }
            catch
            {
                if (marker != null) marker.Dispose();
                lifetime.ReleaseMutex();
                lifetime.Dispose();
                throw;
            }
        }
        finally
        {
            gate.ReleaseMutex();
        }
    }

    internal bool WaitForTurn(Ticket ticket, WaitHandle cancelled, int waitMilliseconds, int legacyPollMilliseconds)
    {
        Mutex predecessor = null;
        Enter(gate);
        try
        {
            long head = counters.Read(Head);
            while (head != ticket.Number && !HasMarker(head))
            {
                head = unchecked(head + 1);
                counters.Write(Head, head);
            }
            if (head == ticket.Number) return true;

            // Sleep behind the closest live predecessor. Waiting on the head
            // would wake every queued process together when one slot opens.
            long previous = unchecked(ticket.Number - 1);
            while (previous != head && !HasMarker(previous)) previous = unchecked(previous - 1);
            Mutex.TryOpenExisting(TicketName(previous) + "-lifetime",
                MutexRights.Synchronize | MutexRights.Modify, out predecessor);
        }
        finally
        {
            gate.ReleaseMutex();
        }

        if (predecessor == null)
        {
            int interval = waitMilliseconds == Timeout.Infinite ? legacyPollMilliseconds : Math.Min(waitMilliseconds, legacyPollMilliseconds);
            cancelled.WaitOne(interval);
            return false;
        }

        using (predecessor)
        {
            try
            {
                if (WaitHandle.WaitAny(new WaitHandle[] { cancelled, predecessor }, waitMilliseconds) == 1)
                    predecessor.ReleaseMutex();
            }
            catch (AbandonedMutexException error)
            {
                if (error.MutexIndex != 1) throw;
                predecessor.ReleaseMutex();
            }
        }
        return false;
    }

    private bool HasMarker(long number)
    {
        EventWaitHandle marker;
        if (!EventWaitHandle.TryOpenExisting(TicketName(number), EventWaitHandleRights.Synchronize, out marker)) return false;
        marker.Dispose();
        return true;
    }

    internal int PendingCount()
    {
        Enter(gate);
        try
        {
            int count = 0;
            long tail = counters.Read(Tail);
            for (long number = counters.Read(Head); number != tail; number = unchecked(number + 1))
                if (HasMarker(number)) count++;
            return count;
        }
        finally
        {
            gate.ReleaseMutex();
        }
    }

    private string TicketName(long ticket)
    {
        return prefix + "-ticket-" + ticket.ToString(CultureInfo.InvariantCulture);
    }

    internal static void Enter(Mutex mutex)
    {
        try { mutex.WaitOne(); }
        catch (AbandonedMutexException) { /* Windows has granted ownership. */ }
    }

    public void Dispose()
    {
        counters.Dispose();
        gate.Dispose();
    }
}
