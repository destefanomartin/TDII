#include "task-heartbeat.h"

void HEARTBEAT_Init(void) {
}

void HEARTBEAT_Update(void) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
