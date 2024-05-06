/*
 * dac_config.c
 *
 *  Created on: Apr 20, 2024
 *      Author: iddou
 */


#include "config/dac_config.h"
#include "utils/error_handler.h"


static uint16_t  DAC_Get_Voltage_Value(float voltage);
static void DAC_Out_Init(void);

DAC_HandleTypeDef hdac;


void DAC_Init(void){
	DAC_Out_Init();
}

void DAC_Start(void){
	HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
}

void DAC_SetValue(uint32_t val){
	 HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2,DAC_ALIGN_12B_R,val);
}

void DAC_SetVoltage(float voltage){
	 uint32_t vlotage_val= DAC_Get_Voltage_Value(voltage);
	 HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2,DAC_ALIGN_12B_R,vlotage_val);
}

static uint16_t DAC_Get_Voltage_Value(float voltage){
	return  (uint16_t)(voltage*4096)/3.3;
}

/**
  * @brief DAC Initialization Function
  * @param None
  * @retval None
  */
static void DAC_Out_Init(void)
{
  DAC_ChannelConfTypeDef sConfig = {0};

  /** DAC Initialization
  */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    Error_Handler();
  }

  /** DAC channel OUT2 config
  */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
}
