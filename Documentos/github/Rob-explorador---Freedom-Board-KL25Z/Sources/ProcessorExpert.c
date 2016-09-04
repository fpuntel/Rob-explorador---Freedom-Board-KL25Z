/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-07-11, 11:30, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Application.h"


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
  {
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  
  
 // APP_Run();
  
  
  
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
