/*
 * task-display.c
 *
 *  Created on: 2 dic. 2022
 *      Author: Flia König
 */

#include "task-display.h"

#define MAX (6)

extern uint8_t dpFunction;
extern uint8_t dpControl;
extern uint8_t dpMode;
extern uint8_t dpRows;
extern uint8_t dpBacklight;

extern int mediciones[3];
extern int medicion_activa;
extern int flag_resetear_mediciones;
extern int flag_medir;
static int pasada=0;

void DISPLAY_Init(uint8_t rows)
{
  dpRows = rows;

  dpBacklight = LCD_BACKLIGHT;

  dpFunction = LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS;

  /* Wait for initialization */
  DelayInit();
  HAL_Delay(50);

  ExpanderWrite(dpBacklight);
  HAL_Delay(1000);

  /* 4bit Mode */
  Write4Bits(0x03 << 4);
  DelayUS(4500);

  Write4Bits(0x03 << 4);
  DelayUS(4500);

  Write4Bits(0x03 << 4);
  DelayUS(4500);

  Write4Bits(0x02 << 4);
  DelayUS(100);

  // Control del display
  SendCommand(LCD_FUNCTIONSET | dpFunction);

  dpControl = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
  HD44780_Display();
  HD44780_Clear();

  // Modo del display
  dpMode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
  SendCommand(LCD_ENTRYMODESET | dpMode);
  DelayUS(4500);

  HD44780_Home();

  HD44780_Cursor();
  HD44780_SetCursor(0,0);
  HD44780_PrintStr("Iniciando...");
}

void DISPLAY_Update()
{
	// En cada pasada se envia una parte de los datos al display, sino tarda mucho
	switch(pasada)
	{
		case 0:
			HD44780_Clear();
			HD44780_NoCursor();
			break;
		case 1:
			HD44780_SetCursor(0,0);

			if(medicion_activa==0 && flag_medir)
			{
				HD44780_PrintStr("ME1*");
			}
			else
			{
				HD44780_PrintStr("ME1 ");
			}
			break;
		case 2:
			HD44780_SetCursor(6,0);
			if(medicion_activa==1 && flag_medir)
			{
				HD44780_PrintStr("ME2*");
			}
			else
			{
				HD44780_PrintStr("ME2 ");
			}
			break;
		case 3:
			HD44780_SetCursor(12, 0);
			if(medicion_activa==2 && flag_medir)
			{
				HD44780_PrintStr("ME3*");
			}
			else
			{
				HD44780_PrintStr("ME3 ");
			}
			break;
		case 4:
			HD44780_SetCursor(0, 1);
			if(mediciones[0] == 0)
			{
				HD44780_PrintStr("0  ");
			}
			else
			{
				WriteValue(mediciones[0]);
			}
			break;
		case 5:
			HD44780_SetCursor(6, 1);
			if(mediciones[1] == 0)
			{
				HD44780_PrintStr("0  ");
			}
			else
			{
				WriteValue(mediciones[1]);
			}
			break;
		case 6:
			HD44780_SetCursor(12, 1);
			if(mediciones[2] == 0)
			{
				HD44780_PrintStr("0  ");
			}
			else
			{
				WriteValue(mediciones[2]);
			}
			break;
	}
	pasada++;
	if(pasada >MAX)
	{
		pasada=1;
	}
}
