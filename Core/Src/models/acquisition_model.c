/*
 * acquisition_model.c
 *
 *  Created on: Mar 18, 2024
 *      Author: iddou
 */
#include "models/acquisition_model.h"
#include "config/adc_config.h"
#include "config/dac_config.h"
#include <stdbool.h>
#include <math.h>
/* Private Functions ----------------------------------------------------------*/
static float Input_Voltage(enum ADC_CHANNELS_ENUM ADC_CHANNEL);
static float Calculate_Vo(float input_voltage);
static float Calculate_Io(float input_voltage);
static float Calculate_If(float input_voltage);

/*
 *
*/





Acquisition_Data Start_Data_Conversion(void){
	Acquisition_Data data;
	float If_input_voltage =Input_Voltage(If_CHANNEL);
	float Io_input_voltage =Input_Voltage(Io_CHANNEL);
	float Vo_input_voltage =Input_Voltage(Vo_CHANNEL);
	data.If=Calculate_If(If_input_voltage);
	data.Io=Calculate_Io(Io_input_voltage);
	data.Vo=Calculate_Vo(Vo_input_voltage);

//	vRms=vRms+data.Vo*data.Vo;
//	vMoy+=data.Vo;
//	iRms++;
//
//	if(vMax<data.Vo)
//	{
//		vMax=data.Vo;
//	}
//	if(vMax2>data.Vo)
//		{
//		vMax2=data.Vo;
//		}
//
//	if(iRms==399){
//		pvRms=sqrt(vRms/iRms);
//		pvMoy=vMoy/iRms;
//		pMax2=vMax2;
//		pMax=vMax;
//		vMax=0;
//		vMoy=0;
//		vRms=0;
//		iRms=0;
//		vMax2=0;
//	}
	//data.If=(If_input_voltage);
	//data.Io=(Io_input_voltage);

//	data.Vo=(Vo_input_voltage);
	DAC_SetValue(2);
	return data;
}



static float Calculate_If(float input_voltage){
	return  0.979*(0.0317*input_voltage - 16.102)-0.1012;
;
}

static float Calculate_Io(float input_voltage){
	return 25.04865*input_voltage -62.876915;
}

static float Calculate_Vo(float input_voltage){
	return 300*(1.03*(493.34*(input_voltage-1.256)-9)+5.5)/297;
}


static float Input_Voltage(enum ADC_CHANNELS_ENUM ADC_CHANNEL){
	uint16_t resolution=1023;
	return buffer_adc[ADC_CHANNEL]*3.3/resolution;

}


