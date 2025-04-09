/*
 * sgtl5000.h
 *
 *  Created on: Apr 9, 2025
 *      Author: lcroce
 */

#ifndef SRC_SGTL5000_H_
#define SRC_SGTL5000_H_

#include "main.h"

#define SGTL5000_I2C_ADDR      0x14 << 1  // Adresse 7 bits décalée pour HAL

#define CHIP_ANA_POWER         0x0020
#define CHIP_LINREG_CTRL       0x0026
#define CHIP_REF_CTRL          0x0028
#define CHIP_LINE_OUT_CTRL     0x002C
#define CHIP_SHORT_CTRL        0x002E
#define CHIP_ANA_CTRL          0x002A
#define CHIP_DIG_POWER         0x0002
#define CHIP_LINE_OUT_VOL      0x0022
#define CHIP_CLK_CTRL          0x0004
#define CHIP_I2S_CTRL          0x0006
#define CHIP_ADCDAC_CTRL       0x000E
#define CHIP_DAC_VOL           0x0010

void init_sgtl(I2C_HandleTypeDef *hi2c);

#endif /* SRC_SGTL5000_H_ */


