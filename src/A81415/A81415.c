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
#include "../spi.h"
#include "A81415.h"

/**
 * @brief Calculates a 5-bit CRC for the given data.
 *
 * Uses the polynomial 0x12 (x^5 + x^2 + 1) with an initial CRC value of 0x1F.
 *
 * @param data The input data for the CRC calculation.
 * @return The computed 5-bit CRC.
 */
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

/**
 * @brief Builds a command word for the A81415 device.
 *
 * Constructs a 32-bit command combining command, address, data, and CRC.
 *
 * @param Command The command type (read or write).
 * @param Address The target register address.
 * @param Data The data to be transmitted.
 * @return The complete 32-bit command.
 */
uint32_t A81415BuildCommand(uint8_t Command, uint8_t Address, uint16_t Data) {
    uint32_t request;
    request = ((uint32_t)Command) << 30;
    request |= ((uint32_t)Address) << 25;
    request |= ((uint32_t)Data) << 6;
    request |= calculate_crc(request);
    return request;
}

/**
 * @brief Processes the response from the A81415 device.
 *
 * Validates the response by verifying its CRC and extracts the address and data.
 *
 * @param Response The 32-bit response word.
 * @param pAddress Pointer to store the command address.
 * @param pData Pointer to store the extracted data.
 * @return Non-zero if the response is valid; otherwise, zero.
 */
uint8_t A81415GetResponse(uint32_t Response, uint8_t *pAddress, uint16_t *pData) {
    uint8_t crc = calculate_crc(Response);
    if (crc != A81415_RES_CRC(Response)) {
        return 0;
    }
    if (0 == (Response & (1 << A81415_RES_FAULTFLAG_OFFSET))) {
        return 0;
    }
    if (pAddress) {
        if (A81415_RES_DATAOK(Response) == 0) {
            *pAddress = A81415_REG_STATUS0;
        } else {
            *pAddress = A81415_RES_ADDRESS(Response);
        }
    }
    if (pData) {
        *pData = A81415_RES_DATA(Response);
    }
    return 1;
}

/**
 * @brief Transfers a sequence of SPI commands to the A81415 device.
 *
 * Initiates the SPI transfer of the first command, then continues for the rest.
 *
 * @param Size The number of commands to transfer.
 * @param Commands Pointer to the commands array.
 */
void A81415Transfer(uint32_t Size, uint32_t* Commands) {
    uint32_t* pResponse = Commands;
    spi_transfer(*(Commands++));
    for (uint32_t i = 1; i < Size; ++i) {
        *(pResponse++) = spi_transfer(*(Commands++));
    }
    *(pResponse++) = spi_transfer(A81415BuildCommand(A81415_CMD_READ, 0, 0));
}
