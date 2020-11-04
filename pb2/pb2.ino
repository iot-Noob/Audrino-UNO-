#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int button[3]={6,7,8}; //button pin 2,3,4 in arduino
int btstat[3];  //button status wether its high or low
int btinit=0; //initial stage of button
bool bt0=false,bt1=false,bt2=false;
int count=0;
struct nme {
 String names;
String gv(String nme) {
   return names=nme;
 }
 void show() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Names ");
  lcd.print(count);
  lcd.setCursor(0,1);
  lcd.print(names);
 }
};

nme *n1[4];
void setup() {
Serial.begin(9600);
for(int i=0;i<=2;i++) {
 pinMode(button[i],INPUT_PULLUP); 
}
lcd.begin(16,2);
  n1[0]=new nme;
n1[0]->gv("David");
  n1[1]=new nme;
n1[1]->gv("John");
  n1[2]=new nme;
n1[2]->gv("Vicky");
  n1[3]=new nme;
n1[3]->gv("Mike");
}



void chkbt() { //check which button is pressed
if(btstat[0]==HIGH) {
bt0=true;
bt1=false;
bt2=false;    
}

if(btstat[1]==HIGH) {
bt0=false;
bt1=true;
bt2=false;    
}
if(btstat[2]==HIGH) {
bt0=false;
bt1=false;
bt2=true;    
}
}

void pbseq() { //push button pressed 
 for(int i=0;i<=2;i++) {
btstat[i]=digitalRead(button[i]); 
}
chkbt();
if(bt0==true) {

while(btstat[0]!=btinit) { //move forward
 if(btstat[0]==HIGH) {
   Serial.println("Button 1 is pushed!! Count= ");
   Serial.print(count);
  if(count==3) {
   count=0; 
  }else {
       count++;
  }
 }else {
  Serial.println("\nButton 1 is pulled up!!");
 }
 delay(50);
 btinit=btstat[0];
}
  
}
if(bt1==true) {

while(btstat[1]!=btinit) { //move back
 if(btstat[1]==HIGH) {
   Serial.println("Button 2 is pushed!! Count= ");
   Serial.print(count);
      if(count==0) {
        count=3;
      }else {
        count--;
      }
 }else {
  Serial.println("\nButton 2 is pulled up!!");
 }
 delay(50);
 btinit=btstat[1];
}

  
}
if(bt2==true) {

while(btstat[2]!=btinit) { //delete button
 if(btstat[2]==HIGH) {
   Serial.println("Button 3 is pushed!! Count= ");
   Serial.print(count);
   delete n1[count];
 }else {
  Serial.println("\nButton 3 is pulled up!!");
 }
 delay(50);
 btinit=btstat[2];
}

  
}
n1[count]->show();
}

void loop() {
  delay(7);
pbseq();


}
