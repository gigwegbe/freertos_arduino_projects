/*
Create 3 instance of the same task. 
All using different threads with one task function. 
*/

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

const uint16_t *redLed = (uint16_t *) RED;
const uint16_t *blueLed = (uint16_t *) BLUE; 
const uint16_t *yellowLed = (uint16_t *) YELLOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xTaskCreate(ledControllerTask,"RED LED Task", 2048, (void *)redLed, 1, NULL); 
  xTaskCreate(ledControllerTask,"BLUE LED Task", 2048, (void *)blueLed, 1, NULL); 
  xTaskCreate(ledControllerTask,"YELLOW LED Task", 2048, (void *)yellowLed, 1, NULL); 
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
