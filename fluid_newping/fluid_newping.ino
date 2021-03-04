#include"NewPing.h"
const int tp=3;
const int ep=2;
int distance,dur,cmc,lit,ml,gal;
const int md=400,iteration=5;
NewPing sonar(tp,ep,md);

void setup() {
Serial.begin(9600);
}

void loop() {
  delay(800);
  Serial.print("\n*****************\n");
dur=sonar.ping_median(iteration);
distance=(dur/2)*0.0343;
//distance=8-distance;
Serial.print(distance);
Serial.print("Cm \n");
cmc=pow(distance,3);
Serial.print(cmc);
Serial.print(" Cubic Meter \n");
lit=(cmc/1000);
Serial.print(lit);
Serial.print(" Liters \n");
  ml=(cmc*1);
  Serial.print(ml);
Serial.print(" ml \n");
gal=(cmc/4546);
  Serial.print(gal);
Serial.print(" gallons \n");
Serial.print("*****************\n");
}
