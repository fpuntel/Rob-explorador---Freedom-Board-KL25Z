/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LEDpin4.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-08-21, 17:49, # CodeGen: 24
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       4             |  PTE3/SPI1_MISO/SPI1_MOSI
**             ----------------------------------------------------
**
**         Port name                   : PTE
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : 0x0008
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIOE_PDOR [0x400FF100]
**         Port control register       : GPIOE_PDDR [0x400FF114]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool LEDpin4_GetVal(void);
**         PutVal - void LEDpin4_PutVal(bool Val);
**         ClrVal - void LEDpin4_ClrVal(void);
**         SetVal - void LEDpin4_SetVal(void);
**         NegVal - void LEDpin4_NegVal(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __LEDpin4_H
#define __LEDpin4_H

/* MODULE LEDpin4. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "BitIoLdd5.h"

#include "Cpu.h"




/*
** ===================================================================
**     Method      :  LEDpin4_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define LEDpin4_GetVal() (BitIoLdd5_GetVal(BitIoLdd5_DeviceData))

/*
** ===================================================================
**     Method      :  LEDpin4_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
#define LEDpin4_PutVal(Val) (BitIoLdd5_PutVal(BitIoLdd5_DeviceData, (Val)))

/*
** ===================================================================
**     Method      :  LEDpin4_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define LEDpin4_ClrVal() (BitIoLdd5_ClrVal(BitIoLdd5_DeviceData))

/*
** ===================================================================
**     Method      :  LEDpin4_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define LEDpin4_SetVal() (BitIoLdd5_SetVal(BitIoLdd5_DeviceData))

/*
** ===================================================================
**     Method      :  LEDpin4_NegVal (component BitIO)
**
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define LEDpin4_NegVal() (BitIoLdd5_NegVal(BitIoLdd5_DeviceData))

/* END LEDpin4. */

#endif 
/* ifndef __LEDpin4_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
