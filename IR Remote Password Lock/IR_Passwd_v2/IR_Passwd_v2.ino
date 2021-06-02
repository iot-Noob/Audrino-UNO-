 #include<EEPROM.h>
#include <ShiftedLCD.h>
#include <SPI.h>
#include <IRremote.h>
 const int RECV_PIN = 3,Bl=13,rp=4,bled=5,resetpin=6;
 
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal lcd(2);
bool pc=false;
int nill() {
  return 0;
}

 

uint32_t modesbtn[4]= {
 0xFF728D,//f1
0xFFF20D,//f2
0xFF0AF5,//f3
0xFF926D //OK

};

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
String dialog;
char nums[10]={
'0','1','2','3','4','5','6','7','8','9'
},temp,val[4],op[4]={'1','2','3','4'},eprom_read[4];
int chrcnt=0,st=0,av,av2,cbtf=0,trys=0;

 bool cpm=false;

void eeprom_clr() {
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print("Reset default!!");
 for(int i=0;i<=EEPROM.length();i++) {
  digitalWrite(Bl,HIGH);
   EEPROM.write(i,0);
   digitalWrite(Bl,LOW);  
 }
    digitalWrite(Bl,HIGH);
  lcd.clear();
}

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

void cbtp() {
if(results.value==modesbtn[0]) {
   cbtf=0; 
}else if(results.value==modesbtn[1]) {
     cbtf=1; 
}else if(results.value==modesbtn[2]){
  eeprom_clr();

}else {
    nill();
}
if(cbtf==0) {
  cpm=false;
}
if(cbtf==1) {
  cpm=true;
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

char save(char a) {
delay(33);
 if(temp==NULL) {

 nill();
 
 }else {
 
 if(cpm==false) {
    top:
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
      trys=0;
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
    if(trys==5) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Sleep Mode Enable");
        lcd.setCursor(0,1);
        lcd.print("paswd Limit exceed");
        backled_fadein();
 
        exit(1);
        
      }else {
        trys++;
      }
    delay(1000);
    temp=NULL;
    pc=false;
  chrcnt=0;
   lcd.clear();
     lcd.home();

    }
 
 }
 
 }else {
update_passwd();
delay(63);
 }
 
 }
}
 
int update_passwd() {
    delay(55);
    if(cpm==false) {
    pc=false;
    return 0;   
  }else {
       dialog="Enter New Psaswd!!";
  if(chrcnt!=4) {
    op[chrcnt]=temp;
    lcd.setCursor(chrcnt,0);
    lcd.print("*");
    chrcnt++;
    temp=NULL;
  }else {
     delay(55);
    chrcnt=0;
    temp=NULL;
    for(int i=0;i<=3;i++) {
        EEPROM.update(i,op[i]);
       
      }
      for(int i=0;i<=3;i++) {
        eprom_read[i]=EEPROM.read(i); 
      }
      av=atoi(op);
      av2=atoi(eprom_read);
      if(strcmp(av,av2)==0) {
       lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("Password Set!!");
      delay(1800);
      lcd.clear();
      temp=0;            
      av=0;
      av2=0;
       pc=false;
       results.value=0xFF728D;
      cpm=false;
      }else {
          lcd.setCursor(0,0);
          
      lcd.clear();
      lcd.print("Unable to Set password!!");
       lcd.setCursor(0,1);
       lcd.print("Undefined Error!!");
       delay(1800);
       temp=0;            
      av=0;
      av2=0;
       pc=false;
      cpm=false;
       results.value=0xFF728D;
      }
  }
  }

}
void ReadIr() {
  if (irrecv.decode(&results)){
    digitalWrite(Bl,HIGH);
        
          btnpress();  
          cbtp();
        
        irrecv.resume();
    digitalWrite(Bl,LOW);
  }
}
 int t3;
void setup() {
  lcd.cursor();
  pinMode(resetpin,OUTPUT);
  lcd.begin(16, 2);
Serial.begin(9600);
 irrecv.enableIRIn();
 pinMode(Bl,OUTPUT);
  pinMode(rp,OUTPUT);
  pinMode(bled,OUTPUT);
  digitalWrite(rp,HIGH);
  digitalWrite(bled,HIGH);
 
   for(int i=0;i<=3;i++) {
    op[i]=EEPROM.read(i);
  }
  av=atoi(op);
  if(av==NULL) {
    cpm=true;
    av=0;
  }else {
    cpm=false;
     
     av=0;
  }
}

void loop() {

 ReadIr();
   if(cpm==false) {
      lcd.setCursor(0,1);
        lcd.print("Enter Password");
          }else {
              lcd.setCursor(0,1);
        lcd.print(dialog);
       
          }

}
