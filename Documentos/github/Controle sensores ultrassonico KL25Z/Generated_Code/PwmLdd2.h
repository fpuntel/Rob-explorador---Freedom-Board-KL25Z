/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PwmLdd2.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : PWM_LDD
**     Version     : Component 01.000, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-08-21, 10:54, # CodeGen: 19
**     Abstract    :
**          This component implements a pulse-width modulation generator
**          that generates signal with variable duty and fixed cycle.
**          This PWM component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : PwmLdd2
**          Period device                                  : TPM2_MOD
**          Duty device                                    : TPM2_C0V
**          Output pin                                     : ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX
**          Output pin signal                              : 
**          Counter                                        : TPM2_CNT
**          Linked TimerUnit                               : TU3
**          Interrupt service/event                        : Disabled
**          Period                                         : 3 ms
**          Starting pulse width                           : 1.5 ms
**          Initial polarity                               : low
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnEnd                                      : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component enabled
**            Clock configuration 2                        : This component enabled
**            Clock configuration 3                        : This component enabled
**            Clock configuration 4                        : This component enabled
**            Clock configuration 5                        : This component enabled
**            Clock configuration 6                        : This component enabled
**            Clock configuration 7                        : This component enabled
**     Contents    :
**         Init       - LDD_TDeviceData* PwmLdd2_Init(LDD_TUserData *UserDataPtr);
**         Deinit     - void PwmLdd2_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable     - LDD_TError PwmLdd2_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable    - LDD_TError PwmLdd2_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetRatio8  - LDD_TError PwmLdd2_SetRatio8(LDD_TDeviceData *DeviceDataPtr, uint8_t Ratio);
**         SetRatio16 - LDD_TError PwmLdd2_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio);
**         SetDutyUS  - LDD_TError PwmLdd2_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetDutyMS  - LDD_TError PwmLdd2_SetDutyMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __PwmLdd2_H
#define __PwmLdd2_H

/* MODULE PwmLdd2. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "TU3.h"
#include "PE_LDD.h"
#include "TPM_PDD.h"

#include "Cpu.h"


#define PwmLdd2_PERIOD_VALUE 0xF5C3UL  /* Initial period value in ticks of the timer. */
#define PwmLdd2_PERIOD_VALUE_0 0xF5C3UL /* Period value in ticks of the timer in clock configuration 0. */

/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define PwmLdd2_PRPH_BASE_ADDRESS  0x4003A000U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define PwmLdd2_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_PwmLdd2_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define PwmLdd2_Init_METHOD_ENABLED
#define PwmLdd2_Deinit_METHOD_ENABLED
#define PwmLdd2_Enable_METHOD_ENABLED
#define PwmLdd2_Disable_METHOD_ENABLED
#define PwmLdd2_SetRatio8_METHOD_ENABLED
#define PwmLdd2_SetRatio16_METHOD_ENABLED
#define PwmLdd2_SetDutyUS_METHOD_ENABLED
#define PwmLdd2_SetDutyMS_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */



LDD_TDeviceData* PwmLdd2_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  PwmLdd2_Init (component PWM_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void PwmLdd2_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  PwmLdd2_Deinit (component PWM_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError PwmLdd2_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  PwmLdd2_Enable (component PWM_LDD)
**
**     Description :
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError PwmLdd2_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  PwmLdd2_Disable (component PWM_LDD)
**
**     Description :
**         Disables the component - it stops signal generation and
**         events calling.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError PwmLdd2_SetRatio8(LDD_TDeviceData *DeviceDataPtr, uint8_t Ratio);
/*
** ===================================================================
**     Method      :  PwmLdd2_SetRatio8 (component PWM_LDD)
**
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as an 8-bit unsigned integer number. 0 - FF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer capabilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Ratio           - Ratio to set. 0 - 255 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError PwmLdd2_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio);
/*
** ===================================================================
**     Method      :  PwmLdd2_SetRatio16 (component PWM_LDD)
**
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError PwmLdd2_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
/*
** ===================================================================
**     Method      :  PwmLdd2_SetDutyUS (component PWM_LDD)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit unsigned
**         integer number. The method is available only if it is not
**         selected list of predefined values in <Starting pulse width>
**         property.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Time            - Duty to set [in microseconds]
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

LDD_TError PwmLdd2_SetDutyMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
/*
** ===================================================================
**     Method      :  PwmLdd2_SetDutyMS (component PWM_LDD)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit unsigned
**         integer number. The method is available only if it is not
**         selected list of predefined values in <Starting pulse width>
**         property.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Time            - Duty to set [in milliseconds]
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

/* END PwmLdd2. */

#endif 
/* ifndef __PwmLdd2_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
