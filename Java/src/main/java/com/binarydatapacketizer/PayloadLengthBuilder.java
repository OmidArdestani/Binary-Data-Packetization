package com.binarydatapacketizer;

import java.nio.ByteBuffer;
import java.util.function.Consumer;

/**
 * Stores the payload length as a 4-byte big-endian integer.
 */
public final class PayloadLengthBuilder implements HeaderBuilder {
    private static final int SIZE = 4;

    @Override
    public int size() {
        return SIZE;
    }

    @Override
    public byte[] build(byte[] rawPayload) {
        return ByteBuffer.allocate(SIZE).putInt(rawPayload.length).array();
    }

    @Override
    public Consumer<byte[]> createValidator(byte[] builtBytes) {
        if (builtBytes.length != SIZE) {
            throw new PacketValidationException("invalid payload length field size");
        }
        var expectedLength = ByteBuffer.wrap(builtBytes).getInt();
        return payload -> {
            if (payload.length != expectedLength) {
                throw new PacketValidationException(
                        "payload length mismatch: expected " + expectedLength + ", got " + payload.length);
            }
        };
    }
}
