/*
 * task-mediciones.c
 *
 *  Created on: Nov 28, 2022
 *      Author: Deste
 */
#include "task-mediciones.h"
extern int flag_sumar_uno;
uint16_t Mediciones[3] = {0,0,0};
uint16_t MedicionActual=0;



void Mediciones_Init()
{

}

void Mediciones_Update()
{
	if(flag_sumar_uno == 1)
	{
		Mediciones[MedicionActual]++;
		flag_sumar_uno = 0;
	}
}
