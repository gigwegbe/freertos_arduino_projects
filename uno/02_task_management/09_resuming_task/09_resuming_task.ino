#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8


TaskHandle_t red_Handle, yellow_Handle, blue_Handle; 
uint32_t suspend_monitor; 
uint32_t resume_monitor; 
bool _suspended = false; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreate(redLedControllerTask,"RED LED Task", 100, NULL, 1, &red_Handle); 
  xTaskCreate(blueLedControllerTask,"BLUE LED Task", 100, NULL, 1, &blue_Handle); 
  xTaskCreate(yellowLedControllerTask,"YELLOW LED Task", 100, NULL, 1, &yellow_Handle); 
}

void redLedControllerTask(void * pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1){
  digitalWrite(RED, digitalRead(RED)^1); 
  vTaskDelay(300);
  }
}


void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
  suspend_monitor++; 
  digitalWrite(BLUE, digitalRead(BLUE)^1);
  vTaskDelay(300);

  if(_suspended){
    resume_monitor++; 
    if(resume_monitor >= 4){
      vTaskResume(yellow_Handle);
      resume_monitor = 0; 
      _suspended = false; 
    }
  }
  
  }
}


void yellowLedControllerTask(void * pvParameters)
{

  pinMode(YELLOW, OUTPUT);
  while(1){
  digitalWrite(YELLOW, digitalRead(YELLOW)^1);
  if (suspend_monitor>=10)
    {
      _suspended = true; 
      suspend_monitor = 0; 
      vTaskSuspend(NULL);  
    }
    
  }
   vTaskDelay(300);
}

void loop() {
  // put your main code here, to run repeatedly:

}
