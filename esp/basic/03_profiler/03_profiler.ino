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
  xTaskCreate(redLedControllerTask,"RED LED Task", 2048, NULL, 1, NULL); 
  xTaskCreate(blueLedControllerTask,"BLUE LED Task", 2048, NULL, 1, NULL); 
  xTaskCreate(yellowLedControllerTask,"YELLOW LED Task", 2048, NULL, 1, NULL); 
  
  
}

void redLedControllerTask(void * pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1){
    RedLEDProfiler++;
    Serial.print("RedLEDProfiler: ");
    Serial.println(RedLEDProfiler);
    digitalWrite(RED, digitalRead(RED)^1);
    delay(300);
  }
}

void blueLedControllerTask(void * pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1){
    YellowLEDProfiler++;
    Serial.print("YellowLEDProfiler: ");
    Serial.println(YellowLEDProfiler);
    digitalWrite(BLUE, digitalRead(BLUE)^1);
    delay(300);
  }
}


void yellowLedControllerTask(void * pvParameters)
{
  pinMode(YELLOW, OUTPUT);
  while(1){
    BlueLEDProfiler++; 
    Serial.print("BlueLEDProfiler: ");
    Serial.println(BlueLEDProfiler);
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
    delay(300);
  }
}


void loop() {
}
