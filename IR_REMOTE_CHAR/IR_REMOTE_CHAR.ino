#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include<Servo.h>
Servo tks;
int nill() {
 return 0; 
}

uint32_t kpd_btn[10]= {
0xFF00FF,//0  
0xFF807F, //1
0xFF40BF, //2
0xFFC03F, //3
0xFF20DF, //4
0xFFA05F, //5
0xFF609F, //6
0xFFE01F,//7
0xFF10EF, //8
0xFF906F,//9

};
uint32_t btok=0xFF926D;
char digits[10]={'0','1','2','3','4','5','6','7','8','9'};
int chr_cnt=1;
char temp[3];
int actual_value;
int btf=0;
const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
Serial.begin(9600);
 irrecv.enableIRIn();
  irrecv.blink13(true);
  tks.attach(3);
}

void clr_temp() {
  for(int i=1;i<=3;i++) {
    temp[i]=0;
  }
}

void btn_press() {
  for(int i=0;i<=9;i++) {
    if(results.value==kpd_btn[i]) {
      btf=i;
    }
    delay(10);
  }

  Serial.print("\n Button pressed= ");
  Serial.print(btf);

  if(chr_cnt!=3) {

    temp[chr_cnt]=digits[btf];
    chr_cnt++;
      
  }else {

      Serial.print("\n");

      chr_cnt=0;
    actual_value=atoi(temp);
    Serial.print("\n Concat value= ");
  Serial.print(actual_value);

  clr_temp();

  Serial.print("\n");


  }

}

void ir_read() {
 if (irrecv.decode(&results)){

         btn_press();
         
        irrecv.resume();
           tks.write(actual_value);
  }  

}
void loop() {
ir_read();

}
