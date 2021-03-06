/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : RxBuf.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : RingBufferUInt8
**     Version     : Component 01.005, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-09-09, 14:34, # CodeGen: 47
**     Abstract    :
**         This component implements a ring buffer for 8bit data type.
**     Settings    :
**          Component name                                 : RxBuf
**          Buffer Size                                    : 64
**     Contents    :
**         Clear           - void RxBuf_Clear(void);
**         Put             - byte RxBuf_Put(byte elem);
**         Get             - byte RxBuf_Get(byte *elemP);
**         NofElements     - byte RxBuf_NofElements(void);
**         NofFreeElements - byte RxBuf_NofFreeElements(void);
**         Init            - void RxBuf_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2013, all rights reserved.
**     Web: http://www.mcuoneclipse.com
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/

#ifndef __RxBuf_H
#define __RxBuf_H

/* MODULE RxBuf. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"


#define RxBuf_BUF_SIZE   64  /* number of elements in the buffer */


byte RxBuf_Put(byte elem);
/*
** ===================================================================
**     Method      :  RxBuf_Put (component RingBufferUInt8)
**
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RxBuf_Get(byte *elemP);
/*
** ===================================================================
**     Method      :  RxBuf_Get (component RingBufferUInt8)
**
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RxBuf_NofElements(void);
/*
** ===================================================================
**     Method      :  RxBuf_NofElements (component RingBufferUInt8)
**
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void RxBuf_Init(void);
/*
** ===================================================================
**     Method      :  RxBuf_Init (component RingBufferUInt8)
**
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

byte RxBuf_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  RxBuf_NofFreeElements (component RingBufferUInt8)
**
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void RxBuf_Clear(void);
/*
** ===================================================================
**     Method      :  RxBuf_Clear (component RingBufferUInt8)
**
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END RxBuf. */

#endif
/* ifndef __RxBuf_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
