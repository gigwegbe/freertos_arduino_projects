/*
Create 3 instance of the same task. 
All using different threads with one task function. 
*/



#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

typedef int TaskProfiler;

TaskProfiler RedLEDProfiler; 
TaskProfiler YellowLEDProfiler;
TaskProfiler BlueLEDProfiler;

const uint16_t *redLed = (uint16_t *) RED;
const uint16_t *blueLed = (uint16_t *) BLUE; 
const uint16_t *yellowLed = (uint16_t *) YELLOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(ledControllerTask,"RED LED Task", 128, (void *)redLed, 1, NULL); 
  xTaskCreate(ledControllerTask,"BLUE LED Task", 128, (void *)blueLed, 1, NULL); 
  xTaskCreate(ledControllerTask,"YELLOW LED Task", 128, (void *)yellowLed, 1, NULL); 
}

void ledControllerTask(void * pvParameters)
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
  while(1){
    digitalWrite(pvParameters, digitalRead(pvParameters)^1); 
    vTaskDelay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
