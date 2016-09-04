#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Application.h"
#include "Ultrasonico.h"

void formataDado(uint16_t c);
static UART_Desc deviceData;

//Váriavel GLOBAL
uint16_t c;
uint16_t c1;

int passo;

//Semáforo
LWSEM_STRUCT sValor;
LWSEM_STRUCT sValorMotor;

//SPI
char dado = 0;
LDD_TUserData *UserDataPtr;
LDD_TData *BufferPtr = 0;

void formataDado(uint16_t c){
	unsigned char cm[3];
	
	cm[0] = (char)((c / 100)+48);
	cm[1] = (char)(((c % 100)/10)+48);
	cm[2] = (char)((c % 10)+48);
	
	SendString((unsigned char*)"cm:", &deviceData);
	SendChar(cm[0], &deviceData);
	SendChar(cm[1], &deviceData);
	SendChar(cm[2], &deviceData);
	SendString((unsigned char*)"\r\n", &deviceData);
}
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
void mString(const unsigned char *str){
	SendString((unsigned char*)str, &deviceData);
}
static void Init(void) {
	//Criar semáforo
	_lwsem_create(&sValor, 1);	  
	_lwsem_create(&sValorMotor, 1);	 
	
  // Inicializa campos da Struct 
  deviceData.handle = AS1_Init(&deviceData);
  deviceData.isSent = FALSE;
  deviceData.rxChar = '\0';
  deviceData.rxPutFct = RxBuf_Put;
  // Configurando RX para receber o buufer
  RxBuf_Init(); //Inicializa o Buiffer
  // Configura ReceiveBlock () com um único buffer byte. 
  while(AS1_ReceiveBlock(deviceData.handle, (LDD_TData *)&deviceData.rxChar, sizeof(deviceData.rxChar))!=ERR_OK) {} //Inicia para receber os dados

  //Ultrasonico
  inicioUltrasonico(); 
  inicioUltrasonico2(); 
}

//Sensor
void Task1_task(uint32_t task_init_data)
{
	UserDataPtr = SS1_Init(NULL);
	Init();	
  while(1) {
	  SendString((unsigned char*)"Tarefa SENSOR\r\n", &deviceData);
	 // WAIT1_Waitms(1000);
	  
	  
	  //SPI
	  _lwsem_wait(&sValor);
	  SS1_ReceiveBlock(UserDataPtr,(LDD_TData *) &dado, sizeof(BufferPtr));
	  SendChar(dado, &deviceData);
	  _lwsem_post(&sValorMotor);
	  WAIT1_Waitms(100);
	  	  
	    //Ultrasom
	   _lwsem_wait(&sValor);
	  
	  inicioUltrasonico();
	  c = sUltrasonico();
	  SendString((unsigned char*)"\nSensor 1 ", &deviceData);
	  formataDado(c);

	  
	  _lwsem_post(&sValorMotor);
	  WAIT1_Waitms(200);
  }
}

//Motores
void Task2_task(uint32_t task_init_data)
{
	//Init();	
  while(1) {
	  SendString((unsigned char*)"Tarefa MOTOR\r\n", &deviceData);
	  _lwsem_wait(&sValorMotor);
	
	  //SPI
	  if(dado != 0){
		  SendChar(dado, &deviceData);
		  virar((int)dado);
	  }
	 
	  //Ultrasom
	  if(c < 40 && c > 0 && c != 6){
		  SendString((unsigned char*)"Tarefa MOTOR - MUDAR ROTA\r\n", &deviceData);
		  mudaRota();
	  }
	  
	  _lwsem_post(&sValor);
	  WAIT1_Waitms(200);
  }
}




