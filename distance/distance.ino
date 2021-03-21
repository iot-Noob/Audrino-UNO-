/*
 * Distance measurment using sensor amalgum of DHT 11 Sonar sensor
 * made by Talha IOT NOOB
 * 31-3-2021
 * 
 */

//include distance library

#include "distance.h"
//pin 2 of arduino for dht sensor pin and 5,5 for trigger and echo pin of sonar sensor
//d1(dht,trigger,echo);
distance d1(4,5,5);
void setup() {
d1.begin(); //start sensor
 
}

void loop() {
d1.measure(); //measurement
}
