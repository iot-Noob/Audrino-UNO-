#include<NewPing.h>
#include<DHT.h>
#include"Arduino.h"
#include "distance.h"



 distance::distance(int dhtp,int trigp,int echp) {
  dhtpin=dhtp;
  tp=trigp;
  ep=echp;
 }
 
void distance::begin() {
 DHT dht(dhtpin,DHT11);
   Serial.begin(9600); 
   dht.begin();
  NewPing sonar(tp, ep, md);

}
 void distance::measure() {
   NewPing sonar(tp, ep, md); 
    DHT dht(dhtpin,DHT11);
  delay(170);
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
  Serial.print("\ntemperature= ");
    Serial.print(temp);

 
    Serial.print("\nDictance mm= ");
   
 
    Serial.print(" mm\n");
        
      Serial.print(" Humidity= ");
 
    Serial.print("\nDictance= ");
    
    Serial.print(dist);
    Serial.print(" Cm\n");

Serial.print("\nDictanceInch= ");
    Serial.print(inch);
    Serial.print("In\n");

    Serial.print("\nDictanceFoot= ");
     
    
         
    Serial.print(foot);
    Serial.print("Ft\n");

      Serial.print("\nDictanceKilometer= ");
     
    
         
    Serial.print(km);
    Serial.print("km\n");

 
 
}
