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



*/

// include the library code:
#include <LiquidCrystal.h>

byte batery[11][2][8]= {
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
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int vin=8;
float sv;
float voltage,vmt ;
void setup() {
 Serial.begin(9600);
  lcd.begin(16, 2);
pinMode(vin,INPUT_PULLUP);
 
}

void cal_voltage() {
sv=analogRead(vin);
voltage= (sv * 5.0) / 1024.0; 
 //vmt=voltage*1000;
 //voltage=voltage*(10000/vmt); //10k ressitor

Serial.println(voltage);
}

void bat_stat(int bp) {
 lcd.createChar(0,batery[bp][0]);
lcd.createChar(1,batery[bp][1]); 
}

void draw_battery(int r,int c) {
  
 lcd.setCursor(r,c); 
 lcd.write(byte(0));
  lcd.setCursor(r+1,c); 
 lcd.write(byte(1));
}
 
void loop() {
   bat_stat(0);
 draw_battery(4,0);
 
}
