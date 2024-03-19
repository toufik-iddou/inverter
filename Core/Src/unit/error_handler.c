/*
 * error_handler.c
 *
 *  Created on: Mar 17, 2024
 *      Author: iddou
 */
#include "utils/error_handler.h"
#include "stm32f4xx_hal.h"

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
