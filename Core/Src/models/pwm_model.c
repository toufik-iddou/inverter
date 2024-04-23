/*
 * pwm_model.c
 *
 *  Created on: Mar 17, 2024
 *      Author: IDDOU Toufik Islem , BOUKHENNOUFA Mohamed Anis
 */


#include <config/timer_config.h>
#include "controllers/pid_controller.h"
#include "models/pwm_model.h"
#include "system_variables.h"
#include "models/acquisition_model.h"

float duty = 0;
Acquisition_Data data;
static float calculate_Duty_Cycle(float V_ref);
static void PWM_Genearte_GPIO(float duty_cycle);

void PWM_Generate(void){
	data = Start_Data_Conversion();
//	float V_ref = calculate_PID_V_ref(data.If,data.Io,data.Vo);
//	float duty_cycle = calculate_Duty_Cycle(V_ref);
//	PWM_Genearte_GPIO(duty_cycle);
}

void PWM_Model_Init(void){
	init_pid_controller();
}

static float calculate_Duty_Cycle(float V_ref){
		return V_ref*PWM_TIM_period/V_IN;
}

static void PWM_Genearte_GPIO(float duty_cycle){
	duty=duty_cycle;
//	TIM1->CCR1 = TIM1->CCR2 == 0 ? (uint16_t) TIM1->CCR3/2 : (uint16_t) TIM1->CCR2/2;
//	TIM1->CCR2 = duty_cycle>0 ? (int16_t)duty_cycle:0;
//	TIM1->CCR3 = duty_cycle>0 ? 0:-(int16_t)duty_cycle;

}


