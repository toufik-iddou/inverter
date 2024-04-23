/*
 * dac_config.h
 *
 *  Created on: Apr 20, 2024
 *      Author: iddou
 */

#ifndef INC_CONFIG_DAC_CONFIG_H_
#define INC_CONFIG_DAC_CONFIG_H_


/* Private includes ----------------------------------------------------------*/
#include "stm32f4xx_hal.h"
/* Private Macros ----------------------------------------------------------*/

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/

/* Private Functions ----------------------------------------------------------*/
void DAC_Init(void);
void DAC_Start(void);
void DAC_SetValue(float val);


#endif /* INC_CONFIG_DAC_CONFIG_H_ */
