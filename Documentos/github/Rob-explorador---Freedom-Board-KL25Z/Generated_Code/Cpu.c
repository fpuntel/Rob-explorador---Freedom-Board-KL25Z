/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : MKL25Z128LK4
**     Version     : Component 01.025, Driver 01.04, CPU db: 3.00.000
**     Datasheet   : KL25P80M48SF0RM, Rev.3, Sep 2012
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-09-09, 15:40, # CodeGen: 48
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Cpu. */
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
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Cpu.h"

/* Global variables */
volatile uint8_t SR_reg;               /* Current value of the FAULTMASK register */
volatile uint8_t SR_lock = 0x00U;      /* Lock */


/*
** ===================================================================
**     Method      :  Cpu_INT_NMIInterrupt (component MKL25Z128LK4)
**
**     Description :
**         This ISR services the Non Maskable Interrupt interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cpu_INT_NMIInterrupt(void)
{
  Cpu_OnNMIINT();
}

/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MKL25Z128LK4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  PE_DEBUGHALT();
}


/*** !!! Here you can place your own code using property "User data declarations" on the build options tab. !!! ***/

/*lint -esym(765,__init_hardware) Disable MISRA rule (8.10) checking for symbols (__init_hardware). The function is linked to the EWL library */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cpu_Interrupt). */
void __init_hardware(void)
{

  /*** !!! Here you can place your own code before PE initialization using property "User code before PE initialization" on the build options tab. !!! ***/

  /*** ### MKL25Z128VLK4 "Cpu" init code ... ***/
  /*** PE initialization code after reset ***/
  SCB_VTOR = (uint32_t)(&__vect_table); /* Set the interrupt vector table position */
  /* Disable the WDOG module */
  /* SIM_COPC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COPT=0,COPCLKS=0,COPW=0 */
  SIM_COPC = 0x00U;                                                   
  /* System clock initialization */
  /* SIM_SCGC5: PORTE=1,PORTD=1,PORTC=1,PORTB=1,PORTA=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK |
               SIM_SCGC5_PORTD_MASK |
               SIM_SCGC5_PORTC_MASK |
               SIM_SCGC5_PORTB_MASK |
               SIM_SCGC5_PORTA_MASK;   /* Enable clock gate for ports to enable pin routing */
  /* SIM_CLKDIV1: OUTDIV1=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,OUTDIV4=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = 0x00U;                 /* Update system prescalers */
  /* SIM_SOPT2: PLLFLLSEL=0 */
  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_PLLFLLSEL_MASK); /* Select FLL as a clock source for various peripherals */
  /* SIM_SOPT1: OSC32KSEL=3 */
  SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x03); /* LPO 1kHz oscillator drives 32 kHz clock for various peripherals */
  /* SIM_SOPT2: TPMSRC=1 */
  SIM_SOPT2 = (uint32_t)((SIM_SOPT2 & (uint32_t)~(uint32_t)(
               SIM_SOPT2_TPMSRC(0x02)
              )) | (uint32_t)(
               SIM_SOPT2_TPMSRC(0x01)
              ));                      /* Set the TPM clock */
  /* Switch to FEI Mode */
  /* MCG_C1: CLKS=0,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK);                                                   
  /* MCG_C2: LOCRE0=0,??=0,RANGE0=0,HGO0=0,EREFS0=0,LP=0,IRCS=0 */
  MCG_C2 = 0x00U;                                                   
  /* MCG_C4: DMX32=0,DRST_DRS=0 */
  MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));                                                   
  /* OSC0_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC0_CR = OSC_CR_ERCLKEN_MASK;                                                   
  /* MCG_C5: ??=0,PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
  MCG_C5 = 0x00U;                                                   
  /* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
  MCG_C6 = 0x00U;                                                   
  while((MCG_S & MCG_S_IREFST_MASK) == 0x00U) { /* Check that the source of the FLL reference clock is the internal reference clock. */
  }
  while((MCG_S & 0x0CU) != 0x00U) {    /* Wait until output of the FLL is selected */
  }
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code after PE initialization using property "User code after PE initialization" on the build options tab. !!! ***/

}



/*
** ===================================================================
**     Method      :  PE_low_level_init (component MKL25Z128LK4)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /* {MQXLite RTOS Adapter} Set new interrupt vector (function handler and ISR parameter) */
      /* Initialization of the SIM module */
  /* PORTA_PCR4: ISF=0,MUX=7 */
  PORTA_PCR4 = (uint32_t)((PORTA_PCR4 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK
               )) | (uint32_t)(
                PORT_PCR_MUX(0x07)
               ));                                                  
        /* Initialization of the RCM module */
  /* RCM_RPFW: RSTFLTSEL=0 */
  RCM_RPFW &= (uint8_t)~(uint8_t)(RCM_RPFW_RSTFLTSEL(0x1F));                                                   
  /* RCM_RPFC: RSTFLTSS=0,RSTFLTSRW=0 */
  RCM_RPFC &= (uint8_t)~(uint8_t)(
               RCM_RPFC_RSTFLTSS_MASK |
               RCM_RPFC_RSTFLTSRW(0x03)
              );                                                   
        /* Initialization of the FTFL_FlashConfig module */
      /* Initialization of the PMC module */
  /* PMC_LVDSC1: LVDACK=1,LVDIE=0,LVDRE=1,LVDV=0 */
  PMC_LVDSC1 = (uint8_t)((PMC_LVDSC1 & (uint8_t)~(uint8_t)(
                PMC_LVDSC1_LVDIE_MASK |
                PMC_LVDSC1_LVDV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC1_LVDACK_MASK |
                PMC_LVDSC1_LVDRE_MASK
               ));                                                  
  /* PMC_LVDSC2: LVWACK=1,LVWIE=0,LVWV=0 */
  PMC_LVDSC2 = (uint8_t)((PMC_LVDSC2 & (uint8_t)~(uint8_t)(
                PMC_LVDSC2_LVWIE_MASK |
                PMC_LVDSC2_LVWV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC2_LVWACK_MASK
               ));                                                  
  /* PMC_REGSC: BGEN=0,ACKISO=0,BGBE=0 */
  PMC_REGSC &= (uint8_t)~(uint8_t)(
                PMC_REGSC_BGEN_MASK |
                PMC_REGSC_ACKISO_MASK |
                PMC_REGSC_BGBE_MASK
               );                                                   
  /* SMC_PMPROT: ??=0,??=0,AVLP=0,??=0,ALLS=0,??=0,AVLLS=0,??=0 */
  SMC_PMPROT = 0x00U;                  /* Setup Power mode protection register */
  /* Common initialization of the CPU registers */
  /* PORTA_PCR20: ISF=0,MUX=7 */
  PORTA_PCR20 = (uint32_t)((PORTA_PCR20 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x07)
                ));                                                  
  /* NVIC_IPR1: PRI_6=0 */
  NVIC_IPR1 &= (uint32_t)~(uint32_t)(NVIC_IP_PRI_6(0xFF));                                                   
  /* ### RingBufferUInt8 "RxBuf" init code ... */
  RxBuf_Init();
  /* ### BitIO_LDD "BitIoLdd1" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd1_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd2" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd2_Init(NULL);
  /* ### LED "LED1" init code ... */
  LED1_Init(); /* initialize LED driver */
  /* ### PWM_LDD "PwmLdd1" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)PwmLdd1_Init(NULL);
  /* ### PWM "Inhr1" init code ... */
  /* ### LED "LED2" init code ... */
  LED2_Init(); /* initialize LED driver */
  /* ### BitIO_LDD "BitIoLdd4" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd4_Init(NULL);
  /* ### PWM_LDD "PwmLdd2" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)PwmLdd2_Init(NULL);
  /* ### PWM "Inhr2" init code ... */
  /* ### LED "LED3" init code ... */
  LED3_Init(); /* initialize LED driver */
  /* ### BitIO_LDD "BitIoLdd5" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd5_Init(NULL);
  /* ### LED "MF01" init code ... */
  MF01_Init(); /* initialize LED driver */
  /* ### BitIO_LDD "BitIoLdd6" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd6_Init(NULL);
  /* ### LED "MF02" init code ... */
  MF02_Init(); /* initialize LED driver */
  /* ### BitIO_LDD "BitIoLdd7" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd7_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd8" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd8_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd9" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd9_Init(NULL);
  /* ### BitIO_LDD "BitIoLdd10" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)BitIoLdd10_Init(NULL);
}
  /* Flash configuration field */
  __attribute__ ((section (".cfmconfig"))) const uint8_t _cfm[0x10] = {
   /* NV_BACKKEY3: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY2: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY1: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY0: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY7: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY6: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY5: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY4: KEY=0xFF */
    0xFFU,
   /* NV_FPROT3: PROT=0xFF */
    0xFFU,
   /* NV_FPROT2: PROT=0xFF */
    0xFFU,
   /* NV_FPROT1: PROT=0xFF */
    0xFFU,
   /* NV_FPROT0: PROT=0xFF */
    0xFFU,
   /* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=2 */
    0x7EU,
   /* NV_FOPT: ??=1,??=1,FAST_INIT=1,LPBOOT1=1,RESET_PIN_CFG=1,NMI_DIS=1,??=1,LPBOOT0=1 */
    0xFFU,
    0xFFU,
    0xFFU
  };

/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
