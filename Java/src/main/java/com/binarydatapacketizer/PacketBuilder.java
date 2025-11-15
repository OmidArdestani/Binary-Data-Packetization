package com.binarydatapacketizer;

/**
 * Transforms the packet body when packing and unpacks it when reverting.
 */
public interface PacketBuilder {
    byte[] apply(byte[] data);

    byte[] revert(byte[] data);
}
