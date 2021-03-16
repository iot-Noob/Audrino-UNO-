#include<NewPing.h>
#include<DHT.h>
#include <LiquidCrystal.h>

byte dc[8]= {B00000,B11000,B11000,B00111,B01000,B01000,B01000,B00111};
byte bs[11][2][8]= {
 { {B11111,B10100,B10010,B10001,B10001,B10010,B10100,B11111},{ B11110,B00110,B01011, B10001,B10001,B01011,B00110,B11110} }, //battery critical
{ { B11111, B10000,B10000,B10000,B10000,B10000,B10000,B11111},{  B11110,B00010,B00011,B00001,B00001,B00011,B00010,B11110} }, //battery low
{ { B11111,B10000,B11000,B11000,B11000,B11000,B10000,B11111},{  B11110,B00010,B00011,B00001,B00001,B00011,B00010,B11110} }, //battery 1%
{ { B11111,B10000,B11000,B11000,B11000,B11000,B10000,B11111},{  B11110,B00010,B00011,B00001,B00001,B00011,B00010,B11110} }, //battery 9%
{ { B11111,B10000,B11100,B11100,B11100,B11100,B10000,B11111},{  B11110,B00010,B00011,B00001,B00001,B00011,B00010,B11110} }, //battery 15%
{ { B11111,B10000,B11110,B11110,B11110,B11110,B10000,B11111},{  B11110,B00010,B00011,B00001,B00001,B00011,B00010,B11110} }, //battery 25%
{ { B11111,B10000,B11111,B11111,B11111,B11111,B10000,B11111},{  B11110,B00010,B00011,B00001,B00001,B00011,B00010,B11110} }, //battery 45%
{ { B11111,B10000,B11111,B11111,B11111,B11111,B10000,B11111},{  B11110,B00010,B10011,B10001,B10001,B10011,B00010,B11110} }, //battery 55%
{ { B11111,B10000,B11111,B11111,B11111,B11111,B10000,B11111},{  B11110,B00010,B11011,B11001,B11001,B11011,B00010,B11110} }, //battery 74%
{ { B11111,B10000,B11111,B11111,B11111,B11111,B10000,B11111},{  B11110,B00010,B11011,B11001,B11001,B11011,B00010,B11110} }, //battery 95%
{ { B11111,B10000,B11111,B11111,B11111,B11111,B10000,B11111},{  B11110,B00010,B11111,B11111,B11111,B11111,B00010,B11110} }, //battery 100%
 };
 /* 
  * lcd pin arduino
  * rs=6
  * en=7
  * d4=5
  * d5 = 4
  * d6 = 3
  *  d7 = 2
  */
const int  dhtpin=8;
int del=3000;
const int tp = 9; //sonar echo pin
const int ep = 9;// sonar triger pin
const int md = 400;
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
int iterations = 5;
NewPing sonar(tp, ep, md);

int nill() {
  return 1;
}


DHT dht(dhtpin,DHT11);
void setup() {
Serial.begin(9600);
dht.begin();
 

}


class readValues {
protected:
float   inch;
float   foot;
float temp;
float hum;
 float dur, dist,soundsp,soundcm,mm,km;

public:
 readValues() {
   bat_stat(0);
  
 }
void bat_stat(int bp) {
 lcd.createChar(0,bs[bp][0]);
lcd.createChar(1,bs[bp][1]); 
}

void draw_battery(int r,int c) {
  
 lcd.setCursor(r,c); 
 lcd.write(byte(0));
  lcd.setCursor(r+1,c); 
 lcd.write(byte(1));
}

void bat_disp(int v) {
   draw_battery(14,1);
   if(v==100) {
    bat_stat(10);
  }
  if(v<90) {
   bat_stat(9); 
  }
  if(v<80) {
   bat_stat(8); 
  }
  if(v<70) {
   bat_stat(7); 
  }
   if(v<60) {
   bat_stat(6); 
  }
   if(v<50) {
   bat_stat(5); 
  }
   if(v<40) {
   bat_stat(4); 
  }
   if(v<30) {
   bat_stat(3); 
  }
   if(v<20) {
   bat_stat(2); 
  }
   if(v<10) {
   bat_stat(1); 
  }
   if(v==0) {
   bat_stat(0); 
  }
  
}
void read_values() {
   hum=dht.readHumidity();
  temp=dht.readTemperature();
  soundsp=331.4+(0.606*temp)+(0.0124*hum);
  soundcm=soundsp/10000;
  dur = sonar.ping_median(iterations);
  dist = (dur / 2) * soundcm;
  inch=(dist/2.54);
  mm=(dist*10);
    foot=(dist/30.48);
    km=(foot/3281); 
}
};

class disp_values:public readValues {
private:

  long previousMillis = 0;
 long interval = 1000;
int sensorValue,bp;
float voltage;

public:

void battery() {
bat_disp(bp);
    lcd.setCursor(0,1);
 sensorValue = analogRead(A0);
 voltage = sensorValue * (5.0 / 1023.0);

unsigned long currentMillis = millis();

if (currentMillis - previousMillis > interval) {
  previousMillis = currentMillis;
 if (voltage <= 3.5){
       lcd.print(voltage);
      lcd.print("v");
      bp=(voltage/5)*100;
     
       lcd.print(" ");
      lcd.print(bp);
       lcd.print("%");
     
 
 }else {

      Serial.println(voltage, DEC); 
      lcd.print(voltage);
      lcd.print("v");
      bp=(voltage/5)*100;
     
       lcd.print(" ");
      lcd.print(bp);
       lcd.print("% ");
     
     }
} 
delay(800); 
}

disp_values() {

lcd.begin(16, 2);
lcd.createChar(2,dc);

}

void show_cm() {
lcd.setCursor(4,0);
lcd.print(dist);  
lcd.print("cm");
 battery(); 
}
void show_in() {
lcd.setCursor(4,0);
lcd.print(inch);  
lcd.print("in"); 
 battery();
}

void show_ft() {
lcd.setCursor(4,0);
lcd.print(foot);  
lcd.print("ft"); 
 battery();
}
void show_mm() {
lcd.setCursor(4,0);
lcd.print(mm);  
lcd.print("mm"); 
 battery();
}
void show_km() {
lcd.setCursor(4,0);
lcd.print(km);  
lcd.print("km"); 
 battery();
}

void show_all() {
   battery();
lcd.setCursor(4,0);
if(foot>=70) {
     lcd.clear();
   lcd.print("Out of range!! No nearby object"); 
 
}else {
    if(dist<0.1) {
    lcd.clear();
   lcd.print(mm); 
     lcd.print(" mm"); 
   }
   if(dist<2.97) {
    lcd.clear();
   lcd.print(dist); 
     lcd.print("cm"); 
   }
if(dist>2.97) {
   lcd.clear();
   lcd.print(inch); 
     lcd.print("in"); 
   }
if(foot>=1) {
   lcd.clear();
   lcd.print(foot); 
     lcd.print("ft"); 
   }
   if(foot>3280.84) {
   lcd.clear();
   lcd.print(km); 
     lcd.print("km"); 
   }
} 
}

void show_humi_temp() {
  
lcd.setCursor(0,0); 
lcd.print("Temp=");  
lcd.print(temp); 
lcd.write(byte(2)); 
lcd.setCursor(0,1); 
lcd.print("Humid=");  
lcd.print(hum); 
lcd.print("%"); 
}

void ss(int vc) {
switch (vc) {
case 0:
lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Cm Distance  ");
 delay(del);
break;

case 1:
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("foot Distance ");

 delay(del);
break;

case 2:
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("inch Distance ");

 delay(del);
break;

case 3:
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("milimeter Distance ");

 delay(del);
break;

case 4:
lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Kilometer Distance ");

 delay(del); 
break;

case 5:
lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Your distance");

 delay(del); 
break;

case 6:
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Humidity/Temperature");
 delay(del);
break;
  }
}
};

class main:public disp_values {
private:
 const int btn=10; //button to change mode arrach at pin 10 of arduino nano
 int btf=0,btini=0,btread,count;//total 7

public:  
main() {
pinMode(btn,INPUT);  
}
disp_values d1[7];


void modes_change() {
  btread=digitalRead(btn);
 while(btread!=btini) {
   if(btread==HIGH) {
   if(count==7) {
    count=0;
   }else {
    count++;
    ss(count);
   }
   }else {
    Serial.println(count);
   }
   delay(50);
   btini=btread;
 }
}

void Main() {
modes_change();
read_values();

switch(count) {
  
case 0:
lcd.clear();
show_cm();

break;

case 1:
lcd.clear();
show_ft();

break;

case 2:
lcd.clear();
show_in();

break;

case 3:
lcd.clear();
show_mm();

break;

case 4:
lcd.clear();
show_km();

break;

case 5:
lcd.clear();
show_all();

break;

case 6:
lcd.clear();
show_humi_temp();
break;
}

}
};
main m1;
void loop() {
 
m1.Main();
 
}

 
