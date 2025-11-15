package com.binarydatapacketizer;

import java.util.function.Consumer;

/**
 * Produces fixed-size segments for headers or footers.
 */
public interface HeaderBuilder {
    int size();

    byte[] build(byte[] rawPayload);

    Consumer<byte[]> createValidator(byte[] builtBytes);
}
