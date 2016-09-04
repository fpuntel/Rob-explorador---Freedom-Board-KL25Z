/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TU3.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-08-21, 10:54, # CodeGen: 19
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU3
**          Module name                                    : TPM2
**          Counter                                        : TPM2_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Input clock source                             : Internal
**            Counter frequency                            : Auto select
**          Counter restart                                : On-match
**            Period device                                : TPM2_MOD
**            Period                                       : 3 ms
**            Interrupt                                    : Disabled
**          Channel list                                   : 1
**            Channel 0                                    : 
**              Mode                                       : Compare
**                Compare                                  : TPM2_C0V
**                Offset                                   : 1.5 ms
**                Output on compare                        : Set
**                  Output on overrun                      : Clear
**                  Initial state                          : Low
**                  Output pin                             : ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX
**                  Output pin signal                      : 
**                Interrupt                                : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Disabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
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
**         Init               - LDD_TDeviceData* TU3_Init(LDD_TUserData *UserDataPtr);
**         Deinit             - void TU3_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable             - LDD_TError TU3_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable            - LDD_TError TU3_Disable(LDD_TDeviceData *DeviceDataPtr);
**         GetPeriodTicks     - LDD_TError TU3_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TU3_TValueType...
**         ResetCounter       - LDD_TError TU3_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
**         GetCounterValue    - TU3_TValueType TU3_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
**         SetOffsetTicks     - LDD_TError TU3_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         GetOffsetTicks     - LDD_TError TU3_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         SelectOutputAction - LDD_TError TU3_SelectOutputAction(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TU3_H
#define __TU3_H

/* MODULE TU3. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "TPM_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_TU3_TValueType
#define __BWUserType_TU3_TValueType
  typedef uint16_t TU3_TValueType ;    /* Type for data parameters of methods */
#endif
#define TU3_CNT_INP_FREQ_U_0 0x01400000UL /* Counter input frequency in Hz */
#define TU3_CNT_INP_FREQ_R_0 20971395.017196544F /* Counter input frequency in Hz */
#define TU3_CNT_INP_FREQ_COUNT 0U      /* Count of predefined counter input frequencies */
#define TU3_PERIOD_TICKS   0xF5C3UL    /* Initialization value of period in 'counter ticks' */
#define TU3_NUMBER_OF_CHANNELS 0x01U   /* Count of predefined channels */
#define TU3_COUNTER_WIDTH  0x10U       /* Counter width in bits  */
#define TU3_COUNTER_DIR    DIR_UP      /* Direction of counting */
#define TU3_OFFSET_0_TICKS 0x7AE1ul    /* Initialization value of offset as 'counter ticks' for channel 0 */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TU3_PRPH_BASE_ADDRESS  0x4003A000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define TU3_Init_METHOD_ENABLED
#define TU3_Deinit_METHOD_ENABLED
#define TU3_Enable_METHOD_ENABLED
#define TU3_Disable_METHOD_ENABLED
#define TU3_GetPeriodTicks_METHOD_ENABLED
#define TU3_ResetCounter_METHOD_ENABLED
#define TU3_GetCounterValue_METHOD_ENABLED
#define TU3_SetOffsetTicks_METHOD_ENABLED
#define TU3_GetOffsetTicks_METHOD_ENABLED
#define TU3_SelectOutputAction_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */



LDD_TDeviceData* TU3_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  TU3_Init (component TimerUnit_LDD)
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

void TU3_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU3_Deinit (component TimerUnit_LDD)
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

LDD_TError TU3_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU3_Enable (component TimerUnit_LDD)
**
**     Description :
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask). The method is
**         not available if the counter can't be disabled/enabled by HW.
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

LDD_TError TU3_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU3_Disable (component TimerUnit_LDD)
**
**     Description :
**         Disables the component - it stops signal generation and
**         events calling. The method is not available if the counter
**         can't be disabled/enabled by HW.
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

LDD_TError TU3_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TU3_TValueType *TicksPtr);
/*
** ===================================================================
**     Method      :  TU3_GetPeriodTicks (component TimerUnit_LDD)
**
**     Description :
**         Returns the number of counter ticks before re-initialization.
**         See also method <SetPeriodTicks>. This method is available
**         only if the property <"Counter restart"> is switched to
**         'on-match' value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * TicksPtr        - Pointer to return value of the
**                           number of counter ticks before
**                           re-initialization
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError TU3_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU3_ResetCounter (component TimerUnit_LDD)
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

TU3_TValueType TU3_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU3_GetCounterValue (component TimerUnit_LDD)
**
**     Description :
**         Returns the content of counter register. This method can be
**         used both if counter is enabled and if counter is disabled.
**         The method is not available if HW doesn't allow reading of
**         the counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Counter value (number of counted ticks).
** ===================================================================
*/

LDD_TError TU3_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU3_TValueType Ticks);
/*
** ===================================================================
**     Method      :  TU3_SetOffsetTicks (component TimerUnit_LDD)
**
**     Description :
**         Sets the new offset value to channel specified by the
**         parameter ChannelIdx. It is user responsibility to use value
**         below selected period. This method is available when at
**         least one channel is configured.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         ChannelIdx      - Index of the component
**                           channel.
**         Ticks           - Number of counter ticks to compare
**                           match.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel
**                           ERR_PARAM_TICKS - Ticks parameter is out of
**                           possible range.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError TU3_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU3_TValueType *TicksPtr);
/*
** ===================================================================
**     Method      :  TU3_GetOffsetTicks (component TimerUnit_LDD)
**
**     Description :
**         Returns the number of counter ticks to compare match channel
**         specified by the parameter ChannelIdx. See also method
**         <SetOffsetTicks>. This method is available when at least one
**         channel is configured.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         ChannelIdx      - Index of the component
**                           channel.
**       * TicksPtr        - Pointer to return value of the
**                           number of counter ticks to compare match.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError TU3_SelectOutputAction(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, LDD_TimerUnit_TOutAction CompareAction, LDD_TimerUnit_TOutAction CounterAction);
/*
** ===================================================================
**     Method      :  TU3_SelectOutputAction (component TimerUnit_LDD)
**
**     Description :
**         Sets the type of compare match and counter overflow action
**         on channel output. This method is available when at least
**         one channel is configured.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         ChannelIdx      - Index of the component
**                           channel.
**         CompareAction   - Select output action
**                           on compare match
**         CounterAction   - Select output action
**                           on counter overflow
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range
**                           ERR_NOTAVAIL -  Action is not possible on
**                           selected channel or counter. Supported
**                           combinations are HW specific.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

/* END TU3. */

#endif
/* ifndef __TU3_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
