/*
 * clock_config.h
 *
 *  Created on: Mar 19, 2024
 *      Author: iddou
 */

#ifndef INC_CONFIG_CLOCK_CONFIG_H_
#define INC_CONFIG_CLOCK_CONFIG_H_

/* Private includes ----------------------------------------------------------*/
#include "stm32f4xx_hal.h"
/* Private Macros ----------------------------------------------------------*/

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/

/* Private Functions ----------------------------------------------------------*/
void Real_Time_Clock_Init(void);
void System_Clock_Init(void);

#endif /* INC_CONFIG_CLOCK_CONFIG_H_ */
