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
#define ADC_CHANNELS_LENGHT 3
/* Private Constants ----------------------------------------------------------*/

/* Private Enums ----------------------------------------------------------*/
enum ADC_CHANNELS_ENUM{
	If_CHANNEL,
	Io_CHANNEL,
	Vo_CHANNEL,
};
/* External Variables ----------------------------------------------------------*/
extern uint16_t buffer_adc[ADC_CHANNELS_LENGHT];
/* Private Functions ----------------------------------------------------------*/
void ADC_Init(void);
void ADC_Start(void);

#endif /* INC_CONFIG_ADC_CONFIG_H_ */
