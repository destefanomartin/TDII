#include "OS.h"

#include "system.h"

#include "task-heartbeat.h"
#include "task-watchdog.h"

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

            // Initialize WWDT and event router
        	// Chip_WWDT_Init(LPC_WWDT);

            // Set up WDT (timeout in *microseconds*)
            // WATCHDOG_Init(WatchDog_RateuS);

            // Set up Timer 0 as MoniTTor unit
            // MONITTOR_I_Init();

        	// Prepare for Heartbeat task
        	HEARTBEAT_Init();

        	// Add tasks to schedule.
            // Parameters are:
            // 1. Task name
            // 2. Initial delay / offset (in ticks)
            // 3. Task period (in ticks): Must be > 0
            // 4. Task WCET (in microseconds)
            // 5. Task BCET (in microseconds)

            // Add watchdog task first
            SCH_Add_Task(WATCHDOG_Update, 0, 1, 10, 0);

            // Add Heartbeat task
            SCH_Add_Task(HEARTBEAT_Update, 0, 1000, 20, 0);

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

    while(1)
	{
        // Flicker Heartbeat LED to indicate fault
        for (Delay = 0; Delay < 200000; Delay++) j *= 3;
        HEARTBEAT_Update();
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

