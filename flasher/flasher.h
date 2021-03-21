#ifndef flasher_h
#define flasher_h
#include"Arduino.h"
class flasher {
private:
int d1,d2,d3;
public:  
flasher (int led1,int led2, int led3);
void PinSetup();
void Sequance1();
};

#endif
