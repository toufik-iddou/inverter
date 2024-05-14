/*
 * if_observer_model.h
 *
 *  Created on: May 8, 2024
 *      Author: iddou
 */

#ifndef INC_MODELS_IF_OBSERVER_MODEL_H_
#define INC_MODELS_IF_OBSERVER_MODEL_H_



/* Private includes ----------------------------------------------------------*/

/* Private Macros ----------------------------------------------------------*/

//#define A11	0.9487f
//#define A12	-0.02447f
//#define A21	2.128f
//#define A22	0.9732f

#define A11	0.9750f
#define A12	-0.0250f
#define A21	2.1739f
#define A22	1u


#define A0 0.975f
#define A1 -0.025f
#define A2 2.1739f

#define A0A0 0.950625f
#define A0A1 -0.024375f
#define A1A1 -0.000625f
#define A0A2 2.1195525f
#define A1A2 -0.0543475f
#define A2A2 4.72584121f





#define B0 0.0250f
#define B3 -2.1739f



//#define B11 0.02447f
//#define B12	0.02683f
//#define B21	0.02683f
//#define B22	-2.154f

#define B11 0.0250f
#define B12	0u
#define B21	0u
#define B22	-2.1739f

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/

/* Private Structure ----------------------------------------------------------*/

/* Private Functions ----------------------------------------------------------*/

void Observer_Init(void);
float Observer_Start(float Uinv,float Io,float Vo);
float calculate_kalman_current(float Uinv,float Io,float Vo);

#endif /* INC_MODELS_IF_OBSERVER_MODEL_H_ */
