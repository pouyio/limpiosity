#include <LiquidCrystal.h>

#include <Motor.h>

Motor myMotor(4,5,6,7);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly: 
  //myMotor.turn(30,200,200);
  delay(1000);
  myMotor.straight(100,100);
  delay(1000);
  myMotor.turn(20,100,100);
}
