#include"ioport.h"

/*For pinMode 
 *KEYWORD
 * d_port(Digital port,INPUT/OUTPUT); 
 * d_port2(port start,port end,INPUT/OUTPUT);
 * d_port3(int port_open,bool io,bool mode);
 * 
 * for output digital read write
 * KEYWORD
 *  drw(int mode,bool hl,int sp); //digital Read write mode 0=digital read 1 for digital write 2 for analog read 3 for analog write
 *  drw_mm(int mode,bool hl,int sp);
 * mode 0 fordigital read 
 * mode 1 for digital write 
 * mode 2 for analog read 
 * mode 3 for analog write
 *  Library originally added 22 Apr 2021
 by IOT Noob
 
 
 */
 ioport ip;
void setup() {
Serial.begin(9600);
 
 ip.d_port3(4,4,0);
}

void loop() {
 ip.drw_mm(1,1,4);
}
