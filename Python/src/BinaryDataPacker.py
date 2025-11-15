"""Binary data packetization utilities.

This module implements a simple but extensible packetization system that
allows callers to decorate raw payloads with headers, footers and a chain
of transformations (encryption, compression, ...).  The implementation is
purposely lightweight and only depends on the Python standard library so it
can be used in resource constrained environments as well as in unit tests.

The design is intentionally declarative.  A :class:`BinaryDataPacker`
instance is configured with builders that produce fixed size header/footer
segments based on the *raw* payload.  The packer also maintains a
collection of :class:`PacketBuilder` instances that are applied sequentially
when the payload is packed and rolled back in reverse order during
unpacking.  Each builder contributes an optional validator that is executed
once the raw payload has been reconstructed.

Even though the original project description mentions a huge amount of
combinations, the Python implementation focuses on a pragmatic and tested
subset that covers the most common scenarios: constant markers, payload
length information, CRC32 checksums, XOR based encryption and DEFLATE
compression.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Callable, List, Optional
import binascii
import zlib


class PacketConfigurationError(ValueError):
    """Raised when the packer is misconfigured."""


class PacketValidationError(ValueError):
    """Raised when validation fails while unpacking a packet."""


Validator = Callable[[bytes], None]


class FixedSizeBuilder:
    """Base class for header/footer builders with a fixed output size."""

    size: int

    def __init__(self, size: int) -> None:
        if size <= 0:
            raise PacketConfigurationError("builder size must be positive")
        self.size = size

    def build(self, raw_payload: bytes) -> bytes:
        raise NotImplementedError

    def create_validator(self, built_bytes: bytes) -> Validator:
        raise NotImplementedError

    def __repr__(self) -> str:  # pragma: no cover - helper for debugging
        return f"{self.__class__.__name__}(size={self.size})"


class ConstantBuilder(FixedSizeBuilder):
    """Builder that always emits the same byte sequence."""

    def __init__(self, value: bytes) -> None:
        if not isinstance(value, (bytes, bytearray)):
            raise PacketConfigurationError("constant value must be bytes")
        self._value = bytes(value)
        super().__init__(len(self._value))

    def build(self, raw_payload: bytes) -> bytes:  # pragma: no cover - trivial
        return self._value

    def create_validator(self, built_bytes: bytes) -> Validator:
        expected = self._value

        if built_bytes != expected:
            raise PacketValidationError("constant header/footer mismatch")

        return lambda _: None


class PayloadLengthBuilder(FixedSizeBuilder):
    """Builder that encodes the raw payload length as an unsigned integer."""

    def __init__(self) -> None:
        super().__init__(size=4)

    def build(self, raw_payload: bytes) -> bytes:
        return len(raw_payload).to_bytes(self.size, byteorder="big")

    def create_validator(self, built_bytes: bytes) -> Validator:
        if len(built_bytes) != self.size:
            raise PacketValidationError("invalid payload length field size")
        expected_length = int.from_bytes(built_bytes, byteorder="big")

        def _validate(raw_payload: bytes) -> None:
            if len(raw_payload) != expected_length:
                raise PacketValidationError(
                    "payload length mismatch: expected "
                    f"{expected_length}, got {len(raw_payload)}"
                )

        return _validate


class CRC32Builder(FixedSizeBuilder):
    """Builder that stores a CRC32 checksum of the raw payload."""

    def __init__(self) -> None:
        super().__init__(size=4)

    def build(self, raw_payload: bytes) -> bytes:
        checksum = binascii.crc32(raw_payload) & 0xFFFFFFFF
        return checksum.to_bytes(self.size, byteorder="big")

    def create_validator(self, built_bytes: bytes) -> Validator:
        if len(built_bytes) != self.size:
            raise PacketValidationError("invalid CRC field size")
        expected = int.from_bytes(built_bytes, byteorder="big")

        def _validate(raw_payload: bytes) -> None:
            actual = binascii.crc32(raw_payload) & 0xFFFFFFFF
            if actual != expected:
                raise PacketValidationError(
                    "CRC mismatch: expected "
                    f"0x{expected:08X}, got 0x{actual:08X}"
                )

        return _validate


class PacketBuilder:
    """Base class for transformations applied to payloads."""

    def apply(self, data: bytes) -> bytes:
        raise NotImplementedError

    def revert(self, data: bytes) -> bytes:
        raise NotImplementedError


@dataclass
class XorCipher(PacketBuilder):
    """Symmetric XOR based cipher using a repeating key."""

    key: bytes

    def __post_init__(self) -> None:
        if not self.key:
            raise PacketConfigurationError("XOR key must not be empty")
        if not isinstance(self.key, (bytes, bytearray)):
            raise PacketConfigurationError("XOR key must be bytes")
        self.key = bytes(self.key)

    def _xor(self, data: bytes) -> bytes:
        key = self.key
        key_len = len(key)
        return bytes(b ^ key[i % key_len] for i, b in enumerate(data))

    def apply(self, data: bytes) -> bytes:
        return self._xor(data)

    def revert(self, data: bytes) -> bytes:
        return self._xor(data)


class DeflateCompressor(PacketBuilder):
    """Applies DEFLATE compression and decompression using zlib."""

    def __init__(self, level: int = 6) -> None:
        if not (0 <= level <= 9):
            raise PacketConfigurationError("compression level must be between 0 and 9")
        self.level = level

    def apply(self, data: bytes) -> bytes:
        return zlib.compress(data, self.level)

    def revert(self, data: bytes) -> bytes:
        try:
            return zlib.decompress(data)
        except zlib.error as exc:  # pragma: no cover - exercised via tests
            raise PacketValidationError(f"failed to decompress payload: {exc}") from exc


class BinaryDataPacker:
    """Utility that packs and unpacks binary payloads."""

    def __init__(self) -> None:
        self._sof_builder: Optional[FixedSizeBuilder] = None
        self._eof_builders: List[FixedSizeBuilder] = []
        self._packet_builders: List[PacketBuilder] = []

    # ------------------------------------------------------------------
    # Configuration helpers
    def set_sof_builder(self, builder: FixedSizeBuilder) -> None:
        if not isinstance(builder, FixedSizeBuilder):
            raise PacketConfigurationError("SOF builder must derive from FixedSizeBuilder")
        self._sof_builder = builder

    def add_eof_builder(self, builder: FixedSizeBuilder) -> None:
        if not isinstance(builder, FixedSizeBuilder):
            raise PacketConfigurationError("EOF builder must derive from FixedSizeBuilder")
        self._eof_builders.append(builder)

    def clear_eof_builders(self) -> None:
        self._eof_builders.clear()

    def add_packet_builder(self, builder: PacketBuilder) -> None:
        if not isinstance(builder, PacketBuilder):
            raise PacketConfigurationError("packet builder must derive from PacketBuilder")
        self._packet_builders.append(builder)

    def clear_packet_builders(self) -> None:
        self._packet_builders.clear()

    # ------------------------------------------------------------------
    @staticmethod
    def _ensure_bytes(data: bytes | bytearray | memoryview | str) -> bytes:
        if isinstance(data, bytes):
            return data
        if isinstance(data, bytearray):
            return bytes(data)
        if isinstance(data, memoryview):
            return data.tobytes()
        if isinstance(data, str):
            return data.encode("utf-8")
        raise TypeError("payload must be bytes, bytearray, memoryview or str")

    def _build_header(self, raw_payload: bytes) -> tuple[bytes, List[Validator]]:
        if self._sof_builder is None:
            return b"", []
        header_bytes = self._sof_builder.build(raw_payload)
        if len(header_bytes) != self._sof_builder.size:
            raise PacketConfigurationError(
                "SOF builder returned an unexpected number of bytes"
            )
        validator = self._sof_builder.create_validator(header_bytes)
        return header_bytes, [validator]

    def _build_footer(self, raw_payload: bytes) -> tuple[bytes, List[Validator]]:
        footer_bytes = bytearray()
        validators: List[Validator] = []
        for builder in self._eof_builders:
            segment = builder.build(raw_payload)
            if len(segment) != builder.size:
                raise PacketConfigurationError(
                    f"builder {builder} returned an unexpected number of bytes"
                )
            footer_bytes.extend(segment)
            validators.append(builder.create_validator(segment))
        return bytes(footer_bytes), validators

    def _extract_header(
        self, packet: memoryview
    ) -> tuple[memoryview, List[Validator]]:
        if self._sof_builder is None:
            return packet, []
        size = self._sof_builder.size
        if len(packet) < size:
            raise PacketValidationError("packet is too small to contain the header")
        header = packet[:size]
        validator = self._sof_builder.create_validator(header.tobytes())
        return packet[size:], [validator]

    def _extract_footer(
        self, packet: memoryview
    ) -> tuple[memoryview, List[Validator]]:
        if not self._eof_builders:
            return packet, []
        validators: List[Validator] = []
        end = len(packet)
        for builder in reversed(self._eof_builders):
            size = builder.size
            if end < size:
                raise PacketValidationError("packet is too small to contain the footer")
            segment = packet[end - size : end]
            validators.append(builder.create_validator(segment.tobytes()))
            end -= size
        return packet[:end], list(reversed(validators))

    # ------------------------------------------------------------------
    def get_packet(self, payload: bytes | bytearray | memoryview | str) -> bytes:
        """Pack *payload* into a binary packet."""

        raw_payload = self._ensure_bytes(payload)
        header, header_validators = self._build_header(raw_payload)
        footer, footer_validators = self._build_footer(raw_payload)

        transformed = raw_payload
        for builder in self._packet_builders:
            transformed = builder.apply(transformed)

        body_length = len(transformed).to_bytes(4, byteorder="big")
        packet = bytearray()
        packet.extend(header)
        packet.extend(body_length)
        packet.extend(transformed)
        packet.extend(footer)

        # Validators are only used during unpacking but building them here
        # ensures that potential configuration errors are caught early.
        for validator in header_validators + footer_validators:
            validator(raw_payload)

        return bytes(packet)

    def unpack_data(self, packet: bytes | bytearray | memoryview) -> bytes:
        """Unpack *packet* and return the original payload."""

        if not isinstance(packet, (bytes, bytearray, memoryview)):
            raise TypeError("packet must be bytes-like")

        view = memoryview(packet if isinstance(packet, (bytes, bytearray)) else packet.tobytes())

        view, header_validators = self._extract_header(view)
        view, footer_validators = self._extract_footer(view)

        if len(view) < 4:
            raise PacketValidationError("packet does not contain body length information")
        body_length = int.from_bytes(view[:4], byteorder="big")
        body = view[4:]
        if len(body) != body_length:
            raise PacketValidationError(
                "body length mismatch: declared "
                f"{body_length}, actual {len(body)}"
            )

        transformed = body.tobytes()
        for builder in reversed(self._packet_builders):
            transformed = builder.revert(transformed)

        for validator in header_validators + footer_validators:
            validator(transformed)

        return transformed


__all__ = [
    "BinaryDataPacker",
    "CRC32Builder",
    "ConstantBuilder",
    "DeflateCompressor",
    "PacketConfigurationError",
    "PacketValidationError",
    "PayloadLengthBuilder",
    "XorCipher",
]
