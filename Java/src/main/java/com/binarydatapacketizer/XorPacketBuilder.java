package com.binarydatapacketizer;

import java.util.Arrays;

/**
 * Applies a XOR transformation with a repeating key.
 */
public final class XorPacketBuilder implements PacketBuilder {
    private final byte[] key;

    public XorPacketBuilder(byte[] key) {
        if (key == null || key.length == 0) {
            throw new PacketConfigurationException("XOR key must not be empty");
        }
        this.key = Arrays.copyOf(key, key.length);
    }

    @Override
    public byte[] apply(byte[] data) {
        return xor(data);
    }

    @Override
    public byte[] revert(byte[] data) {
        return xor(data);
    }

    private byte[] xor(byte[] data) {
        var result = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            result[i] = (byte) (data[i] ^ key[i % key.length]);
        }
        return result;
    }
}
