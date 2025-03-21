/*
 * driver_led.c
 *
 *  Created on: Mar 13, 2025
 *      Author: lcroce
 */
#include "driver_led.h"

uint8_t MCP23S17_SPI_Transmit(uint8_t data) {
	uint8_t receivedData;
    HAL_SPI_TransmitReceive(&hspi3, &data, &receivedData, 1, HAL_MAX_DELAY);
    return receivedData;
}

void MCP23S17_WriteRegister(uint8_t reg, uint8_t value) {
    MCP23S17_CS_LOW();
    MCP23S17_SPI_Transmit(0x40);  // Adresse + écriture (0x40 = 0b01000000)
    MCP23S17_SPI_Transmit(reg);
    MCP23S17_SPI_Transmit(value);
    MCP23S17_CS_HIGH();
}
