from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from Python.src.BinaryDataPacker import (
    BinaryDataPacker,
    ConstantBuilder,
    CRC32Builder,
    PayloadLengthBuilder,
    PacketValidationError,
)


class BinaryDataPackerTDD(unittest.TestCase):
    def setUp(self) -> None:
        self.packer = BinaryDataPacker()

    def test_round_trip_with_markers(self) -> None:
        self.packer.set_sof_builder(ConstantBuilder(b"HDR"))
        self.packer.add_eof_builder(ConstantBuilder(b"FTR"))
        payload = b"unit test"

        packet = self.packer.get_packet(payload)
        self.assertTrue(packet.startswith(b"HDR"))
        self.assertTrue(packet.endswith(b"FTR"))
        self.assertEqual(self.packer.unpack_data(packet), payload)

    def test_length_validation(self) -> None:
        self.packer.set_sof_builder(PayloadLengthBuilder())
        payload = b"validation"
        packet = self.packer.get_packet(payload)

        tampered = bytearray(packet)
        tampered[0] ^= 0x01
        with self.assertRaises(PacketValidationError):
            self.packer.unpack_data(bytes(tampered))

    def test_checksum_validation(self) -> None:
        self.packer.add_eof_builder(CRC32Builder())
        payload = b"checksum"
        packet = self.packer.get_packet(payload)

        tampered = bytearray(packet)
        tampered[-1] ^= 0xFF
        with self.assertRaises(PacketValidationError):
            self.packer.unpack_data(bytes(tampered))


if __name__ == "__main__":
    unittest.main()
