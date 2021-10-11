/*******************************************************************************
 *  [FILE NAME]: lm35_sensor.h
 *
 *  [Author]: Hisham Elsayed
 *
 *  [DATE CREATED]: Oct 6, 2021
 *
 *  [DESCRIPTION]: Header file for lm35 sensor Driver                                       *
 *******************************************************************************/



#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/


/***************************************************************************************************
 * [Function Name]:          LM35_GetTemperature
 *
 * [Description]:            Function used to Read ADC channel where the temperature sensor is connected.
 *                           and Calculate the temperature from the ADC value
 *
 * [Arguments]:              VOID
 *
 * [Returns]:                The value of the measured temperature
 ***************************************************************************************************/

uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
