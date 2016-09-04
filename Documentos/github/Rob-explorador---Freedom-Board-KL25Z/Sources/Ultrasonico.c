/*
 * Ultrasonico.c
 *
 *  Created on: Jul 16, 2013
 *      Author: LARM
 */
#include "Application.h"

static US_DeviceType usDevice;  //Ultrasonico 
static US_DeviceType usDevice2;  //Ultrasonico2 

void inicioUltrasonico(void)
{
	usDevice.state = ECHO_IDLE;
	usDevice.capture = 0;
	usDevice.trigDevice = TRIG_Init(NULL);
	usDevice.echoDevice = TU1_Init(&usDevice);
}
void inicioUltrasonico2(void)
{
	usDevice2.state = ECHO_IDLE;
	usDevice2.capture = 0;
	usDevice2.trigDevice = TRIG2_Init(NULL);
	usDevice2.echoDevice = TU1_Init(&usDevice2);
}

/* Retorna o tempo*/
uint16_t tUltrasonico(void){
	uint16_t us;
	
	usDevice.echoDevice = TU1_Init(&usDevice);
	
	/*Manda pulso 10us na TRIG*/
	TRIG_SetVal(usDevice.trigDevice);
	WAIT1_Waitus(10);
	usDevice.state = ECHO_TRIGGERED;
	TRIG_ClrVal(usDevice.trigDevice);
	while(usDevice.state != ECHO_FINISHED){
		if(usDevice.state == ECHO_OVERFLOW){
			mString("0");
			usDevice.state = ECHO_IDLE;
			return 0; /*ERRO*/
		}
	}
	us = (usDevice.capture*1000UL)/(TU1_CNT_INP_FREQ_U_0/1000);
	return us;
}

uint16_t tUltrasonico2(void){
	uint16_t us;
	
	usDevice2.echoDevice = TU1_Init(&usDevice2);
	
	/*Manda pulso 10us na TRIG*/
	TRIG2_SetVal(usDevice2.trigDevice);
	WAIT1_Waitus(10);
	usDevice2.state = ECHO_TRIGGERED;
	TRIG2_ClrVal(usDevice2.trigDevice);
	while(usDevice2.state != ECHO_FINISHED){
		if(usDevice2.state == ECHO_OVERFLOW){
			mString("2");
			usDevice2.state = ECHO_IDLE;
			return 0; /*ERRO*/
		}
	}
	us = (usDevice2.capture*1000UL)/(TU1_CNT_INP_FREQ_U_0/1000);
	return us;
}

void US_EventEchoCapture(LDD_TUserData *UserDataPtr) {
  US_DeviceType *ptr = (US_DeviceType*)UserDataPtr;

  if (ptr->state==ECHO_TRIGGERED) { /* 1st edge, this is the raising edge, start measurement */
    TU1_ResetCounter(ptr->echoDevice);
    ptr->state = ECHO_MEASURE;
  } else if (ptr->state==ECHO_MEASURE) { /* 2nd edge, this is the falling edge: use measurement */
    (void)TU1_GetCaptureValue(ptr->echoDevice, 0, &ptr->capture);
    ptr->state = ECHO_FINISHED;
  }
}

void US_EventEchoOverflow(LDD_TUserData *UserDataPtr) {
  US_DeviceType *ptr = (US_DeviceType*)UserDataPtr;
  
  ptr->state = ECHO_OVERFLOW;
}

static uint16_t calcAirspeed_dms(uint8_t temperatureCelsius) {
  /* Return the airspeed depending on the temperature, in deci-meter per second */
  unsigned int airspeed; /* decimeters per second */

  airspeed = 3313 + (6 * temperatureCelsius); /* dry air, 0% humidity, see http://en.wikipedia.org/wiki/Speed_of_sound */
  airspeed -= (airspeed/100)*15; /* factor in ~15% for a relative humidity of ~40% */ 
  return airspeed;
}

uint16_t US_usToCentimeters(uint16_t microseconds, uint8_t temperatureCelsius) {
  return (microseconds*100UL)/calcAirspeed_dms(temperatureCelsius)/2; /* 2 because because of two way */
}
uint16_t sUltrasonico(void){
	uint16_t us, cm;
	uint8_t buf[8];
	
	
	us = tUltrasonico();
	UTIL1_Num16uToStrFormatted(buf, sizeof(buf), us, ' ', 5);
	cm = US_usToCentimeters(us, 22);
	UTIL1_Num16uToStrFormatted(buf, sizeof(buf), cm, ' ', 5);
	TU1_Deinit(&usDevice);
	
	return cm;
}
uint16_t sUltrasonico2(void){
	uint16_t us, cm;
	uint8_t buf[8];
	
	
	us = tUltrasonico2();
	UTIL1_Num16uToStrFormatted(buf, sizeof(buf), us, ' ', 5);
	cm = US_usToCentimeters(us, 22);
	UTIL1_Num16uToStrFormatted(buf, sizeof(buf), cm, ' ', 5);
	TU1_Deinit(&usDevice2);

	return cm;
}
