/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
//#include "models/pwm_model.h"
#include "config/config.h"
#include "models/pwm_model.h"
#include "models/pwm_model.h"
#include "models/if_observer_model.h"
#include "controllers/pid_controller.h"
#include "system_variables.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//****************************************************************************
void EnableTiming(void);

#ifdef DEVELOPMENT_MODE
volatile unsigned int *DWT_CYCCNT   = (volatile unsigned int *)0xE0001004;
volatile unsigned int *DWT_CONTROL  = (volatile unsigned int *)0xE0001000;
volatile unsigned int *DWT_LAR      = (volatile unsigned int *)0xE0001FB0;
volatile unsigned int *SCB_DHCSR    = (volatile unsigned int *)0xE000EDF0;
volatile unsigned int *SCB_DEMCR    = (volatile unsigned int *)0xE000EDFC;
volatile unsigned int *ITM_TER      = (volatile unsigned int *)0xE0000E00;
volatile unsigned int *ITM_TCR      = (volatile unsigned int *)0xE0000E80;

//****************************************************************************

static int Debug_ITMDebug = 0;
/* USER CODE END PD */
void EnableTiming(void)
{
  if ((*SCB_DHCSR & 1) && (*ITM_TER & 1)) // Enabled?
    Debug_ITMDebug = 1;

  *SCB_DEMCR |= 0x01000000;
  *DWT_LAR = 0xC5ACCE55; // enable access
  *DWT_CYCCNT = 0; // reset the counter
  *DWT_CONTROL |= 1 ; // enable the counter
}
#endif

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/


/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/


/* USER CODE BEGIN PFP */

volatile bool start_adc = false;
void set_start_adc (bool adc){
	start_adc=adc;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	PWM_Generate();

	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);

}
	/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */

  /* USER CODE BEGIN 2 */
  System_Init();
  PWM_Model_Init();
  init_pid_controller();
  System_Start();
#ifdef DEVELOPMENT_MODE
  EnableTiming();
  *DWT_CYCCNT = 0;
#endif
  TIM1->CCR1= 0;

//  TIM1->CCR2= 4000;
//  TIM1->CCR3=0;
//  PWM_Generate();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(start_adc){
		  start_adc=false;
		  ADC_Start();
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}




#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
