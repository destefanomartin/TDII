/*------------------------------------------------------------------*-

    port_lpc1769.h (Released 2019-04)

  ------------------------------------------------------------------

    This is the "Port Header" file: it documents usage of port pins
    in the project.

-*------------------------------------------------------------------*/

#ifndef _PORT_H
#define _PORT_H 1


// ------ Public constants -----------------------------------------
#define TIM_PRESCALE_USVAL	(100)


// Car wash Controller
#define SENSOR_ON	(true)
#define SENSOR_OFF	(false)
#define MOTOR_ON	(true)
#define MOTOR_OFF	(false)


// Allows Active Low or Active High led to be used (or other wiring variations)
#define LED_ON	(true)
#define LED_OFF	(false)


// Heartbeat LED
// Connected to "LED2" on LPC1769 board
// Port 0, Pin 22
#define HEARTBEAT_LED_PORT (0)
#define HEARTBEAT_LED_PIN (22)
#define HEARTBEAT_LED_PIN_MODE (IOCON_MODE_INACT)
#define HEARTBEAT_LED_PIN_FUNC (IOCON_FUNC0)


// RGB LED
// Connected to "RED" on LPC1769 board
// Port 2, Pin 0
#define MOTOR1_LED_PORT (2)
#define MOTOR1_LED_PIN (0)
#define MOTOR1_LED_PIN_MODE (IOCON_MODE_INACT)
#define MOTOR1_LED_PIN_FUNC (IOCON_FUNC0)


// RGB LED
// Connected to "GREEN" on LPC1769 board
// Port 2, Pin 1
#define MOTOR2_LED_PORT (2)
#define MOTOR2_LED_PIN (1)
#define MOTOR2_LED_PIN_MODE (IOCON_MODE_INACT)
#define MOTOR2_LED_PIN_FUNC (IOCON_FUNC0)

// RGB LED
// Connected to "BLUE" on LPC1769 board
// Port 0, Pin 26


// Allows NO or NC switch to be used (or other wiring variations)
#define SW_PRESSED		(false)
#define SW_NOT_PRESSED	(true)


// SW2-PRESS SWITCH
// Connected to "SW2 PRESS" on LPCXpresso baseboard
// Port 0, Pin 17
#define E1_SWITCH_PORT (0)
#define E1_SWITCH_PIN (17)
#define E1_SWITCH_PIN_MODE (IOCON_MODE_PULLUP)
#define E1_SWITCH_PIN_FUNC (IOCON_FUNC0)


// SW2-UP SWITCH
// Connected to "SW2 UP" on LPCXpresso baseboard
// Port 2, Pin 3
#define S1_SWITCH_PORT (2)
#define S1_SWITCH_PIN (3)
#define S1_SWITCH_PIN_MODE (IOCON_MODE_PULLUP)
#define S1_SWITCH_PIN_FUNC (IOCON_FUNC0)


// SW2-DOWN SWITCH
// Connected to "SW2 DOWN" on LPCXpresso baseboard
// Port 0, Pin 15


// SW2-LEFT SWITCH
// Connected to "SW2 LEFT" on LPCXpresso baseboard
// Port 2, Pin 4


// SW2-RIGHT SWITCH
// Connected to "SW2 RIGHT" on LPCXpresso baseboard
// Port 0, Pin 16


// SW3 SWITCH
// Connected to "SW3" on LPCXpresso baseboard
// Port 2, Pin 10
#define S2_SWITCH_PORT (2)
#define S2_SWITCH_PIN (10)
#define S2_SWITCH_PIN_MODE (IOCON_MODE_PULLUP)
#define S2_SWITCH_PIN_FUNC (IOCON_FUNC0)


// SW4 SWITCH
// Connected to "SW4" on LPCXpresso baseboard
// Port 1, Pin 31
#define S3_SWITCH_PORT (1)
#define S3_SWITCH_PIN (31)
#define S3_SWITCH_PIN_MODE (IOCON_MODE_PULLUP)
#define S3_SWITCH_PIN_FUNC (IOCON_FUNC0)


// Add jumper wire on baseboard to control WDT
// WDT is enabled *only* if jumper is in place.
// (Jumper is read at init phase only)
// Port 2, Pin 3 => Connected to "SW2 UP" on LPCXpresso baseboard
#define WDT_JUMPER_PORT (2)
#define WDT_JUMPER_PIN (3)
#define WDT_JUMPER_PIN_MODE (IOCON_MODE_PULLUP)
#define WDT_JUMPER_PIN_FUNC (IOCON_FUNC0)


// ------ Public data type declarations ----------------------------


// ------ Public function prototypes -------------------------------


#endif


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
