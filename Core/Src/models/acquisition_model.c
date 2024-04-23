/*
 * acquisition_model.c
 *
 *  Created on: Mar 18, 2024
 *      Author: iddou
 */
#include "models/acquisition_model.h"
#include "config/adc_config.h"

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
//	data.If=(If_input_voltage);
//	data.Io=(Io_input_voltage);
//	data.Vo=(Vo_input_voltage);
	return data;
}



static float Calculate_If(float input_voltage){
	return  24.606*input_voltage - 61.613;
;
}

static float Calculate_Io(float input_voltage){
	return  24.606*input_voltage - 61.613;
}

static float Calculate_Vo(float input_voltage){
	return 514.98*input_voltage - 647.08;
}


static float Input_Voltage(enum ADC_CHANNELS_ENUM ADC_CHANNEL){
	uint16_t resolution=1023;
	return buffer_adc[ADC_CHANNEL]*3.3/resolution;

}


