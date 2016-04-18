#include <LiquidCrystal.h>
#include <Piezo.h>
#include <Ultrasounds.h>
#include <Motor.h>
#include <VirtualWire.h>

#define RECIEVEPIN 45
#define LEDPIN 8

bool firstStart = false;
bool stopFlag = true;

uint8_t buf[1];

Motor motor(4,5,6,7);
Piezo piezo(51,49,9,8,10);

Ultrasounds leftUltrasound(40,42);
Ultrasounds centerUltrasound(44,46);
Ultrasounds rightUltrasound(48,50);

LiquidCrystal lcd(12,11,22,24,26,28,30,32,34,36);


void setup() {
  Serial.begin(9600);
  lcd.begin(20,4);

  //reception
  vw_set_rx_pin(RECIEVEPIN);
  vw_setup(2000);
  vw_rx_start();

  //Led Pins
  pinMode(2,INPUT);
  pinMode(51,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);

  //Interruption pin
  attachInterrupt(0,LDRUP,CHANGE);
}

void loop(){
  
  //Check the three modes Automatic(E), OFF(A), or remote control(R,L,F,P,B)
  switch(recibobyte()){
  case'E':
    //Detect the first entry in the case
    if(!firstStart){
      blink();
      vw_rx_stop();//Stop the transmission with rx.
      piezo.start();//Start the melody with the piezo
      vw_rx_start();
      firstStart = true;
      stopFlag = false;   
    }

    int obstacle = dataToBits(rightUltrasound.isNear(), leftUltrasound.isNear(), 
							  centerUltrasound.isNear());
    motorMovement(obstacle);
    break;
    
  case 'A':
    if(!stopFlag){
      motor.stop(0.5);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Wait...");
      stopFlag = 1;
      firstStart = 0;
    }
    break;
  case'R': 
    Serial.println("Right");
    motor.turn(-0.1);
    motor.stop(0.0);
    break;
  case'L': 
    Serial.println("Left");
    motor.turn(0.1);
    motor.stop(0.0);
    break;
  case'F': 
    Serial.println("Foward");
    motor.straight();
    break;
  case'P': 
    piezo.bip();
    break;
  case'B': 
    Serial.println("Sigo recto");
    motor.stop(0.1);
    break;
      
  }
}

//LDR Interruption
void LDRUP(){

  if(!digitalRead(2)){
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(49, LOW);
     digitalWrite(51, LOW);
  }

  if(digitalRead(2)){
     digitalWrite(8, HIGH);
     digitalWrite(9, HIGH);
     digitalWrite(49, HIGH);
     digitalWrite(51, HIGH);
  }
}

void blink(void){

  digitalWrite(LEDPIN, HIGH);
  delay(500);
  digitalWrite(LEDPIN, LOW);
  delay(500);
}

char recibobyte(void){

  uint8_t buflen = 1; //Lenght in bytes

  if(vw_get_message(buf,&buflen)){
     Serial.println("Recibido:");
     Serial.println(buf[0]);
     lcd.setCursor(0, 0);
     lcd.print("Recibido:");
  }
  return buf[0];
}

int dataToBits(bool flagRight, bool flagLeft, bool flagCenter){
	//Ponderation to each flag in a 3 bits number
	return flagRight * 4 + flagLeft * 2 + flagCenter * 1; 
}

void motorMovement(int obstacle){

  switch(obstacle){
  case 0:
    Serial.println("Straight On");
    motor.straight();
    break;

  case 1:
    Serial.println("Front Obstacle");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Front Obstacle");
    motor.turn(2.5);
    motor.stop(0.5);
    break;

  case 2:
    Serial.println("Left Obstacle");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Left Obstacle");
    motor.turn(-1);
    motor.stop(0.5);
    break;

  case 3:
    Serial.println("Left and Center Obstacle");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Left and Center Obstacle");
    motor.turn(-1);
    motor.stop(0.5);
    break;

  case 4:
    Serial.println("Right Obstacle");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Right Obstacle");
    motor.turn(1);
    motor.stop(0.5);
    break;

  case 5:
    Serial.println("Right and Center Obstacle");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Right and Center Obstacle");
    motor.turn(1);
    motor.stop(0.5);
    break;  

  case 6:
    Serial.println("Right and Left Obstacle");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Right and Left Obstacle");
    motor.turn(-2.5);
    motor.stop(0.5);
    break;

  case 7:
    Serial.println("Obstacle everywhere");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Obstacle everywhere o.O");
    motor.turn(2.5);
    motor.stop(0.5);
    break;
  }
}
