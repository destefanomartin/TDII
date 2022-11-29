/*
 * task-pulsador-antirrebote.c
 *
 *  Created on: 3 nov. 2022
 *      Author: Flia König
 */

#include <task-pulsador-falla.h>


int cont_estados;
static GPIO_PinState estado_actual_B1;
GPIO_PinState estado_anterior_B1;
GPIO_PinState vector_entradas[] = {0,0,0,0,0};

void ANTIRREBOTE_Init(void)
{

}

//Update cada 10 ms, 5 lecturas
void ANTIRREBOTE_Update(void)
{
	GPIO_PinState entradaB1;

	int suma_entradas=0;
	int j=0;

	entradaB1 = Pin_Read(B1_GPIO_Port, B1_Pin);

	//Agrego valor de entrada actual
	vector_entradas[cont_estados] = entradaB1;
	cont_estados++;
	if(cont_estados>4)
	{
		cont_estados = 0;
	}

	//sumo todos los valores del vector
	for(j=0; j<5; j++)
	{
		suma_entradas += vector_entradas[j];
	}

	//Comparo ultimos valores de entrada con la actual
	estado_anterior_B1 = estado_actual_B1;
	if((estado_anterior_B1 == OFF) && (suma_entradas > 3))
	{
		estado_actual_B1 = ON;

	}
	else if((estado_anterior_B1 == ON) && (suma_entradas < 2))
	{
		estado_actual_B1 = OFF;
		Pin_Write(LD2_GPIO_Port, LD2_Pin, ON); //Parece que el pulsador on-board es normal cerrado
		//Loop para entrar en falla
		while(1)
		{
			j=j;
		}
	}
}
