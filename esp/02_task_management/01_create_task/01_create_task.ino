
#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif


#define RED     25
#define YELLOW  32
#define BLUE    22


typedef int TaskProfiler;

TaskProfiler RedLEDProfiler; 
TaskProfiler YellowLEDProfiler;
TaskProfiler BlueLEDProfiler;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreatePinnedToCore(redLedControllerTask,"RED LED Task", 2048, NULL, 1, NULL, ARDUINO_RUNNING_CORE); 
  xTaskCreatePinnedToCore(blueLedControllerTask,"BLUE LED Task", 2048, NULL, 1, NULL, ARDUINO_RUNNING_CORE); 
  xTaskCreatePinnedToCore(yellowLedControllerTask,"YELLOW LED Task", 2048, NULL, 1, NULL, ARDUINO_RUNNING_CORE); 
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
