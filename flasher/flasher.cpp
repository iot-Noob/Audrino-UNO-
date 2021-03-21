#include "Arduino.h"
#include "flasher.h"
flasher::flasher (int led1,int led2, int led3)  {
 d1=led1;
 d2=led2;
 d3=led3; 
}
 
void flasher::PinSetup() {
 pinMode(d1,OUTPUT); 
  pinMode(d2,OUTPUT); 
   pinMode(d3,OUTPUT); 
}

void flasher::Sequance1() {
digitalWrite(d1,HIGH);  
delay(1000);
digitalWrite(d1,LOW);  
delay(1000);
digitalWrite(d2,HIGH);  
delay(1000);
digitalWrite(d2,LOW);  
delay(1000);
digitalWrite(d3,HIGH);  
delay(1000);
digitalWrite(d3,LOW);  
delay(1000);
}
 
