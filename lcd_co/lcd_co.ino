/*


  The circuit:
 * LCD RS pin to digital pin 6
 * LCD Enable pin to digital pin 7
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
 * pin 8 for class shift button

*/


#include <LiquidCrystal.h>

class  liquid_crystal {
private:
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  

protected:
String Name;
public:  


void gdata(String a) {
 Name=a;
}
void show() {
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
  lcd.begin(16, 2);  
lcd.setCursor(0,0);  
lcd.print(Name);
}

};

class main:public liquid_crystal {
protected:
int button=8;
int btflag=0;
public:
liquid_crystal lc[5];
main() {
  pinMode(button,INPUT);
lc[0].gdata("Talha");  
lc[1].gdata("Sherry");
lc[2].gdata("Fasih");
lc[3].gdata("Hammad");
lc[4].gdata("Umair");        
}
void pb() {
  delay(66);
if(digitalRead(button)==HIGH) {
if(btflag==0) {
btflag=1;      
}else if(btflag==1) {
btflag=2;      
}else if(btflag==2) {
btflag=3;      
}else if(btflag==3) {
btflag=4;      
}else if(btflag==4) {
btflag=5;      
}else {
  btflag=0;
}

}
}

void ms() {
if(digitalRead(button)==HIGH) {
   pb(); 
  
}else {
   lc[btflag].show();
}
   
 
}
};

main m1;
void setup() {
 
}

void loop() {
m1.ms();

}
