/*
 * dma_config.h
 *
 *  Created on: Mar 18, 2024
 *      Author: iddou
 */

#ifndef INC_CONFIG_DMA_CONFIG_H_
#define INC_CONFIG_DMA_CONFIG_H_

/* Private includes ----------------------------------------------------------*/
#include "stm32f4xx_hal.h"
/* Private Macros ----------------------------------------------------------*/

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern DMA_HandleTypeDef hdma_adc2;
extern DMA_HandleTypeDef hdma_adc3;

extern DMA_HandleTypeDef hdma_tim8_ch1;
extern DMA_HandleTypeDef hdma_tim8_ch3;
/* Private Functions ----------------------------------------------------------*/
void DMA_Init(void);


#endif /* INC_CONFIG_DMA_CONFIG_H_ */
