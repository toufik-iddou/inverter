/*
 * pwm_config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: iddou
 */

#ifndef INC_CONFIG_PWM_CONFIG_H_
#define INC_CONFIG_PWM_CONFIG_H_


/* Private includes ----------------------------------------------------------*/
#include <stdint.h>
#include "stm32f4xx_hal.h"
/* Private Macros ----------------------------------------------------------*/
#define   	TS	0.00005
#define		PWM_TIM_period	8400-1

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/
extern uint16_t pwm1;
extern uint16_t pwm2;
extern TIM_HandleTypeDef htim8;
/* Private Functions ----------------------------------------------------------*/
void PWM_Init(void);
void PWM_Start(void);

#endif /* INC_CONFIG_PWM_CONFIG_H_ */
