/*******************************************************************************
 *  [FILE NAME]: mini_project.c
 *
 *  [Author]: Hisham Elsayed
 *
 *  [DATE CREATED]: Oct 6, 2021
 *
 *  [DESCRIPTION]: Application file for Mini Project 3
 *******************************************************************************/

#include <avr/io.h>
#include "pwm.h"
#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "adc.h"
#include "lm35_sensor.h"

typedef enum
{
	OFF,ON
}FanState;


int main()
{
	uint8 temp=0;
	FanState State;

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {Internal_AREF,Div_Factor8};


	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Config); /* initialize ADC driver */

	DcMotor_Init(); /* initialize DC Motor driver */

	LCD_displayStringRowColumn(0, 4,"Fan is ");
	LCD_displayStringRowColumn(1,4,"Temp=     C ");
	while (1)
	{
		if ( State == ON)
		{
			LCD_displayStringRowColumn(0, 11, "ON");
		}
		else if ( State == OFF)
		{
			LCD_displayStringRowColumn(0, 11, "OFF");
		}
		temp = LM35_getTemperature();

		if(temp < 30)
		{
			State = OFF;
			DcMotor_Rotate(Stop, 0);
		}
		else
		{
			State = ON;
			LCD_displayCharacter(' ');  /* To prevent error like "ONF" to be written */
			if( temp >= 30 && temp < 60 )
			{
				DcMotor_Rotate(Clockwise,25);
			}
			else if( temp >=60 )
			{
				DcMotor_Rotate(Clockwise,50);
			}
			else if( temp >= 90)
			{
				DcMotor_Rotate(Clockwise,75);
			}
			else if( temp >= 120)
			{
				DcMotor_Rotate(Clockwise,100);
			}
		}

		LCD_moveCursor(1,11);
		if(temp >= 100)
		{
			LCD_integerToString(temp);
		}
		else
		{
			LCD_integerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}

