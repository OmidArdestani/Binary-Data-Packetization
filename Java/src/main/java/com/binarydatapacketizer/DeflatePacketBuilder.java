package com.binarydatapacketizer;

import java.io.ByteArrayOutputStream;
import java.util.zip.DataFormatException;
import java.util.zip.Deflater;
import java.util.zip.Inflater;

/**
 * Compresses and decompresses payloads using the DEFLATE algorithm.
 */
public final class DeflatePacketBuilder implements PacketBuilder {
    private final int level;

    public DeflatePacketBuilder(int level) {
        if (level < Deflater.NO_COMPRESSION || level > Deflater.BEST_COMPRESSION) {
            throw new PacketConfigurationException("invalid DEFLATE compression level");
        }
        this.level = level;
    }

    public DeflatePacketBuilder() {
        this(Deflater.DEFAULT_COMPRESSION);
    }

    @Override
    public byte[] apply(byte[] data) {
        var deflater = new Deflater(level);
        deflater.setInput(data);
        deflater.finish();
        var output = new ByteArrayOutputStream();
        var buffer = new byte[1024];
        while (!deflater.finished()) {
            int count = deflater.deflate(buffer);
            output.write(buffer, 0, count);
        }
        deflater.end();
        return output.toByteArray();
    }

    @Override
    public byte[] revert(byte[] data) {
        var inflater = new Inflater();
        inflater.setInput(data);
        var output = new ByteArrayOutputStream();
        var buffer = new byte[1024];
        try {
            while (!inflater.finished()) {
                int count = inflater.inflate(buffer);
                if (count == 0 && inflater.needsInput()) {
                    break;
                }
                output.write(buffer, 0, count);
            }
        } catch (DataFormatException ex) {
            throw new PacketValidationException("invalid DEFLATE payload", ex);
        } finally {
            inflater.end();
        }
        return output.toByteArray();
    }
}
