#include"Arduino.h"
#include"battery.h"
#include "LiquidCrystal.h"
 const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
void  battery::begin(int br,int bc) {

   Serial.begin(9600);
  lcd.begin(16, 2);
  btr=br;
  btc=bc;
  bvcc=5.0;
 }
 battery::battery(int inp) {
  vin=inp;
 }

 void  battery::cal_voltage() {
sv=analogRead(vin);
voltage= (sv * bvcc) / 1024.0; 
 
 bp=(voltage/bvcc)*100;

Serial.println(voltage);
}
void battery::bat_stat(int bp) {
 
 lcd.createChar(0,batery[bp][0]);
lcd.createChar(1,batery[bp][1]); 
}
void battery::draw_battery(int r,int c) {
 
 lcd.setCursor(r,c); 
 lcd.write(byte(0));
  lcd.setCursor(r+1,c); 
 lcd.write(byte(1));
 

}

void  battery::charge() {

  btsmap=map(bp,100,0,10,0);
  
   bat_stat(btsmap); 
     lcd.setCursor(btr+2,btc); 
    lcd.print(bp);
   lcd.print("%");
 }

void battery::Main() {
   delay(800);
  draw_battery(btr,btc);
cal_voltage();  
charge();


}

void battery::batvolt(float v) {
  bvcc=v;
}
