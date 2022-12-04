/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "OS.h"
#include "pin_functions_stm32f401.h"
#include "ports_stm32f401.h"
#include "i2c-display.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define ADC_BUF_LEN   (4096)
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

// Flag para activar/desactivar el watchdog sin tener que cambiar la configuracion en el .ioc
#define WWDG_ENABLED (0)

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
/*
 * La frecuencia del WWDG es de System_Clock/2/4096/Preescaler,
 * Es decir que para System_Clock = 84MHZ y Preescaler = 2 el periodo de cada tick del WWDG es:
 * 1/(84000000/2/4096/2) = 195us
 *
 * Con WWDG_TICKS = 69 tenemos que hay 6 ticks del WWDG hasta que llegue a 63 y resetee que son 1170us,
 * buen valor de base para uns Systick de 1ms
 *
 * Con WWDG_WINDOW = 65 tenemos que hay 2 ticks de ventana para resetear que son 390us antes del reset
 * y nos sirve como chequeo extra de que el update no se esté haciendo demasiado rápido
 *
 * https://www.hackster.io/vasam2230/stm32-window-watchdog-wwdg-dda290
 * */
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define WWDG_WINDOW 66
#define WWDG_TICKS 74
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Heartbeat_Pin GPIO_PIN_10
#define Heartbeat_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define B2_Pin GPIO_PIN_10
#define B2_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
