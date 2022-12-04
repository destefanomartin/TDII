#include "task-watchdog.h"

extern WWDG_HandleTypeDef hwwdg;

void WATCHDOG_Init(void) {
}

void WATCHDOG_Update(void) {
	HAL_WWDG_Refresh(&hwwdg);
}
