
int button[3]={2,3,4};
int btstat[3];
int btinit=0;
bool bt0=false,bt1=false,bt2=false;
void setup() {
Serial.begin(9600);
for(int i=0;i<=2;i++) {
 pinMode(button[i],INPUT_PULLUP); 
}
}

void chkbt() {
if(btstat[0]==HIGH) {
bt0=true;
bt1=false;
bt2=false;    
}

if(btstat[1]==HIGH) {
bt0=false;
bt1=true;
bt2=false;    
}
if(btstat[2]==HIGH) {
bt0=false;
bt1=false;
bt2=true;    
}
}

void pbseq() {
 for(int i=0;i<=2;i++) {
btstat[i]=digitalRead(button[i]); 
}
chkbt();
if(bt0==true) {

while(btstat[0]!=btinit) {
 if(btstat[0]==HIGH) {
   Serial.println("Button 1 is pushed!!");
 }else {
  Serial.println("Button 1 is pulled up!!");
 }
 delay(50);
 btinit=btstat[0];
}
  
}
if(bt1==true) {

while(btstat[1]!=btinit) {
 if(btstat[1]==HIGH) {
   Serial.println("Button 2 is pushed!!");
 }else {
  Serial.println("Button 2 is pulled up!!");
 }
 delay(50);
 btinit=btstat[1];
}

  
}
if(bt2==true) {

while(btstat[2]!=btinit) {
 if(btstat[2]==HIGH) {
   Serial.println("Button 3 is pushed!!");
 }else {
  Serial.println("Button 3 is pulled up!!");
 }
 delay(50);
 btinit=btstat[2];
}

  
}
 
}
void loop() {
  delay(7);
pbseq();
}
