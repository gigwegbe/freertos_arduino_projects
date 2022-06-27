#include <Seeed_Arduino_FreeRTOS.h>

#define RED     2
#define YELLOW  3
#define BLUE    4

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);


  xTaskCreate(redLedControllerTask,"RED LED Task", 128, NULL, 1, NULL); 
  xTaskCreate(blueLedControllerTask,"BLUE LED Task", 128, NULL, 1, NULL); 
  xTaskCreate(yellowLedControllerTask,"YELLOW LED Task", 128, NULL, 1, NULL); 

// Start the RTOS, this function wiTerminal never return and wiTerminal schedule the tasks.
  vTaskStartScheduler();

  while(1){};

  
}

void redLedControllerTask(void * pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1){
    digitalWrite(RED, digitalRead(RED)^1);
    delay(300);
  }
}

void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
    digitalWrite(BLUE, digitalRead(BLUE)^1);
    delay(300);
  }
}


void yellowLedControllerTask(void * pvParameters)
{
  pinMode(YELLOW, OUTPUT);
  while(1){
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
    delay(300);
  }
}


void loop() {
  
}
