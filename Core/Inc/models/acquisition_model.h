/*
 * acquisition_model.h
 *
 *  Created on: Mar 18, 2024
 *      Author: iddou
 */

#ifndef INC_MODELS_ACQUISITION_MODEL_H_
#define INC_MODELS_ACQUISITION_MODEL_H_


/* Private includes ----------------------------------------------------------*/
#include "config/adc_config.h"

/* Private Macros ----------------------------------------------------------*/

/* Private Constants ----------------------------------------------------------*/

/* Private Variables ----------------------------------------------------------*/

/* Private Structs ----------------------------------------------------------*/

typedef struct Acquisition_Data {
float  If;
float  Io;
float  Vo;
} Acquisition_Data;

/* Private Functions ----------------------------------------------------------*/
Acquisition_Data Start_Data_Conversion(void);

#endif /* INC_MODELS_ACQUISITION_MODEL_H_ */
