#include <Ultrasounds.h>

Ultrasounds mySensor(52); //attached pin

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Distance to object in cm is:  ");
  Serial.print(mySensor.checkDistanceInCm());
  delay(500);  
}
