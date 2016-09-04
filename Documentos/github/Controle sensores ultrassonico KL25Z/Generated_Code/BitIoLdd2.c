/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : BitIoLdd2.c
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
**          Component name                                 : BitIoLdd2
**          Pin for I/O                                    : TSI0_CH12/PTB19/TPM2_CH1
**          Pin signal                                     : 
**          Direction                                      : Output
**          Initialization                                 : 
**            Init. direction                              : Output
**            Init. value                                  : 0
**            Auto Initialization                          : yes
**          Safe mode                                      : yes
**     Contents    :
**         Init   - LDD_TDeviceData* BitIoLdd2_Init(LDD_TUserData *UserDataPtr);
**         GetVal - bool BitIoLdd2_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         PutVal - void BitIoLdd2_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val);
**         ClrVal - void BitIoLdd2_ClrVal(LDD_TDeviceData *DeviceDataPtr);
**         SetVal - void BitIoLdd2_SetVal(LDD_TDeviceData *DeviceDataPtr);
**         NegVal - void BitIoLdd2_NegVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE BitIoLdd2. */

#include "BitIoLdd2.h"

typedef struct {
  LDD_TUserData *UserDataPtr;          /* Pointer to user data */
} BitIoLdd2_TDeviceData;               /* Device data structure type */

typedef BitIoLdd2_TDeviceData *BitIoLdd2_TDeviceDataPtr ; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static BitIoLdd2_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  BitIoLdd2_Init (component BitIO_LDD)
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
LDD_TDeviceData* BitIoLdd2_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  BitIoLdd2_TDeviceDataPtr DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */

  /* Configure pin as output */
  /* GPIOB_PDDR: PDD|=0x00080000 */
  GPIOB_PDDR |= GPIO_PDDR_PDD(0x00080000);                                                   

  /* Set initialization value */
  /* GPIOB_PDOR: PDO&=~0x00080000 */
  GPIOB_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(0x00080000));                                                   

  /* Initialization of Port Control register */
  /* PORTB_PCR19: ISF=0,MUX=1 */
  PORTB_PCR19 = (uint32_t)((PORTB_PCR19 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));                                                  
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_BitIoLdd2_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}
/*
** ===================================================================
**     Method      :  BitIoLdd2_GetVal (component BitIO_LDD)
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
bool BitIoLdd2_GetVal(LDD_TDeviceData *DeviceDataPtr)
{
  uint32_t portData;                   /* Port data masked according to the bit used */

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  portData = GPIO_PDD_GetPortDataOutput(BitIoLdd2_MODULE_BASE_ADDRESS) & BitIoLdd2_PORT_MASK;

  return (portData != 0U) ? (bool)TRUE : (bool)FALSE;
}

/*
** ===================================================================
**     Method      :  BitIoLdd2_PutVal (component BitIO_LDD)
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
void BitIoLdd2_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  if (Val) {
    GPIO_PDD_SetPortDataOutputMask(BitIoLdd2_MODULE_BASE_ADDRESS, BitIoLdd2_PORT_MASK);
  } else { /* !Val */
    GPIO_PDD_ClearPortDataOutputMask(BitIoLdd2_MODULE_BASE_ADDRESS, BitIoLdd2_PORT_MASK);
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  BitIoLdd2_ClrVal (component BitIO_LDD)
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
void BitIoLdd2_ClrVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  GPIO_PDD_ClearPortDataOutputMask(BitIoLdd2_MODULE_BASE_ADDRESS, BitIoLdd2_PORT_MASK);
}

/*
** ===================================================================
**     Method      :  BitIoLdd2_SetVal (component BitIO_LDD)
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
void BitIoLdd2_SetVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  GPIO_PDD_SetPortDataOutputMask(BitIoLdd2_MODULE_BASE_ADDRESS, BitIoLdd2_PORT_MASK);
}

/*
** ===================================================================
**     Method      :  BitIoLdd2_NegVal (component BitIO_LDD)
**
**     Description :
**         Negates (inverts) the output value. It is equivalent to the
**         [PutVal(!GetVal())]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/
void BitIoLdd2_NegVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  GPIO_PDD_TogglePortDataOutputMask(BitIoLdd2_MODULE_BASE_ADDRESS, BitIoLdd2_PORT_MASK);
}

/* END BitIoLdd2. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
