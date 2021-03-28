#ifndef dmm_h
#define dmm_h
#include <ShiftedLCD.h>
#include <SPI.h>
#include"Arduino.h"

class dmm {
private:
int analogInput;
float vout = 0.0;
float vin = 0.0;
float R1;      
float R2;   
float vref;
int value = 0;
public:  
void begin();
void  voltage(int r,int c);
void volt_devider(float r1,float r2);
dmm(); 
void voltage_range(float v); 
float vinput();
  sensor_pin(int pin);
 
};

#endif
