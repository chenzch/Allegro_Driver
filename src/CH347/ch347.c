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
#include <stdio.h>
#include "spi.h"
#include <windows.h>
#include "CH347DLL.h"

#pragma comment(lib, "..\\CH347\\CH347DLL.lib")

HANDLE hDevice = INVALID_HANDLE_VALUE;

void spi_init() {
    hDevice = CH347OpenDevice(0);
    if (hDevice == INVALID_HANDLE_VALUE) {
        printf("CH347OpenDevice failed\n");
    }

    mSpiCfgS spiCfg;
    spiCfg.iMode                 = 3;
    spiCfg.iClock                = 6;
    spiCfg.iByteOrder            = 1;
    spiCfg.iSpiWriteReadInterval = 5;
    spiCfg.iSpiOutDefaultData    = 0;
    spiCfg.iChipSelect           = 0x81;
    spiCfg.CS1Polarity           = 0;
    spiCfg.CS2Polarity           = 0;
    spiCfg.iIsAutoDeativeCS      = 1;
    spiCfg.iActiveDelay          = 5;
    spiCfg.iDelayDeactive        = 5;
    CH347SPI_Init(0, &spiCfg);
    CH347SPI_SetDataBits(0, 0);
}

void spi_deinit() {
    if (hDevice == INVALID_HANDLE_VALUE) {
        CH347CloseDevice(0);
        hDevice = INVALID_HANDLE_VALUE;
    }
}

static void DumpBits(uint32_t data) {
    for (int i = 31; i >= 0; --i) {
        printf("%2d ", i);
        if (0 == (i & 7)) {
            printf("| ");
        }
    }
    printf("\n");
    for (int i = 31; i >= 0; --i) {
        printf(" %d ", (data & (1 << i) ? 1 : 0));
        if (0 == (i & 7)) {
            printf("| ");
        }
    }
    printf("\n");
}

static uint32_t swapbyte(uint32_t data) {
    return ((data & 0xFF) << 24) | ((data & 0xFF00) << 8) | ((data & 0xFF0000) >> 8) |
           ((data & 0xFF000000) >> 24);
}

uint32_t spi_transfer(uint32_t data) {
    uint32_t result = swapbyte(data);
    if (hDevice != INVALID_HANDLE_VALUE) {
        CH347SPI_WriteRead(0, 0x80, 4, &result);
    } else {
        result = swapbyte(0b10111100100101101001011010110101);
    }
    result = swapbyte(result);
    printf("SPI send: 0x%08X, receive: 0x%08X\n", data, result);
    DumpBits(data);
    DumpBits(result);
    return result;
}
