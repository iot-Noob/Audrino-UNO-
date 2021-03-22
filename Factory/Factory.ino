/*
 * download PCM.h library for arduino
 * use pin 11 for output of audio
 * enjoy
 */

#include"factory.h"
void setup() {
Serial.begin(9600);
Serial.print(F("Initilize Alarm"));
for(int i=0;i<=6;i++) {
 Serial.print(F(".")); 
 delay(400);
}
delay(1000);
Serial.print(F("\nAlarm started"));
}

void loop() {
 
fa();
 delay(650);
}
