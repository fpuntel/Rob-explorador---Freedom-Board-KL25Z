/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-07-11, 11:30, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Application.h"
#include "Ultrasonico.h"

/*
** ===================================================================
**     Event       :  AS1_OnBlockReceived (module Events)
**
**     Component   :  AS1 [Serial_LDD]
**     Description :
**         This event is called when the requested number of data is
**         moved to the input buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
	UART_Desc *ptr = (UART_Desc*)UserDataPtr;
	 
	  (void)ptr->rxPutFct(ptr->rxChar); /* but received character into buffer */
	  (void)AS1_ReceiveBlock(ptr->handle, (LDD_TData *)&ptr->rxChar, sizeof(ptr->rxChar));
}

/*
** ===================================================================
**     Event       :  AS1_OnBlockSent (module Events)
**
**     Component   :  AS1 [Serial_LDD]
**     Description :
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
	 UART_Desc *ptr = (UART_Desc*)UserDataPtr;
	 
	  ptr->isSent = TRUE; /* set flag so sender knows we have finished */
}

/*
** ===================================================================
**     Event       :  TU1_OnCounterRestart (module Events)
**
**     Component   :  TU1 [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
	US_EventEchoOverflow(UserDataPtr);
}

/*
** ===================================================================
**     Event       :  TU1_OnChannel0 (module Events)
**
**     Component   :  TU1 [TimerUnit_LDD]
**     Description :
**         Called if compare register match the counter registers or
**         capture register has a new content. OnChannel0 event and
**         Timer unit must be enabled. See <SetEventMask> and
**         <GetEventMask> methods. This event is available only if a
**         <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void TU1_OnChannel0(LDD_TUserData *UserDataPtr)
{
	US_EventEchoCapture(UserDataPtr);
}

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  SS1_OnBlockSent (module Events)
**
**     Component   :  SS1 [SPISlave_LDD]
**     Description :
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
**     Returns     : Nothing
** ===================================================================
*/
void SS1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  SS1_OnBlockReceived (module Events)
**
**     Component   :  SS1 [SPISlave_LDD]
**     Description :
**         This event is called when the requested number of data is
**         moved to the input buffer. This method is available only if
**         the ReceiveBlock method is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
**     Returns     : Nothing
** ===================================================================
*/
void SS1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TU1_OnChannel1 (module Events)
**
**     Component   :  TU1 [TimerUnit_LDD]
**     Description :
**         Called if compare register match the counter registers or
**         capture register has a new content. OnChannel1 event and
**         Timer unit must be enabled. See <SetEventMask> and
**         <GetEventMask> methods. This event is available only if a
**         <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void TU1_OnChannel1(LDD_TUserData *UserDataPtr)
{
	US_EventEchoCapture(UserDataPtr);
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kin0etis series of microcontrollers.
**
** ###################################################################
*/
