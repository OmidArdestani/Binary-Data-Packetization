package com.binarydatapacketizer;

import java.nio.ByteBuffer;
import java.util.zip.CRC32;
import java.util.function.Consumer;

/**
 * Stores a CRC32 checksum of the raw payload.
 */
public final class Crc32Builder implements HeaderBuilder {
    private static final int SIZE = 4;

    @Override
    public int size() {
        return SIZE;
    }

    @Override
    public byte[] build(byte[] rawPayload) {
        var crc32 = new CRC32();
        crc32.update(rawPayload);
        return ByteBuffer.allocate(SIZE).putInt((int) (crc32.getValue() & 0xFFFFFFFFL)).array();
    }

    @Override
    public Consumer<byte[]> createValidator(byte[] builtBytes) {
        if (builtBytes.length != SIZE) {
            throw new PacketValidationException("invalid CRC field size");
        }
        var expected = ByteBuffer.wrap(builtBytes).getInt();
        return payload -> {
            var crc32 = new CRC32();
            crc32.update(payload);
            int actual = (int) (crc32.getValue() & 0xFFFFFFFFL);
            if (actual != expected) {
                throw new PacketValidationException(
                        String.format("CRC mismatch: expected 0x%08X, got 0x%08X", expected, actual));
            }
        };
    }
}
