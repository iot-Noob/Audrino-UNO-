/*
 * IR Remote RGB  LED controll
 * use IR Sensor pin 1 to arduino pin 2
 * use RGB LED 4 pin myne is common anode so pin A0 is for Red A1 for green and A2 for blue
 * 
 * 
 */



#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>



const int RECV_PIN = 2; //ir recivor pins
//                    btr       btg     btb 
uint32_t button[3]={16741005,16773645,16747125};  //rgb buttons
//                      1         2        3        4       5       6         ok
uint32_t program[7]={16744575,16728255,16760895,16769055,16752735,16736415,16749165}; //buttons of remore tv
//                      0         1        2        3       4         5       6
int nill() {
return 1;  
}

IRrecv irrecv(RECV_PIN);
decode_results results;



class ledrgb {
private:

uint32_t  bton=317649421;
uint32_t  btoff=16712445;
uint32_t vup=16724175;
uint32_t vdn=16718055;

bool ison=false;

int fadeflag=255;
//          R   G  B   
int rgb[3]={3,6,5}; //RGB LED PIN OUT

public:



unsigned  operator = (ledrgb & la)  {
for(int i=0;i<=2;i++) {
rgb[i]=la.rgb[i];  
}
ison=la.ison;
}

ledrgb() {
 for(int i=0;i<=2;i++) {
  pinMode(rgb[i],OUTPUT); 
 }

}
void led_controll(uint32_t select) {
switch (select) {
  case  317649421:
      ison=true;
   
       break;

        case  16749165:
      ison=true;
       break;
        case  16712445:
      ison=false;
      Serial.print("LED Offline");
       break;
      
      case 16724175:
      
        if(fadeflag==255) {
          nill();
          
        }else {
          fadeflag+=5;
         
        }
    delay(30);
      break;

      case 16718055:
         if(fadeflag==0) {
          nill();
          
        }else {
          fadeflag-=5;
           
        }
     delay(30);
      break;
    }

}



void led_glow(int slct) {
  
if(ison==true) {
   
analogWrite(rgb[slct],fadeflag);    
}
if(ison==false) {
analogWrite(rgb[slct],LOW);       
}

}



};
 
ledrgb lrgb[3];
ledrgb ledprog[6];

void setup() {
Serial.begin(9600);
 irrecv.enableIRIn();
  irrecv.blink13(true);
pinMode(RECV_PIN,INPUT_PULLUP);
}
void ir_read() {
 if (irrecv.decode(&results)){
        Serial.println(results.value);
        irrecv.resume();
  }  
}


int select=0;
int asize;
void btpress() {
   if (irrecv.decode(&results)){
        if(results.value==button[0]) {
select=0;
 Serial.print("\nRed led is Selected\n");    
}

if(results.value==button[1]) {
select=1;    
 Serial.print("\nGreen led is Selected\n"); 
}

if(results.value==button[2]) {
   Serial.print("\nBlue led is Selected\n"); 
select=2;    
}
switch(select) {
case 0:
lrgb[select].led_glow(0);
  Serial.print("\nRed led is on\n");
break;  

case 1:
lrgb[select].led_glow(1);
  Serial.print("\nGreen led is turning on\n");
break;

case 2:
lrgb[select].led_glow(2);
  Serial.print("\n Blue LED turning on\n");
break;
}
irrecv.resume();
  }




}

void loop() {
//ir_read();
btpress();

lrgb[select].led_controll(results.value);
delay(30);
}
