#include "Application.h"
#include "Ultrasonico.h"

void re();
void aceleracao();
void virar();
void mudaRota();
void endireitaVolante();

//static UART_Desc deviceData;
int passo = 0;
int angulo = 0;

void APP_Run(void) {
	//unsigned char cm[3];
	uint16_t c;
	//int i;
	
	//Init();
	//SendString((unsigned char*)"Hello World\r\n", &deviceData);
	
	//Inhr2_Enable();
	//Inhr1_Enable();
	
	//aceleracao();
	
	//for(;;) {
	//	c = sUltrasonico(); //Leitura do dado
		
		//Imprime Serial
	//	cm[0] = (char)((c / 100)+48);
	//	cm[1] = (char)(((c % 100)/10)+48);
	//	cm[2] = (char)((c % 10)+48);
		
	//	SendString((unsigned char*)"cm:", &deviceData);
	//	SendChar(cm[0], &deviceData);
	//	SendChar(cm[1], &deviceData);
	//	SendChar(cm[2], &deviceData);
	//	SendString((unsigned char*)"\r\n", &deviceData);

	//	WAIT1_Waitms(500);
		
		//re();
		if(c < 40 && c > 0 && c != 7){
		//	SendString((unsigned char*)"Mudar Rota\r\n", &deviceData);
	//		mudaRota();
		}
		
	//	WAIT1_Waitms(50);
//	}
}
void setPasso(int p1, int p2, int p3, int p4){
	P1_PutVal(p1);
	P2_PutVal(p2);
	P3_PutVal(p3);
	P4_PutVal(p4);
}

void passos(){
	
	switch(passo){
		case 1:
			setPasso(1,0,0,0);
		 	break;
		case 2:
			setPasso(0,1,0,0);
			break;
		case 3:
			setPasso(0,0,1,0);
			break;
		case 0:
			setPasso(0,0,0,1);
			break;
	}
}
void virar(int anguloDesejado){
	
	while(abs (anguloDesejado - angulo) > 1.5){
		if(anguloDesejado < angulo){
			passo++;
			if (passo == 4)
				passo = 0;
			angulo -= 1.5;
		}else{
			passo--;
			if(passo == -1)
				passo = 3;
			angulo += 1.5;
		}
		passos();
		WAIT1_Waitms(10);
	}
}
void endireitaVolante(){
	LEDpin4_PutVal(0); 
	LEDpin5_PutVal(0);
	//angulo = passo = 0;
}
void re(){
	(void)Inhr1_SetRatio8(0);
	(void)Inhr2_SetRatio8(100);
}
void aceleracao(){
	(void)Inhr2_SetRatio8(0);
	(void)Inhr1_SetRatio8(50);
}
void mudaRota(){
	(void)Inhr2_SetRatio8(0);
	(void)Inhr1_SetRatio8(0);
	WAIT1_Waitms(500);
	virar(20);
	re();
	WAIT1_Waitms(500);
	aceleracao();
	WAIT1_Waitms(40);
	endireitaVolante();
	virar(-20);
}
