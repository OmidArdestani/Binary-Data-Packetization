package com.binarydatapacketizer;

import static org.junit.jupiter.api.Assertions.*;

import java.nio.charset.StandardCharsets;
import java.util.Arrays;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class BinaryDataPackerTest {
    private static final byte[] SAMPLE_PAYLOAD =
            "The quick brown fox jumps over the lazy dog".getBytes(StandardCharsets.UTF_8);

    @Test
    @DisplayName("pack and unpack a simple payload")
    void packAndUnpackRoundTrip() {
        var packer = new BinaryDataPacker();
        packer.setSofBuilder(new ConstantHeaderBuilder("SOF".getBytes(StandardCharsets.UTF_8)));
        packer.addEofBuilder(new ConstantHeaderBuilder("EOF".getBytes(StandardCharsets.UTF_8)));

        var packet = packer.getPacket(SAMPLE_PAYLOAD);
        assertArrayEquals("SOF".getBytes(StandardCharsets.UTF_8), Arrays.copyOf(packet, 3));
        assertArrayEquals("EOF".getBytes(StandardCharsets.UTF_8),
                Arrays.copyOfRange(packet, packet.length - 3, packet.length));

        assertArrayEquals(SAMPLE_PAYLOAD, packer.unpackData(packet));
    }

    @Test
    @DisplayName("length and CRC validations detect tampering")
    void lengthAndCrcValidations() {
        var packer = new BinaryDataPacker();
        packer.setSofBuilder(new PayloadLengthBuilder());
        packer.addEofBuilder(new Crc32Builder());

        var packet = packer.getPacket(SAMPLE_PAYLOAD);
        var tampered = packet.clone();
        tampered[tampered.length - 1] ^= 0x01;
        assertThrows(PacketValidationException.class, () -> packer.unpackData(tampered));
    }

    @Test
    @DisplayName("transformations are applied and reverted")
    void transformationsAreAppliedAndReverted() {
        var packer = new BinaryDataPacker();
        packer.setSofBuilder(new ConstantHeaderBuilder("HDR".getBytes(StandardCharsets.UTF_8)));
        packer.addPacketBuilder(new XorPacketBuilder("secret".getBytes(StandardCharsets.UTF_8)));
        packer.addPacketBuilder(new DeflatePacketBuilder(9));
        packer.addEofBuilder(new Crc32Builder());

        var packet = packer.getPacket(SAMPLE_PAYLOAD);
        assertFalse(new String(packet, StandardCharsets.UTF_8).contains("The quick brown fox"));

        assertArrayEquals(SAMPLE_PAYLOAD, packer.unpackData(packet));
    }

    @Test
    @DisplayName("configuration safeguards")
    void configurationErrors() {
        var packer = new BinaryDataPacker();
        assertThrows(PacketConfigurationException.class, () -> packer.setSofBuilder(null));
        assertThrows(PacketConfigurationException.class, () -> packer.addEofBuilder(null));
        assertThrows(PacketConfigurationException.class, () -> packer.addPacketBuilder(null));
        assertThrows(PacketConfigurationException.class, () -> new ConstantHeaderBuilder(new byte[0]));
        assertThrows(PacketConfigurationException.class, () -> new XorPacketBuilder(new byte[0]));
        assertThrows(PacketConfigurationException.class, () -> new DeflatePacketBuilder(42));
    }

    @Test
    @DisplayName("body length mismatch is detected")
    void bodyLengthMismatch() {
        var packer = new BinaryDataPacker();
        var packet = packer.getPacket(SAMPLE_PAYLOAD);
        var tampered = packet.clone();
        tampered[1] ^= 0xFF; // flip body length byte
        assertThrows(PacketValidationException.class, () -> packer.unpackData(tampered));
    }

    @Test
    @DisplayName("string payloads are encoded using UTF-8")
    void stringPayloadsAreSupported() {
        var packer = new BinaryDataPacker();
        var packet = packer.getPacket("payload with ünicode");
        assertArrayEquals("payload with ünicode".getBytes(StandardCharsets.UTF_8), packer.unpackData(packet));
    }
}
