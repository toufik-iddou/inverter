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
#include <stdlib.h>
#include "config/dac_config.h"
#include "models/if_observer_model.h"


#define LABO_SENSORS
//#define OUR_SENSORS

float duty = 0;
Acquisition_Data data;
static float calculate_Duty_Cycle(float V_ref);
static void PWM_Genearte_GPIO(float duty_cycle);
int16_t pwm  = 0;

float V_ref=0;
float Io;
float If;
float If_calman;
float Vo;


float vMax=0;
float vMax2=0;
float pMax=0;
float pMax2=0;
float vRms=0;
int iRms=0;
float pvRms=0;
float vMoy=0;
float pvMoy=0;

float IMax=0;
float IMax2=0;
float IpMax=0;
float IpMax2=0;
float IRms=0;
float pIRms=0;
float IMoy=0;
float pIMoy=0;


float IoMax=0;
float IoMax2=0;
float IopMax=0;
float IopMax2=0;
float IoRms=0;
float pIoRms=0;
float IoMoy=0;
float pIoMoy=0;
float kp_i=6.2831;
float t=0;
float I_ref=0;
float a=1;
void PWM_Generate(void){
	static float x[2]={0,0},p[2][2]={{1,0},{0,1}};
	float b[2][2],k[2],y[2];
	static int i =0;
	static float sum_error =0.0f;

/*	acquisition	*/
#ifdef LABO_SENSORS
	If= 0.0375f * buffer_adc[0] - 19.01f;
	Io= 0.036f* buffer_adc[1] - 18.603f;
	Vo=  0.9406f*buffer_adc[2] - 484.61f;
#endif

#ifdef OUR_SENSORS
	If= 0.0373f * buffer_adc[0] - 18.95f;
	Io= 0.0365f* buffer_adc[1] - 18.855f;
	Vo=  0.8884f*buffer_adc[2] - 457.7f;
#endif

	If_calman = x[0];


/*	PID controller	*/
		float V_error = (sin_V_ref[i])-Vo;
		sum_error +=V_error;
		float I_ref =Io +  kP_E*V_error + kI_E*TS*sum_error;
		V_ref =(Vo + kp_i*(I_ref - If));
		int16_t duty_cycle = V_ref*(PWM_TIM_period)/V_IN;
//		int16_t duty_cycle = (PWM_TIM_period)*sin_V_ref[i]/V_IN;
//		int16_t duty_cycle = pwm;
//		DAC_SetVoltage(1.65f+sin_V_ref[i]/30,DAC_CHANNEL_1);
//		DAC_SetVoltage(1.65f+sin_V_ref[i]/30,DAC_CHANNEL_2);
/*	Generate PWM signal	*/
		if(duty_cycle>0){
			TIM1->CCR2= duty_cycle;
			TIM1->CCR3= 0;
		}
		else{
			TIM1->CCR2= 0;
			TIM1->CCR3= -duty_cycle;
		}
		i=(i+1)%400;
		t=i+0.1f;
/*	observer IF	*/

		/* calculate X' */
		y[0]=A11*x[0]+A12*x[1]+B11*V_ref;
		y[1]=A21*x[0]+ x[1]+B22*Io;
		/* calculate P' */

		b[0][0]=(A11*p[0][0]+A12*p[1][0])*A11+(A11*p[0][1]+A12*p[1][1])*A12+1;
		b[0][1]=(A11*p[0][0]+A12*p[1][0])*A21+(A11*p[0][1]+A12*p[1][1]) ;
		b[1][0]=(A21*p[0][0]+ p[1][0])*A11+(A21*p[0][1]+ p[1][1])*A12;
		b[1][1]=(A21*p[0][0]+ p[1][0])*A21+(A21*p[0][1]+ p[1][1]) +1;

		/* calculate K */
		k[0]=b[0][1]/(b[1][1]+1);
		k[1]=b[1][1]/(b[1][1]+1);
		/* calculate X */

		x[0]=y[0]+k[0]*(Vo-y[1]);
		x[1]=y[1]+k[1]*(Vo-y[1]);

		/* calculate P */
		p[0][0]=b[0][0]-(k[0]*b[1][0]);
		p[0][1]=+b[0][1]-(k[0]*b[1][1]);
		p[1][0]=b[1][0]*(1-k[1]);
		p[1][1]=b[1][1]*(1-k[1]);


/*	calculation	*/
		vRms=vRms+Vo*Vo;
		vMoy+=Vo;

		IRms=IRms+If*If;
		IMoy+=If;

		IoRms=IoRms+Io*Io;
				IoMoy+=Io;

		iRms++;

		if(vMax<Vo)
		{
			vMax=Vo;
		}
		if(vMax2>Vo)
			{
			vMax2=Vo;
			}


		if(IoMax<Io)
		{
			IoMax=Io;
		}
		if(IoMax2>Io)
			{
			IoMax2=Io;
			}



		if(IMax<If)
		{
			IMax=If;
		}
		if(IMax2>If)
			{
			IMax2=If;
			}

		if(iRms==399){
			pvRms=sqrt(vRms/iRms);
			pvMoy=vMoy/iRms;
			pMax2=vMax2;
			pMax=vMax;
			vMax=0;
			vMoy=0;
			vRms=0;
			vMax2=0;

			pIoRms=sqrt(IoRms/iRms);
			pIoMoy=IoMoy/iRms;
			IopMax2=IoMax2;
			IopMax=IoMax;
			IoMax=0;
			IoMoy=0;
			IoRms=0;
			IoMax2=0;


			pIRms=sqrt(IRms/iRms);
			pIMoy=IMoy/iRms;
			IpMax2=IMax2;
			IpMax=IMax;
			IMax=0;
			IMoy=0;
			IRms=0;
			IMax2=0;

			iRms=0;

		}
//	data = Start_Data_Conversion();
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


