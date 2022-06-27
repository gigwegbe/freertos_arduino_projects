#include <Seeed_Arduino_FreeRTOS.h>
// Sombe boards use SerialUSB, some use Serial
#define Terminal          SerialUSB

#define RED     2
#define YELLOW  3
#define BLUE    4


typedef int TaskProfiler; 
TaskProfiler RedLEDProfiler; 
TaskProfiler YellowLEDProfiler; 
TaskProfiler BlueLEDProfiler; 


void  setup(){
  Terminal.begin(115200); 
  xTaskCreate(redLedControllerTask, 
              "Red LED Task", 
              100,
              NULL, 
              1, 
              NULL
              );
  xTaskCreate(blueLedControllerTask, 
            "Blue LED Task", 
            100,
            NULL, 
            1, 
            NULL
            );
 xTaskCreate(yellowLedControllerTask, 
            "Yellow LED Task", 
            100,
            NULL, 
            1, 
            NULL
            );

// Start the RTOS, this function wiTerminal never return and wiTerminal schedule the tasks.
  vTaskStartScheduler();
  
  while(1){};
  
}

void  redLedControllerTask(void *pvParameters){
  pinMode(RED, OUTPUT); 
  while(1){
    Terminal.print("This is RED: ");  
    RedLEDProfiler++;
    Terminal.println(RedLEDProfiler);
    digitalWrite(RED, digitalRead(RED)^1);
    delay(300);  
  }
}


void  blueLedControllerTask(void *pvParameters){
  pinMode(BLUE, OUTPUT); 
  while(1){
    Terminal.print("This is BLUE: ");  
    BlueLEDProfiler++; 
    Terminal.println(BlueLEDProfiler);  
    digitalWrite(BLUE, digitalRead(BLUE)^1);
    delay(300);
  }
}


void  yellowLedControllerTask(void *pvParameters){
  pinMode(YELLOW, OUTPUT); 
  while(1){
    Terminal.print("This is YELLOW: "); 
    YellowLEDProfiler++; 
    Terminal.println(YellowLEDProfiler);
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
    delay(300);
  }
}


void loop(){
  
}
