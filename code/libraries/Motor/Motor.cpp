/*
  Motor.h Library
  Vicente Ortiz, David Martinez. December 10, 2013
*/

#include "Arduino.h"
#include "Motor.h"


Motor::Motor(int left, int enable1, int enable2, int right) : _enable1(enable1),
															  _enable2(enable2),
															  _left(left), 
															  _right(right){
	
	pinMode(_enable1, OUTPUT);
	pinMode(_enable2, OUTPUT);
	pinMode(_left, OUTPUT);
	pinMode(_right, OUTPUT);
}

void Motor::stop(double timeStop){
	//LOW == clockwise, HIGH = anticlockwise
	digitalWrite(_left, LOW);
	digitalWrite(_right, LOW);
	analogWrite(_enable1, 0);
	analogWrite(_enable2, 0);
	delay(timeStop * 1000);
}

void Motor::straight(){
	//LOW == clockwise, HIGH = anticlockwise
	digitalWrite(_left, LOW);
	digitalWrite(_right, LOW);
	analogWrite(_enable1, 100);
	analogWrite(_enable2, 100);
}

void Motor::speedUp(){
	digitalWrite(_left, LOW);
	digitalWrite(_right, LOW);
	analogWrite(_enable1, 100);
	analogWrite(_enable2, 100);
}

void Motor::turn(float timeTurn){
	if(timeTurn < 0){
		digitalWrite(_left, LOW);
		digitalWrite(_right, HIGH);
		analogWrite(_enable1, 70);
		analogWrite(_enable2, 70);
		delay(timeTurn * -1000);
	} else {
		digitalWrite(_left, HIGH);
		digitalWrite(_right, LOW);
		analogWrite(_enable1, 70);
		analogWrite(_enable2, 70);
		delay(timeTurn * 1000);
	}
}
