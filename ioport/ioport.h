#ifndef ioport_h
#define ioport_h
#include"Arduino.h"

class ioport {
private:
int ports[12]={2,3,4,5,6,7,8,9,10,11,12,13};
int p_range,s_range,e_range;
 
public:  
int nill();
void begin();

void d_port(int port_open,bool io); //0 for input 1 for output
void d_port2(int sport,int eport,bool io); //0 for input 1 for output 
void d_port3(int port_open,bool io,bool mode); //0 for input 1 for output 
 
void  drw(int mode,bool hl,int sp);  //0 for digital_read 1 for digital_write 2 for analog_read 3 for analog_write

void drw_mm(int mode,bool hl,int sp);  //0 for digital_read 1 for digital_write 2 for analog_read 3 for analog_write
};

#endif
