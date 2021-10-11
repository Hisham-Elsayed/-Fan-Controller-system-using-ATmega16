/*******************************************************************************
 *  [FILE NAME]: adc.h
 *
 *  [Author]: Hisham Elsayed
 *
 *  [DATE CREATED]: Oct 6, 2021
 *
 *  [DESCRIPTION]: Header file for ADC Driver
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*********************************************************
 *                    Types Declaration                  *
 *********************************************************/
typedef enum
{
	AREF,AVCC,Reserved,Internal_AREF
}ADC_ReferenceVoltage;

typedef enum
{
	Div_Factor2,Div_Factorr2,Div_Factor4,Div_Factor8,Div_Factor16,Div_Factor32,Div_Factor64,Div_Factor128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                   Function Prototypes                                       *
 *******************************************************************************/


/***************************************************************************************************
 * [Function Name]:         ADC_init
 *
 * [Description]:           The Function responsible for initializing the driver and Choosing the Pre-scaler
 *                          and the Reference voltage for an ADC Channel.
 *
 * [Arguments]:             Constant Pointer to structure ADC_ConfigType
 *
 * [Returns]:               VOID
 ***************************************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr);

/***************************************************************************************************
 * [Function Name]:         ADC_readChannel
 *
 * [Description]:           The Function responsible for reading ADC channel
 *
 * [Arguments]:             unsigned char ADC Channel number
 *
 * [Returns]:               Returns the converted digital data from data register
 ***************************************************************************************************/

uint16 ADC_readChannel(uint8 channel_num);




#endif /* ADC_H_ */
