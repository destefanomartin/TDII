#include "task-watchdog.h"
#include "main.h"
extern WWDG_HandleTypeDef hwwdg;

void WATCHDOG_Init(void) {
	  /* USER CODE BEGIN WWDG_Init 0 */

	  /* USER CODE END WWDG_Init 0 */

	  /* USER CODE BEGIN WWDG_Init 1 */

	  /* USER CODE END WWDG_Init 1 */
	  hwwdg.Instance = WWDG;
	  hwwdg.Init.Prescaler = WWDG_PRESCALER_2;
	  hwwdg.Init.Window = 65;
	  hwwdg.Init.Counter = 69;
	  hwwdg.Init.EWIMode = WWDG_EWI_DISABLE;
	  if (HAL_WWDG_Init(&hwwdg) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN WWDG_Init 2 */

	  /* USER CODE END WWDG_Init 2 */

}

void WATCHDOG_Update(void) {
	HAL_WWDG_Refresh(&hwwdg);
}
