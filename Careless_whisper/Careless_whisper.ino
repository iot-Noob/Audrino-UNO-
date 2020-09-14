#include"melody.h"
int sout=2; //speaker output
void setup() {

}

void loop() {

tone(sout, e5,610);
delay(666);
tone(sout, d5,650);
delay(314);
tone(sout, a4, 650);
delay(444);
tone(sout, f4, 850);
delay(600);//v1
tone(sout, e5,640);
delay(666);
tone(sout, d5,650);
delay(314);
tone(sout, a4, 650);
delay(444);
tone(sout, f4, 850);
delay(600);//v1

tone(sout, c5,640);
delay(500);
tone(sout, as4,650);
delay(314);
tone(sout, f4, 650);
delay(444);
tone(sout, d4, 850);
delay(600);//v2
tone(sout, c5,640);
delay(500);
tone(sout, as4,650);
delay(314);
tone(sout, f4, 650);
delay(444);
tone(sout, d4, 850);
delay(600);
//v3
tone(sout, as4,640);
delay(500);
tone(sout, a4,650);
delay(314);
tone(sout, f4, 650);
delay(444);
tone(sout, d4, 850);
delay(444);
tone(sout, as3, 850);
delay(630);
//v4
tone(sout, a3,540);
delay(500);
tone(sout, as3,550);
delay(314);
tone(sout, c4, 650);
delay(444);
tone(sout, d4, 850);
delay(444);
tone(sout, e4, 850);
delay(444);
tone(sout, f4, 850);
delay(444);
tone(sout, g4, 850);
delay(444);
tone(sout, a4, 850);
delay(6000);

}
