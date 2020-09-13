/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * Speaker output from pin 13 to ground
*/ 


#include"pp.h"
#include <LiquidCrystal.h>
int h=0;
int m=0;
int s=13;
int sout=13; //speaker output
int on_led=8;
void beeps() {
tone(sout, 2600, 44);  
delay(90);
tone(sout, 2600, 44);  
delay(90);
tone(sout, 2600, 44); 
delay(2000);
tone(sout, 2600, 44);  
delay(90);
tone(sout, 2600, 44);  
delay(90);
tone(sout, 2600, 44);   
}
 void countdown(void) {

if(s==0) {
s=59;  
m-=1;
if(m==0&&h>0) {
m=59;
h-=1;  
}
}else {
s--;  
}
 } 



const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  speak(sout);
  pinMode(on_led,OUTPUT);


  lcd.begin(16, 2);
  Serial.begin(9600);

}
int flag=1;
void loop() {

 if(h==0&&m==0&&s==0) {
    lcd.clear();

  lcd.setCursor(70,1);
  lcd.print("BOOM!!");
    lcd.setCursor(0,1);
  lcd.print("Its A Prank!!");
 digitalWrite(on_led,HIGH);
ppt();
//beeps();
//delay(1000);

return 0;

}else {

  lcd.clear();
  lcd.setCursor(1, 0);
    lcd.print("  ");
  lcd.print(h);
  lcd.print("  : ");
  lcd.print(m);
  lcd.print("  : ");
  lcd.print(s);
 countdown();
 lcd.setCursor(1, 11);
    lcd.print("End of World");
    lcd.blink();
}  



delay(1000);
tone(sout, 1600, 90);

 
  }
