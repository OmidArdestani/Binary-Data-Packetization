package com.binarydatapacketizer;

/**
 * Thrown when the packetizer is misconfigured.
 */
public final class PacketConfigurationException extends IllegalStateException {
    public PacketConfigurationException(String message) {
        super(message);
    }
}
