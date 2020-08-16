/*
 * use single 7 sagment display
 * single 7 sagment display  user output
 * conect pin 2 of audrino  to a 3 to b 4 to c 5 to d 6 to e 7 to f and 8 to g respectivly. 
 * open serial monitor and enter alphabect in table below 
 * x to clear value
 * enjoy
 * Code by Talha Khalid
 */


char inData[20]; // Allocate some space for the string
int inChar; // Where to store the character read
byte charIndex = 0; // Index into array; where to store the character
boolean okPrint;

int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
//alphabect for audrino that can display on 7sagment display
char A[8]={a,f,e,b,c,g};
char B[8]={f,e,g,c,d};
char C[8]={a,f,e,d};
char D[8]={g,e,d,b,c};
char E[8]={a,f,g,e,d};
char F[8]={a,f,e,g};
char G[8]={a,f,g,b,c};
char H[8]={f,e,b,c,g};
char L[8]={f,e,d};
char O[8]={a,f,e,d,c,b};
char P[8]={f,e,a,b,g};
char S[8]={a,f,g,c,d};
char U[8]={f,e,d,b,c};
char Y[8]={f,g,b,c};
char I[8]={b,c};
char Q[8]={a,f,g,b,c};
//end
void cls(void) {
for(int k=0;k<=7;k++) {
  digitalWrite(A[k],LOW); 
  digitalWrite(B[k],LOW); 
  digitalWrite(C[k],LOW); 
  digitalWrite(D[k],LOW); 
  digitalWrite(E[k],LOW); 
  digitalWrite(F[k],LOW); 
  digitalWrite(H[k],LOW); 
  digitalWrite(L[k],LOW); 
  digitalWrite(O[k],LOW); 
  digitalWrite(P[k],LOW); 
  digitalWrite(S[k],LOW); 
  digitalWrite(U[k],LOW); 
  digitalWrite(Y[k],LOW); 
   digitalWrite(I[k],LOW);
      digitalWrite(Q[k],LOW);
  delay(3); 
}
}
char ues;
void setup() /setup start
{
  Serial.begin(9600);

  
 pinMode(a,OUTPUT);
 pinMode(b,OUTPUT);
 pinMode(c,OUTPUT);
 pinMode(d,OUTPUT);
 pinMode(e,OUTPUT);
 pinMode(f,OUTPUT);
 pinMode(g,OUTPUT);
  pinMode(9, INPUT_PULLUP);

}//define pinmode end
int i;
char key;

void loop() { //main function that input alphabect in serial monitor and display to 7 sagment display
 key=Serial.read();
switch(key) {
 case 'a':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(A[i],HIGH);
 delay(55); 
}
  break;
 case 'b':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(B[i],HIGH);
 delay(55); 
}
  break;  

 case 'c':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(C[i],HIGH);
 delay(55); 
}
  break;   
   case 'i':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(I[i],HIGH);
 delay(55); 
}
  break;  

   case 'e':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(E[i],HIGH);
 delay(55); 
}
  break;  
  case 'f':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(F[i],HIGH);
 delay(55); 
}
  break; 
   case 'l':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(L[i],HIGH);
 delay(55); 
}
  break;   
   case 'o':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(O[i],HIGH);
 delay(55); 
}
  break;   
   case 'p':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(P[i],HIGH);
 delay(55); 
}
  break;  
   case 's':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(S[i],HIGH);
 delay(55); 
}
  break;  
   case 'u':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(U[i],HIGH);
 delay(55); 
}
  break;  
   case 'y':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(Y[i],HIGH);
 delay(55); 
}
  break; 
     case 'd':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(D[i],HIGH);
 delay(55); 
}
  break; 

    case 'h':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(H[i],HIGH);
 delay(55); 
}
  break;  
      case 'q':
 cls();
for(i=0;i<=7;i++){
 digitalWrite(Q[i],HIGH);
 delay(55); 
}
  break; 
  case 'x':
cls();
   break;
}
Serial.println(key);
delay(1000);  
}
  
