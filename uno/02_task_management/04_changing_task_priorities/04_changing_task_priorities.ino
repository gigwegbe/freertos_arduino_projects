/*
Experimenting with task priorities. 
*/



#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

typedef int TaskProfiler;

//TaskProfiler RedLEDProfiler; 
//TaskProfiler YellowLEDProfiler;
//TaskProfiler BlueLEDProfiler;

TaskHandle_t red_Handle, yellow_Handle, blue_Handle; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(redLedControllerTask,"RED LED Task", 128, NULL, 1, &red_Handle); 
  xTaskCreate(blueLedControllerTask,"BLUE LED Task", 128, NULL, 1, &blue_Handle); 
  xTaskCreate(yellowLedControllerTask,"YELLOW LED Task", 128, NULL, 1, &yellow_Handle); 
}

void redLedControllerTask(void * pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1){
    digitalWrite(RED, digitalRead(RED)^1); 
    vTaskDelay(50);
  }
}


void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
    digitalWrite(BLUE, digitalRead(BLUE)^1);
    vTaskDelay(50);
  }
}


void yellowLedControllerTask(void * pvParameters)
{

  pinMode(YELLOW, OUTPUT);
  while(1){
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
 // Use the handle to raise the priority of the created task.
    vTaskPrioritySet(blue_Handle, 2);
    vTaskDelay(50);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
