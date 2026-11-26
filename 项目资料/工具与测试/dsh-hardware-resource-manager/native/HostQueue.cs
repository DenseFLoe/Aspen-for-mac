using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

internal sealed class HostQueue
{
    private readonly string prefix;
    private readonly TextWriter output;
    private readonly Func<int, ulong, bool> hasHeadroom;
    private readonly Dictionary<int, ManualResetEvent> requests = new Dictionary<int, ManualResetEvent>();
    private readonly object writes = new object();

    internal HostQueue(string prefix, TextWriter output, Func<int, ulong, bool> hasHeadroom)
    {
        this.prefix = prefix;
        this.output = output;
        this.hasHeadroom = hasHeadroom;
    }

    internal int Run(TextReader input)
    {
        try
        {
            string line;
            while ((line = input.ReadLine()) != null)
            {
                int split = line.IndexOf(' ');
                int id;
                if (split < 0 || !int.TryParse(line.Substring(split + 1), NumberStyles.None,
                    CultureInfo.InvariantCulture, out id) || id <= 0)
                    throw new InvalidDataException("Invalid host queue request.");

                string operation = line.Substring(0, split);
                if (operation == "request" || operation == "request-stat") Register(id, operation == "request-stat");
                else if (operation == "cancel") Cancel(id);
                else throw new InvalidDataException("Invalid host queue operation.");
            }
            return 0;
        }
        finally
        {
            lock (requests)
            {
                foreach (ManualResetEvent cancelled in requests.Values) cancelled.Set();
            }
        }
    }

    private void Cancel(int id)
    {
        lock (requests)
        {
            ManualResetEvent cancelled;
            if (requests.TryGetValue(id, out cancelled)) cancelled.Set();
        }
    }

    private void Register(int id, bool stat)
    {
        ManualResetEvent cancelled = new ManualResetEvent(false);
        using (ManualResetEvent registered = new ManualResetEvent(false))
        {
            lock (requests) requests.Add(id, cancelled);
            // A parked request needs a thread to own its ticket mutex, not a separate process.
            Thread waiter = new Thread(() => RunRequest(id, stat, cancelled, registered), 256 * 1024);
            waiter.IsBackground = true;
            try
            {
                waiter.Start();
            }
            catch
            {
                lock (requests) requests.Remove(id);
                cancelled.Dispose();
                throw;
            }
            // Register in input order even if Windows schedules the waiter threads differently.
            registered.WaitOne();
        }
    }

    private void Write(string status, int id, string detail = null)
    {
        lock (writes)
        {
            output.WriteLine(status + " " + id.ToString(CultureInfo.InvariantCulture) +
                (detail == null ? "" : " " + detail));
            output.Flush();
        }
    }

    private void RunRequest(int id, bool stat, ManualResetEvent cancelled, ManualResetEvent registered)
    {
        bool announced = false;
        try
        {
            bool consumed = ToolBudget.OfferPermit(prefix, stat, cancelled, () =>
            {
                announced = true;
                registered.Set();
            }, token => Write("permit", id, token), hasHeadroom);
            Write(consumed ? "claimed" : "cancelled", id);
        }
        catch (IOException) { /* The host closed the pipe. */ }
        catch (Exception error)
        {
            try { Write("error", id, Convert.ToBase64String(Encoding.UTF8.GetBytes(error.Message))); }
            catch (IOException) { /* The host closed the pipe. */ }
        }
        finally
        {
            if (!announced) registered.Set();
            lock (requests) requests.Remove(id);
            cancelled.Dispose();
        }
    }
}
