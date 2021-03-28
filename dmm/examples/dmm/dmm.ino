#include "dmm.h"
/*
 * Sketch made by IOT Noob Talha
 * in this sketch i am using Shift register for displaying output to my lcd
 * you can use normal lcd pins by little changes in lcd dmm.cpp
 * tell you accurate voltage using this sketch
 * change voltage divider resistor values accordingly
 */
 dmm dm;
void setup() {
  Serial.begin(9600);
dm.begin();
//dm.sensor_pin(A2); //by default set to A0 
//dm.volt_devider(float r1,float r2)// by default added resistor values of voltage sensor if you made your own voltage devider  n try add resistor values here a
}
float v1;
void loop() {
dm.voltage(0,0);

//dm.voltage_range(float v); //by default set to 5.0V change voltage here
v1=dm.vinput(); //return voltage values of sensor to variable; 
Serial.println(v1);
}
