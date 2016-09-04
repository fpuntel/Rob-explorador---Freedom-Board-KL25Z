#include "Application.h"
#include "Ultrasonico.h"

void re();
void aceleracao();
void virarDireita();
void virarEsquerda();
void mudaRota();
void endireitaVolante();

static UART_Desc deviceData;

static void SendChar(unsigned char ch, UART_Desc *desc) {
  desc->isSent = FALSE;  /* this will be set to 1 once the block has been sent */
  while(AS1_SendBlock(desc->handle, (LDD_TData*)&ch, 1)!=ERR_OK) {} /* Send char */
  while(!desc->isSent) {} /* wait until we get the green flag from the TX interrupt */
}
 
static void SendString(const unsigned char *str,  UART_Desc *desc) {
  while(*str!='\0') {
    SendChar(*str++, desc);
  }
}
 
static void Init(void) {
  /* initialize struct fields */
  deviceData.handle = AS1_Init(&deviceData);
  deviceData.isSent = FALSE;
  deviceData.rxChar = '\0';
  deviceData.rxPutFct = RxBuf_Put;
  /* set up to receive RX into input buffer */
  RxBuf_Init(); /* initialize RX buffer */
  /* Set up ReceiveBlock() with a single byte buffer. We will be called in OnBlockReceived() event. */
  while(AS1_ReceiveBlock(deviceData.handle, (LDD_TData *)&deviceData.rxChar, sizeof(deviceData.rxChar))!=ERR_OK) {} /* initial kick off for receiving data */

  //Ultrasonico
  inicioUltrasonico(); 
}


void APP_Run(void) {
	unsigned char cm[3];
	uint16_t c;
	//int i;
	
	Init();
	SendString((unsigned char*)"Hello World\r\n", &deviceData);
	
	Inhr2_Enable();
	Inhr1_Enable();
	
	aceleracao();
	
	for(;;) {
		c = sUltrasonico(); //Leitura do dado
		
		//Imprime Serial
		cm[0] = (char)((c / 100)+48);
		cm[1] = (char)(((c % 100)/10)+48);
		cm[2] = (char)((c % 10)+48);
		
		SendString((unsigned char*)"cm:", &deviceData);
		SendChar(cm[0], &deviceData);
		SendChar(cm[1], &deviceData);
		SendChar(cm[2], &deviceData);
		SendString((unsigned char*)"\r\n", &deviceData);

		WAIT1_Waitms(500);
		
		//re();
		if(c < 10 && c > 0 && c != 6){
			SendString((unsigned char*)"Mudar Rota\r\n", &deviceData);
			mudaRota();
		}
		
		WAIT1_Waitms(500);
	}
}

void virarDireita(){
	LEDpin4_PutVal(0); //Motor frente 
	LEDpin5_PutVal(1); //Motor frente
}
void virarEsquerda(){
	LEDpin4_PutVal(1); //Motor frente 
	LEDpin5_PutVal(0); //Motor frente
}
void endireitaVolante(){
	LEDpin4_PutVal(0); 
	LEDpin5_PutVal(0);
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
	virarDireita();
	re();
	WAIT1_Waitms(800);
	aceleracao();
	virarEsquerda();
	WAIT1_Waitms(40);
	endireitaVolante();
}
