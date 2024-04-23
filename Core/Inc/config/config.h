/*
 * config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: iddou
 */

#ifndef INC_CONFIG_CONFIG_H_
#define INC_CONFIG_CONFIG_H_


#include <config/timer_config.h>
#include"config/adc_config.h"
#include"config/dma_config.h"
#include"config/gpio_config.h"
#include"config/clock_config.h"
#include "config/dac_config.h"

void System_Init(void);
void System_Start(void);

#endif /* INC_CONFIG_CONFIG_H_ */
