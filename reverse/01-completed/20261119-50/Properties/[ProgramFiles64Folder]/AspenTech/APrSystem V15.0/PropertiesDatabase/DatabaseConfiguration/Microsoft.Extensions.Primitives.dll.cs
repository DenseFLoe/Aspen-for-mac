// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// Source files combined from dotnet/runtime at 5535e31a712343a63f5d7d796cd874e563e5ac14.
#define NETCOREAPP
#nullable enable annotations

using Microsoft.Extensions.FileProviders;
using Microsoft.Extensions.Internal;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Diagnostics;
using System.Numerics.Hashing;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Permissions;
using System.Security;
using System.Text;
using System.Threading;
using System;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyDefaultAlias("Microsoft.Extensions.Primitives")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata("IsTrimmable", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyCopyright("© Microsoft Corporation. All rights reserved.")]
[assembly: AssemblyDescription("Primitives shared by framework extensions. Commonly used types include:\r\n\r\nCommonly Used Types:\r\nMicrosoft.Extensions.Primitives.IChangeToken\r\nMicrosoft.Extensions.Primitives.StringValues\r\nMicrosoft.Extensions.Primitives.StringSegment")]
[assembly: AssemblyFileVersion("8.0.23.53103")]
[assembly: AssemblyInformationalVersion("8.0.0+5535e31a712343a63f5d7d796cd874e563e5ac14")]
[assembly: AssemblyProduct("Microsoft® .NET")]
[assembly: AssemblyTitle("Microsoft.Extensions.Primitives")]
[assembly: AssemblyMetadata("RepositoryUrl", "https://github.com/dotnet/runtime")]
[assembly: AssemblyVersion("8.0.0.0")]

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// A <see cref="IChangeToken"/> implementation using <see cref="CancellationToken"/>.
    /// </summary>
    [DebuggerDisplay("HasChanged = {HasChanged}")]
    public class CancellationChangeToken : IChangeToken
    {
        /// <summary>
        /// Initializes a new instance of <see cref="CancellationChangeToken"/>.
        /// </summary>
        /// <param name="cancellationToken">The <see cref="CancellationToken"/>.</param>
        public CancellationChangeToken(CancellationToken cancellationToken)
        {
            Token = cancellationToken;
        }

        /// <inheritdoc />
        public bool ActiveChangeCallbacks { get; private set; } = true;

        /// <inheritdoc />
        public bool HasChanged => Token.IsCancellationRequested;

        private CancellationToken Token { get; }

        /// <inheritdoc />
        public IDisposable RegisterChangeCallback(Action<object?> callback, object? state)
        {
            return ChangeCallbackRegistrar.UnsafeRegisterChangeCallback(
                callback,
                state,
                Token,
                static s => s.ActiveChangeCallbacks = false, // Reset the flag to indicate to future callers that this wouldn't work.
                this);
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// Propagates notifications that a change has occurred.
    /// </summary>
    public static class ChangeToken
    {
        /// <summary>
        /// Registers the <paramref name="changeTokenConsumer"/> action to be called whenever the token produced changes.
        /// </summary>
        /// <param name="changeTokenProducer">Produces the change token.</param>
        /// <param name="changeTokenConsumer">Action called when the token changes.</param>
        /// <returns></returns>
        public static IDisposable OnChange(Func<IChangeToken?> changeTokenProducer, Action changeTokenConsumer)
        {
            if (changeTokenProducer is null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.changeTokenProducer);
            }
            if (changeTokenConsumer is null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.changeTokenConsumer);
            }

            return new ChangeTokenRegistration<Action>(changeTokenProducer, callback => callback(), changeTokenConsumer);
        }

        /// <summary>
        /// Registers the <paramref name="changeTokenConsumer"/> action to be called whenever the token produced changes.
        /// </summary>
        /// <param name="changeTokenProducer">Produces the change token.</param>
        /// <param name="changeTokenConsumer">Action called when the token changes.</param>
        /// <param name="state">state for the consumer.</param>
        /// <returns></returns>
        public static IDisposable OnChange<TState>(Func<IChangeToken?> changeTokenProducer, Action<TState> changeTokenConsumer, TState state)
        {
            if (changeTokenProducer is null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.changeTokenProducer);
            }
            if (changeTokenConsumer is null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.changeTokenConsumer);
            }

            return new ChangeTokenRegistration<TState>(changeTokenProducer, changeTokenConsumer, state);
        }

        private sealed class ChangeTokenRegistration<TState> : IDisposable
        {
            private readonly Func<IChangeToken?> _changeTokenProducer;
            private readonly Action<TState> _changeTokenConsumer;
            private readonly TState _state;
            private IDisposable? _disposable;

            private static readonly NoopDisposable _disposedSentinel = new NoopDisposable();

            public ChangeTokenRegistration(Func<IChangeToken?> changeTokenProducer, Action<TState> changeTokenConsumer, TState state)
            {
                _changeTokenProducer = changeTokenProducer;
                _changeTokenConsumer = changeTokenConsumer;
                _state = state;

                IChangeToken? token = changeTokenProducer();

                RegisterChangeTokenCallback(token);
            }

            private void OnChangeTokenFired()
            {
                // The order here is important. We need to take the token and then apply our changes BEFORE
                // registering. This prevents us from possible having two change updates to process concurrently.
                //
                // If the token changes after we take the token, then we'll process the update immediately upon
                // registering the callback.
                IChangeToken? token = _changeTokenProducer();

                try
                {
                    _changeTokenConsumer(_state);
                }
                finally
                {
                    // We always want to ensure the callback is registered
                    RegisterChangeTokenCallback(token);
                }
            }

            private void RegisterChangeTokenCallback(IChangeToken? token)
            {
                if (token is null)
                {
                    return;
                }
                IDisposable registraton = token.RegisterChangeCallback(s => ((ChangeTokenRegistration<TState>?)s)!.OnChangeTokenFired(), this);
                if (token.HasChanged && token.ActiveChangeCallbacks)
                {
                    registraton?.Dispose();
                    return;
                }
                SetDisposable(registraton);
            }

            private void SetDisposable(IDisposable disposable)
            {
                // We don't want to transition from _disposedSentinel => anything since it's terminal
                // but we want to allow going from previously assigned disposable, to another
                // disposable.
                IDisposable? current = Volatile.Read(ref _disposable);

                // If Dispose was called, then immediately dispose the disposable
                if (current == _disposedSentinel)
                {
                    disposable.Dispose();
                    return;
                }

                // Otherwise, try to update the disposable
                IDisposable? previous = Interlocked.CompareExchange(ref _disposable, disposable, current);

                if (previous == _disposedSentinel)
                {
                    // The subscription was disposed so we dispose immediately and return
                    disposable.Dispose();
                }
                else if (previous == current)
                {
                    // We successfully assigned the _disposable field to disposable
                }
                else
                {
                    // Sets can never overlap with other SetDisposable calls so we should never get into this situation
                    throw new InvalidOperationException("Somebody else set the _disposable field");
                }
            }

            public void Dispose()
            {
                // If the previous value is disposable then dispose it, otherwise,
                // now we've set the disposed sentinel
                Interlocked.Exchange(ref _disposable, _disposedSentinel)?.Dispose();
            }

            private sealed class NoopDisposable : IDisposable
            {
                public void Dispose()
                {
                }
            }
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// An <see cref="IChangeToken"/> which represents one or more <see cref="IChangeToken"/> instances.
    /// </summary>
    [DebuggerDisplay("HasChanged = {HasChanged}")]
    public class CompositeChangeToken : IChangeToken
    {
        private static readonly Action<object?> _onChangeDelegate = OnChange;
        private readonly object _callbackLock = new();
        private CancellationTokenSource? _cancellationTokenSource;
        private List<IDisposable>? _disposables;

        [MemberNotNullWhen(true, nameof(_cancellationTokenSource))]
        [MemberNotNullWhen(true, nameof(_disposables))]
        private bool RegisteredCallbackProxy { get; set; }

        /// <summary>
        /// Creates a new instance of <see cref="CompositeChangeToken"/>.
        /// </summary>
        /// <param name="changeTokens">The list of <see cref="IChangeToken"/> to compose.</param>
        public CompositeChangeToken(IReadOnlyList<IChangeToken> changeTokens)
        {
            if (changeTokens is null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.changeTokens);
            }

            ChangeTokens = changeTokens;
            for (int i = 0; i < ChangeTokens.Count; i++)
            {
                if (ChangeTokens[i].ActiveChangeCallbacks)
                {
                    ActiveChangeCallbacks = true;
                    break;
                }
            }
        }

        /// <summary>
        /// Returns the list of <see cref="IChangeToken"/> which compose the current <see cref="CompositeChangeToken"/>.
        /// </summary>
        public IReadOnlyList<IChangeToken> ChangeTokens { get; }

        /// <inheritdoc />
        public IDisposable RegisterChangeCallback(Action<object?> callback, object? state)
        {
            EnsureCallbacksInitialized();
            return _cancellationTokenSource.Token.Register(callback, state);
        }

        /// <inheritdoc />
        public bool HasChanged
        {
            get
            {
                if (_cancellationTokenSource != null && _cancellationTokenSource.Token.IsCancellationRequested)
                {
                    return true;
                }

                for (int i = 0; i < ChangeTokens.Count; i++)
                {
                    if (ChangeTokens[i].HasChanged)
                    {
                        OnChange(this);
                        return true;
                    }
                }

                return false;
            }
        }

        /// <inheritdoc />
        public bool ActiveChangeCallbacks { get; }

        [MemberNotNull(nameof(_cancellationTokenSource))]
        [MemberNotNull(nameof(_disposables))]
        private void EnsureCallbacksInitialized()
        {
            if (RegisteredCallbackProxy)
            {
                return;
            }

            lock (_callbackLock)
            {
                if (RegisteredCallbackProxy)
                {
                    return;
                }

                _cancellationTokenSource = new CancellationTokenSource();
                _disposables = new List<IDisposable>();
                for (int i = 0; i < ChangeTokens.Count; i++)
                {
                    if (ChangeTokens[i].ActiveChangeCallbacks)
                    {
                        IDisposable disposable = ChangeTokens[i].RegisterChangeCallback(_onChangeDelegate, this);
                        if (_cancellationTokenSource.IsCancellationRequested)
                        {
                            disposable.Dispose();
                            break;
                        }
                        _disposables.Add(disposable);
                    }
                }
                RegisteredCallbackProxy = true;
            }
        }

        private static void OnChange(object? state)
        {
            Debug.Assert(state != null);

            var compositeChangeTokenState = (CompositeChangeToken)state;
            if (compositeChangeTokenState._cancellationTokenSource == null)
            {
                return;
            }

            lock (compositeChangeTokenState._callbackLock)
            {
                if (compositeChangeTokenState._cancellationTokenSource.IsCancellationRequested)
                {
                    return;
                }

                try
                {
                    compositeChangeTokenState._cancellationTokenSource.Cancel();
                }
                catch
                {
                }
            }

            List<IDisposable>? disposables = compositeChangeTokenState._disposables;
            Debug.Assert(disposables != null);
            for (int i = 0; i < disposables.Count; i++)
            {
                disposables[i].Dispose();
            }
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// Provides extensions methods for the <see cref="Primitives"/> namespace.
    /// </summary>
    public static class Extensions
    {
        /// <summary>
        /// Add the given <see cref="StringSegment"/> to the <see cref="StringBuilder"/>.
        /// </summary>
        /// <param name="builder">The <see cref="StringBuilder"/> to add to.</param>
        /// <param name="segment">The <see cref="StringSegment"/> to add.</param>
        /// <returns>The original <see cref="StringBuilder"/>.</returns>
        public static StringBuilder Append(this StringBuilder builder, StringSegment segment)
        {
            return builder.Append(segment.Buffer, segment.Offset, segment.Length);
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// Propagates notifications that a change has occurred.
    /// </summary>
    public interface IChangeToken
    {
        /// <summary>
        /// Gets a value that indicates if a change has occurred.
        /// </summary>
        bool HasChanged { get; }

        /// <summary>
        /// Indicates if this token will pro-actively raise callbacks. If <c>false</c>, the token consumer must
        /// poll <see cref="HasChanged" /> to detect changes.
        /// </summary>
        bool ActiveChangeCallbacks { get; }

        /// <summary>
        /// Registers for a callback that will be invoked when the entry has changed.
        /// <see cref="HasChanged"/> MUST be set before the callback is invoked.
        /// </summary>
        /// <param name="callback">The <see cref="Action{Object}"/> to invoke.</param>
        /// <param name="state">State to be passed into the callback.</param>
        /// <returns>An <see cref="IDisposable"/> that is used to unregister the callback.</returns>
        IDisposable RegisterChangeCallback(Action<object?> callback, object? state);
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// Provides a mechanism for fast, non-allocating string concatenation.
    /// </summary>
    [DebuggerDisplay("Value = {_value}")]
    [EditorBrowsable(EditorBrowsableState.Never)]
    [Obsolete("This type is retained only for compatibility. The recommended alternative is string.Create<TState> (int length, TState state, System.Buffers.SpanAction<char,TState> action).", error: true)]
    public struct InplaceStringBuilder
    {
        private int _offset;
        private int _capacity;
        private string? _value;

        /// <summary>
        /// Initializes a new instance of the <see cref="InplaceStringBuilder"/> class.
        /// </summary>
        /// <param name="capacity">The suggested starting size of the <see cref="InplaceStringBuilder"/> instance.</param>
        public InplaceStringBuilder(int capacity) : this()
        {
            if (capacity < 0)
            {
                ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.capacity);
            }

            _capacity = capacity;
        }

        /// <summary>
        /// Gets the number of characters that the current <see cref="InplaceStringBuilder"/> object can contain.
        /// </summary>
        public int Capacity
        {
            get => _capacity;
            set
            {
                if (value < 0)
                {
                    ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.value);
                }

                // _offset > 0 indicates writing state
                if (_offset > 0)
                {
                    ThrowHelper.ThrowInvalidOperationException(ExceptionResource.Capacity_CannotChangeAfterWriteStarted);
                }

                _capacity = value;
            }
        }

        /// <summary>
        /// Appends a string to the end of the current <see cref="InplaceStringBuilder"/> instance.
        /// </summary>
        /// <param name="value">The string to append.</param>
        public void Append(string? value)
        {
            if (value == null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.value);
            }

            Append(value, 0, value.Length);
        }

        /// <summary>
        /// Appends a string segment to the end of the current <see cref="InplaceStringBuilder"/> instance.
        /// </summary>
        /// <param name="segment">The string segment to append.</param>
        public void Append(StringSegment segment)
        {
            Append(segment.Buffer, segment.Offset, segment.Length);
        }

        /// <summary>
        /// Appends a substring to the end of the current <see cref="InplaceStringBuilder"/> instance.
        /// </summary>
        /// <param name="value">The string that contains the substring to append.</param>
        /// <param name="offset">The starting position of the substring within value.</param>
        /// <param name="count">The number of characters in value to append.</param>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public unsafe void Append(string? value, int offset, int count)
        {
            EnsureValueIsInitialized();

            if (value == null
                || offset < 0
                || value.Length - offset < count
                || Capacity - _offset < count)
            {
                ThrowValidationError(value, offset, count);
            }

            fixed (char* destination = _value)
            fixed (char* source = value)
            {
                Unsafe.CopyBlockUnaligned(destination + _offset, source + offset, (uint)count * 2);
                _offset += count;
            }
        }

        /// <summary>
        /// Appends a character to the end of the current <see cref="InplaceStringBuilder"/> instance.
        /// </summary>
        /// <param name="c">The character to append.</param>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public unsafe void Append(char c)
        {
            EnsureValueIsInitialized();

            if (_offset >= Capacity)
            {
                ThrowHelper.ThrowInvalidOperationException(ExceptionResource.Capacity_NotEnough, 1, Capacity - _offset);
            }

            fixed (char* destination = _value)
            {
                destination[_offset++] = c;
            }
        }

        /// <summary>
        /// Converts the value of this instance to a String.
        /// </summary>
        /// <returns>A string whose value is the same as this instance.</returns>
        public override string? ToString()
        {
            if (Capacity != _offset)
            {
                ThrowHelper.ThrowInvalidOperationException(ExceptionResource.Capacity_NotUsedEntirely, Capacity, _offset);
            }

            return _value;
        }

        private void EnsureValueIsInitialized()
        {
            _value ??= new string('\0', _capacity);
        }

        private void ThrowValidationError(string? value, int offset, int count)
        {
            if (value == null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.value);
            }

            if (offset < 0 || value.Length - offset < count)
            {
                ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.offset);
            }

            if (Capacity - _offset < count)
            {
                ThrowHelper.ThrowInvalidOperationException(ExceptionResource.Capacity_NotEnough, value.Length, Capacity - _offset);
            }
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// An optimized representation of a substring.
    /// </summary>
    [DebuggerDisplay("{Value}")]
    public readonly struct StringSegment : IEquatable<StringSegment>, IEquatable<string?>
    {
        /// <summary>
        /// A <see cref="StringSegment"/> for <see cref="string.Empty"/>.
        /// </summary>
        public static readonly StringSegment Empty = string.Empty;

        /// <summary>
        /// Initializes an instance of the <see cref="StringSegment"/> struct.
        /// </summary>
        /// <param name="buffer">
        /// The original <see cref="string"/>. The <see cref="StringSegment"/> includes the whole <see cref="string"/>.
        /// </param>
        public StringSegment(string? buffer)
        {
            Buffer = buffer;
            Offset = 0;
            Length = buffer?.Length ?? 0;
        }

        /// <summary>
        /// Initializes an instance of the <see cref="StringSegment"/> struct.
        /// </summary>
        /// <param name="buffer">The original <see cref="string"/> used as buffer.</param>
        /// <param name="offset">The offset of the segment within the <paramref name="buffer"/>.</param>
        /// <param name="length">The length of the segment.</param>
        /// <exception cref="ArgumentNullException">
        /// <paramref name="buffer"/> is <see langword="null" />.
        /// </exception>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="offset"/> or <paramref name="length"/> is less than zero, or <paramref name="offset"/> +
        /// <paramref name="length"/> is greater than the number of characters in <paramref name="buffer"/>.
        /// </exception>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public StringSegment(string buffer, int offset, int length)
        {
            // Validate arguments, check is minimal instructions with reduced branching for inlinable fast-path
            // Negative values discovered though conversion to high values when converted to unsigned
            // Failure should be rare and location determination and message is delegated to failure functions
            if (buffer == null || (uint)offset > (uint)buffer.Length || (uint)length > (uint)(buffer.Length - offset))
            {
                ThrowInvalidArguments(buffer, offset, length);
            }

            Buffer = buffer;
            Offset = offset;
            Length = length;
        }

        /// <summary>
        /// Gets the <see cref="string"/> buffer for this <see cref="StringSegment"/>.
        /// </summary>
        public string? Buffer { get; }

        /// <summary>
        /// Gets the offset within the buffer for this <see cref="StringSegment"/>.
        /// </summary>
        public int Offset { get; }

        /// <summary>
        /// Gets the length of this <see cref="StringSegment"/>.
        /// </summary>
        public int Length { get; }

        /// <summary>
        /// Gets the value of this segment as a <see cref="string"/>.
        /// </summary>
        public string? Value => HasValue ? Buffer.Substring(Offset, Length) : null;

        /// <summary>
        /// Gets whether this <see cref="StringSegment"/> contains a valid value.
        /// </summary>
        [MemberNotNullWhen(true, nameof(Buffer))]
        [MemberNotNullWhen(true, nameof(Value))]
        public bool HasValue => Buffer != null;

        /// <summary>
        /// Gets the <see cref="char"/> at a specified position in the current <see cref="StringSegment"/>.
        /// </summary>
        /// <param name="index">The offset into the <see cref="StringSegment"/></param>
        /// <returns>The <see cref="char"/> at a specified position.</returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="index"/> is greater than or equal to <see cref="Length"/> or less than zero.
        /// </exception>
        public char this[int index]
        {
            get
            {
                if ((uint)index >= (uint)Length)
                {
                    ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.index);
                }

                Debug.Assert(Buffer is not null);
                return Buffer[Offset + index];
            }
        }

        /// <summary>
        /// Gets a <see cref="ReadOnlySpan{T}"/> from the current <see cref="StringSegment"/>.
        /// </summary>
        /// <returns>The <see cref="ReadOnlySpan{T}"/> from this <see cref="StringSegment"/>.</returns>
        public ReadOnlySpan<char> AsSpan() => Buffer.AsSpan(Offset, Length);

        /// <summary>
        /// Gets a <see cref="ReadOnlySpan{T}"/> from the current <see cref="StringSegment"/> that starts
        /// at the position specified by <paramref name="start"/>, and has the remaining length.
        /// </summary>
        /// <param name="start">The zero-based starting character position in this <see cref="StringSegment"/>.</param>
        /// <returns>A <see cref="ReadOnlySpan{T}"/> with the remaining chars that begins at <paramref name="start"/> in
        /// this <see cref="StringSegment"/>.</returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="start"/> is greater than or equal to <see cref="Length"/> or less than zero.
        /// </exception>
        public ReadOnlySpan<char> AsSpan(int start)
        {
            if (!HasValue || start < 0)
            {
                ThrowInvalidArguments(start, Length - start, ExceptionArgument.start);
            }

            return Buffer.AsSpan(Offset + start, Length - start);
        }

        /// <summary>
        /// Gets a <see cref="ReadOnlySpan{T}"/> from the current <see cref="StringSegment"/> that starts
        /// at the position specified by <paramref name="start"/>, and has the specified <paramref name="length"/>.
        /// </summary>
        /// <param name="start">The zero-based starting character position in this <see cref="StringSegment"/>.</param>
        /// <param name="length">The number of characters in the span.</param>
        /// <returns>A <see cref="ReadOnlySpan{T}"/> with <paramref name="length"/> that begins at
        /// <paramref name="start"/> in this <see cref="StringSegment"/>.</returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="start"/> or <paramref name="length"/> is less than zero, or <paramref name="start"/> + <paramref name="length"/> is
        /// greater than <see cref="Length"/>.
        /// </exception>
        public ReadOnlySpan<char> AsSpan(int start, int length)
        {
            if (!HasValue || start < 0 || length < 0 || (uint)(start + length) > (uint)Length)
            {
                ThrowInvalidArguments(start, length, ExceptionArgument.start);
            }

            return Buffer.AsSpan(Offset + start, length);
        }

        /// <summary>
        /// Gets a <see cref="ReadOnlyMemory{T}"/> from the current <see cref="StringSegment"/>.
        /// </summary>
        /// <returns>The <see cref="ReadOnlyMemory{T}"/> from this <see cref="StringSegment"/>.</returns>
        public ReadOnlyMemory<char> AsMemory() => Buffer.AsMemory(Offset, Length);

        /// <summary>
        /// Compares substrings of two specified <see cref="StringSegment"/> objects using the specified rules,
        /// and returns an integer that indicates their relative position in the sort order.
        /// </summary>
        /// <param name="a">The first <see cref="StringSegment"/> to compare.</param>
        /// <param name="b">The second <see cref="StringSegment"/> to compare.</param>
        /// <param name="comparisonType">One of the enumeration values that specifies the rules for the comparison.</param>
        /// <returns>
        /// A 32-bit signed integer indicating the lexical relationship between the two comparands.
        /// The value is negative if <paramref name="a"/> is less than <paramref name="b"/>, 0 if the two comparands are equal,
        /// and positive if <paramref name="a"/> is greater than <paramref name="b"/>.
        /// </returns>
        public static int Compare(StringSegment a, StringSegment b, StringComparison comparisonType)
        {
            if (a.HasValue && b.HasValue)
            {
                return a.AsSpan().CompareTo(b.AsSpan(), comparisonType);
            }
            else
            {
                CheckStringComparison(comparisonType); // must arg check before returning
                return !a.HasValue ? (b.HasValue ? -1 : 0) : 1; // null sorts less than non-null, and two nulls sort as equal
            }
        }

        /// <summary>
        /// Indicates whether the current object is equal to another object of the same type.
        /// </summary>
        /// <param name="obj">An object to compare with this object.</param>
        /// <returns><see langword="true" /> if the current object is equal to the other parameter; otherwise, <see langword="false" />.</returns>
        public override bool Equals([NotNullWhen(true)] object? obj)
        {
            return obj is StringSegment segment && Equals(segment);
        }

        /// <summary>
        /// Indicates whether the current object is equal to another object of the same type.
        /// </summary>
        /// <param name="other">An object to compare with this object.</param>
        /// <returns><see langword="true" /> if the current object is equal to the other parameter; otherwise, <see langword="false" />.</returns>
        public bool Equals(StringSegment other) => Equals(other, StringComparison.Ordinal);

        /// <summary>
        /// Indicates whether the current object is equal to another object of the same type.
        /// </summary>
        /// <param name="other">An object to compare with this object.</param>
        /// <param name="comparisonType">One of the enumeration values that specifies the rules to use in the comparison.</param>
        /// <returns><see langword="true" /> if the current object is equal to the other parameter; otherwise, <see langword="false" />.</returns>
        public bool Equals(StringSegment other, StringComparison comparisonType)
        {
            if (HasValue && other.HasValue)
            {
                return AsSpan().Equals(other.AsSpan(), comparisonType);
            }
            else
            {
                CheckStringComparison(comparisonType); // must arg check before returning
                return !HasValue && !other.HasValue; // only return true if both are null
            }
        }

        // This handles StringSegment.Equals(string, StringSegment, StringComparison) and StringSegment.Equals(StringSegment, string, StringComparison)
        // via the implicit type converter
        /// <summary>
        /// Determines whether two specified <see cref="StringSegment"/> objects have the same value. A parameter specifies the culture, case, and
        /// sort rules used in the comparison.
        /// </summary>
        /// <param name="a">The first <see cref="StringSegment"/> to compare.</param>
        /// <param name="b">The second <see cref="StringSegment"/> to compare.</param>
        /// <param name="comparisonType">One of the enumeration values that specifies the rules for the comparison.</param>
        /// <returns><see langword="true" /> if the objects are equal; otherwise, <see langword="false" />.</returns>
        public static bool Equals(StringSegment a, StringSegment b, StringComparison comparisonType) => a.Equals(b, comparisonType);

        /// <summary>
        /// Checks if the specified <see cref="string"/> is equal to the current <see cref="StringSegment"/>.
        /// </summary>
        /// <param name="text">The <see cref="string"/> to compare with the current <see cref="StringSegment"/>.</param>
        /// <returns><see langword="true" /> if the specified <see cref="string"/> is equal to the current <see cref="StringSegment"/>; otherwise, <see langword="false" />.</returns>
        public bool Equals(string? text) => Equals(text, StringComparison.Ordinal);

        /// <summary>
        /// Checks if the specified <see cref="string"/> is equal to the current <see cref="StringSegment"/>.
        /// </summary>
        /// <param name="text">The <see cref="string"/> to compare with the current <see cref="StringSegment"/>.</param>
        /// <param name="comparisonType">One of the enumeration values that specifies the rules to use in the comparison.</param>
        /// <returns><see langword="true" /> if the specified <see cref="string"/> is equal to the current <see cref="StringSegment"/>; otherwise, <see langword="false" />.</returns>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public bool Equals(string? text, StringComparison comparisonType)
        {
            if (!HasValue || text == null)
            {
                CheckStringComparison(comparisonType); // must arg check before returning
                return text == Buffer; // only return true if both are null
            }

            return AsSpan().Equals(text.AsSpan(), comparisonType);
        }

        /// <summary>
        /// Returns a hash code for this instance.
        /// </summary>
        /// <returns>
        /// A hash code for this instance, suitable for use in hashing algorithms and data structures like a hash table.
        /// </returns>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public override int GetHashCode()
        {
#if NETCOREAPP
            return string.GetHashCode(AsSpan());
#elif (NETSTANDARD2_0 || NETFRAMEWORK)
            // This GetHashCode is expensive since it allocates on every call.
            // However this is required to ensure we retain any behavior (such as hash code randomization) that
            // string.GetHashCode has.
            return Value?.GetHashCode() ?? 0;
#else
#error Target frameworks need to be updated.
#endif
        }

        /// <summary>
        /// Checks if two specified <see cref="StringSegment"/> have the same value.
        /// </summary>
        /// <param name="left">The first <see cref="StringSegment"/> to compare, or <see langword="null" />.</param>
        /// <param name="right">The second <see cref="StringSegment"/> to compare, or <see langword="null" />.</param>
        /// <returns><see langword="true" /> if the value of <paramref name="left"/> is the same as the value of <paramref name="right"/>; otherwise, <see langword="false" />.</returns>
        public static bool operator ==(StringSegment left, StringSegment right) => left.Equals(right);

        /// <summary>
        /// Checks if two specified <see cref="StringSegment"/> have different values.
        /// </summary>
        /// <param name="left">The first <see cref="StringSegment"/> to compare, or <see langword="null" />.</param>
        /// <param name="right">The second <see cref="StringSegment"/> to compare, or <see langword="null" />.</param>
        /// <returns><see langword="true" /> if the value of <paramref name="left"/> is different from the value of <paramref name="right"/>; otherwise, <see langword="false" />.</returns>
        public static bool operator !=(StringSegment left, StringSegment right) => !left.Equals(right);

        // PERF: Do NOT add a implicit converter from StringSegment to String. That would negate most of the perf safety.
        /// <summary>
        /// Creates a new <see cref="StringSegment"/> from the given <see cref="string"/>.
        /// </summary>
        /// <param name="value">The <see cref="string"/> to convert to a <see cref="StringSegment"/></param>
        public static implicit operator StringSegment(string? value) => new StringSegment(value);

        /// <summary>
        /// Creates a see <see cref="ReadOnlySpan{T}"/> from the given <see cref="StringSegment"/>.
        /// </summary>
        /// <param name="segment">The <see cref="StringSegment"/> to convert to a <see cref="ReadOnlySpan{T}"/>.</param>
        public static implicit operator ReadOnlySpan<char>(StringSegment segment) => segment.AsSpan();

        /// <summary>
        /// Creates a see <see cref="ReadOnlyMemory{T}"/> from the given <see cref="StringSegment"/>.
        /// </summary>
        /// <param name="segment">The <see cref="StringSegment"/> to convert to a <see cref="ReadOnlyMemory{T}"/>.</param>
        public static implicit operator ReadOnlyMemory<char>(StringSegment segment) => segment.AsMemory();

        /// <summary>
        /// Checks if the beginning of this <see cref="StringSegment"/> matches the specified <see cref="string"/> when compared using the specified <paramref name="comparisonType"/>.
        /// </summary>
        /// <param name="text">The <see cref="string"/>to compare.</param>
        /// <param name="comparisonType">One of the enumeration values that specifies the rules to use in the comparison.</param>
        /// <returns><see langword="true" /> if <paramref name="text"/> matches the beginning of this <see cref="StringSegment"/>; otherwise, <see langword="false" />.</returns>
        /// <exception cref="ArgumentNullException">
        /// <paramref name="text"/> is <see langword="null" />.
        /// </exception>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public bool StartsWith(string text, StringComparison comparisonType)
        {
            if (text == null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.text);
            }

            if (!HasValue)
            {
                CheckStringComparison(comparisonType); // must arg check before returning
                return false;
            }

            return AsSpan().StartsWith(text.AsSpan(), comparisonType);
        }

        /// <summary>
        /// Checks if the end of this <see cref="StringSegment"/> matches the specified <see cref="string"/> when compared using the specified <paramref name="comparisonType"/>.
        /// </summary>
        /// <param name="text">The <see cref="string"/>to compare.</param>
        /// <param name="comparisonType">One of the enumeration values that specifies the rules to use in the comparison.</param>
        /// <returns><see langword="true" /> if <paramref name="text"/> matches the end of this <see cref="StringSegment"/>; otherwise, <see langword="false" />.</returns>
        /// <exception cref="ArgumentNullException">
        /// <paramref name="text"/> is <see langword="null" />.
        /// </exception>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public bool EndsWith(string text, StringComparison comparisonType)
        {
            if (text == null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.text);
            }

            if (!HasValue)
            {
                CheckStringComparison(comparisonType); // must arg check before returning
                return false;
            }

            return AsSpan().EndsWith(text.AsSpan(), comparisonType);
        }

        /// <summary>
        /// Retrieves a substring from this <see cref="StringSegment"/>.
        /// The substring starts at the position specified by <paramref name="offset"/> and has the remaining length.
        /// </summary>
        /// <param name="offset">The zero-based starting character position of a substring in this <see cref="StringSegment"/>.</param>
        /// <returns>A <see cref="string"/> that is equivalent to the substring of remaining length that begins at
        /// <paramref name="offset"/> in this <see cref="StringSegment"/></returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="offset"/> is greater than or equal to <see cref="Length"/> or less than zero.
        /// </exception>
        public string Substring(int offset) => Substring(offset, Length - offset);

        /// <summary>
        /// Retrieves a substring from this <see cref="StringSegment"/>.
        /// The substring starts at the position specified by <paramref name="offset"/> and has the specified <paramref name="length"/>.
        /// </summary>
        /// <param name="offset">The zero-based starting character position of a substring in this <see cref="StringSegment"/>.</param>
        /// <param name="length">The number of characters in the substring.</param>
        /// <returns>A <see cref="string"/> that is equivalent to the substring of <paramref name="length"/> that begins at
        /// <paramref name="offset"/> in this <see cref="StringSegment"/></returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="offset"/> or <paramref name="length"/> is less than zero, or <paramref name="offset"/> + <paramref name="length"/> is
        /// greater than <see cref="Length"/>.
        /// </exception>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public string Substring(int offset, int length)
        {
            if (!HasValue || offset < 0 || length < 0 || (uint)(offset + length) > (uint)Length)
            {
                ThrowInvalidArguments(offset, length, ExceptionArgument.offset);
            }

            return Buffer.Substring(Offset + offset, length);
        }

        /// <summary>
        /// Retrieves a <see cref="StringSegment"/> that represents a substring from this <see cref="StringSegment"/>.
        /// The <see cref="StringSegment"/> starts at the position specified by <paramref name="offset"/>.
        /// </summary>
        /// <param name="offset">The zero-based starting character position of a substring in this <see cref="StringSegment"/>.</param>
        /// <returns>A <see cref="StringSegment"/> that begins at <paramref name="offset"/> in this <see cref="StringSegment"/>
        /// whose length is the remainder.</returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="offset"/> is greater than or equal to <see cref="Length"/> or less than zero.
        /// </exception>
        public StringSegment Subsegment(int offset) => Subsegment(offset, Length - offset);

        /// <summary>
        /// Retrieves a <see cref="StringSegment"/> that represents a substring from this <see cref="StringSegment"/>.
        /// The <see cref="StringSegment"/> starts at the position specified by <paramref name="offset"/> and has the specified <paramref name="length"/>.
        /// </summary>
        /// <param name="offset">The zero-based starting character position of a substring in this <see cref="StringSegment"/>.</param>
        /// <param name="length">The number of characters in the substring.</param>
        /// <returns>A <see cref="StringSegment"/> that is equivalent to the substring of <paramref name="length"/> that begins at <paramref name="offset"/> in this <see cref="StringSegment"/></returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="offset"/> or <paramref name="length"/> is less than zero, or <paramref name="offset"/> + <paramref name="length"/> is
        /// greater than <see cref="Length"/>.
        /// </exception>
        public StringSegment Subsegment(int offset, int length)
        {
            if (!HasValue || offset < 0 || length < 0 || (uint)(offset + length) > (uint)Length)
            {
                ThrowInvalidArguments(offset, length, ExceptionArgument.offset);
            }

            return new StringSegment(Buffer, Offset + offset, length);
        }

        /// <summary>
        /// Gets the zero-based index of the first occurrence of the character <paramref name="c"/> in this <see cref="StringSegment"/>.
        /// The search starts at <paramref name="start"/> and examines a specified number of <paramref name="count"/> character positions.
        /// </summary>
        /// <param name="c">The Unicode character to seek.</param>
        /// <param name="start">The zero-based index position at which the search starts. </param>
        /// <param name="count">The number of characters to examine.</param>
        /// <returns>The zero-based index position of <paramref name="c"/> from the beginning of the <see cref="StringSegment"/> if that character is found, or -1 if it is not.</returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="start"/> or <paramref name="count"/> is less than zero, or <paramref name="start"/> + <paramref name="count"/> is
        /// greater than <see cref="Length"/>.
        /// </exception>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public int IndexOf(char c, int start, int count)
        {
            int index = -1;

            if (HasValue)
            {
                if ((uint)start > (uint)Length)
                {
                    ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.start);
                }

                if ((uint)count > (uint)(Length - start))
                {
                    ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.count);
                }

                index = AsSpan(start, count).IndexOf(c);
                if (index >= 0)
                {
                    index += start;
                }
            }

            return index;
        }

        /// <summary>
        /// Gets the zero-based index of the first occurrence of the character <paramref name="c"/> in this <see cref="StringSegment"/>.
        /// The search starts at <paramref name="start"/>.
        /// </summary>
        /// <param name="c">The Unicode character to seek.</param>
        /// <param name="start">The zero-based index position at which the search starts. </param>
        /// <returns>The zero-based index position of <paramref name="c"/> from the beginning of the <see cref="StringSegment"/> if that character is found, or -1 if it is not.</returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="start"/> is greater than or equal to <see cref="Length"/> or less than zero.
        /// </exception>
        public int IndexOf(char c, int start) => IndexOf(c, start, Length - start);

        /// <summary>
        /// Gets the zero-based index of the first occurrence of the character <paramref name="c"/> in this <see cref="StringSegment"/>.
        /// </summary>
        /// <param name="c">The Unicode character to seek.</param>
        /// <returns>The zero-based index position of <paramref name="c"/> from the beginning of the <see cref="StringSegment"/> if that character is found, or -1 if it is not.</returns>
        public int IndexOf(char c) => IndexOf(c, 0, Length);

        /// <summary>
        /// Reports the zero-based index of the first occurrence in this instance of any character in a specified array
        /// of Unicode characters. The search starts at a specified character position and examines a specified number
        /// of character positions.
        /// </summary>
        /// <param name="anyOf">A Unicode character array containing one or more characters to seek.</param>
        /// <param name="startIndex">The search starting position.</param>
        /// <param name="count">The number of character positions to examine.</param>
        /// <returns>The zero-based index position of the first occurrence in this instance where any character in <paramref name="anyOf"/>
        /// was found; -1 if no character in <paramref name="anyOf"/> was found.</returns>
        /// <exception cref="ArgumentNullException">
        /// <paramref name="anyOf"/> is <see langword="null" />.
        /// </exception>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="startIndex"/> or <paramref name="count"/> is less than zero, or <paramref name="startIndex"/> + <paramref name="count"/> is
        /// greater than <see cref="Length"/>.
        /// </exception>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public int IndexOfAny(char[] anyOf, int startIndex, int count)
        {
            int index = -1;

            if (HasValue)
            {
                if ((uint)startIndex > (uint)Length)
                {
                    ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.start);
                }

                if ((uint)count > (uint)(Length - startIndex))
                {
                    ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.count);
                }

                index = Buffer.IndexOfAny(anyOf, Offset + startIndex, count);
                if (index != -1)
                {
                    index -= Offset;
                }
            }

            return index;
        }

        /// <summary>
        /// Reports the zero-based index of the first occurrence in this instance of any character in a specified array
        /// of Unicode characters. The search starts at a specified character position.
        /// </summary>
        /// <param name="anyOf">A Unicode character array containing one or more characters to seek.</param>
        /// <param name="startIndex">The search starting position.</param>
        /// <returns>The zero-based index position of the first occurrence in this instance where any character in <paramref name="anyOf"/>
        /// was found; -1 if no character in <paramref name="anyOf"/> was found.</returns>
        /// <exception cref="ArgumentOutOfRangeException">
        /// <paramref name="startIndex"/> is greater than or equal to <see cref="Length"/> or less than zero.
        /// </exception>
        public int IndexOfAny(char[] anyOf, int startIndex)
        {
            return IndexOfAny(anyOf, startIndex, Length - startIndex);
        }

        /// <summary>
        /// Reports the zero-based index of the first occurrence in this instance of any character in a specified array
        /// of Unicode characters.
        /// </summary>
        /// <param name="anyOf">A Unicode character array containing one or more characters to seek.</param>
        /// <returns>The zero-based index position of the first occurrence in this instance where any character in <paramref name="anyOf"/>
        /// was found; -1 if no character in <paramref name="anyOf"/> was found.</returns>
        public int IndexOfAny(char[] anyOf)
        {
            return IndexOfAny(anyOf, 0, Length);
        }

        /// <summary>
        /// Reports the zero-based index position of the last occurrence of a specified Unicode character within this instance.
        /// </summary>
        /// <param name="value">The Unicode character to seek.</param>
        /// <returns>The zero-based index position of value if that character is found, or -1 if it is not.</returns>
        public int LastIndexOf(char value)
        {
            return AsSpan().LastIndexOf(value);
        }

        /// <summary>
        /// Removes all leading and trailing whitespaces.
        /// </summary>
        /// <returns>The trimmed <see cref="StringSegment"/>.</returns>
        public StringSegment Trim() => TrimStart().TrimEnd();

        /// <summary>
        /// Removes all leading whitespaces.
        /// </summary>
        /// <returns>The trimmed <see cref="StringSegment"/>.</returns>
        public StringSegment TrimStart()
        {
            ReadOnlySpan<char> span = AsSpan();

            int i;
            for (i = 0; i < span.Length; i++)
            {
                if (!char.IsWhiteSpace(span[i]))
                {
                    break;
                }
            }

            return Subsegment(i);
        }

        /// <summary>
        /// Removes all trailing whitespaces.
        /// </summary>
        /// <returns>The trimmed <see cref="StringSegment"/>.</returns>
        public StringSegment TrimEnd()
        {
            ReadOnlySpan<char> span = AsSpan();

            int i;
            for (i = span.Length - 1; i >= 0; i--)
            {
                if (!char.IsWhiteSpace(span[i]))
                {
                    break;
                }
            }

            return Subsegment(0, i + 1);
        }

        /// <summary>
        /// Splits a string into <see cref="StringSegment"/>s that are based on the characters in an array.
        /// </summary>
        /// <param name="chars">A character array that delimits the substrings in this string, an empty array that
        /// contains no delimiters, or null.</param>
        /// <returns>An <see cref="StringTokenizer"/> whose elements contain the <see cref="StringSegment"/>s from this instance
        /// that are delimited by one or more characters in <paramref name="chars"/>.</returns>
        public StringTokenizer Split(char[] chars)
        {
            return new StringTokenizer(this, chars);
        }

        /// <summary>
        /// Indicates whether the specified <see cref="StringSegment"/> is null or an Empty string.
        /// </summary>
        /// <param name="value">The <see cref="StringSegment"/> to test.</param>
        /// <returns></returns>
        public static bool IsNullOrEmpty(StringSegment value)
        {
            bool res = false;

            if (!value.HasValue || value.Length == 0)
            {
                res = true;
            }

            return res;
        }

        /// <summary>
        /// Returns the <see cref="string"/> represented by this <see cref="StringSegment"/> or <see cref="string.Empty" /> if the <see cref="StringSegment"/> does not contain a value.
        /// </summary>
        /// <returns>The <see cref="string"/> represented by this <see cref="StringSegment"/> or <see cref="string.Empty" /> if the <see cref="StringSegment"/> does not contain a value.</returns>
        public override string ToString()
        {
            return Value ?? string.Empty;
        }

        private static void CheckStringComparison(StringComparison comparisonType)
        {
            // Single comparison to check if comparisonType is within [CurrentCulture .. OrdinalIgnoreCase]
            if ((uint)comparisonType > (uint)StringComparison.OrdinalIgnoreCase)
            {
                ThrowHelper.ThrowArgumentOutOfRangeException(ExceptionArgument.comparisonType);
            }
        }

        // Methods that do no return (i.e. throw) are not inlined
        // https://github.com/dotnet/coreclr/pull/6103
        [DoesNotReturn]
        private static void ThrowInvalidArguments(string? buffer, int offset, int length)
        {
            // Only have single throw in method so is marked as "does not return" and isn't inlined to caller
            throw GetInvalidArgumentsException();

            Exception GetInvalidArgumentsException()
            {
                if (buffer == null)
                {
                    return ThrowHelper.GetArgumentNullException(ExceptionArgument.buffer);
                }

                if (offset < 0)
                {
                    return ThrowHelper.GetArgumentOutOfRangeException(ExceptionArgument.offset);
                }

                if (length < 0)
                {
                    return ThrowHelper.GetArgumentOutOfRangeException(ExceptionArgument.length);
                }

                return ThrowHelper.GetArgumentException(ExceptionResource.Argument_InvalidOffsetLength);
            }
        }

        [DoesNotReturn]
        private void ThrowInvalidArguments(int offset, int length, ExceptionArgument offsetOrStart)
        {
            throw GetInvalidArgumentsException(HasValue);

            Exception GetInvalidArgumentsException(bool hasValue)
            {
                if (!hasValue)
                {
                    return ThrowHelper.GetArgumentOutOfRangeException(offsetOrStart);
                }

                if (offset < 0)
                {
                    return ThrowHelper.GetArgumentOutOfRangeException(offsetOrStart);
                }

                if (length < 0)
                {
                    return ThrowHelper.GetArgumentOutOfRangeException(ExceptionArgument.length);
                }

                return ThrowHelper.GetArgumentException(ExceptionResource.Argument_InvalidOffsetLengthStringSegment);
            }
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// Compares two <see cref="StringSegment"/> objects.
    /// </summary>
    public class StringSegmentComparer : IComparer<StringSegment>, IEqualityComparer<StringSegment>
    {
        /// <summary>
        /// Gets a <see cref="StringSegmentComparer"/> object that performs a case-sensitive ordinal <see cref="StringSegment"/> comparison.
        /// </summary>
        public static StringSegmentComparer Ordinal { get; }
            = new StringSegmentComparer(StringComparison.Ordinal, StringComparer.Ordinal);

        /// <summary>
        /// Gets a <see cref="StringSegmentComparer"/> object that performs a case-insensitive ordinal <see cref="StringSegment"/> comparison.
        /// </summary>
        public static StringSegmentComparer OrdinalIgnoreCase { get; }
            = new StringSegmentComparer(StringComparison.OrdinalIgnoreCase, StringComparer.OrdinalIgnoreCase);

        private StringSegmentComparer(StringComparison comparison, StringComparer comparer)
        {
            Comparison = comparison;
            Comparer = comparer;
        }

        private StringComparison Comparison { get; }
        private StringComparer Comparer { get; }

        /// <summary>
        /// Compares two <see cref="StringSegment"/> objects and returns an indication of their relative sort order.
        /// </summary>
        /// <param name="x">The first <see cref="StringSegment"/> to compare.</param>
        /// <param name="y">The second <see cref="StringSegment"/> to compare.</param>
        /// <returns>A 32-bit signed integer that indicates the lexical relationship between the two comparands.</returns>
        public int Compare(StringSegment x, StringSegment y)
        {
            return StringSegment.Compare(x, y, Comparison);
        }

        /// <summary>
        /// Determines whether two <see cref="StringSegment"/> objects are equal.
        /// </summary>
        /// <param name="x">The first <see cref="StringSegment"/> to compare.</param>
        /// <param name="y">The second <see cref="StringSegment"/> to compare.</param>
        /// <returns><see langword="true"/> if the two <see cref="StringSegment"/> objects are equal; otherwise, <see langword="false"/>.</returns>
        public bool Equals(StringSegment x, StringSegment y)
        {
            return StringSegment.Equals(x, y, Comparison);
        }

        /// <summary>
        /// Returns a hash code for a <see cref="StringSegment"/> object.
        /// </summary>
        /// <param name="obj">The <see cref="StringSegment"/> to get a hash code for.</param>
        /// <returns>A hash code for a <see cref="StringSegment"/>, suitable for use in hashing algorithms and data structures like a hash table.</returns>
        public int GetHashCode(StringSegment obj)
        {
#if NETCOREAPP || NETSTANDARD2_1
            return string.GetHashCode(obj.AsSpan(), Comparison);
#else
            if (!obj.HasValue)
            {
                return 0;
            }

            // .NET Core strings use randomized hash codes for security reasons. Consequently we must materialize the StringSegment as a string
            return Comparer.GetHashCode(obj.Value);
#endif
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// Tokenizes a <see cref="string"/> into <see cref="StringSegment"/>s.
    /// </summary>
    public readonly struct StringTokenizer : IEnumerable<StringSegment>
    {
        private readonly StringSegment _value;
        private readonly char[] _separators;

        /// <summary>
        /// Initializes a new instance of <see cref="StringTokenizer"/>.
        /// </summary>
        /// <param name="value">The <see cref="string"/> to tokenize.</param>
        /// <param name="separators">The characters to tokenize by.</param>
        public StringTokenizer(string value, char[] separators)
        {
            if (value == null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.value);
            }

            if (separators == null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.separators);
            }

            _value = value;
            _separators = separators;
        }

        /// <summary>
        /// Initializes a new instance of <see cref="StringTokenizer"/>.
        /// </summary>
        /// <param name="value">The <see cref="StringSegment"/> to tokenize.</param>
        /// <param name="separators">The characters to tokenize by.</param>
        public StringTokenizer(StringSegment value, char[] separators)
        {
            if (!value.HasValue)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.value);
            }

            if (separators == null)
            {
                ThrowHelper.ThrowArgumentNullException(ExceptionArgument.separators);
            }

            _value = value;
            _separators = separators;
        }

        /// <summary>
        /// Initializes a new instance of <see cref="Enumerator"/>.
        /// </summary>
        /// <returns>An <see cref="Enumerator"/> based on the <see cref="StringTokenizer"/>'s value and separators.</returns>
        public Enumerator GetEnumerator() => new Enumerator(in _value, _separators);

        IEnumerator<StringSegment> IEnumerable<StringSegment>.GetEnumerator() => GetEnumerator();

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

        /// <summary>
        /// Enumerates the <see cref="string"/> tokens represented by <see cref="StringSegment"/>.
        /// </summary>
        public struct Enumerator : IEnumerator<StringSegment>
        {
            private readonly StringSegment _value;
            private readonly char[] _separators;
            private int _index;

            internal Enumerator(in StringSegment value, char[] separators)
            {
                _value = value;
                _separators = separators;
                Current = default;
                _index = 0;
            }

            /// <summary>
            /// Initializes an <see cref="Enumerator"/> using a <see cref="StringTokenizer"/>.
            /// </summary>
            /// <param name="tokenizer"><see cref="StringTokenizer"/> containing value and separators for enumeration.</param>
            public Enumerator(ref StringTokenizer tokenizer)
            {
                _value = tokenizer._value;
                _separators = tokenizer._separators;
                Current = default(StringSegment);
                _index = 0;
            }

            /// <summary>
            /// Gets the current <see cref="StringSegment"/> from the <see cref="StringTokenizer"/>.
            /// </summary>
            public StringSegment Current { get; private set; }

            object IEnumerator.Current => Current;

            /// <summary>
            /// Releases all resources used by the <see cref="Enumerator"/>.
            /// </summary>
            public void Dispose()
            {
            }

            /// <summary>
            /// Advances the enumerator to the next token in the <see cref="StringTokenizer"/>.
            /// </summary>
            /// <returns><see langword="true"/> if the enumerator was successfully advanced to the next token; <see langword="false"/> if the enumerator has passed the end of the <see cref="StringTokenizer"/>.</returns>
            public bool MoveNext()
            {
                if (!_value.HasValue || _index > _value.Length)
                {
                    Current = default(StringSegment);
                    return false;
                }

                int next = _value.IndexOfAny(_separators, _index);
                if (next == -1)
                {
                    // No separator found. Consume the remainder of the string.
                    next = _value.Length;
                }

                Current = _value.Subsegment(_index, next - _index);
                _index = next + 1;

                return true;
            }

            /// <summary>
            /// Resets the <see cref="Enumerator"/> to its initial state.
            /// </summary>
            public void Reset()
            {
                Current = default(StringSegment);
                _index = 0;
            }
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    /// <summary>
    /// Represents zero/null, one, or many strings in an efficient way.
    /// </summary>
    [DebuggerDisplay("{ToString()}")]
    [DebuggerTypeProxy(typeof(StringValuesDebugView))]
    public readonly struct StringValues : IList<string?>, IReadOnlyList<string?>, IEquatable<StringValues>, IEquatable<string?>, IEquatable<string?[]?>
    {
        /// <summary>
        /// A readonly instance of the <see cref="StringValues"/> struct whose value is an empty string array.
        /// </summary>
        /// <remarks>
        /// In application code, this field is most commonly used to safely represent a <see cref="StringValues"/> that has null string values.
        /// </remarks>
        public static readonly StringValues Empty = new StringValues(Array.Empty<string>());

        private readonly object? _values;

        /// <summary>
        /// Initializes a new instance of the <see cref="StringValues"/> structure using the specified string.
        /// </summary>
        /// <param name="value">A string value or <c>null</c>.</param>
        public StringValues(string? value)
        {
            _values = value;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="StringValues"/> structure using the specified array of strings.
        /// </summary>
        /// <param name="values">A string array.</param>
        public StringValues(string?[]? values)
        {
            _values = values;
        }

        /// <summary>
        /// Defines an implicit conversion of a given string to a <see cref="StringValues"/>.
        /// </summary>
        /// <param name="value">A string to implicitly convert.</param>
        public static implicit operator StringValues(string? value)
        {
            return new StringValues(value);
        }

        /// <summary>
        /// Defines an implicit conversion of a given string array to a <see cref="StringValues"/>.
        /// </summary>
        /// <param name="values">A string array to implicitly convert.</param>
        public static implicit operator StringValues(string?[]? values)
        {
            return new StringValues(values);
        }

        /// <summary>
        /// Defines an implicit conversion of a given <see cref="StringValues"/> to a string, with multiple values joined as a comma separated string.
        /// </summary>
        /// <remarks>
        /// Returns <c>null</c> where <see cref="StringValues"/> has been initialized from an empty string array or is <see cref="StringValues.Empty"/>.
        /// </remarks>
        /// <param name="values">A <see cref="StringValues"/> to implicitly convert.</param>
        public static implicit operator string? (StringValues values)
        {
            return values.GetStringValue();
        }

        /// <summary>
        /// Defines an implicit conversion of a given <see cref="StringValues"/> to a string array.
        /// </summary>
        /// <param name="value">A <see cref="StringValues"/> to implicitly convert.</param>
        public static implicit operator string?[]? (StringValues value)
        {
            return value.GetArrayValue();
        }

        /// <summary>
        /// Gets the number of <see cref="string"/> elements contained in this <see cref="StringValues" />.
        /// </summary>
        public int Count
        {
            [MethodImpl(MethodImplOptions.AggressiveInlining)]
            get
            {
                // Take local copy of _values so type checks remain valid even if the StringValues is overwritten in memory
                object? value = _values;
                if (value is null)
                {
                    return 0;
                }
                if (value is string)
                {
                    return 1;
                }
                else
                {
                    // Not string, not null, can only be string[]
                    return Unsafe.As<string?[]>(value).Length;
                }
            }
        }

        bool ICollection<string?>.IsReadOnly => true;

        /// <summary>
        /// Gets the <see cref="string"/> at index.
        /// </summary>
        /// <value>The string at the specified index.</value>
        /// <param name="index">The zero-based index of the element to get.</param>
        /// <exception cref="NotSupportedException">Set operations are not supported on readonly <see cref="StringValues"/>.</exception>
        string? IList<string?>.this[int index]
        {
            get => this[index];
            set => throw new NotSupportedException();
        }

        /// <summary>
        /// Gets the <see cref="string"/> at index.
        /// </summary>
        /// <value>The string at the specified index.</value>
        /// <param name="index">The zero-based index of the element to get.</param>
        public string? this[int index]
        {
            [MethodImpl(MethodImplOptions.AggressiveInlining)]
            get
            {
                // Take local copy of _values so type checks remain valid even if the StringValues is overwritten in memory
                object? value = _values;
                if (value is string str)
                {
                    if (index == 0)
                    {
                        return str;
                    }
                }
                else if (value != null)
                {
                    // Not string, not null, can only be string[]
                    return Unsafe.As<string?[]>(value)[index]; // may throw
                }

                return OutOfBounds(); // throws
            }
        }

        [MethodImpl(MethodImplOptions.NoInlining)]
        private static string OutOfBounds()
        {
            return Array.Empty<string>()[0]; // throws
        }

        /// <summary>
        /// Converts the value of the current <see cref="StringValues"/> object to its equivalent string representation, with multiple values joined as a comma separated string.
        /// </summary>
        /// <returns>A string representation of the value of the current <see cref="StringValues"/> object.</returns>
        public override string ToString()
        {
            return GetStringValue() ?? string.Empty;
        }

        private string? GetStringValue()
        {
            // Take local copy of _values so type checks remain valid even if the StringValues is overwritten in memory
            object? value = _values;
            if (value is string s)
            {
                return s;
            }
            else
            {
                return GetStringValueFromArray(value);
            }

            static string? GetStringValueFromArray(object? value)
            {
                if (value is null)
                {
                    return null;
                }

                Debug.Assert(value is string[]);
                // value is not null or string, array, can only be string[]
                string?[] values = Unsafe.As<string?[]>(value);
                return values.Length switch
                {
                    0 => null,
                    1 => values[0],
                    _ => GetJoinedStringValueFromArray(values),
                };
            }

            static string GetJoinedStringValueFromArray(string?[] values)
            {
                // Calculate final length
                int length = 0;
                for (int i = 0; i < values.Length; i++)
                {
                    string? value = values[i];
                    // Skip null and empty values
                    if (value != null && value.Length > 0)
                    {
                        if (length > 0)
                        {
                            // Add separator
                            length++;
                        }

                        length += value.Length;
                    }
                }
#if NETCOREAPP
                // Create the new string
                return string.Create(length, values, (span, strings) => {
                    int offset = 0;
                    // Skip null and empty values
                    for (int i = 0; i < strings.Length; i++)
                    {
                        string? value = strings[i];
                        if (value != null && value.Length > 0)
                        {
                            if (offset > 0)
                            {
                                // Add separator
                                span[offset] = ',';
                                offset++;
                            }

                            value.AsSpan().CopyTo(span.Slice(offset));
                            offset += value.Length;
                        }
                    }
                });
#else
                var sb = new ValueStringBuilder(length);
                bool hasAdded = false;
                // Skip null and empty values
                for (int i = 0; i < values.Length; i++)
                {
                    string? value = values[i];
                    if (value != null && value.Length > 0)
                    {
                        if (hasAdded)
                        {
                            // Add separator
                            sb.Append(',');
                        }

                        sb.Append(value);
                        hasAdded = true;
                    }
                }

                return sb.ToString();
#endif
            }
        }

        /// <summary>
        /// Creates a string array from the current <see cref="StringValues"/> object.
        /// </summary>
        /// <returns>A string array represented by this instance.</returns>
        /// <remarks>
        /// <para>If the <see cref="StringValues"/> contains a single string internally, it is copied to a new array.</para>
        /// <para>If the <see cref="StringValues"/> contains an array internally it returns that array instance.</para>
        /// </remarks>
        public string?[] ToArray()
        {
            return GetArrayValue() ?? Array.Empty<string>();
        }

        private string?[]? GetArrayValue()
        {
            // Take local copy of _values so type checks remain valid even if the StringValues is overwritten in memory
            object? value = _values;
            if (value is string[] values)
            {
                return values;
            }
            else if (value != null)
            {
                // value not array, can only be string
                return new[] { Unsafe.As<string>(value) };
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// Returns the zero-based index of the first occurrence of an item in the <see cref="StringValues" />.
        /// </summary>
        /// <param name="item">The string to locate in the <see cref="StringValues"></see>.</param>
        /// <returns>the zero-based index of the first occurrence of <paramref name="item" /> within the <see cref="StringValues"></see>, if found; otherwise, -1.</returns>
        int IList<string?>.IndexOf(string? item)
        {
            return IndexOf(item);
        }

        private int IndexOf(string? item)
        {
            // Take local copy of _values so type checks remain valid even if the StringValues is overwritten in memory
            object? value = _values;
            if (value is string[] values)
            {
                for (int i = 0; i < values.Length; i++)
                {
                    if (string.Equals(values[i], item, StringComparison.Ordinal))
                    {
                        return i;
                    }
                }
                return -1;
            }

            if (value != null)
            {
                // value not array, can only be string
                return string.Equals(Unsafe.As<string>(value), item, StringComparison.Ordinal) ? 0 : -1;
            }

            return -1;
        }

        /// <summary>Determines whether a string is in the <see cref="StringValues" />.</summary>
        /// <param name="item">The <see cref="string"/> to locate in the <see cref="StringValues" />.</param>
        /// <returns>true if <paramref name="item">item</paramref> is found in the <see cref="StringValues" />; otherwise, false.</returns>
        bool ICollection<string?>.Contains(string? item)
        {
            return IndexOf(item) >= 0;
        }

        /// <summary>
        /// Copies the entire <see cref="StringValues" />to a string array, starting at the specified index of the target array.
        /// </summary>
        /// <param name="array">The one-dimensional <see cref="Array" /> that is the destination of the elements copied from. The <see cref="Array" /> must have zero-based indexing.</param>
        /// <param name="arrayIndex">The zero-based index in the destination array at which copying begins.</param>
        /// <exception cref="ArgumentNullException"><paramref name="array">array</paramref> is null.</exception>
        /// <exception cref="ArgumentOutOfRangeException"><paramref name="arrayIndex">arrayIndex</paramref> is less than 0.</exception>
        /// <exception cref="ArgumentException">The number of elements in the source <see cref="StringValues"></see> is greater than the available space from <paramref name="arrayIndex">arrayIndex</paramref> to the end of the destination <paramref name="array">array</paramref>.</exception>
        void ICollection<string?>.CopyTo(string?[] array, int arrayIndex)
        {
            CopyTo(array, arrayIndex);
        }

        private void CopyTo(string?[] array, int arrayIndex)
        {
            // Take local copy of _values so type checks remain valid even if the StringValues is overwritten in memory
            object? value = _values;
            if (value is string[] values)
            {
                Array.Copy(values, 0, array, arrayIndex, values.Length);
                return;
            }

            if (value != null)
            {
                if (array == null)
                {
                    ThrowHelper.ThrowArgumentNullException(ExceptionArgument.array);
                }
                if (arrayIndex < 0)
                {
                    throw new ArgumentOutOfRangeException(nameof(arrayIndex));
                }
                if (array.Length - arrayIndex < 1)
                {
                    throw new ArgumentException(
                        $"'{nameof(array)}' is not long enough to copy all the items in the collection. Check '{nameof(arrayIndex)}' and '{nameof(array)}' length.");
                }

                // value not array, can only be string
                array[arrayIndex] = Unsafe.As<string>(value);
            }
        }

        void ICollection<string?>.Add(string? item) => throw new NotSupportedException();

        void IList<string?>.Insert(int index, string? item) => throw new NotSupportedException();

        bool ICollection<string?>.Remove(string? item) => throw new NotSupportedException();

        void IList<string?>.RemoveAt(int index) => throw new NotSupportedException();

        void ICollection<string?>.Clear() => throw new NotSupportedException();

        /// <summary>Retrieves an object that can iterate through the individual strings in this <see cref="StringValues" />.</summary>
        /// <returns>An enumerator that can be used to iterate through the <see cref="StringValues" />.</returns>
        public Enumerator GetEnumerator()
        {
            return new Enumerator(_values);
        }

        /// <inheritdoc cref="GetEnumerator()" />
        IEnumerator<string?> IEnumerable<string?>.GetEnumerator()
        {
            return GetEnumerator();
        }

        /// <inheritdoc cref="GetEnumerator()" />
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        /// <summary>
        /// Indicates whether the specified <see cref="StringValues"/> contains no string values.
        /// </summary>
        /// <param name="value">The <see cref="StringValues"/> to test.</param>
        /// <returns>true if <paramref name="value">value</paramref> contains a single null or empty string or an empty array; otherwise, false.</returns>
        public static bool IsNullOrEmpty(StringValues value)
        {
            object? data = value._values;
            if (data is null)
            {
                return true;
            }
            if (data is string[] values)
            {
                return values.Length switch
                {
                    0 => true,
                    1 => string.IsNullOrEmpty(values[0]),
                    _ => false,
                };
            }
            else
            {
                // Not array, can only be string
                return string.IsNullOrEmpty(Unsafe.As<string>(data));
            }
        }

        /// <summary>
        /// Concatenates two specified instances of <see cref="StringValues"/>.
        /// </summary>
        /// <param name="values1">The first <see cref="StringValues"/> to concatenate.</param>
        /// <param name="values2">The second <see cref="StringValues"/> to concatenate.</param>
        /// <returns>The concatenation of <paramref name="values1"/> and <paramref name="values2"/>.</returns>
        public static StringValues Concat(StringValues values1, StringValues values2)
        {
            int count1 = values1.Count;
            int count2 = values2.Count;

            if (count1 == 0)
            {
                return values2;
            }

            if (count2 == 0)
            {
                return values1;
            }

            var combined = new string[count1 + count2];
            values1.CopyTo(combined, 0);
            values2.CopyTo(combined, count1);
            return new StringValues(combined);
        }

        /// <summary>
        /// Concatenates specified instance of <see cref="StringValues"/> with specified <see cref="string"/>.
        /// </summary>
        /// <param name="values">The <see cref="StringValues"/> to concatenate.</param>
        /// <param name="value">The <see cref="string" /> to concatenate.</param>
        /// <returns>The concatenation of <paramref name="values"/> and <paramref name="value"/>.</returns>
        public static StringValues Concat(in StringValues values, string? value)
        {
            if (value == null)
            {
                return values;
            }

            int count = values.Count;
            if (count == 0)
            {
                return new StringValues(value);
            }

            var combined = new string[count + 1];
            values.CopyTo(combined, 0);
            combined[count] = value;
            return new StringValues(combined);
        }

        /// <summary>
        /// Concatenates specified instance of <see cref="string"/> with specified <see cref="StringValues"/>.
        /// </summary>
        /// <param name="value">The <see cref="string" /> to concatenate.</param>
        /// <param name="values">The <see cref="StringValues"/> to concatenate.</param>
        /// <returns>The concatenation of <paramref name="values"/> and <paramref name="values"/>.</returns>
        public static StringValues Concat(string? value, in StringValues values)
        {
            if (value == null)
            {
                return values;
            }

            int count = values.Count;
            if (count == 0)
            {
                return new StringValues(value);
            }

            var combined = new string[count + 1];
            combined[0] = value;
            values.CopyTo(combined, 1);
            return new StringValues(combined);
        }

        /// <summary>
        /// Determines whether two specified <see cref="StringValues"/> objects have the same values in the same order.
        /// </summary>
        /// <param name="left">The first <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The second <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is the same as the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool Equals(StringValues left, StringValues right)
        {
            int count = left.Count;

            if (count != right.Count)
            {
                return false;
            }

            for (int i = 0; i < count; i++)
            {
                if (left[i] != right[i])
                {
                    return false;
                }
            }

            return true;
        }

        /// <summary>
        /// Determines whether two specified <see cref="StringValues"/> have the same values.
        /// </summary>
        /// <param name="left">The first <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The second <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is the same as the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator ==(StringValues left, StringValues right)
        {
            return Equals(left, right);
        }

        /// <summary>
        /// Determines whether two specified <see cref="StringValues"/> have different values.
        /// </summary>
        /// <param name="left">The first <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The second <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is different to the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator !=(StringValues left, StringValues right)
        {
            return !Equals(left, right);
        }

        /// <summary>
        /// Determines whether this instance and another specified <see cref="StringValues"/> object have the same values.
        /// </summary>
        /// <param name="other">The string to compare to this instance.</param>
        /// <returns><c>true</c> if the value of <paramref name="other"/> is the same as the value of this instance; otherwise, <c>false</c>.</returns>
        public bool Equals(StringValues other) => Equals(this, other);

        /// <summary>
        /// Determines whether the specified <see cref="string"/> and <see cref="StringValues"/> objects have the same values.
        /// </summary>
        /// <param name="left">The <see cref="string"/> to compare.</param>
        /// <param name="right">The <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is the same as the value of <paramref name="right"/>; otherwise, <c>false</c>. If <paramref name="left"/> is <c>null</c>, the method returns <c>false</c>.</returns>
        public static bool Equals(string? left, StringValues right) => Equals(new StringValues(left), right);

        /// <summary>
        /// Determines whether the specified <see cref="StringValues"/> and <see cref="string"/> objects have the same values.
        /// </summary>
        /// <param name="left">The <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The <see cref="string"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is the same as the value of <paramref name="right"/>; otherwise, <c>false</c>. If <paramref name="right"/> is <c>null</c>, the method returns <c>false</c>.</returns>
        public static bool Equals(StringValues left, string? right) => Equals(left, new StringValues(right));

        /// <summary>
        /// Determines whether this instance and a specified <see cref="string"/>, have the same value.
        /// </summary>
        /// <param name="other">The <see cref="string"/> to compare to this instance.</param>
        /// <returns><c>true</c> if the value of <paramref name="other"/> is the same as this instance; otherwise, <c>false</c>. If <paramref name="other"/> is <c>null</c>, returns <c>false</c>.</returns>
        public bool Equals(string? other) => Equals(this, new StringValues(other));

        /// <summary>
        /// Determines whether the specified string array and <see cref="StringValues"/> objects have the same values.
        /// </summary>
        /// <param name="left">The string array to compare.</param>
        /// <param name="right">The <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is the same as the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool Equals(string?[]? left, StringValues right) => Equals(new StringValues(left), right);

        /// <summary>
        /// Determines whether the specified <see cref="StringValues"/> and string array objects have the same values.
        /// </summary>
        /// <param name="left">The <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The string array to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is the same as the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool Equals(StringValues left, string?[]? right) => Equals(left, new StringValues(right));

        /// <summary>
        /// Determines whether this instance and a specified string array have the same values.
        /// </summary>
        /// <param name="other">The string array to compare to this instance.</param>
        /// <returns><c>true</c> if the value of <paramref name="other"/> is the same as this instance; otherwise, <c>false</c>.</returns>
        public bool Equals(string?[]? other) => Equals(this, new StringValues(other));

        /// <inheritdoc cref="Equals(StringValues, string)" />
        public static bool operator ==(StringValues left, string? right) => Equals(left, new StringValues(right));

        /// <summary>
        /// Determines whether the specified <see cref="StringValues"/> and <see cref="string"/> objects have different values.
        /// </summary>
        /// <param name="left">The <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The <see cref="string"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is different to the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator !=(StringValues left, string? right) => !Equals(left, new StringValues(right));

        /// <inheritdoc cref="Equals(string, StringValues)" />
        public static bool operator ==(string? left, StringValues right) => Equals(new StringValues(left), right);

        /// <summary>
        /// Determines whether the specified <see cref="string"/> and <see cref="StringValues"/> objects have different values.
        /// </summary>
        /// <param name="left">The <see cref="string"/> to compare.</param>
        /// <param name="right">The <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is different to the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator !=(string? left, StringValues right) => !Equals(new StringValues(left), right);

        /// <inheritdoc cref="Equals(StringValues, string[])" />
        public static bool operator ==(StringValues left, string?[]? right) => Equals(left, new StringValues(right));

        /// <summary>
        /// Determines whether the specified <see cref="StringValues"/> and string array have different values.
        /// </summary>
        /// <param name="left">The <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The string array to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is different to the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator !=(StringValues left, string?[]? right) => !Equals(left, new StringValues(right));

        /// <inheritdoc cref="Equals(string[], StringValues)" />
        public static bool operator ==(string?[]? left, StringValues right) => Equals(new StringValues(left), right);

        /// <summary>
        /// Determines whether the specified string array and <see cref="StringValues"/> have different values.
        /// </summary>
        /// <param name="left">The string array to compare.</param>
        /// <param name="right">The <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the value of <paramref name="left"/> is different to the value of <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator !=(string?[]? left, StringValues right) => !Equals(new StringValues(left), right);

        /// <summary>
        /// Determines whether the specified <see cref="StringValues"/> and <see cref="object"/>, which must be a
        /// <see cref="StringValues"/>, <see cref="string"/>, or array of <see cref="string"/>, have the same value.
        /// </summary>
        /// <param name="left">The <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The <see cref="object"/> to compare.</param>
        /// <returns><c>true</c> if the <paramref name="left"/> object is equal to the <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator ==(StringValues left, object? right) => left.Equals(right);

        /// <summary>
        /// Determines whether the specified <see cref="StringValues"/> and <see cref="object"/>, which must be a
        /// <see cref="StringValues"/>, <see cref="string"/>, or array of <see cref="string"/>, have different values.
        /// </summary>
        /// <param name="left">The <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The <see cref="object"/> to compare.</param>
        /// <returns><c>true</c> if the <paramref name="left"/> object is equal to the <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator !=(StringValues left, object? right) => !left.Equals(right);

        /// <summary>
        /// Determines whether the specified <see cref="object"/>, which must be a
        /// <see cref="StringValues"/>, <see cref="string"/>, or array of <see cref="string"/>, and specified <see cref="StringValues"/>,  have the same value.
        /// </summary>
        /// <param name="left">The <see cref="StringValues"/> to compare.</param>
        /// <param name="right">The <see cref="object"/> to compare.</param>
        /// <returns><c>true</c> if the <paramref name="left"/> object is equal to the <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator ==(object? left, StringValues right) => right.Equals(left);

        /// <summary>
        /// Determines whether the specified <see cref="object"/> and <see cref="StringValues"/> object have the same values.
        /// </summary>
        /// <param name="left">The <see cref="object"/> to compare.</param>
        /// <param name="right">The <see cref="StringValues"/> to compare.</param>
        /// <returns><c>true</c> if the <paramref name="left"/> object is equal to the <paramref name="right"/>; otherwise, <c>false</c>.</returns>
        public static bool operator !=(object? left, StringValues right) => !right.Equals(left);

        /// <summary>
        /// Determines whether this instance and a specified object have the same value.
        /// </summary>
        /// <param name="obj">An object to compare with this object.</param>
        /// <returns><c>true</c> if the current object is equal to <paramref name="obj"/>; otherwise, <c>false</c>.</returns>
        public override bool Equals(object? obj)
        {
            if (obj == null)
            {
                return Equals(this, StringValues.Empty);
            }

            if (obj is string str)
            {
                return Equals(this, str);
            }

            if (obj is string[] array)
            {
                return Equals(this, array);
            }

            if (obj is StringValues stringValues)
            {
                return Equals(this, stringValues);
            }

            return false;
        }

        /// <summary>
        /// Returns a hash code for this instance.
        /// </summary>
        /// <returns>
        /// A hash code for this instance, suitable for use in hashing algorithms and data structures like a hash table.
        /// </returns>
        public override int GetHashCode()
        {
            object? value = _values;
            if (value is string[] values)
            {
                if (Count == 1)
                {
                    return Unsafe.As<string>(this[0])?.GetHashCode() ?? Count.GetHashCode();
                }
                int hashCode = 0;
                for (int i = 0; i < values.Length; i++)
                {
                    hashCode = HashHelpers.Combine(hashCode, values[i]?.GetHashCode() ?? 0);
                }
                return hashCode;
            }
            else
            {
                return Unsafe.As<string>(value)?.GetHashCode() ?? Count.GetHashCode();
            }
        }

        /// <summary>
        /// Enumerates the string values of a <see cref="StringValues" />.
        /// </summary>
        public struct Enumerator : IEnumerator<string?>
        {
            private readonly string?[]? _values;
            private int _index;
            private string? _current;

            internal Enumerator(object? value)
            {
                if (value is string str)
                {
                    _values = null;
                    _current = str;
                }
                else
                {
                    _current = null;
                    _values = Unsafe.As<string?[]>(value);
                }
                _index = 0;
            }

            /// <summary>
            /// Instantiates an <see cref="Enumerator"/> using a <see cref="StringValues"/>.
            /// </summary>
            /// <param name="values">The <see cref="StringValues"/> to enumerate.</param>
            public Enumerator(ref StringValues values) : this(values._values)
            { }

            /// <summary>
            /// Advances the enumerator to the next element of the <see cref="StringValues"/>.
            /// </summary>
            /// <returns><see langword="true"/> if the enumerator was successfully advanced to the next element; <see langword="false"/> if the enumerator has passed the end of the <see cref="StringValues"/>.</returns>
            public bool MoveNext()
            {
                int index = _index;
                if (index < 0)
                {
                    return false;
                }

                string?[]? values = _values;
                if (values != null)
                {
                    if ((uint)index < (uint)values.Length)
                    {
                        _index = index + 1;
                        _current = values[index];
                        return true;
                    }

                    _index = -1;
                    return false;
                }

                _index = -1; // sentinel value
                return _current != null;
            }

            /// <summary>
            /// Gets the element at the current position of the enumerator.
            /// </summary>
            public string? Current => _current;

            object? IEnumerator.Current => _current;

            void IEnumerator.Reset()
            {
                throw new NotSupportedException();
            }

            /// <summary>
            /// Releases all resources used by the <see cref="Enumerator" />.
            /// </summary>
            public void Dispose()
            {
            }
        }

        private sealed class StringValuesDebugView(StringValues values)
        {
            [DebuggerBrowsable(DebuggerBrowsableState.RootHidden)]
            public string?[] Items => values.ToArray();
        }
    }
}

namespace Microsoft.Extensions.Primitives
{
    internal static class ThrowHelper
    {
        [DoesNotReturn]
        internal static void ThrowArgumentNullException(ExceptionArgument argument)
        {
            throw new ArgumentNullException(GetArgumentName(argument));
        }

        [DoesNotReturn]
        internal static void ThrowArgumentOutOfRangeException(ExceptionArgument argument)
        {
            throw new ArgumentOutOfRangeException(GetArgumentName(argument));
        }

        [DoesNotReturn]
        internal static void ThrowArgumentException(ExceptionResource resource)
        {
            throw new ArgumentException(GetResourceText(resource));
        }

        [DoesNotReturn]
        internal static void ThrowInvalidOperationException(ExceptionResource resource)
        {
            throw new InvalidOperationException(GetResourceText(resource));
        }

        [DoesNotReturn]
        internal static void ThrowInvalidOperationException(ExceptionResource resource, params object[] args)
        {
            string message = string.Format(GetResourceText(resource), args);

            throw new InvalidOperationException(message);
        }

        internal static ArgumentNullException GetArgumentNullException(ExceptionArgument argument)
        {
            return new ArgumentNullException(GetArgumentName(argument));
        }

        internal static ArgumentOutOfRangeException GetArgumentOutOfRangeException(ExceptionArgument argument)
        {
            return new ArgumentOutOfRangeException(GetArgumentName(argument));
        }

        internal static ArgumentException GetArgumentException(ExceptionResource resource)
        {
            return new ArgumentException(GetResourceText(resource));
        }

        private static string GetResourceText(ExceptionResource resource)
        {
            Debug.Assert(Enum.IsDefined(typeof(ExceptionResource), resource),
                "The enum value is not defined, please check the ExceptionResource Enum.");

            switch (resource)
            {
                case ExceptionResource.Argument_InvalidOffsetLength: return SR.Argument_InvalidOffsetLength;
                case ExceptionResource.Argument_InvalidOffsetLengthStringSegment: return SR.Argument_InvalidOffsetLengthStringSegment;
                case ExceptionResource.Capacity_CannotChangeAfterWriteStarted: return SR.Capacity_CannotChangeAfterWriteStarted;
                case ExceptionResource.Capacity_NotEnough: return SR.Capacity_NotEnough;
                case ExceptionResource.Capacity_NotUsedEntirely: return SR.Capacity_NotUsedEntirely;
                default:
                    Debug.Fail($"Unexpected resource {resource}");
                    return "";
            }
        }

        private static string GetArgumentName(ExceptionArgument argument)
        {
            Debug.Assert(Enum.IsDefined(typeof(ExceptionArgument), argument),
                "The enum value is not defined, please check the ExceptionArgument Enum.");

            return argument.ToString();
        }
    }

    internal enum ExceptionArgument
    {
        buffer,
        offset,
        length,
        text,
        start,
        count,
        index,
        value,
        capacity,
        separators,
        comparisonType,
        changeTokens,
        changeTokenProducer,
        changeTokenConsumer,
        array,
    }

    internal enum ExceptionResource
    {
        Argument_InvalidOffsetLength,
        Argument_InvalidOffsetLengthStringSegment,
        Capacity_CannotChangeAfterWriteStarted,
        Capacity_NotEnough,
        Capacity_NotUsedEntirely
    }
}

namespace System.Numerics.Hashing
{
    internal static class HashHelpers
    {
        public static int Combine(int h1, int h2)
        {
            // RyuJIT optimizes this to use the ROL instruction
            // Related GitHub pull request: https://github.com/dotnet/coreclr/pull/1830
            uint rol5 = ((uint)h1 << 5) | ((uint)h1 >> 27);
            return ((int)rol5 + h1) ^ h2;
        }
    }
}

namespace Microsoft.Extensions.Internal
{
    internal static class ChangeCallbackRegistrar
    {
        /// <summary>
        /// Registers for a callback that will be invoked when the entry has changed. <see cref="Primitives.IChangeToken.HasChanged"/>
        /// MUST be set before the callback is invoked.
        /// </summary>
        /// <param name="callback">The callback to invoke.</param>
        /// <param name="state">State to be passed into the callback.</param>
        /// <param name="token">The <see cref="CancellationToken"/> to invoke the callback with.</param>
        /// <param name="onFailure">The action to execute when an <see cref="ObjectDisposedException"/> is thrown. Should be used to set the IChangeToken's ActiveChangeCallbacks property to false.</param>
        /// <param name="onFailureState">The state to be passed into the <paramref name="onFailure"/> action.</param>
        /// <returns>The <see cref="CancellationToken"/> registration.</returns>
        internal static IDisposable UnsafeRegisterChangeCallback<T>(Action<object?> callback, object? state, CancellationToken token, Action<T> onFailure, T onFailureState)
        {
#if NETCOREAPP || NETSTANDARD2_1
            try
            {
                return token.UnsafeRegister(callback, state);
            }
            catch (ObjectDisposedException)
            {
                onFailure(onFailureState);
            }
#else
            // Don't capture the current ExecutionContext and its AsyncLocals onto the token registration causing them to live forever
            bool restoreFlow = false;
            if (!ExecutionContext.IsFlowSuppressed())
            {
                ExecutionContext.SuppressFlow();
                restoreFlow = true;
            }

            try
            {
                return token.Register(callback, state);
            }
            catch (ObjectDisposedException)
            {
                onFailure(onFailureState);
            }
            finally
            {
                // Restore the current ExecutionContext
                if (restoreFlow)
                {
                    ExecutionContext.RestoreFlow();
                }
            }
#endif
            return EmptyDisposable.Instance;
        }
    }
}

namespace Microsoft.Extensions.FileProviders
{
    internal sealed class EmptyDisposable : IDisposable
    {
        public static EmptyDisposable Instance { get; } = new EmptyDisposable();

        private EmptyDisposable()
        {
        }

        public void Dispose()
        {
        }
    }
}

namespace System
{
    internal static partial class SR
    {
        private static readonly bool s_usingResourceKeys = AppContext.TryGetSwitch("System.Resources.UseSystemResourceKeys", out bool usingResourceKeys) ? usingResourceKeys : false;

        // This method is used to decide if we need to append the exception message parameters to the message when calling SR.Format.
        // by default it returns the value of System.Resources.UseSystemResourceKeys AppContext switch or false if not specified.
        // Native code generators can replace the value this returns based on user input at the time of native code generation.
        // The trimming tools are also capable of replacing the value of this method when the application is being trimmed.
        internal static bool UsingResourceKeys() => s_usingResourceKeys;

        // We can optimize out the resource string blob if we can see all accesses to it happening
        // through the generated SR.XXX properties.
        // If a call to GetResourceString is left, the optimization gets defeated and we need to keep
        // the whole resource blob. It's important to keep this private. CoreCLR's CoreLib gets a free
        // pass because the VM needs to be able to call into this, but that's a known set of constants.
#if CORECLR || LEGACY_GETRESOURCESTRING_USER
        internal
#else
        private
#endif
        static string GetResourceString(string resourceKey)
        {
            if (UsingResourceKeys())
            {
                return resourceKey;
            }

            string? resourceString = null;
            try
            {
                resourceString =
#if SYSTEM_PRIVATE_CORELIB || NATIVEAOT
                    InternalGetResourceString(resourceKey);
#else
                    ResourceManager.GetString(resourceKey);
#endif
            }
            catch (MissingManifestResourceException) { }

            return resourceString!; // only null if missing resources
        }

#if LEGACY_GETRESOURCESTRING_USER
        internal
#else
        private
#endif
        static string GetResourceString(string resourceKey, string defaultString)
        {
            string resourceString = GetResourceString(resourceKey);

            return resourceKey == resourceString || resourceString == null ? defaultString : resourceString;
        }

        internal static string Format(string resourceFormat, object? p1)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1);
            }

            return string.Format(resourceFormat, p1);
        }

        internal static string Format(string resourceFormat, object? p1, object? p2)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2);
            }

            return string.Format(resourceFormat, p1, p2);
        }

        internal static string Format(string resourceFormat, object? p1, object? p2, object? p3)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2, p3);
            }

            return string.Format(resourceFormat, p1, p2, p3);
        }

        internal static string Format(string resourceFormat, params object?[]? args)
        {
            if (args != null)
            {
                if (UsingResourceKeys())
                {
                    return resourceFormat + ", " + string.Join(", ", args);
                }

                return string.Format(resourceFormat, args);
            }

            return resourceFormat;
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, object? p1)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1);
            }

            return string.Format(provider, resourceFormat, p1);
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, object? p1, object? p2)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2);
            }

            return string.Format(provider, resourceFormat, p1, p2);
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, object? p1, object? p2, object? p3)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2, p3);
            }

            return string.Format(provider, resourceFormat, p1, p2, p3);
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, params object?[]? args)
        {
            if (args != null)
            {
                if (UsingResourceKeys())
                {
                    return resourceFormat + ", " + string.Join(", ", args);
                }

                return string.Format(provider, resourceFormat, args);
            }

            return resourceFormat;
        }
    }
}

namespace FxResources.Microsoft.Extensions.Primitives
{
    internal static class SR
    {
    }
}

namespace System
{
    internal static partial class SR
    {
        private static ResourceManager? s_resourceManager;

        internal static ResourceManager ResourceManager =>
            s_resourceManager ??= new ResourceManager(typeof(FxResources.Microsoft.Extensions.Primitives.SR));

        internal static string Argument_InvalidOffsetLength => GetResourceString("Argument_InvalidOffsetLength");

        internal static string Argument_InvalidOffsetLengthStringSegment => GetResourceString("Argument_InvalidOffsetLengthStringSegment");

        internal static string Capacity_CannotChangeAfterWriteStarted => GetResourceString("Capacity_CannotChangeAfterWriteStarted");

        internal static string Capacity_NotEnough => GetResourceString("Capacity_NotEnough");

        internal static string Capacity_NotUsedEntirely => GetResourceString("Capacity_NotUsedEntirely");
    }
}
