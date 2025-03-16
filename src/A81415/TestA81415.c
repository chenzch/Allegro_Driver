#include <stdio.h>
#include <stdint.h>
#include "../spi.h"
#include "A81415.h"

int main() {
    uint32_t Commands[5];

    spi_init();

    Commands[0] = A81415BuildCommand(A81415_CMD_WRITE, A81415_REG_READBACK, 0x1234);
    Commands[1] = A81415BuildCommand(A81415_CMD_WRITE, A81415_REG_READBACK, 0x5678);
    Commands[2] = A81415BuildCommand(A81415_CMD_WRITE, A81415_REG_READBACK, 0xABCD);
    Commands[3] = A81415BuildCommand(A81415_CMD_WRITE, A81415_REG_READBACK, 0x0000);
    Commands[4] = A81415BuildCommand(A81415_CMD_WRITE, A81415_REG_READBACK, 0xFFFF);

    A81415Transfer(sizeof(Commands) / sizeof(Commands[0]), &Commands[0]);

    //for (int i = 0; i < sizeof(Commands) / sizeof(Commands[0]); ++i)
    {
        uint32_t response = Commands[0];
        printf("Command %d: 0x%08X\n", 0, response);
        printf("Address: %d\n", A81415_RES_ADDRESS(response));
        printf("Frame Count: %d\n", A81415_RES_FRAMECOUNT(response));
        printf("Fault Flag: %d\n", A81415_RES_FAULTFLAG(response));
        printf("Data: 0x%04X\n", A81415_RES_DATA(response));
        printf("Data OK: %d\n", A81415_RES_DATAOK(response));
        printf("CRC: %d\n", A81415_RES_CRC(response));
        uint16_t data;
        uint8_t  address;
        if (A81415GetResponse(response, &address, &data)) {
            printf("Address: %d\n", address);
            printf("Data: 0x%04X\n", data);
        } else {
            printf("Response failed\n");
        }
    }

    spi_deinit();
}
