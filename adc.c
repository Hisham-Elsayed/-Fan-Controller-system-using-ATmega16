/*******************************************************************************
 *  [FILE NAME]: adc.c
 *
 *  [Author]: Hisham Elsayed
 *
 *  [DATE CREATED]: Oct 6, 2021
 *
 *  [DESCRIPTION]: Source file for ADC Driver
 *******************************************************************************/

#include <avr/io.h>
#include "adc.h"
#include "gpio.h"
#include "common_macros.h"

/*********************************************************
 *                   Function Definitions               *
 ********************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* Use internal 2.56V with external capacitor at AREF pin */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr -> ref_volt )<<REFS0);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA |= (1<<ADEN);
	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr -> prescaler)&0x07);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX = (ADMUX & 0xE0); /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}

