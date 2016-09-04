/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TRIG.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : BitIO_LDD
**     Version     : Component 01.031, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-08-21, 10:54, # CodeGen: 19
**     Abstract    :
**         The HAL BitIO component provides a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL BitIO API are simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : TRIG
**          Pin for I/O                                    : PTA12/TPM1_CH0
**          Pin signal                                     : US_Trig_D3
**          Direction                                      : Input/Output
**          Initialization                                 : 
**            Init. direction                              : Output
**            Init. value                                  : 0
**            Auto Initialization                          : no
**          Safe mode                                      : no
**     Contents    :
**         Init   - LDD_TDeviceData* TRIG_Init(LDD_TUserData *UserDataPtr);
**         Deinit - void TRIG_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetDir - void TRIG_SetDir(LDD_TDeviceData *DeviceDataPtr, bool Dir);
**         GetVal - bool TRIG_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         PutVal - void TRIG_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val);
**         ClrVal - void TRIG_ClrVal(LDD_TDeviceData *DeviceDataPtr);
**         SetVal - void TRIG_SetVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TRIG_H
#define __TRIG_H

/* MODULE TRIG. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"

#include "Cpu.h"



/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TRIG_PRPH_BASE_ADDRESS  0x400FF000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define TRIG_Init_METHOD_ENABLED
#define TRIG_Deinit_METHOD_ENABLED
#define TRIG_SetDir_METHOD_ENABLED
#define TRIG_GetVal_METHOD_ENABLED
#define TRIG_PutVal_METHOD_ENABLED
#define TRIG_ClrVal_METHOD_ENABLED
#define TRIG_SetVal_METHOD_ENABLED

/* Definition of implementation constants */
#define TRIG_MODULE_BASE_ADDRESS FPTA_BASE_PTR /* Name of macro used as the base address */
#define TRIG_PORTCONTROL_BASE_ADDRESS PORTA_BASE_PTR /* Name of macro used as the base address */
#define TRIG_PORT_MASK 0x1000U         /* Mask of the allocated pin from the port */



LDD_TDeviceData* TRIG_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  TRIG_Init (component BitIO_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
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

void TRIG_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TRIG_Deinit (component BitIO_LDD)
**
**     Description :
**          Deinitializes the device. Switches off the device, frees
**         the device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

void TRIG_SetDir(LDD_TDeviceData *DeviceDataPtr, bool Dir);
/*
** ===================================================================
**     Method      :  TRIG_SetDir (component BitIO_LDD)
**
**     Description :
**         Sets a pin direction (available only if the direction =
**         _[input/output]_).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Dir             - Direction to set. Possible values:
**                           <false> - Input
**                           <true> - Output
**     Returns     : Nothing
** ===================================================================
*/

bool TRIG_GetVal(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TRIG_GetVal (component BitIO_LDD)
**
**     Description :
**         Returns the input/output value. If the direction is [input]
**         then the input value of the pin is read and returned. If the
**         direction is [output] then the last written value is read
**         and returned (see <Safe mode> property for limitations).
**         This method cannot be disabled if direction is [input].
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Input or output value. Possible values:
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
** ===================================================================
*/

void TRIG_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val);
/*
** ===================================================================
**     Method      :  TRIG_PutVal (component BitIO_LDD)
**
**     Description :
**         The specified output value is set. If the direction is <b>
**         input</b>, the component saves the value to a memory or a
**         register and this value will be written to the pin after
**         switching to the output mode (using <tt>SetDir(TRUE)</tt>;
**         see <a href="BitIOProperties.html#SafeMode">Safe mode</a>
**         property for limitations). If the direction is <b>output</b>,
**         it writes the value to the pin. (Method is available only if
**         the direction = <u><tt>output</tt></u> or <u><tt>
**         input/output</tt></u>).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Val             - Output value. Possible values:
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/

void TRIG_ClrVal(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TRIG_ClrVal (component BitIO_LDD)
**
**     Description :
**         Clears (set to zero) the output value. It is equivalent to
**         the [PutVal(FALSE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

void TRIG_SetVal(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TRIG_SetVal (component BitIO_LDD)
**
**     Description :
**         Sets (to one) the output value. It is equivalent to the
**         [PutVal(TRUE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

/* END TRIG. */

#endif
/* ifndef __TRIG_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/