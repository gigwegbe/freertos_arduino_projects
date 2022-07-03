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

//const uint16_t *redLed = (uint16_t *) RED;
//const uint16_t *blueLed = (uint16_t *) BLUE; 
//const uint16_t *yellowLed = (uint16_t *) YELLOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(redLedControllerTask,"RED LED Task", 128, NULL, 1, NULL); 
  xTaskCreate(blueLedControllerTask,"BLUE LED Task", 128, NULL, 1, NULL); 
  xTaskCreate(yellowLedControllerTask,"YELLOW LED Task", 128, NULL, 3, NULL); 
}

void redLedControllerTask(void * pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1){
    digitalWrite(RED, digitalRead(RED)^1); 
  }
}


void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
    digitalWrite(BLUE, digitalRead(BLUE)^1); 
  }
}


void yellowLedControllerTask(void * pvParameters)
{

  pinMode(YELLOW, OUTPUT);
  while(1){
    digitalWrite(YELLOW, digitalRead(YELLOW)^1); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
