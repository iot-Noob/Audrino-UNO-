#ifndef distance_h
#define distance_h
#include"Arduino.h"
#include<NewPing.h>
#include<DHT.h>

class distance {
private:
int  dhtpin;
float   inch;
float   foot;
int tp = 9;
int ep = 9;
const int md = 400;
int iterations = 5;
float temp;
float hum;
 float dur, dist,soundsp,soundcm,mm,km,yard;
public: 
 distance(int dhtp,int trigp,int echp);

 void begin();
void measure();
};

#endif
