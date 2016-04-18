#include <Ultrasounds.h>

Ultrasounds mySensor(52);

void setup() {
  Serial.begin(9600);
}

void loop() { 
  if(mySensor.isNear()){
    Serial.println("You are about to crash!");
  }else println("You can continue");
  delay(500);
}
