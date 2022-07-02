
#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

typedef int TaskProfiler;

TaskProfiler RedLEDProfiler; 
TaskProfiler YellowLEDProfiler;
TaskProfiler BlueLEDProfiler;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(redLedControllerTask,"RED LED Task", 128, NULL, 1, NULL); 
  xTaskCreate(blueLedControllerTask,"BLUE LED Task", 128, NULL, 1, NULL); 
  xTaskCreate(yellowLedControllerTask,"YELLOW LED Task", 128, NULL, 1, NULL); 
  

}

void redLedControllerTask(void * pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1){
    Serial.println("This is Red");
    vTaskDelay(100);
  }
}

void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
    Serial.println("This is Yellow");
    vTaskDelay(100);
  }
}


void yellowLedControllerTask(void * pvParameters)
{
  pinMode(YELLOW, OUTPUT);
  while(1){
    Serial.println("This is Blue");
    vTaskDelay(100);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
