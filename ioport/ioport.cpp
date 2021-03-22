#include "Arduino.h"
#include "ioport.h"
int ioport::nill() {
 return 0; 
 exit;
}
void begin(){
  Serial.begin(9600);
}
void ioport::d_port(int port_open,bool io) { //0 for input 1 for output
if(port_open<2||port_open>13) {
  Serial.println("Invalid input port!! port range from D2-D13");
  nill();
}else {
   p_range=map(port_open,2,13,0,12); 
  for(int i=0;i<=p_range;i++) {
   
 pinMode(ports[i],io);
 if(io==0) {
  Serial.print("\nPort ");
   Serial.print(ports[i]);
   Serial.print("Input");
 }
  if(io==1) {
  Serial.print("\nPort ");
   Serial.print(ports[i]);
   Serial.print(" Output");
 }
  }
}
}
 
void ioport::d_port2(int sport,int eport,bool io) { //0 for input 1 for output
if(sport<2||eport>13) {
  Serial.println("Invalid input port!! port range from D2-D13");
  nill();
}else {
 
   s_range=map(sport,2,13,0,12);
   e_range=map(eport,2,13,0,12);  
  for(int i=s_range;i<=e_range;i++) {
   
 pinMode(ports[i],io);
 if(io==0) {
  Serial.print("\nPort ");
   Serial.print(ports[i]);
   Serial.print("Input\n");
 }
  if(io==1) {
  Serial.print("\nPort ");
   Serial.print(ports[i]);
   Serial.print(" Output\n");
 }
  }
}
}

void ioport::d_port3(int port_open,bool io,bool mode) { //0 for input 1 for output mode0 for all  , mode 1` for manual entry
if(port_open<2||port_open>13) {
  Serial.println("Invalid input port!! port range from D2-D13");
  nill();
}else {
 
 p_range=map(port_open,2,13,0,12);
 
 if(mode==0) { //set all ports

  for(int i=0;i<=p_range;i++) {
   
 pinMode(ports[i],io);
 if(io==0) {
  Serial.print("\nPort ");
   Serial.print(ports[i]);
   Serial.print("Input");
 }
  if(io==1) {
  Serial.print("\nPort ");
   Serial.print(ports[i]);
   Serial.print(" Output");
 }
  }
  
 }
 if(mode==1) { //set manually ports
   pinMode(ports[p_range],io);
 if(io==0) {
  Serial.print("\nPort ");
   Serial.print(ports[p_range]);
   Serial.print("Input");
 }
  if(io==1) {
  Serial.print("\nPort ");
   Serial.print(ports[p_range]);
   Serial.print(" Output");
 }
 }
 
}

}
 
 void ioport::drw(int mode,bool hl,int sp) {
  if(sp<2||sp>13) {
     Serial.println("Invalid output port!! port range from D2-D13");
  }else {
    p_range=map(sp,2,13,0,12); 
    for(int i=0;i<-p_range;i++) {
          switch (mode) {
      case 0: //digital read
       digitalRead(ports[i]);
      break;

      case 1: //digital Write
       digitalWrite(ports[i],hl);
      break;  
      case 2: //analog read
      analogRead(ports[i]);
      break; 
      case 3: //analog Write
      analogWrite(ports[i],hl);
      break; 
    }
    }
  }
 }

 void ioport::drw_mm(int mode,bool hl,int sp) {
    if(sp<2||sp>13) {
     Serial.println("Invalid output port!! port range from D2-D13");
  }else {
    p_range=map(sp,2,13,0,12); 
     
          switch (mode) {
      case 0: //digital read
       digitalRead(ports[p_range]);
      break;

      case 1: //digital Write
       digitalWrite(ports[p_range],hl);
      break;  
      case 2: //analog read
      analogRead(ports[p_range]);
      break; 
      case 3: //analog Write
      analogWrite(ports[p_range],hl);
      break; 
    }
 
  }
 }
