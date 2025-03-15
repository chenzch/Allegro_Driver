//---------------------------------------------------------------------------------------------------------------------
//
// WTMEC CORPORATION CONFIDENTIAL
// ________________________________
//
// [2025] Wtmec Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Wtmec Corporation owns all rights to this work and intends to maintain it in confidence to
// preserve its trade secret status. Wtmec Corporation reserves the right, under the copyright
// laws of the United States or those of any other country that may have jurisdiction, to protect
// this work as an unpublished work, in the event of an inadvertent or deliberate unauthorized
// publication. Wtmec Corporation also reserves its rights under all copyright laws to protect
// this work as a published work, when appropriate. Those having access to this work may not copy
// it, use it, modify it, or disclose the information contained in it without the written
// authorization of Wtmec Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "A81415.h"

uint8_t calculate_crc(uint32_t data) {
    // Polynomial: 0x12 (x^5 + x^2 + 1) in binary: 10010
    uint8_t polynomial = 0x12;
    // Initial CRC value: 11111b
    uint8_t crc = 0x1F;

    // Extract data from bit 30 to bit 5
    data = (data >> 5) & 0x3FFFFFF;

    // Process each bit from the most significant to the least significant
    for (int i = 26; i >= 0; i--) {
        // Check if the most significant bit of CRC is 1
        uint8_t msb = (crc & 0x10) ? 1 : 0;
        // Left shift CRC by 1 bit
        crc <<= 1;
        // Add the next bit from data into CRC
        crc |= (data >> i) & 1;
        // If the previous most significant bit was 1, XOR with the polynomial
        if (msb) {
            crc ^= polynomial;
        }
    }

    return crc & 0x1F;
}

uint32_t A81415BuildCommand(uint8_t Command, uint8_t Address, uint16_t Data) {
    uint32_t request;
    request = ((uint32_t)Command) << 30;
    request |= ((uint32_t)Address) << 25;
    request |= ((uint32_t)Data) << 6;
    request |= calculate_crc(request);
    return request;
}

uint8_t A81415CheckCRC(uint32_t Data) {
    uint8_t crc = calculate_crc(Data);
    if (crc == A81415_RES_CRC(Data)) {
        return 1;
    } else {
        return 0;
    }
}

#include "../CH347/spi.h"

void A81415Transfer(uint32_t Size, uint32_t* Commands) {
    uint32_t* pResponse = Commands;
    spi_transfer(*(Commands++));
    for (uint32_t i = 1; i < Size; ++i) {
        *(pResponse++) = spi_transfer(*(Commands++));
    }
    *(pResponse++) = spi_transfer(A81415BuildCommand(A81415_CMD_READ, 0, 0));
}
