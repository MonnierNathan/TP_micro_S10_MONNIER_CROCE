/*
 * driver_led.h
 *
 *  Created on: Mar 13, 2025
 *      Author: lcroce
 */
#ifndef SRC_DRIVER_LED_H_
#define SRC_DRIVER_LED_H_

#endif /* SRC_DRIVER_LED_H_ */
/* USER CODE BEGIN Includes */

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "spi.h"
#define MCP23S17_CS_LOW()   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET)
#define MCP23S17_CS_HIGH()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET)
void MCP23S17_WriteRegister(uint8_t reg, uint8_t value);
uint8_t MCP23S17_SPI_Transmit(uint8_t data);
//void setLed(bool port, uint8_t pin_number , bool sens, bool keep);
void init();
