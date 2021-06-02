 
#include <ShiftedLCD.h>
#include <SPI.h>
#include <IRremote.h>
 const int RECV_PIN = 3,Bl=13,rp=4,bled=5;
 
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal lcd(2);
bool pc=false;
int nill() {
  return 0;
}

uint32_t btns[10]= {
0xFF00FF,//0  
0xFF807F,//1
0xFF40BF,//2
0xFFC03F,//3
0xFF20DF,//4
0xFFA05F,//5
0xFF609F,//6
0xFFE01F,//7
0xFF10EF,//8
0xFF906F,//9
};

char nums[10]={
'0','1','2','3','4','5','6','7','8','9'
},temp,val[4],op[4]={'6','2','9','5'};
int chrcnt=0,st=0,av,av2;

 

void backled_fadein() {
 for(int i=255;i>=0;i--) {
    analogWrite(bled,i);
   delay(5);
 }
}
void backled_fadeout() {
 for(int i=0;i<=255;i++) {
    analogWrite(bled,i);
   delay(5);
 }
}


void btnpress() {

for(int i=0;i<=9;i++) {
   if(results.value==btns[i]) {
     temp=nums[i];
     save(temp);
  
   }else {

    nill();
   }
}
 
}

void gate_open() {
  digitalWrite(rp,LOW);
  delay(2000);
    digitalWrite(rp,HIGH);  
}

void save(char a) {
 
 if(temp==NULL) {

  nill();
 }else {
  
  if(chrcnt!=4) {
    
   val[chrcnt]=a;
   chrcnt++;
   lcd.setCursor(chrcnt,0);
    lcd.print("*");
   temp=NULL;
 }else if(chrcnt==4) {
  lcd.clear();
  lcd.setCursor(0,0);
  av=atoi(val);
  av2=atoi(op);
  for(int i=0;i<=3;i++) {
    //lcd.print(val[i]);
   // if(strcmp(val[i],op[i])==0) {
   if(strcmp(av,av2)==0) {
      pc=true;
    }else {
      pc=false;
    }
    
  }
 
    if(pc==true) {
       lcd.setCursor(3,0);
      lcd.print("Granted!!");
      lcd.setCursor(1,1);
      lcd.print("Welcome Admin!!");
gate_open();
    delay(2000);
    temp=NULL;
  chrcnt=0;
  pc=false;
   lcd.clear();
     lcd.home();

    }else {
          lcd.setCursor(3,0);
      lcd.print("Denied!!");
    lcd.setCursor(0,1);
    lcd.print("Invalid Passwd!!");
    delay(2000);
    temp=NULL;
    pc=false;
  chrcnt=0;
   lcd.clear();
     lcd.home();

    }
 
 }
 
 }
}
 

void ReadIr() {
  if (irrecv.decode(&results)){
    digitalWrite(Bl,HIGH);
          btnpress();  
          
        irrecv.resume();
    digitalWrite(Bl,LOW);
  }
}
 int t3;
void setup() {
 
  lcd.begin(16, 2);
Serial.begin(9600);
 irrecv.enableIRIn();
 pinMode(Bl,OUTPUT);
  pinMode(rp,OUTPUT);
  pinMode(bled,OUTPUT);
  digitalWrite(rp,HIGH);
  digitalWrite(bled,HIGH);
 
   
}

void loop() {
 
   lcd.setCursor(0,1);
  lcd.print("Enter password");
 ReadIr();
  

}
