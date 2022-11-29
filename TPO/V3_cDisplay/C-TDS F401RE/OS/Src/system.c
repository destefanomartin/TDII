
#include "system.h"



eSystem_mode System_mode_G;

void SYSTEM_Identify_Required_Mode(void);
void SYSTEM_Configure_Required_Mode(void);

void SYSTEM_Init(void) {
	SYSTEM_Identify_Required_Mode();
	SYSTEM_Configure_Required_Mode();
}

void SYSTEM_Identify_Required_Mode(void) {
	if(__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST))
	{
		__HAL_RCC_CLEAR_RESET_FLAGS();
		System_mode_G = FAIL_SILENT;
		return;
	}
    System_mode_G = NORMAL;
}

void SYSTEM_Configure_Required_Mode(void) {
	switch (System_mode_G)
	{
        default: // Default to "FAIL_SILENT"
        case FAIL_SILENT:
        {
            // Reset caused by WDT
            // Trigger "fail silent" behavior
            SYSTEM_Perform_Safe_Shutdown();
            break;
        }
        case FAULT_TASK_TIMING:
        {
            // Reset caused by WDT
            // Trigger "fail silent" behavior
            SYSTEM_Perform_Safe_Shutdown();
            break;
        }
        case NORMAL:
        {
        	// Set up scheduler for 1 ms ticks (tick interval in *ms*)
            SCH_Init(1);

        	// Prepare for Heartbeat task
        	HEARTBEAT_Init();
        	WATCHDOG_Init();
        	ANTIRREBOTE_Init();
        	READ_ADC_Init();
        	//HD44780_Init(2);

        	// Add tasks to schedule.
            // Parameters are:
            // 1. Task name
            // 2. Initial delay / offset (in ticks)
            // 3. Task period (in ticks): Must be > 0
            // 4. Task WCET (in microseconds)
            // 5. Task BCET (in microseconds)

            // Add watchdog task first
            SCH_Add_Task(WATCHDOG_Update, 0, 1, 1, 1);

            // Add Heartbeat task
            SCH_Add_Task(HEARTBEAT_Update, 0, 10, 1, 1);

            // Agregar Task Antirrebote con LED
            SCH_Add_Task(ANTIRREBOTE_Update, 1, 10, 1, 1);

            // Agregar Task Lectura ADC
            SCH_Add_Task(READ_ADC_Update, 0, 10,100 , 1);

            // Tarea display
            //SCH_Add_Task(lcd_update, 0, 100, 1, 0);

            //SCH_Add_Task(Mediciones_Update, 0, 10, 5, 0);
            break;
        }
	}
}

void SYSTEM_Perform_Safe_Shutdown(void)
{
    // Used for simple fault reporting
    int Delay, j;

    // Here we simply "fail silent" with rudimentary fault reporting
    // OTHER BEHAVIOUR IS LIKELY TO BE REQUIRED IN YOUR DESIGN
    // *************************************
    // NOTE: This function should NOT return
    // *************************************
    HEARTBEAT_Init();
    Pin_Config(LD2_GPIO_Port, LD2_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);
    Pin_Config(Heartbeat_GPIO_Port, Heartbeat_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);
    Pin_Write(LD2_GPIO_Port, LD2_Pin, ON);

    while(1)
	{
        // Flicker Heartbeat LED to indicate fault
    	for (Delay = 0; Delay < 2000000; Delay++) j *= 3;

        	Pin_Toggle(LD2_GPIO_Port, LD2_Pin);
        	HEARTBEAT_Update();

			SYSTEM_Change_Mode_Fault(NORMAL);

	}

}

void SYSTEM_Change_Mode_Fault(eSystem_mode mode)
{
	System_mode_G = mode;
}


eSystem_mode SYSTEM_Get_Mode(void)
{
	return System_mode_G;
}

