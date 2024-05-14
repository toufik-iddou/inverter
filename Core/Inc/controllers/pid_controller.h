/*
 * pid_controller.c
 *
 *  Created on: Mar 16, 2024
 *      Author: IDDOU Toufik Islem , BOUKHENNOUFA Mohamed Anis
 */

#ifndef INC_CONTROLLERS_PID_CONTROLLER_H_
#define INC_CONTROLLERS_PID_CONTROLLER_H_

/* Private includes ----------------------------------------------------------*/
#include <config/timer_config.h>
#include <math.h>
#include <stdint.h>
#include "system_variables.h"

/* Private Macros ----------------------------------------------------------*/
#define   	kP_E	0.1839f
#define   	kI_E	183.8707f
#define   	kP_I	6.2831f

#ifdef DEVELOPMENT_MODE
#define		N_ECH 1/(TS*V_REF_FREQUENY)
#endif
#ifdef PRODUCTION_MODE
#define		N_ECH 400
#endif

#define   	WINDUP_MAX 	1000
#define   	WINDUP_MIN 	-1000

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/
#ifdef PRODUCTION_MODE
extern const float sin_V_ref[400];
#endif
#ifdef DEVELOPMENT_MODE
extern float sin_V_ref[400];
#endif
/* Private Functions ----------------------------------------------------------*/
/*	initialization	*/
void init_pid_controller();
/*	calculation	*/
float calculate_PID_V_ref(float Vo,float If,float I_ref);


#endif /* INC_CONTROLLERS_PID_CONTROLLER_H_ */
