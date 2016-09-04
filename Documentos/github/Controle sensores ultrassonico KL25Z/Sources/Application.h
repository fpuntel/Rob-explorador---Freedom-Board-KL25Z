/*
 * Application.h
 *
 *  Created on: Jul 11, 2013
 *      Author: PikaFumo
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "PE_Types.h"
#include "PE_LDD.h"
#include "RxBuf.h"
#include "AS1.h"
#include "UTIL1.h"
#include "TU1.h"
#include "TRIG.h"

typedef struct {
  LDD_TDeviceData *handle; /* LDD device handle */
  volatile uint8_t isSent; /* this will be set to 1 once the block has been sent */
  uint8_t rxChar; /* single character buffer for receiving chars */
  uint8_t (*rxPutFct)(uint8_t); /* callback to put received character into buffer */
} UART_Desc;
 
//ULTRASONICO
typedef enum {
  ECHO_IDLE, /* device not used */
  ECHO_TRIGGERED, /* started trigger pulse */
  ECHO_MEASURE, /* measuring echo pulse */
  ECHO_OVERFLOW, /* measurement too too long */
  ECHO_FINISHED /* measurement finished */
} US_EchoState;

typedef struct { 
  LDD_TDeviceData *trigDevice; /* device handle for the Trigger pin */
  LDD_TDeviceData *echoDevice; /* input capture device handle (echo pin) */
  volatile US_EchoState state; /* state */
  TU1_TValueType capture; /* input capture value */
} US_DeviceType;



void APP_Run(void);
void US_EventEchoOverflow(LDD_TUserData *UserDataPtr);
void US_EventEchoCapture(LDD_TUserData *UserDataPtr);

#endif /* APPLICATION_H_ */
