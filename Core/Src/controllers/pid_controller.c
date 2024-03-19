/*
 * pid_controller.c
 *
 *  Created on: Mar 16, 2024
 *      Author: IDDOU Toufik Islem , BOUKHENNOUFA Mohamed Anis
 */

/* Private includes ----------------------------------------------------------*/
#include "controllers/pid_controller.h"
#include "models/pwm_model.h"
#include <stdbool.h>
/* Private Constants ----------------------------------------------------------*/
#ifdef PRODUCTION_MOD
const float sin_V_ref[101]={};
#endif
/* Private Variables ----------------------------------------------------------*/
#ifdef DEVELOPMENT_MODE
float sin_V_ref[101];
#endif
uint8_t sin_ref_index=0;
bool sin_ref_signe=false;
float sum_V_error=0;
/* Private Functions ----------------------------------------------------------*/
/*	initialization	*/
#ifdef PRODUCTION_MODE
void init_sin_V_ref();
#endif
void pid_controller_Init();
/*	calculation	*/
static void caclulate_sin_ref_index(void);
static float calculate_V_error(float Vo);
static float calculate_if_ref(float Io,float Vo,float V_error);
static float calculate_V_ref(float Vo,float If,float I_ref);

/*
 * code begin
 */

#ifdef DEVELOPMENT_MODE
static void init_sin_V_ref(){
 	for ( int i=0;i<=N_ECH/4;i++){
 		sin_V_ref[i]=(V_REF_MAX*sin(i*2*PI/N_ECH));
 	}
}
#endif

void init_pid_controller(){

#ifdef DEVELOPMENT_MODE
	init_sin_V_ref();
#endif

}


static void caclulate_sin_ref_index(){
	static int8_t sin_ref_index_direction=1;
	if(sin_ref_index==0){
		sin_ref_index_direction = 1;
		sin_ref_signe=!sin_ref_signe;
	}
	if(sin_ref_index==100){
		sin_ref_index_direction = -1;
	}
	sin_ref_index+=sin_ref_index_direction;
}

static float calculate_V_error(float Vo){
	float error = (sin_V_ref[sin_ref_index])-Vo;
	sum_V_error += error;
	return error;
}

static float calculate_if_ref(float Vo,float Io,float V_error){	// voltage loop
	return (Io + kP_E*V_error + kI_E*TS*sum_V_error);
}

static float calculate_V_ref(float Vo,float If,float I_ref){	// current loop
	return (Vo + kP_I*(I_ref - If));
}

float calculate_PID_V_ref(float If,float Io,float Vo){
	caclulate_sin_ref_index();
	float V_error = calculate_V_error(Vo);
	float I_ref = calculate_if_ref(Vo,Io,V_error);
	float V_ref =  calculate_V_ref(Vo,If,I_ref);
	return V_ref;
	//return (uint16_t) (PWM_TIM_period*V_ref/V_ref_max);
}
