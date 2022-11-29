/*
 * adc_functions_stm32f401.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Flia König
 */
/* #include "adc_functions_stm32f401.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void Poll_ADC(void){
	uint16_t raw_data;
	char msg[10];

	HAL_ADC_Start(&hadc1);
	raw_data = HAL_ADC_GetValue(&hadc1);

	sprintf(msg, "%hu\r\n", raw_data);
	HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg),HAL_MAX_DELAY);
}
*/
