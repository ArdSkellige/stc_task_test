#include "crc_32.h"

constexpr auto Crc::GetTableValue()
{
    std::array<uint32_t, TABLE_SIZE> crcValTable = { 0 };

    for(size_t i = 0; i < TABLE_SIZE; i++)
    {
        uint32_t crc = i;
        for(size_t j = 0; j < BYTE_SIZE; j++)
        {
            if(crc & 1)
            {
                crc = (crc >> 1) ^ POLYNOM;
            }
            else
            {
                crc = (crc >> 1);
            }
        }
        crcValTable[i] = crc;
    }
    return crcValTable;
}

uint32_t Crc::Count(const char* byteOrderP, size_t length)
{
    const auto  tableValue = GetTableValue();
    const auto initial = 0xFFFFFFFF;
    const auto xorOut = 0xFFFFFFFF;
    uint32_t crc = initial;
    while(length)
    {
        crc = tableValue[(crc ^ *byteOrderP) & 0xFF] ^ (crc >> 8);
        byteOrderP++;
        length--;
    }
    return crc ^ xorOut;
}
