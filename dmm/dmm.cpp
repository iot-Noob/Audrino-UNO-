#include"Arduino.h"
#include "dmm.h"
#include <ShiftedLCD.h>
#include <SPI.h>
 LiquidCrystal lcd(10);
 
void dmm::begin() {
   pinMode(analogInput, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
 
 //analogReference(EXTERNAL);
}
void  dmm::voltage(int r,int c) {
    lcd.setCursor(r,c);

    value = analogRead(analogInput);
   vout = (value * vref) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   lcd.setCursor(4,1);
   lcd.print(vin);
   lcd.print("V");
   Serial.println(value); 
}
void  dmm::volt_devider(float r1,float r2) {
 R1=r1;
 R2=r2; 
}

dmm::dmm() {
  R1 = 30000.0;
  R2 = 7500.0;
  vref=5.0;
  analogInput=A0;
 
}

void dmm::voltage_range(float v) {
vref=v;  
}
float dmm::vinput() {
  return vin;
}

int dmm::sensor_pin(int pin) {
analogInput=pin;  
}
