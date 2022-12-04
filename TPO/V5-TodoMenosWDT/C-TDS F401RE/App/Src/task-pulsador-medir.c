/*
 * task-pulsador-medir.c
 *
 *  Created on: 1 dic. 2022
 *      Author: Flia König
 */

#include "task-pulsador-medir.h"

#define ENTRADAS 20

int cont_estados_B2;
static GPIO_PinState estado_actual_B2;
GPIO_PinState estado_anterior_B2;
GPIO_PinState vector_entradas_B2[ENTRADAS];

int flag_medir = 0;
int flag_resetear_mediciones = 1;


void PULSADOR_MEDIR_Init(void)
{
	int i=0;
	for(i=0; i<ENTRADAS; i++)
	{
		vector_entradas_B2[i]=0;
	}
}

//Update cada 10 ms, 5 lecturas
void PULSADOR_MEDIR_Update(void)
{
		GPIO_PinState entradaB2;

		int suma_entradas=0;
		int j=0;

		entradaB2 = Pin_Read(B2_GPIO_Port, B2_Pin);

		//Agrego valor de entrada actual
		vector_entradas_B2[cont_estados_B2] = entradaB2;
		cont_estados_B2++;
		if(cont_estados_B2>9)
		{
			cont_estados_B2 = 0;
		}

		//sumo todos los valores del vector
		for(j=0; j<10; j++)
		{
			suma_entradas += vector_entradas_B2[j];
		}

		//Comparo ultimos valores de entrada con la actual
		estado_anterior_B2 = estado_actual_B2;
		if((estado_anterior_B2 == OFF) && (suma_entradas > 8))
		{
			estado_actual_B2 = ON;
		}

		if(estado_actual_B2== ON)
		{
			estado_actual_B2 = OFF;

			if(!flag_medir)
			{
				flag_medir = ON;
			}
			else
			{
				flag_medir = OFF;
				flag_resetear_mediciones = ON;
			}
		}

}
