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
#include "config/dac_config.h"
/* Private Constants ----------------------------------------------------------*/
#ifdef PRODUCTION_MODE
const float sin_V_ref[400]={0.000000,5.109068,10.216876,15.322163,20.423668,25.520136,30.610306,35.692924,40.766735,45.830486,50.882931,55.922821,60.948910,65.959961,70.954742,75.932014,80.890549,85.829124,90.746529,95.641541,100.512947,105.359558,110.180176,114.973602,119.738670,124.474182,129.178986,133.851929,138.491837,143.097565,147.667999,152.201981,156.698425,161.156204,165.574219,169.951370,174.286606,178.578827,182.826981,187.030045,191.186951,195.296677,199.358215,203.370575,207.332764,211.243774,215.102676,218.908508,222.660324,226.357193,229.998215,233.582489,237.109131,240.577271,243.986053,247.334641,250.622192,253.847900,257.010986,260.110657,263.146149,266.116699,269.021606,271.860138,274.631592,277.335266,279.970520,282.536682,285.033173,287.459290,289.814514,292.098206,294.309845,296.448853,298.514740,300.506958,302.425018,304.268463,306.036835,307.729706,309.346649,310.887268,312.351166,313.738007,315.047424,316.279114,317.432770,318.508087,319.504852,320.422760,321.261597,322.021179,322.701324,323.301819,323.822571,324.263397,324.624237,324.904968,325.105530,325.225891,325.265991,325.225861,325.105469,324.904846,324.624084,324.263214,323.822327,323.301575,322.701019,322.020844,321.261230,320.422333,319.504395,318.507599,317.432251,316.278564,315.046814,313.737366,312.350494,310.886566,309.345917,307.728943,306.036041,304.267609,302.424133,300.506042,298.513763,296.447876,294.308838,292.097168,289.813416,287.458191,285.032013,282.535522,279.969299,277.334015,274.630310,271.858826,269.020264,266.115326,263.144745,260.109222,257.009521,253.846405,250.620667,247.333084,243.984467,240.575668,237.107498,233.580826,229.996521,226.355469,222.658569,218.906738,215.100891,211.241959,207.330917,203.368713,199.356339,195.294769,191.185013,187.028091,182.825012,178.576828,174.284576,169.949341,165.572159,161.154129,156.696335,152.199875,147.665863,143.095413,138.489670,133.849747,129.176804,124.471977,119.736443,114.971367,110.177925,105.357300,100.510674,95.639252,90.744232,85.826820,80.888237,75.929688,70.952408,65.957626,60.946564,55.920467,50.880569,45.828121,40.764362,35.690548,30.607927,25.517754,20.421284,15.319776,10.214487,5.106679,-0.002390,-5.111457,-10.219264,-15.324550,-20.426054,-25.522518,-30.612684,-35.695297,-40.769104,-45.832851,-50.885292,-55.925175,-60.951260,-65.962303,-70.957077,-75.934334,-80.892868,-85.831429,-90.748825,-95.643822,-100.515221,-105.361824,-110.182426,-114.975838,-119.740891,-124.476395,-129.181183,-133.854095,-138.493988,-143.099716,-147.670120,-152.204102,-156.700516,-161.158279,-165.576279,-169.953415,-174.288620,-178.580826,-182.828964,-187.031998,-191.188873,-195.298584,-199.360107,-203.372437,-207.334595,-211.245590,-215.104477,-218.910278,-222.662064,-226.358902,-229.999908,-233.584152,-237.110764,-240.578888,-243.987640,-247.336182,-250.623703,-253.849396,-257.012451,-260.112091,-263.147552,-266.118073,-269.022949,-271.861450,-274.632843,-277.336517,-279.971741,-282.537872,-285.034302,-287.460419,-289.815582,-292.099274,-294.310852,-296.449829,-298.515686,-300.507843,-302.425903,-304.269318,-306.037659,-307.730469,-309.347382,-310.887970,-312.351837,-313.738617,-315.048004,-316.279663,-317.433289,-318.508575,-319.505280,-320.423157,-321.261963,-322.021515,-322.701630,-323.302094,-323.822784,-324.263580,-324.624390,-324.905090,-325.105621,-325.225922,-325.265991,-325.225830,-325.105377,-324.904755,-324.623932,-324.263031,-323.822113,-323.301300,-322.700714,-322.020508,-321.260864,-320.421936,-319.503937,-318.507141,-317.431732,-316.277985,-315.046234,-313.736725,-312.349823,-310.885864,-309.345154,-307.728149,-306.035217,-304.266785,-302.423248,-300.505127,-298.512817,-296.446899,-294.307800,-292.096100,-289.812347,-287.457062,-285.030853,-282.534332,-279.968079,-277.332764,-274.629028,-271.857513,-269.018921,-266.113953,-263.143341,-260.107788,-257.008057,-253.844910,-250.619141,-247.331528,-243.982895,-240.574051,-237.105865,-233.579163,-229.994843,-226.353760,-222.656830,-218.904968,-215.099091,-211.240143,-207.329071,-203.366852,-199.354446,-195.292862,-191.183075,-187.026123,-182.823029,-178.574829,-174.282562,-169.947296,-165.570099,-161.152054,-156.694244,-152.197769,-147.663742,-143.093277,-138.487503,-133.847565,-129.174606,-124.469772,-119.734222,-114.969131,-110.175682,-105.355042,-100.508400,-95.636971,-90.741936,-85.824516,-80.885918,-75.927368,-70.950081,-65.955284,-60.944218,-55.918114,-50.878212,-45.825756,-40.761993,-35.688175,-30.605549,-25.515371,-20.418900,-15.317389,-10.212099,-5.104290};
#endif
/* Private Variables ----------------------------------------------------------*/
#ifdef DEVELOPMENT_MODE
float sin_V_ref[101];
#endif
uint8_t sin_ref_index=-1;
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
 		sin_V_ref[i]=(V_REF_MAX*sin(i*2*PI/(N_ECH)));

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
	float error = sin_ref_signe ? (sin_V_ref[sin_ref_index])-Vo : (-sin_V_ref[sin_ref_index])-Vo;
	sum_V_error += error;
	return error;
}

static float calculate_if_ref(float Vo,float Io,float V_error){	// voltage loop
	return (Io + kP_E*V_error + kI_E*TS*sum_V_error);
}

static float calculate_V_ref(float Vo,float If,float I_ref){	// current loop
	return (Vo + kP_I*(I_ref - If));
}

float Vout ;

float calculate_PID_V_ref(float If,float Io,float Vo){
	caclulate_sin_ref_index();
	float V_error = calculate_V_error(Vo);
	float I_ref = calculate_if_ref(Vo,Io,V_error);
	float V_ref =  calculate_V_ref(Vo,If,I_ref);
//	if(sin_ref_signe){
//		Vout = (float) (1.5*sin_V_ref[sin_ref_index]/(V_REF_MAX))+1.5;
//
//		}else{
//			Vout =- (float) (1.5*sin_V_ref[sin_ref_index]/(V_REF_MAX))+1.5;
//		}
		DAC_SetValue(Io);
	return V_ref;
}
