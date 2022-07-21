
#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif


#define RED     25
#define YELLOW  32
#define BLUE    22

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  xTaskCreatePinnedToCore(redLedControllerTask,"RED LED Task", 2048, NULL, 1, NULL, ARDUINO_RUNNING_CORE); 
  xTaskCreatePinnedToCore(blueLedControllerTask,"BLUE LED Task", 2048, NULL, 1, NULL, ARDUINO_RUNNING_CORE); 
  xTaskCreatePinnedToCore(yellowLedControllerTask,"YELLOW LED Task", 2048, NULL, 1, NULL, ARDUINO_RUNNING_CORE); 
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
  }
}

void yellowLedControllerTask(void * pvParameters)
{
  pinMode(YELLOW, OUTPUT);
  while(1){
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
    vTaskDelay(300);
  }
}


void loop() {
  
}
