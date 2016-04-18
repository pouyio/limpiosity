/*
  Ultrasounds.h Library created to control US sensors
  By Vicente Ortiz, David Martinez. December 10, 2013
*/

#ifndef Ultrasounds_h
#define Ultrasounds_h

#include "Arduino.h"

#define MIN_DISTANCE 15 //Minimal distance to be close enough
  
class Ultrasounds
{
public:
	Ultrasounds(int echoPin, int trigPin);
	float checkDistanceInCm();
	bool isNear();
	
private:
	int _echoPin;
	int _trigPin;
	float _pulseTime;
};

#endif
