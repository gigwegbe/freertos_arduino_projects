#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8


TaskHandle_t red_Handle, yellow_Handle, blue_Handle; 
uint32_t suspend_monitor; 

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
  digitalWrite(BLUE, digitalRead(BLUE)^1);
  vTaskDelay(300);
  suspend_monitor++; 
  }
}


void yellowLedControllerTask(void * pvParameters)
{

  pinMode(YELLOW, OUTPUT);
  while(1){
  digitalWrite(YELLOW, digitalRead(YELLOW)^1);
  if (suspend_monitor>=10)
    {
      vTaskSuspend(blue_Handle);  
    }
    
  }
   vTaskDelay(300);
}

void loop() {
  // put your main code here, to run repeatedly:

}
