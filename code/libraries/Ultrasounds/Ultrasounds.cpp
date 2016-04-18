/*
  Ultrasounds.cpp Library created to control US sensors
  By Vicente Ortiz, David Martinez. December 10, 2013
*/

#include "Arduino.h"
#include "Ultrasounds.h"


 Ultrasounds::Ultrasounds(int echoPin, int trigPin) : _echoPin(echoPin),
													  _trigPin(trigPin)
 {
 }

float Ultrasounds::checkDistanceInCm()
{
	digitalWrite(_trigPin, LOW);                  
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);                 
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);                  
	pulseTime = pulseIn(_echoPin, HIGH);
	return pulseTime / 58; //convert from inch (distance/29/2) to cm
}

bool Ultrasounds::isNear() //return TRUE if closer than MIN_DISTANCE
{
	digitalWrite(_trigPin, LOW);                  
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);                 
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);                  
	pulseTime = pulseIn(echoPin, HIGH);
	
	return (pulseTime / 58) <= MIN_DISTANCE ? true : false;
}
