#include <VirtualWire.h>

#define pintrans 3
#define pinbutton1 2
#define pinbutton2 4
#define right 5
#define left 6
#define front 7
#define back 8

int count=1;

void setup(){

  Serial.begin(9600);
  vw_set_tx_pin(pintrans);
  pinMode(pinbutton1,INPUT_PULLUP);
  pinMode(pinbutton2,INPUT_PULLUP);
  pinMode(right,INPUT_PULLUP);
  pinMode(left,INPUT_PULLUP);
  pinMode(front,INPUT_PULLUP);
  pinMode(back,INPUT_PULLUP);
  vw_setup(2000);

}

void loop(){

  unsigned char packet[1];

  if((digitalRead(pinbutton1)==0)){
    packet[0]='A';
    vw_send((uint8_t*)packet,1);
    vw_wait_tx();
    Serial.print("off");
    Serial.println(packet[0]);
    //delay(1000);
  }
  else if((digitalRead(pinbutton2)==0)){
    packet[0]='E';
    vw_send((uint8_t*)packet,1);
    vw_wait_tx();
    Serial.print("on");
    Serial.println(packet[0]);
    //delay(1000);
  }
  else if((digitalRead(pinbutton2)==1)&&(digitalRead(pinbutton1==1))){
    Serial.println("mid");
    while(digitalRead(right)==0){
      packet[0]='R';
      vw_send((uint8_t*)packet,1);
      vw_wait_tx();
      Serial.print("right");
      Serial.println(packet[0]);
    }
    while(digitalRead(left)==0){
      packet[0]='L';
      vw_send((uint8_t*)packet,1);
      vw_wait_tx();
      Serial.print("left");
      Serial.println(packet[0]);
    }
    while(digitalRead(front)==0){
      packet[0]='F';
      vw_send((uint8_t*)packet,1);
      vw_wait_tx();
      Serial.print("forward");
      Serial.println(packet[0]);
    }
    while(digitalRead(back)==0){
      packet[0]='P';
      vw_send((uint8_t*)packet,1);
      vw_wait_tx();
      Serial.print("buzz");
      Serial.println(packet[0]);
    }

    delay(300);
    packet[0]='B';
    vw_send((uint8_t*)packet,1);
    vw_wait_tx();
    Serial.print("back");
    Serial.println(packet[0]);

  }



}
