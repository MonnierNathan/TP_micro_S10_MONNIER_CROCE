/*
 * sgtl5000.c
 *
 *  Created on: Apr 9, 2025
 *      Author: lcroce
 */

#include "sgtl5000.h"

static void write_register(I2C_HandleTypeDef *hi2c, uint16_t reg, uint16_t value) {
    uint8_t data[4];
    data[0] = (reg >> 8) & 0xFF;  // MSB reg
    data[1] = reg & 0xFF;         // LSB reg
    data[2] = (value >> 8) & 0xFF;  // MSB value
    data[3] = value & 0xFF;         // LSB value

    HAL_I2C_Master_Transmit(hi2c, SGTL5000_I2C_ADDR, data, 4, HAL_MAX_DELAY);
}

void init_sgtl(I2C_HandleTypeDef *hi2c) {
    write_register(hi2c, CHIP_ANA_POWER,      0x4060);
    write_register(hi2c, CHIP_LINREG_CTRL,    0x006C);
    write_register(hi2c, CHIP_REF_CTRL,       0x01F2);
    write_register(hi2c, CHIP_LINE_OUT_CTRL,  0x0322);
    write_register(hi2c, CHIP_SHORT_CTRL,     0x4446);
    write_register(hi2c, CHIP_ANA_CTRL,       0x0137);
    write_register(hi2c, CHIP_DIG_POWER,      0x0073);
    write_register(hi2c, CHIP_LINE_OUT_VOL,   0x1D1D);
    write_register(hi2c, CHIP_CLK_CTRL,       0x0004);
    write_register(hi2c, CHIP_I2S_CTRL,       0x0130);
    write_register(hi2c, CHIP_ADCDAC_CTRL,    0x0000);
    write_register(hi2c, CHIP_DAC_VOL,        0x3C3C);
}

