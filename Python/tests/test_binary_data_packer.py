import sys
from pathlib import Path

import pytest

# Ensure the repository root (containing the ``Python`` package) is importable
ROOT = Path(__file__).resolve().parents[2]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from Python.src.BinaryDataPacker import (
    BinaryDataPacker,
    CRC32Builder,
    ConstantBuilder,
    DeflateCompressor,
    PacketConfigurationError,
    PacketValidationError,
    PayloadLengthBuilder,
    XorCipher,
)


@pytest.fixture
def sample_payload() -> bytes:
    return b"The quick brown fox jumps over the lazy dog"


def test_pack_and_unpack_roundtrip(sample_payload):
    packer = BinaryDataPacker()
    packer.set_sof_builder(ConstantBuilder(b"SOF"))
    packer.add_eof_builder(ConstantBuilder(b"EOF"))

    packet = packer.get_packet(sample_payload)
    assert packet.startswith(b"SOF")
    assert packet.endswith(b"EOF")

    unpacked = packer.unpack_data(packet)
    assert unpacked == sample_payload


def test_length_and_crc_validations(sample_payload):
    packer = BinaryDataPacker()
    packer.set_sof_builder(PayloadLengthBuilder())
    packer.add_eof_builder(CRC32Builder())

    packet = packer.get_packet(sample_payload)

    # Tamper with the checksum and ensure validation fails.
    tampered = bytearray(packet)
    tampered[-1] ^= 0x01
    with pytest.raises(PacketValidationError):
        packer.unpack_data(bytes(tampered))


def test_transformations_are_applied_and_reverted(sample_payload):
    packer = BinaryDataPacker()
    packer.set_sof_builder(ConstantBuilder(b"HDR"))
    packer.add_packet_builder(XorCipher(b"secret"))
    packer.add_packet_builder(DeflateCompressor(level=9))
    packer.add_eof_builder(CRC32Builder())

    packet = packer.get_packet(sample_payload)
    # The body should be compressed and encrypted, therefore different from the raw payload.
    assert sample_payload not in packet

    unpacked = packer.unpack_data(packet)
    assert unpacked == sample_payload


def test_configuration_errors():
    packer = BinaryDataPacker()

    with pytest.raises(PacketConfigurationError):
        packer.set_sof_builder("not a builder")  # type: ignore[arg-type]

    with pytest.raises(PacketConfigurationError):
        packer.add_eof_builder("not a builder")  # type: ignore[arg-type]

    with pytest.raises(PacketConfigurationError):
        packer.add_packet_builder("invalid")  # type: ignore[arg-type]

    with pytest.raises(PacketConfigurationError):
        ConstantBuilder("text")  # type: ignore[arg-type]

    with pytest.raises(PacketConfigurationError):
        XorCipher(b"")

    with pytest.raises(PacketConfigurationError):
        DeflateCompressor(level=42)


def test_body_length_mismatch_detection(sample_payload):
    packer = BinaryDataPacker()
    packet = packer.get_packet(sample_payload)

    tampered = bytearray(packet)
    tampered[3] ^= 0xFF  # corrupt the body length field

    with pytest.raises(PacketValidationError):
        packer.unpack_data(bytes(tampered))


def test_accepts_str_payloads():
    packer = BinaryDataPacker()
    payload = "payload with ünicode"
    packet = packer.get_packet(payload)
    unpacked = packer.unpack_data(packet)
    assert unpacked == payload.encode("utf-8")


def test_validator_runs_during_pack(sample_payload):
    packer = BinaryDataPacker()
    packer.set_sof_builder(ConstantBuilder(b"HDR"))

    packet = packer.get_packet(sample_payload)
    assert packet.startswith(b"HDR")


@pytest.mark.parametrize("bad_packet", [123, object(), None])
def test_unpack_requires_bytes_like(bad_packet):
    packer = BinaryDataPacker()
    with pytest.raises(TypeError):
        packer.unpack_data(bad_packet)  # type: ignore[arg-type]
