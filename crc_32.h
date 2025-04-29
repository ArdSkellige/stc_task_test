#ifndef CRC_32_H
#define CRC_32_H

#include <cstdint>
#include <array>
#include <cstddef>

namespace Crc
{
    static constexpr uint32_t POLYNOM = 0xEDB88320; // ~0x04C11DB7
    static constexpr size_t TABLE_SIZE = 256;
    static constexpr uint8_t BYTE_SIZE = 8;

    constexpr auto GetTableValue();
    uint32_t Count(const char* byteOrderP, size_t length);
}

#endif // CRC_32_H
