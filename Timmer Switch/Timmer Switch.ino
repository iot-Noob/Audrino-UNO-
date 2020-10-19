/*

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

*/


#include <LiquidCrystal.h>




class s_timmer {
protected:
int btset=A0;
int btstart=A1;
int btnext=A2;
int btprev=A3;
int relay=8;
int btflag=0;
private:
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int h,m,s,cs;
public:
s_timmer() {
  digitalWrite(relay, HIGH);

   pinMode(btset,INPUT);
   pinMode(btstart,INPUT);
   pinMode(btnext,INPUT);
   pinMode(btprev,INPUT);
    pinMode(relay,OUTPUT);
   h=0;
   m=0;
   s=2;
   cs=90;
}

int countdown() {
 if(h>0&&m==0) {
  h-=1;
  m=59;
 }else if(m>0&&s==0) {
  m-=1;
  s=59;
 }else if(s>0&&cs==0) {
  cs=99;
  s-=1;
 }else if(h>0||m>0||s>0||cs>0) {
  cs--;
 }else {
  digitalWrite(relay, LOW);
 }
 }

  void show() {
    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
   lcd.begin(16, 2);
   lcd.setCursor(5,1);
   lcd.print(h);
   lcd.print(":");
    lcd.print(m);
   lcd.print(":");
    lcd.print(s);
   lcd.print(":");
    lcd.print(cs);
   lcd.setCursor(0,0);
   lcd.print("-LightOffTimmer-");
  }

  void next() {
    if(digitalRead(btnext)==HIGH) {
      if(btflag==0) {
        btflag=1;
      }else if(btflag==1) {
        btflag=2;
      }else if(btflag==2) {
        btflag=3;
      }else if(btflag==3) {
        btflag=4;
      }
    }
  }

  void prev() {
     if(digitalRead(btprev)==HIGH) {
      if(btflag==4) {
        btflag=3;
      }else if(btflag==3) {
        btflag=2;
      }else if(btflag==2) {
        btflag=1;
      }else if(btflag==1) {
        btflag=0;
      }
    }
  }

  void main() {
    if(digitalRead(btset)==HIGH) {
      
    }else if(digitalRead(btstart)==true) {
      
    }
  }
};
s_timmer st;
void setup() {


}

void loop() {
st.countdown();
st.show();
delayMicroseconds(10000);

}
