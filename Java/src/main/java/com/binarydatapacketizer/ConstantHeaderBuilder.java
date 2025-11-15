package com.binarydatapacketizer;

import java.util.Arrays;
import java.util.function.Consumer;

/**
 * Header/footer builder that emits a constant value.
 */
public final class ConstantHeaderBuilder implements HeaderBuilder {
    private final byte[] value;

    public ConstantHeaderBuilder(byte[] value) {
        if (value == null || value.length == 0) {
            throw new PacketConfigurationException("constant header value must not be empty");
        }
        this.value = Arrays.copyOf(value, value.length);
    }

    @Override
    public int size() {
        return value.length;
    }

    @Override
    public byte[] build(byte[] rawPayload) {
        return Arrays.copyOf(value, value.length);
    }

    @Override
    public Consumer<byte[]> createValidator(byte[] builtBytes) {
        if (!Arrays.equals(builtBytes, value)) {
            throw new PacketValidationException("constant header/footer mismatch");
        }
        return payload -> {};
    }
}
