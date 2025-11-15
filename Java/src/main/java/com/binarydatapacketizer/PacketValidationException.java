package com.binarydatapacketizer;

/**
 * Thrown when validation fails while unpacking a packet.
 */
public final class PacketValidationException extends IllegalArgumentException {
    public PacketValidationException(String message) {
        super(message);
    }

    public PacketValidationException(String message, Throwable cause) {
        super(message, cause);
    }
}
