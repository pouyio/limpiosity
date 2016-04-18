/*
 Piezo.cpp Library 
 https://gist.github.com/1804108
 by David Martinez. 27 Nov 2013
*/
#include "Piezo.h"
#include "Arduino.h"

#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

Piezo::Piezo(int ledPin1, int ledPin2, int ledPin3, int ledPin4, int piezoPin) : 
	_ledPin1(ledPin1),
    _ledPin2(ledPin2),
    _ledPin3(ledPin3),
    _ledPin4(ledPin4),
	_piezoPin(piezoPin)
{
	pinMode(_ledPin1,OUTPUT);
    pinMode(_ledPin2,OUTPUT);
    pinMode(_ledPin3,OUTPUT);
    pinMode(_ledPin4,OUTPUT);
	pinMode(_piezoPin,OUTPUT);
}

void Piezo::beep (int frequency, long time)
{
    //Use the LEDS to visualize the played notes
    digitalWrite(_ledPin1, HIGH);
    digitalWrite(_ledPin2, HIGH);
    digitalWrite(_ledPin3, HIGH);
    digitalWrite(_ledPin4, HIGH);
        
    long delayAmount = (long)(1000000 / frequency);
    long loopTime = (long)((time * 1000) / (delayAmount * 2));
    for (int x = 0; x < loopTime; ++x)     
    {     
        digitalWrite(_piezoPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(_piezoPin,LOW);
        delayMicroseconds(delayAmount);
    }
   
    digitalWrite(_ledPin1, LOW);
    digitalWrite(_ledPin2, LOW);
    digitalWrite(_ledPin3, LOW);
    digitalWrite(_ledPin4, LOW);       
    delay(20); //delay to separate notes
}

void Piezo::bip()
{
    beep(eH, 10);
}

void Piezo::start()
{   
    //500 ms for a quart note
    beep(a, 400);
    beep(a, 400);
    beep(a, 400);
    beep(f, 250);
    beep(cH, 100);

    beep(a, 400);
    beep(f, 250);
    beep(cH, 100);
    beep(a, 900);

    beep(eH, 400);
    beep(eH, 400);
    beep(eH, 400);
    beep(fH, 250);
    beep(cH, 100);

    beep(gS, 400);
    beep(f, 250);
    beep(cH, 100);
    beep(a, 900);
}

