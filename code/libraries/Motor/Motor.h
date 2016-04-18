/*
  Motor.h Library 
  Vicente Ortiz, David Martinez. December 10, 2013
*/

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"


class Motor
{ 
public:
	Motor(int left, int enable1, int enable2, int right);
	void turn(float timeTurn);
	void straight();
	void speedUp();
	void stop(double timeStop);
	
private:                                                             
	int _enable1;
	int _enable2;
	int _left;
	int _right;
};

#endif
