/*
Experimenting with task priorities. 
*/



#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

typedef int TaskProfiler;

TaskProfiler RedLEDProfiler; 
TaskProfiler YellowLEDProfiler;
TaskProfiler BlueLEDProfiler;

TaskHandle_t red_Handle, yellow_Handle, blue_Handle; 
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
  RedLEDProfiler++; 
  Serial.print("RedTask Time: ");
  Serial.println(RedLEDProfiler);
   delay(300);
  }
}


void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
  BlueLEDProfiler++;
  Serial.print("BlueTask Time: ");
  Serial.println(BlueLEDProfiler);
  vTaskPrioritySet(NULL, 3);
  delay(300);
  }
}


void yellowLedControllerTask(void * pvParameters)
{

  pinMode(YELLOW, OUTPUT);
  while(1){
  YellowLEDProfiler++;
 // Use the handle to raise the priority of the created task. 
  Serial.print("YellowTask Time: ");
  Serial.println(YellowLEDProfiler);
  vTaskPrioritySet(NULL, 3);
  delay(300);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
