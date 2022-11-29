#include "task-heartbeat.h"

void HEARTBEAT_Init(void)
{
	//Pin_Config(Heartbeat_GPIO_Port, Heartbeat_Pin, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_FREQ_LOW);
	Pin_Write(Heartbeat_GPIO_Port, Heartbeat_Pin, ON);
	return;
}

void HEARTBEAT_Update(void)
{
	Pin_Toggle(Heartbeat_GPIO_Port, Heartbeat_Pin);
	return;
}
