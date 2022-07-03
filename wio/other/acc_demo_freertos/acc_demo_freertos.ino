#include <Seeed_Arduino_FreeRTOS.h>
#include"LIS3DHTR.h"
LIS3DHTR<TwoWire> lis;
 
void setup() {
  Serial.begin(115200);
  lis.begin(Wire1);
 
  if (!lis) {
    Serial.println("ERROR");
    while(1);
  }
  lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ); //Data output rate
  lis.setFullScaleRange(LIS3DHTR_RANGE_2G); //Scale range set to 2g

  xTaskCreate(acceTask,"YELLOW LED Task", 128, NULL, 1, NULL); 

// Start the RTOS, this function wiTerminal never return and wiTerminal schedule the tasks.
  vTaskStartScheduler();

}


void acceTask(void * pvParameters)
{
  float x_values, y_values, z_values;
   
  while(1){
  x_values = lis.getAccelerationX();
  y_values = lis.getAccelerationY();
  z_values = lis.getAccelerationZ();
 
  Serial.print("X: "); Serial.print(x_values);
  Serial.print(" Y: "); Serial.print(y_values);
  Serial.print(" Z: "); Serial.print(z_values);
  Serial.println();
  delay(50);
   
  }
}
 
void loop() {
}
