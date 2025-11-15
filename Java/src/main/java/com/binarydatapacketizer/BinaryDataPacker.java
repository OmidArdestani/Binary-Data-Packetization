package com.binarydatapacketizer;

import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Objects;
import java.util.function.Consumer;

/**
 * Packs and unpacks binary data using configurable header/footer builders and
 * packet body transformations.
 */
public final class BinaryDataPacker {
    private HeaderBuilder sofBuilder;
    private final List<HeaderBuilder> eofBuilders = new ArrayList<>();
    private final List<PacketBuilder> packetBuilders = new ArrayList<>();

    public void setSofBuilder(HeaderBuilder builder) {
        if (builder == null) {
            throw new PacketConfigurationException("SOF builder must not be null");
        }
        this.sofBuilder = builder;
    }

    public void clearSofBuilder() {
        this.sofBuilder = null;
    }

    public void addEofBuilder(HeaderBuilder builder) {
        if (builder == null) {
            throw new PacketConfigurationException("EOF builder must not be null");
        }
        eofBuilders.add(builder);
    }

    public void clearEofBuilders() {
        eofBuilders.clear();
    }

    public void addPacketBuilder(PacketBuilder builder) {
        if (builder == null) {
            throw new PacketConfigurationException("packet builder must not be null");
        }
        packetBuilders.add(builder);
    }

    public void clearPacketBuilders() {
        packetBuilders.clear();
    }

    private record Segment(byte[] bytes, List<Consumer<byte[]>> validators) {
        Segment {
            Objects.requireNonNull(bytes, "bytes");
            Objects.requireNonNull(validators, "validators");
        }
    }

    private Segment buildHeader(byte[] rawPayload) {
        if (sofBuilder == null) {
            return new Segment(new byte[0], List.of());
        }
        var header = sofBuilder.build(rawPayload);
        if (header.length != sofBuilder.size()) {
            throw new PacketConfigurationException("SOF builder returned an unexpected number of bytes");
        }
        var validator = sofBuilder.createValidator(Arrays.copyOf(header, header.length));
        return new Segment(header, List.of(validator));
    }

    private Segment buildFooter(byte[] rawPayload) {
        if (eofBuilders.isEmpty()) {
            return new Segment(new byte[0], List.of());
        }
        var output = new byte[eofBuilders.stream().mapToInt(HeaderBuilder::size).sum()];
        int offset = 0;
        var validators = new ArrayList<Consumer<byte[]>>(eofBuilders.size());
        for (var builder : eofBuilders) {
            var segment = builder.build(rawPayload);
            if (segment.length != builder.size()) {
                throw new PacketConfigurationException("builder returned an unexpected number of bytes");
            }
            System.arraycopy(segment, 0, output, offset, segment.length);
            offset += segment.length;
            validators.add(builder.createValidator(Arrays.copyOf(segment, segment.length)));
        }
        return new Segment(output, validators);
    }

    private Segment extractHeader(byte[] packet, int offset) {
        if (sofBuilder == null) {
            return new Segment(new byte[0], List.of());
        }
        int size = sofBuilder.size();
        if (packet.length - offset < size) {
            throw new PacketValidationException("packet is too small to contain the header");
        }
        var header = Arrays.copyOfRange(packet, offset, offset + size);
        var validator = sofBuilder.createValidator(header);
        return new Segment(header, List.of(validator));
    }

    private Segment extractFooter(byte[] packet, int start, int end) {
        if (eofBuilders.isEmpty()) {
            return new Segment(new byte[0], List.of());
        }
        var validators = new ArrayList<Consumer<byte[]>>(eofBuilders.size());
        int cursor = end;
        for (int i = eofBuilders.size() - 1; i >= 0; i--) {
            var builder = eofBuilders.get(i);
            int size = builder.size();
            if (cursor - size < start) {
                throw new PacketValidationException("packet is too small to contain the footer");
            }
            var segment = Arrays.copyOfRange(packet, cursor - size, cursor);
            validators.add(builder.createValidator(segment));
            cursor -= size;
        }
        Collections.reverse(validators);
        return new Segment(Arrays.copyOfRange(packet, cursor, end), validators);
    }

    public byte[] getPacket(byte[] payload) {
        Objects.requireNonNull(payload, "payload");
        var rawPayload = Arrays.copyOf(payload, payload.length);
        var header = buildHeader(rawPayload);
        var footer = buildFooter(rawPayload);

        byte[] transformed = rawPayload;
        for (var builder : packetBuilders) {
            transformed = builder.apply(transformed);
        }

        var bodyLength = ByteBuffer.allocate(4).putInt(transformed.length).array();
        var packet = new byte[header.bytes().length + bodyLength.length + transformed.length + footer.bytes().length];
        int offset = 0;
        System.arraycopy(header.bytes(), 0, packet, offset, header.bytes().length);
        offset += header.bytes().length;
        System.arraycopy(bodyLength, 0, packet, offset, bodyLength.length);
        offset += bodyLength.length;
        System.arraycopy(transformed, 0, packet, offset, transformed.length);
        offset += transformed.length;
        System.arraycopy(footer.bytes(), 0, packet, offset, footer.bytes().length);

        // Run validators eagerly to surface configuration issues during packing.
        for (var validator : header.validators()) {
            validator.accept(rawPayload);
        }
        for (var validator : footer.validators()) {
            validator.accept(rawPayload);
        }

        return packet;
    }

    public byte[] getPacket(String payload) {
        Objects.requireNonNull(payload, "payload");
        return getPacket(payload.getBytes(StandardCharsets.UTF_8));
    }

    public byte[] unpackData(byte[] packet) {
        Objects.requireNonNull(packet, "packet");
        int offset = 0;
        var validators = new ArrayList<Consumer<byte[]>>();

        if (sofBuilder != null) {
            var header = extractHeader(packet, offset);
            validators.addAll(header.validators());
            offset += sofBuilder.size();
        }

        int end = packet.length;
        if (!eofBuilders.isEmpty()) {
            var footer = extractFooter(packet, offset, end);
            validators.addAll(footer.validators());
            end -= footer.bytes().length;
        }

        if (end - offset < 4) {
            throw new PacketValidationException("packet does not contain body length information");
        }
        int bodyLength = ByteBuffer.wrap(packet, offset, 4).getInt();
        offset += 4;
        int actualBodySize = end - offset;
        if (actualBodySize != bodyLength) {
            throw new PacketValidationException(
                    "body length mismatch: declared " + bodyLength + ", actual " + actualBodySize);
        }
        var body = Arrays.copyOfRange(packet, offset, end);

        byte[] transformed = body;
        for (int i = packetBuilders.size() - 1; i >= 0; i--) {
            transformed = packetBuilders.get(i).revert(transformed);
        }

        for (var validator : validators) {
            validator.accept(transformed);
        }

        return transformed;
    }
}
