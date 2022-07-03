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

int yellowTaskPrio; 
int redTaskPrio;
int blueTaskPrio;

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
  redTaskPrio = uxTaskPriorityGet(red_Handle);
  Serial.print("RedTaskPriority: ");
  Serial.println(redTaskPrio);
  }
}


void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
  blueTaskPrio = uxTaskPriorityGet(blue_Handle);
  Serial.print("BlueTaskPriority: ");
  Serial.println(blueTaskPrio);
  }
}


void yellowLedControllerTask(void * pvParameters)
{

  pinMode(YELLOW, OUTPUT);
  while(1){
  YellowLEDProfiler++;
//  yellowTaskPrio = uxTaskPriorityGet(yellow_Handle);
  yellowTaskPrio = uxTaskPriorityGet(NULL); //Alternative 
  Serial.print("YellowTaskPriority: ");
  Serial.println(yellowTaskPrio);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
