/*******************************************************************************
 *  [FILE NAME]: pwm.c
 *
 *  [Author]: Hisham Elsayed
 *
 *  [DATE CREATED]: Oct 5, 2021
 *
 *  [DESCRIPTION]: Source file for PWM Driver
 *******************************************************************************/

#include <avr/io.h>
#include "pwm.h"
#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"

/*******************************************************************************
 *                         Function Definitions                                *
 *******************************************************************************/

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0=0;               /* Set Timer Initial value */
	OCR0 = duty_cycle;     /* Set Compare Value */
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);    /* set PB3/OC0 as Output pin --> pin where the PWM signal is generated from MC. */

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
