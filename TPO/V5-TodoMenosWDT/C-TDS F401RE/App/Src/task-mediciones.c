/*
 * task-mediciones.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Flia König
 */

#include "task-mediciones.h"
#define CICLOS_CONTEO (1000) //Para 1 minuto de conteo, llamado cada 10ms, 6000. Para 20 segundos, 2000

extern int flag_sumar_uno;
extern int flag_medir;
extern int flag_resetear_mediciones;
int medicion_activa;		//Numero de la medicion, -1 es ninguna
int timer_conteo;
int mediciones[3];

void MEDICIONES_Init(void)
{
	mediciones[0]=0;
	mediciones[1]=0;
	mediciones[2]=0;

	return;
}

void MEDICIONES_Update(void)
{
	if(flag_resetear_mediciones)
	{
		flag_resetear_mediciones=0;
		mediciones[0]=0;
		mediciones[1]=0;
		mediciones[2]=0;
		flag_medir=0;
		timer_conteo=0;
		medicion_activa=0;
	}

	if(flag_medir)
	{
		//Si se detecta un pulso, sumar a medicion activa
		if(flag_sumar_uno)
		{
			flag_sumar_uno=0; 	//Se resetea flag
			mediciones[medicion_activa]++;
		}

		//Timer de mediciones (1 minuto, 6000 ticks, 3 veces)
		timer_conteo++;
		if(timer_conteo > CICLOS_CONTEO)	//Si termina el minuto, ver si se pasa a siguiente medicion o se termina
		{
			timer_conteo=0;
			medicion_activa++;
			if(medicion_activa > 2)	//finalizar mediciones o continuar
			{
				flag_medir = 0;		//Se deja de medir
				medicion_activa = 0; //Se resetea medición activa
			}
		}
	}
	return;
}


