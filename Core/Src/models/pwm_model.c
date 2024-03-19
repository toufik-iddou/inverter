///*
// * pwm_model.c
// *
// *  Created on: Mar 17, 2024
// *      Author: IDDOU Toufik Islem , BOUKHENNOUFA Mohamed Anis
// */
//
//
//#include "controllers/pid_controller.h"
//#include "models/pwm_model.h"
//#include "config/pwm_config.h"
//#include "system_variables.h"
//
//static int16_t calculate_Duty_Cycle(float V_ref){
//		return V_ref*PWM_TIM_period/V_REF_MAX;
//}
//
//static void PWM_Genearte_GPIO(int16_t duty_cycle){
//	pwm1 = duty_cycle>0 ? duty_cycle:0;
//	pwm2 = duty_cycle>0 ? 0:-duty_cycle;
//}
//
//
//void PWM_Generate(void){
//	float V_ref = calculate_PID_V_ref(0,0,0);
//	int16_t duty_cycle = calculate_Duty_Cycle(V_ref);
//	PWM_Genearte_GPIO(duty_cycle);
//
//
//}
