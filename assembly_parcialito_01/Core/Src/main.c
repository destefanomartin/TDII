/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tasks.h"
#include <stdio.h>
#include <string.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#ifdef __cplusplus
}
#endif

PUTCHAR_PROTOTYPE
{
	/* Place your implementation of fputc here */
     /* e.g. write a character to the USART2 and Loop until the end of transmission */
 	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

 	return ch;
}

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

//	User Code Begin PFP => "C - Assembly Interface"

#if (TEST_X == TEST_1)	/* getLowerSigned => Signed Elements */

int32_t getLowerSigned (void *array, uint32_t sizeOfElements, uint16_t numberOfElements);

#endif


#if (TEST_X == TEST_2)	/* getLowerUnsigned => Unsigned Elements */

uint32_t getLowerUnsigned (void *array, uint32_t sizeOfElements, uint16_t numberOfElements);

#endif

//	User Code End PFP => "C - Assembly Interface"

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//	User Data Begin PFP => "C - Assembly Interface"

#if (TEST_X == TEST_1)	/* getLowerSigned => Signed Elements */

int32_t arrayInt32[]	= {9, 7, 5, 3, 1, 0, -3, -2, -1, 2, 4, 6};
int16_t arrayInt16[]	= {   9, 7, 5, 3, 1,  0, -2, -1, 2, 4   };
int8_t	 arrayInt8[]	= {      9, 7, 5, 3,  1,  0, -1, 2      };

#endif


#if (TEST_X == TEST_2)	/* getLowerUnsigned => Unsigned Elements */

uint32_t arrayUint32[]	= {9, 7, 5, 3, 1, 0, 2, 4, 6, 8};
uint16_t arrayUint16[]	= {   9, 7, 5, 3, 1, 2, 4, 6   };
uint8_t	 arrayUint8[]	= {      9, 7, 5, 3, 2, 4      };

#endif

//	User Data End PFP => "C - Assembly Interface"

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int32_t		lowerArrayInt;
	uint32_t	lowerArrayUint;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

	printf("Project: assembly_parcialito_01\r\n\n");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		//	User Code Begin  Init & Test => "C - Assembly Interface"

	#if (TEST_X == TEST_1)		/* getLowerSigned => Signed Elements */

	printf("/* getLowerSigned => Signed Elements */\r\n");

	lowerArrayInt = getLowerSigned (arrayInt8,  sizeof(uint8_t),  (sizeof(arrayInt8) /sizeof(int8_t)));
	printf("   Lower = %8x (Hexa) = %i (Dec)\r\n", lowerArrayInt, lowerArrayInt);

	lowerArrayInt = getLowerSigned (arrayInt32, sizeof(int32_t), (sizeof(arrayInt32)/sizeof(int32_t)));
	printf("   Lower = %8x (Hexa) = %i (Dec)\r\n", lowerArrayInt, lowerArrayInt);

	lowerArrayInt = getLowerSigned (arrayInt16, sizeof(int16_t), (sizeof(arrayInt16)/sizeof(int16_t)));
	printf("   Lower = %8x (Hexa) = %i (Dec)\r\n", lowerArrayInt, lowerArrayInt);


	printf("\r\n");

	#endif

	#if (TEST_X == TEST_2)		/* getLowerUnsigned => Unsigned Elements */

	printf("/* getLowerUnsigned => Unsigned Elements */\r\n");

	lowerArrayUint = getLowerUnsigned (arrayUint32, sizeof(uint32_t), (sizeof(arrayUint32)/sizeof(uint32_t)));
	printf("   Lower = %8x (Hexa) = %i (Dec)\r\n", lowerArrayUint, lowerArrayUint);

	lowerArrayUint = getLowerUnsigned (arrayUint16, sizeof(uint16_t), (sizeof(arrayUint16)/sizeof(uint16_t)));
	printf("   Lower = %8x (Hexa) = %i (Dec)\r\n", lowerArrayUint, lowerArrayUint);

	lowerArrayUint = getLowerUnsigned (arrayUint8,  sizeof(uint8_t),  (sizeof(arrayUint8) /sizeof(uint8_t)));
	printf("   Lower = %8x (Hexa) = %i (Dec)\r\n", lowerArrayUint, lowerArrayUint);

	printf("\r\n");

	#endif

		// User Code End  Init & Test => "C - Assembly Interface"
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
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
