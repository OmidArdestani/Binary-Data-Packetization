using System.Buffers.Binary;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.IO.Hashing;
using System.Linq;

namespace BinaryDataPacker;

public sealed class PacketConfigurationException : InvalidOperationException
{
    public PacketConfigurationException(string message) : base(message)
    {
    }
}

public sealed class PacketValidationException : InvalidOperationException
{
    public PacketValidationException(string message) : base(message)
    {
    }
}

public interface IHeaderBuilder
{
    int Size { get; }

    byte[] Build(ReadOnlySpan<byte> rawPayload);

    Action<byte[]> CreateValidator(ReadOnlySpan<byte> builtBytes);
}

public interface IPacketBuilder
{
    byte[] Apply(ReadOnlySpan<byte> data);

    byte[] Revert(ReadOnlySpan<byte> data);
}

public sealed class ConstantHeaderBuilder : IHeaderBuilder
{
    private readonly byte[] _value;

    public ConstantHeaderBuilder(ReadOnlySpan<byte> value)
    {
        if (value.IsEmpty)
        {
            throw new PacketConfigurationException("constant header value must not be empty");
        }

        _value = value.ToArray();
    }

    public int Size => _value.Length;

    public byte[] Build(ReadOnlySpan<byte> rawPayload) => _value;

    public Action<byte[]> CreateValidator(ReadOnlySpan<byte> builtBytes)
    {
        if (!builtBytes.SequenceEqual(_value))
        {
            throw new PacketValidationException("constant header/footer mismatch");
        }

        return _ => { };
    }
}

public sealed class PayloadLengthBuilder : IHeaderBuilder
{
    public int Size => 4;

    public byte[] Build(ReadOnlySpan<byte> rawPayload)
    {
        var buffer = new byte[Size];
        BinaryPrimitives.WriteInt32BigEndian(buffer, rawPayload.Length);
        return buffer;
    }

    public Action<byte[]> CreateValidator(ReadOnlySpan<byte> builtBytes)
    {
        if (builtBytes.Length != Size)
        {
            throw new PacketValidationException("invalid payload length field size");
        }

        var expectedLength = BinaryPrimitives.ReadInt32BigEndian(builtBytes);
        return payload =>
        {
            if (payload.Length != expectedLength)
            {
                throw new PacketValidationException(
                    $"payload length mismatch: expected {expectedLength}, got {payload.Length}");
            }
        };
    }
}

public sealed class Crc32Builder : IHeaderBuilder
{
    public int Size => 4;

    public byte[] Build(ReadOnlySpan<byte> rawPayload)
    {
        var checksum = Crc32.Hash(rawPayload);
        if (checksum.Length != Size)
        {
            throw new PacketConfigurationException("unexpected CRC-32 output size");
        }

        return checksum;
    }

    public Action<byte[]> CreateValidator(ReadOnlySpan<byte> builtBytes)
    {
        if (builtBytes.Length != Size)
        {
            throw new PacketValidationException("invalid CRC field size");
        }

        var expected = BinaryPrimitives.ReadUInt32BigEndian(builtBytes);
        return payload =>
        {
            var actual = BinaryPrimitives.ReadUInt32BigEndian(Crc32.Hash(payload));
            if (actual != expected)
            {
                throw new PacketValidationException(
                    $"CRC mismatch: expected 0x{expected:X8}, got 0x{actual:X8}");
            }
        };
    }
}

public sealed class XorPacketBuilder : IPacketBuilder
{
    private readonly byte[] _key;

    public XorPacketBuilder(ReadOnlySpan<byte> key)
    {
        if (key.IsEmpty)
        {
            throw new PacketConfigurationException("XOR key must not be empty");
        }

        _key = key.ToArray();
    }

    public byte[] Apply(ReadOnlySpan<byte> data) => Xor(data);

    public byte[] Revert(ReadOnlySpan<byte> data) => Xor(data);

    private byte[] Xor(ReadOnlySpan<byte> data)
    {
        var result = new byte[data.Length];
        for (var i = 0; i < data.Length; i++)
        {
            result[i] = (byte)(data[i] ^ _key[i % _key.Length]);
        }

        return result;
    }
}

public sealed class DeflatePacketBuilder : IPacketBuilder
{
    private readonly CompressionLevel _level;

    public DeflatePacketBuilder(CompressionLevel level = CompressionLevel.Optimal)
    {
        _level = level;
    }

    public byte[] Apply(ReadOnlySpan<byte> data)
    {
        using var output = new MemoryStream();
        using (var deflate = new DeflateStream(output, _level, leaveOpen: true))
        {
            deflate.Write(data);
        }

        return output.ToArray();
    }

    public byte[] Revert(ReadOnlySpan<byte> data)
    {
        using var input = new MemoryStream(data.ToArray());
        using var deflate = new DeflateStream(input, CompressionMode.Decompress);
        using var output = new MemoryStream();

        try
        {
            deflate.CopyTo(output);
        }
        catch (InvalidDataException ex)
        {
            throw new PacketValidationException($"failed to decompress payload: {ex.Message}");
        }

        return output.ToArray();
    }
}

public sealed class BinaryDataPacker
{
    private IHeaderBuilder? _sofBuilder;
    private readonly List<IHeaderBuilder> _eofBuilders = new();
    private readonly List<IPacketBuilder> _packetBuilders = new();

    public void AddSOFBuilder(IHeaderBuilder headerBuilder)
    {
        _sofBuilder = headerBuilder ?? throw new ArgumentNullException(nameof(headerBuilder));
    }

    public void AddEOFBuilder(IHeaderBuilder headerBuilder)
    {
        if (headerBuilder is null)
        {
            throw new ArgumentNullException(nameof(headerBuilder));
        }

        _eofBuilders.Add(headerBuilder);
    }

    public void AddPacketBuilder(IPacketBuilder packetBuilder)
    {
        if (packetBuilder is null)
        {
            throw new ArgumentNullException(nameof(packetBuilder));
        }

        _packetBuilders.Add(packetBuilder);
    }

    public byte[] GetPacket(byte[] rawData)
    {
        if (rawData is null)
        {
            throw new ArgumentNullException(nameof(rawData));
        }

        return BuildPacket(rawData);
    }

    public void GetPacket(byte[] raw_data, int size, ref byte[] result_buffer, ref int result_size)
    {
        if (raw_data is null)
        {
            throw new ArgumentNullException(nameof(raw_data));
        }

        if (size < 0 || size > raw_data.Length)
        {
            throw new ArgumentOutOfRangeException(nameof(size));
        }

        var payload = raw_data.AsSpan(0, size).ToArray();
        var packet = BuildPacket(payload);
        result_buffer = packet;
        result_size = packet.Length;
    }

    public byte[] UnpackData(byte[] packedData)
    {
        if (packedData is null)
        {
            throw new ArgumentNullException(nameof(packedData));
        }

        return ExtractPayload(packedData);
    }

    public void UnpackData(byte[] packed_data, int packet_size, ref byte[] result_buffer, ref int result_size)
    {
        if (packed_data is null)
        {
            throw new ArgumentNullException(nameof(packed_data));
        }

        if (packet_size < 0 || packet_size > packed_data.Length)
        {
            throw new ArgumentOutOfRangeException(nameof(packet_size));
        }

        var packet = packed_data.AsSpan(0, packet_size).ToArray();
        var payload = ExtractPayload(packet);
        result_buffer = payload;
        result_size = payload.Length;
    }

    private byte[] BuildPacket(ReadOnlySpan<byte> rawPayload)
    {
        var headerValidators = new List<Action<byte[]>>();
        var headerBytes = Array.Empty<byte>();

        if (_sofBuilder is not null)
        {
            headerBytes = _sofBuilder.Build(rawPayload);
            if (headerBytes.Length != _sofBuilder.Size)
            {
                throw new PacketConfigurationException("SOF builder returned unexpected number of bytes");
            }

            headerValidators.Add(_sofBuilder.CreateValidator(headerBytes));
        }

        var footerBytes = new List<byte>();
        var footerValidators = new List<Action<byte[]>>();
        foreach (var builder in _eofBuilders)
        {
            var bytes = builder.Build(rawPayload);
            if (bytes.Length != builder.Size)
            {
                throw new PacketConfigurationException("EOF builder returned unexpected number of bytes");
            }

            footerBytes.AddRange(bytes);
            footerValidators.Add(builder.CreateValidator(bytes));
        }

        var transformed = rawPayload.ToArray();
        foreach (var builder in _packetBuilders)
        {
            transformed = builder.Apply(transformed);
        }

        var packet = new byte[headerBytes.Length + 4 + transformed.Length + footerBytes.Count];
        var cursor = 0;

        Array.Copy(headerBytes, 0, packet, cursor, headerBytes.Length);
        cursor += headerBytes.Length;

        BinaryPrimitives.WriteInt32BigEndian(packet.AsSpan(cursor, 4), transformed.Length);
        cursor += 4;

        Array.Copy(transformed, 0, packet, cursor, transformed.Length);
        cursor += transformed.Length;

        if (footerBytes.Count > 0)
        {
            footerBytes.CopyTo(packet, cursor);
        }

        foreach (var validator in headerValidators)
        {
            validator(rawPayload.ToArray());
        }

        foreach (var validator in footerValidators)
        {
            validator(rawPayload.ToArray());
        }

        return packet;
    }

    private byte[] ExtractPayload(ReadOnlySpan<byte> packet)
    {
        var validators = new List<Action<byte[]>>();
        var cursor = 0;

        if (_sofBuilder is not null)
        {
            if (packet.Length < _sofBuilder.Size)
            {
                throw new PacketValidationException("packet is too small to contain the header");
            }

            var header = packet.Slice(cursor, _sofBuilder.Size).ToArray();
            validators.Add(_sofBuilder.CreateValidator(header));
            cursor += _sofBuilder.Size;
        }

        var footerSegments = new List<Action<byte[]>>();
        if (_eofBuilders.Count > 0)
        {
            var remaining = packet.Length - cursor;
            for (var index = _eofBuilders.Count - 1; index >= 0; index--)
            {
                var builder = _eofBuilders[index];
                if (remaining < builder.Size)
                {
                    throw new PacketValidationException("packet is too small to contain the footer");
                }

                var segmentStart = packet.Length - builder.Size;
                var footerSegment = packet.Slice(segmentStart, builder.Size).ToArray();
                footerSegments.Add(builder.CreateValidator(footerSegment));
                packet = packet.Slice(0, segmentStart);
                remaining = packet.Length - cursor;
            }

            footerSegments.Reverse();
            validators.AddRange(footerSegments);
        }

        if (packet.Length - cursor < 4)
        {
            throw new PacketValidationException("packet does not contain body length information");
        }

        var bodyLength = BinaryPrimitives.ReadInt32BigEndian(packet.Slice(cursor, 4));
        cursor += 4;

        var body = packet.Slice(cursor).ToArray();
        if (body.Length != bodyLength)
        {
            throw new PacketValidationException(
                $"body length mismatch: declared {bodyLength}, actual {body.Length}");
        }

        var transformed = body;
        for (var index = _packetBuilders.Count - 1; index >= 0; index--)
        {
            transformed = _packetBuilders[index].Revert(transformed);
        }

        foreach (var validator in validators)
        {
            validator(transformed);
        }

        return transformed;
    }
}

