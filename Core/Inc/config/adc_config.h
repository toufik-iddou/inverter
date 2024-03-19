/*
 * adc_config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: iddou
 */

#ifndef INC_CONFIG_ADC_CONFIG_H_
#define INC_CONFIG_ADC_CONFIG_H_


/* Private includes ----------------------------------------------------------*/
#include "stm32f4xx_hal.h"
/* Private Macros ----------------------------------------------------------*/
#define DMA_LENGHT 3
/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/
extern uint16_t buffer_adc[DMA_LENGHT];
/* Private Functions ----------------------------------------------------------*/
void ADC_Init(void);
void ADC_Start(void);

#endif /* INC_CONFIG_ADC_CONFIG_H_ */
