/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TU1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-09-10, 10:17, # CodeGen: 54
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU1
**          Module name                                    : TPM0
**          Counter                                        : TPM0_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : 2.62144 MHz
**          Counter restart                                : On-overrun
**            Overrun period                               : Auto select
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_TPM0
**              Interrupt priority                         : medium priority
**          Channel list                                   : 2
**            Channel 0                                    : 
**              Mode                                       : Capture
**                Capture                                  : TPM0_C4V
**                Capture input pin                        : PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4
**                Capture input signal                     : US_Echo_D2
**                Edge                                     : both edges
**                Maximum time of event                    : 25.00001792 ms
**                Interrupt                                : Enabled
**                  Interrupt                              : INT_TPM0
**                  Interrupt priority                     : medium priority
**            Channel 1                                    : 
**              Mode                                       : Capture
**                Capture                                  : TPM0_C5V
**                Capture input pin                        : ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5
**                Capture input signal                     : 
**                Edge                                     : both edges
**                Maximum time of event                    : 25.00001792 ms
**                Interrupt                                : Enabled
**                  Interrupt                              : INT_TPM0
**                  Interrupt priority                     : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Enabled
**              OnChannel0                                 : Enabled
**              OnChannel1                                 : Enabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init            - LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr);
**         Deinit          - void TU1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         ResetCounter    - LDD_TError TU1_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
**         GetCaptureValue - LDD_TError TU1_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TU1_H
#define __TU1_H

/* MODULE TU1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "TPM_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_TU1_TValueType
#define __BWUserType_TU1_TValueType
  typedef uint32_t TU1_TValueType ;    /* Type for data parameters of methods */
#endif
#define TU1_CNT_INP_FREQ_U_0 0x00280000UL /* Counter input frequency in Hz */
#define TU1_CNT_INP_FREQ_R_0 2621438.120953155F /* Counter input frequency in Hz */
#define TU1_CNT_INP_FREQ_COUNT 0U      /* Count of predefined counter input frequencies */
#define TU1_PERIOD_TICKS   0x00010000UL /* Initialization value of period in 'counter ticks' */
#define TU1_NUMBER_OF_CHANNELS 0x02U   /* Count of predefined channels */
#define TU1_COUNTER_WIDTH  0x10U       /* Counter width in bits  */
#define TU1_COUNTER_DIR    DIR_UP      /* Direction of counting */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TU1_PRPH_BASE_ADDRESS  0x40038000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define TU1_Init_METHOD_ENABLED
#define TU1_Deinit_METHOD_ENABLED
#define TU1_ResetCounter_METHOD_ENABLED
#define TU1_GetCaptureValue_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define TU1_OnCounterRestart_EVENT_ENABLED
#define TU1_OnChannel0_EVENT_ENABLED
#define TU1_OnChannel1_EVENT_ENABLED



LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  TU1_Init (component TimerUnit_LDD)
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

void TU1_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU1_Deinit (component TimerUnit_LDD)
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

LDD_TError TU1_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU1_ResetCounter (component TimerUnit_LDD)
**
**     Description :
**         Resets counter. If counter is counting up then it is set to
**         zero. If counter is counting down then counter is updated to
**         the reload value.
**         The method is not available if HW doesn't allow resetting of
**         the counter.
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

LDD_TError TU1_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU1_TValueType *ValuePtr);
/*
** ===================================================================
**     Method      :  TU1_GetCaptureValue (component TimerUnit_LDD)
**
**     Description :
**         Returns the content of capture register specified by the
**         parameter ChannelIdx. This method is available when at least
**         one channel is configured.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         ChannelIdx      - Index of the component
**                           channel.
**       * ValuePtr        - Pointer to return value of the
**                           capture register.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range
**                           ERR_NOTAVAIL -  The capture mode is not
**                           selected for selected channel.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

/* {MQXLite RTOS Adapter} ISR function prototype */
void TU1_Interrupt(LDD_RTOS_TISRParameter _isrParameter);
/*
** ===================================================================
**     Method      :  TU1_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END TU1. */

#endif
/* ifndef __TU1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/