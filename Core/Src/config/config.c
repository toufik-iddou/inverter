/*
 * config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: iddou
 */


#include"config/adc_config.h"
#include"config/pwm_config.h"
#include"config/config.h"
#include"config/dma_config.h"
#include"config/gpio_config.h"

void system_Init(void){
HAL_Init();

GPIO_Init();

DMA_Init();

PWM_Init();
PWM_Start();

ADC_Init();
ADC_Start();
}
