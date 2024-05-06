/*
 * config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: iddou
 */


#include"config/config.h"

void System_Init(void){
HAL_Init();
System_Clock_Init();
GPIO_Init();
DMA_Init();
Real_Time_Clock_Init();
TIM_Init();
ADC_Init();
DAC_Init();
}

void System_Start(void){
TIM_Start();
DAC_Start();
}

