/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : AS1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Serial_LDD
**     Version     : Component 01.165, Driver 01.10, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-09-09, 14:34, # CodeGen: 47
**     Abstract    :
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
**     Settings    :
**          Component name                                 : AS1
**          Device                                         : UART0
**          Interrupt service/event                        : Enabled
**            Interrupt RxD                                : INT_UART0
**            Interrupt RxD priority                       : medium priority
**            Interrupt TxD                                : INT_UART0
**            Interrupt TxD priority                       : medium priority
**            Interrupt Error                              : INT_UART0
**            Interrupt Error priority                     : medium priority
**          Settings                                       : 
**            Data width                                   : 8 bits
**            Parity                                       : None
**            Stop bits                                    : 1
**            Loop mode                                    : Normal
**            Baud rate                                    : 38400 baud
**            Wakeup condition                             : Idle line wakeup
**            Stop in wait mode                            : no
**            Idle line mode                               : Starts after start bit
**            Transmitter output                           : Not inverted
**            Receiver input                               : Not inverted
**            Break generation length                      : 10/11 bits
**            Receiver                                     : Enabled
**              RxD                                        : TSI0_CH2/PTA1/UART0_RX/TPM2_CH0
**              RxD pin signal                             : 
**            Transmitter                                  : Enabled
**              TxD                                        : TSI0_CH3/PTA2/UART0_TX/TPM2_CH1
**              TxD pin signal                             : 
**            Flow control                                 : None
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
**              OnTxComplete                               : Disabled
**              OnError                                    : Disabled
**              OnBreak                                    : Disabled
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
**         Init               - LDD_TDeviceData* AS1_Init(LDD_TUserData *UserDataPtr);
**         Deinit             - void AS1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock          - LDD_TError AS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock       - LDD_TError AS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetSentDataNum     - uint16_t AS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum - uint16_t AS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __AS1_H
#define __AS1_H

/* MODULE AS1. */

#include "PE_LDD.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define AS1_PRPH_BASE_ADDRESS  0x4006A000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define AS1_Init_METHOD_ENABLED
#define AS1_Deinit_METHOD_ENABLED
#define AS1_SendBlock_METHOD_ENABLED
#define AS1_ReceiveBlock_METHOD_ENABLED
#define AS1_GetSentDataNum_METHOD_ENABLED
#define AS1_GetReceivedDataNum_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define AS1_OnBlockReceived_EVENT_ENABLED
#define AS1_OnBlockSent_EVENT_ENABLED

#define ENABLED_TX_INT        0x01U    /* TX interrupt enabled      */
#define BREAK_DETECTED        0x02U    /* Break detect              */
#define TX_COMPLETED          0x04U    /* Transmission completed    */
#define ENABLE_TX_COMPLETE    0x10U    /* Enable/Disable of TX complete detection. Used in the polling mode only. */

typedef struct {
  uint16_t SerFlag;                    /* Flags for serial communication */
  uint16_t InpRecvDataNum;             /* The counter of received characters */
  uint8_t *InpDataPtr;                 /* The buffer pointer for received characters */
  uint16_t InpDataNumReq;              /* The counter of characters to receive by ReceiveBlock() */
  uint16_t OutSentDataNum;             /* The counter of sent characters */
  uint8_t *OutDataPtr;                 /* The buffer pointer for data to be transmitted */
  uint16_t OutDataNumReq;              /* The counter of characters to be send by SendBlock() */
  LDD_RTOS_TISRVectorSettings SavedISRSettings; /* {MQXLite RTOS Adapter} Saved settings of allocated interrupt vector */
  LDD_TUserData *UserDataPtr;          /* Pointer to user data */
} AS1_TDeviceData;                     /* Device data structure type */

typedef AS1_TDeviceData *AS1_TDeviceDataPtr ; /* Pointer to the device data structure. */

LDD_TDeviceData* AS1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  AS1_Init (component Serial_LDD)
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
**         ---             - Device data structure pointer.
** ===================================================================
*/

void AS1_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  AS1_Deinit (component Serial_LDD)
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

LDD_TError AS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);
/*
** ===================================================================
**     Method      :  AS1_ReceiveBlock (component Serial_LDD)
**
**     Description :
**         Specifies the number of data to receive. The method returns
**         ERR_BUSY until the specified number of characters is
**         received. Method <CancelBlockReception> can be used to
**         cancel a running receive operation.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**         Size            - Number of characters to receive
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous receive request is
**                           pending.
** ===================================================================
*/

LDD_TError AS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);
/*
** ===================================================================
**     Method      :  AS1_SendBlock (component Serial_LDD)
**
**     Description :
**         Sends a block of characters. The method returns ERR_BUSY
**         when the previous block transmission is not completed.
**         Method <CancelBlockTransmission> can be used to cancel a
**         transmit operation. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to a buffer from where
**                           data will be sent.
**         Size            - Number of characters in the buffer.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous transmit request is
**                           pending.
** ===================================================================
*/

uint16_t AS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  AS1_GetReceivedDataNum (component Serial_LDD)
**
**     Description :
**         Returns the number of received characters in the receive
**         buffer. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Number of received characters in the
**                           receive buffer.
** ===================================================================
*/

uint16_t AS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  AS1_GetSentDataNum (component Serial_LDD)
**
**     Description :
**         Returns the number of sent characters.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - The number of sent characters.
** ===================================================================
*/

/* {MQXLite RTOS Adapter} ISR function prototype */
void AS1_Interrupt(LDD_RTOS_TISRParameter _isrParameter);
/*
** ===================================================================
**     Method      :  AS1_Interrupt (component Serial_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt. Calls InterruptTX/InterruptRX methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END AS1. */

#endif
/* ifndef __AS1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
