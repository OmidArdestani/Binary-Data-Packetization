# Packetization Module

## Overview

The Packetization Module is a versatile tool developed in C++, C#, and Python for packing raw data into a structured format suitable for transmission over Ethernet or other communication channels. The module adds a customizable header and footer to the raw data, supporting multiple types of headers and footers. Additionally, it provides options for encrypting and compressing the data body, enhancing the efficiency and security of data transmission.

## Features

- **Header and Footer Support:** The module allows the inclusion of headers and footers to the raw data, enabling customization based on specific requirements.

- **Encryption:** Data body encryption is available for secure transmission, providing an extra layer of protection for sensitive information.

- **Compression:** The module supports data compression, optimizing bandwidth usage and transmission efficiency.

- **Low Dependency:** This module depend on no external library.

- **Multi-language Support:** Developed in C++, C#, and Python, making it accessible and integrable into a variety of projects and platforms.

- **Data Streaming:** This modul support data streaming to gadering and detect header and extreact expected data.

## Getting Started

### Prerequisites

- [C++ Compiler](https://github.com/OmidArdestani/BinaryDataPacketization/tree/main/QtCpp)
- [.NET Framework](https://github.com/OmidArdestani/BinaryDataPacketization/tree/main/C%23) (for C#)
- [Python](https://github.com/OmidArdestani/BinaryDataPacketization/tree/main/Python) (for Python)
- [Java](https://github.com/OmidArdestani/BinaryDataPacketization/tree/main/Java) (for Java)

### Usage

 1. Create an Instance:
    * C++
    ```bash
    CBinaryDataPacketizer *packetizer = new BinaryDataPacketizer();
    ```
    * C#
    ```bash
    BinaryDataPacketizer packetizer = new BinaryDataPacketizer();
    ```
    * Python
    ```bash
    packetizer = BinaryDataPacketizer()
    ```
    * Java
    ```bash
    BinaryDataPacketizer packetizer = new BinaryDataPacketizer();
    ```
 2. Initialize:
    * C++
    ```bash
    packetizer->SetSOFBuilder(/*One Header Builder*/);
    packetizer->AddEOFBuilder(/*One Header Builder*/);
    packetizer->AddPacketBuilder(/*One Packet Builder*/);
    ```
    * C#
    ```bash
    packetizer.SetSOFBuilder(/*One Header Builder*/);
    packetizer.AddEOFBuilder(/*One Header Builder*/);
    packetizer.AddPacketBuilder(/*One Packet Builder*/);
    ```
    * Python
    ```bash
    packetizer.SetSOFBuilder(/*One Header Builder*/)
    packetizer.AddEOFBuilder(/*One Header Builder*/)
    packetizer.AddPacketBuilder(/*One Packet Builder*/)
    ```
    * Java
    ```bash
    packetizer.SetSOFBuilder(/*One Header Builder*/);
    packetizer.AddEOFBuilder(/*One Header Builder*/);
    packetizer.AddPacketBuilder(/*One Packet Builder*/);
    ```
 3. Pack Data:
    * C++
    ```bash
    packetizer->GetPacket(/*raw_data*/, /*raw_data_size*/, /*result*/, /*result_size*/);
    ```
    * C#
    ```bash
    byte[] result = packetizer.SetSOFBuilder(/*raw_data*/);
    ```
    * Python
    ```bash
    result = packetizer.SetSOFBuilder(/*raw_data*/)
    ```
    * Java
    ```bash
    byte[] result = packetizer.SetSOFBuilder(/*raw_data*/);
    ```    
 5. Unpack Data:
    * C++
    ```bash
    packetizer->UnpackData(/*packed_data*/, /*packed_data_size*/, /*result*/, /*result_size*/);
    ```
    * C#
    ```bash
    byte[] result = packetizer.UnpackData(/*packed_data*/);
    ```
    * Python
    ```bash
    result = packetizer.UnpackData(/*packed_data*/)
    ```
    * Java
    ```bash
    byte[] result = packetizer.UnpackData(/*packed_data*/);
    ```

### Advanced Usage

 * Customizing Headers and Footers: The module provides flexibility in defining header and footer types. Explore the documentation for details on customizing these components based on your application's needs.
 * Configuring Encryption: To enable encryption, set the encryption parameters using the provided API. Refer to the documentation for a comprehensive guide on configuring encryption.
 * Optimizing Compression: Fine-tune the compression settings to balance between compression ratio and computational overhead. The documentation contains information on optimizing compression for various scenarios.

## Library Class Diagram (UML)

![Binary Data Packetization Class Diagram](https://github.com/OmidArdestani/BinaryDataPacketization/blob/main/Document/DataPacker.jpg)

Clone the repository to your local machine:
```bash
git clone https://github.com/OmidArdestani/BinaryDataPacketization.git
```
