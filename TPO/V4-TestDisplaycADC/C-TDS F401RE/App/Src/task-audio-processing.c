/*
 * task-read-adc.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Flia König
 */
#include <task-audio-processing.h>
#include "ports_stm32f401.h"
#include "pin_functions_stm32f401.h"

#define OFFSET 3200
#define THRESHOLD 20

extern uint16_t adc_buf[];
extern ADC_HandleTypeDef hadc1;

int flag_sumar_uno = 0;
int conteo_positivos = 0;

void READ_ADC_Init(void)
{
	int i=0;
	for(i=0; i < ADC_BUF_LEN; i++)
	{
		adc_buf[i]=0;
	}

	Pin_Write(LD2_GPIO_Port, LD2_Pin, OFF);
	return;
}
void READ_ADC_Update(void)
{
	int i = 0;
	int suma = 0;
	uint32_t prom = 0;
	int resta = 0;


	HAL_ADC_Stop_DMA(&hadc1);

	for(i=0; i < ADC_BUF_LEN; i++)
	{
		resta =  ((int) adc_buf[i])-OFFSET;

		if(resta<0)
		{
			resta *= -1;
		}
		suma += resta;

	}
	prom = suma/ADC_BUF_LEN;
	//Verificar si el promedio de datos capturados supera el umbral seteado
	if(prom > THRESHOLD)
	{
		conteo_positivos++;
		Pin_Write(LD2_GPIO_Port, LD2_Pin, ON);
	}
	else
	{
		conteo_positivos = 0;
		Pin_Write(LD2_GPIO_Port, LD2_Pin, OFF);
	}

	if(conteo_positivos >=6)
	{
		flag_sumar_uno = 1;	//este flag se debe poner en 0 al sumar al conteo de pulsos
		conteo_positivos=0;
	}
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adc_buf, ADC_BUF_LEN);
	return;
}
