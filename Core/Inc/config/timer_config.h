/*
 * pwm_config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: iddou
 */

#ifndef INC_CONFIG_TIMER_CONFIG_H_
#define INC_CONFIG_TIMER_CONFIG_H_


/* Private includes ----------------------------------------------------------*/
#include <stdint.h>
#include "stm32f4xx_hal.h"
/* Private Macros ----------------------------------------------------------*/
#define   	TS	0.00005f
#define		PWM_TIM_period	8400-1

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
/* Private Functions ----------------------------------------------------------*/
void TIM_Init(void);
void TIM_Start(void);

#endif /* INC_CONFIG_TIMER_CONFIG_H_ */
