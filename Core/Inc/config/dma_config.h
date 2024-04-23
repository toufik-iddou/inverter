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
/* Private Functions ----------------------------------------------------------*/
void DMA_Init(void);


#endif /* INC_CONFIG_DMA_CONFIG_H_ */
