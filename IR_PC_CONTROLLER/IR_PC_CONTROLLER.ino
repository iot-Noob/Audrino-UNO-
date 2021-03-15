#include <LiquidCrystal.h>

#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
Serial.begin(9600);
 irrecv.enableIRIn();
  irrecv.blink13(true);
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void ir_read() {
 if (irrecv.decode(&results)){
      Serial.print("0x");
        Serial.println(results.value,HEX);
        irrecv.resume();
  }  
}

class kpad {
protected:
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

uint32_t cb[7]={
 0xFF12ED,//left
0xFF52AD,//right
0xFFE21D,//up
0xFFD22D,//down
0xFF926D,//ok left click
0xFF50AF,//ctrl
0xFF6897 //alt


};

int btf,cbf;
public:  
};

class signals:public kpad {
private:

int btf,misbtf=0;
  
public:
void btn_keys() {
for(int i=0;i<=9;i++) {
   if(results.value==kpd_btn[i]) {
      btf=i; 
   }
}

}

void misc_btn_press() {
 for(int i=0;i<=6;i++) {
    if(results.value==cb[i]) {
      misbtf=i; 
   }
 }
}

void keytag() {
  switch (btf) {
    lcd.write(btf);
    case 0:
     Serial.println(0);
     
    break;

    case 1:
     Serial.println(1);
    break;

    case 2:
     Serial.println(2);
    break;

    case 3:
     Serial.println(3);
    break;

    case 4:
     Serial.println(4);
    break;

    case 5:
     Serial.println(5);
    break;

    case 6:
     Serial.println(6);
    break;  

    case 7:
     Serial.println(7);
    break;

    case 8:
     Serial.println(8);
    break;

    case 9:
     Serial.println(9);
    break;
  }

  switch(misbtf) {
    case 0:
Serial.println("left");
lcd.write("left");
    break;

    case 1:
Serial.println("right");
lcd.write("right");
    break;

    case 2:
    Serial.println("up");
    lcd.write("up");
    break;

    case 3:
Serial.write("down");
lcd.write("down");
    break;

    case 4:
Serial.write("ok");
lcd.write("ok");
    break;

    case 5:
Serial.write("ctrl");
lcd.write("ctrl");
    break;

    case 6:
Serial.write("alt");
lcd.write("alt");
    break;
 
    
  }
}

void press_me() {
 if (irrecv.decode(&results)){
  lcd.clear();
// btn_keys();
 misc_btn_press();
 keytag(); 
        irrecv.resume();
  }  
}

};
 signals  s1;
void loop() {
s1.press_me();
}
