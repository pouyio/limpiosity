/*
 Piezo.h Library
 by David Martinez. 27 Nov 2013
*/

#ifndef Piezo_h
#define Piezo_h

#include "Arduino.h"

class Piezo
{
public:
	Piezo(int ledPin1, int ledPin2, int ledPin3, int ledPin4, int piezoPin);	
	void start();
	void bip();

private:
	void beep(int frequency, long time);
	
private:
	int _ledPin1;
	int _ledPin2;
	int _ledPin3;
	int _ledPin4;
	int _piezoPin;	
};

#endif
