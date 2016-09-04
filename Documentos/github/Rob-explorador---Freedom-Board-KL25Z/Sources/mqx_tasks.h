/** ###################################################################
**     Filename    : mqx_tasks.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-08-23, 18:17, # CodeGen: 29
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Task1_task - void Task1_task(void* task_init_data);
**
** ###################################################################*/

#ifndef __mqx_tasks_H
#define __mqx_tasks_H
/* MODULE mqx_tasks */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "AS1.h"
#include "RxBuf.h"
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "TRIG.h"
#include "TU1.h"
#include "WAIT1.h"
#include "UTIL1.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "BitIoLdd2.h"
#include "TU2.h"
#include "LED2.h"
#include "Inhr1.h"
#include "PwmLdd1.h"
#include "TU3.h"
#include "LED3.h"
#include "LEDpin3.h"
#include "BitIoLdd4.h"
#include "Inhr2.h"
#include "PwmLdd2.h"
#include "MF01.h"
#include "LEDpin4.h"
#include "BitIoLdd5.h"
#include "MF02.h"
#include "LEDpin5.h"
#include "BitIoLdd6.h"
#include "MQX1.h"
#include "SystemTimer1.h"
#include "P1.h"
#include "BitIoLdd7.h"
#include "P2.h"
#include "BitIoLdd8.h"
#include "P3.h"
#include "BitIoLdd9.h"
#include "P4.h"
#include "BitIoLdd10.h"
#include "SS1.h"
#include "TRIG2.h"
#include "PE_LDD.h"



void Task1_task(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  Task1_task (module mqx_tasks)
**
**     Component   :  Task1 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/




void Task2_task(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  Task2_task (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/



void Task3_task(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  Task3_task (module mqx_tasks)
**
**     Component   :  Task3 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/

/* END mqx_tasks */
#endif /* __mqx_tasks_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
